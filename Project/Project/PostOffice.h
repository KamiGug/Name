#pragma once
#include <vector>
#include "Player.h"
#include "PowerUp.h"

class PostOffice
{
public:
	PostOffice();
	~PostOffice();

	Player* GivePlayer();
	std::vector<PowerUp*> GivePowerUp();

private:
	Player* player;
	std::vector<PowerUp*> IncreasePower;

	//cokolwiek dalej
};

