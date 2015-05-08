/*
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/*
 *    NaiveBayesMultinomialText.java
 *    Copyright (C) 2012 University of Waikato, Hamilton, New Zealand
 */

package weka.classifiers.bayes;
import java.io.BufferedReader;
import java.io.PrintWriter;
import java.io.Serializable;
import java.util.ArrayList;
import java.util.Enumeration;
import java.util.Vector;
import weka.classifiers.AbstractClassifier;
import weka.classifiers.bayes.SGM.SGM;
import weka.classifiers.bayes.SGM.TFIDF;
import weka.classifiers.bayes.SGM.SparseVector;
import weka.core.Capabilities;
import weka.core.Capabilities.Capability;
import weka.core.Instance;
import weka.core.Instances;
import weka.core.Option;
import weka.core.RevisionUtils;
import weka.core.SelectedTag;
import weka.core.Tag;
import weka.core.Utils;
import weka.core.WeightedInstancesHandler;

/**
 * @author Antti Puurula (as12{[at]}students{[dot]}waikato{[dot]}ac{[dot]}nz)
 *
 */
public class SparseGenerativeModel extends AbstractClassifier implements WeightedInstancesHandler, Serializable{

	/** For serialization */
	private static final long serialVersionUID = -3376037288335722173L;
	/** number of unique words */
	protected int m_numAttributes;
	/** number of class values */
	protected int m_numClasses;
	/** copy of header information for use in toString method */
	protected Instances m_headerInfo;

	/*public static final Tag[] TAGS_POST_NORM= {
		new Tag(0, "No normalization"),
		new Tag(1, "Posterior normalization"),
		new Tag(2, "Cross Entropy normalization"),
		new Tag(3, "KL-divergence normalization")
	};*/
	
	public static final Tag[] TAGS_USE_TFIDF= {
		new Tag(0, "No normalization"),
		new Tag(1, "TF-IDF"),
		new Tag(2, "TF"),
		new Tag(3, "IDF")
	};

	TFIDF tfidf;
	SGM sgm;
	protected boolean kernel_densities= true;
	protected boolean full_posteriors= false;
	protected boolean norm_posteriors= false;
	protected int constrain_labels= 0;
	protected int use_tfidf= 0;
	protected int cond_hashsize= 10000000;
	protected double prune_count_table= -1000000;
	protected double prune_count_insert= -6.0;	
	protected double min_count= 0.0;
	protected double min_idf= 0.0;
	protected double length_scale= 0.0;
	protected double idf_lift= 0.0;
	//protected double cond_unif_weight= 0.5;
	//protected double cond_bg_weight= 0.0;
	//protected double cond_scale= 1.0;
	protected double prior_scale= 0.5;
	protected double label_threshold= -1000000;
	protected double feedback_weight= 0.0;
	
	protected double bg_unif_smooth= 1.0;
	protected double jelinek_mercer= 0.5;
	protected double dirichlet_prior= 0.0;
	protected double absolute_discount= 0.0;
	protected double powerlaw_discount= 0.0;
	protected double kernel_jelinek_mercer= 0.0;
	protected double kernel_powerlaw_discount= 0.5;
	protected double kernel_dirichlet_prior= 0.01;
	//protected double kernel_smooth_weight= 0.5;
	protected double cond_norm= 1.0;
	protected double combination= 1.0;
	protected int top_k= 50;
	protected int max_retrieved= 1;
	/**
	 * Returns a string describing classifier
	 * @return a description suitable for
	 * displaying in the explorer/experimenter gui
	 */
	public String globalInfo() {
		return "Generative models for scalable text mining. " +
				"Provides sparse matrix implementations for Multinomial Naive Bayes " +
				"and Multinomial Kernel Density classifiers. Uses hash tables for training, " +
				"inverted indices for classification. Implements several options for smoothing, " +
				"TF-IDF feature transforms, parameter pruning and model-based feedback. Default " +
				"options smooth class-conditionals using Uniform Jelinek-Mercer and instance-conditionals " +
				"with Pitman-Yor Process smoothing.\n\n" +
				"Restart Weka after package installation. For preprocessing use " +
				"Weka StringToWordVector with outputWordCounts=True.\n\n" +
				"Documentation website: sourceforge.net/p/sgmweka/wiki\n\n" +
				"References:\n" +
				"Puurula, A. " +
				"Scalable Text Classification with Sparse Generative Modeling. " +
				"Proceedings of the 12th Pacific Rim International Conference on Artificial Intelligence. " +
				"2012.\n" +
				"Puurula, A and Bifet, A." +
				"Ensembles of Sparse Multinomial Classifiers for Scalable Text Classification." +
				"ECML/PKDD PASCAL Workshop on Large-Scale Hierarchical Classification." +
				"2012.\n" +
				"Puurula, A and Myaeng, S." +
				"Integrated Instance- and Class-based Generative Modeling for Text Classification." +
				"Proceedings of the Australasian Document Computing Symposium." +
				"2013";
	}

