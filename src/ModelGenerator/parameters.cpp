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
#include <string.h>


#define BUILD_VERSION "Cosmos 1.4"

/**
 * Constructor for parameters, set all default values
 */
parameters::parameters() :
verbose(2),
interactive(false),
updatetime(100),
seed(0),
Njob(1),

epsilon(0.000001),
continuousStep(1),
Level(0.99),
Width(0.001),
Batch(1000),
MaxRuns(2000000),
sequential(true),
relative(false),

comp_uuid("tmpuuid"),
tmpPath("tmp"),
tmpStatus(0),
Path(""),
PathGspn(""),
PathLha(""),
constants(),
generateLHA(0),
loopLHA(0.0),
loopTransientLHA(0.0),
CSLformula(""),
externalHASL(""),

localTesting(false),
RareEvent(false),
DoubleIS(false),
BoundedRE(0),
horizon(100),
BoundedContinuous(false),

CountTrans(false),
StringInSpnLHA(false),

GMLinput(false),
computeStateSpace(0),
alligatorMode(false),
unfold(""),

gcccmd("g++"),
gccflags("-O3 -Wno-return-type"),

prismPath(""),
dataoutput(""),
dataraw(""),
datatrace(""),
sampleResol(0.0),
dataPDFCDF(""),
gnuplotDriver(""),
tracedPlace("ALL"),
dotfile(""),

HaslFormulas(vector<HaslFormulasTop*>(0)),
HaslFormulasname(vector<string>(0)),
nbAlgebraic(0),
nbPlace(0)
//prismPath = "/import/barbot/prism-4.0.1-linux64/bin/prism";
{
}

/**
 * Display the usage text
 */
void parameters::usage() {
    cout << "usage: Cosmos [-ghsr] [-vb arg] ";
    cout << "[--alligator-mode] ";
    cout << "[--level arg] [--width arg] [--batch arg] [--max-run arg] ";
    cout << "[--set-Horizon arg] [--njob arg] ";
    cout << "gspn_file lha_file" << endl;

    cout << "General options:" << endl;
    cout << "\t--version\tdisplay version number" << endl;
    cout << "\t-v,--verbose arg\tset the verbose level" << endl;
    cout << "\t-i,--interactive \tAsk the user to choose next transition" << endl;
    cout << "\t--update-time\t set the time in second beetween two updates of the display" << endl;
    cout << "\t-h,--help \tdisplay this message" << endl;
    cout << "\t--njob    \tset the number of parralel thread" << endl;
    cout << "\t--gppcmd  \tset the C++ compiler (default g++)" << endl;
    cout << "\t--gppflags\tset the C++ compiler flags (default -O3)" << endl;

    cout << "Option of simulation:" << endl;
    cout << "\t--level \tset the confidence level for the simulation (default=0.99)" << endl;
    cout << "\t--width \tset the width of the confidence interval (default=0.001)" << endl;
    cout << "\t--batch \tset the size of batch of simulation (default=1000)" << endl;
    cout << "\t--max-run \tset the maximal number of run (default=2000000)" << endl;
    cout << "\t--relative \tUse relative confidence interval instead of absolute one" << endl;
    cout << "\t--chernoff (level | width | nbrun)\tuse chernoff-hoeffding bound to compute the number of simulation" << endl;
    cout << "\t--seed \tSpecify the seed for the random generator, 0 allow to take a random value" << endl;
    cout << "\t--local-test \tUse local testing faster on big net" << endl;
    cout << "\t--const \toverride constant value of the model" << endl;

    cout << "Rare event options:" << endl;
    cout << "\t-r \tUnbounded rare event mode" << endl;
    cout << "\t-b arg \tDiscrete bounded rare event mode, arg is the method to use to stop vector" << endl;
    cout << "\t--set-Horizon arg \tSet the horizon for bounded rare event mode arg must be an integer in discrete bounded case" << endl;
    cout << "\t-c \tContinuous bounded rare event mode." << endl;
    cout << "\t--epsilon arg \tError level of the fox glynn algorithme" << endl;
    cout << "\t--step-continuous arg \tSize of step of the continuous method" << endl;


    cout << "Miscellaneous options:" << endl;
    cout << "\t-g,--grmlinput \tuse gml file format for input file" << endl;
    cout << "\t--alligator-mode \toutput easy to parse result" << endl;
    cout << "\t--unfold arg \tUnfold the GSPN given as input" << endl;
    cout << "\t--count-transition \tAdd a Hasl formula for wich count the number of time each transition occurs" << endl;
    cout << "\t--tmp-path arg \tPath to the temporary directory by default ./tmp/" << endl;
    cout << "\t--bin-path arg \tPath to the binary of cosmos (guess automatically)" << endl;
    cout << "\t--tmp-status arg \tDo not remove or do not rebuild tmp directory: 0 default->rebuild,destroy; 1->do not build;2->do not destroy;3-> do not build nor destroy" << endl;
    cout << "\t--debug-string \tAdd transition and place name to the compile file for debuging" << endl;
    cout << "\t-d,--outputdata \tOutput successive result in the blank separated file format" << endl;
    cout << "\t--output-raw \tOutput the result of each trajectory in a file for debug purpose" << endl;
    cout << "\t--output-trace arg resol \tOutput the trace each trajectory in the file arg with a resolution of resol" << endl;
    cout << "\t--output-graph \tOutput the result of CDF or PDF formula in gnuplot file format" << endl;
    cout << "\t--output-dot \tOutput the Petri net in a dot file" << endl;
    cout << "\t--gnuplot-driver terminal\tRun gnuplot on the output datafile to produce graph use the given terminal for gnuplot" << endl;
    cout << "\t--trace-pt arg\tSpecify which place to trace in all the output file, arg is a comma separated list of places and transitions name" << endl;
    cout << "\t--HASL-expression \tAllow to define an HASL formula from the command line" << endl;
    cout << "\t--loop t1 [--transtient t2] \tGenerate an LHA that loop for t1 times unit and then t2 time unit. The --transient option alone do not do anything" << endl;
    cout << "\t--sampling t1 t2 \tGenerate an LHA that loop for t1 times unit and sample the average number of token each t2 time units" << endl;
    cout << "\t--formula f\t specify a CSL formula to use instead of an automata" << endl;
    cout << "\t--prism \tExport the state space and lauch prism." << endl;
    cout << "\t-s,--state-space \tExport the state space." << endl;

}

