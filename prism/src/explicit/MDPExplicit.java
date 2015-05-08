//==============================================================================
//	
//	Copyright (c) 2002-
//	Authors:
//	* Dave Parker <david.parker@comlab.ox.ac.uk> (University of Oxford)
//	* Christian von Essen <christian.vonessen@imag.fr> (Verimag, Grenoble)
//	
//------------------------------------------------------------------------------
//	
//	This file is part of PRISM.
//	
//	PRISM is free software; you can redistribute it and/or modify
//	it under the terms of the GNU General Public License as published by
//	the Free Software Foundation; either version 2 of the License, or
//	(at your option) any later version.
//	
//	PRISM is distributed in the hope that it will be useful,
//	but WITHOUT ANY WARRANTY; without even the implied warranty of
//	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//	GNU General Public License for more details.
//	
//	You should have received a copy of the GNU General Public License
//	along with PRISM; if not, write to the Free Software Foundation,
//	Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//	
//==============================================================================

package explicit;

import java.util.*;
import java.io.*;

import explicit.rewards.MDPRewards;
import prism.ModelType;
import prism.PrismException;
import prism.PrismLog;
import prism.PrismUtils;

/**
 * Base class for explicit-state representations of an MDP.
 */
public abstract class MDPExplicit extends ModelExplicit implements MDP
{
	// Accessors (for Model)
	
	@Override
	public ModelType getModelType()
	{
		return ModelType.MDP;
	}

	@Override
	public String infoString()
	{
		String s = "";
		s += numStates + " states (" + getNumInitialStates() + " initial)";
		s += ", " + getNumTransitions() + " transitions";
		s += ", " + getNumChoices() + " choices";
		s += ", dist max/avg = " + getMaxNumChoices() + "/" + PrismUtils.formatDouble2dp(((double) getNumChoices()) / numStates);
		return s;
	}

	@Override
	public String infoStringTable()
	{
		String s = "";
		s += "States:      " + numStates + " (" + getNumInitialStates() + " initial)\n";
		s += "Transitions: " + getNumTransitions() + "\n";
		s += "Choices:     " + getNumChoices() + "\n";
		s += "Max/avg:     " + getMaxNumChoices() + "/" + PrismUtils.formatDouble2dp(((double) getNumChoices()) / numStates) + "\n";
		return s;
	}

	@Override
	public void exportToPrismExplicitTra(PrismLog out) throws PrismException
	{
		int i, j, numChoices;
		Object action;
		TreeMap<Integer, Double> sorted;
		// Output transitions to .tra file
		out.print(numStates + " " + getNumChoices() + " " + getNumTransitions() + "\n");
		sorted = new TreeMap<Integer, Double>();
		for (i = 0; i < numStates; i++) {
			numChoices = getNumChoices(i);
			for (j = 0; j < numChoices; j++) {
				// Extract transitions and sort by destination state index (to match PRISM-exported files)
				Iterator<Map.Entry<Integer, Double>> iter = getTransitionsIterator(i, j);
				while (iter.hasNext()) {
					Map.Entry<Integer, Double> e = iter.next();
					sorted.put(e.getKey(), e.getValue());
				}
				// Print out (sorted) transitions
				for (Map.Entry<Integer, Double> e : sorted.entrySet()) {
					// Note use of PrismUtils.formatDouble to match PRISM-exported files
					out.print(i + " " + j + " " + e.getKey() + " " + PrismUtils.formatDouble(e.getValue()));
					action = getAction(i, j);
					out.print(action == null ? "\n" : (" " + action + "\n"));
				}
				sorted.clear();
			}
		}
	}

