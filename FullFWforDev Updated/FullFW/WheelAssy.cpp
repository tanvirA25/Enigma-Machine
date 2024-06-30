#include <stdio.h>
#include "WheelAssy.h"


//Set w2AtNotch to true if wheel2 is at notch
//If wheel 1 is at notch advance() wheel 2
//If w2AtNotch AND wheel 2 is NOT at notch advance() wheel 3
//advance() wheel 1
void WheelAssy::advance() {
    printf("Wheel advance initiated\n");
    const bool w2atNotch = wheel2->atNotch();
    if (wheel1->atNotch()) { wheel2->advance(); }
    if (w2atNotch && !wheel2->atNotch()) { wheel3->advance(); }
    wheel1->advance();
}


	}
    wheel1->advance();

//Set c1 to Wheel 1 rToL(c)
//Set c2 to Wheel 2 rToL(c1)
//Set c3 to Wheel 3 rToL(c2)
//Return c3
unsigned char WheelAssy::rToL(unsigned char c) {
    printf("Right to left\n");
    short c1 = wheel1->getRtoL(c);
    short c2 = wheel2->getRtoL(c1);
    short c3 = wheel3->getRtoL(c2);
    printf("%c\n", c3 + 32);
	return static_cast<unsigned char> (c3+32);
}

// Resets the wheels to their initial positions
void WheelAssy::reset() {
    printf("Wheels reset\n");
    wheel1->resetCur(c1);
    wheel2->resetCur(c2);
    wheel3->resetCur(c3);
}
unsigned char WheelAssy::lToR(unsigned char c) {
    printf("Left to right\n");
    short c3 = wheel1->getLtoR(c);
    short c2 = wheel2->getLtoR(c1);
    short c1 = wheel3->getLtoR(c2);
    printf("%c\n", c3 + 32);
    return static_cast<unsigned char> (c1+32);
}

//Set c3 to Wheel 3 lToR(c)
//Set c2 to Wheel 2 lToR(c3)
//Set c1 to Wheel 1 lToR(c2)
//Return c1
unsigned char WheelAssy::lToR(unsigned char c) {
    printf("Left to right\n");
    short c3 = wheel1->getLtoR(c);
    short c2 = wheel2->getLtoR(c1);
    short c1 = wheel3->getLtoR(c2);
    printf("%c\n", c3 + 32);
    return static_cast<unsigned char> (c1+32);
}
