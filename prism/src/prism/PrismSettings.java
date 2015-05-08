//==============================================================================
//	
//	Copyright (c) 2002-
//	Authors:
//	* Dave Parker <david.parker@comlab.ox.ac.uk> (University of Oxford, formerly University of Birmingham)
//	* Andrew Hinton <ug60axh@cs.bham.ac.uk> (University of Birmingham)
//	* Vincent Nimal <vincent.nimal@comlab.ox.ac.uk> (University of Oxford)
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

import java.util.*;
import java.io.*;
import java.awt.*;
import javax.swing.*;
import java.util.regex.*;

import parser.ast.*;
import settings.*;

public class PrismSettings implements Observer
{
	//Default Constants
	public static final String DEFAULT_STRING = "";
	public static final int DEFAULT_INT = 0;
	public static final double DEFAULT_DOUBLE = 0.0;
	public static final float DEFAULT_FLOAT = 0.0f;
	public static final long DEFAULT_LONG = 0l;
	public static final boolean DEFAULT_BOOLEAN = false;
	public static final Color DEFAULT_COLOUR = Color.white;
	public static final Font DEFAULT_FONT = new Font("monospaced", Font.PLAIN, 12);
	public static final FontColorPair DEFAULT_FONT_COLOUR = new FontColorPair(new Font("monospaced", Font.PLAIN, 12), Color.black);
	public static final File DEFAULT_FILE = null;
	
	//Type Constants
	public static final String STRING_TYPE = "s";
	public static final String INTEGER_TYPE = "i";
	public static final String FLOAT_TYPE = "f";
	public static final String DOUBLE_TYPE = "d";
	public static final String LONG_TYPE = "l";
	public static final String BOOLEAN_TYPE = "b";
	public static final String COLOUR_TYPE = "c";
	//public static final String FONT_TYPE = "fo";	  //remove for now cos we don't have a setting for this yet
	public static final String CHOICE_TYPE = "ch";
	public static final String FONT_COLOUR_TYPE = "fct";
	public static final String FILE_TYPE = "fi";
	
	//Property Constant Keys
	//======================
	
	//PRISM
	public static final	String PRISM_ENGINE							= "prism.engine";
	public static final	String PRISM_VERBOSE						= "prism.verbose";
	public static final	String PRISM_FAIRNESS						= "prism.fairness";
	public static final	String PRISM_PRECOMPUTATION					= "prism.precomputation";
	public static final	String PRISM_PROB0							= "prism.prob0";
	public static final	String PRISM_PROB1							= "prism.prob1";
	public static final	String PRISM_DO_PROB_CHECKS					= "prism.doProbChecks";
	public static final	String PRISM_COMPACT						= "prism.compact";
	public static final	String PRISM_LIN_EQ_METHOD					= "prism.linEqMethod";//"prism.iterativeMethod";
	public static final	String PRISM_LIN_EQ_METHOD_PARAM			= "prism.linEqMethodParam";//"prism.overRelaxation";
	public static final	String PRISM_MDP_SOLN_METHOD				= "prism.mdpSolnMethod";
	public static final	String PRISM_TERM_CRIT						= "prism.termCrit";//"prism.termination";
	public static final	String PRISM_TERM_CRIT_PARAM				= "prism.termCritParam";//"prism.terminationEpsilon";
	public static final	String PRISM_MAX_ITERS						= "prism.maxIters";//"prism.maxIterations";
	public static final	String PRISM_CUDD_MAX_MEM					= "prism.cuddMaxMem";
	public static final	String PRISM_CUDD_EPSILON					= "prism.cuddEpsilon";
	public static final	String PRISM_NUM_SB_LEVELS					= "prism.numSBLevels";//"prism.hybridNumLevels";
	public static final	String PRISM_SB_MAX_MEM						= "prism.SBMaxMem";//"prism.hybridMaxMemory";
	public static final	String PRISM_NUM_SOR_LEVELS					= "prism.numSORLevels";//"prism.hybridSORLevels";
	public static final	String PRISM_SOR_MAX_MEM					= "prism.SORMaxMem";//"prism.hybridSORMaxMemory";
	public static final	String PRISM_DO_SS_DETECTION				= "prism.doSSDetect";
	public static final	String PRISM_EXTRA_DD_INFO					= "prism.extraDDInfo";
	public static final	String PRISM_EXTRA_REACH_INFO				= "prism.extraReachInfo";
	public static final String PRISM_SCC_METHOD						= "prism.sccMethod";
	public static final String PRISM_SYMM_RED_PARAMS					= "prism.symmRedParams";
	public static final String PRISM_PTA_METHOD					= "prism.ptaMethod";
	public static final String PRISM_AR_OPTIONS					= "prism.arOptions";
	public static final String PRISM_EXPORT_ADV					= "prism.exportAdv";
	public static final String PRISM_EXPORT_ADV_FILENAME			= "prism.exportAdvFilename";
	
	//Simulator
	public static final String SIMULATOR_DEFAULT_NUM_SAMPLES		= "simulator.defaultNumSamples";
	public static final String SIMULATOR_DEFAULT_CONFIDENCE			= "simulator.defaultConfidence";
	public static final String SIMULATOR_DEFAULT_WIDTH				= "simulator.defaultWidth";
	public static final String SIMULATOR_DEFAULT_APPROX				= "simulator.defaultApprox";
	public static final String SIMULATOR_DEFAULT_MAX_PATH			= "simulator.defaultMaxPath";
	public static final String SIMULATOR_DECIDE 					= "simulator.decide";
	public static final String SIMULATOR_ITERATIONS_TO_DECIDE		= "simulator.iterationsToDecide";
	public static final String SIMULATOR_MAX_REWARD					= "simulator.maxReward";
	public static final	String SIMULATOR_SIMULTANEOUS				= "simulator.simultaneous";
	public static final String SIMULATOR_FIELD_CHOICE				= "simulator.fieldChoice";
	public static final	String SIMULATOR_NEW_PATH_ASK_VIEW			= "simulator.newPathAskView";
	public static final	String SIMULATOR_RENDER_ALL_VALUES			= "simulator.renderAllValues";
	public static final String SIMULATOR_NETWORK_FILE				= "simulator.networkFile";
	
	//GUI Model
	public static final	String MODEL_AUTO_PARSE						= "model.autoParse";
	public static final	String MODEL_AUTO_MANUAL					= "model.autoManual";
	public static final	String MODEL_PARSE_DELAY					= "model.parseDelay";
	public static final	String MODEL_PRISM_EDITOR_FONT				= "model.prismEditor.font";
	public static final	String MODEL_SHOW_LINE_NUMBERS				= "model.prismEditor.lineNumbers";
	
	//public static final	String MODEL_PRISM_EDITOR_FONT_COLOUR		= "model.prismEditor.fontColour";
	public static final	String MODEL_PRISM_EDITOR_BG_COLOUR			= "model.prismEditor.bgColour";
	public static final	String MODEL_PRISM_EDITOR_NUMERIC_COLOUR	= "model.prismEditor.numericColour";
	public static final	String MODEL_PRISM_EDITOR_NUMERIC_STYLE		= "model.prismEditor.numericStyle";
	public static final	String MODEL_PRISM_EDITOR_IDENTIFIER_COLOUR	  =	"model.prismEditor.identifierColour";
	public static final	String MODEL_PRISM_EDITOR_IDENTIFIER_STYLE	  =	"model.prismEditor.identifierStyle";
	public static final	String MODEL_PRISM_EDITOR_KEYWORD_COLOUR	= "model.prismEditor.keywordColour";
	public static final	String MODEL_PRISM_EDITOR_KEYWORD_STYLE		= "model.prismEditor.keywordStyle";
	public static final	String MODEL_PRISM_EDITOR_COMMENT_COLOUR	= "model.prismEditor.commentColour";
	public static final	String MODEL_PRISM_EDITOR_COMMENT_STYLE		= "model.prismEditor.commentStyle";
	public static final	String MODEL_PEPA_EDITOR_FONT				= "model.pepaEditor.font";
	//public static final	String MODEL_PEPA_EDITOR_FONT_COLOUR		= "model.pepaEditor.fontColour";
	public static final	String MODEL_PEPA_EDITOR_BG_COLOUR			= "model.pepaEditor.bgColour";
	public static final	String MODEL_PEPA_EDITOR_COMMENT_COLOUR		= "model.pepaEditor.commentColour";
	public static final	String MODEL_PEPA_EDITOR_COMMENT_STYLE		= "model.pepaEditor.commentStyle";
	
