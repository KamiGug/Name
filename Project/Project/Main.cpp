#include "Necessities.h"
#include "Object.h"
#include "Game.h"
#include "Init.h"
#include "PostOffice.h"

#define KEY_SEEN     1
#define KEY_RELEASED 2

int main()
{
	std::cout << "AaAaAaAaAaAaAaAaAaAa";
	if (!FirstInit())
	{
		return -1;
	}

	ALLEGRO_DISPLAY * Screen = al_create_display(width, height);
	ALLEGRO_TIMER * time = al_create_timer(1.0 / FPS);
	ALLEGRO_EVENT_QUEUE * queue = al_create_event_queue();
	
	if (!SecondInit(Screen, time, queue))
	{
		return -2;
	}

	unsigned char key[ALLEGRO_KEY_MAX];
	memset(key, 0, sizeof(key));

	ALLEGRO_EVENT event;

	PostOffice * all;

	bool DontStopMeNow = 1;

	int a = 0;

	al_start_timer(time);
	while (DontStopMeNow)
	{
		al_wait_for_event(queue, &event);
		switch (event.type)
		{
		case ALLEGRO_EVENT_TIMER:

			DontStopMeNow = Controls(key, all);
			break;

		case ALLEGRO_EVENT_KEY_DOWN:
			key[event.keyboard.keycode] = KEY_SEEN | KEY_RELEASED;
			break;

		case ALLEGRO_EVENT_KEY_UP:
			key[event.keyboard.keycode] &= KEY_RELEASED;
			break;

		case ALLEGRO_EVENT_DISPLAY_CLOSE:
			DontStopMeNow = false;

		default:
			break;
		}
		/*switch (a)
		{
		case 0:
			al_clear_to_color(al_map_rgb(255, 0, 0));
			break;

		case 1:
			al_clear_to_color(al_map_rgb(0, 255, 0));
			break;

		case 2:
			al_clear_to_color(al_map_rgb(0, 0, 255));
			break;

		default:
			break;
		}

		a = (a + 1) % 3;*/
		
		//

		al_flip_display();
	}


	return 0;
}