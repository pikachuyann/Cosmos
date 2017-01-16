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
 * file Generator.cpp                                                          *
 * Created by Benoit Barbot on 21/01/2014.                                     *
 *******************************************************************************
 */


#include <fstream>
#include <iostream>
#include <string>

#include "Generator.hpp"
#include "parameters.hpp"
#include "LhaParser/Lha-Reader.hpp"
#include "GspnParser/Gspn-Writer.hpp"
#include "GspnParser/Gspn-Writer-Color.hpp"


using namespace std;

shared_ptr<GspnType> ParseGSPN() {

    // initialize an empty structure for the model.
    Gspn_Reader gReader(P);

    if (P.verbose > 0)cout << "Start Parsing " << P.PathGspn << endl;
    int parseresult;

    try {
        // Check the extension of the model file to call the correct parser
        if (!P.GMLinput
        && P.PathGspn.substr(P.PathGspn.length() - 4, 4) != "grml"
        && P.PathGspn.substr(P.PathGspn.length() - 3, 3) != "gml"
        && P.PathGspn.substr(P.PathGspn.length() - 4, 4) != "gspn"){
            if(P.verbose>0)cerr << "Input file not in GrML try to use convertor."<< endl;
            auto outspt = P.tmpPath + "/generatedspt";
            stringstream cmd;
            cmd << P.Path << "modelConvert --grml ";
            if(P.lightSimulator)cmd << "--light ";
            cmd << P.PathGspn << " " << outspt;
            if (P.verbose > 0)cout << cmd.str() << endl;
            if (system(cmd.str().c_str()) != 0) {
                cerr << "Fail to Convert from input language to GrML!" << endl;
                return nullptr;
            }
            P.PathGspn = outspt+".grml";
        }
        
        if (P.GMLinput
            || (P.PathGspn.compare(P.PathGspn.length() - 4, 4, "grml") == 0)
            || (P.PathGspn.compare(P.PathGspn.length() - 3, 3, "gml") == 0)) {
            parseresult = gReader.parse_gml_file(P);
        } else {
            parseresult = gReader.parse_file(P.PathGspn);
        }
        P.nbPlace = gReader.spn->pl;

        if(parseresult==1 || !gReader.spn)return nullptr;

        //The following code modify the internal representation of the
        //SPN according to options.

        //Set the isTraced flag for places, transitions and hybrid var
        if (P.tracedPlace.count("ALL") == 0 && P.tracedPlace.count("ALLCOLOR")==0 ) {
            P.nbPlace = 0;
            for (size_t i = 0; i < gReader.spn->pl; i++) {
                if (P.tracedPlace.count(gReader.spn->placeStruct[i].name)>0) {
                    gReader.spn->placeStruct[i].isTraced = true;
                    P.nbPlace++;
                } else {
                    gReader.spn->placeStruct[i].isTraced = false;
                }
            }
            for (size_t i = 0; i < gReader.spn->tr; i++) {
                if ( P.tracedPlace.count(gReader.spn->transitionStruct[i].name)>0 ) {
                    gReader.spn->transitionStruct[i].isTraced = true;
                } else {
                    gReader.spn->transitionStruct[i].isTraced = false;
                }
            }
            for (auto &v: gReader.spn->hybridVars) {
                if ( P.tracedPlace.count(v.name)>0 ) {
                    v.isTraced = true;
                } else {
                    v.isTraced = false;
                }
            }
        }

        //Apply Law of mass action for MASSACTION distribution:
        for (size_t t = 0; t < gReader.spn->tr; t++) {
            ProbabiliteDistribution *trDistr = &gReader.spn->transitionStruct[t].dist;
            if (trDistr->name.compare("MASSACTION") == 0) {
                gReader.spn->transitionStruct[t].markingDependant = true;
                for (size_t p = 0; p < gReader.spn->pl; p++) {
                    if (!gReader.spn->access(gReader.spn->inArcsStruct, t, p).isEmpty) {
                        expr exponent = gReader.spn->access(gReader.spn->inArcsStruct, t, p).exprVal;
                        /*if (gReader.spn->access(gReader.spn->inArcsStruct, t, p).isMarkDep) {
                            exponent = expr(gReader.spn->access(gReader.spn->inArcsStruct, t, p).stringVal);
                        } else {
                            exponent = expr((int) gReader.spn->access(gReader.spn->inArcsStruct, t, p).intVal);
                        }*/
                        expr pl = expr(PlaceName, gReader.spn->placeStruct[p].name);
                        expr mult = expr(Pow, pl, exponent);
                        expr dist = expr(Times, trDistr->Param[0], mult);

                        trDistr->Param[0] = dist;
                    }
                }
            }
        }

        //Check that the model is not empty and generate the code
        if (!parseresult && gReader.spn->pl > 0 && gReader.spn->tr > 0) {
            Gspn_Writer_Color writer(*gReader.spn, P);
            writer.writeFile();
            writer.writeDotFile(P.tmpPath + "/templatePetriNet.dot");
        } else {
            cout << "Empty model for the GSPN: abort" << endl;
            return nullptr;
        }
    } catch (exception& e) {
        cerr << "The following exception append during import: " << e.what() << endl;
        return nullptr;
    }

    return gReader.spn;
    }

