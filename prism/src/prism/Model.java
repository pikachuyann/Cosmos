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

import java.io.*;
import java.util.*;

import jdd.*;
import odd.*;
import parser.*;

public interface Model
{
	ModelType getModelType();

	int getNumModules();
	String[] getModuleNames();
	String getModuleName(int i);
	
	int getNumVars();
	VarList getVarList();
	String getVarName(int i);
	int getVarIndex(String n);
	int getVarModule(int i);
	int getVarLow(int i);
	int getVarHigh(int i);
	int getVarRange(int i);
	Values getConstantValues();
	List<String> getSynchs();
	String globalToLocal(long x);
	int globalToLocal(long x, int l);
	State convertBddToState(JDDNode dd);
	int convertBddToIndex(JDDNode dd);

	StateList getReachableStates();
	StateList getDeadlockStates();
	StateList getStartStates();
	int getNumRewardStructs();
	long getNumStates();
	long getNumTransitions();
	long getNumStartStates();
	String getNumStatesString();
	String getNumTransitionsString();
	String getNumStartStatesString();

	JDDNode getTrans();
	JDDNode getTrans01();
	JDDNode getStart();
	JDDNode getReach();
	JDDNode getDeadlocks();
	JDDNode getFixedDeadlocks();
	JDDNode getStateRewards();
	JDDNode getStateRewards(int i);
	JDDNode getStateRewards(String s);
	JDDNode getTransRewards();
	JDDNode getTransRewards(int i);
	JDDNode getTransRewards(String s);
	JDDNode getTransActions();
	JDDNode[] getTransPerAction();
	JDDVars[] getVarDDRowVars();
	JDDVars[] getVarDDColVars();
	JDDVars getVarDDRowVars(int i);
	JDDVars getVarDDColVars(int i);
	JDDVars[] getModuleDDRowVars();
	JDDVars[] getModuleDDColVars();
	JDDVars getModuleDDRowVars(int i);
	JDDVars getModuleDDColVars(int i);
	JDDVars getAllDDRowVars();
	JDDVars getAllDDColVars();
	int getNumDDRowVars();
	int getNumDDColVars();
	int getNumDDVarsInTrans();
	Vector<String> getDDVarNames();
	
	ODDNode getODD();

	void setSynchs(List<String> synchs);
	void resetTrans(JDDNode trans);
	void resetTransRewards(int i, JDDNode transRewards);
	void doReachability();
	void doReachability(boolean extraReachInfo);
	void skipReachability();
	void setReach(JDDNode reach);
	void setTransActions(JDDNode transActions); // MDPs only
	void setTransPerAction(JDDNode[] transPerAction); // D/CTMCs only
	void filterReachableStates();
	void findDeadlocks();
	void fixDeadlocks();
	void printTrans();
	void printTrans01();
	public void printTransInfo(PrismLog log);
	public void printTransInfo(PrismLog log, boolean extra);
	void exportToFile(int exportType, boolean explicit, File file) throws FileNotFoundException, PrismException;
	String exportStateRewardsToFile(int exportType, File file) throws FileNotFoundException, PrismException;
	String exportTransRewardsToFile(int exportType, boolean explicit, File file) throws FileNotFoundException, PrismException;

	void clear();
}

//------------------------------------------------------------------------------