/**
 * Parse the command line and set the parameter structure
 * with the option set by the user
 */
void parameters::parseCommandLine(int argc, char** argv) {
    int c;

    while (1) {
        static struct option long_options[] ={
            /* Options for the simulator*/
            {"level", required_argument, 0, 'l'},
            {"width", required_argument, 0, 'w'},
            {"batch", required_argument, 0, 2},
            {"max-run", required_argument, 0, 'm'},
            {"seed", required_argument, 0, 10},
            {"local-test", no_argument, 0, 12},
            {"sampling", required_argument, 0, 25},
            {"loop", required_argument, 0, 14},
            {"transient", required_argument, 0, 16},
            {"formula", required_argument, 0, 'f'},
            {"chernoff", required_argument, 0, 17},
            {"relative", no_argument, 0, 26},
            {"const", required_argument, 0, 21},

            /* Options for the rare event engine */
            {"rareevent", no_argument, 0, 'r'},
            {"boundedcountiniousRE", no_argument, 0, 'c'},
            {"boundedRE", required_argument, 0, 'b'},
            {"step-continuous", required_argument, 0, 23},
            {"epsilon", required_argument, 0, 'e'},
            {"set-Horizon", required_argument, 0, 1},
            {"state-space", no_argument, 0, 's'},
            {"prism", no_argument, 0, 'p'},
            {"normalize-IS", no_argument, 0, 27},

            /* CosyVerif Options */
            {"gmlinput", no_argument, 0, 'g'},
            {"grml-input", no_argument, 0, 'g'},
            {"alligator-mode", no_argument, 0, 'a'},

            /* Miscellaneous options */
            {"unfold", required_argument, 0, 24},
            {"HASL-formula", required_argument, 0, 13},
            {"HASL-expression", required_argument, 0, 13},
            {"njob", required_argument, 0, 'n'},
            {"gppcmd", required_argument, 0, 6},
            {"gppflags", required_argument, 0, 7},
            {"verbose", required_argument, 0, 'v'},
            {"interactive", no_argument, 0, 'i'},
            {"update-time", required_argument, 0, 'u'},
            {"outputdata", required_argument, 0, 'd'},
            {"output-data", required_argument, 0, 'd'},
            {"output-raw", required_argument, 0, 8},
            {"output-trace", required_argument, 0, 18},
            {"output-PDFCDF", required_argument, 0, 11},
            {"output-graph", required_argument, 0, 11},
            {"output-dot", required_argument, 0, 28},
            {"gnuplot-driver", required_argument, 0, 15},
            {"trace-place", required_argument, 0, 19},
            {"trace-pt", required_argument, 0, 19},
            {"help", no_argument, 0, 'h'},
            {"count-transition", no_argument, 0, 't'},
            {"debug-string", no_argument, 0, 3},
            {"tmp-path", required_argument, 0, 4},
            {"tmp-status", required_argument, 0, 5},
            {"bin-path", required_argument, 0, 9},
            {"prism-path", required_argument, 0, 20},
            {"version", no_argument, 0, 22},

            {0, 0, 0, 0}
        };
        /* getopt_long stores the option index here. */
        int option_index = 0;

        c = getopt_long(argc, argv, "gihscrb:v:d:",
                long_options, &option_index);

        /* Detect the end of the options. */
        if (c == -1)
            break;

        switch (c) {
            case 'h':
                usage();
                exit(EXIT_SUCCESS);
                break;

            case 'v':verbose = atoi(optarg);
                if (verbose >= 4)StringInSpnLHA = true;
                break;

            case 'i':
                interactive = true;
                verbose = 6;
                StringInSpnLHA = true;
                break;

            case 'u':updatetime = chrono::duration_cast<chrono::milliseconds>(chrono::duration<double> (atof(optarg)));
                break;

            case 'g':GMLinput = true;
                break;

            case 'r':
                RareEvent = true;
                StringInSpnLHA = true; // Need to know the name of place to find
                // place begining with "RE_"
                localTesting = false; //Need to unfire transition not implemented for local testing
                relative = true;
                break;

            case 26:
                relative = true;
                break;

            case 27:
                DoubleIS = true;
                break;

            case 'b':BoundedRE = atoi(optarg);
                StringInSpnLHA = true;
                RareEvent = true;
                relative = true;
                break;

            case 'c':BoundedContinuous = true;
                RareEvent = true;
                break;

            case 1:horizon = atof(optarg);
                break;

            case 's':computeStateSpace = 2;
                StringInSpnLHA = true;
                localTesting = false; //Need to unfire transition, not implemented for local testing
                break;

            case 'p':computeStateSpace = 1;
                StringInSpnLHA = true;
                localTesting = false; //Need to unfire transition, not implemented for local testing
                break;

            case 'a':alligatorMode = true;
                verbose = 0;
                break;

            case 24:unfold = optarg;
                break;

            case 'l':Level = atof(optarg);
                break;
            case 'w':Width = atof(optarg);
                break;
            case 2: Batch = atol(optarg);
                break;
            case 'm': MaxRuns = atol(optarg);
                break;
            case 17: sequential = false;
                if (strcmp(optarg, "level") == 0)Level = 0;
                else if (strcmp(optarg, "width") == 0)Width = 0;
                else if (strcmp(optarg, "nbrun") == 0)MaxRuns = 0;
                else {
                    cerr << "Required one of (level | width | nbrun) to specify which ";
                    cerr << "parameter should be computed" << endl;
                    usage();
                    exit(EXIT_FAILURE);
                }


                break;
            case 12: localTesting = !localTesting;
                break;
            case 'n': Njob = atoi(optarg);
                break;
            case 'e': epsilon = atof(optarg);
                break;
            case 23: continuousStep = atoi(optarg);
                break;
            case 'd': dataoutput = optarg;
                break;
            case 8: dataraw = optarg;
                break;
            case 28: dotfile = optarg;
                break;
            case 18:
                datatrace = optarg;
                StringInSpnLHA = true;
                if (optind == argc) {
                    usage();
                    exit(EXIT_FAILURE);
                }
                sampleResol = atof(argv[optind]);
                optind++;
                break;

            case 11: dataPDFCDF = optarg;
                break;
            case 't': CountTrans = true;
                break;
            case 3: StringInSpnLHA = true;
                break;
            case 4: tmpPath = optarg;
                break;
            case 9: Path = optarg;
                break;
            case 5: tmpStatus = atoi(optarg);
                break;
            case 6: gcccmd = optarg;
                break;
            case 7: gccflags = optarg;
                break;
            case 10: seed = atoi(optarg);
                break;
            case 13: externalHASL = optarg;
                break;
            case 14:
                loopLHA = atof(optarg);
                generateLHA = 1;
                PathLha = "LOOP";
                break;
            case 25:
                loopLHA = atof(optarg);
                generateLHA = 2;
                PathLha = "SAMPLING";
                if (optind == argc) {
                    usage();
                    exit(EXIT_FAILURE);
                }
                loopTransientLHA = atof(argv[optind]);
                optind++;
                break;
            case 16: loopTransientLHA = atof(optarg);
                break;
            case 'f': CSLformula = optarg;
                break;

            case 15: gnuplotDriver = optarg;
                break;

            case 19: tracedPlace = optarg;
                break;
            case 20: prismPath = optarg;
                break;

            case 21: // const
            {
                string conststr = optarg;
                size_t index, index2;
                index2 = conststr.find('=', 0) + 1;
                for (index = 0; index != string::npos; index2 = conststr.find('=', index) + 1) {
                    string varname = conststr.substr(index, index2 - index - 1);
                    index = conststr.find(',', index2);
                    string varvalue;
                    if (index == string::npos) {
                        varvalue = conststr.substr(index2, conststr.length() - index2);
                    } else {
                        varvalue = conststr.substr(index2, index - index2);
                        index++;
                    }
                    constants[varname] = varvalue;
                }

                break;
            }
            case 22:
                cout << BUILD_VERSION << " Build Date:" << __DATE__ " at " << __TIME__ << endl;
                exit(0);

            case '?':
                usage();
                exit(EXIT_FAILURE);

            default:
                usage();
                exit(EXIT_FAILURE);
        }
    }

    //If no LHA is required only set the path for the GSPN.
    if (optind + 1 == argc && (loopLHA > 0.0 || !CSLformula.empty() || !unfold.empty())) {
        PathGspn = argv[optind];
    } else if (optind + 2 == argc) {
        PathGspn = argv[optind];
        PathLha = argv[optind + 1];
    } else {
        if (optind + 2 > argc) {
            cout << "Two files are require." << endl;
        } else {
            cout << "Unrecognize option:" << argv[optind + 2] << endl;
        }

        usage();
        exit(EXIT_FAILURE);
    }
}