	/**
	 * Returns default capabilities of the classifier.
	 *
	 * @return      the capabilities of this classifier
	 */
	public Capabilities getCapabilities() {
		Capabilities result = super.getCapabilities();
		result.disableAll();
		result.enable(Capability.NUMERIC_ATTRIBUTES);
		result.enable(Capability.NOMINAL_CLASS);
		result.enable(Capability.MISSING_CLASS_VALUES);
		return result;
	}

	/**
	 * Generates the classifier.
	 *
	 * @param instances   set of instances serving as training data
	 * @throws Exception  if the classifier has not been generated successfully
	 */
	public void buildClassifier(Instances instances) throws Exception {
		// can classifier handle the data?
		getCapabilities().testWithFail(instances);

		instances = new Instances(instances);
		instances.deleteWithMissingClass();
		m_headerInfo= new Instances(instances, 0);
		m_numClasses= instances.numClasses();
		m_numAttributes= instances.numAttributes();

		tfidf= new TFIDF(length_scale, idf_lift, use_tfidf);
		sgm= new SGM();
		//sgm.init_model(cond_hashsize, tfidf, cond_norm);
		sgm.init_model(cond_hashsize, tfidf);

		sgm.prune_count_insert= prune_count_insert;
		if (kernel_densities) sgm.kernel_densities();
		Instance instance;
		int terms_length;
		int[] labels= {-1};
		float[] label_weights= {1};
		Enumeration<Instance> enumInsts= (Enumeration<Instance>) instances.enumerateInstances();
		while (enumInsts.hasMoreElements()) {
			instance= (Instance)enumInsts.nextElement();
			labels[0]= (int)instance.value(instance.classIndex());
			label_weights[0]= (float)instance.weight();
			terms_length= instance.numValues();
			for(int a= 0; a<instance.numValues(); a++) if(instance.index(a) == instance.classIndex()) terms_length--;
			int n= 0;
			int[] terms= new int[terms_length];
			float[] counts= new float[terms_length];
			for(int a= 0; a<instance.numValues(); a++) {
				if(instance.index(a) != instance.classIndex()) {
					if(!instance.isMissing(a)) {
						terms[n]= instance.index(a);
						counts[n++]= (float)instance.valueSparse(a);
					}
				}
			}
			sgm.add_instance(terms, counts, labels, label_weights);
		}
		tfidf.normalize(min_count, min_idf);
		if (prune_count_table>-1000000.0) sgm.prune_counts(prune_count_table, cond_hashsize);
		sgm.apply_idfs();
		sgm.make_bo_models();
		//if (cond_scale!=1.0) sgm.scale_conditionals(cond_scale);
		//sgm.smooth_conditionals(cond_unif_weight, cond_bg_weight, kernel_smooth_weight);
		//sgm.smooth_prior(prior_scale);
		//sgm.prepare_inference(top_k, max_retrieved, label_threshold, combination, norm_posteriors);
		
		sgm.smooth_conditionals(bg_unif_smooth, jelinek_mercer, dirichlet_prior, absolute_discount, powerlaw_discount, kernel_jelinek_mercer, kernel_powerlaw_discount, kernel_dirichlet_prior);
	    sgm.smooth_prior(prior_scale);
	    sgm.prepare_inference(top_k, max_retrieved, label_threshold, combination, full_posteriors, norm_posteriors, constrain_labels);
	}

