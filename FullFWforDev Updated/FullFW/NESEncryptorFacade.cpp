#include <stdio.h>
#include "NESEncryptorFacade.h"
#include "Plugboard.h"

using namespace std;


bool NESEncryptorFacade::encrypt(unsigned char& c) {
	
	c = PB.getPBC(c);
	c = WHASS.rToL(c);
	c+=32;
	c = REF.reflect(c);
	c-=32;
	c = WHASS.lToR(c);
	c = PB.getPBC(c);
	WHASS.advance();
	
	return true;

}
bool NESEncryptorFacade::decrypt(unsigned char& c) {
	
	c = PB.getPBC(c);
	c+=32;
	c = WHASS.rToL(c);
	c = REF.reflect(c);
	c-=32;
	c = WHASS.lToR(c);
	c = PB.getPBC(c);
	WHASS.advance();
	
	printf("End decrypt: %c\n", c);
	return true;
}

void NESEncryptorFacade::reset() {
	WHASS.reset();
}
