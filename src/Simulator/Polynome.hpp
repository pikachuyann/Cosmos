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

template <unsigned int N>
struct Monome {
    int d[N];
    double coeff;
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