	public double classifyInstance(Instance instance) throws Exception {
	//public double[] distributionForInstance(Instance instance) throws Exception {
		int terms_length= instance.numValues();
		int n= 0;
		int[] terms= new int[terms_length];
		float[] counts= new float[terms_length];
		for(int a= 0; a<instance.numValues(); a++) if(instance.index(a) == instance.classIndex()) terms_length--;
		for(int a= 0; a<instance.numValues(); a++)
			if(instance.index(a) != instance.classIndex()) {
				if(!instance.isMissing(a)) {
					terms[n]= instance.index(a);
					counts[n++]= (float)instance.valueSparse(a);
				}
		}

		//SparseVector scores= sgm.inference(terms, counts);
		//System.out.println(m_numClasses+" "+scores.indices.length+" "+scores.values.length+"\n");
		//double[] posteriors= new double[m_numClasses]; 
		//if (m_numClasses+1!= scores.values.length) {
		//	double bg_score= scores.values[scores.values.length-1];
		//	for (int a= 0; a< m_numClasses; a++) posteriors[a]= Math.exp(bg_score);
		//}
		//for (int a= 0; a< scores.indices.length-1; a++) 
		//	posteriors[scores.indices[a]]= Math.exp(scores.values[a]);
		/*double probOfDoc= 0.0, max= -1000000.0;
	    for (double score: scores.values) if (score>max) max= score;
		for (int a= 0; a< scores.indices.length; a++)
			probOfDoc+= posteriors[scores.indices[a]]= Math.exp(scores.values[a]-max);
	    Utils.normalize(posteriors, probOfDoc);*/
		//return posteriors;
		
		//int label= sgm.inference(terms, counts, top_k, max_retrieved).indices[0];
		int label= sgm.infer_posterior(terms, counts, feedback_weight).indices[0];
		return label;
	}

	public String pruneCountTableTipText() {return "Log-count pruning value of conditional parameters after training.";}
	public double getPruneCountTable() {return (double)prune_count_table;}
	public void setPruneCountTable(double value) {prune_count_table= (float)value;}
	
	public String pruneCountInsertTipText() {return "Log-count pruning value of conditional parameters after each update. If used, typical values -6 to -10.";}
	public double getPruneCountInsert() {return (double)prune_count_insert;}
	public void setPruneCountInsert(double value) {prune_count_insert= (float)value;}

	public String minCountTipText() {return "Minimum document frequency of term after training. 1 = no terms pruned.";}
	public double getMinCount() {return (double)min_count;}
	public void setMinCount(double value) {min_count= (float)value;}

	public String lengthScaleTipText() {return "TF length normalization parameter. Higher values for stronger length normalization.";}
	public double getLengthScale() {return (double)length_scale;}
	public void setLengthScale(double value) {length_scale= (float)value;}

	public String idfLiftTipText() {return "IDF normalization parameter. Higher values for weaker IDF normalization. -1 = Croft-Harper IDF, 0 = Robertson-Walker IDF.";}
	public double getIdfLift() {return (double)idf_lift;}
	public void setIdfLift(double value) {idf_lift= (float)value;}

	/*public String condUnifWeightTipText() {return "Uniform smoothing weight for conditionals.";}
	public double getCondUnifWeight() {return (double)cond_unif_weight;}
	public void setCondUnifWeight(double value) {cond_unif_weight= (float)value;}

	public String condBgWeightTipText() {return "Background model smoothing weight for conditionals.";}
	public double getCondBgWeight() {return (double)cond_bg_weight;}
	public void setCondBgWeight(double value) {cond_bg_weight= (float)value;}*/

	public String feedbackWeightTipText() {return "Feedback model interpolation weight for model-based feedback.";}
	public double getFeedbackWeight() {return (double)feedback_weight;}
	public void setFeedbackWeight(double value) {feedback_weight= (float)value;}

	public String bgUnifSmoothTipText() {return "Uniform smoothing weight for background model.";}
	public double getBgUnifSmooth() {return (double)bg_unif_smooth;}
	public void setBgUnifSmooth(double value) {bg_unif_smooth= (float)value;}

	public String jelinekMercerTipText() {return "Jelinek-Mercer smoothing of class-conditionals with the background model.";}
	public double getJelinekMercer() {return (double)jelinek_mercer;}
	public void setJelinekMercer(double value) {jelinek_mercer= (float)value;}
	
	public String dirichletPriorTipText() {return "Dirichlet Prior smoothing of class-conditionals with the background model.";}
	public double getDirichletPrior() {return (double)dirichlet_prior;}
	public void setDirichletPrior(double value) {dirichlet_prior= (float)value;}

	public String absoluteDiscountTipText() {return "Absolute Discount smoothing of class-conditionals with the background model.";}
	public double getAbsoluteDiscount() {return (double)absolute_discount;}
	public void setAbsoluteDiscount(double value) {absolute_discount= (float)value;}
	
