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
	//printf("Plugboard start: %c\n", c);
	if (c < OFFSET || c > LAST) {
	printf("Bad value: %c\nTERMINATING\n", c);
	std::exit(1);
}
	if (plugs.find(c) == plugs.end()) {
		printf("No plug; %c\n", c);
		return c;
	}

	printf("Plugboard changes %c to %c\n", c, plugs[c]);
   return plugs[c];

}
