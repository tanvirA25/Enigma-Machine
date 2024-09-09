#include "RedFileInterface.h"

using namespace std;

// All return true if OK, otherwise false.
bool RedFileInterface::openForRead() {
	if (MyInFile.is_open()) { return false; }
	MyInFile.open("MyInFile.txt", ios::in);
	return true;
}

bool RedFileInterface::openForWrite() {
	if (MyInFile.is_open()) { return false; }
	MyInFile.open("MyOutFile.txt", ios::out);
	return true;
}

unsigned char RedFileInterface::getNextChar() {
	if (!MyInFile.good()) { return 0; }
	return MyInFile.get();
}

bool RedFileInterface::putNextChar(unsigned char c) {
	if (MyInFile) {
		MyInFile.put(c);
		return true;
	}
	return false;
}

bool RedFileInterface::eof() {
	if (MyInFile.eof()) { return true; }
	return false;
}

bool RedFileInterface::close() {
	if (MyInFile.is_open()) {
		MyInFile.close();
		return true;
	}
	return false;
}