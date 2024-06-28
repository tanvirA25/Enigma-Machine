#if !defined        (NESEncryptorFacade____INCL)
#define              NESEncryptorFacade____INCL

#include <iostream>
#include "NESEncryptorFacade.h"
#include "RedFileInterface.h"
#include "BlackFileInterface.h"
#include "WheelAssy.h"
#include "Plugboard.h"
#include "Reflector.h"

class NESEncryptorFacade
{

    // Constructor is private.
    //WheelAssy& wheel_assay;
    //Plugboard& plug_board;
    //Reflector& reflec_tor;

    NESEncryptorFacade() {}

public:

    // Meyer's Singleton pattern.
    static NESEncryptorFacade& Instance()
    {
        static NESEncryptorFacade nef;
        return nef;
    }

    bool encrypt(char c);

    bool decrypt(char c);

    ~NESEncryptorFacade() {};

};

#endif
