#pragma once

#include <vector>

class Wheel
{
   vector<short>        lToR;
   vector<short>        rToL;

   const short          nRec;
   short               notch;
   short              curPos;
   unsigned int       seed;

   void loadLToR          ();
   void loadRToL          ();
   void convertToOffset   ();
 
 public:

    Wheel
    (
    const short       nEnts,
    const unsigned int seed,
    const short        cPos
    );

   //
   // Returns true
   // if wheel is at
   // notch, false otherwise.
   //
   inline bool atNotch() const  
        { return (curPos == notch); }

   //
   // Set top of wheel
   // to the specified
   // value.
   //
   inline void resetCur(short cP) 
                     { curPos = cP; }

   //
   // Get translated 
   // value at index, i.
   //
   short getLtoR           (short i);
   short getRtoL           (short i);

   //
   // Get current top
   // of wheel position.
   //
   inline short getCurPos()
                   { return curPos; }

   //
   // Advance the
   // wheel one position.
   //
   inline void  advance()
   {  
      curPos = (++curPos >= nRec) ?
                          0 : curPos;
   }
   inline void reverse() {
  
    curPos = (--curPos < 0) ? nRec - 1 : curPos;
}



