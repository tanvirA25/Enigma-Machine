#pragma once

class NESEncryptorControl
{

    NESEncryptorControl() {}
    //NESEncryptorControl(const NESEncryptorControl&) = delete;
    //NESEncryptorControl& operator=(const NESEncryptorControl&) = delete;

public:

    // Meyer's Singleton pattern.
    static NESEncryptorControl& Instance()
    {
        static NESEncryptorControl nef;
        return nef;
    }

    static void start();

    ~NESEncryptorControl() {};

};