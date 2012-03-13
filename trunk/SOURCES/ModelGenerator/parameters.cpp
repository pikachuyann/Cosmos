/*******************************************************************************
 *                                                                             *
 * Cosmos:(C)oncept et (O)utils (S)tatistique pour les (Mo)deles               *
 * (S)tochastiques                                                             *
 *                                                                             *
 * Copyright (C) 2009-2012 LSV & LACL                                          *
 * Authors: Paolo Ballarini Benoît Barbot & Hilal Djafri                       *
 * Website: http://www.lsv.ens-cachan.fr/Software/cosmos                       *
 *                                                                             *
 * This program is free software; you can redistribute it and/or modify        *
 * it under the terms of the GNU General Public License as published by        *
 * the Free Software Foundation; either version 3 of the License, or           *
 * (at your option) any later version.                                         *
 *                                                                             *
 * This program is distributed in the hope that it will be useful,             *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of              *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the               *
 * GNU General Public License for more details.                                *
 *                                                                             *
 * You should have received a copy of the GNU General Public License along     *
 * with this program; if not, write to the Free Software Foundation, Inc.,     *
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.                 *
 * file parameters.cpp                                                         *
 * Created by Benoit Barbot on 08/02/12.                                       *
 *******************************************************************************
 */

#include "parameters.hpp"
#include <boost/program_options.hpp>
#include <iostream>


namespace po = boost::program_options;


parameters::parameters() {
    verbose =1;
	Level = 0.99;
    epsilon = 0.000001;
	Width = 0.001;
	Batch =   1000;
	MaxRuns = 2000000;
	Path = "";
	RareEvent = false;
	DoubleIS = false;
	BoundedRE = 0;
    horizon =100;
    BoundedContinuous = false;
	Njob = 1;
	GMLinput = false;
    computeStateSpace = false;
	alligatorMode = false;
}



void parameters::View() {
	cout << "Confidence interval width:      " << Width << endl;
	cout << "Confidence interval level:      " << Level << endl;
	cout << "Maximum number of trajectories: " << MaxRuns << endl;
	cout << "Batch size:                     " << Batch << endl;
	cout << "Rare Event:                     " << RareEvent << endl;
	cout << "Double Important Sampling:      " << DoubleIS << endl;
	cout << "Number of parallel execution:   " << Njob << endl;
	cout << "Read GML file as input:         " << GMLinput << endl;  
}


void parameters::parseCommandLine(int argc, char** argv){
    po::options_description desc("usage: Cosmos [options] GspnFile LhaFile\n\nAllowed options");
	desc.add_options()
    ("help", "produce help message")
	("GMLinput,g",po::bool_switch(&GMLinput),"Change input file format")
	("RareEvent,r",po::bool_switch(&RareEvent),"Use Rare Event acceleration")
	("DoubleIS,d",po::bool_switch(&DoubleIS),"Use Rare Event acceleration with double Important Sampling")
	("BoundedRE,b",po::value(&BoundedRE),"Use Bounded Rare Event acceleration")
    ("BoundedContinuous,c",po::bool_switch(&BoundedContinuous),"Use Continuous Rare Event acceleration")
    ("set-Horizon",po::value(&horizon),"Set the horizon for bounded until")
    ("verbose,v",po::value(&verbose),"Set the verbose level")
    ("StateSpace,s",po::bool_switch(&computeStateSpace),"Generate the state space of the systeme")
	("alligator-mode",po::bool_switch(&alligatorMode),"alligator mode")
	("setPath,p",po::value(&Path),"Set executable path")
	("level",po::value(&Level),"Set Confidence interval level")
	("width",po::value(&Width),"Set Confidence interval width")
	("batch",po::value(&Batch),"Set Batch Size")
	("max-run",po::value(&MaxRuns),"Set the maximum number of run")
	("njob",po::value(&Njob),"Set the number of parallel simulation")
	("epsilon",po::value(&epsilon),"Set epsilon value for fox-glynn algorith")
	;
	
	po::options_description hidden("Hidden options");
	hidden.add_options()
	("GspnFile",po::value(&PathGspn),"Path to the Gspn")
	("LhaFile",po::value(&PathLha),"Path to the Lha")
	;
	
	po::positional_options_description p;
	p.add("GspnFile", 1);
	p.add("LhaFile", 2);
	
	po::options_description visible("Allowed options");
	visible.add(desc).add(hidden);
	
	po::variables_map vm;
	po::store(po::command_line_parser(argc, argv).
			  options(visible).positional(p).run(), vm);
	//po::store(po::parse_command_line(argc, argv, desc), vm);
	po::notify(vm);    
	
	if (vm.count("help")) {
		cout << desc << "\n";
		exit(EXIT_FAILURE);
	}
	
	//ViewParameters(P);
	
	if (!vm.count("LhaFile") || !vm.count("GspnFile")) {
		cout << desc << "\n";
		//cout << "usage: ... " << endl;
		exit(EXIT_FAILURE);
	} 	

}