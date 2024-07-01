#include <stdio.h>
#include "NESEncryptorFacade.h"
#include "Plugboard.h"

using namespace std;


bool NESEncryptorFacade::encrypt(unsigned char& c) {
	c = PB.getPBC(c);
	//c = Plugboard::Instance().getPBC(c);
	c = WHASS.rToL(c - 32);
	c = REF.reflect(c);
	c = WHASS.lToR(c - 32);
	c = PB.getPBC(c);
	//c = Plugboard::Instance().getPBC(c);
	WHASS.advance();
	return true;

}
bool NESEncryptorFacade::decrypt(unsigned char& c) {
	c = PB.getPBC(c);
	//c = Plugboard::Instance().getPBC(c);
	
	c = WHASS.rToL(c - 32);
	c = REF.reflect(c);
	c = WHASS.lToR(c - 32);
	c = PB.getPBC(c);
	//c = Plugboard::Instance().getPBC(c);
	WHASS.advance();
	printf("End decrypt: %c\n", c);
	return true;
}

void NESEncryptorFacade::reset() {
	WHASS.reset();
}