#pragma once
#include "Object.h"
class Player :	public Object
{
public:
	//static void AddPlayer();
	//void AddPlayer(jakieś zmienne);
	~Player();
	Player();
	void Crouch(bool DoIt);
	bool IsThisCrouching();

protected:
	bool IsCrouching = 0;
};

