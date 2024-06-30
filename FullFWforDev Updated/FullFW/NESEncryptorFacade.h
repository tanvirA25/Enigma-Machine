#if !defined        (NESEncryptortFacade____INCL)
#define              NESEncryptortFacade____INCL

#include                     <iostream>
#include "Plugboard.h"
#include "WheelAssy.h"
#include "Reflector.h"


class NESEncryptortFacade
{


    Plugboard& PB;
    WheelAssy& WHASS;
    Reflector& REF;
    //
    // Constructor is
    // private.
    //
    NESEncryptortFacade() :

        PB(Plugboard::Instance()),
        WHASS(WheelAssy::Instance()),
        REF(Reflector::Instance())
    {};

public:

    //
    // Meyer's Singleton
    // pattern.
    //
    static NESEncryptortFacade& Instance()
    {
        static NESEncryptortFacade nef;
        return                     nef;
    }

    bool encrypt(unsigned char c) {
        return false;
    }

    bool decrypt(unsigned char c) {
        return false;
    }

    void reset(){}

    ~NESEncryptortFacade() {};

};



#endif
