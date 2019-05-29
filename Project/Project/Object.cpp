#include "Object.h"



Object::Object()
{
}


Object::~Object()
{
}

void Object::Draw()
{
}

void Object::ChangeSpeed(double X, double Y)
{
	dx += X;
	dy += Y;
}

void Object::ChangeSpeedTo(double X, double Y)
{
	x = X;
	y = Y;
}

void Object::Move()
{
	x += dx * speed;
	y += dy * speed;
}

bool Object::IsDoingThis(WhatIsDoing This)
{
	if (this->IsDoing == This)
	{
		return true;
	}
	else
	{
		return false;
	}
	
}