	//GUI Properties
	public static final	String PROPERTIES_FONT						= "properties.font";
	public static final	String PROPERTIES_SELECTION_COLOUR			= "properties.selectionColour";
	public static final	String PROPERTIES_WARNING_COLOUR			= "properties.warningColour";
	public static final	String PROPERTIES_ADDITION_STRATEGY			= "properties.additionStategy";
	public static final	String PROPERTIES_CLEAR_LIST_ON_LOAD		= "properties.clearListOnLoad";
	
	//GUI Log
	public static final	String LOG_FONT								= "log.font";
	public static final	String LOG_SELECTION_COLOUR					= "log.selectionColour";
	public static final	String LOG_BG_COLOUR						= "log.bgColour";
	public static final	String LOG_BUFFER_LENGTH					= "log.bufferLength";
	
	
	//Defaults, types and constaints
	
	public static final String[] propertyOwnerNames =
	{
		"PRISM",
		"Simulator",
		"Model",
		"Properties",
		"Log"
	};
	public static final int[] propertyOwnerIDs =
	{
		PropertyConstants.PRISM,
		PropertyConstants.SIMULATOR,
		PropertyConstants.MODEL,
		PropertyConstants.PROPERTIES,
		PropertyConstants.LOG
	};
	
	
	// Property table:
	// * Datatype = type of choice (see type constants at top of this file)
	// * Key = internal key, used programmatically; need to add this to key list above
	// * Display name = display name; used e.g. in GUI options dialog
	// * Version = last public version of PRISM in which this setting did *not* appear
	//   (the main use for this is to allow a new default setting to be provided in a new version of PRISM)
	//   (if the version of the user settings file is older, a new default value will be set in the file)
	// * Default = default value 
	// * Constraints = limitations on possible values 
	// * Comments = explanatory comments; used e.g. in GUI options dialog 
	
