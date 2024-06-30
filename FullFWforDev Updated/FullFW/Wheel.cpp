#include "wheel.h"
#include <cstdlib>
#include <stdio.h>

using namespace std;

// Wheel constructor initializer for number of entries, seed, and current position
Wheel::Wheel(const short nEnts, const unsigned int seed, const short cPos)
    : nRec(nEnts), curPos(cPos) {
    srand(seed);

    notch = rand() % nRec;

    loadLToR();
    loadRToL();
    convertToOffset();
}

Wheel::Wheel(const short nEnts, const unsigned int seed, const short cPos, const short nPos)
    : nRec(nEnts), curPos(cPos) {
    srand(seed);

    rand() % nRec;

    loadLToR();
    loadRToL();
    convertToOffset();
}

// Initializes the ltoR vector with random values from 0 to 9
void Wheel::loadLToR() {
    for (short i = 0; i < nRec; ++i) {
        lToR.push_back(i);
    }
    for (short i = 0; i < nRec; ++i) {
        short j = rand() % nRec;
        swap(lToR[i], lToR[j]);
    }
}

// Initializes the rtoL vector with random values from 0 to 9
void Wheel::loadRToL() {
    for (short i = 0; i < nRec; ++i) {
        rToL.push_back(0);
    }
    for (short i = 0; i < nRec; ++i) {
        rToL[lToR[i]] = i;
    }
}


// Gets absolute values in ltoR and rToL to offsett realtive to their indices
void Wheel::convertToOffset() {
    for (short i = 0; i < nRec; ++i) {
        short offsett = lToR.at(i) - i;
        lToR[i] = offsett;
        offsett = rToL.at(i) - i;
        rToL[i] = offsett;
    }
}


// Computes the transformed value from ltoR using the current position and index
short Wheel::getLtoR(short i) {
    printf("getLtoR\n");
    const short index = (curPos + i) % nRec;
    short val = lToR.at(index);
    printf("i: %i(%c)   index: %i(%c)   val: %i(%c)\n", i, i+32, index, index+32, val, val+32);
    val += i;
    if (val < 0) { val += nRec; }
    else if (val >= nRec) { val -= nRec; }
    printf("val: %c\n", val+32);
    return val;
}


// Computes the transformed value from rtoL using the current position and index
short Wheel::getRtoL(short i) {
    printf("getRtoL\n");
    const short index = (curPos + i) % nRec;
    short val = rToL.at(index);
    printf("i: %i(%c)   index: %i(%c)   val: %i(%c)\n", i, i+32, index, index+32, val, val+32);
    val += i;
    if (val < 0) { val += nRec; }
    else if (val >= nRec) { val -= nRec; }
    printf("val: %c\n", val+32);
    return val;
}


// Clear the vector
Wheel::~Wheel() {
    lToR.clear();
    rToL.clear();
}