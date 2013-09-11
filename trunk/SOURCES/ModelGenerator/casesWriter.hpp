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
 * file casesWriter.hpp                                                        *
 * Created by Benoit Barbot on 11/09/13.                                       *
 *******************************************************************************
 */

#ifndef Cosmos_casesWriter_h
#define Cosmos_casesWriter_h

#include <string>
#include <vector>
#include <ostream>
#include <map>
#include <stdio.h>
#include <string.h>

struct cmp_str
{
  bool operator()(char const *a, char const *b){
    return strcmp(a, b) < 0;
  }
};

class casesHandler {
public:
  casesHandler(std::string svar);
  void addCase(int c,const std::string st);
  void writeCases(std::ostream &s);
private:
  const std::string scase;
  std::map<const char*,int,cmp_str> cases;
  std::map<int,std::string> mapping;
};




#endif
