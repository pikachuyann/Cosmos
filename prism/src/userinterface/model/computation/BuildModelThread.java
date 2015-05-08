//==============================================================================
//	
//	Copyright (c) 2002-
//	Authors:
//	* Andrew Hinton <ug60axh@cs.bham.ac.uk> (University of Birmingham)
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

package userinterface.model.computation;

import javax.swing.*;

import userinterface.*;
import userinterface.model.*;
import parser.*;
import parser.ast.*;
import prism.*;
import userinterface.util.*;

public class BuildModelThread extends GUIComputationThread
{
	private GUIMultiModelHandler handler;
	private String buildThis;
	private boolean isPepa;
	private ModulesFile mod;
	private Model model;
	private Values buildValues;
	private boolean forceShow;
	private String errMsg;
	private PrismLangException parseError;
	private PrismException buildError;
	private StateList deadlocks;
    
	/** Creates a new instance of BuildModelThread */
// 	public BuildModelThread(GUIMultiModelHandler handler, String buildThis, boolean isPepa, Values buildValues, boolean forceShow)
// 	{
// 		this.handler = handler;
// 		this.buildThis = buildThis;
// 		this.isPepa = isPepa;
// 		this.buildValues = buildValues;
// 		plug = handler.getGUIPlugin();
// 		this.forceShow = forceShow;
// 	}
	
	public BuildModelThread(GUIMultiModelHandler handler, ModulesFile buildParse, Values buildValues, boolean forceShow)
	{
		super(handler.getGUIPlugin());
		this.handler = handler;
		this.buildThis = null;
		this.mod = buildParse;
		this.buildValues = buildValues;
		this.forceShow = forceShow;
		
	}

