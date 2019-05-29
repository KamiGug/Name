#include "PostOffice.h"



PostOffice::PostOffice()
{
}


PostOffice::~PostOffice()
{
}

Player * PostOffice::GivePlayer()
{
	return player;
}

std::vector<PowerUp*> PostOffice::GivePowerUp()
{
	return IncreasePower;
}
