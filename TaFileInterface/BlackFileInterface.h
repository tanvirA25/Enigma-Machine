// Name: Tanvir Ahmed
// CS 490
// Assignment 3: Reflector

#pragma once
#include <fstream>
using namespace std;

class BlackFileInterface {

// filestream for reading and writing in the cpp file
// private constructor
private:
    BlackFileInterface() {}
    ifstream infile;
    ofstream outfile;

public:
    static BlackFileInterface& Instance() {
        static BlackFileInterface bfi;
        return bfi;
    }
    // for reading the file
    bool openForRead();

    // getting the charactrers in the file
    unsigned char getNextChar();

    // for opening the file
    bool openForWrite();

    // for writing the file
    bool putNextChar(unsigned char c);

    // checking end of file
    bool eof();

    // closing file
    bool close();


};
