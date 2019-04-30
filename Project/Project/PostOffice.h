#pragma once
#include <vector>
#include "Player.h"
#include "PowerUp.h"

class PostOffice
{
public:
	PostOffice();
	~PostOffice();

private:
	Player* player;
	std::vector<PowerUp> IncreasePower;
	//cokolwiek dalej
};

