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
 * file marking.cpp created by Benoit Barbot on 28/01/13.                      *
 *******************************************************************************
 */

#ifndef Cosmos_marking_h
#define Cosmos_marking_h

#define let const auto&

#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

class abstractMarkingImpl;

class abstractMarking {
public:
	/**
	 * Pointer to to the actual marking inmplementation
	 * which is generated.
	 */
	abstractMarkingImpl* P;
	
	abstractMarking();
	abstractMarking(const std::vector<int>& m);
	abstractMarking(const abstractMarking& m);
	abstractMarking& operator = (const abstractMarking& m);
	~abstractMarking();
	
	//! Swap marking in constant time
	void swap(abstractMarking& m);
	void printHeader(std::ostream &)const;
	void print(std::ostream &, double eTime)const;
    void printSedCmd(std::ostream &)const;
	void resetToInitMarking();
	int getNbOfTokens(int)const;
	std::vector<int> getVector()const;
	void setVector(const std::vector<int>&);
	
    void Symmetrize();
    
    
    
    template <typename T, typename C>
    std::vector<size_t> getPerm(const std::vector<T> v, C c)const{
        std::vector<size_t> index( static_cast<int>(c), 0);
        for (size_t i = 0 ; i != index.size() ; i++)index[i] = i;
        sort(index.begin(), index.end(),
             [&](const int& a, const int& b) {
                 return greaterIndex(v, c, a, b);
             });
        return index;
    }
    
    
    template <typename T, typename C>
    void applyPerm(const std::vector<T *> v, C c,const std::vector<size_t> id){
        for( let d : v)d->apply_perm(c,id);
    }
    

/*
    template <typename T, typename C>
    std::vector<size_t> getPerm(const std::vector<T> v, C c) const;
    template <typename T, typename C>
    void applyPerm(const std::vector<T *> v, C c,const std::vector<size_t>);*/
};

struct markingEqState{
	bool operator()(const abstractMarking &t1,const abstractMarking &t2) const;
};

struct markingHashState{
	int operator()(const abstractMarking &t1) const;
};

class abstractBindingImpl;

class abstractBinding {
public:
	abstractBindingImpl* P;
	abstractBinding();
	~abstractBinding();
	abstractBinding(const abstractBinding& b);
	abstractBinding& operator = (const abstractBinding& m);
	
	//! Nexte binding in the bindin list of the transition.
	bool next();
	//! Print in human readable format.
	void print()const;
	//! Transition to which the binding belong.
	int transition()const;
	//! Total number of binding in binding list.
	int idTotal()const;
	//! Identifier for this binding
	int id()const;
	int idcount;
};

inline bool contains(int i, int j){ return i>=j;}

template <typename T>
struct DomainGen {
    std::map<T, unsigned int > tokens;
    
    public:
    
    DomainGen(size_t v =0) { }
    size_t copyVector(std::vector<int> &v ,size_t s)const{
        return 0;
    }
    size_t setVector(const std::vector<int> &v ,size_t s){
        return 0;
    }
    DomainGen& operator = (const DomainGen& x){
        tokens=x.tokens;
        return *this;
    }
    bool operator == (const DomainGen& x){
        return tokens==x.tokens;
    }

    bool operator < (const T& x)const{
        if(tokens.empty())return true;
        if(tokens.size()> 1) return false;
        
        auto xsing = x;
        xsing.mult = 1;
        auto tokDom = tokens.find(xsing);
        if(tokDom != tokens.end()) return tokDom->second < x.mult;
        return false;
    }
    
    bool operator >= (const T& x)const{
        auto xsing = x;
        xsing.mult = 1;
        auto tokDom = tokens.find(xsing);
        if(tokDom != tokens.end()) return tokDom->second >= x.mult;
        return false;
    }
    
    bool operator < (const DomainGen& x)const{
        bool strictEq = false;
        for(const auto &tok : tokens ){
            auto tokDom2 = x.tokens.find(tok.first);
            if(tokDom2 != x.tokens.end()){
                if(tokDom2->second < tok.second) return false;
                if(tokDom2->second > tok.second) strictEq = true;
            } else {
                return false;
            }
        }
        return strictEq;
    }
    
    unsigned int card()const{
        unsigned int acc=0;
        for( const auto &tok: tokens)
            acc += tok.second;
        return acc;
    }
    
    DomainGen& operator += (const DomainGen &x) {
        for (const auto &tok : x.tokens) {
            auto tokDom1 = tokens.find(tok.first);
            if (tokDom1 != tokens.end()) { tokDom1->second += tok.second; }
            else { tokens.insert(tok); }
        }
    }
    DomainGen& operator += (const T& x) {
       auto xsing = x;
       xsing.mult = 1;
       auto tokDom1 = tokens.find(xsing);
       if (tokDom1 != tokens.end()) { tokDom1->second += x.mult; }
       else { tokens.insert(std::pair<T,unsigned int>(x,x.mult)); } 
       return *this;
    }
    
    DomainGen& operator + (const T& x) {
        DomainGen& d(*this);
        d+=x;
        return d;
    }
    
    DomainGen& operator -= (const T& x) {
       auto xsing = x;
       xsing.mult = 1;
       auto tokDom1 = tokens.find(xsing);
       if (tokDom1 != tokens.end()) { tokDom1->second -= x.mult; } // Il faudrait peut-être vérifier qu'on arrive pas à un nombre de zéro (et enlever le token dans ce cas)
       else { tokens.insert(std::pair<T,unsigned int>(x,x.mult)); } 
       return *this;
    }
    
    DomainGen& operator -= (const DomainGen &x) {
        for (const auto &tok : x.tokens) {
            auto tokDom1 = tokens.find(tok.first);
            if (tokDom1 != tokens.end()) { tokDom1->second -= tok.second; } // Vérifier qu'on arrive pas déjà à zéro
            else { tok.second *= -1; tokens.insert(tok); }
        }
        return *this;
    }
    
    DomainGen& operator - (const DomainGen &x) {
        DomainGen& d(*this);
        d-=x;
        return d;
    }
    
    DomainGen& operator - (const T& x) {
        DomainGen& d(*this);
        d-=x;
        return d;
    }
    
    DomainGen& operator * (int v) {
        for (const auto tok : tokens) {
            tok.second *= v;
        }
        return *this;
    }
    
    
    /*
    bool operator > (const patient_Domain& x){
        return  equal((int*)mult, ((int*)mult) + sizeof(mult)/sizeof(int), (int*)x.mult,std::greater<int>());
    }
*/
    
    

    virtual void apply_perm(T,const std::vector<size_t> &){
        std::cerr << "non implémenté";
        exit(1);
    }
    virtual int compare(T,int cci,int ccj)const{
        std::cerr << "non implémenté";
        exit(1);
        return 0;
    }

    
};

template <typename T>
std::ostream& operator << (std::ostream& out, const DomainGen<T>& x) {
    out << "(";
    for (const auto& t:x.tokens) {
        out << t.second << "*";
        t.first.print(out);
        out << ",";
    }
    out << ")";
    return out;
}

#endif