	public String powerlawDiscountTipText() {return "Powerlaw Discount smoothing of class-conditionals with the background model.";}
	public double getPowerlawDiscount() {return (double)powerlaw_discount;}
	public void setPowerlawDiscount(double value) {powerlaw_discount= (float)value;}

	//public String condScaleTipText() {return "Scaling of discounted unsmoothed conditional probabilities. Similar to absolute discounting.";}
	//public double getCondScale() {return (double)cond_scale;}
	//public void setCondScale(double value) {cond_scale= (float)value;}

	public String priorScaleTipText() {return "Scaling of prior probabilities. Equivalent to language model scaling in HMM speech recognition.";}
	public double getPriorScale() {return (double)prior_scale;}
	public void setPriorScale(double value) {prior_scale= (float)value;}
	
	public String kernelDensitiesTipText() {return "Use Multinomial Kernel densities.";}
	public boolean getKernelDensities() {return kernel_densities;}
	public void setKernelDensities(boolean value) {kernel_densities= value;}
	
	public String useTFIDFTipText() {return "Use TF-IDF:\n" +
		" \t 0 = no feature transform\n" +
		" \t 1 = TF-IDF\n" +
		" \t 2 = TF\n" +
		" \t 3 = IDF\n";
	}

	public void setUseTFIDF(SelectedTag value) {
		if (value.getTags() == TAGS_USE_TFIDF) use_tfidf = value.getSelectedTag().getID();
	}
	
	public SelectedTag getUseTFIDF() {return new SelectedTag(use_tfidf, TAGS_USE_TFIDF);}	
	
	/*public String normPosteriorsTipText() {return "\tPosterior score normalization:\n" +
				"\t\t 0 = no normalization\n" +
				"\t\t 1 = posterior normalization\n" +
				"\t\t 2 = KL-divergence normalization";}
	public void setNormPosteriors(SelectedTag value) {
		if (value.getTags() == TAGS_POST_NORM) norm_posteriors = value.getSelectedTag().getID();
	}
	
	public SelectedTag getNormPosteriors() {return new SelectedTag(norm_posteriors, TAGS_POST_NORM);}	
	*/

	//public String kernelSmoothWeightTipText() {return "Weight for smoothing kernels with class-centroid.";}
	//public double getKernelSmoothWeight() {return (double)kernel_smooth_weight;}
	//public void setKernelSmoothWeight(double value) {kernel_smooth_weight= (float)value;}
	
	public String kernelJelinekMercerTipText() {return "Jelinek-Mercer smoothing of instance-conditionals with the class-conditionals.";}
	public double getKernelJelinekMercer() {return (double)kernel_jelinek_mercer;}
	public void setKernelJelinekMercer(double value) {kernel_jelinek_mercer= (float)value;}

	public String kernelPowerlawDiscountTipText() {return "Powerlaw Discount smoothing of instance-conditionals with the class-conditionals.";}
	public double getKernelPowerlawDiscount() {return (double)kernel_powerlaw_discount;}
	public void setKernelPowerlawDiscount(double value) {kernel_powerlaw_discount= (float)value;}
	
	public String kernelDirichletPriorTipText() {return "Dirichlet Prior smoothing of instance-conditionals with the class-conditionals.";}
	public double getKernelDirichletPrior() {return (double)kernel_dirichlet_prior;}
	public void setKernelDirichletPrior(double value) {kernel_dirichlet_prior= (float)value;}

	public String combinationTipText() {return "Instance score combination:\n \t 1 = kernel density\n \t 0 = voting\n \t 1 = distance-weighted voting\n";}
	public double getCombination() {return (double)combination;}
	public void setCombination(double value) {combination= (float)value;}
	
	//public String condNormTipText() {return "Normalization for the conditional parameters. Magnitude for vector norm, negative sign for exponentiated parameters. Common cases: 1.0 = Multinomial, -2.0 = Cosine\n";}
	//public double getCondNorm() {return (double)cond_norm;}
	//public void setCondNorm(double value) {cond_norm= (float)value;}
	
	public String topKTipText() {return "Top k instances for inference with kernel densities.";}
	public int getTopK() {return top_k;}
	public void setTopK(int value) {top_k= (int)value;}

