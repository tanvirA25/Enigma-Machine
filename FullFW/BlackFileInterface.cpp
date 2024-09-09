#include "BlackFileInterface.h"

using namespace std;

bool BlackFileInterface::openForRead() {
	if (MyInFile.is_open()) { return false; }
	MyInFile.open("MyOutFile.dat", ios::in);
	return true;
}

bool BlackFileInterface::openForWrite() {
	if (MyInFile.is_open()) { return false; }
	MyInFile.open("MyOutFile.dat", ios::out);
	return true;
}

unsigned char BlackFileInterface::getNextChar() {
	if (!MyInFile.good()) {	return 0; }
	return MyInFile.get();
}

bool BlackFileInterface::putNextChar(unsigned char c) {
	if (MyInFile) {
		MyInFile.put(c);
		return true;
	}
	return false;
}

bool BlackFileInterface::eof() {
	if (MyInFile.eof()) { return true; }
	return false;
}

bool BlackFileInterface::close() {
	if (MyInFile.is_open()) {
		MyInFile.close();
		return true;
	}
	return false;
}