#pragma once
#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_ttf.h>
#include <iostream>

#define KEY_SEEN     1
#define KEY_RELEASED 2
#define FPS 120
#define width 1000
#define height 750
#define pull 9.87
#define speed 10
#define ClimbingSpeed 1.5

const double TimeBetweenFrames = 1 / FPS;