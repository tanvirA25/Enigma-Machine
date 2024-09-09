#pragma once

#include <map>

class Plugboard {

      enum { DEBUG = false };

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




