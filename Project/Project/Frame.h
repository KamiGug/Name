#pragma once
class Frame
{
public:
	Frame();
	~Frame();
private:
	ALLEGRO_BITMAP * Standing;

	double BoxOffsetX;
	double BoxOffsetY;
	double BoxSizeX;
	double BoxSizeY;
};

