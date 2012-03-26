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
 * file exportFile.cpp                                                         *
 * Created by Benoit Barbot on 26/03/12.                                       *
 *******************************************************************************
 */


#include <string>
#include "exportFile.hpp"
#include <iostream>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>


using namespace std;

void LauchExport(parameters& P){
    
    ostringstream os;
	if (P.Path == "") os << "./ClientSim 1 " << P.verbose;
    else os <<  P.Path << "ClientSim 1 " << P.verbose;
    os << " " << "-STSP";
    
    if (system(os.str().c_str()) == 0){
        cout << "Export Finish" << endl;
    }else{
        cout << "Export Fail" << endl;
    }
    
    cout<< "Starting Prism"<< endl;
    string cmd =P.prismPath + " -ctmc -importtrans prismMatrix.tra -importstates prismStates.sta -importlabels prismLabel.lbl prismProperty.ctl -v > prismOutput";
    cout << "Prism finish" << endl;
    system(cmd.c_str());
}