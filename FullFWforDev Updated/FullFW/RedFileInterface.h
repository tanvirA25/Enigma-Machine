#pragma once

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class RedFileInterface {

    fstream MyInFile;

    // Constructor is private.
    RedFileInterface() {}

public:
    // Meyer's Singleton pattern.
    static RedFileInterface & Instance() {
        static RedFileInterface fB;
        return fB;
    }

    // Implement the following operations for both the red and black files.
    // All return true if OK, otherwise false.
    bool openForRead();
    unsigned char getNextChar();
    bool openForWrite();
    bool putNextChar(unsigned char c);
    bool eof();
    bool close();

    ~RedFileInterface() {}
};