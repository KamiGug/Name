#include "Game.h"

bool Controls(unsigned char * key, PostOffice* all)
{
	if (key[ALLEGRO_KEY_UP])
		y--;
	if (key[ALLEGRO_KEY_DOWN])
		y++;
	if (key[ALLEGRO_KEY_LEFT])
		x--;
	if (key[ALLEGRO_KEY_RIGHT])
		x++;
	return false;
}
