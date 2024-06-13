#pragma once

#include <vector>

class Wheel {
private:
    std::vector<short> lToR;
    std::vector<short> rToL;
    const short nRec;
    short notch;
    short curPos;
    unsigned int seed; // Add seed as a member variable

    void loadLToR();
    void loadRToL();
    void convertToOffset();

public:
    Wheel(short nEnts, unsigned int seed, short cPos);
    ~Wheel();

    bool atNotch() const;
    void resetCur(short cP);
    short getLtoR(short i);
    short getRtoL(short i);
    short getCurPos() const;
    void advance();
    void reverse();
};
