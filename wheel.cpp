#include "wheel.h"
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

void Wheel::advance() {
    ++curPos;
    curPos = (curPos >= nRec) ? 0 : curPos;
}

void Wheel::reverse() {
    --curPos;
    curPos = (curPos < 0) ? nRec - 1 : curPos;
}

Wheel::~Wheel() {
}
