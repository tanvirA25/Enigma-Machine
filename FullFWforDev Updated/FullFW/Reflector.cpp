#include <stdio.h>
#include "Reflector.h"

// This mayhaps needs to be changed.
const unsigned char Reflector::getRefChar(const unsigned char ch) const {
    return 0;
};

Reflector::Reflector() {
    numbers = {
        45, 58, 66, 47, 16, 25, 15, 88, 74,
            62, 51, 77, 90, 61, 71, 6, 4, 80, 19,
            18, 94, 75, 53, 86, 28, 5, 76, 89, 24,
            55, 92, 34, 81, 82, 31, 63, 84, 93, 67,
            50, 91, 72, 57, 68, 54, 0, 60, 3, 78, 52,
            39, 10, 49, 22, 44, 29, 69, 42, 1, 64, 46,
            13, 9, 35, 59, 73, 2, 38, 43, 56, 79, 14, 41,
            65, 8, 21, 26, 11, 48, 70, 17, 32, 33, 83,
            36, 87, 23, 85, 7, 27, 12, 40, 30, 37, 20, 95
    };
    //numbers = { {61,7}, {55,51}, {73,54}, {57,94}, {84,82}, {59,21}, {3,91}, {7,88}, {8,74}, {9,62},
    //    {10,51}, {,} }
}

const unsigned char Reflector::reflect(const unsigned char c) const {
    printf("Reflect begin\n");
    if (c == 10) return 31;
    if (c == 31) return 10;
    if (c < OFFSET || c > LAST) {
        std::cout << "Bad value: " << c << "\nTERMINATING" << std::endl;
        std::exit(1);
    }
    printf("gg\n");
    printf("Reflect %c to %c\n", c, numbers[c-32] + 32);
    return static_cast<unsigned char> (numbers[c-32] + 32);
}



