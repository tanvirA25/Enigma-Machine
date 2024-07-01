#include <stdio.h>
#include "NESEncryptorControl.h"

using namespace std;

void NESEncryptorControl::start() {

	bool b = ACSI.authorize();
	if (!b) {
		cout << "Cannot Authorize" << endl;
		terminate;
	}

	do {
		UserInput::Action action = UI.getUserAction();
		NEF.reset();

		if (action == UserInput::ENC) {
			rf.openForRead();
			bf.openForWrite();
			while (true) {
				unsigned char c = rf.getNextChar();
				if (rf.eof()) { break; }
				printf("Start: %c\n", c);
				NEF.encrypt(c);
				bf.putNextChar(c);
				printf("End: %c\n", c);
			}
		}

		AAS.sendEncryptOK();

		if (action == UserInput::DEC) {
			bf.openForRead();
			rf.openForWrite();
			while (true) {
				unsigned char c = bf.getNextChar();
				if (bf.eof()) { break; }
				printf("Start: %c\n", c);
				NEF.decrypt(c);
				printf("red: %c\n", c);
				rf.putNextChar(c);
				printf("End: %c\n", c);
			}
		}
		AAS.sendDecryptOK();

		bf.close();
		rf.close();

	} while (true);





}