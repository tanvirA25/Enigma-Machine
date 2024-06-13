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

#include <iostream>
#include <vector>
#include <random>

Wheel::Wheel(short nEnts, unsigned int seed, short cPos)
    : nRec(nEnts), seed(seed), curPos(cPos) {
    loadLToR();
    loadRToL();
    convertToOffset();
}

void Wheel::loadLToR() {
    std::mt19937 gen(seed);
    std::uniform_int_distribution<int> dis(0, nRec - 1);


    lToR.clear(); // Clear any previous content
    for (int i = 0; i < nRec; ++i) {
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


    for (int i = 0; i < nRec; ++i) {
        int j = dis(gen);
        std::swap(lToR[i], lToR[j]);
    }
}

void Wheel::loadRToL() {
    rToL.clear(); // Clear any previous content
    for (int i = 0; i < nRec; ++i) {
        rToL.push_back(i);
    }

    for (int i = 0; i < nRec; ++i) {
        rToL[lToR[i]] = i;
    }
}

void Wheel::convertToOffset() {
    for (int i = 0; i < nRec; ++i) {
        int offset = lToR[i] - i;
        lToR[i] = offset;
        offset = rToL[i] - i;
        rToL[i] = offset;
    }
}

short Wheel::getLtoR(short i) {
    int index = (curPos + i) % nRec;
    int val = lToR[index];
    val += i;
    if (val < 0) val += nRec;
    else if (val >= nRec) val -= nRec;
    return val;
}

short Wheel::getRtoL(short i) {
    int index = (curPos + i) % nRec;
    int val = rToL[index];
    val += i;
    if (val < 0) val += nRec;
    else if (val >= nRec) val -= nRec;
    return val;
}

bool Wheel::atNotch() const {
    return (curPos == notch);
}

void Wheel::resetCur(short cP) {
    curPos = cP;
}


short Wheel::getCurPos() const {
    return curPos;
}


Wheel::~Wheel() {
}

