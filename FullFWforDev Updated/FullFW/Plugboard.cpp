#include <map>
#include <stdio.h>
#include "Plugboard.h"

// map for some characters
Plugboard::Plugboard()
{
	plugs = { { 1,3 }, { 3,1 }, { 4,8 }, { 5,64 }, { 8,4 }, { 64,5 } };
}

Plugboard::~Plugboard() {}

unsigned char Plugboard::getPBC(unsigned char c)
{
	// retruns bad value if out of range
	//printf("Plugboard start: %c\n", c);
	if (c < OFFSET || c > LAST) {
		printf("Bad value: %c\nTERMINATING\n", c);
		std::exit(1);
}
	// if there is no mapping return the original char
	if (plugs.find(c) == plugs.end()) {
		printf("No plug; %c\n", c);
		return c;
	}
	// else return the changed char
	// printf("Plugboard changes %c to %c\n", c, plugs[c]);
   return plugs[c];

}
