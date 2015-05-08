package weka.classifiers.bayes.SGM;
import java.util.HashSet; 
import java.util.Hashtable; 
import java.nio.IntBuffer;
import java.nio.FloatBuffer;
import java.nio.DoubleBuffer;
import java.util.LinkedList;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Enumeration;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.io.Serializable;
import java.lang.Math;
import java.util.Iterator;
import java.util.TreeSet;
import java.util.Map;
import java.util.Map.Entry;

public class SGM implements Serializable{
	private static final long serialVersionUID = -3376037288335722173L;
	public int debug;
	private BufferedReader input_file;
	public SparseData data;
	public int num_classified;
	public int num_labels_classified;
	//Hashtable<Integer, IntBuffer> inverted_index;
	//Hashtable<Integer, FloatBuffer> inverted_index2;
	Hashtable<Integer, ArrayList<Integer>> inverted_index;
	Hashtable<Integer, ArrayList<Float>> inverted_index2;
	int prior_max_label;
	public double prune_count_insert;
	double label_threshold;
	int cond_hashsize;
	public SGM_Params model;

	int constrain_labels; // 0= no constrains, %2== 1 constrain evaluation, >1 constrain search
	HashSet<Integer> constrained_labels;
	TFIDF tfidf;
	int num_classes;
	public boolean norm_posteriors;
	public boolean full_posteriors;
	Hashtable<IntBuffer, Integer> labels2powerset;
	Hashtable<Integer, IntBuffer> powerset2labels;
	Hashtable<Integer, Integer> component_counts;
	Hashtable<Integer, Double> bo_mean_lweights;
	public int top_k;
	public int max_retrieved;
	public double combination;
	//public double cond_norm;
	int tp, fp, fn, tp0, fp0, fn0;
	double rec, prec, fscore, rec0, prec0, fscore0, map, meanjaccard;//, mapErrors, wAcc;

	public SGM() {
	}

	public String hello() {
		return("Hello!");
	}

	public void init_model(int cond_hashsize) throws Exception {
		//System.out.println("SGM Initializing model");
		debug= 0;
		this.cond_hashsize= cond_hashsize;
		model= new SGM_Params(cond_hashsize);
		constrained_labels= null;
		prior_max_label= -1;
		labels2powerset= null;
		powerset2labels= null;
		norm_posteriors= false;
		full_posteriors= false;
		//cond_norm= 1;
	}

	//public void init_model(int cond_hashsize, TFIDF tfidf, double cond_norm) throws Exception {
	public void init_model(int cond_hashsize, TFIDF tfidf) throws Exception {
		init_model(cond_hashsize);
		this.tfidf= tfidf;
		//this.cond_norm= cond_norm;
	}

	public void train_model(int batch_size, double prune_count_insert) throws Exception {
		this.prune_count_insert= prune_count_insert;
		if (debug>0) System.out.println("Updating model " + data.doc_count + " "+ model.train_count);
		if (data.label_weights==null) for (int w= 0; w < data.doc_count; w++) add_instance(data.terms[w], data.counts[w], data.labels[w], null);
		else for (int w= 0; w < data.doc_count; w++) add_instance(data.terms[w], data.counts[w], data.labels[w], data.label_weights[w]);
	}

	public int[] get_label_powerset(int[] labels) {
		int[] labels2= Arrays.copyOf(labels, labels.length);
		if (labels2.length>1) Arrays.sort(labels2);
		IntBuffer wrap_labels= IntBuffer.wrap(labels2);
		Integer powerset= labels2powerset.get(wrap_labels);
		if (powerset==null) {
			powerset= labels2powerset.size();
			labels2powerset.put(wrap_labels, powerset);
		}
		labels= new int[1];
		labels[0]= powerset;
		return labels;
	}

	public void add_instance(int[] terms, float[] counts, int[] labels, float[] label_weights) {
		tfidf.length_normalize(terms, counts);
		if (labels2powerset!=null) labels= get_label_powerset(labels);
		//if (labels.length>1) Arrays.sort(labels);
		if (model.prior_lprobs!=null) {
			for (int label:labels) {
				Integer label2= label;
				Float lsp= model.prior_lprobs.get(label2);
				lsp= (lsp==null) ? (float) 0.0 : flogaddone(lsp);
				model.prior_lprobs.put(label2, lsp);
			}
		}
		if (model.node_links!=null) {
			int bo_label= -(labels[0]+1);
			model.node_links.put(model.train_count, bo_label);
			if (bo_label<model.min_encoded_label) model.min_encoded_label= bo_label;
			labels= new int[1];
			labels[0]= model.train_count;
		}
		model.train_count++;
		int t= 0, j;

		for (t= 0;t<terms.length;) counts[t]= (float)Math.log(counts[t++]);	
		if (label_weights!=null) for (t= 0;t<labels.length;) label_weights[t]= (float)Math.log(label_weights[t++]);
		//float norm= -1000000;
		//if (tfidf.use_tfidf==8) 
		//for (float count:counts) norm= (float)logsum(norm, count);
		for (t= 0; t<terms.length; t++) {
			int term= terms[t];
			Integer term2= new Integer(term);
			double prune= prune_count_insert;
			//if (tfidf.use_tfidf==1 || tfidf.use_tfidf==3 || tfidf.use_tfidf==5) prune-= Math.log(tfidf.get_idf(term2));
			if (tfidf.use_tfidf==1 || tfidf.use_tfidf==3 || tfidf.use_tfidf==5|| tfidf.use_tfidf==8) prune-= Math.log(tfidf.get_idf(term2));
			//if (tfidf.use_tfidf==8) 
			//prune+= norm; //approximate
			double lprob= counts[t];
			j= 0;
			for (int label:labels) {
				if (label_weights!=null) lprob+= label_weights[j++];
				else if (labels.length>1) lprob-= Math.log(labels.length);
				add_lprob(label, term, lprob, prune);
			}
		}
		//if (model.train_count % batch_size == 0) prune_counts(prune_count_insert, cond_hashsize);
	}

	public void add_lprob(int label, int term, double lprob2, double prune) {
		CountKey p_index= new CountKey(label, term);
		Float lprob= model.cond_lprobs.get(p_index);
		if (lprob==null) {
			label= -2147483648;
			if (model.cond_lprobs.size()==cond_hashsize) return;
			lprob= (float) lprob2;
		}
		else lprob= (float) logsum(lprob, lprob2);
		//System.out.println(label+" "+term+" "+lprob2+" "+prune); 
		if (lprob < prune) {if (label!=-2147483648) model.cond_lprobs.remove(p_index);}
		else model.cond_lprobs.put(p_index, lprob);
	}

	public double dlog(double number) {
		if (number==0.0) return -1000000;
		return Math.log(number);
	}

	public void make_bo_models() throws Exception{
		CountKey p_index= new CountKey();
		Hashtable<Integer, Double> norms= get_cond_norms(model.cond_lprobs);
		Hashtable<CountKey, Float> bo_lprobs= new Hashtable<CountKey, Float>();
		for (Map.Entry<CountKey, Float> entry : model.cond_lprobs.entrySet()) {
			p_index= entry.getKey();
			int label= p_index.label;
			float lprob2= (float)(entry.getValue()- norms.get((Integer)label));
			Integer term2= p_index.term;
			Float cond_bg= model.cond_bgs.get(term2);
			cond_bg= (cond_bg==null) ? lprob2 : (float)logsum(cond_bg, lprob2);
			model.cond_bgs.put(term2, cond_bg);
			if (model.min_encoded_label!=0) {
				Integer label2= model.node_links.get((Integer)p_index.label);
				CountKey p_index2= new CountKey(label2, p_index.term);
				Float lprob= bo_lprobs.get(p_index2);
				if (lprob==null) lprob= lprob2;
				else lprob= (float)logsum(lprob, lprob2);
				bo_lprobs.put(p_index2, lprob);
			}
		}
		//System.out.println(bo_lprobs.size()+" "+model.cond_lprobs.size()+" "+cond_hashsize);
		//if (bo_lprobs.size()+model.cond_lprobs.size()>cond_hashsize) prune_counts(-1000000.0, cond_hashsize-bo_lprobs.size());
		if (model.min_encoded_label!=0) 
			for (Map.Entry<CountKey, Float> entry : bo_lprobs.entrySet()) {
				p_index= entry.getKey();
				add_lprob(p_index.label, p_index.term, entry.getValue(), -1000000.0);
			}
		Iterator<Entry<Integer, Float>> entries= tfidf.idfs.entrySet().iterator();
		while (entries.hasNext()) {
			Entry<Integer,  Float> entry= (Entry<Integer,  Float>) entries.next();
			if (!model.cond_bgs.containsKey(entry.getKey())) entries.remove();
		}
	}

