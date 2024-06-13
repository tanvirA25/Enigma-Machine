#include "wheel.h"
#include<random>
#include<cstdlib>

using namespace std;

Wheel::Wheel(
    const short       nEnts,
    const unsigned int seed,
    const short        cPos) : nRec(nEnts), seed(seed),curPos(cPos)
    {
    
    srand (seed);
    
    notch = rand() % nRec-1;
        
    loadLToR          ();
    loadRToL          ();
    convertToOffset   ();
 

    }

void Wheel::loadLToR(){
    const int rRange = nRec -1;

    mt19937 gen(seed);
    uniform_int_distribution<> dis(0,rRange);

    for (short i = 0; i < nRec; ++i){
        lToR.push_back(i);
    }
     for (short i = 0; i < nRec; ++i){ 
        
        short j = dis(gen);
        swap(lToR[i], lToR[j]);
    }

}

void Wheel::loadRToL(){
 const int rRange = nRec -1;
    for (short i = 0; i < nRec; ++i){
        rToL.push_back(0);
    }
    for (short i = 0; i < nRec; ++i){ 
        rToL[lToR[i]] = i;
    }
}

void Wheel::convertToOffset(){
    for (short i = 0; i < nRec; ++i){
        short offsett = lToR.at(i) - i;
        lToR[i] = offsett;
        offsett = rToL.at(i) - i;
        rToL[i] = offsett;

    }
}

short Wheel::getLtoR(short i){
    const short index = (curPos + i) % nRec;
    short val = lToR.at(index);
    val+=i;
    if (val < 0) val += nRec;
    else if (val >= nRec) val-= nRec;
    return val;

}

short Wheel::getRtoL(short i){
    const short index = (curPos + i) % nRec;
    short val = rToL.at(index);
    val+=i;
    if (val < 0) val += nRec;
    else if (val >= nRec) val-= nRec;
    return val;

}


Wheel::~Wheel(){
    


}