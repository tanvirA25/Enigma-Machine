#include "reflector.h"
#include <iostream>
#include <cstdlib>

Reflector& Reflector::Instance() {
    static Reflector instance;
    return instance;
}

Reflector::Reflector() {}

const unsigned char Reflector::reflect(const unsigned char c) {
    static const unsigned char mapping[] = {
        45, 58, 66, 47, 16, 25, 15, 88, 74, 62, 51, 77, 90,
	61, 71, 6, 4, 80, 19, 18, 94, 75, 53, 86, 28, 5, 76,
	89, 24, 55, 92, 34, 81, 82, 31, 63, 84, 93, 67, 50, 91,
	72, 57, 68, 54, 0, 60, 3, 78, 52, 39, 10, 49, 22, 44,
	29, 69, 42, 1, 64, 46, 13, 9, 35, 59, 73, 2, 38, 43, 56,
	79, 14, 41, 65, 8, 21, 26, 11, 48, 70, 17, 32, 33, 83, 36,
	87, 23, 85, 7, 27, 12, 40, 30, 37, 20
    };

    if (c >= 32 && c <= 126) {
        unsigned char index = c - 32;
        unsigned char result = mapping[index];
        return result + 32;
    } else if (c == 10) {
	   return 31;
    }   else if (c == 31) {
	       return 10;
    } else {
        std::cerr << "Bad value: " << static_cast<int>(c) << " TERMINATING" << std::endl;
        exit(EXIT_FAILURE);
    }
}
