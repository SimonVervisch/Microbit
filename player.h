#ifndef PLAYER_H_
#define PLAYER_H_
#include "point.h"
#include "MicroBit.h"
#include <stdio.h>
#include <stdlib.h>
typedef struct player{
	Point pos; 
	uint8_t lives; 
} Player;

uint8_t gravity_to_pixel(int8_t value);

Player player;
#endif
