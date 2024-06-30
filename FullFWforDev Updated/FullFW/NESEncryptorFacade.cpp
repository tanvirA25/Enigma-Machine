#include <iostream>
#include "NESEncryptorFacade.h"
#include "WheelAssy.h"
#include "Plugboard.h"
#include "Reflector.h"

using namespace std;
//Open red file for read in RedFileInterface
//Open black file for write in BlackFileInterface
//Reset wheels to initial positions
//While file not at end of file
//Set c to getNextChar() in the red file
//Set c to getPBC(c)
//Set c to rToL(c) in WheelAssy
//Set c to reflect(c) in Reflector
//Set c to lToR(c) in WheelAssy
//Set c to getPBC(c)
//Call advance() in WheelAssy
//Call putNextChar(c) in the black file
//Close red file
//Close black file
bool NESEncryptorFacade::encrypt(char c) {
	c = Plugboard::Instance().getPBC(c);
	c = WheelAssy::Instance().rToL(c-32);
	c = Reflector::Instance().reflect(c);
	c = WheelAssy::Instance().lToR(c-32);
	c = Plugboard::Instance().getPBC(c);
	WheelAssy::Instance().advance();

	return true;
}


//Open black file for read in BlackFileInterface
//Open red file for write in RedFileInterface
//Reset wheels to initial positions
//While file not at end of file
//Set c to getNextChar() in the Red file
//Set c to getPBC(c)
//Set c to rToL(c) in WheelAssy
//Set c to reflect(c) in Reflector
//Set c to rToL(c) in WheelAssy
//Set c to getPBC(c)
//Call advance() in WheelAssy
//Call putNextChar(c) in the red file
//Close red file
//Close black file
bool NESEncryptorFacade::decrypt(char c) {
	c = Plugboard::Instance().getPBC(c);
	c = WheelAssy::Instance().rToL(c-32);
	c = Reflector::Instance().reflect(c);
	c = WheelAssy::Instance().lToR(c-32);
	c = Plugboard::Instance().getPBC(c);
	WheelAssy::Instance().advance();

	return true;
}