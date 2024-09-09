#if !defined (Reflector____INCL)
#define Reflector____INCL

#include <iostream>
#include <array>
#include <cstdlib>

class Reflector {
    enum { DEBUG = false };

    std::array<int, 96> numbers;

    // Constructor is private.
    Reflector();
    Reflector(const Reflector&) = delete;
    Reflector& operator=(const Reflector&) = delete;

public:
    // Meyer's Singleton pattern.
    static Reflector& Instance() {
        static Reflector ref;
        return ref;
    }

    const unsigned char reflect(const unsigned char c) const;

    ~Reflector() {};

};

#endif