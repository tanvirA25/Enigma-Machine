#pragma once

#include "ACSInterface.h"
#include "AASInterface.h"
#include "UserInput.h"
#include "RedFileInterface.h"
#include "BlackFileInterface.h"
#include "NESEncryptorFacade.h"



class NESEncryptorControl

{

	ACSInterface& ACSI;
	AASInterface& AAS;
	UserInput& UI;
	RedFileInterface& rf;
	BlackFileInterface& bf;
	NESEncryptortFacade& NEF;

	NESEncryptorControl() :
		ACSI(ACSInterface::Instance()),
		AAS(AASInterface::Instance()),
		UI(UserInput::Instance()),
		rf(RedFileInterface::Instance()),
		bf(BlackFileInterface::Instance()),
		NEF(NESEncryptortFacade::Instance())


	{}
	
public:

	static NESEncryptorControl& Instance()
	{
		static NESEncryptorControl NESC;
		return NESC;
	}

	void start();



};