bool ParseLHA(){
    GspnType emptyGSPN;

    return ParseLHA(emptyGSPN);
}

bool ParseLHA(GspnType &spn){
    // Intialize an empty structure for the automaton
    Lha_Reader lReader(spn, P);
    auto &A = lReader.MyLha;

    int parseresult;

    //Copy name of transition and place required for synchronization.
    A.TransitionIndex = spn.TransId;
    A.PlaceIndex = spn.PlacesId;
    A.ConfidenceLevel = P.Level;
    if(! A.isDeterministic )P.lhaType= NOT_DET;

    if (P.verbose > 0)cout << "Start Parsing " << P.PathLha << endl;

    try {
        // If the automaton need to be generated from a formula
        // call the generating tool.
        if (!P.CSLformula.empty()) {
            P.PathLha = P.tmpPath + "/generatedlha.lha";
            stringstream cmd;
            cmd << "echo \"" << P.CSLformula << "\" | " << P.Path <<
                    "automataGen >" << P.PathLha;
            if (P.verbose > 0)cout << cmd.str() << endl;
            if (system(cmd.str().c_str()) != 0) {
                cerr << "Fail to Generate the Automaton!" << endl;
                return false;
            }
        }

        if (P.generateLHA == TimeLoop || P.generateLHA == ActionLoop)generateLoopLHA(spn);
        if (P.generateLHA == SamplingLoop)generateSamplingLHA(spn);

        //check the type of the LHA file
        //First check if it is not C++ code
        if (P.PathLha.compare(P.PathLha.length() - 3, 3, "cpp") != 0) {

            if (P.PathLha.compare(P.PathLha.length() - 4, 4, "grml") == 0) {
                //The LHA is in the GRML file format
                parseresult = lReader.parse_gml_file(P);
            } else {
                //The LHA is in the LHA file format
                parseresult = lReader.parse_file(P);
            }

            //Add external HASL formula to the lha.
            if (P.externalHASL.compare("") != 0)
                lReader.parse(P.externalHASL);

            //Set the isTraced flag for variables
            if (P.tracedPlace.count("ALL")==0 && P.tracedPlace.count("ALLCOLOR")==0) {
                for (size_t i = 0; i < A.NbVar; i++) {
                    if ( P.tracedPlace.count(A.Vars.label[i])>0){
                        A.Vars.isTraced[i] = true;
                    } else {
                        A.Vars.isTraced[i] = false;
                    }
                }
            }

            //If everythink work correctly, copy the HASL formula and generate the code
            if (!parseresult && A.NbLoc > 0) {
                P.HaslFormulasname = A.HASLname;
                P.HaslFormulas = vector<HaslFormulasTop*>(A.HASLtop);
                P.nbAlgebraic = A.Algebraic.size();
                P.nbQualitatif = A.FinalStateCond.size();

                //If the countTrans option is set then add HASL formula counting the occurance of each transition of the LHA.
                if (P.CountTrans) {
                    for (size_t tr = 0; tr < A.Edge.size(); tr++) {
                        P.nbAlgebraic++;
                        std::stringstream transname;
                        transname << "P_";
                        transname << A.LocLabel[A.Edge[tr].Source];
                        transname << "->";
                        transname << A.LocLabel[A.Edge[tr].Target];
                        P.HaslFormulasname.push_back(transname.str());
                        P.HaslFormulas.push_back(new HaslFormulasTop(A.Algebraic.size() + tr));
                    }
                }

                //some cleaning:
                A.SimplyUsedLinearForm = vector<bool>(A.LinearForm.size(),true);
                for( size_t i = 0; i< A.LhaFuncArg.size();++i)
                    if(A.LhaFuncType[i]!="Last")
                        A.SimplyUsedLinearForm[A.LhaFuncArg[i]] = false;


                //Generate the code for the LHA
                lReader.WriteFile(P);
                lReader.writeDotFile(P.tmpPath + "/templateLHA.dot");

            } else {
                return false;
            }

            //If the LHA is already C++ code just copy it to temporary
            //and add external HASL formula
        } else if (P.PathLha.compare(P.PathLha.length() - 3, 3, "cpp") == 0) {
            //The code for the LHA is provided by the user
            A.ConfidenceLevel = P.Level;
            //Add external HASL formula
            if (P.externalHASL.compare("") == 0) {
                P.HaslFormulasname.push_back("preComputedLHA");
                HaslFormulasTop *ht = new HaslFormulasTop((size_t) 0);
                P.HaslFormulas.push_back(ht);
                P.nbAlgebraic = 1;
            } else {
                parseresult = lReader.parse(P.externalHASL);
                if (!parseresult) {
                    P.HaslFormulasname = A.HASLname;
                    P.HaslFormulas = vector<HaslFormulasTop*>(A.HASLtop);
                    P.nbAlgebraic = A.Algebraic.size();
                } else
                    cerr << "Fail to parse extra Hasl Formula" << endl;
            }

            //Copy the code into the temporary directory
            if( P.PathLha != P.tmpPath + "/LHA.cpp"){
                string cmd = "cp " + P.PathLha + " " + P.tmpPath + "/LHA.cpp";
                if (P.verbose > 2)cout << cmd << endl;
                if (system(cmd.c_str()) != 0) {
                    cerr << "Fail to copy LHA to temporary" << endl;
                    return false;
                }
            }
        }
    } catch (exception& e) {
        cerr << "The following exception append during import: " << e.what() << endl;
        return false;
    }

    string cmd;

    if (P.RareEvent) {
        //If rareevent handling is require copy the lumping function and table of value to the temporary directory
        if (P.BoundedRE == 0)cmd = "cp muFile " + P.tmpPath + "/muFile";
        else cmd = "cp matrixFile " + P.tmpPath + "/matrixFile";
        if (system(cmd.c_str())) return false;
        cmd = "cp lumpingfun.cpp " + P.tmpPath + "/lumpingfun.cpp";
        if (system(cmd.c_str())) return false;

        //Rewrite part of probabilistic operator to apply Rare event handling
        //First case for Continuous bounded rare event.
        if (P.BoundedContinuous) {
            for (vector<HaslFormulasTop*>::iterator it = P.HaslFormulas.begin();
                    it != P.HaslFormulas.end(); ++it)
                if ((*it)->TypeOp == EXPECTANCY) {
                    (*it)->TypeOp = RE_Continuous;
                    (*it)->Value = P.continuousStep;
                    (*it)->Value2 = P.epsilon;

                }
        } else { // Second case Unbounded rare event.
            vector<HaslFormulasTop*> tmpRE;
            vector<string> tmpREName;
            for (vector<HaslFormulasTop*>::iterator it = P.HaslFormulas.begin();
                    it != P.HaslFormulas.end(); ++it)
                if ((*it)->TypeOp == EXPECTANCY) {
                    (*it)->TypeOp = RE_AVG;
                    HaslFormulasTop *HaslCopy = new HaslFormulasTop(**it);
                    HaslCopy->TypeOp = RE_Likelyhood;
                    tmpRE.push_back(HaslCopy);
                    tmpREName.push_back("Likelyhood_" + P.HaslFormulasname[it - P.HaslFormulas.begin() ]);
                }
            for (vector<HaslFormulasTop*>::iterator it = tmpRE.begin();
                    it != tmpRE.end(); ++it) {
                P.HaslFormulas.push_back(*it);
                P.HaslFormulasname.push_back(tmpREName[it - tmpRE.begin()]);
            }
        }
    }

    //generateMain();

    return true;

}

