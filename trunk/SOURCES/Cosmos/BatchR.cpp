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
#include <math.h>
#include <float.h>

using namespace std;


/**
 *Initialize the batch with zeros
 * @param i is the number of formula evaluated by the automaton.
 */
 BatchR::BatchR(const size_t i) :
	I(0) ,
	Isucc(0),
	TableLength(i),
	IsBernoulli(vector<bool>(i,true)),
	Mean(vector<double>(i,0.0)),
	M2(vector<double>(i,0.0)) {}

/**
 * Add a simulation to the batch
 * If the simulation is a success then The Mean and second Moment are updated
 * @param Result the result of one trajectory in the simulator.
 */
 void BatchR::addSim(SimOutput *Result){
    I++;
    if (Result->first) {
        Isucc++;
        
        for(size_t i =0; i< TableLength; i++){
            
            if (Result->second[i] * (1 - Result->second[i]) != 0){
                IsBernoulli[i] = false;
            }
            
            Mean[i] += Result->second[i];
			
            M2[i] += pow(Result->second[i], 2);
        }
    }
}

/**
 * Take the union of two batch of result.
 * @param batch is a batch of result wich is added to the current batch.
 */
void BatchR::unionR(BatchR *batch){
    
    I += batch->I;
    Isucc += batch->Isucc;
    
    for(unsigned int i =0; i< TableLength; i++){
        IsBernoulli[i] = IsBernoulli[i] && batch->IsBernoulli[i];
        
        Mean[i] += batch->Mean[i];
        
        M2[i] += batch->M2[i];
    }
}

/**
 * This function write a batch on the standart output it is suposed to
 * be read by the function BatchR::inputR
 */
 void BatchR::outputR() {
    write(STDOUT_FILENO,reinterpret_cast<char*>(&I),sizeof(I));
	write(STDOUT_FILENO,reinterpret_cast<char*>(&Isucc),sizeof(Isucc));

    for(unsigned int i =0; i< TableLength; i++){
        bool tmpbool = IsBernoulli[i];
        write(STDOUT_FILENO,reinterpret_cast<char*>(&tmpbool),sizeof(bool));
        write(STDOUT_FILENO,reinterpret_cast<char*>(&Mean[i]),sizeof(Mean[0]));
        write(STDOUT_FILENO,reinterpret_cast<char*>(&M2[i]),sizeof(Mean[0]));
    }
}

/**
 * Read a batch from a file.
 * The batch should be print with BatchR::outputR
 * @param f an opened for reading file.
 */
bool BatchR::inputR(FILE* f) {
    bool readb;
	size_t readbyte;
    bool ok = true;
	
	readbyte = fread(reinterpret_cast<char*>( &I ), sizeof I ,1, f);
	ok &= (readbyte == 1);
	
    readbyte = fread(reinterpret_cast<char*>( &Isucc), sizeof Isucc ,1, f);
    ok &= (readbyte == 1);

    for(unsigned int i =0; i< TableLength; i++){
        readbyte = fread(reinterpret_cast<char*>( &readb ), sizeof readb ,1, f);
        IsBernoulli[i]=readb;
		ok &= (readbyte == 1);
        readbyte = fread(reinterpret_cast<char*>( &(Mean[i]) ), sizeof Mean[i] ,1, f);
        ok &= (readbyte == 1);
        readbyte = fread(reinterpret_cast<char*>( &(M2[i]) ), sizeof M2[i] ,1, f);
        ok &= (readbyte == 1);
    }
	return ok;
}

void BatchR::print(){
    cerr << "I:\t" << I << endl << "Isucc:\t" << Isucc << endl;
    for(size_t i =0; i< TableLength; i++){
        cerr << "Mean:\t" << Mean[i]/Isucc << endl << "M2:\t" << M2[i]/Isucc << endl << "IsBernoulli:\t" << IsBernoulli[i] << endl;
    }
}