	public void prune_counts(double prune_count_table, int cond_hashsize) {
		//this.cond_hashsize= cond_hashsize;
		if (debug>0) System.out.println("Pruning conditional hash table:"+ model.cond_lprobs.size()+ " " + prune_count_table);
		Iterator<Entry<CountKey, Float>> entries= model.cond_lprobs.entrySet().iterator();
		while (entries.hasNext()) {
			Entry<CountKey,  Float> entry= (Entry<CountKey,  Float>) entries.next();
			float lprob= (Float) entry.getValue();

			//if (tfidf.use_tfidf!=0 && tfidf.use_tfidf!=2) lprob+= Math.log(tfidf.get_idf(((CountKey)entry.getKey()).term));
			if (tfidf.use_tfidf==1 || tfidf.use_tfidf==3 || tfidf.use_tfidf==8) lprob+= Math.log(tfidf.get_idf(((CountKey)entry.getKey()).term));
			//System.out.println(lprob+" "+tfidf.get_idf(((CountKey)entry.getKey()).term)+ " "+prune_count_table);
			if (lprob <= prune_count_table) entries.remove();
		}
		if (debug>0) System.out.println("Hash table pruned:"+ model.cond_lprobs.size());
		prune_counts_size(model.cond_lprobs, cond_hashsize);
	}

	public void prune_counts2(double prune_count_table) {
		if (debug>0) System.out.println("Pruning conditional hash table:"+ model.cond_lprobs.size()+ " " + prune_count_table);
		Iterator<Entry<CountKey, Float>> entries= model.cond_lprobs.entrySet().iterator();
		while (entries.hasNext()) {
			Entry<CountKey,  Float> entry= (Entry<CountKey,  Float>) entries.next();
			float lprob= (Float) entry.getValue();
			if (lprob <= prune_count_table) entries.remove();
		}
		if (debug>0) System.out.println("Hash table pruned:"+ model.cond_lprobs.size());
	}

	public void prune_counts_size(Hashtable<CountKey, Float> counts, int hashsize) {
		if (counts.size() > hashsize) {
			int bins= (int) Math.log(counts.size());
			int i= 0, j= 0;
			double tmp[]= new double[1+counts.size()/bins];
			for (Map.Entry<CountKey, Float> entry : counts.entrySet()) {
				if (i++%bins==0) {
					float lprob= (Float)entry.getValue();
					if (tfidf.use_tfidf==1 || tfidf.use_tfidf==3 || tfidf.use_tfidf==5) lprob+= Math.log(tfidf.get_idf(((CountKey)entry.getKey()).term));
					//if (tfidf.use_tfidf!=0 && tfidf.use_tfidf!=2) lprob+= Math.log(tfidf.get_idf(((CountKey)entry.getKey()).term));
					tmp[j++]= lprob;
				}
			}
			Arrays.sort(tmp);
			double prune = tmp[(counts.size() - hashsize)/bins];
			Iterator<Entry<CountKey, Float>> entries= counts.entrySet().iterator();
			while (entries.hasNext()) {
				Entry<CountKey, Float> entry= (Entry<CountKey, Float>)entries.next();
				float lprob= (Float)entry.getValue();
				//if (tfidf.use_tfidf!=0 && tfidf.use_tfidf!=2) lprob+= Math.log(tfidf.get_idf(((CountKey)entry.getKey()).term));
				if (tfidf.use_tfidf==1 || tfidf.use_tfidf==3 || tfidf.use_tfidf==5) lprob+= Math.log(tfidf.get_idf(((CountKey)entry.getKey()).term));
				if (lprob <= prune) entries.remove();
			}
		}
		if (debug>0) System.out.println("Hash table pruned:"+ model.cond_lprobs.size());
	}

	public void use_icfs() throws Exception {
		for (Iterator<Integer> d = tfidf.idfs.keySet().iterator(); d.hasNext();) {
			Integer term= d.next();
			Float idf= (float) -model.cond_bgs.get(term);
			tfidf.idfs.put(term, idf);
		}
	}

	public void apply_idfs() throws Exception {
		//if (tfidf.use_tfidf==0) return;
		for (Iterator<Integer> d = model.cond_bgs.keySet().iterator(); d.hasNext();) {
			Integer term= d.next();
			Float idf= (float)tfidf.get_idf(term);
			if (!tfidf.idfs.containsKey(term) || idf<=0.0) d.remove(); 
			else {
				if (tfidf.use_tfidf!=1 && tfidf.use_tfidf!=3) idf= (float) 1;
				Float lprob= model.cond_bgs.get(term) +(float) Math.log(idf);
				model.cond_bgs.put(term, lprob);
				//System.out.println(term+" "+lprob);
			}
		}
		for (Iterator<CountKey> e= model.cond_lprobs.keySet().iterator(); e.hasNext();) {
			CountKey p_index= e.next();
			Integer term= p_index.term;
			Float idf= (float)tfidf.get_idf(term);
			if (!tfidf.idfs.containsKey(term) || idf<=0.0) {
				//System.out.println(idf+" "+term+" "+tfidf.idfs.containsKey(term));
				e.remove();
			}
			else {
				if (tfidf.use_tfidf!=1 && tfidf.use_tfidf!=3) idf= (float) 1;
				Float lprob= (float)(model.cond_lprobs.get(p_index))+(float)Math.log(idf);
				//Float lprob= (float)(model.cond_lprobs.get(p_index))+(float)Math.log(tfidf.get_idf(term));
				model.cond_lprobs.put(p_index, lprob);
			}
		}
	}

	/*public void scale_conditionals(double cond_scale) throws Exception {
		if (debug>0) System.out.println("Scaling conditionals");
		for (Map.Entry<CountKey, Float> entry : model.cond_lprobs.entrySet()) entry.setValue((Float)(entry.getValue()*(float)cond_scale));
	}*/

	public Hashtable<Integer, Double> get_cond_norms(Hashtable<CountKey, Float> lprobs) throws Exception {
		Hashtable<Integer, Double> norms= new Hashtable<Integer, Double>();
		for (Map.Entry<CountKey, Float> entry : lprobs.entrySet()) {
			Integer label= ((CountKey)entry.getKey()).label;
			Double lsum= norms.get(label);
			if (lsum == null) lsum= -100000.0;
			lsum= logsum(lsum, entry.getValue());
			//lsum= logsum(lsum, entry.getValue()* Math.abs(cond_norm));
			norms.put(label, lsum);
		}
		return norms;
	}

