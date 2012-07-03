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
 * file BatchR.cpp created by Benoit Barbot.                                   *
 *******************************************************************************
 */

#include "BatchR.hpp"
#include <unistd.h>

using namespace std;

/*BatchR::BatchR(int i) {
 IsBernoulli = true;
 I =0;
 Isucc=0;
 Mean=0;
 M2=0;
 TableLength=i;
 //    vector<double> MeanTable(i);
 //    vector<double> M2Table(i);
 }
 
 BatchR::BatchR(){
 BatchR(0);
 }*/


BatchR::BatchR() {
    IsBernoulli = true;
    I =0;
    Isucc=0;
    Mean=0;
    M2=0;
    TableLength=0;
}

BatchR::~BatchR() {
}

void BatchR::outputR() {
    int size;
    size = write(STDOUT_FILENO,reinterpret_cast<char*>(&IsBernoulli),sizeof(bool));
    size = write(STDOUT_FILENO,reinterpret_cast<char*>(&I),sizeof(int));
    size = write(STDOUT_FILENO,reinterpret_cast<char*>(&Isucc),sizeof(int));
    size = write(STDOUT_FILENO,reinterpret_cast<char*>(&Mean),sizeof(double));
    size = write(STDOUT_FILENO,reinterpret_cast<char*>(&M2),sizeof(double));
    
    //write table
    size = write(STDOUT_FILENO,reinterpret_cast<char*>(&TableLength),sizeof(int));
    for(int i =0; i< TableLength; i++){
        size = write(STDOUT_FILENO,reinterpret_cast<char*>(&MeanTable[i]),sizeof(double));
        size = write(STDOUT_FILENO,reinterpret_cast<char*>(&M2Table[i]),sizeof(double));
    }
    fflush(stdout);
}

void BatchR::inputR(FILE* f) {
    double read;
    bool readb;
    int readi;
    int size;
    
    size = fread(reinterpret_cast<char*>( &readb ), sizeof readb ,1, f);
    IsBernoulli=readb;
    size = fread(reinterpret_cast<char*>( &readi ), sizeof readi ,1, f);
    I=readi;
    size = fread(reinterpret_cast<char*>( &readi ), sizeof readi ,1, f);
    Isucc=readi;
    size = fread(reinterpret_cast<char*>( &read ), sizeof read ,1, f);
    Mean=read;
    size = fread(reinterpret_cast<char*>( &read ), sizeof read ,1, f);
    M2=read;
    
    //read table
    size = fread(reinterpret_cast<char*>( &readi ), sizeof readi ,1, f);
    TableLength=readi;
    for(int i =0; i< TableLength; i++){
        size = fread(reinterpret_cast<char*>( &read ), sizeof read ,1, f);
        MeanTable.push_back(read);
        size = fread(reinterpret_cast<char*>( &read ), sizeof read ,1, f);
        M2Table.push_back(read);
    }
    fflush(stdout);
}

void BatchR::print(){
    cerr << "IsBernoulli:\t" << IsBernoulli << endl
    << "I:\t" << I << endl
    << "Isucc:\t" << Isucc << endl
    << "Mean:\t" << Mean << endl
    << "M2:\t" << M2 << endl;
}