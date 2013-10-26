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
 *******************************************************************************
 */

/*
 * This file implement low level interaction between the main program
 * and all its children. In particular it lauches the require copies of
 * simulator and wait for the result.
 */




#ifndef _SERVER_HPP
#define	_SERVER_HPP

#include "parameters.hpp"

/**
 * The function lauchExport execute one instance of the simulator
 * With the right parameters to exporte the state space to files.
 * @param P the parameters to use for the export.
 */
void launchExport(parameters& P);

/**
 * One of the main function of the tool.
 * lauchServer execute several instance of the simulator,
 * then wait for some simulators to retun result.
 * At this point the new result are aggreated to the previous one using
 * the class result.
 * The class result indicate if the simulation should continue, if not
 * this function kill all the instance of the simulator, return all
 * the results to files or to stdout and return.
 * @param is the parameters to use for the export.
 */
void launchServer(parameters& P);

/**
 * This function desactivate the signal handler on sigchld for the
 * time of the execution of a shell script. This function is necessary
 * to avoid a deadlock where the signal wait for a child wich status
 * have been retrieved by system.
 */
int systemsigsafe(const char*cmd);

#endif	/* _SERVER_HPP */
