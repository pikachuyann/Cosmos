#include "lex.eval.c"

#include "Eval-parser.tab.hh"
#include "Eval.hpp"

#include "string.h"

#include <string>
#include <sstream>
#include <fstream>
#include <set>




using namespace std;

Eval::Eval() {
    trace_scanning = false;
    trace_parsing = false;

}

Eval::~Eval() {
}

int Eval::parse(string& expr) {


    scan_expression(expr);

    eval::Eval_parser parser(*this);

    parser.set_debug_level(trace_parsing);

    int res = parser.parse();
    scan_end();
    return res;
}

void
Eval::error(const eval::location& l, const std::string& m) {
    std::cerr << l << ": " << m << std::endl;
}

void
Eval::error(const std::string& m) {
    std::cerr << m << std::endl;
}

