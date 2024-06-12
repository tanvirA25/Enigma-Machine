// Name: Tanvir Ahmed
// CS 490
// Assignment 1: Reflector


// header guard to prevent multiple inclusion
#ifndef Reflector_H
#define Reflector_H

#include <iostream>

//reflector class for singleton pattern
class Reflector {

// public member of reflector class
public:
    // returns simgleton instance of reflector
    static Reflector &Instance(){
        static Reflector ascii;
        return ascii;
    }
    //gets the unsigned char and returns its reflected value
    const unsigned char reflect(const unsigned char c);

// only can be accssed and modified within the reflector class
private:

    // array for character mapping
    static int arr[95];


};
#endif


  

  