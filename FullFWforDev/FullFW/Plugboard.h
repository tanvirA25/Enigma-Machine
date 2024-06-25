#pragma once

class Plugboard
   {

      enum { DEBUG = false };


      //
      // Constructor is
      // private.
      //
      Plugboard();

   public:

      //
      // Meyer's Singleton
      // pattern.
      //
      static Plugboard& Instance()
      {
         static Plugboard pB;
         return           pB;
      }

      unsigned char
         getPBC(unsigned char c);

      ~Plugboard();

   };