	public static final Object[][][] propertyData =
	{
		{	//Datatype:			Key:									Display name:							Version:		Default:																	Constraints:																				Comment:
			//====================================================================================================================================================================================================================================================================================================================================
			
			// ENGINES/METHODS:
			{ CHOICE_TYPE,		PRISM_ENGINE,							"Engine",								"2.1",			"Hybrid",																	"MTBDD,Sparse,Hybrid",																		
																			"Which engine (hybrid, sparse or MTBDD) should be used for model checking." },
			{ CHOICE_TYPE,		PRISM_PTA_METHOD,						"PTA model checking method",			"3.3",			"Stochastic games",																	"Digital clocks,Stochastic games",																
																			"Which method to use for model checking of PTAs." },
			// NUMERICAL SOLUTION OPTIONS:
			{ CHOICE_TYPE,		PRISM_LIN_EQ_METHOD,					"Linear equations method",				"2.1",			"Jacobi",																	"Power,Jacobi,Gauss-Seidel,Backwards Gauss-Seidel,Pseudo-Gauss-Seidel,Backwards Pseudo-Gauss-Seidel,JOR,SOR,Backwards SOR,Pseudo-SOR,Backwards Pseudo-SOR",
																			"Which iterative method to use when solving linear equation systems." },
			{ DOUBLE_TYPE,		PRISM_LIN_EQ_METHOD_PARAM,				"Over-relaxation parameter",			"2.1",			new Double(0.9),															"",																							
																			"Over-relaxation parameter for iterative numerical methods such as JOR/SOR." },
			{ CHOICE_TYPE,		PRISM_MDP_SOLN_METHOD,					"MDP solution method",				"4.0",			"Value iteration",																"Value iteration,Gauss-Seidel,Policy iteration,Modified policy iteration,Linear programming",
																			"Which method to use when solving Markov decision processes." },
			{ CHOICE_TYPE,		PRISM_TERM_CRIT,						"Termination criteria",					"2.1",			"Relative",																	"Absolute,Relative",																		
																			"Criteria to use for checking termination of iterative numerical methods." },
			{ DOUBLE_TYPE,		PRISM_TERM_CRIT_PARAM,					"Termination epsilon",					"2.1",			new Double(1.0E-6),															"0.0,",																						
																			"Epsilon value to use for checking termination of iterative numerical methods." },
			{ INTEGER_TYPE,		PRISM_MAX_ITERS,						"Termination max. iterations",			"2.1",			new Integer(10000),															"0,",																						
																			"Maximum number of iterations to perform if iterative methods do not converge." },
			// MODEL CHECKING OPTIONS:
			{ BOOLEAN_TYPE,		PRISM_PRECOMPUTATION,					"Use precomputation",					"2.1",			new Boolean(true),															"",																							
																			"Whether to use model checking precomputation algorithms (Prob0, Prob1, etc.), where optional." },
			{ BOOLEAN_TYPE,		PRISM_PROB0,							"Use Prob0 precomputation",				"4.0.2",		new Boolean(true),															"",																							
																			"Whether to use model checking precomputation algorithm Prob0 (if precomputation enabled)." },
			{ BOOLEAN_TYPE,		PRISM_PROB1,							"Use Prob1 precomputation",				"4.0.2",		new Boolean(true),															"",																							
																			"Whether to use model checking precomputation algorithm Prob1 (if precomputation enabled)." },
			{ BOOLEAN_TYPE,		PRISM_FAIRNESS,							"Use fairness",							"2.1",			new Boolean(false),															"",																							
																			"Constrain to fair adversaries when model checking MDPs." },
			{ BOOLEAN_TYPE,		PRISM_DO_PROB_CHECKS,					"Do probability/rate checks",			"2.1",			new Boolean(true),															"",																							
																			"Perform sanity checks on model probabilities/rates when constructing probabilistic models." },
			{ BOOLEAN_TYPE,		PRISM_DO_SS_DETECTION,					"Use steady-state detection",			"2.1",			new Boolean(true),															"0,",																						
																			"Use steady-state detection during CTMC transient probability computation." },
			{ CHOICE_TYPE,		PRISM_SCC_METHOD,						"SCC decomposition method",				"3.2",			"Lockstep",																	"Xie-Beerel,Lockstep,SCC-Find",																
																			"Which algorithm to use for decomposing a graph into strongly connected components (SCCs)." },
			{ STRING_TYPE,		PRISM_SYMM_RED_PARAMS,					"Symmetry reduction parameters",		"3.2",			"",																	"",																
																			"Parameters for symmetry reduction (format: \"i j\" where i and j are the number of modules before and after the symmetric ones; empty string means symmetry reduction disabled)." },
			{ STRING_TYPE,		PRISM_AR_OPTIONS,						"Abstraction refinement options",		"3.3",			"",																	"",																
																			"Various options passed to the asbtraction-refinement engine (e.g. for PTA model checking)." },
			// OUTPUT OPTIONS:
			{ BOOLEAN_TYPE,		PRISM_VERBOSE,							"Verbose output",						"2.1",			new Boolean(false),															"",																							
																			"Display verbose output to log." },
			{ BOOLEAN_TYPE,		PRISM_EXTRA_DD_INFO,					"Extra MTBDD information",				"3.1.1",		new Boolean(false),															"0,",																						
																			"Display extra information about (MT)BDDs used during and after model construction." },
			{ BOOLEAN_TYPE,		PRISM_EXTRA_REACH_INFO,					"Extra reachability information",		"3.1.1",		new Boolean(false),															"0,",																						
																			"Display extra information about progress of reachability during model construction." },
			// SPARSE/HYBRID/MTBDD OPTIONS:
			{ BOOLEAN_TYPE,		PRISM_COMPACT,							"Use compact schemes",					"2.1",			new Boolean(true),															"",																							
																			"Use additional optimisations for compressing sparse matrices and vectors with repeated values." },
			{ INTEGER_TYPE,		PRISM_NUM_SB_LEVELS,					"Hybrid sparse levels",					"2.1",			new Integer(-1),															"-1,",																						
																			"Number of MTBDD levels ascended when adding sparse matrices to hybrid engine data structures (-1 means use default)." },
			{ INTEGER_TYPE,		PRISM_SB_MAX_MEM,						"Hybrid sparse memory (KB)",			"2.1",			new Integer(1024),															"0,",																						
																			"Maximum memory usage when adding sparse matrices to hybrid engine data structures (KB)." },
			{ INTEGER_TYPE,		PRISM_NUM_SOR_LEVELS,					"Hybrid GS levels",						"2.1",			new Integer(-1),															"-1,",																						
																			"Number of MTBDD levels descended for hybrid engine data structures block division with GS/SOR." },
			{ INTEGER_TYPE,		PRISM_SOR_MAX_MEM,						"Hybrid GS memory (KB)",				"2.1",			new Integer(1024),															"0,",																						
																			"Maximum memory usage for hybrid engine data structures block division with GS/SOR (KB)." },
			{ INTEGER_TYPE,		PRISM_CUDD_MAX_MEM,						"CUDD max. memory (KB)",				"2.1",			new Integer(409600),														"0,",																						
																			"Maximum memory available to CUDD (underlying BDD/MTBDD library) in KB (Note: Restart PRISM after changing this.)" },
			{ DOUBLE_TYPE,		PRISM_CUDD_EPSILON,						"CUDD epsilon",							"2.1",			new Double(1.0E-15),														"0.0,",																						
																			"Epsilon value used by CUDD (underlying BDD/MTBDD library) for terminal cache comparisons." },
			// ADVERSARIES/COUNTEREXAMPLES:
			{ CHOICE_TYPE,		PRISM_EXPORT_ADV,						"Adversary export",						"3.3",			"None",																	"None,DTMC,MDP",																
																			"Type of adversary to generate and export during MDP model checking" },
			{ STRING_TYPE,		PRISM_EXPORT_ADV_FILENAME,				"Adversary export filename",			"3.3",			"adv.tra",																	"",															
																			"Name of file for MDP adversary export (if enabled)" },
		},
		{
			{ INTEGER_TYPE,		SIMULATOR_DEFAULT_NUM_SAMPLES,			"Default number of samples",			"4.0",		new Integer(1000),			"1,",
																			"Default number of samples when using approximate (simulation-based) model checking (CI/ACI/APMC methods)." },
			{ DOUBLE_TYPE,		SIMULATOR_DEFAULT_CONFIDENCE,			"Default confidence parameter",			"4.0",		new Double(0.01),			"0,1",
																			"Default value for the 'confidence' parameter when using approximate (simulation-based) model checking (CI/ACI/APMC/SPRT methods). For CI/ACI, this means that the corresponding 'confidence level' is 100 x (1 - confidence)%; for APMC, this is the probability of the 'approximation' being exceeded; for SPRT, this is the acceptable probability for type I/II errors." },
			{ DOUBLE_TYPE,		SIMULATOR_DEFAULT_WIDTH,				"Default width of confidence interval",	"4.0",		new Double(0.05),			"0,",
																			"Default (half-)width of the confidence interval when using approximate (simulation-based) model checking (CI/ACI/SPRT methods). For SPRT, this refers to the 'indifference' parameter." },
			{ DOUBLE_TYPE,		SIMULATOR_DEFAULT_APPROX,				"Default approximation parameter",		"4.0",		new Double(0.05),			"0,",
																			"Default value for the 'approximation' parameter when using approximate (simulation-based) model checking (APMC method)." },
			{ INTEGER_TYPE,		SIMULATOR_DEFAULT_MAX_PATH,				"Default maximum path length",			"2.1",		new Integer(10000),			"1,",
																			"Default maximum path length when using approximate (simulation-based) model checking." },
			{ BOOLEAN_TYPE,		SIMULATOR_DECIDE,						"Decide S^2=0 or not automatically",	"4.0",		new	Boolean(true),			"",
																			"Let PRISM choose whether, after a certain number of iterations, the standard error is null or not." },
			{ INTEGER_TYPE,		SIMULATOR_ITERATIONS_TO_DECIDE,			"Number of iterations to decide",		"4.0",		new	Integer(10000),			"1,",
																			"Number of iterations to decide whether the standard error is null or not." },
			{ DOUBLE_TYPE,		SIMULATOR_MAX_REWARD,					"Maximum reward",						"4.0",		new	Double(1000.0),			"1,",
																			"Maximum reward for CI/ACI methods. It helps these methods in displaying the progress in case of rewards computation." },
			{ BOOLEAN_TYPE,		SIMULATOR_SIMULTANEOUS,					"Check properties simultaneously",		"2.1",		new Boolean(true),			"",
																			"Check multiple properties simultaneously over the same set of execution paths (simulator only)." },
			{ CHOICE_TYPE,		SIMULATOR_FIELD_CHOICE,					"Values used in dialog",				"2.1",		"Last used values",			"Last used values,Always use defaults",
																			"How to choose values for the simulation dialog: remember previously used values or revert to the defaults each time." },
			{ BOOLEAN_TYPE,		SIMULATOR_NEW_PATH_ASK_VIEW,			"Ask for view configuration",			"2.1",		new Boolean(false),			"",
																			"Display dialog with display options when creating a new simulation path." },
			{ CHOICE_TYPE,		SIMULATOR_RENDER_ALL_VALUES,			"Path render style",					"3.2",		"Render all values",		"Render changes,Render all values",
																			"Display style for paths in the simulator user interface: only show variable values when they change, or show all values regardless." },
			{ FILE_TYPE,		SIMULATOR_NETWORK_FILE,					"Network profile",						"2.1",		new File(""),				"",
																			"File specifying the network profile used by the distributed PRISM simulator." }
		},
		{
			{ BOOLEAN_TYPE,		MODEL_AUTO_PARSE,						"Auto parse",							"2.1",			new Boolean(true),															"",																							"Parse PRISM models automatically as they are loaded/edited in the text editor." },
			{ BOOLEAN_TYPE,		MODEL_AUTO_MANUAL,						"Manual parse for large models",		"2.1",			new Boolean(true),															"",																							"Disable automatic model parsing when loading large PRISM models." },
			{ INTEGER_TYPE,		MODEL_PARSE_DELAY,						"Parse delay (ms)",						"2.1",			new Integer(1000),															"0,",																						"Time delay (after typing has finished) before an automatic re-parse of the model is performed." },
			{ FONT_COLOUR_TYPE,	MODEL_PRISM_EDITOR_FONT,				"PRISM editor font",					"2.1",			new FontColorPair(new Font("monospaced", Font.PLAIN, 12), Color.black),		"",																							"Font used in the PRISM model text editor." },
			{ BOOLEAN_TYPE,		MODEL_SHOW_LINE_NUMBERS,				"PRISM editor line numbers",            "3.2",    new Boolean(true),															"",																							"Enable or disable line numbers in the PRISM model text editor" },
			{ COLOUR_TYPE,		MODEL_PRISM_EDITOR_BG_COLOUR,			"PRISM editor background",				"2.1",			new Color(255,255,255),														"",																							"Background colour for the PRISM model text editor." },
			{ COLOUR_TYPE,		MODEL_PRISM_EDITOR_NUMERIC_COLOUR,		"PRISM editor numeric colour",			"2.1",			new Color(0,0,255),															"",																							"Syntax highlighting colour for numerical values in the PRISM model text editor." },
			{ CHOICE_TYPE,		MODEL_PRISM_EDITOR_NUMERIC_STYLE,		"PRISM editor numeric style",			"2.1",			"Plain",																	"Plain,Italic,Bold,Bold Italic",															"Syntax highlighting style for numerical values in the PRISM model text editor." },
			{ COLOUR_TYPE,		MODEL_PRISM_EDITOR_IDENTIFIER_COLOUR,	"PRISM editor identifier colour",		"2.1",			new Color(255,0,0),															"",																							"Syntax highlighting colour for identifiers values in the PRISM model text editor" },
			{ CHOICE_TYPE,		MODEL_PRISM_EDITOR_IDENTIFIER_STYLE,	"PRISM editor identifier style",		"2.1",			"Plain",																	"Plain,Italic,Bold,Bold Italic",															"Syntax highlighting style for identifiers in the PRISM model text editor." },
			{ COLOUR_TYPE,		MODEL_PRISM_EDITOR_KEYWORD_COLOUR,		"PRISM editor keyword colour",			"2.1",			new Color(0,0,0),															"",																							"Syntax highlighting colour for keywords in the PRISM model text editor" },
			{ CHOICE_TYPE,		MODEL_PRISM_EDITOR_KEYWORD_STYLE,		"PRISM editor keyword style",			"2.1",			"Bold",																		"Plain,Italic,Bold,Bold Italic",															"Syntax highlighting style for keywords in the PRISM model text editor." },
			{ COLOUR_TYPE,		MODEL_PRISM_EDITOR_COMMENT_COLOUR,		"PRISM editor comment colour",			"2.1",			new Color(0,99,0),															"",																							"Syntax highlighting colour for comments in the PRISM model text editor." },
			{ CHOICE_TYPE,		MODEL_PRISM_EDITOR_COMMENT_STYLE,		"PRISM editor comment style",			"2.1",			"Italic",																	"Plain,Italic,Bold,Bold Italic",															"Syntax highlighting style for comments in the PRISM model text editor." },
			{ FONT_COLOUR_TYPE,	MODEL_PEPA_EDITOR_FONT,					"PEPA editor font",						"2.1",			new FontColorPair(new Font("monospaced", Font.PLAIN, 12), Color.black),		"",																							"Font used in the PEPA model text editor." },
			{ COLOUR_TYPE,		MODEL_PEPA_EDITOR_BG_COLOUR,			"PEPA editor background",				"2.1",			new Color(255,250,240),														"",																							"Background colour for the PEPA model text editor." },
			{ COLOUR_TYPE,		MODEL_PEPA_EDITOR_COMMENT_COLOUR,		"PEPA editor comment colour",			"2.1",			new Color(0,99,0),															"",																							"Syntax highlighting colour for comments in the PEPA model text editor." },
			{ CHOICE_TYPE,		MODEL_PEPA_EDITOR_COMMENT_STYLE,		"PEPA editor comment style",			"2.1",			"Italic",																	"Plain,Italic,Bold,Bold Italic",															"Syntax highlighting style for comments in the PEPA model text editor." }
		},
		{
			{ FONT_COLOUR_TYPE,	PROPERTIES_FONT,						"Display font",							"2.1",			new FontColorPair(new Font("monospaced", Font.PLAIN, 12), Color.black),		"",																							"Font used for the properties list." },
			{ COLOUR_TYPE,		PROPERTIES_WARNING_COLOUR,				"Warning colour",						"2.1",			new Color(255,130,130),														"",																							"Colour used to indicate that a property is invalid." },
			{ CHOICE_TYPE,		PROPERTIES_ADDITION_STRATEGY,			"Property addition strategy",			"2.1",			"Warn when invalid",														"Warn when invalid,Do not allow invalid",													"How to deal with properties that are invalid." },
			{ BOOLEAN_TYPE,		PROPERTIES_CLEAR_LIST_ON_LOAD,			"Clear list when load model",			"2.1",			new Boolean(true),															"",																							"Clear the properties list whenever a new model is loaded." }
		},
		{
			{ FONT_COLOUR_TYPE,	LOG_FONT,								"Display font",							"2.1",			new FontColorPair(new Font("monospaced", Font.PLAIN, 12), Color.black),		"",																							"Font used for the log display." },
			{ COLOUR_TYPE,		LOG_BG_COLOUR,							"Background colour",					"2.1",			new Color(255,255,255),														"",																							"Background colour for the log display." },
			{ INTEGER_TYPE,		LOG_BUFFER_LENGTH,						"Buffer length",						"2.1",			new Integer(10000),															"1,",																						"Length of the buffer for the log display." }
		}
	};
	
