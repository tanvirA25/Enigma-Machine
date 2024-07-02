#include "RedFileInterface.h"
#include <iostream>
#include <fstream>

using namespace std;

// All return true if OK, otherwise false.
bool RedFileInterface::openForRead() {
	if (MyInFile.is_open()) {
		// printf("Red already open for read\n");
		return false;
	}
	// printf("Red open for read\n");
	MyInFile.open("MyInFile.txt", ios::in);
	return true;
}

bool RedFileInterface::openForWrite() {
	if (MyInFile.is_open()) {
		// printf("Red already open for write\n");
		return false;
	}
	// printf("Red open for write\n");
	MyInFile.open("MyOutFile.txt", ios::out);
	return true;
}

unsigned char RedFileInterface::getNextChar() {
	if (!MyInFile.good()) {
		// printf("No next char\n");
		return 0;
	}
	// printf("Red get next char\n");
	return MyInFile.get();
}

bool RedFileInterface::putNextChar(unsigned char c) {
	if (MyInFile) {
		// printf("Red put next char\n");
		MyInFile.put(c);
		return true;
	}
	// printf("Red can't put next char\n");
	return false;
}

bool RedFileInterface::eof() {
	if (MyInFile.eof()) {
		// printf("Red EOF\n");
		return true;
	}
	// printf("Red not EOF\n");
	return false;
}

bool RedFileInterface::close() {
	if (MyInFile.is_open()) {
		// printf("Red close file\n");
		MyInFile.close();
		return true;
	}
	// printf("Red not close file\n");
	return false;
}
