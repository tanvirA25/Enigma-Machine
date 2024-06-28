#if !defined        (NESEncryptorFacade____INCL)
#define              NESEncryptorFacade____INCL

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

    // Meyer's Singleton pattern.
    static NESEncryptorFacade& Instance()
    {
        static NESEncryptorFacade nef;
        return nef;
    }

    bool encrypt(unsigned char c) {
        return false;
    }

    bool decrypt(unsigned char c) {
        return false;
    }

    void reset(){}

    ~NESEncryptorFacade() {};

};

#endif
