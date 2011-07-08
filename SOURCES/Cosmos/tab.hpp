#ifndef _TAB_HPP
#define	_TAB_HPP
#include <set>
#include <utility>
#include <string>
#include <vector>
#include <map>
#include <cstring>
#include <unordered_map>

using namespace std;
using namespace __gnu_cxx;

struct eqvect{
  bool operator()(const vector<int>* t1,const vector<int>* t2) const {
    for(int it=0; it < t1->size() ; it++)
      if((*t1)[it] != (*t2)[it]) return false;
    return true;
  }
};

struct hashvect{
  int operator()(const vector<int>* t1) const {
    int h = 0;
    for(int it=0; it < t1->size() ; it++)
      h = h * 524287 + (*t1)[it];
    return h;
  }
};

typedef unordered_map<const vector<int>*, double , hashvect , eqvect > hash_prob;
class TAB {
public:
  hash_prob M;
  TAB();
  void load();
  double find(const vector<int>* vect){
    hash_prob::iterator it = M.find (vect);
    if (it != M.end ())
      return(it->second); // found
    else
      return(0.0);
  }

private:
};

#endif
