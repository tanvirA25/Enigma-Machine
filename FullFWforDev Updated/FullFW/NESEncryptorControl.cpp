#include <iostream>
#include <stdio.h>
#include "NESEncryptorControl.h"
#include "ACSInterface.h"
#include "AASInterface.h"
#include "NESEncryptorFacade.h"
#include "UserInput.h"

//Set b to authorize() in ACSInterface
//If b is false, terminate with an error message
//Do forever
//Set action to getUserAction() in UserInput // program terminates if user commands
//Reset wheels to initial positions
//If ENC
//Open red file for read in RedFileInterface
//Open black file for write in BlackFileInterface
//While file not at end of red file
//Set c to getNextChar() in the red file
//Set c to encrypt(c - 32) in NESEncryptorFacade
//Call putNextChar(c + 32) in the black file
//Call sendEncryptOK() in AASInterface
//If DEC
//Open black file for read in BlackFileInterface
//Open red file for write in RedFileInterface
//While file not at end of black file
//Set c to getNextChar() in the black file
//Set c to decrypt(c - 32) in NESEncryptorFacade
//Call putNextChar(c + 32) in the red file
//Call sendDecryptOK() in AASInterface
//Close files
void NESEncryptorControl::start() {
	printf("Start\n");
	bool b = ACSInterface::Instance().authorize();

	if (!b) {
		std::cout << "Unauthorized access\n TERMINATING PROCESS\n";
		std::exit(1);
	}

	while (true) {
		UserInput::Action act = UserInput::Instance().getUserAction();
		printf("Action acquired\n");
		if (act == UserInput::Action::ENC) {
			printf("Encryption requested\n");
			RedFileInterface& red = RedFileInterface::Instance();
			BlackFileInterface& black = BlackFileInterface::Instance();

			red.openForRead();
			black.openForWrite();

			WheelAssy::Instance().reset();
			unsigned char c = red.getNextChar();
			while (!red.eof()) {
				
				printf("%c\n", c);
				NESEncryptorFacade::Instance().encrypt(c);
				if (c < 127) { black.putNextChar(c); }
				c = red.getNextChar();

			}

			black.close();
			red.close();

			AASInterface::Instance().sendEncryptOK();
		}

		else if (act == UserInput::Action::DEC) {
			printf("Decryption requested\n");
			RedFileInterface& red = RedFileInterface::Instance();
			BlackFileInterface& black = BlackFileInterface::Instance();

			black.openForRead();
			red.openForWrite();
			unsigned char c = black.getNextChar();
			WheelAssy::Instance().reset();
			while (!black.eof()) {
				
				printf("%c\n", c);
				NESEncryptorFacade::Instance().encrypt(c);
				if (c < 127) { red.putNextChar(c); }
				c = black.getNextChar();
			}

			black.close();
			red.close();

			AASInterface::Instance().sendDecryptOK();
		}
		else {
			return;
		}
	}
}