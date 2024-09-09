#include "Plugboard.h"

Plugboard::Plugboard()
{
	plugs = { { 1,3 }, { 3,1 }, { 4,8 }, { 5,64 }, { 8,4 }, { 64,5 } };
}

Plugboard::~Plugboard() {}

unsigned char Plugboard::getPBC(unsigned char c)
{
	// if the character is out of range terminate
	if (c < 0 || c > 96) { std::exit(1); }

	// if there is no mapping return the original char
	if (plugs.find(c) == plugs.end()) { return c; }

	// else return the changed char
    return plugs[c];

}