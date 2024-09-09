#pragma once

#include <iostream>
#include <fstream>

using namespace std;

class BlackFileInterface {

    fstream MyInFile;

    // Constructor is private.
    BlackFileInterface() {}

public:
    // Meyer's Singleton pattern.
    static BlackFileInterface& Instance() {
        static BlackFileInterface fB;
        return fB;
    }

    bool openForRead();
    unsigned char getNextChar();
    bool openForWrite();
    bool putNextChar(unsigned char c);
    bool eof();
    bool close();

    ~BlackFileInterface() {}
};