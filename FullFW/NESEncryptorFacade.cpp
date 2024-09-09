#include "NESEncryptorFacade.h"
#include "Plugboard.h"

using namespace std;

// encrypt file going through the cmoponents of enigma machine
bool NESEncryptorFacade::encrypt(unsigned char& c) {
	WHASS.advance();
	c = PB.getPBC(c);
	c = WHASS.rToL(c);
	c = REF.reflect(c);
	c = WHASS.lToR(c);
	c = PB.getPBC(c);
	return true;

}

// decrypt file by going through the components of enigma machine
bool NESEncryptorFacade::decrypt(unsigned char& c) {
	WHASS.advance();
	c = PB.getPBC(c);
	c = WHASS.rToL(c);
	c = REF.reflect(c);
	c = WHASS.lToR(c);
	c = PB.getPBC(c);
	return true;
}

// reset the wheel
void NESEncryptorFacade::reset() {
	WHASS.reset();
}