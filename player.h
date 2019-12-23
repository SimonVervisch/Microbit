#ifndef PLAYER_H_
#define PLAYER_H_
#include "point.h"
typedef struct player{
	register Point pos; //as this will be used a lot
	uint8_t lives; 
} Player;
#endif