	public void normalize_conditionals(Hashtable<Integer, Double> norms) throws Exception {
		//Hashtable<Integer, Double> norms= get_cond_norms(model.cond_lprobs);
		//if (Math.abs(cond_norm)!=1) for (Map.Entry<Integer, Double> entry : norms.entrySet()) entry.setValue(entry.getValue() / Math.abs(cond_norm));
		for (Map.Entry<CountKey, Float> entry : model.cond_lprobs.entrySet())
			entry.setValue((Float)(entry.getValue()- (float)(double)norms.get(((CountKey)entry.getKey()).label)));
		double[] tmp_vals;
		int t= 0;
		float norm;
		if (model.cond_bgs.size()>0) {
			tmp_vals= new double[model.cond_bgs.size()];
			for (Float lprob: model.cond_bgs.values()) tmp_vals[t++]= (double) lprob;
			norm= (float) logsum_doubles(tmp_vals);
			//for (Float lprob: model.cond_bgs.values()) tmp_vals[t++]= (double) lprob * Math.abs(cond_norm);
			//norm= (float)(logsum_doubles(tmp_vals) / Math.abs(cond_norm));
			for (Map.Entry<Integer, Float> entry : model.cond_bgs.entrySet()) entry.setValue((Float)(entry.getValue()- norm));
		}
	}

	public void normalize_priors() throws Exception {
		//normalize_conditionals();
		double[] tmp_vals;
		int t= 0;
		float norm;
		if (model.prior_lprobs!=null) {
			t= 0; tmp_vals= new double[model.prior_lprobs.size()];
			for (Float lprob: model.prior_lprobs.values()) tmp_vals[t++]= (double) lprob;
			norm= (float) logsum_doubles(tmp_vals);
			for (Map.Entry<Integer, Float> entry : model.prior_lprobs.entrySet()) entry.setValue((Float)(entry.getValue()- norm));
		}
	}

	public void smooth_conditionals(double bg_unif_smooth, double jelinek_mercer, double dirichlet_prior, double absolute_discount, double powerlaw_discount, double kernel_jelinek_mercer, double kernel_powerlaw_discount, double kernel_dirichlet_prior) throws Exception {
		//System.out.println("model.cond_bgs.size(): "+model.cond_bgs.size());
		jelinek_mercer= Math.max(jelinek_mercer, 1.0E-60);
		kernel_jelinek_mercer= Math.max(kernel_jelinek_mercer, 1.0E-60);
		double jm= Math.log(jelinek_mercer);
		double a5= Math.log(1.0-bg_unif_smooth); // + Math.log(jelinek_mercer);
		double bg_uniform= Math.log(bg_unif_smooth) - Math.log(model.cond_bgs.size());// + Math.log(jelinek_mercer);
		double ad= Math.log(absolute_discount);
		double pd= Math.log(powerlaw_discount);
		double dp= -1000000;
		//if (dirichlet_prior!=0) dp= logsum(dirichlet_prior, 0);
		if (dirichlet_prior!=0) dp= Math.log(dirichlet_prior*model.cond_bgs.size());

		Hashtable<Integer, Double> norms= get_cond_norms(model.cond_lprobs);
		if (powerlaw_discount== -1) {
			float ones= 0, twos= 0;
			for (Float lprob: model.cond_lprobs.values()) if (lprob<=2.00000001) {
				if (lprob<=1.00000001) ones+= 1;
				twos+= 1;
			}
			twos-= ones;
			powerlaw_discount= ones/(ones+twos*2); //Huang:10, Ney:04
			pd= Math.log(powerlaw_discount);
		}
		double norm;
		Hashtable<Integer, Double> norms2= norms;
		if (absolute_discount!=0 || powerlaw_discount!=0 || kernel_powerlaw_discount!=0) {
			Iterator<Entry<CountKey, Float>> entries= model.cond_lprobs.entrySet().iterator();
			while (entries.hasNext()) {
				Entry<CountKey,  Float> entry= (Entry<CountKey,  Float>) entries.next();
				float lprob= entry.getValue();

				Integer node= ((CountKey)entry.getKey()).label;
				double pd2= pd, powerlaw_discount2= powerlaw_discount;
				if (model.node_links!=null) {
					if (node>=0) {
						pd2= Math.log(kernel_powerlaw_discount);
						powerlaw_discount2= kernel_powerlaw_discount;
					}
				}
				if (absolute_discount!=0) lprob= (float) logsubtract(lprob, ad);
				if (powerlaw_discount2!=0) lprob= (float) logsubtract(lprob, pd2+lprob*powerlaw_discount2);
				entry.setValue(lprob);
			}
			norms2= get_cond_norms(model.cond_lprobs);
		} 
		model.bo_lweights= new Hashtable<Integer, Float>();
		for (Map.Entry<Integer, Double> entry: norms.entrySet()) {
			norm= entry.getValue();
			Double norm2= norms2.get(entry.getKey());
			if (norm2==null) norm2= norm;
			Integer node= entry.getKey();
			double jm2= jm;
			double dp2= dp;
			if (model.node_links!=null) {
				if (node>=0) {
					jm2= Math.log(kernel_jelinek_mercer);
					dp2= -1000000;
					if (kernel_dirichlet_prior!=0) dp2= Math.log(kernel_dirichlet_prior*model.cond_bgs.size());
				}
			}
			Float bo_weight= (float)(logsubtract(0, logsubtract(norm2, norm2+jm2) - logsum(norm, dp2)));
			model.bo_lweights.put(node, bo_weight);
		}
		norms= norms2;
		//if (cond_scale!=1.0) scale_conditionals(cond_scale);
		normalize_conditionals(norms);
		for (Map.Entry<Integer, Float> entry : model.cond_bgs.entrySet()) entry.setValue((Float)(float)(logsum(a5 + entry.getValue(), bg_uniform)));
		if (model.node_links==null) smooth_cond_nodes(-1000000, 1000000);
		else {
			//smooth_cond_nodes(-1000000, model.min_encoded_label);
			smooth_cond_nodes(model.min_encoded_label, 0);
			smooth_cond_nodes(0, 1000000);
		}

		/*if (cond_norm<0) {
			for (Map.Entry<Integer, Float> entry : model.cond_bgs.entrySet()) entry.setValue((float)Math.exp(entry.getValue()));
			for (Map.Entry<CountKey, Float> entry : model.cond_lprobs.entrySet()) entry.setValue((float)Math.exp(entry.getValue()));
		}*/

		if (model.node_links==null) precompute_cond_nodes(-1000000, 1000000);
		else {
			precompute_cond_nodes(0, 1000000);
			precompute_cond_nodes(model.min_encoded_label, 0);
			//precompute_cond_nodes(-1000000, model.min_encoded_label);
		}
	}

	public void precompute_cond_nodes(int top, int bottom) {
		CountKey p_index= new CountKey(), p_index2= new CountKey();
		float bo_lprob;
		Integer node, bo_node= null;
		for (Map.Entry<CountKey, Float> entry : model.cond_lprobs.entrySet()) {
			p_index= entry.getKey();
			if (p_index.label<top || p_index.label>=bottom) continue;
			p_index2.term= p_index.term;
			node= p_index.label;
			bo_lprob= model.bo_lweights.get(node);
			if (model.node_links!=null) bo_node= model.node_links.get(node);
			if (bo_node!=null) { 
				p_index2.label= bo_node;
				bo_lprob+= model.cond_lprobs.get(p_index2);
			}
			else bo_lprob+= model.cond_bgs.get(p_index.term);
			entry.setValue((float)entry.getValue()-bo_lprob);
		}
	}

	public void smooth_cond_nodes(int top, int bottom) {
		CountKey p_index= new CountKey(), p_index2= new CountKey();
		float bo_lprob, node_lweight;
		//System.out.println(top+" "+bottom);
		Integer node, bo_node= null;
		for (Map.Entry<CountKey, Float> entry : model.cond_lprobs.entrySet()) {
			p_index= entry.getKey();
			if (p_index.label<top || p_index.label>=bottom) continue;
			p_index2.term= p_index.term;
			node= p_index.label;
			bo_lprob= model.bo_lweights.get(node);
			node_lweight= (float)logsubtract(0, bo_lprob);
			if (model.node_links!=null) bo_node= model.node_links.get(node);
			if (bo_node!=null) { 
				p_index2.label= bo_node;
				bo_lprob+= model.cond_lprobs.get(p_index2);
			}
			else bo_lprob+= model.cond_bgs.get(p_index.term);
			entry.setValue((float)logsum(bo_lprob, node_lweight+entry.getValue()));
		}
	}

