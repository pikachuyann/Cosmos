package weka.classifiers.rules.modlem;

/**
 * Entity which represents single relation on attribute
 * 
 * @author Szymon Wojciechowski
 */

import java.io.Serializable;
import java.util.ArrayList;
import java.util.BitSet;
import java.util.List;

import weka.core.Instance;
import weka.core.Instances;
import weka.core.Utils;

public class RuleCondition implements Serializable, Cloneable
{	
	public static final int Lesser = 1;
	public static final int GreaterEqual = 2;
	public static final int Between = 3;
	public static final int Contains = 4;
	
	public RuleCondition(int p_attribute, int p_relation, Double p_value, BitSet p_coverage)
	{
		m_attribute = p_attribute;
		m_coverage = p_coverage;
		m_relation = p_relation;
		m_usage = false;
		if(p_value != null)
		{
			m_values.add(p_value);
		}
	}

	public RuleCondition clone()
	{
		RuleCondition object = null;
		try
		{
			object = (RuleCondition) super.clone();
		}
		catch (CloneNotSupportedException e)
		{
			throw new UnsupportedOperationException("RuleCondition's clone() failed");
		}
		
		object.m_attribute = m_attribute;
		object.m_coverage = (BitSet) m_coverage.clone();
		object.m_evaluation = m_evaluation;
		object.m_nrOfPositives = m_nrOfPositives;
		object.m_relation = m_relation;
		object.m_usage = m_usage;
		object.m_values = new ArrayList<Double>();
		object.m_values.addAll(m_values);
		
		return object;
	}
	
	public boolean contains(double p_value)
	{
		for (Double value : m_values)
		{
			if (p_value == value)
			{
				return true;
			}
		}
		return false;
	}

	public boolean covers(Instance p_instance)
	{
		if(p_instance.isMissing(m_attribute))
		{
			return true;
		}
		
		double value = p_instance.value(m_attribute);
		switch (m_relation)
		{
			case Lesser:
			{
				return value < m_values.get(0);
			}
			case GreaterEqual:
			{
				return value >= m_values.get(0);
			}
			case Between:
			{
				return value >= m_values.get(0) && value < m_values.get(1);
			}
			case Contains:
			{
				return contains(value);
			}
			default:
				return false;
		}
	}

	public void extend(double p_value)
	{
		m_values.add(p_value);
	}
	
	public int getAttribute()
	{
		return m_attribute;
	}
	
	public BitSet getCoverage()
	{
		return m_coverage;
	}
	
	public double getEvaluation()
	{
		return m_evaluation;
	}

	public int getNrOfPositives()
	{
		return m_nrOfPositives;
	}
	
	public int getRelationType()
	{
		return m_relation;
	}
	
	public List<Double> getValues()
	{
		return m_values;
	}

	public boolean isUsed()
	{
		return m_usage;
	}
	
	public void mergeNumerical(RuleCondition p_selector)
	{
		if(m_relation == GreaterEqual)
		{
			if(p_selector.m_relation == GreaterEqual)
			{
				m_values.set(0, Math.max(m_values.get(0), p_selector.m_values.get(0)));
			}
			else if(p_selector.m_relation == Lesser)
			{
				m_values.add(p_selector.m_values.get(0));
				m_relation = Between;
			}						
		}
		else if(m_relation == Lesser)
		{
			if(p_selector.m_relation == GreaterEqual)
			{
				m_values.add(0, p_selector.m_values.get(0));
				m_relation = Between;
			}
			else if(p_selector.m_relation == Lesser)
			{
				m_values.set(0, Math.min(m_values.get(0), p_selector.m_values.get(0)) );
			}							
		}
		else if(m_relation == Between)
		{
			if(p_selector.m_relation == GreaterEqual)
			{
				m_values.set(0, Math.max(m_values.get(0), p_selector.m_values.get(0)) );
			}
			else if(p_selector.m_relation == Lesser)
			{
				m_values.set(1, Math.min(m_values.get(1), p_selector.m_values.get(0)) );
			}								
		}
		else
		{
			throw new UnsupportedOperationException("Unsupported selector type: " + m_relation);
		}
	}
	
	public void setEvaluation(double p_evaluation)
	{
		this.m_evaluation = p_evaluation;
	}
		
	public void setNrOfPositives(int p_nrOfPositives)
	{
		this.m_nrOfPositives = p_nrOfPositives;
	}
	
	public void setUsed(boolean p_usage)
	{
		this.m_usage = p_usage;
	}
	
	public String toString(Instances data)
	{
		StringBuffer output = new StringBuffer();
		output.append("(" + data.attribute(m_attribute).name());
		switch (m_relation)
		{
			case Lesser:
			{
				output.append(" < " + Utils.doubleToString(m_values.get(0), 2));
				break;
			}
			case GreaterEqual:
			{
				output.append(" >= " + Utils.doubleToString(m_values.get(0), 2));
				break;
			}
			case Between:
			{
				output.append(" in [" +
							Utils.doubleToString(m_values.get(0), 2)+ ", " +
							Utils.doubleToString(m_values.get(1), 2)+ "]");
				break;
			}
			case Contains:
			{
				output.append(" in {");
	
				for (int i = 0; i < m_values.size(); )
				{
					output.append(data.attribute(m_attribute).value(m_values.get(i).intValue()));
					++i;
					
					if (i < m_values.size())
					{
						output.append(", ");
					}
				}
				output.append("}");
				break;
			}
		}
		output.append(")");
		return output.toString();
	}
				
	private int m_attribute;
	private BitSet m_coverage;
	private double m_evaluation;
	private int m_nrOfPositives;
	private int m_relation;
	private boolean m_usage;
	private List<Double> m_values = new ArrayList<Double>();
	private static final long serialVersionUID = -5040472529910807683L;
}
