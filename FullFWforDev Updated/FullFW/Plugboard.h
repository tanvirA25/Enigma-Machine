#pragma once

#include <map>

class Plugboard {

      enum { DEBUG = false };

      const static unsigned char OFFSET = 32;
      const static unsigned char LAST = 126;

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




