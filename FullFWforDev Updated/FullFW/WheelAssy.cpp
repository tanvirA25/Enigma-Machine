#include <stdio.h>
#include "WheelAssy.h"


void WheelAssy::advance() {
    printf("Wheel advance initiated\n");
    const bool w2atNotch = wheel2->atNotch();
    if (wheel1->atNotch()) { wheel2->advance(); }
    if (w2atNotch && !wheel2->atNotch()) { wheel3->advance(); }
    wheel1->advance();
}

unsigned char WheelAssy::rToL(unsigned char c) {
    printf("Right to left\n");
    short c1 = wheel1->getRtoL(c);
    short c2 = wheel2->getRtoL(c1);
    short c3 = wheel3->getRtoL(c2);
    printf("%c\n", c3);
	return c ;
}

unsigned char WheelAssy::lToR(unsigned char c) {
    printf("Left to right\n");
    short c3 = wheel3->getLtoR(c);
    short c2 = wheel2->getLtoR(c3);
    short c1 = wheel1->getLtoR(c2);
    printf("%c\n", c1 );
    return c1;
}

// Resets the wheels to their initial positions
void WheelAssy::reset() {
    printf("Wheels reset\n");
    wheel1->resetCur(c1);
    wheel2->resetCur(c2);
    wheel3->resetCur(c3);
}

WheelAssy::~WheelAssy() {
    delete wheel1;
    delete wheel2;
    delete wheel3;
}
