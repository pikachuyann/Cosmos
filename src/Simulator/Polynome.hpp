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
 * file Polynome.hpp created by Created by Benoît Barbot on 07/01/2016         *
 *******************************************************************************
 */

#ifndef Polynome_h
#define Polynome_h

#include <iostream>
#include <fstream>
#include <array>

template <unsigned int N>
struct Monome {
    array<int, N> d;
    double coeff;
    Monome(){
        coeff=0.0;
    }
    ~Monome(){
    }
};

template <unsigned int N>
using Poly=vector<const Monome<N>>;

template <unsigned int N>
double eval(const Poly<N> p, vector<double> const& param){
    double rslt = 0.0;
    for(unsigned int i=0; p[i].coeff != 0.0 ; i++){
        double mv = p[i].coeff;
        for(unsigned int j=0; j<N;j++)
            mv *= pow( param[j+1] , p[i].d[j]);
        rslt += mv;
    }
    return rslt;
}

template <unsigned int N>
std::vector<Poly<N>> parse(const std::string file){
    vector<Poly<N>> polyT;
    std::ifstream polyf(file);
    if(polyf.is_open()){
    std::cerr << "start reading:" << file << endl;
    while( polyf.good()){
        string line;
        std::getline(polyf, line);
        size_t pos = line.find_first_of(',', 0);
        if(pos== string::npos)continue;
        if(std::stoi(line.substr(0,pos)) != N ) cerr << "fail to parse file" << endl;
        Poly<N> p;
        while (pos < line.length()-1) {
            Monome<N> m;
            for(size_t i=0; i<N;i++){
                auto pos2 = line.find_first_of(',', pos+1);
                m.d[i] = stoi(line.substr(pos+1,pos2-pos-1));
                pos = pos2;
            }
            auto pos2 = line.find_first_of(',', pos+1);
            if(pos2 == string::npos)pos2 = line.length();
            m.coeff = stod(line.substr(pos+1,pos2-pos-1));
            pos = pos2;
            p.push_back(m);
        }
        p.push_back(Monome<N>());
        polyT.push_back(p);
    }
    }
    cerr << "Finish parsing found "<< polyT.size() <<" polynomes" << endl;
    return polyT;
}


template <unsigned int N>
double eval(const Poly<N> p, vector<double> const& param, double t){
    //cerr << "poly " << param[0] << ": ("<< t << ")" ;
    double rslt = 0.0;
    for(unsigned int i=0; p[i].coeff != 0.0 ; i++){
        double mv = p[i].coeff;
        for(unsigned int j=0; j<N-1;j++)
            mv *= pow( param[j+1] , p[i].d[j]);
        mv *= pow(t,p[i].d[N-1]);
        //cerr << " mon:" << mv;
        rslt += mv;
    }
    //cerr << "res: " << rslt << endl;
    return rslt;
}

#endif /* Polynome_h */
