#if !defined        (NESEncryptortFacade____INCL)
#define              NESEncryptortFacade____INCL

#include <iostream>
#include "Plugboard.h"
#include "WheelAssy.h"
#include "Reflector.h"


class NESEncryptorFacade
{
     // references
    Plugboard& PB;
    WheelAssy& WHASS;
    Reflector& REF;

    // Constructor is private.
    NESEncryptorFacade() :
        PB(Plugboard::Instance()),
        WHASS(WheelAssy::Instance()),
        REF(Reflector::Instance())
    {};

public:

    // Meyer's Singleton pattern.
    static NESEncryptorFacade& Instance() {
        static NESEncryptorFacade nef;
        return nef;
    }

    bool encrypt(unsigned char& c);

    bool decrypt(unsigned char& c);

    void reset();

    ~NESEncryptorFacade() {};

};



#endif
