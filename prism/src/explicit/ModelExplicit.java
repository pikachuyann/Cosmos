//==============================================================================
//	
//	Copyright (c) 2002-
//	Authors:
//	* Dave Parker <david.parker@comlab.ox.ac.uk> (University of Oxford)
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

import java.io.File;
import java.util.*;

import parser.State;
import parser.Values;
import prism.ModelType;
import prism.PrismException;
import prism.PrismLog;
import prism.PrismFileLog;

/**
 * Base class for explicit-state model representations.
 */
public abstract class ModelExplicit implements Model
{
	// Number of states
	protected int numStates;
	// Initial states
	protected List<Integer> initialStates; // TODO: should be a (linkedhash?) set really
	/**
	 * States with deadlocks that have been "fixed", i.e. a state that was
	 * originally a deadlock but has been fixed through the addition of a self-loop,
	 * or a state that is still a deadlock but in a model where this acceptable, e.g. a CTMC.
	 */
	protected TreeSet<Integer> deadlocksFixed;
	// State info (read only, just a pointer)
	protected List<State> statesList;
	// Constant info (read only, just a pointer)
	protected Values constantValues;

	// Mutators

	/**
	 * Copy data from another ModelExplicit (used by superclass copy constructors).
	 * Assumes that this has already been initialise()ed.
	 */
	public void copyFrom(ModelExplicit model)
	{
		numStates = model.numStates;
		for (int in : model.initialStates) {
			addInitialState(in);
		}
		// Shallow copy of read-only stuff
		statesList = model.statesList;
		constantValues = model.constantValues;
	}

	/**
	 * Copy data from another ModelExplicit and a state index permutation,
	 * i.e. state index i becomes index permut[i]
	 * (used by superclass copy constructors).
	 * Assumes that this has already been initialise()ed.
	 * Pointer to states list is NOT copied (since now wrong).
	 */
	public void copyFrom(ModelExplicit model, int permut[])
	{
		numStates = model.numStates;
		for (int in : model.initialStates) {
			addInitialState(permut[in]);
		}
		// Shallow copy of (some) read-only stuff
		// (i.e. info that is not broken by permute)
		statesList = null;
		constantValues = model.constantValues;
	}

	/**
	 * Initialise: create new model with fixed number of states.
	 */
	public void initialise(int numStates)
	{
		this.numStates = numStates;
		initialStates = new ArrayList<Integer>();
		deadlocksFixed = new TreeSet<Integer>();
		statesList = null;
	}

	/**
	 * Add a state to the list of initial states.
	 */
	public void addInitialState(int i)
	{
		initialStates.add(i);
	}

	/**
	 * Add a state to the list of "fixed" deadlock states.
	 */
	public void addFixedDeadlockState(int i)
	{
		deadlocksFixed.add(i);
	}

	/**
	 * Build (anew) from a list of transitions exported explicitly by PRISM (i.e. a .tra file).
	 */
	public abstract void buildFromPrismExplicit(String filename) throws PrismException;

	/**
	 * Set the associated (read-only) state list.
	 */
	public void setStatesList(List<State> statesList)
	{
		this.statesList = statesList;
	}
	
	/**
	 * Set the associated (read-only) constant values.
	 */
	public void setConstantValues(Values constantValues)
	{
		this.constantValues = constantValues;
	}

	// Accessors (for Model interface)

	@Override
	public abstract ModelType getModelType();

	@Override
	public int getNumStates()
	{
		return numStates;
	}

	@Override
	public int getNumInitialStates()
	{
		return initialStates.size();
	}

	@Override
	public Iterable<Integer> getInitialStates()
	{
		return initialStates;
	}

	@Override
	public int getFirstInitialState()
	{
		return initialStates.isEmpty() ? -1 : initialStates.get(0);
	}

	@Override
	public boolean isInitialState(int i)
	{
		return initialStates.contains(i);
	}

	@Override
	public boolean isFixedDeadlockState(int i)
	{
		return deadlocksFixed.contains(i);
	}
	
	@Override
	public List<State> getStatesList()
	{
		return statesList;
	}

	@Override
	public Values getConstantValues()
	{
		return constantValues;
	}

	@Override
	public abstract int getNumTransitions();

	@Override
	public abstract boolean isSuccessor(int s1, int s2);

	@Override
	public abstract int getNumChoices(int s);

	@Override
	public void checkForDeadlocks() throws PrismException
	{
		checkForDeadlocks(null);
	}

	@Override
	public abstract void checkForDeadlocks(BitSet except) throws PrismException;

	@Override
	public void exportToPrismExplicit(String baseFilename) throws PrismException
	{
		// Default implementation - just output .tra file
		// (some models might override this)
		exportToPrismExplicitTra(baseFilename + ".tra");
	}

	@Override
	public void exportToPrismExplicitTra(String filename) throws PrismException
	{
		exportToPrismExplicitTra(new PrismFileLog(filename));
	}

	@Override
	public void exportToPrismExplicitTra(File file) throws PrismException
	{
		exportToPrismExplicitTra(new PrismFileLog(file.getPath()));
	}

	@Override
	public abstract void exportToPrismExplicitTra(PrismLog out) throws PrismException;

	@Override
	public void exportToDotFile(String filename) throws PrismException
	{
		exportToDotFile(filename, null);
	}

	@Override
	public abstract void exportToDotFile(String filename, BitSet mark) throws PrismException;

	@Override
	public abstract void exportToPrismLanguage(String filename) throws PrismException;

	@Override
	public abstract String infoString();

	@Override
	public abstract String infoStringTable();

	@Override
	public boolean equals(Object o)
	{
		if (o == null || !(o instanceof ModelExplicit))
			return false;
		ModelExplicit model = (ModelExplicit) o;
		if (numStates != model.numStates)
			return false;
		if (!initialStates.equals(model.initialStates))
			return false;
		return true;
	}
}