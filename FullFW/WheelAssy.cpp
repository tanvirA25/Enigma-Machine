#include "WheelAssy.h"


void WheelAssy::advance() {
    const bool w2atNotch = wheel2->atNotch();
    if (wheel1->atNotch()) { wheel2->advance(); }
    if (w2atNotch && !wheel2->atNotch()) { wheel3->advance(); }
    wheel1->advance();
}

unsigned char WheelAssy::rToL(unsigned char c) {
    return wheel3->getRtoL(wheel2->getRtoL(wheel1->getRtoL(c)));
}

unsigned char WheelAssy::lToR(unsigned char c) {
    return wheel1->getLtoR(wheel2->getLtoR(wheel3->getLtoR(c)));
}

// Resets the wheels to their initial positions
void WheelAssy::reset() {
    wheel1->resetCur(c1);
    wheel2->resetCur(c2);
    wheel3->resetCur(c3);
}

WheelAssy::~WheelAssy() {
    delete wheel1;
    delete wheel2;
    delete wheel3;
}