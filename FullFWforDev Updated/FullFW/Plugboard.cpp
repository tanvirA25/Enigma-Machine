#include <map>
#include <stdio.h>
#include "Plugboard.h"

Plugboard::Plugboard()
{
	plugs = { { 1,3 }, { 3,1 }, { 4,8 }, { 5,64 }, { 8,4 }, { 64,5 } };
}

Plugboard::~Plugboard() {}

unsigned char Plugboard::getPBC(unsigned char c)
{

	//
	// If 3 is connected
	// to 1 then
	// if (c==3) return 1;
	// if (c==1) return 3;
	//   etc.
	//
	if (c == 10) { return 31; }
	if (c == 31) { return 10; }
	if (c < OFFSET || c > LAST) {
		printf("Bad value: %c\nTERMINATING\n", c);
		std::exit(1);
	}
	if (plugs.find(c) == plugs.end()) {
		printf("No plug\n");
		return c;
	}

	printf("Plugboard changes %c to %c\n", c, plugs[c]);
    return plugs[c-32] + 32;

}