	@Override
	public void exportToDotFile(String filename, BitSet mark) throws PrismException
	{
		int i, j, numChoices;
		String nij;
		Object action;
		try {
			FileWriter out = new FileWriter(filename);
			out.write("digraph " + getModelType() + " {\nsize=\"8,5\"\nnode [shape=box];\n");
			for (i = 0; i < numStates; i++) {
				if (mark != null && mark.get(i))
					out.write(i + " [style=filled  fillcolor=\"#cccccc\"]\n");
				numChoices = getNumChoices(i);
				for (j = 0; j < numChoices; j++) {
					action = getAction(i, j);
					nij = "n" + i + "_" + j;
					out.write(i + " -> " + nij + " [ arrowhead=none,label=\"" + j);
					if (action != null)
						out.write(":" + action);
					out.write("\" ];\n");
					out.write(nij + " [ shape=point,width=0.1,height=0.1,label=\"\" ];\n");
					Iterator<Map.Entry<Integer, Double>> iter = getTransitionsIterator(i, j);
					while (iter.hasNext()) {
						Map.Entry<Integer, Double> e = iter.next();
						out.write(nij + " -> " + e.getKey() + " [ label=\"" + e.getValue() + "\" ];\n");
					}
				}
			}
			out.write("}\n");
			out.close();
		} catch (IOException e) {
			throw new PrismException("Could not write " + getModelType() + " to file \"" + filename + "\"" + e);
		}
	}

	@Override
	public void exportToPrismLanguage(String filename) throws PrismException
	{
		int i, j, numChoices;
		boolean first;
		FileWriter out;
		TreeMap<Integer, Double> sorted;
		Object action;
		try {
			// Output transitions to PRISM language file
			out = new FileWriter(filename);
			out.write(getModelType().keyword() + "\n");
			out.write("module M\nx : [0.." + (numStates - 1) + "];\n");
			sorted = new TreeMap<Integer, Double>();
			for (i = 0; i < numStates; i++) {
				numChoices = getNumChoices(i);
				for (j = 0; j < numChoices; j++) {
					// Extract transitions and sort by destination state index (to match PRISM-exported files)
					Iterator<Map.Entry<Integer, Double>> iter = getTransitionsIterator(i, j);
					while (iter.hasNext()) {
						Map.Entry<Integer, Double> e = iter.next();
						sorted.put(e.getKey(), e.getValue());
					}
					// Print out (sorted) transitions
					action = getAction(i, j);
					out.write(action != null ? ("[" + action + "]") : "[]");
					out.write("x=" + i + "->");
					first = true;
					for (Map.Entry<Integer, Double> e : sorted.entrySet()) {
						if (first)
							first = false;
						else
							out.write("+");
						// Note use of PrismUtils.formatDouble to match PRISM-exported files
						out.write(PrismUtils.formatDouble(e.getValue()) + ":(x'=" + e.getKey() + ")");
					}
					out.write(";\n");
					sorted.clear();
				}
			}
			out.write("endmodule\n");
			out.close();
		} catch (IOException e) {
			throw new PrismException("Could not export " + getModelType() + " to file \"" + filename + "\"" + e);
		}
	}

	// Accessors (for MDP)

	@Override
	public void mvMultMinMax(double vect[], boolean min, double result[], BitSet subset, boolean complement, int adv[])
	{
		int s;
		// Loop depends on subset/complement arguments
		if (subset == null) {
			for (s = 0; s < numStates; s++)
				result[s] = mvMultMinMaxSingle(s, vect, min, adv);
		} else if (complement) {
			for (s = subset.nextClearBit(0); s < numStates; s = subset.nextClearBit(s + 1))
				result[s] = mvMultMinMaxSingle(s, vect, min, adv);
		} else {
			for (s = subset.nextSetBit(0); s >= 0; s = subset.nextSetBit(s + 1))
				result[s] = mvMultMinMaxSingle(s, vect, min, adv);
		}
	}