	public void smooth_prior(double prior_scale) throws Exception{
		normalize_priors();
		if (model.prior_lprobs!=null) {
			for (Map.Entry<Integer, Float> entry : model.prior_lprobs.entrySet()) entry.setValue((Float)(float) (entry.getValue() * prior_scale));
			//if (cond_norm<0) for (Map.Entry<Integer, Float> entry : model.prior_lprobs.entrySet()) entry.setValue((float)Math.exp(entry.getValue()));
		}
	}

	public final int[] intbuf_add(int number, int[] buf) {
		int buf_size2= buf.length + 1;
		int[] buf2= new int[buf_size2];
		int h= 0;
		for (int j: buf) 
			if (j < number) buf2[h++]= j; 
			else break;
		buf2[h++]= number;
		for (; h < buf_size2;) buf2[h]= buf[(h++)-1];
		return buf2;
	}

	public final int[] intbuf_add2(int number, int[] buf, int[] buf2) {
		int buf_size2= buf2.length;
		int h= 0;
		for (int j: buf) 
			if (j < number) buf2[h++]= j; 
			else break;
		buf2[h++]= number;
		for (; h < buf_size2;) buf2[h]= buf[(h++)-1];
		return buf2;
	}

	public final int[] intbuf_remove(int number, int[] buf) {
		int buf_size2= buf.length - 1;
		int[] buf2= new int[buf_size2];
		int h= 0;
		for (int j:buf) if (j != number) buf2[h++]= j; else break;
		for (; h < buf_size2;) buf2[h]= buf[++h];
		return buf2;
	}

	public double logsum(double val1, double val2) {
		if (val1+20.0 < val2) return val2;
		if (val2+20.0 < val1) return val1;
		if (val1 > val2) return Math.log(Math.exp(val2 - val1) + 1.0) + val1;
		return Math.log(Math.exp(val1 - val2) + 1.0) + val2;
	}

	public double logsubtract(double val1, double val2) {
		// Note: negative values floored to 0
		if (val2+20.0 < val1) return val1;
		if (val1 > val2) return Math.log(-Math.exp(val2 - val1) + 1.0) + val1;
		return (-1000000.0);
	}

	public float flogsum(float val1, float val2) {
		if (val1 > val2) return (float) Math.log(Math.exp(val2 - val1) + 1) + val1;
		else return (float) Math.log(Math.exp(val1 - val2) + 1) + val2;
	}

	public float flogaddone(float val1) {
		return (float) Math.log(Math.exp(val1) + 1.0);
	}

	public final double sum_doubles(double[] vals) {
		TreeSet<DoubleBuffer> treesort = new TreeSet<DoubleBuffer>();
		for (double val: vals) {
			double[] entry = {Math.abs(val), val};
			treesort.add(DoubleBuffer.wrap(entry));
		}             
		double sum= 0.0;
		for (Iterator<DoubleBuffer> e = treesort.descendingIterator(); e.hasNext();) sum+= e.next().get(1);	
		return sum;
		//while (treesort.size()>1){
		//   //Iterator<DoubleBuffer> e = treesort.descendingIterator();
		//    Iterator<DoubleBuffer> e = treesort.iterator();
		//    double val= e.next().get(1);
		//    e.remove();
		//    val+= e.next().get(1);
		//    e.remove();
		//    double[] entry = {Math.abs(val), val};
		//    treesort.add(DoubleBuffer.wrap(entry));
		//}
		//return treesort.first().get(1);
	}

	public final double logsum_doubles(double[] vals) {
		TreeSet<DoubleBuffer> treesort = new TreeSet<DoubleBuffer>();
		for (double val: vals) {
			double[] entry = {Math.abs(val), val};
			treesort.add(DoubleBuffer.wrap(entry));
		}
		//double sum= 0.0;
		double sum= -1000000.0;
		for (Iterator<DoubleBuffer> e = treesort.descendingIterator(); e.hasNext();) sum= logsum(sum, e.next().get(1));
		return sum;
	}

	public final double logsum_ndoubles(double[] vals) {
		//Note: Sorts original
		Arrays.sort(vals); //reduce double sum error
		double sum= -1000000.0;
		for (double val: vals) sum= logsum(val, sum);
		return sum;
	}

	public final double sum_ndoubles(double[] vals, int count) {
		Arrays.sort(vals, 0, count);
		double sum= 0.0;
		for (int i= 0; i<count;) sum+= vals[i++];
		return sum;
	}

	public final double sum_ndoubles(double[] vals) {
		//Note: Sorts original
		Arrays.sort(vals); //reduce double sum error
		double sum= 0.0;
		//double correct= 0.0;
		//double t, c;
		//for (double val: vals){
		//    val-= correct;
		//    t= sum + val;
		//    float tmp= (float)(t-sum); 
		//    correct= tmp- val;
		//    sum= t;
		//}

		for (double val: vals) sum+= val;
		return sum;

		//double mean= 0.0;
		//int i= 0;
		//for (double val: vals) mean+= (val - mean) / ++i;
		//return mean*i;
		//int fork= 1;
		//int length= vals.length;
		//while (fork< length) {
		//    for (int j= 0; j< length; j+= fork+fork) {
		//	if (j+fork< vals.length) vals[j]+= vals[j+fork];
		//	else {vals[j-fork-fork]+= vals[j]; length=j;}
		//	//System.out.println(j+" "+(j+fork)+" "+vals.length);
		//    }
		//   fork+=fork;
		//}
		//return vals[0];
	}


	/*
	  private final boolean EQ(double d1, double d2){
	  if (Math.abs(d1-d2)< 0.000000001)
	  return true;
	  return false;
	  }

	private final boolean GE(double d1, double d2){
		if (EQ(d1, d2)) return true;
		return GT(d1, d2);
	}

	private final boolean GT(double d1, double d2){
		if (d1> d2 + 0.000000001) return true;
		return false;
	}*/

	//public <T> void addToHash(T a, Hashtable<T> c) {
	//}