void generateMain() { // Not use for the moment
    string loc;

    loc = P.tmpPath + "/main.cpp";
    ofstream mF(loc.c_str(), ios::out | ios::trunc);

    mF << "#include \"BatchR.hpp\"" << endl;
    mF << "#include \"clientsim.hpp\"" << endl;
    /*mF << "#include \"Simulator.hpp\"" << endl;
    mF << "#include \"SimulatorRE.hpp\"" << endl;
    mF << "#include \"SimulatorBoundedRE.hpp\"" << endl;
    mF << "#include \"SimulatorContinuousBounded.hpp\"" << endl;
    mF << "#include <sys/types.h>" << endl;
    mF << "#include <unistd.h>" << endl;
    mF << "#include <signal.h>" << endl;*/
    
    mF << "int main(int argc, char** argv) {" << endl;
    mF << "    signal(SIGINT, signalHandler);" << endl;

    if( P.computeStateSpace>0){
        mF << "stateSpace states;" << endl;
        mF << "states.exploreStateSpace();" << endl;
        mF << "states.buildTransitionMatrix();" << endl;
        if(P.computeStateSpace==1){
            mF << "states.outputPrism();" << endl;
            mF << "states.launchPrism(\""<< P.prismPath <<"\");" << endl;
            mF << "states.importPrism();" << endl;
            mF << "states.outputVect();" << endl;
            mF << "states.outputTmpLumpingFun();" << endl;
            mF << "double prResult = states.returnPrismResult();" << endl;
            mF << "BatchR dummR(1,0);" << endl;
            mF << "SimOutput sd;" << endl;
            mF << "sd.accept=true;" << endl;
            mF << "sd.quantR.push_back(prResult);" << endl;
            mF << "dummR.addSim(sd);" << endl;
        } else{
            //states.uniformizeMatrix();
            mF << "states.outputMat();" << endl;
            mF << "states.outputTmpLumpingFun();" << endl;
            mF << "BatchR dummR(0,0);" << endl;
        }
        mF << "dummR.outputR(cout);" << endl;
        mF << "cerr << \"Finish Exporting\" << endl;" << endl;
        mF << "exit(EXIT_SUCCESS);" << endl;
        mF << "}" << endl;
        return;
    }
    
    // Instantiate EventQueue
    const auto eqt = (P.is_domain_impl_set ? "EventsQueueSet" :"EventsQueue<vector<_trans>>");

    // Instantiate DEDS
    if (P.BoundedRE > 0 || P.BoundedContinuous) {
        mF << "    SPN_BoundedRE N(false);" << endl;
    } else if (P.RareEvent) {
        mF << "    SPN_RE N("<< P.DoubleIS <<");" << endl;
    } else {
        mF << "    SPN_orig<" << eqt << "> N;" << endl;
    }
    
    // Instantiade LHA
    if( P.lhaType == DET){
        mF << "    LHA_orig<decltype(N.Marking)> A;"<< endl;
    }else{
        mF << "    NLHA<decltype(N.Marking)> A;"<< endl;
    }

    // Instantiate Simulator
    if (P.BoundedContinuous){
        mF << "    SimulatorContinuousBounded<SPN_BoundedRE> sim(N,A,"<<
        P.BoundedRE << ", "<< P.epsilon << ", " << P.continuousStep << ");" << endl;
        mF << "    sim.initVectCo("<< P.horizon <<");" << endl;
    }else if (P.BoundedRE > 0) {
        mF << "    SimulatorBoundedRE<SPN_BoundedRE> sim(N,A,"<< P.BoundedRE <<");" << endl;
        mF << "    sim.initVect("<< (int)P.horizon <<");" << endl;
    } else if (P.RareEvent) {
        mF << "    SimulatorRE<SPN_RE> sim(N,A);" << endl;
        mF << "    sim.initVect();" << endl;
    } else {
        mF << "    Simulator<"<< eqt << ",typeof N> sim(N,A);" << endl;
    }

    
    if( !P.dataraw.empty()) mF << "    sim.logValue(\"" << P.dataraw << "\");" <<endl;
    if( !P.datatrace.empty()){
        mF << "    sim.logTrace(\"" << P.datatrace << "\","<< P.sampleResol << ");" <<endl;
        mF << "    bool singleBatch = true;"<< endl;
    } else mF << "    bool singleBatch = false;"<< endl;
    if( !P.dotfile.empty()) mF << "    sim.dotFile = \"" << P.dotfile << "\";" << endl;
    
    mF << "    sim.SetBatchSize(" << P.Batch << ");" << endl;
    
    mF << "    setSimulator(sim,argc,argv);" << endl;
    
    mF << "    if((verbose>=4) | singleBatch )sim.RunBatch();" << endl;
    mF << "    else while( !cin.eof() ){" << endl;
    mF << "        BatchR batchResult = sim.RunBatch(); //simulate a batch of trajectory" << endl;
    mF << "        batchResult.outputR(cout);// output the result on the standart output" << endl;
    mF << "    }" << endl;
    mF << "    return (EXIT_SUCCESS);" << endl;
    mF << "}" << endl << endl;

    mF.close();
}

