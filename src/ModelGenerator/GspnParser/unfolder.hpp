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
 * file unfolder.hpp created by Benoit Barbot on 10/01/14.                     *
 *******************************************************************************
 */

#ifndef __Cosmos__unfolder__
#define __Cosmos__unfolder__

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>


#include "Gspn-Reader.hpp"


class unfolder: public Gspn_Reader {
public:
	unfolder(Gspn_Reader& g):Gspn_Reader(g){};
	
	void export_grml(ofstream &fout);
private:
	//void export_init_grml(ofstream &fout);
	
	map<string,size_t> uid;
	void export_place_grml(ofstream &fout,const place &p);
	void export_transition_grml(ofstream &fout,const transition&t);
	void export_arc_grml(ofstream &fout,size_t tr,size_t pl);
	//size_t next_uid;
	size_t get_uid(const string&);
	
	
};
#endif /* defined(__Cosmos__unfolder__) */
