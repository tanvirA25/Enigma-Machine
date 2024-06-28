#include             <iostream>
#include "BlackFileInterface.h"
#include   "RedFileInterface.h"

using namespace std;

int main()
{

   //
   // Test file
   // Interface.
   //
   RedFileInterface &rfi =
      RedFileInterface::Instance();

   BlackFileInterface &bfi =
      BlackFileInterface::Instance();


   rfi.openForRead("MyInFile.txt");
   
   bfi.openForWrite("MyOutFile.dat");

   while (rfi.eof() == false)
   {
      const unsigned char c = 
                   rfi.getNextChar();
      if (c<=127) bfi.putNextChar(c+20);
   }

   rfi.close();
   bfi.close();


   bfi.openForRead("MyOutFile.dat");
   rfi.openForWrite("MyOutFile.txt");

   while (bfi.eof() == false)
   {
      const unsigned char c = bfi.getNextChar();
      if (c<=127) rfi.putNextChar(c-20);
   }

   rfi.close();
   bfi.close();

   return 0;

 
}