	public final SparseVector inference(int[] terms, float[] counts, double top_k, int max_retrieved) {
		Integer term2;
		float count;
		int term_count= 0;
		Hashtable<Integer, Double> lprobs= new Hashtable<Integer, Double>();
		float sum_counts= 0;
		double[] bg_lprobs= new double[terms.length];
		Iterator<Integer> e;
		Iterator<Float> g;
		for (int t= 0; t<terms.length; t++) {
			term2= terms[t];
			count= counts[t];

			//int[] nodes= inverted_index.get(term2).array();
			//float[] cond_lprobs= inverted_index2.get(term2).array();
			//for (int i= 0; i< nodes.length; i++) {
			//Integer node= nodes[i];
			//double lprob= cond_lprobs[i] * count;

			g= inverted_index2.get(term2).listIterator();
			for (e= inverted_index.get(term2).listIterator(); e.hasNext();) {
				Integer node= e.next();
				double lprob= (float) g.next() * count;

				if (constrain_labels>1 && node>=model.min_encoded_label) 
					if (model.node_links!=null) {if (!constrained_labels.contains(-(node+1))) continue;}	
					else if (!constrained_labels.contains(node)) continue;

				Double lprob2= lprobs.get(node);
				if (lprob2==null) lprob2= lprob;
				else lprob2+= lprob;
				lprobs.put(node, lprob2);
				//System.out.println(node+ " "+lprob+" "+ (lprob+ count * (model.cond_bgs.get(term2) + model.bo_lweights.get(node))) +" "+model.cond_bgs.get(term2)+ " "+ model.bo_lweights.get(node));
			}
			sum_counts+= count;
			bg_lprobs[term_count++]= model.cond_bgs.get(term2) * count;
		}
		//System.out.println(term_count);
		double sum_bg_lprob= sum_ndoubles(bg_lprobs, term_count);
		int n= 0;
		int[] node_sort= new int[lprobs.size()];
		for (Map.Entry<Integer,Double> entry: lprobs.entrySet()) node_sort[n++]= (int)entry.getKey();
		Arrays.sort(node_sort);
		TreeSet<DoubleBuffer> retrieve_sort= new TreeSet<DoubleBuffer>();

		double lprob, max_lprob= -1000000.0, topset_lprob= -1000000.0;
		Hashtable<Integer, Double> label_posteriors= new Hashtable<Integer, Double>();
		for (int i= 0; i<node_sort.length; i++) {
			Integer node= node_sort[i];
			if (node< model.min_encoded_label) continue;
			lprob= lprobs.get(node);
			//System.out.println(node+" "+lprob);

			Integer bo_node= null;
			if (model.node_links!=null) {
				bo_node= model.node_links.get(node);

				if (bo_node!=null) {
					Double lprob2= lprobs.get(bo_node);
					if (lprob2==null) lprob2= -1000000.0;
					lprob+= lprob2 + sum_counts* model.bo_lweights.get(node);
					//System.out.println(node+" "+bo_node +" "+model.bo_lweights.get(node)+" "+lprob);
				}
				else lprob+= sum_bg_lprob + sum_counts* model.bo_lweights.get(node);
				lprobs.put(node, lprob);

				if (node<0) {label_posteriors.put(-(node+1), -1000000.0); continue;}
				if (model.prior_lprobs!=null) lprob+= model.prior_lprobs.get(-(model.node_links.get(node)+1));
			} else {
				lprob+= sum_bg_lprob + sum_counts* model.bo_lweights.get(node);
				if (model.prior_lprobs!=null) lprob+= model.prior_lprobs.get(node);
			}

			if (lprob> topset_lprob) {
				double[] entry2 = {lprob, node};
				retrieve_sort.add(DoubleBuffer.wrap(entry2));
				if (lprob > max_lprob) max_lprob= lprob;
				if (retrieve_sort.size()> top_k) retrieve_sort.pollFirst();
				if (retrieve_sort.size()== top_k && top_k>1) topset_lprob= Math.max(max_lprob+label_threshold, retrieve_sort.first().array()[0]);
			}
		}

		if (constrain_labels<2 && retrieve_sort.size()==0 && label_posteriors.size()==0 && !full_posteriors) {
			SparseVector results= new SparseVector(2);
			//System.out.println(prior_max_label);
			results.indices[0]= prior_max_label;
			results.values[0]= (float)sum_bg_lprob;
			if (model.prior_lprobs!=null) results.values[0]+= model.prior_lprobs.get(prior_max_label);
			results.indices[1]= -1;
			return results;
		}

		Iterator<DoubleBuffer> f= retrieve_sort.descendingIterator();
		if (label_threshold>-1000000 && retrieve_sort.size()>0) {
			max_lprob= f.next().array()[0];
			f= retrieve_sort.iterator();
			while (f.hasNext()) if (max_lprob+label_threshold > f.next().array()[0])f.remove(); 
			else break;
			f= retrieve_sort.descendingIterator();
		}

		//System.out.println(node_sort.length+" "+label_posteriors.size()+ " "+retrieve_sort.size());
		int labelsize= retrieve_sort.size();
		//System.out.println(labelsize+" "+top_k);
		if (model.node_links!=null) {
			Hashtable<Integer, Integer> component_counts2= new Hashtable<Integer, Integer>();
			for (n= 0; n< labelsize; n++) {
				double[] entry2= f.next().array();
				Integer bo_node= -(model.node_links.get((int)entry2[1])+1);
				Integer count2= component_counts2.get(bo_node);
				if (model.prior_lprobs!=null) entry2[0]-= model.prior_lprobs.get(bo_node);

				Double lprob4= entry2[0] * Math.abs(combination);
				if (count2==null) count2= 1;
				else {
					count2++;
					lprob4= logsum(label_posteriors.get(bo_node), lprob4);
				}
				component_counts2.put(bo_node, count2);
				label_posteriors.put(bo_node, lprob4);
			}

			retrieve_sort= new TreeSet<DoubleBuffer>();
			int missing_count;
			for (Map.Entry<Integer, Double> entry : label_posteriors.entrySet()) {
				Integer label= entry.getKey();
				Integer label_node= -(label+1);
				double[] entry2 = {entry.getValue(), (int)label};
				Integer component_count= component_counts.get(label_node);
				Integer component_count2= component_counts2.get(label);
				if (component_count2==null) missing_count= component_count;
				else missing_count= component_count - component_count2;
				//System.out.println(label+" "+label_node+" "+missing_count+" "+component_count+" "+component_count2);
				if (missing_count!=0 && combination!=0) {
					Double lprob4= lprobs.get((Integer)label_node);
					//System.out.println(label+" "+bo_mean_lweights.size());
					if (lprob4==null) lprob4= -1000000.0;
					else lprob4+= sum_counts* bo_mean_lweights.get(label_node);
					entry2[0]= logsum(entry2[0], Math.log(missing_count)+ Math.abs(combination)*lprob4);
				}
				//System.out.println(entry2[0]+" "+label+" "+ bo_mean_lweights.get(label_node)+" "+component_counts.get(-(label+1)));
				//System.out.println(entry2[0]+" "+combination+" "+missing_count+" "+component_count);
				if (combination>0) entry2[0]= (entry2[0]- Math.log(component_count)) / Math.abs(combination);
				//if (combination>0) entry2[0]= (entry2[0]- Math.log(component_bolweight))/ combination;
				if (model.prior_lprobs!=null) entry2[0]+= model.prior_lprobs.get(label);
				retrieve_sort.add(DoubleBuffer.wrap(entry2));
			}
			f= retrieve_sort.descendingIterator();
		}

		HashSet<Integer> fill_nodes= new HashSet<Integer>();
		if (full_posteriors) {
			if (constrain_labels<2) fill_nodes= new HashSet<Integer>(model.prior_lprobs.keySet());
			else fill_nodes= new HashSet<Integer>(constrained_labels);
			for (; f.hasNext();) fill_nodes.remove((int)f.next().array()[1]);
			for (Integer label: fill_nodes){
				double[] entry2 = {sum_bg_lprob, (int)label};
				if (model.node_links!=null) {
					entry2[0]+= sum_counts* model.bo_lweights.get(label) * bo_mean_lweights.get(label);
					//Integer bo_node= model.node_links.get(-((int)entry2[1])+1);
					//if (bo_node!=null){Double lprob4= lprobs.get(bo_node);
				} else entry2[0]+= sum_counts* model.bo_lweights.get(label);
				if (model.prior_lprobs!=null) entry2[0]+= model.prior_lprobs.get(label);
				retrieve_sort.add(DoubleBuffer.wrap(entry2));
			}

			f= retrieve_sort.descendingIterator();
		}

		int labelsize2= Math.min(retrieve_sort.size(), max_retrieved);
		SparseVector result= new SparseVector(labelsize2+1);
		for (n= 0; n< labelsize2;) {
			double[] entry2= f.next().array();
			result.indices[n]= (int)entry2[1];
			result.values[n++]= (float)entry2[0];
		}
		float bg_score= (float) sum_bg_lprob;
		int missing= num_classes- labelsize2;
		if (constrain_labels>1) missing= Math.min(missing, constrained_labels.size()-labelsize2);
		//System.out.println(retrieve_sort.size()+" "+max_retrieved+" "+constrained_labels.size()+" "+missing);
		result.indices[labelsize2]= -1;
		result.values[labelsize2]= bg_score;

		if (norm_posteriors) {
			/*float q_entropy= 0;
	      double q_norm= 0;
	    for (float count2:counts) q_norm+= count2;
	    q_norm= Math.log(q_norm);
	    for (float count2:counts) {
	    double lprob2= Math.log(count2) - q_norm;
	    //double lprob2= logsum((count2 - q_norm +a1), u1);
		q_entropy-= (float)Math.exp(lprob2)* lprob2;
	    }
	    for (n= 0; n< labelsize2+1;) result.values[n++]+= q_entropy;
	    float sum= -1000000;
	    for (n= 0; n< labelsize2;) sum= (float)logsum(sum, result.values[n++]);
	    if (missing!= 0) sum= (float) logsum(sum, Math.log(missing)+ bg_score+ q_entropy);
            for (n= 0; n< labelsize2+1;) result.values[n++]-= sum;*/

			float sum= -1000000;
			for (n= 0; n< labelsize2;) sum= (float)logsum(sum, result.values[n++]);
			//System.out.println(sum);
			if (missing!= 0) sum= (float) logsum(sum, Math.log(missing)+ bg_score); //Note: not exact. bg_score depends on missing. Fix if needed
			for (n= 0; n< labelsize2+1;) result.values[n++]-= sum;
			//System.out.println(sum+" "+missing+" "+bg_score+" "+Math.log(missing)+" "+ bg_score+" "+num_classes);
		}
		return result;
	}

