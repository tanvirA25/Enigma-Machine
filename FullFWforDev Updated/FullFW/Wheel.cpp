#include "Wheel.h"
#include <random>


void Wheel::loadLToR()
{ }


void Wheel::loadRToL()
{ }

void Wheel::convertToOffset()
{}

short Wheel::getLtoR(short i)
{
   return 0;
}

short Wheel::getRtoL(short i)
{
   return 0;
}

Wheel::Wheel
(
   const short               nEnts,
   const unsigned int         seed,
   const short                cPos
) : nRec(nEnts), curPos(cPos)
{}

Wheel::~Wheel()
{}