	public static final String[] oldPropertyNames =  {"simulator.apmcStrategy", "simulator.engine", "simulator.newPathAskDefault"};
	
	public DefaultSettingOwner[] optionOwners;
	private Hashtable<String,Setting> data;
	private boolean modified;
	
	private ArrayList<PrismSettingsListener> settingsListeners;
	
	/**
	 * Default constructor: set all options to default values. 
	 */
	public PrismSettings()
	{
		optionOwners = new DefaultSettingOwner[propertyOwnerIDs.length];
		
		int counter = 0;
		
		for(int i = 0; i < propertyOwnerIDs.length; i++)
		{
			optionOwners[i] = new DefaultSettingOwner(propertyOwnerNames[i], propertyOwnerIDs[i]);
			for(int j = 0; j < propertyData[i].length; j++)
			{
				counter++;
				Object[] setting = propertyData[i][j];
				String key = (String)setting[1];
				String display = (String)setting[2];
				String version = (String)setting[3];
				Object value = setting[4];
				String constraint = (String)setting[5];
				String comment = (String)setting[6];
				
				Setting set;
				
				if(setting[0].equals(STRING_TYPE))
				{
					set = new SingleLineStringSetting(display, (String)value, comment, optionOwners[i], false);
					set.setKey(key);
					set.setVersion(version);
					optionOwners[i].addSetting(set);
				}
				else if(setting[0].equals(INTEGER_TYPE))
				{
					if(constraint.equals(""))
						set = new IntegerSetting(display, (Integer)value, comment, optionOwners[i], false);
					else
						set = new IntegerSetting(display, (Integer)value, comment, optionOwners[i], false, new RangeConstraint(constraint));
					set.setKey(key);
					set.setVersion(version);
					optionOwners[i].addSetting(set);
				}
				else if(setting[0].equals(DOUBLE_TYPE))
				{
					//DO constraints for this double
					if(constraint.equals(""))
						set = new DoubleSetting(display, (Double)value, comment, optionOwners[i], false);
					else
						set = new DoubleSetting(display, (Double)value, comment, optionOwners[i], false, new RangeConstraint(constraint));
					set.setKey(key);
					set.setVersion(version);
					optionOwners[i].addSetting(set);
				}
				else if(setting[0].equals(BOOLEAN_TYPE))
				{
					//DO constraints for this boolean
					set = new BooleanSetting(display, (Boolean)value, comment, optionOwners[i], false);
					set.setKey(key);
					set.setVersion(version);
					optionOwners[i].addSetting(set);
				}
				else if(setting[0].equals(COLOUR_TYPE))
				{
					//DO constraints for this Color
					set = new ColorSetting(display, (Color)value, comment, optionOwners[i], false);
					set.setKey(key);
					set.setVersion(version);
					optionOwners[i].addSetting(set);
				}
				else if(setting[0].equals(CHOICE_TYPE))
				{
					//DO constraints for this choice
					StringTokenizer tokens = new StringTokenizer(constraint, ",");
					String[] choices = new String[tokens.countTokens()];
					int k = 0;
					while(tokens.hasMoreTokens())
					{
						choices[k++] = tokens.nextToken();
					}
					set = new ChoiceSetting(display, choices, (String)value, comment, optionOwners[i], false);
					set.setKey(key);
					set.setVersion(version);
					optionOwners[i].addSetting(set);
				}
				else if(setting[0].equals(FONT_COLOUR_TYPE))
				{
					//DO constraints for this FontColorPair
					set = new FontColorSetting(display, (FontColorPair)value, comment, optionOwners[i], false);
					set.setKey(key);
					set.setVersion(version);
					optionOwners[i].addSetting(set);
				}
				else if(setting[0].equals(FILE_TYPE))
				{
					set = new FileSetting(display, (File)value, comment, optionOwners[i], false);
					set.setKey(key);
					set.setVersion(version);
					optionOwners[i].addSetting(set);
				}
				else
				{
					System.err.println("Fatal error when loading properties: unknown setting type "+setting[0]);
				}
			}
			optionOwners[i].addObserver(this);
		}
		
		modified = false;
		
		//populate a hash table with the keys
		populateHashTable(counter);
		settingsListeners = new ArrayList<PrismSettingsListener>();
	}
	
