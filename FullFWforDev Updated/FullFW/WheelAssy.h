#if !defined        (WheelAssy____INCL)
#define              WheelAssy____INCL

#include "Wheel.h"

#include "Wheel.h"

class WheelAssy
{
    // Constructor is private.
    Wheel* wheel1;
    Wheel* wheel2;
    Wheel* wheel3;
    const int nRecs = 96;
    const short s1 = 111;
    const short s2 = 222;
    const short s3 = 333;
    const int c1 = 11;
    const int c2 = 22;
    const int c3 = 33;
    //const int n1 = 91;
    //const int n2 = 91;
    //const int n3 = 17;
    

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
