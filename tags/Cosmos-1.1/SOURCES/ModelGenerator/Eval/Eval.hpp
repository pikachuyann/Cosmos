
#ifndef EVAL_HH
#define EVAL_HH

#include "Eval-parser.tab.hh"


#define EVAL_DECL                                            \
  eval::Eval_parser::token_type                         \
  evallex (eval::Eval_parser::semantic_type* evallval,      \
         eval::Eval_parser::location_type* evallloc,      \
         Eval& Evaluate)

EVAL_DECL;
using namespace std;

class Eval {
public:
    Eval();
    virtual ~Eval();

    int IntResult;
    double RealResult;
    void scan_begin();
    void scan_end();
    void scan_expression(const string&);

    bool trace_scanning;


    int parse(std::string&);


    bool trace_parsing;


    void error(const eval::location& l, const std::string& m);
    void error(const std::string& m);

    void view();
};
#endif 
