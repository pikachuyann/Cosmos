//==============================================================================
//	
//	Copyright (c) 2002-
//	Authors:
//	* Dave Parker <david.parker@comlab.ox.ac.uk> (University of Oxford, formerly University of Birmingham)
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

package prism;

import java.io.File;

import jdd.JDDNode;
import jdd.JDDVars;

// Interface for classes for state-indexed vectors of (integer or double) values

public interface StateValues
{
	StateValuesDV convertToStateValuesDV();
	StateValuesMTBDD convertToStateValuesMTBDD();
	void readFromFile(File file) throws PrismException;
	void roundOff(int places);
	void subtractFromOne();
	void add(StateValues sp);
	void timesConstant(double d);
	void filter(JDDNode filter);
	public void maxMTBDD(JDDNode vec2);
	void clear();
	int getNNZ();
	String getNNZString();
	double firstFromBDD(JDDNode filter);
	double minOverBDD(JDDNode filter);
	double maxOverBDD(JDDNode filter);
	double sumOverBDD(JDDNode filter);
	double sumOverMTBDD(JDDNode mult);
	StateValues sumOverDDVars(JDDVars sumVars, Model newModel) throws PrismException;
	JDDNode getBDDFromInterval(String relOp, double bound);
	JDDNode getBDDFromInterval(double lo, double hi);
	JDDNode getBDDFromCloseValue(double val, double epsilon, boolean abs);
	JDDNode getBDDFromCloseValueAbs(double val, double epsilon);
	JDDNode getBDDFromCloseValueRel(double val, double epsilon);
	void print(PrismLog log) throws PrismException;
	void print(PrismLog log, boolean printSparse, boolean printMatlab, boolean printStates) throws PrismException;
	void printFiltered(PrismLog log, JDDNode filter) throws PrismException;
	void printFiltered(PrismLog log, JDDNode filter, boolean printSparse, boolean printMatlab, boolean printStates) throws PrismException;
	StateValues deepCopy() throws PrismException; 
}
