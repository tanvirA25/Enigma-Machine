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
		static NESEncryptorControl NESC;
		return NESC;
    }

    static void start();

    ~NESEncryptorControl() {};

};