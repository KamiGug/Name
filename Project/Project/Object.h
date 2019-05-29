#pragma once
#include "Necessities.h"
#include "Frame.h"

typedef enum {standing, walking, jumping, falling, climbing, crouching} WhatIsDoing;

class Object
{
public:
	Object();
	virtual ~Object();
	virtual void Draw();
	virtual void ChangeSpeed(double X, double Y);
	virtual void ChangeSpeedTo(double X, double Y);
	virtual void Move();
	void Jump();
	bool IsDoingThis(WhatIsDoing This);

protected:
	//drawing thingies
	double x;
	double y;
	

	//speed thingies
	double dx;
	double dy;

	//animation thingies
	int HowLongBeen;
	int MaxHowLong;

	Frame * CurrentFrame;
	int CurrentFrameLength;

	
	/*ALLEGRO_BITMAP ** Walking;
	ALLEGRO_BITMAP ** Jumping;
	ALLEGRO_BITMAP ** Falling;
	int WalkingLength;
	int JumpingLength;
	int Falling;*/
	WhatIsDoing IsDoing;
	
};

