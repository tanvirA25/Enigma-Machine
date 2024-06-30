#include "NESEncryptorFacade.h"

using namespace std;




inline bool NESEncryptortFacade::encrypt(unsigned char c) {

	c = PB.getPBC(c);
	c = WHASS.rToL(c);
	c = REF.reflect(c);
	c = WHASS.lToR(c);
	c = PB.getPBC(c);
	WHASS.advance();
	return c;

}
inline bool NESEncryptortFacade::decrypt(unsigned char c) {
	c = PB.getPBC(c);
	c = WHASS.rToL(c);
	c = REF.reflect(c);
	c = WHASS.lToR(c);
	c = PB.getPBC(c);
	WHASS.advance();
	return c;

}
inline void NESEncryptortFacade::reset() {
	WHASS.reset();


}
