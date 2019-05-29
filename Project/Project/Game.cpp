#include "Game.h"



bool Controls(unsigned char * key, PostOffice* all)
{

	if (key[ALLEGRO_KEY_UP])
		//all->GivePlayer()->ChangeSpeed(0, -1 / FPS);
		if (all->GivePlayer()->IsDoingThis(WhatIsDoing::climbing))
		{
			all->GivePlayer()->ChangeSpeedTo(0, -TimeBetweenFrames * speed * ClimbingSpeed);
		}
		else
		{
			all->GivePlayer()->Jump();
		}

	if (key[ALLEGRO_KEY_DOWN])
		//all->GivePlayer()->ChangeSpeed(0, 1 / FPS);
		if (all->GivePlayer()->IsDoingThis(WhatIsDoing::climbing))
		{
			all->GivePlayer()->ChangeSpeedTo(0, TimeBetweenFrames * speed * ClimbingSpeed);
		}
		else
		{
			all->GivePlayer()->Crouch();
		}



	if (key[ALLEGRO_KEY_LEFT])
	{
		all->GivePlayer()->ChangeSpeed(-TimeBetweenFrames * speed, 0);
	}
		
	if (key[ALLEGRO_KEY_RIGHT])
	{
		all->GivePlayer()->ChangeSpeed(TimeBetweenFrames * speed, 0);
	}
		


	
	return false;
}

void DealWithEvent(ALLEGRO_EVENT * event, unsigned char key[], PostOffice * all, bool DontStopMeNow)
{
	switch (event->type)
	{
	case ALLEGRO_EVENT_TIMER:
		DontStopMeNow = Controls(key, all);

		break;

	case ALLEGRO_EVENT_KEY_DOWN:
		key[event->keyboard.keycode] = KEY_SEEN | KEY_RELEASED;
		break;

	case ALLEGRO_EVENT_KEY_UP:
		key[event->keyboard.keycode] &= KEY_RELEASED;
		break;

	case ALLEGRO_EVENT_DISPLAY_CLOSE:
		DontStopMeNow = false;

	default:
		break;
	}
}