bool build() {

    string bcmd = P.gcccmd + " " + P.gccflags;

    if (P.verbose > 0) {
        cout << "Parsing OK.\n" << endl;
        cout << "Start building ... " << endl;
    }

    string cmd = "( ";
    //Compile the SPN
    cmd += bcmd + " -c -I" + P.Path + "../include -o " + P.tmpPath + "/spn.o " + P.tmpPath + "/spn.cpp";
    cmd += " )\\\n";
    //Compile the LHA
    if(!P.lightSimulator)cmd += "&(" + bcmd + " -c -I" + P.Path + "../include -o " + P.tmpPath + "/LHA.o " + P.tmpPath + "/LHA.cpp)\\\n";
    
    //Compile the Main
    cmd += "&(" + bcmd + " -c -I"+P.Path+"../include "+ P.boostpath +" -o "+P.tmpPath+"/main.o "+P.tmpPath+"/main.cpp)";
    
    cmd += " & wait";

    if (P.verbose > 2)cout << cmd << endl;
    if (system(cmd.c_str())) return false;
    

    //Link SPN and LHA with the library
    cmd = bcmd + " -o " + P.tmpPath + "/ClientSim ";
    if(P.modelType == GSPN)cmd += P.tmpPath + "/spn.o ";
    cmd += P.tmpPath + "/main.o "; 
    if(P.lightSimulator){
        cmd += P.Path + "../lib/libClientSimLight.a ";
    } else {
        cmd += P.tmpPath + "/LHA.o ";
        cmd += P.Path + "../lib/libClientSim.a ";
    };
 

    if (P.verbose > 2)cout << cmd << endl;
    if (system(cmd.c_str())) return false;

    if (P.verbose > 0)cout << "Building OK.\n" << endl;

    return true;
}

