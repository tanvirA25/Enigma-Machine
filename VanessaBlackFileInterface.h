#pragma once

#include <iostream>
#include <string>
#include <fstream>

class BlackFileInterface {

    fstream MyInFile;

    // Constructor is private.
    BlackFileInterface();

public:
    // Meyer's Singleton pattern.
    static BlackFileInterface& Instance() {
        static BlackFileInterface fB;
        return fB;
    }

    // Implement the following operations for both the Black and black files.
    // All return true if OK, otherwise false.
    bool openForRead();
    unsigned char getNextChar();
    bool openForWrite();
    bool putNextChar(unsigned char c);
    bool eof();
    bool close();

    ~BlackFileInterface() {}
};