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
#include <iostream>
#include <cstdlib>
#include <getopt.h>

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
    //prismPath = "/Applications/prism-4.0.2-osx64/bin/prism";
    prismPath = "/import/barbot/prism-4.0.1-linux64/bin/prism";

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

void parameters::usage(){
    cout << "usage: Cosmos [-ghsr] [-vb arg] ";
    cout << "[--alligator-mode] ";
    cout << "[--level arg] [--width arg] [--batch arg] [--max-run arg] ";
    cout << "[--set-Horizon arg] [--njob arg] ";
    cout << "gspn_file lha_file" << endl;
    
    cout << "General options:" << endl;
    cout << "\t-v,--verbose arg\tset the verbose level"<< endl;
    cout << "\t-h,--help \tdisplay this message" << endl;
    cout << "\t--njob    \tset the number of parralel thread"<< endl;
    cout << "Option of simulation:" << endl;
    cout << "\t--level \tset the confidence level for the simulation (default=0.99)"<< endl;
    cout << "\t--width \tset the width of the confidence interval (default=0.001)"<< endl;
    cout << "\t--batch \tset the size of batch of simulation (default=1000)"<< endl;
    cout << "\t--max-run \tset the maximal number of run (default=2000000)" << endl;
    cout << "Miscellanous options:" << endl;
    cout << "\t-g,--gmlinput \tuse gml file format for input file"<< endl;
    cout << "\t--alligator-mode \toutput easy to parse result"<< endl;
}
    

void parameters::parseCommandLine(int argc, char** argv){
    int c;
    
    while (1)
    {
        static struct option long_options[] =
        {
            /* Options for the simulator*/
            {"level" , required_argument, 0, 'l'},
            {"width" , required_argument, 0, 'w'},
            {"batch" , required_argument, 0,  2 },
            {"max-run",required_argument, 0, 'm'},
            
            /* Options for the rare event engine */
            {"rareevent",   no_argument,        0, 'r'},
            {"boundedcountiniousRE",no_argument,0, 'c'},
            {"boundedRE",   required_argument,  0, 'b'},
            {"epsilon" ,    required_argument,  0, 'e'},
            {"set-Horizon", required_argument , 0,  1 },
            {"stateSpace" , no_argument ,       0, 's'},

            /* CosyVerif Options */
            {"gmlinput" ,      no_argument, 0, 'g'},
            {"alligator-mode", no_argument, 0, 'a'},

            /* Miscellanious options */
            {"njob" , required_argument, 0 , 'n'},
            {"verbose", required_argument, 0, 'v'},
            {"help" , no_argument , 0 , 'h'},
            
            {0, 0, 0, 0}
        };
        /* getopt_long stores the option index here. */
        int option_index = 0;
        
        c = getopt_long (argc, argv, "ghscrb:v:",
                         long_options, &option_index);
        
        /* Detect the end of the options. */
        if (c == -1)
            break;
        
        switch (c)
        {
            case 'h':
                usage();
                exit(EXIT_SUCCESS);
                break;
                
            case 'v':verbose = atoi(optarg);   break;
                
            case 'g':GMLinput = true;          break;
                
            case 'r':RareEvent = true;          break;
                
            case 'b':BoundedRE = atoi(optarg);
                RareEvent=true;
                break;
                
            case 'c':BoundedContinuous = true;
                RareEvent=true;
                break;
               
            case  1:horizon = atof(optarg);     break;
                
            case 's':computeStateSpace= true;  break;
                
            case 'a':alligatorMode = true;  break;
                            
            case  'l':Level = atof(optarg);     break;
            case  'w':Width = atof(optarg);     break;
            case  2: Batch = atoi(optarg);      break;
            case  'm': MaxRuns = atoi(optarg);      break;
            case  'n': Njob = atoi(optarg);      break;
            case  'e': epsilon = atof(optarg);  break;
                
            case '?':
                usage();
                exit(EXIT_FAILURE);
                
            default:
                abort ();
        }
    }
   
    if (optind+1 < argc){
        PathGspn = argv[optind];
        PathLha  = argv[optind+1];
    }else{
        cout << "Two files are require." << endl;
        usage();
        exit(EXIT_FAILURE);
    }
}