	public Enumeration<Option> listOptions() {
		Vector<Option> newVector = new Vector<Option>();
		newVector.addElement(new Option(pruneCountTableTipText(), "prune_count_table", 1, "-prune_count_table <double>"));
		newVector.addElement(new Option(pruneCountInsertTipText(), "prune_count_insert", 1, "-prune_count_insert <double>"));
		newVector.addElement(new Option(minCountTipText(), "min_count", 1, "-min_count <double>"));
		newVector.addElement(new Option(lengthScaleTipText(), "length_scale", 1, "-length_scale <double>"));
		newVector.addElement(new Option(idfLiftTipText(), "idf_lift", 1, "-idf_lift <double>"));
		//newVector.addElement(new Option(condUnifWeightTipText(), "cond_unif_weight", 1, "-cond_unif_weight <double>"));
		//newVector.addElement(new Option(condBgWeightTipText(), "cond_bg_weight", 1, "-cond_bg_weight <double>"));

		newVector.addElement(new Option(feedbackWeightTipText(), "feedback_weight", 1, "-feedback_weight <double>"));
		newVector.addElement(new Option(bgUnifSmoothTipText(), "bg_unif_smooth", 1, "-bg_unif_smooth <double>"));
		newVector.addElement(new Option(jelinekMercerTipText(), "jelinek_mercer", 1, "-jelinek_mercer <double>"));
		newVector.addElement(new Option(dirichletPriorTipText(), "dirichlet_prior", 1, "-dirichlet_prior <double>"));
		newVector.addElement(new Option(absoluteDiscountTipText(), "absolute_discount", 1, "-absolute_discount <double>"));
		newVector.addElement(new Option(powerlawDiscountTipText(), "powerlaw_discount", 1, "-powerlaw_discount <double>"));
		
		//newVector.addElement(new Option(condScaleTipText(), "cond_scale", 1, "-cond_scale <double>"));
		newVector.addElement(new Option(priorScaleTipText(), "prior_scale", 1, "-prior_scale <double>"));
		newVector.addElement(new Option(kernelDensitiesTipText(), "kernel_densities", 0, "-kernel_densities"));
		//newVector.addElement(new Option(normPosteriorsTipText(), "norm_posteriors", 1, "norm_posteriors <int>"));
		newVector.addElement(new Option(useTFIDFTipText(), "use_tfidf", 1, "use_tfidf<int>"));
		//newVector.addElement(new Option(kernelSmoothWeightTipText(), "kernel_smooth_weight", 1, "-kernel_smooth_weight"));
		newVector.addElement(new Option(kernelJelinekMercerTipText(), "kernel_jelinek_mercer", 1, "-kernel_jelinek_mercerkernel_jelinek_mercer"));
		newVector.addElement(new Option(kernelPowerlawDiscountTipText(), "kernel_powerlaw_discount", 1, "-kernel_powerlaw_discount"));
		newVector.addElement(new Option(kernelDirichletPriorTipText(), "kernel_dirichlet_prior", 1, "-kernel_dirichlet_prior"));
		newVector.addElement(new Option(combinationTipText(), "combination", 1, "-combination"));
		//newVector.addElement(new Option(condNormTipText(), "cond_norm", 1, "-cond_norm"));
		newVector.addElement(new Option(topKTipText(), "top_k", 1, "-top_k"));
		return newVector.elements();
	}
    	