	/**
	 * Copy constructor. 
	 */
	public PrismSettings(PrismSettings settings)
	{
		// Create anew with default values
		// (that way, we get a fresh set of Setting objects)
		this();
		// Then, copy across options
		for (Map.Entry<String,Setting> e : settings.data.entrySet()) {
			try {
				set(e.getKey(), e.getValue().getValue());
			} catch (PrismException ex) {
				// Should never happen
				System.err.println(ex);
			}
		}
	}
	
	private void populateHashTable(int size)
	{
		data = new Hashtable<String,Setting>(size);
		
		for(int i = 0; i < optionOwners.length; i++)
		{
			for(int j = 0; j < optionOwners[i].getNumSettings(); j++)
			{
				data.put(optionOwners[i].getSetting(j).getKey(), optionOwners[i].getSetting(j));
			}
		}
	}
	
	private Setting settingFromHash(String key)
	{
		return data.get(key);
	}
	
	public void addSettingsListener(PrismSettingsListener listener)
	{
		settingsListeners.add(listener);
	}
	
	public void removeSettingsListener(PrismSettingsListener listener)
	{
		settingsListeners.remove(listener);
	}
	
	public void notifySettingsListeners()
	{
		for(int i = 0; i < settingsListeners.size(); i++)
		{
			PrismSettingsListener listener = settingsListeners.get(i);
			listener.notifySettings(this);
		}
	}
	
	public File getLocationForSettingsFile()
	{
		return new File(System.getProperty("user.home")+File.separator+".prism");
	}
	
	public synchronized void saveSettingsFile() throws PrismException
	{
		File file = getLocationForSettingsFile();
		
		try
		{
			FileWriter out = new FileWriter(file);
			
			out.write("# PRISM settings file\n");
			out.write("# (created by version "+Prism.getVersion()+")\n");
			
			for(int i = 0; i < optionOwners.length; i++)
			{
				out.write("\n");
				for(int j = 0; j < optionOwners[i].getNumSettings(); j++)
				{
					Setting set = optionOwners[i].getSetting(j);
					//write the key
					out.write(set.getKey()+"=");
					String value = set.toString();
					while(value.indexOf('\n') != -1) //is multiline string
					{
						out.write(value.substring(0,value.indexOf('\n')) + "\\");
						if(value.substring(value.indexOf('\n')).length() > 0)
							value = value.substring(value.indexOf('\n')+1);
						else
							value = "";
					}
					
					out.write(value+"\n");
					
				}
			}
			
			out.close();
			
		}
		catch(IOException e)
		{
			throw new PrismException("Error exporting properties file: "+e.getMessage());
		}
		
		modified = false;
	}
	
	public synchronized void loadSettingsFile() throws PrismException
	{
		File file = getLocationForSettingsFile();
		
		BufferedReader reader;
		String line = null;
		String key = "";
		String value;
		int equalsIndex;
		StringBuffer multiline = new StringBuffer();
		boolean inMulti = false;
		String version;
		boolean resaveNeeded = false;
		
		try
		{
			// Read first two lines to extract version
			version = null;
			reader = new BufferedReader(new FileReader(file));
			if (reader.ready()) line = reader.readLine();
			if (reader.ready()) line = reader.readLine();
			Matcher matcher =  Pattern.compile("# \\(created by version (.+)\\)").matcher(line);
			if (matcher.find()) version = matcher.group(1);
			reader.close();
			
			// Do we need to resave the file?
			// (i.e. is the version of the saved settings (a) old? (b) unparseable?)
			if (version == null) version = "0";
			if (Prism.compareVersions(version, Prism.getVersion()) == -1) resaveNeeded = true;
			
			// Read whole file
			reader = new BufferedReader(new FileReader(file));
			while(reader.ready())
			{
				line = reader.readLine();
				if(!inMulti)
				{
					if(line.startsWith("#")) continue; //ignore comments
					equalsIndex = line.indexOf('=');
					if(equalsIndex == -1) continue; //is not a valid property line
					else
					{
						key = line.substring(0, equalsIndex);
						value = (equalsIndex==line.length()-1)?"":line.substring(equalsIndex+1);
						if(value.endsWith("\\"))
						{
							inMulti = true;
							multiline = new StringBuffer(value.substring(0, value.length()-1)); // trim the \ off
						}
						else
						{
							Setting set = settingFromHash(key);
							if(set != null)
							{
								// If the version of the settings file is not newer than the "version" of the setting,
								// and we are re-saving the file, overwrite the setting with the default value 
								if (resaveNeeded && Prism.compareVersions(version, set.getVersion()) <= 0) continue;
								try
								{
									Object valObj = set.parseStringValue(value);
									set.setValue(valObj);
								}
								catch(SettingException ee)
								{
									System.err.println("Warning: PRISM setting \""+key+"\" has invalid value \"" + value + "\"");
								}
							}
							else
							{
								// Warning for unused options disabled for now
								// (it's a pain when you have lots of branches with lots of new options)
								if (false) {
									// Make sure this is not an old PRISM setting and if not print a warning
									boolean isOld = false;
									for (int i = 0; i < oldPropertyNames.length; i++) {
										if (oldPropertyNames[i].equals(key)) {
											isOld = true;
											break;
										}
									}
									if (!isOld)
										System.err.println("Warning: PRISM setting \"" + key + "\" is unknown.");
								}
							}
						}
					}
				}
				else
				{
					//In multiline
					if(line.endsWith("\\"))
					{
						multiline.append(line.substring(0, line.length()-1));
					}
					else
					{
						Setting set = settingFromHash(key);
						if(set != null)
						{
							// If the version of the settings file is not newer than the "version" of the setting,
							// and we are re-saving the file, overwrite the setting with the default value 
							if (resaveNeeded && Prism.compareVersions(version, set.getVersion()) <= 0) continue;
							try
							{
								Object valObj = set.parseStringValue(multiline.toString() + line);
								set.setValue(valObj);
							}
							catch(SettingException ee)
							{
								System.err.println("Warning: PRISM setting \""+key+"\" has invalid value \"" + multiline.toString() + line + "\"");
							}
						}
						else
						{
							System.err.println("Warning: PRISM setting \""+key+"\" is unknown.");
						}
						
						inMulti = false;
						multiline = null;
					}
				}
			}
		}
		catch(IOException e)
		{
			throw new PrismException("Error importing properties file: "+e.getMessage());
		}
		
		modified = false;
		
		// If necessary, resave the preferences file
		if (resaveNeeded) {
			try {
				saveSettingsFile();
			}
			catch (PrismException e) {
			}
		}
		
		notifySettingsListeners();
	}
	
