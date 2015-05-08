//==============================================================================
//	
//	Copyright (c) 2002-
//	Authors:
//	* Dave Parker <david.parker@comlab.ox.ac.uk> (University of Oxford)
//	* Vojtech Forejt <vojtech.forejt@cs.ox.ac.uk> (University of Oxford)
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

package explicit.rewards;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.List;

import parser.State;
import parser.Values;
import parser.ast.Expression;
import parser.ast.RewardStruct;
import prism.PrismException;
import prism.PrismFileLog;
import prism.PrismLog;
import explicit.*;

public class ConstructRewards
{
	protected PrismLog mainLog;

	public ConstructRewards()
	{
		this(new PrismFileLog("stdout"));
	}

	public ConstructRewards(PrismLog mainLog)
	{
		this.mainLog = mainLog;
	}

	/**
	 * Construct rewards from a model and reward structure. 
	 * @param model The model
	 * @param rewStr The reward structure
	 * @param constantValues Values for any undefined constants needed
	 */
	public Rewards buildRewardStructure(Model model, RewardStruct rewStr, Values constantValues) throws PrismException
	{
		switch (model.getModelType()) {
		case DTMC:
		case CTMC:
			return buildMCRewardStructure((DTMC) model, rewStr, constantValues);
		case MDP:
			return buildMDPRewardStructure((MDP) model, rewStr, constantValues);
		default:
			throw new PrismException("Cannot build rewards for " + model.getModelType() + "s");
		}
	}

	/**
	 * Construct the rewards for a Markov chain (DTMC or CTMC) from a model and reward structure. 
	 * @param mc The DTMC or CTMC
	 * @param rewStr The reward structure
	 * @param constantValues Values for any undefined constants needed
	 */
	public MCRewards buildMCRewardStructure(DTMC mc, RewardStruct rewStr, Values constantValues) throws PrismException
	{
		List<State> statesList;
		Expression guard;
		int i, j, n, numStates;

		if (rewStr.getNumTransItems() > 0) {
			// TODO
			throw new PrismException("Explicit engine does not yet handle transition rewards for D/CTMCs");
		}
		// Special case: constant rewards
		if (rewStr.getNumStateItems() == 1 && Expression.isTrue(rewStr.getStates(0)) && rewStr.getReward(0).isConstant()) {
			return new StateRewardsConstant(rewStr.getReward(0).evaluateDouble(constantValues));
		}
		// Normal: state rewards
		else {
			numStates = mc.getNumStates();
			statesList = mc.getStatesList();
			StateRewardsArray rewSA = new StateRewardsArray(numStates);
			n = rewStr.getNumItems();
			for (i = 0; i < n; i++) {
				guard = rewStr.getStates(i);
				for (j = 0; j < numStates; j++) {
					if (guard.evaluateBoolean(constantValues, statesList.get(j))) {
						rewSA.addToStateReward(j, rewStr.getReward(i).evaluateDouble(constantValues, statesList.get(j)));
					}
				}
			}
			return rewSA;
		}
	}

	/**
	 * Construct the rewards for an MDP from a model and reward structure. 
	 * @param model The MDP
	 * @param rewStr The reward structure
	 * @param constantValues Values for any undefined constants needed
	 */
	public MDPRewards buildMDPRewardStructure(MDP mdp, RewardStruct rewStr, Values constantValues) throws PrismException
	{
		List<State> statesList;
		Expression guard;
		String action;
		Object mdpAction;
		int i, j, k, n, numStates, numChoices;

		// Special case: constant state rewards
		if (rewStr.getNumStateItems() == 1 && Expression.isTrue(rewStr.getStates(0)) && rewStr.getReward(0).isConstant()) {
			return new StateRewardsConstant(rewStr.getReward(0).evaluateDouble(constantValues));
		}
		// Normal: state and transition rewards
		else {
			numStates = mdp.getNumStates();
			statesList = mdp.getStatesList();
			MDPRewardsSimple rewSimple = new MDPRewardsSimple(numStates);
			n = rewStr.getNumItems();
			for (i = 0; i < n; i++) {
				guard = rewStr.getStates(i);
				action = rewStr.getSynch(i);
				for (j = 0; j < numStates; j++) {
					// Is guard satisfied?
					if (guard.evaluateBoolean(constantValues, statesList.get(j))) {
						// Transition reward
						if (rewStr.getRewardStructItem(i).isTransitionReward()) {
							numChoices = mdp.getNumChoices(j);
							for (k = 0; k < numChoices; k++) {
								mdpAction = mdp.getAction(j, k);
								if (mdpAction == null ? (action.isEmpty()) : mdpAction.equals(action)) {
									rewSimple.addToTransitionReward(j, k, rewStr.getReward(i).evaluateDouble(constantValues, statesList.get(j)));
								}
							}
						}
						// State reward
						else {
							rewSimple.addToStateReward(j, rewStr.getReward(i).evaluateDouble(constantValues, statesList.get(j)));
						}
					}
				}
			}
			return rewSimple;
		}
	}

	/**
	 * Construct the rewards for an MDP from files exported explicitly by PRISM.
	 * @param model The MDP
	 * @param rews The file containing state rewards (ignored if null)
	 * @param rewt The file containing transition rewards (ignored if null)
	 */
	public MDPRewards buildMDPRewardsFromPrismExplicit(MDP mdp, File rews, File rewt) throws PrismException
	{
		BufferedReader in;
		String s, ss[];
		int i, j, lineNum = 0;
		double reward;
		MDPRewardsSimple rs = new MDPRewardsSimple(mdp.getNumStates());

		try {
			if (rews != null) {
				// Open rews file
				in = new BufferedReader(new FileReader(rews));
				// Ignore first line (num states)
				s = in.readLine();
				lineNum = 1;
				if (s == null)
					throw new PrismException("Missing first line of .rews file");
				// Go though list of transitions in file
				s = in.readLine();
				lineNum++;
				while (s != null) {
					s = s.trim();
					if (s.length() > 0) {
						ss = s.split(" ");
						i = Integer.parseInt(ss[0]);
						reward = Double.parseDouble(ss[1]);
						rs.setStateReward(i, reward);
					}
					s = in.readLine();
					lineNum++;
				}
				// Close file
				in.close();
			}
		} catch (IOException e) {
			throw new PrismException("Could not read rewards from file \"" + rewt + "\"" + e);
		} catch (NumberFormatException e) {
			throw new PrismException("Problem in .rewt file (line " + lineNum + ") for MDP");
		}

		try {
			if (rewt != null) {
				// Open rewt file
				in = new BufferedReader(new FileReader(rewt));
				// Ignore first line (num states)
				s = in.readLine();
				lineNum = 1;
				if (s == null)
					throw new PrismException("Missing first line of .rewt file");
				// Go though list of transitions in file
				s = in.readLine();
				lineNum++;
				while (s != null) {
					s = s.trim();
					if (s.length() > 0) {
						ss = s.split(" ");
						i = Integer.parseInt(ss[0]);
						j = Integer.parseInt(ss[1]);
						reward = Double.parseDouble(ss[2]);
						rs.setTransitionReward(i, j, reward);
					}
					s = in.readLine();
					lineNum++;
				}
				// Close file
				in.close();
			}
		} catch (IOException e) {
			throw new PrismException("Could not read transition rewards from file \"" + rewt + "\"" + e);
		} catch (NumberFormatException e) {
			throw new PrismException("Problem in .rewt file (line " + lineNum + ") for MDP");
		}

		return rs;
	}
}
