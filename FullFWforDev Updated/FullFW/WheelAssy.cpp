#include "WheelAssy.h"
#include "Wheel.h"

static short nents = 96;
static unsigned int seed1 = 111;
static unsigned int seed2 = 222;
static unsigned int seed3 = 333;
static short pos1 = 11;
static short pos2 = 22;
static short pos3 = 33;
bool w2AtNotch;

WheelAssy::WheelAssy() :

	wheel1(new Wheel(nents, seed1, pos1)),
	wheel2(new Wheel(nents, seed2, pos2)),
	wheel3(new Wheel(nents, seed3, pos3))

{ w2AtNotch = false;

};


void WheelAssy::advance() {

	
	if (wheel2->atNotch()){
		w2AtNotch = true;
	}
	if (wheel1->atNotch()) {
		wheel2->advance();
	}
	if (w2AtNotch && wheel2->atNotch() == false) {
		wheel3->advance();


	}
	wheel1->advance();

}
void WheelAssy::reset() {
	wheel1->resetCur(pos1);
	wheel2->resetCur(pos2);
	wheel3->resetCur(pos3);

}
unsigned char WheelAssy::lToR(unsigned char c) {
	unsigned char c1 = wheel1->getRtoL(c);
	unsigned char c2 = wheel2->getRtoL(c1);
	unsigned char c3 = wheel3->getRtoL(c2);
	return c3;


}
unsigned char WheelAssy::rToL(unsigned char c) {
	unsigned char c3 = wheel3->getRtoL(c);
	unsigned char c2 = wheel2->getRtoL(c3);
	unsigned char c1 = wheel3->getRtoL(c2);
	return c1;

}
WheelAssy::WheelAssy() {
	delete wheel1;
	delete wheel2;
	delete wheel3;
}