void generateSamplingLHA(GspnType &spn) {
    //bool allcolor = false;
    //if (P.tracedPlace == "ALLCOLOR")allcolor= true;
    P.sampleResol = P.loopTransientLHA;
    size_t nbsample = static_cast<size_t> (ceil((P.loopLHA / P.sampleResol)));

    P.PathLha = P.tmpPath + "/samplelha.lha";
    ofstream lhastr(P.PathLha.c_str(), ios::out | ios::trunc);

    //lhastr << "NbVariables = "<<1+gReader.spn->tr + P.nbPlace <<";\nNbLocations = 3;\n";
    lhastr << "const double T=" << P.loopLHA << ";\n";
    lhastr << "const double invT=" << P.sampleResol << ";\n";
    lhastr << "const double invT2=" << 1 / P.sampleResol << ";\n";

    lhastr << "VariablesList = {time,time2, DISC counter";
    for (const auto &itt : spn.placeStruct)if (itt.isTraced) {
            lhastr << ", PLVARACC_" << itt.name;
            lhastr << ", DISC PLVAR_" << itt.name << "[" << nbsample << "]";
            //if(allcolor && itt.colorDom != UNCOLORED_DOMAIN){
            //	gReader.iterateDom("", "_", "","","","" ,gReader.spn->colDoms[itt.colorDom], 0, [&] (const string &str,const string&){
            //		lhastr << ", PLVAR_" + itt.name + str;
            //	});

            //}
        }
    lhastr << "} ;\nLocationsList = {l0,";
    //for (size_t i = 0; i < nbsample ; ++i ) lhastr << "l" << i << ", ";
    lhastr << "l2 };\n";

    for (const auto &itt : spn.placeStruct) {
        if (itt.isTraced)for (size_t i = 0; i < nbsample; ++i) {
                lhastr << "MeanToken_" << itt.name << "$GRAPH$" << (double) i * P.sampleResol << "$" << (double) (i + 1) * P.sampleResol << "$= AVG(Last( PLVAR_" << itt.name << "[" << i << "]));\n";
                /*if(allcolor && itt.colorDom != UNCOLORED_DOMAIN){
                    gReader.iterateDom("", "_", "","","","" ,gReader.spn->colDoms[itt.colorDom], 0, [&] (const string &str,const string&){
                        lhastr << "MeanToken_" << itt.name << str << "= AVG(Last( PLVAR_" << itt.name<< str <<"));\n";
                    });
                }*/
            }
    }
    lhastr << P.externalHASL << endl;
    lhastr << "InitialLocations={l0};\nFinalLocations={l2};\n";
    lhastr << "Locations={" << endl;
    //for (size_t i = 0; i < nbsample ; ++i ) {
    lhastr << "(l" << 0 << ", TRUE , (time:1,time2:1";
    for (const auto &itt : spn.placeStruct)
        if (itt.isTraced) {
            lhastr << ", PLVARACC_" << itt.name << ": " << itt.name << "* invT2 ";
            /*if(allcolor && itt.colorDom != UNCOLORED_DOMAIN){
             gReader.iterateDom("", "_", "","","","," ,gReader.spn->colDoms[itt.colorDom], 0, [&] (const string &str,const string &str2){
             lhastr << ", PLVAR_" << itt.name << str << ": " << itt.name << "[" << str2 <<"]* invT ";
             });
             }*/
        }
    lhastr << "));" << endl;
    //}
    lhastr << "(l2, TRUE , (time:1,time2:1));};\n";
    lhastr << "Edges={";
    //for (size_t i = 0; i < nbsample ; ++i ) {
    lhastr << "((l0,l0),ALL,time<= invT ,#);";
    lhastr << "((l0,l0),#,time=invT ,{time=0,counter=counter+1";
    for (const auto &itt : spn.placeStruct)if (itt.isTraced) {
            lhastr << ", PLVARACC_" << itt.name << " = 0.0 ";
            lhastr << ", PLVAR_" << itt.name << "[" << "counter" << "]=PLVARACC_" << itt.name;
        }
    lhastr << "});" << endl;
    lhastr << "((l0,l2),# , time2 >= " << P.loopLHA + P.sampleResol * 0.001 << ",#);";

    //}

    lhastr << "};";
    lhastr.close();

}

