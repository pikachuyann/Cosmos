package weka.classifiers.rules.modlem.strategies;

import static weka.classifiers.rules.modlem.Constants.CHI_SQUARE;
import static weka.classifiers.rules.modlem.Constants.DEFAULT_CLASS;
import static weka.classifiers.rules.modlem.Constants.M_ESTIMATE;
import static weka.classifiers.rules.modlem.Constants.MEASURE_OF_DISCRIMINATION;
import static weka.classifiers.rules.modlem.Constants.NEAREST_RULES;
import static weka.classifiers.rules.modlem.Constants.STRENGTH_AND_SPECIFICITY;

import static weka.classifiers.rules.modlem.Constants.FULL_MATCHING;
import static weka.classifiers.rules.modlem.Constants.PARTIAL_MATCHING_OFF;

import java.io.Serializable;
import java.util.BitSet;
import java.util.List;

import weka.core.Instance;
import weka.core.Instances;
import weka.core.Utils;
import weka.classifiers.rules.modlem.DataSetMapper;
import weka.classifiers.rules.modlem.MLRule;

/**
 * Abstract class implementing classification strategy.
 * 
 * @author Szymon Wojciechowski
 */
public abstract class ClassificationStrategy implements Serializable
{		
	public static ClassificationStrategy createClassificationStrategy(int classificationStrategy, Instances dataset, List<MLRule> rules, int matchingMode, DataSetMapper dataSetMapper)
	{
		switch(classificationStrategy)
		{
			case CHI_SQUARE:
				return new ChiSquareStrategy(dataset, rules, matchingMode, dataSetMapper);
			case DEFAULT_CLASS:
				return new DefaultClassStrategy(dataset, rules, matchingMode, dataSetMapper);
			case M_ESTIMATE:
				return new MEstimateStrategy(dataset, rules, matchingMode, dataSetMapper);
			case MEASURE_OF_DISCRIMINATION:
				return new MeasureOfDiscriminationStrategy(dataset, rules, matchingMode, dataSetMapper);
			case NEAREST_RULES:
				return new NearestRulesStrategy(dataset, rules, matchingMode, dataSetMapper);
			case STRENGTH_AND_SPECIFICITY:
				return new StrengthAndSpecificityStrategy(dataset, rules, matchingMode, dataSetMapper);
			default:
				throw new UnsupportedOperationException("Unsupported classification strategy");
		}
	}
	
	public ClassificationStrategy(Instances dataset, List<MLRule> rules, int abstainingStatus, DataSetMapper dataSetMap)
	{
		m_abstainingInfo = abstainingStatus;
		m_data = dataset;
		m_dataSetMap = dataSetMap;
		m_rules = rules;
	}

	/**
	 * Classifies the given test instance. The instance has to belong to a
	 * dataset when it's being classified. Note that a classifier MUST implement
	 * either this or distributionForInstance().
	 * 
	 * @param instance
	 *            the instance to be classified
	 * @return the predicted most likely class for the instance or
	 *         Instance.missingValue() if no prediction is made
	 * @exception Exception
	 *                if an error occurred during the prediction
	 */
	public double classifyInstance(Instance instance)
	{
		double result = Double.NaN;
		double[] distribution = distributionForInstance(instance);				
				
		if (!Utils.eq(Utils.sum(distribution), 0))
		{
			result = Utils.maxIndex(distribution);
		}
		return result;
	}

	/**
	 * Predicts the class memberships for a given instance. If an instance is
	 * unclassified, the returned array elements must be all zero. If the class
	 * is numeric, the array must consist of only one element, which contains
	 * the predicted value. Note that a classifier MUST implement either this or
	 * classifyInstance().
	 * 
	 * @param instance
	 *            the instance to be classified
	 * @return an array containing the estimated membership probabilities of the
	 *         test instance in each class or the numeric prediction
	 * @exception Exception
	 *                if distribution could not be computed successfully
	 */
	private double[] distributionForInstance(Instance instance)
	{		
		double[] distribution = new double[m_data.numClasses()];
		BitSet coveredClasses = new BitSet(m_data.numClasses());
		BitSet coveringRules = new BitSet(m_rules.size());
		
		for (int i = 0; i < m_rules.size(); ++i)
		{
			if (m_rules.get(i).covers(instance))
			{
				coveringRules.set(i);
				coveredClasses.set( (int)m_rules.get(i).getConsequent() );
			}
		}

		if (coveredClasses.cardinality() == 1)
		{
			distribution[(int)(m_rules.get(coveringRules.nextSetBit(0))).getConsequent()] = 1;
		}
		else if (coveredClasses.cardinality() > 1 && (m_abstainingInfo == FULL_MATCHING || m_abstainingInfo == PARTIAL_MATCHING_OFF))
		{			
			multiple(distribution, coveringRules);
		}
		else if ((coveredClasses.cardinality() == 0) && (m_abstainingInfo == FULL_MATCHING))
		{	
			partial(distribution, instance);
		}
				
		if (!Utils.eq(Utils.sum(distribution), 0))
		{
			Utils.normalize(distribution);
		}
		
		return distribution;
	}
	
	public abstract void multiple(double[] result, BitSet coveringRules);
	
	public abstract void partial(double[] result, Instance instance);
		
	protected int m_abstainingInfo = FULL_MATCHING;
	protected Instances m_data;
	protected DataSetMapper m_dataSetMap;
	protected List<MLRule> m_rules;
	private static final long serialVersionUID = -3352779366764870922L;
}
