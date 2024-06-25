#include "RedFileInterface.h"

using namespace std;

bool RedFileInterface::openForRead()
{
   return false;
}

bool RedFileInterface::openForWrite()
{
   return false;
}

bool RedFileInterface::eof()
{
   return false;
}

bool RedFileInterface::close()
{
   return false;
}

unsigned char RedFileInterface::getNextChar()
{ 
   return 0; 
}

bool RedFileInterface::putNextChar
   (unsigned char c)
{
   return false;
}