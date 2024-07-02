#include <stdio.h>
#include <cstdlib.h>
#include "NESEncryptorControl.h"

using namespace std;


void NESEncryptorControl::start() {
	// gets authorized from ACSnterface 
	// exit the program if cannot authroize
	bool b = ACSI.authorize();
	if (!b) {
		cout << "Cannot Authorize" << endl;
		termiante;
	}
	do {
		// loop to get userinput to either encrypt or decrypt
		UserInput::Action action = UI.getUserAction();
		NEF.reset();
		// if encrypt, gets the file interface to read and write
		if (action == UserInput::ENC) {
			rf.openForRead();
			bf.openForWrite();
			while (true) {
				unsigned char c = rf.getNextChar();
				if (rf.eof()) { break; }
				// printf("Start: %c\n", c);
				c -= 32;
				NEF.encrypt(c);
				c += 32;
				bf.putNextChar(c);
				// printf("End: %c\n", c);
			}
			bf.close();
			rf.close();
			AAS.sendEncryptOK();
		}
		// if encrypt gets the file interface to read and write
		if (action == UserInput::DEC) {
			bf.openForRead();
			rf.openForWrite();
			while (true) {
				unsigned char c = bf.getNextChar();
				if (bf.eof()) { break; }
				// printf("Start: %c\n", c);
				c -= 32;
				NEF.decrypt(c);
				c += 32;
				rf.putNextChar(c);
				// printf("End: %c\n", c);
			}
			bf.close();
			rf.close();
			AAS.sendDecryptOK();
		}

	} while (true);





}
