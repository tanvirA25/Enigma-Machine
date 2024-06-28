// Name: Tanvir Ahmed
// CS 490
// Assignment 3: Reflector

#include "BlackFileInterface.h"
#include <iostream>

bool BlackFileInterface::openForRead() {
    //using filstream open the file  
    // returns true if its successfull
    infile.open("MyOutFile.dat");
    if (infile.is_open()) {
        return true;
    }
    return false;
}

unsigned char BlackFileInterface::getNextChar() {
    char c;
    // gets character from the file on by one
    if (infile.get(c)) {
        return c;
    }
    return 0;
}

bool BlackFileInterface::openForWrite() {
    // opens output file 
    // and returns true if its successfull
    outfile.open("MyOutFile.dat");
    if (outfile.is_open()) {
        return true;
    }
    return false;
}

bool BlackFileInterface::putNextChar(unsigned char c) {
    //check if the outfile is open and put the character
    if (outfile.is_open() ) {
        outfile << c;
        return true;
    }
    return false;
}

bool BlackFileInterface::eof() {
    // check for end of file
    return infile.eof();
}

bool BlackFileInterface::close() {
    // checks if file is open then close it
    if (infile.is_open()) {
        infile.close();
        return true;
    }
    if (outfile.is_open()) {
        outfile.close();
        return true;
    }
    return false;
}