	public synchronized void loadDefaults()
	{
		for(int i = 0; i < propertyOwnerIDs.length; i++)
		{
			
			for(int j = 0; j < propertyData[i].length; j++)
			{
				Setting set = settingFromHash(propertyData[i][j][1].toString());
			
				if(set != null)
				{
					try
					{
						set.setValue(propertyData[i][j][4]);
					}
					catch(SettingException e)
					{
						System.err.println("Warning: Error with default value for PRISM setting \""+set.getName()+"\"");
					}
				}
			}
		}
		
		notifySettingsListeners();
	}
	
	/**
	 * Set an option by parsing one or more command-line arguments.
	 * Reads the ith argument (assumed to be in the form "-switch")
	 * and also any subsequent arguments required as parameters.
	 * Return the index of the next argument to be read.
	 * @param args Full list of arguments
	 * @param i Index of first argument to read
	 */
	public synchronized int setFromCommandLineSwitch(String args[], int i) throws PrismException
	{
		String sw, s;
		int j;
		double d;
		
		sw = args[i].substring(1);

		// Note: the order of these switches should match the -help output (just to help keep track of things).
		
		// ENGINES/METHODS:
		
		// Main model checking engine
		if (sw.equals("mtbdd") || sw.equals("m")) {
			set(PRISM_ENGINE, "MTBDD");
		}
		else if (sw.equals("sparse") || sw.equals("s")) {
			set(PRISM_ENGINE, "Sparse");
		}
		else if (sw.equals("hybrid") || sw.equals("h")) {
			set(PRISM_ENGINE, "Hybrid");
		}
		// PTA model checking methods
		else if (sw.equals("ptamethod")) {
			if (i < args.length - 1) {
				s = args[++i];
				if (s.equals("digital"))
					set(PRISM_PTA_METHOD, "Digital clocks");
				else if (s.equals("games"))
					set(PRISM_PTA_METHOD, "Stochastic games");
				else if (s.equals("bisim"))
					set(PRISM_PTA_METHOD, "Bisimulation minimisation");
				else
					throw new PrismException("Unrecognised option for -" + sw + " switch (options are: digital, games)");
			} else {
				throw new PrismException("No parameter specified for -" + sw + " switch");
			}
		}

		// NUMERICAL SOLUTION OPTIONS:
		
		// Linear equation solver method
		else if (sw.equals("power") || sw.equals("pow") || sw.equals("pwr")) {
			set(PRISM_LIN_EQ_METHOD, "Power");
		} else if (sw.equals("jacobi") || sw.equals("jac")) {
			set(PRISM_LIN_EQ_METHOD, "Jacobi");
		} else if (sw.equals("gaussseidel") || sw.equals("gs")) {
			set(PRISM_LIN_EQ_METHOD, "Gauss-Seidel");
			set(PRISM_MDP_SOLN_METHOD, "Gauss-Seidel");
		} else if (sw.equals("bgaussseidel") || sw.equals("bgs")) {
			set(PRISM_LIN_EQ_METHOD, "Backwards Gauss-Seidel");
		} else if (sw.equals("pgaussseidel") || sw.equals("pgs")) {
			set(PRISM_LIN_EQ_METHOD, "Pseudo-Gauss-Seidel");
		} else if (sw.equals("bpgaussseidel") || sw.equals("bpgs")) {
			set(PRISM_LIN_EQ_METHOD, "Backwards Pseudo-Gauss-Seidel");
		} else if (sw.equals("jor")) {
			set(PRISM_LIN_EQ_METHOD, "JOR");
		} else if (sw.equals("sor")) {
			set(PRISM_LIN_EQ_METHOD, "SOR");
		} else if (sw.equals("bsor")) {
			set(PRISM_LIN_EQ_METHOD, "Backwards SOR");
		} else if (sw.equals("psor")) {
			set(PRISM_LIN_EQ_METHOD, "Pseudo-SOR");
		} else if (sw.equals("bpsor")) {
			set(PRISM_LIN_EQ_METHOD, "Backwards Pseudo-SOR");
		}
		// Linear equation solver over-relaxation parameter
		else if (sw.equals("omega")) {
			if (i < args.length - 1) {
				try {
					d = Double.parseDouble(args[++i]);
					set(PRISM_LIN_EQ_METHOD_PARAM, d);
				} catch (NumberFormatException e) {
					throw new PrismException("Invalid value for -" + sw + " switch");
				}
			} else {
				throw new PrismException("No value specified for -" + sw + " switch");
			}
		}
		// Termination criterion (iterative methods)
		else if (sw.equals("relative") || sw.equals("rel")) {
			set(PRISM_TERM_CRIT, "Relative");
		}
		else if (sw.equals("absolute") || sw.equals("abs")) {
			set(PRISM_TERM_CRIT, "Absolute");
		}
		// Termination criterion parameter
		else if (sw.equals("epsilon") || sw.equals("e")) {
			if (i < args.length - 1) {
				try {
					d = Double.parseDouble(args[++i]);
					if (d < 0)
						throw new NumberFormatException("");
					set(PRISM_TERM_CRIT_PARAM, d);
				} catch (NumberFormatException e) {
					throw new PrismException("Invalid value for -" + sw + " switch");
				}
			} else {
				throw new PrismException("No value specified for -" + sw + " switch");
			}
		}
		// Max iters
		else if (sw.equals("maxiters")) {
			if (i < args.length - 1) {
				try {
					j = Integer.parseInt(args[++i]);
					if (j < 0)
						throw new NumberFormatException("");
					set(PRISM_MAX_ITERS, j);
				} catch (NumberFormatException e) {
					throw new PrismException("Invalid value for -" + sw + " switch");
				}
			} else {
				throw new PrismException("No value specified for -" + sw + " switch");
			}
		}

		// MODEL CHECKING OPTIONS:
		
		// Precomputation algs off
		else if (sw.equals("nopre")) {
			set(PRISM_PRECOMPUTATION, false);
		}
		else if (sw.equals("noprob0")) {
			set(PRISM_PROB0, false);
		}
		else if (sw.equals("noprob1")) {
			set(PRISM_PROB1, false);
		}
		// Fairness on/off
		else if (sw.equals("fair")) {
			set(PRISM_FAIRNESS, true);
		}
		else if (sw.equals("nofair")) {
			set(PRISM_FAIRNESS, false);
		}
		// Prob/rate checks off
		else if (sw.equals("noprobchecks")) {
			set(PRISM_DO_PROB_CHECKS, false);
		}
		// No steady-state detection
		else if (sw.equals("nossdetect")) {
			set(PRISM_DO_SS_DETECTION, false);
		}
		// SCC computation algorithm
		else if (sw.equals("sccmethod") || sw.equals("bsccmethod")) {
			if (i < args.length - 1) {
				s = args[++i];
				if (s.equals("xiebeerel"))
					set(PRISM_SCC_METHOD, "Xie-Beerel");
				else if (s.equals("lockstep"))
					set(PRISM_SCC_METHOD, "Lockstep");
				else if (s.equals("sccfind"))
					set(PRISM_SCC_METHOD, "SCC-Find");
				else
					throw new PrismException("Unrecognised option for -" + sw + " switch (options are: xiebeerel, lockstep, sccfind)");
			} else {
				throw new PrismException("No parameter specified for -" + sw + " switch");
			}
		}
		// Enable symmetry reduction
		else if (sw.equals("symm")) {
			if (i < args.length - 2) {
				set(PRISM_SYMM_RED_PARAMS, args[++i] + " " + args[++i]);
			} else {
				throw new PrismException("-symm switch requires two parameters (num. modules before/after symmetric ones)");
			}
		}
		// Abstraction-refinement engine options string (append if already partially specified)
		else if (sw.equals("aroptions")) {
			if (i < args.length - 1) {
				String arOptions = getString(PRISM_AR_OPTIONS);
				if ("".equals(arOptions))
					arOptions = args[++i].trim();
				else
					arOptions += "," + args[++i].trim();
				set(PRISM_AR_OPTIONS, arOptions);
			} else {
				throw new PrismException("No parameter specified for -" + sw + " switch");
			}
		}
		
		// OUTPUT OPTIONS:
		
		// Verbosity
		else if (sw.equals("verbose") || sw.equals("v")) {
			set(PRISM_VERBOSE, true);
		}
		// Extra dd info on
		else if (sw.equals("extraddinfo")) {
			set(PRISM_EXTRA_DD_INFO, true);
		}
		// Extra reach info on
		else if (sw.equals("extrareachinfo")) {
			set(PRISM_EXTRA_REACH_INFO, true);
		}
		
		// SPARSE/HYBRID/MTBDD OPTIONS:
		
		// Turn off compact option for sparse matrix storage
		else if (sw.equals("nocompact")) {
			set(PRISM_COMPACT, false);
		}
		// Sparse bits info
		else if (sw.equals("sbl")) {
			if (i < args.length - 1) {
				try {
					j = Integer.parseInt(args[++i]);
					if (j < -1)
						throw new NumberFormatException();
					set(PRISM_NUM_SB_LEVELS, j);
				} catch (NumberFormatException e) {
					throw new PrismException("Invalid value for -" + sw + " switch");
				}
			} else {
				throw new PrismException("No value specified for -" + sw + " switch");
			}
		}
		else if (sw.equals("sbmax")) {
			if (i < args.length - 1) {
				try {
					j = Integer.parseInt(args[++i]);
					if (j < 0)
						throw new NumberFormatException();
					set(PRISM_SB_MAX_MEM, j);
				} catch (NumberFormatException e) {
					throw new PrismException("Invalid value for -" + sw + " switch");
				}
			} else {
				throw new PrismException("No value specified for -" + sw + " switch");
			}
		}
		// Hybrid SOR info
		else if (sw.equals("sorl") || sw.equals("gsl")) {
			if (i < args.length - 1) {
				try {
					j = Integer.parseInt(args[++i]);
					if (j < -1)
						throw new NumberFormatException();
					set(PRISM_NUM_SOR_LEVELS, j);
				} catch (NumberFormatException e) {
					throw new PrismException("Invalid value for -" + sw + " switch");
				}
			} else {
				throw new PrismException("No value specified for -" + sw + " switch");
			}
		}
		else if (sw.equals("sormax") || sw.equals("gsmax")) {
			if (i < args.length - 1) {
				try {
					j = Integer.parseInt(args[++i]);
					if (j < 0)
						throw new NumberFormatException();
					set(PRISM_SOR_MAX_MEM, j);
				} catch (NumberFormatException e) {
					throw new PrismException("Invalid value for -" + sw + " switch");
				}
			} else {
				throw new PrismException("No value specified for -" + sw + " switch");
			}
		}
		// CUDD settings
		else if (sw.equals("cuddmaxmem")) {
			if (i < args.length - 1) {
				try {
					j = Integer.parseInt(args[++i]);
					if (j < 0)
						throw new NumberFormatException();
					set(PRISM_CUDD_MAX_MEM, j);
				} catch (NumberFormatException e) {
					throw new PrismException("Invalid value for -" + sw + " switch");
				}
			} else {
				throw new PrismException("No value specified for -" + sw + " switch");
			}
		}
		else if (sw.equals("cuddepsilon")) {
			if (i < args.length - 1) {
				try {
					d = Double.parseDouble(args[++i]);
					if (d < 0)
						throw new NumberFormatException("");
					set(PRISM_CUDD_EPSILON, d);
				} catch (NumberFormatException e) {
					throw new PrismException("Invalid value for -" + sw + " switch");
				}
			} else {
				throw new PrismException("No value specified for -" + sw + " switch");
			}
		}
		
		// ADVERSARIES/COUNTEREXAMPLES:
		
		// Export adversary to file
		else if (sw.equals("exportadv")) {
			if (i < args.length - 1) {
				set(PRISM_EXPORT_ADV, "DTMC");
				set(PRISM_EXPORT_ADV_FILENAME, args[++i]);
			} else {
				throw new PrismException("No file specified for -" + sw + " switch");
			}
		}
		// Export adversary to file, as an MDP
		else if (sw.equals("exportadvmdp")) {
			if (i < args.length - 1) {
				set(PRISM_EXPORT_ADV, "MDP");
				set(PRISM_EXPORT_ADV_FILENAME, args[++i]);
			} else {
				throw new PrismException("No file specified for -" + sw + " switch");
			}
		}
		
		// unknown switch - error
		else {
			throw new PrismException("Invalid switch -" + sw + " (type \"prism -help\" for full list)");
		}
		
		return i + 1;
	}
	
