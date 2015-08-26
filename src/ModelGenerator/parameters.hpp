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
 * file parameters.hpp                                                         *
 * Created by Benoit Barbot on 08/02/12.                                       *
 *******************************************************************************
 */

#ifndef Cosmos_parameters_h
#define Cosmos_parameters_h

#include <string>
#include <set>
#include <vector>
#include <map>
#include <chrono>

#include "HaslFormula.hpp"

#define let const auto&

enum LHAGenType {
    NoGen,
    TimeLoop,
    ActionLoop,
    SamplingLoop,
};

enum Poption {
    CO_level,
    CO_width,
    CO_batch,
    CO_max_run,
    CO_seed,
    CO_local_test,
    CO_sampling,
    CO_loop,
    CO_transient,
    CO_formula,
    CO_chernoff,
    CO_relative,
    CO_const,
    CO_rareevent,
    CO_boundedcountiniouceRE,
    CO_boundedRE,
    CO_step_continuous,
    CO_epsilon,
    CO_set_Horizon,
    CO_state_space,
    CO_prism,
    CO_normalize_IS,
    CO_grml_input,
    CO_alligator_mode,
    CO_unfold,
    CO_HASL_formula,
    CO_njob,
    CO_gppcmd,
    CO_gppflags,
    CO_light_simulator,
    CO_verbose,
    CO_interactive,
    CO_update_time,
    CO_output_data,
    CO_output_raw,
    CO_output_trace,
    CO_output_graph,
    CO_output_dot,
    CO_gnuplot_driver,
    CO_trace_pt,
    CO_help,
    CO_count_transition,
    CO_debug_string,
    CO_tmp_path,
    CO_tmp_status,
    CO_bin_path,
    CO_prism_path,
    CO_magic_values,
    CO_version,
    CO_reuse,
};

enum TmpStat:int {
    TS_GEN       = 0x01,
    TS_BUILD     = 0x02,
    TS_RUN       = 0x04,
    TS_DESTROY   = 0x08
};

struct parameters {
    std::string commandLine;
    int verbose;
    bool interactive;
    std::chrono::milliseconds updatetime;
    unsigned int seed;
    int Njob;

    double epsilon;
    int continuousStep;
    double Level;
    double Width;
    unsigned long int Batch;
    unsigned long int MaxRuns;
    bool sequential;
    bool relative;

    std::string comp_uuid;
    std::string tmpPath;
    TmpStat tmpStatus;      // 0 create and destroy tmp (default),
                            // 1 do not build but destroy,
                            // 2 do not destroy,
                            // 3 do not build nor destoy
                            // 4 do not generate but build and do not destroy
    bool reuse;

    std::string Path;
    std::string PathGspn;
    std::string PathLha;
    std::map<std::string, std::string> constants;

    LHAGenType generateLHA;
    double loopLHA;
    double loopTransientLHA;
    std::string CSLformula;
    std::string externalHASL;
    bool localTesting;
    bool RareEvent;
    bool DoubleIS;
    int BoundedRE;
    double horizon;
    bool BoundedContinuous;
    bool CountTrans;
    bool StringInSpnLHA;

    bool GMLinput;
    int computeStateSpace;

    bool alligatorMode;
    std::string unfold;
    bool isTTY;
    int terminalWidth;

    std::string gcccmd;
    std::string gccflags;
    bool lightSimulator;

    parameters();
    void View();
    void usage();
    void parseCommandLine(int argc, char** argv);
    Poption parsersingleOpt(int i) const;
    //void parseCommandLine2(int argc, char** argv);
    std::string prismPath;
    std::string dataoutput;
    std::string dataraw;
    std::string datatrace;
    double sampleResol;
    std::string dataPDFCDF;
    std::string gnuplotDriver;
    std::map<std::string,int> tracedPlace;
    std::string dotfile;
    std::string magic_values;
    
    std::vector<HaslFormulasTop*> HaslFormulas;
    std::vector<std::string> HaslFormulasname;
    size_t nbAlgebraic;
    size_t nbQualitatif;
    size_t nbPlace;
};

extern parameters P;

#endif
