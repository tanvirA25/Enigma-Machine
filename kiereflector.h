#ifndef Reflector_h
#define Reflector_h

#include <iostream>
#include <array>
#include <cstdlib>

class Reflector {
    
    public:
        static Reflector& Instance() {
            static Reflector instance;
            return instance;
        }

        const unsigned char reflect(const unsigned char c) const;

    private:
        std::array<int, 95> numbers;
        Reflector();
        ~Reflector() = default;
        Reflector(const Reflector&) = delete;
        Reflector& operator=(const Reflector&) = delete;

};

#endif 