	public void run()
	{
		//Notify user interface of the start of computation
		SwingUtilities.invokeLater(new Runnable() { public void run() {
			plug.startProgress();
			plug.notifyEventListeners(new GUIComputationEvent(GUIComputationEvent.COMPUTATION_START, plug));
		}});
		
		//If need to do parse first...
		if(buildThis!=null)
		{
			SwingUtilities.invokeLater(new Runnable() { public void run() {
				plug.setTaskBarText("Parsing model...");
			}});
			
			// do parsing
			try {
				// normal prism mode
				if(!isPepa) {
					mod = prism.parseModelString(buildThis);
				}
				// pepa mode
				else {
					mod = prism.importPepaString(buildThis);
				}
			}
			catch (PrismLangException e) {
				parseError = e;
				SwingUtilities.invokeLater(new Runnable() { public void run() {
					plug.stopProgress(); 
					plug.notifyEventListeners(new GUIComputationEvent(GUIComputationEvent.COMPUTATION_ERROR, plug));
					plug.setTaskBarText("Parsing model... error.");
					error(parseError.getMessage());
					handler.modelParseFailed(parseError, false);
					handler.modelBuildFailed(null);
				}});
				return;
			}
			catch (PrismException e) {
				throw new RuntimeException("Unexpected PrismException: " + e.getMessage());			
			}
			
			//If we are here, the parse was successful, notify the interface
			SwingUtilities.invokeLater(new Runnable() { public void run() {
				plug.setTaskBarText("Parsing model... done.");
				handler.modelParsedSuccessful(mod);
			}});
			
			//give it a break so user can see the ...done before the building model...
			try { sleep(100); } catch(InterruptedException e) {}
		}
		
		// Check whether there are any undefined constants...
		// ...and if there are, get values for them
		UndefinedConstants unC = new UndefinedConstants(mod, null);
		if(unC.getMFNumUndefined() > 0)
		{
			if(forceShow || (buildValues == null))
			{
				// notify interface
				SwingUtilities.invokeLater(new Runnable() { public void run() {
					plug.setTaskBarText("Defining constants...");
				}});
				
				// show dialog
				int result = GUIConstantsPicker.defineConstantsWithDialog(handler.getGUIPlugin().getGUI(), unC, buildValues, null);
				
				// if build cancelled...
				if(result != GUIConstantsPicker.VALUES_DONE) {
					SwingUtilities.invokeLater(new Runnable() { public void run() {
						plug.stopProgress(); 
						plug.notifyEventListeners(new GUIComputationEvent(GUIComputationEvent.COMPUTATION_ERROR, plug));
						plug.setTaskBarText("Building model... cancelled.");
						handler.modelBuildFailed(new PrismException(""));
					}});
					return;
				}
				
				// get build values
				buildValues = unC.getMFConstantValues();
			}
			
			// notify interface
			SwingUtilities.invokeLater(new Runnable() { public void run() {
				plug.setTaskBarText("Defining constants... done.");
			}});
		}
		else {
			// create an empty values object
			buildValues = new Values();
		}
		
		if (buildValues != null) if (buildValues.getNumValues() > 0) logln("\nModel constants: " + buildValues);
		
		// set undefined constants
		try {
			mod.setUndefinedConstants(buildValues);
		}
		catch (PrismException e) {
			buildError = e;
			errMsg = e.getMessage();
			SwingUtilities.invokeLater(new Runnable() { public void run() {
				plug.stopProgress(); 
				plug.notifyEventListeners(new GUIComputationEvent(GUIComputationEvent.COMPUTATION_ERROR, plug));
				plug.setTaskBarText("Building model... error.");
				error(errMsg);
				handler.modelBuildFailed(buildError);
			}});
			return;
		}
		
		// notify interface
		SwingUtilities.invokeLater(new Runnable() { public void run() {
			plug.setTaskBarText("Building model...");
		}});
		
		// do build
		try {
			logSeparator();
			model = prism.buildModel(mod);
		}
		catch (PrismException e) {
			buildError = e;
			errMsg = e.getMessage();
			SwingUtilities.invokeLater(new Runnable() { public void run() {
				plug.stopProgress(); 
				plug.notifyEventListeners(new GUIComputationEvent(GUIComputationEvent.COMPUTATION_ERROR, plug));
				plug.setTaskBarText("Building model... error.");
				error(errMsg);
				handler.modelBuildFailed(buildError);
			}});
			return;
		}
		
		// Check for Deadlocks
		deadlocks = model.getDeadlockStates();
		if (deadlocks != null) if (deadlocks.size() > 0) {
			String[] options = {"Continue", "Display deadlocks"};
			int choice = plug.question("Error", "Error: Model contains deadlock states.\nAdd self-loops to these states and continue?\nOr stop and display deadlock states in log?", options);
			if (choice == 0) {
				logWarning(deadlocks.size() + " deadlock states detected; adding self-loops in these states...");
				model.fixDeadlocks();
			}
			else {
				model.printTransInfo(plug.getGUI().getLog());
				log("\nError: Model contains " + deadlocks.size() + " deadlock states");
				if (deadlocks.size() > 10) {
					log(".\nThe first 10 deadlock states are displayed below.\n");
					deadlocks.print(plug.getGUI().getLog(), 10);
				} else {
					log(":\n");
					deadlocks.print(plug.getGUI().getLog());
				}
				model.clear();
				
				SwingUtilities.invokeLater(new Runnable() { public void run() {
					plug.stopProgress(); 
					plug.notifyEventListeners(new GUIComputationEvent(GUIComputationEvent.COMPUTATION_ERROR, plug));
					plug.setTaskBarText("Building model... error.");
					handler.modelBuildFailed(new PrismException(""));
					plug.logToFront();
				}});
				return;
			}
		}

		logln();
		model.printTransInfo(plug.getGUI().getLog());

		//If we are here, the build was successful, notify the interface
		SwingUtilities.invokeLater(new Runnable() { public void run() {
			plug.stopProgress(); 
			plug.setTaskBarText("Building model... done.");
			plug.notifyEventListeners(new GUIComputationEvent(GUIComputationEvent.COMPUTATION_DONE, plug));
			handler.modelBuildSuccessful(model, buildValues);
		}});
	}
}