	/**
	 * Print a fragment of the -help message,
	 * i.e. a list of the command-line switches handled by this class.
	 */
	public void printHelp(PrismLog mainLog)
	{
		mainLog.println();
		mainLog.println("ENGINES/METHODS:");
		mainLog.println("-mtbdd (or -m) ................. Use the MTBDD engine");
		mainLog.println("-sparse (or -s) ................ Use the Sparse engine");
		mainLog.println("-hybrid (or -h) ................ Use the Hybrid engine [default]");
		mainLog.println("-ptamethod <name> .............. Specify PTA engine (games, digital) [default: games]");
		mainLog.println();
		mainLog.println("NUMERICAL SOLUTION OPTIONS:");
		mainLog.println("-power (or -pow, -pwr) ......... Use the Power method for numerical computation");
		mainLog.println("-jacobi (or -jac) .............. Use Jacobi for numerical computation [default]");
		mainLog.println("-gaussseidel (or -gs) .......... Use Gauss-Seidel for numerical computation");
		mainLog.println("-bgaussseidel (or -bgs) ........ Use Backwards Gauss-Seidel for numerical computation");
		mainLog.println("-pgaussseidel (or -pgs) ........ Use Pseudo Gauss-Seidel for numerical computation");
		mainLog.println("-bpgaussseidel (or -bpgs) ...... Use Backwards Pseudo Gauss-Seidel for numerical computation");
		mainLog.println("-jor ........................... Use JOR for numerical computation");
		mainLog.println("-sor ........................... Use SOR for numerical computation");
		mainLog.println("-bsor .......................... Use Backwards SOR for numerical computation");
		mainLog.println("-psor .......................... Use Pseudo SOR for numerical computation");
		mainLog.println("-bpsor ......................... Use Backwards Pseudo SOR for numerical computation");
		mainLog.println("-omega <x> ..................... Set over-relaxation parameter (for JOR/SOR/...) [default: 0.9]");
		mainLog.println("-relative (or -rel) ............ Use relative error for detecting convergence [default]");
		mainLog.println("-absolute (or -abs) ............ Use absolute error for detecting convergence");
		mainLog.println("-epsilon <x> (or -e <x>) ....... Set value of epsilon (for convergence check) [default: 1e-6]");
		mainLog.println("-maxiters <n> .................. Set max number of iterations [default: 10000]");
		mainLog.println();
		mainLog.println("MODEL CHECKING OPTIONS:");
		mainLog.println("-nopre ......................... Skip precomputation algorithms (where optional)");
		mainLog.println("-noprob0 ....................... Skip precomputation algorithm Prob0 (where optional)");
		mainLog.println("-noprob1 ....................... Skip precomputation algorithm Prob1 (where optional)");
		mainLog.println("-fair .......................... Use fairness (for model checking of MDPs)");
		mainLog.println("-nofair ........................ Don't use fairness (for model checking of MDPs) [default]");
		mainLog.println("-fixdl ......................... Automatically put self-loops in deadlock states");
		mainLog.println("-noprobchecks .................. Disable checks on model probabilities/rates");
		mainLog.println("-zerorewardcheck ............... Check for absence of zero-reward loops");
		mainLog.println("-nossdetect .................... Disable steady-state detection for CTMC transient computations");
		mainLog.println("-sccmethod <name> .............. Specify SCC computation method (xiebeerel, lockstep, sccfind)");
		mainLog.println("-symm <string> ................. Symmetry reduction options string");
		mainLog.println("-aroptions <string> ............ Abstraction-refinement engine options string");
		mainLog.println("-exportadv <file> .............. Export an adversary from MDP model checking (as a DTMC)");
		mainLog.println("-exportadvmdp <file> ........... Export an adversary from MDP model checking (as an MDP)");
		mainLog.println();
		mainLog.println("OUTPUT OPTIONS:");
		mainLog.println("-verbose (or -v) ............... Verbose mode: print out state lists and probability vectors");
		mainLog.println("-extraddinfo ................... Display extra info about some (MT)BDDs");
		mainLog.println("-extrareachinfo ................ Display extra info about progress of reachability");
		mainLog.println();
		mainLog.println("SPARSE/HYBRID/MTBDD OPTIONS:");
		mainLog.println("-nocompact ..................... Switch off \"compact\" sparse storage schemes");
		mainLog.println("-sbl <n> ....................... Set number of levels (for hybrid engine) [default: -1]");
		mainLog.println("-sbmax <n> ..................... Set memory limit (KB) (for hybrid engine) [default: 1024]");
		mainLog.println("-gsl <n> (or sorl <n>) ......... Set number of levels for hybrid GS/SOR [default: -1]");
		mainLog.println("-gsmax <n> (or sormax <n>) ..... Set memory limit (KB) for hybrid GS/SOR [default: 1024]");
		mainLog.println("-cuddmaxmem <n> ................ Set max memory for CUDD package (KB) [default: 200x1024]");
		mainLog.println("-cuddepsilon <x> ............... Set epsilon value for CUDD package [default: 1e-15]");
	}

