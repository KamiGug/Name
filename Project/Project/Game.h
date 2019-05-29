#pragma once
#include "Necessities.h"
#include "PostOffice.h"

bool Controls(unsigned char* key, PostOffice* all);

void DealWithEvent(ALLEGRO_EVENT* event, unsigned char key[], PostOffice* all, bool DontStopMeNow);