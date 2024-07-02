#include "BlackFileInterface.h"
#include <iostream>
#include <fstream>
#include <stdio.h>

using namespace std;

bool BlackFileInterface::openForRead() {
	if (MyInFile.is_open()) {
		//printf("Black already open for read\n");
		return false;
	}
	//printf("Black open for read\n");
	MyInFile.open("MyOutFile.dat", ios::in);
	return true;
}


bool BlackFileInterface::openForWrite() {
	if (MyInFile.is_open()) {
		//printf("Black already open for write\n");
		return false;
	}
	//printf("Black open for write\n");
	MyInFile.open("MyOutFile.dat", ios::out);
	return true;
}

unsigned char BlackFileInterface::getNextChar() {
	if (!MyInFile.good()) {
		//printf("No next char\n");
		return 0;
	}
	//printf("Black get char\n");
	return MyInFile.get();
}

bool BlackFileInterface::putNextChar(unsigned char c) {
	if (MyInFile) {
		//printf("Black put next char\n");
		MyInFile.put(c);
		return true;
	}
	//printf("Black can't put next char\n");
	return false;
}

bool BlackFileInterface::eof() {
	if (MyInFile.eof()) {
		//printf("Black EOF\n");
		return true;
	}
	//printf("Black not EOF\n");
	return false;
}

bool BlackFileInterface::close() {
	if (MyInFile.is_open()) {
		//printf("Black close file\n");
		MyInFile.close();
		return true;
	}
	//printf("Black not close file\n");
	return false;
}
