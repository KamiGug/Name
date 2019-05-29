#pragma once
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>


class Frame
{
public:
	Frame();
	~Frame();
private:
	ALLEGRO_BITMAP * image;

	double BoxOffsetX;
	double BoxOffsetY;
	double BoxSizeX;
	double BoxSizeY;
};