	public void prepare_inference(double top_k, int max_retrieved, double label_threshold, double combination, boolean full_posteriors, boolean norm_posteriors, int constrain_labels) {
		this.label_threshold= (float) label_threshold;
		this.max_retrieved= max_retrieved;
		this.full_posteriors= full_posteriors;
		this.norm_posteriors= norm_posteriors;
		this.combination= combination;
		this.constrain_labels= constrain_labels;
		if (model.prior_lprobs==null) {
			if (full_posteriors) model.prior_lprobs= new Hashtable<Integer, Float>();
			for (Enumeration<CountKey> e = model.cond_lprobs.keys(); e.hasMoreElements();) {
				CountKey key= e.nextElement();
				if (key.label<0) continue;
				prior_max_label= key.label;
				if (model.node_links!=null) prior_max_label= -(model.node_links.get(prior_max_label)+1);
				if (full_posteriors) {
					if (model.node_links==null || key.label<model.min_encoded_label) {Integer label= key.label; model.prior_lprobs.put(label, (float)0);}}
				else break;
			}
		}
		if (model.node_links!=null) {
			component_counts= new Hashtable<Integer, Integer>();
			bo_mean_lweights= new Hashtable<Integer, Double>();
			for (Map.Entry<Integer, Integer> entry : model.node_links.entrySet()) {
				Integer node= entry.getKey();
				Integer bo_node= entry.getValue();
				if (bo_node!=null) {
					Double bo_mean_lweight= bo_mean_lweights.get(bo_node);
					Float bo_mean_lweight2= model.bo_lweights.get(node);
					if (bo_mean_lweight2==null) bo_mean_lweight2= (float)0;
					if (bo_mean_lweight==null) bo_mean_lweight= (double)(float) bo_mean_lweight2;
					else bo_mean_lweight= logsum(bo_mean_lweight, (double)(float) bo_mean_lweight2);
					bo_mean_lweights.put(bo_node, bo_mean_lweight);
				}
				Integer count= component_counts.get(bo_node);
				if (count==null) count= 1; else count++;
				component_counts.put(bo_node, count);
			}
			for (Map.Entry<Integer, Double> entry : bo_mean_lweights.entrySet())
				entry.setValue(entry.getValue() - Math.log(component_counts.get(entry.getKey())));
		}
		//inverted_index= new Hashtable<Integer, IntBuffer>();
		//inverted_index2= new Hashtable<Integer, FloatBuffer>();
		inverted_index= new Hashtable<Integer, ArrayList<Integer>>();
		inverted_index2= new Hashtable<Integer, ArrayList<Float>>();

		HashSet<Integer> tmp_labelset= new HashSet<Integer>();
		//Hashtable<Integer, Integer> term_counts= new Hashtable<Integer, Integer>();
		for (Map.Entry<CountKey, Float> entry : model.cond_lprobs.entrySet()) {
			CountKey p_index= entry.getKey();
			tmp_labelset.add(p_index.label);
			Integer term= p_index.term;

			ArrayList<Integer> labels= inverted_index.get(term);
			if (labels == null) {
				labels= new ArrayList<Integer>(4);
				labels.add(p_index.label);
				inverted_index.put(term, labels);
			} else labels.add(p_index.label);
			ArrayList<Float> lprobs= inverted_index2.get(term);
			if (lprobs == null) {
				lprobs= new ArrayList<Float>(4);
				lprobs.add(entry.getValue());
				inverted_index2.put(term, lprobs);
			} else lprobs.add(entry.getValue());

			//Integer count= term_counts.get(term);
			//if (count==null) count= 1;
			//else count+= 1;
			//term_counts.put(term, count);
		}
		/*
	for (Map.Entry<Integer, Integer> entry : term_counts.entrySet()) {
	    Integer term= entry.getKey();
	    Integer count= entry.getValue();
	    int[] nodes= new int[count];
	    IntBuffer wrap_nodes= IntBuffer.wrap(nodes);
	    float[] lprobs= new float[count];
	    FloatBuffer wrap_lprobs= FloatBuffer.wrap(lprobs);
	    inverted_index.put(term, wrap_nodes);
	    inverted_index2.put(term, wrap_lprobs);
	    entry.setValue(0);
	}

	for (Map.Entry<CountKey, Float> entry : model.cond_lprobs.entrySet()) {
	    float lprob= entry.getValue();
	    CountKey p_index= entry.getKey();
	    Integer term= p_index.term;
	    Integer node= p_index.label;
	    //if (lprob==0) continue;
	    //System.out.println(node +" "+term+" "+lprob);
	    Integer count= term_counts.get(term);
	    ((IntBuffer)inverted_index.get(term)).put(count, node);
	    ((FloatBuffer)inverted_index2.get(term)).put(count, lprob);
	    term_counts.put(term, count+1);
	    }*/

		model.cond_lprobs= null;

		num_classes= tmp_labelset.size();
		this.top_k= (int)Math.max(1, top_k);
		//System.out.println(this.top_k);
		if (labels2powerset!=null) {
			powerset2labels= new Hashtable<Integer, IntBuffer>(labels2powerset.size());
			for (Enumeration<IntBuffer> d= labels2powerset.keys(); d.hasMoreElements();) {
				IntBuffer labels= d.nextElement();
				Integer powerset= labels2powerset.get(labels);
				//System.out.println(powerset+" "+labels.array());
				powerset2labels.put(powerset, labels);
				labels2powerset.remove(labels);
			}
		}
		if (model.prior_lprobs!=null) {
			float max_lprob= -1000000;
			for (Map.Entry<Integer, Float> entry : model.prior_lprobs.entrySet()) if (entry.getValue()> max_lprob) {
				max_lprob= entry.getValue();
				prior_max_label= entry.getKey();
			}
			num_classes= model.prior_lprobs.size();
		}
	}

