#include "Wheel.h"
#include<random>

using namespace std;

bool debug = true;

void Wheel::loadLToR(){
    const int rRange = nRec -1;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0,nRec);

    for (short i = 0; i < nRec; ++i){
        lToR.push_back(i);
    }
     for (short i = 0; i < nRec; ++i){ 
        
        const short iSav = lToR.at(i);
        short j = dis(gen);

        const short jSav = lToR.at(j);
        swap(lToR[iSav], lToR[jSav]);
    }


}

void Wheel::loadRToL(){
 const int rRange = nRec -1;
    for (short i = 0; i < nRec; ++i){
        rToL.push_back(i);
    }
    for (short i = 0; i < nRec; ++i){ 
        const short iSav = lToR.at(i);
        rToL[iSav] = i;
    }
}



void Wheel::convertToOffset(){


    
}

short Wheel::getLtoR(short i){
  


}

short Wheel::getRtoL(short i){

     

}

Wheel::Wheel(
    const short       nEnts,
    const unsigned int seed,
    const short        cPos): nRec(nEnts), curPos(cPos){

    }

