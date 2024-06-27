#include "BlackFileInterface.h"

using namespace std;

bool BlackFileInterface::openForRead()
{
   return false;
}

bool BlackFileInterface::openForWrite()
{
   return false;
}

bool BlackFileInterface::eof()
{
   return false;
}

bool BlackFileInterface::close()
{
   return false;
}

unsigned char BlackFileInterface::getNextChar()
{
   return 0;
}

bool BlackFileInterface::putNextChar
(unsigned char c)
{
   return false;
}