#pragma once

#include <map>

class Plugboard {

      enum { DEBUG = false };

      // var to use in the cpp file
      const static unsigned char OFFSET = 0;
      const static unsigned char LAST = 95;

      std::map<int, int> plugs;

      // Constructor is private.
      Plugboard();

   public:

      // Meyer's Singleton pattern.
      static Plugboard& Instance() {
         static Plugboard pB;
         return pB;
      }

      unsigned char getPBC(unsigned char c);

      ~Plugboard();

   };




