#ifndef _TAB_HPP
#define	_TAB_HPP
#include <set>
#include <utility>
#include <string>
#include <vector>
#include <map>
#include <cstring>
#include <hash_map>

using namespace std;
using namespace __gnu_cxx;

struct eqstr{
  bool operator()(const char* s1, const char* s2) const {
    return strcmp(s1,s2)==0;
  }
};

typedef hash_map<const char*, double , hash<const char*>, eqstr> hash_prob;
class TAB {
public:
  hash_prob M;
  TAB();
  void load();
private:
};

#endif
