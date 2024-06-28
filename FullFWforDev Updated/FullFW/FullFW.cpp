#include             <iostream>
#include <stdio.h>
#include              "Wheel.h"
#include          "UserInput.h"
#include "BlackFileInterface.h"
#include   "RedFileInterface.h"
#include       "AASInterface.h"
#include       "ACSInterface.h"
#include          "WheelAssy.h"
#include "NESEncryptorFacade.h"
#include "NESEncryptorControl.h"

using namespace std;

int main()
{
   // Instantiate NESEcryptor Control

   // Call start(.) in  NesEncryptor Control

	NESEncryptorControl::Instance().start();

}
 

