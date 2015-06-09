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
 * file Gspn-model.hpp                                                         *
 * Created by Benoit Barbot on 09/06/15.                                       *
 *******************************************************************************
 */

#include <fstream>

#include "Gspn-model.hpp"

using namespace std;

void searchreplace(const string &in,const string &motif,const string &rep,string &out){
    out = in;
    size_t pos = out.find(motif);
    while (pos != string::npos) {
        out.replace(pos, motif.size(), rep);
        pos = out.find(motif,pos);
    }
}

std::ostream& operator<<(std::ostream& os, const ProbabiliteDistribution& obj){
    os << obj.name << "(";
    for( const auto &e : obj.Param){
        os << e << ",";
    }
    os << ")";

    return os;
}

std::ostream& operator<<(std::ostream& os, const transition& obj){
    os << "transition " << obj.label << "(" << obj.id << "){" << endl;
    os << "\tdistribution:" << obj.dist << endl;
    os << "\tpriority:" << obj.priority << endl;
    os << "\tweight:" << obj.weight << endl << "}" << endl;
    return os;
}

std::ostream& operator<<(std::ostream& os, const place& obj){
    os << "place " << obj.name << "(" << obj.id << "){" << endl;
    os << "\tmarking:" << obj.Marking << endl;
    return os;
}