	/**
	 * Set the value for an option, with the option key given as a String,
	 * and the value as an Object of appropriate type or a String to be parsed.
	 * For options of type ChoiceSetting, either a String or (0-indexed) Integer can be used.
	 */
	public synchronized void set(String key, Object value) throws PrismException
	{
		Setting set = settingFromHash(key);
		if (set == null)
			throw new PrismException("Property " + key + " is not valid");
		try
		{
			String oldValueString = set.toString();
			if (value instanceof String) {
				set.setValue(set.parseStringValue((String) value));
			} else if (value instanceof Integer && set instanceof ChoiceSetting) {
				int iv = ((Integer)value).intValue();
				((ChoiceSetting) set).setSelectedIndex(iv);
			} else {
				set.setValue(value);
			}
			notifySettingsListeners();
			if (!set.toString().equals(oldValueString))
				modified = true;
		}
		catch(SettingException e)
		{
			throw new PrismException(e.getMessage());
		}
	}
	
	public synchronized void setFileSelector(String key, FileSelector select)
	{
		Setting set = settingFromHash(key);
		if (set instanceof FileSetting) {
			FileSetting fset = (FileSetting)set;
			fset.setFileSelector(select);
		}
	}
	
	public synchronized String getString(String key)
	{
		Setting set = settingFromHash(key);
		if(set instanceof SingleLineStringSetting)
		{
			return ((SingleLineStringSetting)set).getStringValue();
		}
		else if(set instanceof MultipleLineStringSetting)
		{
			return ((MultipleLineStringSetting)set).getStringValue();
		}
		else if(set instanceof ChoiceSetting)
		{
			return ((ChoiceSetting)set).getStringValue();
		}
		else return DEFAULT_STRING;
	}
	
	public synchronized int getInteger(String key)
	{
		Setting set = settingFromHash(key);
		if(set instanceof IntegerSetting)
		{
			return ((IntegerSetting)set).getIntegerValue();
		}
		else if(set instanceof ChoiceSetting)
		{
			return ((ChoiceSetting)set).getCurrentIndex();
		}
		else return DEFAULT_INT;
	}
	
	public synchronized double getDouble(String key)
	{
		Setting set = settingFromHash(key);
		if(set instanceof DoubleSetting)
		{
			return ((DoubleSetting)set).getDoubleValue();
		}
		else return DEFAULT_DOUBLE;
	}
	
	public synchronized boolean getBoolean(String key)
	{
		Setting set = settingFromHash(key);
		if(set instanceof BooleanSetting)
		{
			return ((BooleanSetting)set).getBooleanValue();
		}
		else return DEFAULT_BOOLEAN;
	}
	
	public synchronized Color getColor(String key)
	{
		Setting set = settingFromHash(key);
		if(set instanceof ColorSetting)
		{
			return ((ColorSetting)set).getColorValue();
		}
		else return DEFAULT_COLOUR;
	}
	
	public synchronized FontColorPair getFontColorPair(String key)
	{
		Setting set = settingFromHash(key);
		if(set instanceof FontColorSetting)
		{
			return ((FontColorSetting)set).getFontColorValue();
		}
		else return DEFAULT_FONT_COLOUR;
	}
	
	public synchronized File getFile(String key)
	{
		Setting set = settingFromHash(key);
		if(set instanceof FileSetting)
		{
			return ((FileSetting)set).getFileValue();
		}
		else return DEFAULT_FILE;
	}
	
	public boolean isModified()
	{
		return modified;
	}
	
	public void update(Observable obs, Object obj)
	{
		modified = true;
		notifySettingsListeners();
	}
	
	public static void main(String[]args)
	{
		PrismSettings set = new PrismSettings();
		
		JFrame jf = new JFrame("Prism Settings");
		jf.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		ArrayList<DefaultSettingOwner> owners = new ArrayList<DefaultSettingOwner>();
		for(int i = 0; i < set.optionOwners.length; i++)
		{
			owners.add(set.optionOwners[i]);
		}
		
		SettingTable pt = new SettingTable(jf);
		pt.setOwners(owners);
		
		for(int i = 0; i < owners.size(); i++)
		{
			SettingOwner a = (SettingOwner)owners.get(i);
			a.setDisplay(pt);
		}
		
		jf.getContentPane().add(pt);
		jf.getContentPane().setSize(100, 300);
		
		jf.pack();
		jf.setVisible(true);
	}
}
