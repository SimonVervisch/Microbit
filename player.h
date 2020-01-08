#ifndef PLAYER_H_
#define PLAYER_H_
#include <stdio.h>
#include <stdlib.h>
typedef struct player{
	uint8_t x:1;
	uint8_t y:3;
	uint8_t lives:2; 
} Player;

uint8_t gravity_to_pixel(int8_t value);

extern Player player;
#endif
