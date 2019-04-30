#include "Init.h"

bool FirstInit()
{
	if (!al_init())
	{
		std::cout << "Couldn't initialize allegro";
		return true;
	}

	if (!al_init_image_addon())
	{
		std::cout << "Couldn't initialize allegro image";
		return true;
	}
	return false;
}

bool SecondInit(ALLEGRO_DISPLAY * Screen, ALLEGRO_TIMER * time, ALLEGRO_EVENT_QUEUE * queue)
{
	if (Screen == NULL)
	{
		std::cout << "Couldn't initialize screen";
		return -3;
	}

	if (time == NULL)
	{
		std::cout << "Couldn't initialize timer";
		return -4;
	}

	if (queue == NULL)
	{
		std::cout << "Couldn't initialize event queue";
		return -5;
	}

	if (!al_install_keyboard())
	{
		std::cout << "Couldn't initialize keyboard";
		return -6;
	}

	if (!al_install_mouse())
	{
		std::cout << "Couldn't initialize mouse";
		return -7;
	}

	al_register_event_source(queue, al_get_keyboard_event_source());
	al_register_event_source(queue, al_get_mouse_event_source());
	al_register_event_source(queue, al_get_display_event_source(Screen));
	al_register_event_source(queue, al_get_timer_event_source(time));
	return false;
}