	public void setOptions(String[] options) throws Exception {
		setPruneCountTable(Double.parseDouble(Utils.getOption("prune_count_table", options)));
		setPruneCountInsert(Double.parseDouble(Utils.getOption("prune_count_insert", options)));
		setMinCount(Double.parseDouble(Utils.getOption("min_count", options)));
		setLengthScale(Double.parseDouble(Utils.getOption("length_scale", options)));
		setIdfLift(Double.parseDouble(Utils.getOption("idf_lift", options)));
		//setCondUnifWeight(Double.parseDouble(Utils.getOption("cond_unif_weight", options)));
		//setCondBgWeight(Double.parseDouble(Utils.getOption("cond_bg_weight", options)));
		
		setFeedbackWeight(Double.parseDouble(Utils.getOption("feedback_weight", options)));
		setBgUnifSmooth(Double.parseDouble(Utils.getOption("bg_unif_smooth", options)));
		setJelinekMercer(Double.parseDouble(Utils.getOption("jelinek_mercer", options)));
		setDirichletPrior(Double.parseDouble(Utils.getOption("dirichlet_prior", options)));
		setAbsoluteDiscount(Double.parseDouble(Utils.getOption("absolute_discount", options)));
		setPowerlawDiscount(Double.parseDouble(Utils.getOption("powerlaw_discount", options)));
				
		//setCondScale(Double.parseDouble(Utils.getOption("cond_scale", options)));
		setPriorScale(Double.parseDouble(Utils.getOption("prior_scale", options)));
		if (Utils.getFlag("kernel_densities", options)) kernel_densities= true;
		String tmpStr= Utils.getOption("use_tfidf", options);
		if (tmpStr.length()!= 0) setUseTFIDF(new SelectedTag(Integer.parseInt(tmpStr), TAGS_USE_TFIDF));
		//String tmpStr= Utils.getOption("norm_posteriors", options);
		//if (tmpStr.length()!= 0) setNormPosteriors(new SelectedTag(Integer.parseInt(tmpStr), TAGS_POST_NORM));
		//setKernelSmoothWeight(Double.parseDouble(Utils.getOption("kernel_smooth_weight", options)));
		setKernelJelinekMercer(Double.parseDouble(Utils.getOption("kernel_jelinek_mercer", options)));
		setKernelPowerlawDiscount(Double.parseDouble(Utils.getOption("kernel_powerlaw_discount", options)));
		setKernelDirichletPrior(Double.parseDouble(Utils.getOption("kernel_dirichlet_prior", options)));
		setCombination(Double.parseDouble(Utils.getOption("combination", options)));
		//setCondNorm(Double.parseDouble(Utils.getOption("cond_norm", options)));
		setTopK(Integer.parseInt(Utils.getOption("top_k", options)));
	}
	
	public String[] getOptions() {
		ArrayList<String> options = new ArrayList<String>();
		options.add("-prune_count_table"); options.add("" + getPruneCountTable());
		options.add("-prune_count_insert"); options.add("" + getPruneCountInsert());
		options.add("-min_count"); options.add("" + getMinCount());
		options.add("-length_scale"); options.add("" + getLengthScale());
		options.add("-idf_lift"); options.add("" + getIdfLift());
		//options.add("-cond_unif_weight"); options.add("" + getCondUnifWeight());
		//options.add("-cond_bg_weight"); options.add("" + getCondBgWeight());
		options.add("-feedback_weight"); options.add("" + getFeedbackWeight());
		options.add("-bg_unif_smooth"); options.add("" + getBgUnifSmooth());
		options.add("-jelinek_mercer"); options.add("" + getJelinekMercer());
		options.add("-dirichlet_prior"); options.add("" + getDirichletPrior());
		options.add("-absolute_discount"); options.add("" + getAbsoluteDiscount());
		options.add("-powerlaw_discount"); options.add("" + getPowerlawDiscount());
	
		//options.add("-cond_scale"); options.add("" + getCondScale());
		options.add("-prior_scale"); options.add("" + getPriorScale());
		if (kernel_densities) options.add("-kernel_densities");
		//if (norm_posteriors!=0) {options.add("-norm_posteriors"); options.add(""+ norm_posteriors);}
		if (use_tfidf!=0) {options.add("-use_tfidf"); options.add(""+ use_tfidf);}
		//options.add("-kernel_smooth_weight"); options.add("" + getKernelSmoothWeight());
		options.add("-kernel_jelinek_mercer"); options.add("" + getKernelJelinekMercer());
		options.add("-kernel_powerlaw_discount"); options.add("" + getKernelPowerlawDiscount());
		options.add("-kernel_dirichlet_prior"); options.add("" + getKernelDirichletPrior());
		options.add("-combination"); options.add("" + getCombination());
		//options.add("-cond_norm"); options.add("" + getCondNorm());
		options.add("-top_k"); options.add("" + getTopK());
		return options.toArray(new String[1]);
	}

	public String toString() {
		StringBuffer result = new StringBuffer();
		/*result.append("sgm.model.cond_lprobs.size():" +sgm.model.cond_lprobs.size()+"\n");
		result.append("sgm.model.cond_bgs.size():" +sgm.model.cond_bgs.size()+"\n");
		result.append("sgm.model.prior_lprobs.size():" +sgm.model.prior_lprobs.size()+"\n");
		*/return result.toString();
	}

	public String getRevision() {return RevisionUtils.extract("$Revision: 8034 $");}

	public static void main(String[] args) {runClassifier(new SparseGenerativeModel(), args);}
}