	public SparseVector infer_posterior(int[] terms, float[] counts, double feedback_weight) throws Exception {
		if (tfidf.use_tfidf==1 || tfidf.use_tfidf==2 || tfidf.use_tfidf==6 || tfidf.use_tfidf==7) tfidf.length_normalize(terms, counts);
		int j= 0;
		for (int t= 0; t<terms.length; t++) {
			Integer term2= terms[t];
			float count= counts[t];
			if (!inverted_index.containsKey(term2)) continue;
			if (tfidf.use_tfidf==1 || tfidf.use_tfidf==3 || tfidf.use_tfidf==8) count*= tfidf.get_idf(term2);
			terms[j]= term2;
			counts[j++]= count;
		}
		if (j!=terms.length) {
			counts= Arrays.copyOf(counts, j);
			terms= Arrays.copyOf(terms, j);
		}

		//
		SparseVector inference_results= null;
		if (feedback_weight>0) inference_results= inference(terms, counts, top_k, top_k);
		else inference_results= inference(terms, counts, top_k, max_retrieved);

		if (feedback_weight>0) {
			int[] feedback_labels= Arrays.copyOf(inference_results.indices, inference_results.indices.length);
			float[] feedback_counts= new float[terms.length];
			Hashtable<Integer, Float> feedback= new Hashtable<Integer, Float>();

			double sum_fb_lweights= -1000000, sum_bo_lweights= -1000000;
			for (int t= 0; t<feedback_labels.length-1; t++) {
				Integer label= feedback_labels[t];
				Float fb_lweight= (float)inference_results.values[t];
				//fb_lweight= (float)Math.log((1.0/(t+1)));
				feedback.put(label, fb_lweight);
				sum_fb_lweights= logsum(sum_fb_lweights, fb_lweight);
				Float bo_lweight= model.bo_lweights.get(label);
				sum_bo_lweights= logsum(sum_bo_lweights, bo_lweight+fb_lweight);
			}
			Iterator<Integer> e;
			Iterator<Float> g;
			for (int t= 0; t<terms.length; t++) {
				Integer term2= terms[t];
				float count= (float) (model.cond_bgs.get(term2)+ sum_bo_lweights);

				//int[] nodes= inverted_index.get(term2).array();
				//float[] cond_lprobs= inverted_index2.get(term2).array();
				//for (int i= 0; i< nodes.length; i++) {
				//Integer node= nodes[i];
				//double lprob= cond_lprobs[i];

				g= inverted_index2.get(term2).listIterator();
				for (e= inverted_index.get(term2).listIterator(); e.hasNext();) {
					Integer node= e.next();
					double lprob= (float) g.next();

					if (!feedback.containsKey(node)) continue;
					float posterior= (float)(feedback.get(node)- sum_fb_lweights);
					count= (float)logsubtract(count, model.cond_bgs.get(term2)+ model.bo_lweights.get(node) + posterior);
					count= (float)logsum(count, lprob+model.cond_bgs.get(term2)+ model.bo_lweights.get(node) + posterior);
				}
				//System.out.println(t+" "+count+" "+(float)Math.exp(count));
				feedback_counts[t]= (float)Math.exp(count);
			}

			double sum= 0, sum2= 0;
			for (float count:counts) sum+= count;
			for (float count:feedback_counts) sum2+= count;
			if (sum2==0 || feedback_weight==0) sum2= 0; else sum2= sum*(feedback_weight/sum2);
			if (feedback_weight!=1) sum=(1.0-feedback_weight);

			//System.out.println(sum+" "+sum2+" "+feedback_labels.length);
			for (int t= 0; t< counts.length; t++) feedback_counts[t]= (float)(feedback_counts[t]*sum2 + counts[t] * sum);
			inference_results= inference(terms, feedback_counts, top_k, max_retrieved);
		}
		if (powerset2labels!=null) {
			//SparseVector results= new SparseVector(powerset2labels.get((Integer)(int)f.next().array()[1]).array());
			//results.values= new float[1];
			//results.values[0]= (float)max_lprob;
			int[] labels2= powerset2labels.get((Integer)inference_results.indices[0]).array();
			inference_results= new SparseVector(Arrays.copyOf(labels2, labels2.length+1));
			inference_results.indices[labels2.length]= -1;
		}
		return inference_results;
	}

	public void infer_posteriors(PrintWriter resultsf, double feedback_weight) throws Exception {
		int[] labels;
		for (int w= 0; w < data.doc_count; w++) {
			labels= data.labels[w];
			if (constrain_labels>0) {
				float[] label_weights= data.label_weights[w];
				constrained_labels= new HashSet<Integer>(labels.length);
				int label_count= 0;
				HashSet<Integer> tmp_labels= new HashSet<Integer>(); //hack fix
				for (int i= 0; i < labels.length; i++) {
					if (!tmp_labels.contains((Integer)labels[i])){
						tmp_labels.add(labels[i]);
						constrained_labels.add((Integer)labels[i]);
						if (label_weights[i]>0) label_count++;
					} else label_weights[i]= 0;
				}
				if (constrain_labels%2== 1) {
					int[] labels2= new int[label_count];
					label_count= 0;
					for (int i= 0; i < labels.length; i++) if (label_weights[i]>0) labels2[label_count++]= labels[i];
					labels= labels2;
				}
			}
			//
			if (labels.length==0) continue;
			int[] terms= data.terms[w];
			float[] counts= data.counts[w];
			SparseVector inference_results= infer_posterior(terms, counts, feedback_weight);
			if (resultsf == null) {
				update_evaluation_results(inference_results.indices, inference_results.values,  labels, 1);
			} else {
				String results = "";
				//System.out.println(inference_results.indices.length);
				for (int n = 0; n < inference_results.indices.length-1; n++)
					//results += inference_results.indices[n]+":"+inference_results.values[n] + " ";
					results += inference_results.indices[n]+" ";
				resultsf.println(results.trim());
			}
		}
	}

	public void use_powerset() {
		labels2powerset= new Hashtable<IntBuffer, Integer>();
	}

	public void kernel_densities() {
		model.node_links= new Hashtable<Integer, Integer>();
	}

	public void prepare_evaluation() {
		//prior_max_label= model.cond_lprobs.keys().nextElement().label;
		//if (powerset2labels!=null) prior_max_label= powerset2labels.get(prior_max_label).get(0);
		num_classified= tp= fp= fn= tp0= fp= fn0= num_labels_classified= 0;
		rec= prec= fscore= rec0= prec0= fscore0= map= 0;// mapErrors= wAcc= 0;
	}

	private void update_evaluation_results(int[] labels, float[] scores, int[] ref_labels, int print_results) {
		String ref= num_classified + " Ref:"+Arrays.toString(ref_labels), res= num_classified + " Res:"+Arrays.toString(labels);
		HashSet<Integer> ref_labels2= new HashSet<Integer>(ref_labels.length);
		for (int label:ref_labels) ref_labels2.add((Integer)label); 
		int tp2= 0, fp2= 0;
		double ap= 0.0;
		int labels_length= labels.length-1;
		num_classified++;
		//System.out.println(labels_length+" "+ref_labels.length+" "+constrained_labels.size());
		int map_div= Math.min(max_retrieved, ref_labels.length);
		int m= 0;
		for (int label:labels) {
			if (label==-1) continue;
			if (ref_labels2.contains((Integer)label)) {
				//wAcc+= Math.exp(scores[m]);
				tp++;
				tp2++;
				//ap+= ((double)tp2/(tp2 + fp2)) / labels_length2;
				ap+= ((double)tp2/(tp2 + fp2))/map_div;
			} else {
				//if (tp2!=ref_labels.length) mapErrors+= 1;
				//wAcc-= Math.exp(scores[m]);
				fp++; 
				fp2++;
				//ap+= ((double)tp2/(tp2 + fp2)) / labels_length2;
				//ap+= ((double)tp2/(tp2 + fp2)) /max_retrieved;
			}
			m++; num_labels_classified++;
		}
		//if (labels_length<max_retrieved) for (int i= labels_length; i<=max_retrieved; i++) ap+= tp2/i;
		//System.out.println(num_classified+" "+ ap+" "+max_retrieved+" "+ref_labels.length);
		if (labels_length==0) ap= 0; else
			if (tp2<map_div) for (int i= tp2; i<map_div; i++) ap+= ((double)tp2/(i + fp2))/map_div;
		double jaccard= (double)tp2/(labels_length+ref_labels.length-tp2);
		meanjaccard+= (jaccard-meanjaccard)/num_classified;
		fn+= ref_labels.length - tp2;
		rec= (double) tp / (tp + fn);
		prec= (double) tp / (tp + fp);
		fscore= (2.0 * rec * prec) / (rec + prec);

		map+= (ap-map)/num_classified;
		if ((rec == 0 && prec == 0) || (tp + fp==0) || (tp + fn==0)) fscore= 0;
		System.out.println(res);
		System.out.println(ref + "      TP:" + tp + " FN:" + fn + " FP:" + fp + " meanJaccard:"+meanjaccard+" miFscore:" + fscore + " MAP:" + map);
	}

