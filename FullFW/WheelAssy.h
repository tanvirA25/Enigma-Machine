#if !defined        (WheelAssy____INCL)
#define              WheelAssy____INCL

#include "Wheel.h"

class WheelAssy
{
    // Constructor is private.
    Wheel* wheel1;
    Wheel* wheel2;
    Wheel* wheel3;
    const short nRecs = 96;
    const int s1 = 111;
    const int s2 = 222;
    const int s3 = 333;
    const short c1 = 11;
    const short c2 = 22;
    const short c3 = 33;    

    WheelAssy() {
        wheel1 = new  Wheel(nRecs, s1, c1);
        wheel2 = new  Wheel(nRecs, s2, c2);
        wheel3 = new  Wheel(nRecs, s3, c3);
    }

public:

    // Meyer's Singleton pattern.
    static WheelAssy& Instance()
    {
        static WheelAssy ref;
        return ref;
    }


    void advance();

    void reset();

    unsigned char lToR(unsigned char c);

    unsigned char rToL(unsigned char c);

    ~WheelAssy();

};

#endif