	@Override
	public double mvMultGSMinMax(double vect[], boolean min, BitSet subset, boolean complement, boolean absolute)
	{
		int s;
		double d, diff, maxDiff = 0.0;
		// Loop depends on subset/complement arguments
		if (subset == null) {
			for (s = 0; s < numStates; s++) {
				d = mvMultJacMinMaxSingle(s, vect, min);
				diff = absolute ? (Math.abs(d - vect[s])) : (Math.abs(d - vect[s]) / d);
				maxDiff = diff > maxDiff ? diff : maxDiff;
				vect[s] = d;
			}
		} else if (complement) {
			for (s = subset.nextClearBit(0); s < numStates; s = subset.nextClearBit(s + 1)) {
				d = mvMultJacMinMaxSingle(s, vect, min);
				diff = absolute ? (Math.abs(d - vect[s])) : (Math.abs(d - vect[s]) / d);
				maxDiff = diff > maxDiff ? diff : maxDiff;
				vect[s] = d;
			}
		} else {
			for (s = subset.nextSetBit(0); s >= 0; s = subset.nextSetBit(s + 1)) {
				d = mvMultJacMinMaxSingle(s, vect, min);
				diff = absolute ? (Math.abs(d - vect[s])) : (Math.abs(d - vect[s]) / d);
				maxDiff = diff > maxDiff ? diff : maxDiff;
				vect[s] = d;
			}
		}
		// Use this code instead for backwards Gauss-Seidel
		/*for (s = numStates - 1; s >= 0; s--) {
			if (subset.get(s)) {
				d = mvMultJacMinMaxSingle(s, vect, min);
				diff = absolute ? (Math.abs(d - vect[s])) : (Math.abs(d - vect[s]) / d);
				maxDiff = diff > maxDiff ? diff : maxDiff;
				vect[s] = d;
			}
		}*/
		return maxDiff;
	}

	@Override
	public void mvMultRewMinMax(double vect[], MDPRewards mdpRewards, boolean min, double result[], BitSet subset, boolean complement, int adv[])
	{
		int s;
		// Loop depends on subset/complement arguments
		if (subset == null) {
			for (s = 0; s < numStates; s++)
				result[s] = mvMultRewMinMaxSingle(s, vect, mdpRewards, min, adv);
		} else if (complement) {
			for (s = subset.nextClearBit(0); s < numStates; s = subset.nextClearBit(s + 1))
				result[s] = mvMultRewMinMaxSingle(s, vect, mdpRewards, min, adv);
		} else {
			for (s = subset.nextSetBit(0); s >= 0; s = subset.nextSetBit(s + 1))
				result[s] = mvMultRewMinMaxSingle(s, vect, mdpRewards, min, adv);
		}
	}
	
	@Override
	public double mvMultRewGSMinMax(double vect[], MDPRewards mdpRewards, boolean min, BitSet subset, boolean complement, boolean absolute)
	{
		int s;
		double d, diff, maxDiff = 0.0;
		// Loop depends on subset/complement arguments
		if (subset == null) {
			for (s = 0; s < numStates; s++) {
				d = mvMultRewJacMinMaxSingle(s, vect, mdpRewards, min);
				diff = absolute ? (Math.abs(d - vect[s])) : (Math.abs(d - vect[s]) / d);
				maxDiff = diff > maxDiff ? diff : maxDiff;
				vect[s] = d;
			}
		} else if (complement) {
			for (s = subset.nextClearBit(0); s < numStates; s = subset.nextClearBit(s + 1)) {
				d = mvMultRewJacMinMaxSingle(s, vect, mdpRewards, min);
				diff = absolute ? (Math.abs(d - vect[s])) : (Math.abs(d - vect[s]) / d);
				maxDiff = diff > maxDiff ? diff : maxDiff;
				vect[s] = d;
			}
		} else {
			for (s = subset.nextSetBit(0); s >= 0; s = subset.nextSetBit(s + 1)) {
				d = mvMultRewJacMinMaxSingle(s, vect, mdpRewards, min);
				diff = absolute ? (Math.abs(d - vect[s])) : (Math.abs(d - vect[s]) / d);
				maxDiff = diff > maxDiff ? diff : maxDiff;
				vect[s] = d;
			}
		}
		// Use this code instead for backwards Gauss-Seidel
		/*for (s = numStates - 1; s >= 0; s--) {
			if (subset.get(s)) {
				d = mvMultRewJacMinMaxSingle(s, vect, mdpRewards, min);
				diff = absolute ? (Math.abs(d - vect[s])) : (Math.abs(d - vect[s]) / d);
				maxDiff = diff > maxDiff ? diff : maxDiff;
				vect[s] = d;
			}
		}*/
		return maxDiff;
	}
}