	public void print_evaluation_summary() {
		//String res= "";
		System.out.println("Results: meanJaccard:"+meanjaccard+" miFscore:" +fscore+ " MAP:" +map);//+ " mapErrors:" + mapErrors+" wAcc:"+wAcc);
		//System.out.println("Fscore: " +fscore+ "  " +res);
	}

	public void open_stream(String data_file, int docs, boolean use_label_weights) throws Exception {
		if (debug>0) System.out.println("SGM opening data stream: " + data_file);
		input_file= new BufferedReader(new FileReader(data_file));
		data= new SparseData(docs, use_label_weights);
		//if (data==null || docs!=data.doc_count) data= new SparseData(-1, docs, -1);
	}

	public void close_stream() throws Exception {
		input_file.close();
	}

	public int get_features(int docs) throws Exception {
		int w= 0;
		w= read_libsvm_stream(docs);
		return w;
	}

	public int read_libsvm_stream(int docs) throws Exception {
		String l;
		String[] splits, s;
		int[] labels, terms;
		float[] counts, label_weights= null;
		int w= 0;
		for (; w < docs; w++) {
			if ((l = input_file.readLine()) == null) break;
			int term_c= 0, i= 0;//, length= 0;
			for (char c: l.toCharArray()) if (c==':') term_c++;
			splits= l.split(" ");
			//System.out.println(splits.length+" "+term_c);
			int label_c= splits.length - term_c;
			data.labels[w]= labels= new int[label_c];
			data.terms[w]= terms= new int[term_c];
			data.counts[w]= counts= new float[term_c];
			if (data.label_weights!=null) data.label_weights[w]= label_weights= new float[label_c];
			for (; i < label_c; i++) {
				s= splits[i].split(",")[0].split(";");
				labels[i]= Integer.decode(s[0]);
				if (data.label_weights!=null)
					if (s.length>1) label_weights[i]= new Float(s[1]);
					else label_weights[i]= 1;
				//if (s.length>1 && data.label_weights!=null) label_weights[i]= new Float(s[1]);
			}
			for (; i < splits.length;) {
				//System.out.println(splits[i]);
				s= splits[i].split(":");
				Integer term= Integer.decode(s[0]);
				terms[i - label_c]= term;
				//counts[i++ - label_c]= (float)Integer.decode(s[1]);
				counts[i++ - label_c]= (float)Float.parseFloat(s[1]);
			}
		}
		if (w != docs) data.doc_count = w;
		return w;
	}

	public void save_model(String model_name) throws Exception {
		PrintWriter model_file = new PrintWriter(new FileWriter(model_name));
		model_file.println("train_count: " + model.train_count);
		if (model.prior_lprobs!=null) model_file.println("prior_lprobs: " + model.prior_lprobs.size());
		else model_file.println("prior_lprobs: 0");
		if (labels2powerset!=null) model_file.println("labels2powerset: " + labels2powerset.size());
		else model_file.println("labels2powerset: 0");
		model_file.println("tf_idf.normalized: "+ tfidf.normalized);
		model_file.println("idfs: " + tfidf.idfs.size());
		model_file.println("cond_bgs: " + model.cond_bgs.size());
		model_file.println("lprobs: " + model.cond_lprobs.size());
		if (model.node_links!=null) model_file.println("node_links: " + model.node_links.size());
		else model_file.println("node_links: 0");
		model_file.println("model.min_encoded_label: "+ model.min_encoded_label);
		if (model.prior_lprobs!=null)
			for (Map.Entry<Integer, Float> entry : model.prior_lprobs.entrySet()) model_file.println(entry.getKey()+" "+entry.getValue());
		if (labels2powerset!=null) 
			for (Enumeration<IntBuffer> d = labels2powerset.keys(); d.hasMoreElements();) {
				IntBuffer in = d.nextElement();
				int[] labelset= in.array();
				String tmp= "";
				for (int i= 0; i < labelset.length; i++) tmp+= labelset[i] + " ";
				model_file.println(tmp + labels2powerset.get(in));
			}
		for (Enumeration<Integer> d = tfidf.idfs.keys(); d.hasMoreElements();) {
			Integer in = d.nextElement();
			model_file.println(in + " " + tfidf.idfs.get(in));
		}
		for (Enumeration<Integer> d = model.cond_bgs.keys(); d.hasMoreElements();) {
			Integer in = d.nextElement();
			model_file.println(in + " " + model.cond_bgs.get(in));
		}
		for (Enumeration<CountKey> d = model.cond_lprobs.keys(); d.hasMoreElements();) {
			CountKey in = d.nextElement();
			model_file.println(in.label + " " + in.term + " " + model.cond_lprobs.get(in));
		}
		if (model.node_links!=null) for (Enumeration<Integer> d = model.node_links.keys(); d.hasMoreElements();) {
			Integer in = d.nextElement();
			model_file.println(in + " " + model.node_links.get(in));
		}
		model_file.close();
	}

	public void load_model(String model_name) throws Exception {
		model= new SGM_Params(10000000);
		BufferedReader input= new BufferedReader(new FileReader(model_name));
		model.train_count= tfidf.train_count= new Integer(input.readLine().split(" ")[1]);
		int prior_lprobs= new Integer(input.readLine().split(" ")[1]);
		int labels2powersets= new Integer(input.readLine().split(" ")[1]);
		tfidf.normalized= new Integer(input.readLine().split(" ")[1]);
		int idfs= new Integer(input.readLine().split(" ")[1]);
		int cond_bgs= new Integer(input.readLine().split(" ")[1]);
		int lprobs= new Integer(input.readLine().split(" ")[1]);
		int node_links= new Integer(input.readLine().split(" ")[1]);
		if (node_links!=0) model.node_links= new Hashtable<Integer, Integer>(node_links);
		model.min_encoded_label= new Integer(input.readLine().split(" ")[1]);
		if (prior_lprobs==0) model.prior_lprobs= null;
		while (prior_lprobs > 0) {
			String[] s= input.readLine().split(" ");
			Integer label= new Integer(s[0]);
			Float lprob = new Float(s[1]);
			model.prior_lprobs.put(label, lprob);
			prior_lprobs-= 1;
		}
		while (labels2powersets > 0) {
			String[] s= input.readLine().split(" ");
			int[] labelset = new int[s.length - 1];
			IntBuffer wrap_labelset = IntBuffer.wrap(labelset);
			for (int i = 0; i < labelset.length; i++) labelset[i] = new Integer(s[i]);
			Integer label= new Integer(s[s.length - 1]);
			labels2powerset.put(wrap_labelset, label);
			labels2powersets-= 1;
		}
		while (idfs > 0) {
			String[] s= input.readLine().split(" ");
			Integer label= new Integer(s[0]);
			Float idf= new Float(s[1]);
			tfidf.idfs.put(label, idf);
			idfs-= 1;
		}
		while (cond_bgs > 0) {
			String[] s= input.readLine().split(" ");
			Integer label= new Integer(s[0]);
			Float smooth= new Float(s[1]);
			model.cond_bgs.put(label, smooth);
			cond_bgs-= 1;
		}
		while (lprobs > 0) {
			String[] s= input.readLine().split(" ");
			Float lprob= new Float(s[2]);
			CountKey p_index= new CountKey(new Integer(s[0]), new Integer(s[1]));
			model.cond_lprobs.put(p_index, lprob);
			lprobs-= 1;
		}
		while (node_links > 0) {
			String[] s= input.readLine().split(" ");
			Integer node= new Integer(s[0]);
			Integer bo_node= new Integer(s[1]);
			model.node_links.put(node, bo_node);
			node_links-= 1;
		}
		input.close();
	}

}
