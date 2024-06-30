#include "NESEncryptorControl.h"
using namespace std;



 void NESEncryptorControl::start(){

	bool b = ACSI.authorize();
	 if (!b) {
		 cout << "Cannot Authorize"<< endl;
		 terminate;
	 }
	 do {
		 UserInput::Action action = UI.getUserAction();
		 NEF.reset();

		 if (action == UserInput::ENC) {
			 rf.openForRead();
			 bf.openForWrite();
			 while (!rf.eof()) {
				 unsigned char c = rf.getNextChar();
				 c - 32;
				 c = NEF.encrypt(c);
				 bf.putNextChar(c + 32);
			 }
		 }

		 AAS.sendEncryptOK();

		 if (action == UserInput::DEC) {
			 bf.openForRead();
			 rf.openForWrite();
			 while (!bf.eof()) {
				 unsigned char c = bf.getNextChar();
				 c - 32;
				 c = NEF.decrypt(c);
				 rf.putNextChar(c + 32);
			 }
		 }
		 AAS.sendDecryptOK();

		 bf.close();
		 rf.close();
		
	 } while (true);

	 

	 

}
