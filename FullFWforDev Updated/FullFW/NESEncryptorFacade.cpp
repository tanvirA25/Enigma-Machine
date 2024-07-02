#include <stdio.h>
#include "NESEncryptorFacade.h"
#include "Plugboard.h"

using namespace std;

// encrypt file going through the cmoponents of enigma machine
bool NESEncryptorFacade::encrypt(unsigned char& c) {	
	c = PB.getPBC(c);
	c = WHASS.rToL(c);
	c+=32; // adjustment for reflector
	c = REF.reflect(c);
	c-=32; // adjustment for reflector
	c = WHASS.lToR(c);
	c = PB.getPBC(c);
	WHASS.advance();
	
	return true;

}
// decrypt file by going through the components of enigma machine
bool NESEncryptorFacade::decrypt(unsigned char& c) {
	c = PB.getPBC(c);
	c+=32; // adjustment for reflector
	c = WHASS.rToL(c);
	c = REF.reflect(c);
	c-=32; // adjustment for reflector
	c = WHASS.lToR(c);
	c = PB.getPBC(c);
	WHASS.advance();
	
	printf("End decrypt: %c\n", c);
	return true;
}

// reset the wheel
void NESEncryptorFacade::reset() {
	WHASS.reset();
}
