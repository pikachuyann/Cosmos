#ifndef _LHA_HPP
#define	_LHA_HPP
#include "LHA_orig.hpp"
class LHA: public LHA_ORIG {
public:
	void Load();
	void DoEdgeUpdates(int, vector<int>&);
	void UpdateFormulaVal();
    void UpdateLinForm(vector<int>&);
    void UpdateLhaFunc(double&, double&);
	
    double GetFlow(int, int, vector<int>&);
    bool CheckLocation(int, vector<int>&);
    bool CheckEdgeContraints(int, double, vector<int>&);
		
};
#endif	/* _LHA_HPP */
