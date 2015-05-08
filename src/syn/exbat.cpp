#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
using namespace std;

double currentReward = 0.0;

struct TimeReward
{
    double time;
    double reward;
};

struct RetValTR
{
    TimeReward * pt;
    unsigned int size;
};

TimeReward tr53[] = { {1.0, 2.0}, {12.3,14.5},{22.3,24.5},{32.3,34.5} };
TimeReward tr54[] = { {1.0, 2.0}, {2.3,4.5} };

RetValTR RetStruct(int id)
{
    RetValTR ret = {NULL,0};

    switch(id) {
        case 53:
            ret.pt = & tr53[0];
            ret.size = sizeof(tr53)/(sizeof(double)*2);
            break;
        case 54:
            //ret = & tr54[0];
            break;
            
    }
    return ret;
}

double TransitionTime(int id)
{
    double timeVal = 0.0;
    RetValTR rt = RetStruct(id);
    
    srand (time(NULL));
    int idx = rand() % rt.size;
    
    timeVal = rt.pt[idx].time;
    currentReward = rt.pt[idx].reward;
    return timeVal;
}

int main()
{
   double time;
   cout << "Hello World" << endl; 
   
   time = TransitionTime(53);
   cout <<time<<" "<<currentReward<<endl;
   return 0;
}


