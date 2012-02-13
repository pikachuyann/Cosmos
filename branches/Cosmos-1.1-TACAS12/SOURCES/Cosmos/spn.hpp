#ifndef _SPN_HPP
#define	_SPN_HPP
#include "spn_orig.hpp"
class SPN: public SPN_ORIG {
public:
	void Load();
	bool IsEnabled(int); // Check if a given transition is enabled
	
	void fire(int); // fire a given transition
    void unfire(int); // unfire a given transition
	
	vector<double> GetDistParameters(int); // compute the the parameters value of a given distribution 
	//------------------------- Rare Event ---------------------------------------
	vector<double> GetDistParametersOrigin(int);
	//-------------------------/Rare Event ---------------------------------------
	
	
    double GetWeight(int); // compute the the weight value of a given transition
    double GetPriority(int); // compute the the priority value of a given transition	
};
#endif	/* _SPN_HPP */
