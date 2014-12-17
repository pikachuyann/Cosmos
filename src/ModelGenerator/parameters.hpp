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
 * file parameters.hpp                                                         *
 * Created by Benoit Barbot on 08/02/12.                                       *
 *******************************************************************************
 */

#ifndef Cosmos_parameters_h
#define Cosmos_parameters_h

#include <string>
#include <vector>
#include <map>
#include <chrono>

#include "HaslFormula.hpp"

using namespace std;

struct parameters {
    int verbose;
    bool interactive;
    std::chrono::milliseconds updatetime;
    unsigned int seed;
    int Njob;

    double epsilon;
    int continuousStep;
    double Level;
    double Width;
    unsigned long int Batch;
    unsigned long int MaxRuns;
    bool sequential;
    bool relative;

    string comp_uuid;
    string tmpPath;
    unsigned int tmpStatus; // 0 create and destroy tmp,
    //1 do not build but destroy,2 do not destroy, 3 do not build nor destoy
    string Path;
    string PathGspn;
    string PathLha;
    map<string, string> constants;

    int generateLHA;
    double loopLHA;
    double loopTransientLHA;
    string CSLformula;
    string externalHASL;
    bool localTesting;
    bool RareEvent;
    bool DoubleIS;
    int BoundedRE;
    double horizon;
    bool BoundedContinuous;
    bool CountTrans;
    bool StringInSpnLHA;

    bool GMLinput;
    int computeStateSpace;

    bool alligatorMode;
    string unfold;

    string gcccmd;
    string gccflags;
    bool lightSimulator;

    parameters();
    void View();
    void usage();
    void parseCommandLine(int argc, char** argv);
    //void parseCommandLine2(int argc, char** argv);
    string prismPath;
    string dataoutput;
    string dataraw;
    string datatrace;
    double sampleResol;
    string dataPDFCDF;
    string gnuplotDriver;
    string tracedPlace;
    string dotfile;
    string magic_values;
    
    vector<HaslFormulasTop*> HaslFormulas;
    vector<string> HaslFormulasname;
    size_t nbAlgebraic;
    size_t nbPlace;
};

extern parameters P;

#endif
