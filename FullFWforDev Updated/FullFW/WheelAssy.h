#if !defined        (WheelAssy____INCL)
#define              WheelAssy____INCL
#include "Wheel.h"

class WheelAssy
{

    //
    // Constructor is
    // private.
    //
    WheelAssy();

private:
    Wheel *wheel1;
    Wheel *wheel2;
    Wheel *wheel3;



public:

    //
    // Meyer's Singleton
    // pattern.
    //
    static WheelAssy& Instance()
    {
        static WheelAssy ref;
        return           ref;
    }

    void advance() {}

    void reset() {}

    unsigned char 
       lToR(unsigned char c) { return c; }

    unsigned char
        rToL(unsigned char c) { return c; }

    ~WheelAssy() {};

};



#endif