void generateLoopLHA(GspnType &spn) {
    //If the automaton need to be generated to mesure simple perfomance indices generate it
    //An automaton is produce with two loop the first make time elapse until transient time
    //elapse and then compute the mean number of token in each place and the throughput
    //of each transition
    bool allcolor = false;
    if (P.tracedPlace.count("ALLCOLOR")>0.0)allcolor = true;


    P.PathLha = P.tmpPath + "/looplha.lha";
    ofstream lhastr(P.PathLha.c_str(), ios::out | ios::trunc);

    if(P.generateLHA ==TimeLoop){
        lhastr << "const double T=" << P.loopLHA << ";\n";
        lhastr << "const double invT=" << 1 / P.loopLHA << ";\n";
    } else {
        lhastr << "const double TDiscr=" << P.loopLHA << ";\n";
        lhastr << "const double invT= 1.0 ;\n";
    }
    lhastr << "const double Ttrans=" << P.loopTransientLHA << ";\n";
    lhastr << "VariablesList = {time,DISC countT";
    for (let itt : spn.transitionStruct)
        if (itt.isTraced)lhastr << ", " << itt.name;

    for (let itt : spn.placeStruct) {
        if (itt.isTraced) {
            lhastr << ", PLVAR_" << itt.name;
            if (allcolor && itt.colorDom != UNCOLORED_DOMAIN) {
                spn.iterateDom("", "_", "", "", "", "", spn.colDoms[itt.colorDom], 0, [&] (const string &str, const string&) {
                    lhastr << ", PLVAR_" + itt.name + str;
                });
            }
        }
    }
    lhastr << "} ;\nLocationsList = {l0, l1,l2};\n";

    auto nbHASL = 0;
    for (let itt : spn.transitionStruct)
        if (itt.isTraced){
            nbHASL++;
            lhastr << "Throughput_" << itt.name << "= AVG(Last(" << itt.name << "));\n";
        }
    for (let itt : spn.placeStruct)
        if (itt.isTraced) {
            nbHASL++;
            lhastr << "MeanToken_" << itt.name << "= AVG(Last( PLVAR_" << itt.name << "));\n";
            if (allcolor && itt.colorDom != UNCOLORED_DOMAIN) {
                spn.iterateDom("", "_", "", "", "", "", spn.colDoms[itt.colorDom], 0, [&] (const string &str, const string&) {
                    lhastr << "MeanToken_" << itt.name << str << "= AVG(Last( PLVAR_" << itt.name << str << "));\n";
                });
            }
        }
    lhastr << P.externalHASL << endl;
    if(P.externalHASL.empty() && nbHASL==0)
        lhastr << "PROB;" << endl;

    const auto stopcond = (P.generateLHA == TimeLoop ? "time<=T," : "countT<=TDiscr -1,");

    lhastr << "InitialLocations={l0};\nFinalLocations={l2};\n";
    lhastr << "Locations={\n(l0, TRUE, (time:1));\n(l1, TRUE, (time:1 ";
    for (let itt : spn.placeStruct)
        if (itt.isTraced) {
            lhastr << ", PLVAR_" << itt.name << ": " << itt.name << "* invT ";
            if (allcolor && itt.colorDom != UNCOLORED_DOMAIN) {
                spn.iterateDom("", "_", "", "", "", ",", spn.colDoms[itt.colorDom], 0, [&] (const string &str, const string & str2) {
                    lhastr << ", PLVAR_" << itt.name << str << ": " << itt.name << "[" << str2 << "]* invT ";
                });
            }
        }

    lhastr << "));\n(l2, TRUE);\n};\n";
    lhastr << "Edges={\n((l0,l0),ALL,time<= Ttrans ,#);\n((l0,l1),#,time=Ttrans ,{time=0});\n";
    size_t nbplntr = 0;
    for (let itt : spn.transitionStruct) {
        if (itt.isTraced) {
            lhastr << "((l1,l1),{" << itt.name << "}," << stopcond;
            if(P.loopLHA>0.0){
                lhastr << "{" << itt.name << " = " << itt.name << " + invT, countT = countT+1 });\n";
            }else{
                lhastr << "{" << itt.name << " = " << itt.name << " + 1, countT = countT+1 });\n";
            }
        } else nbplntr++;
    }
    if (nbplntr > 0) {
        lhastr << "((l1,l1),{";
        nbplntr = 0;
        for (let itt : spn.transitionStruct)
            if (!itt.isTraced) {
                if (nbplntr > 0)lhastr << ",";
                lhastr << itt.name;
                nbplntr++;
            }
        lhastr << "}," << stopcond;
        lhastr << "{countT = countT+1 });" << endl;
    }
    if (P.generateLHA == TimeLoop){
        lhastr << "((l1,l2),#,time=T ,#);\n};";
    }else lhastr << "((l1,l2),ALL,countT=TDiscr ,#);\n};";
    lhastr.close();
}



