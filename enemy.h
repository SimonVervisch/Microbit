#ifndef _ENEMY_H
#define _ENEMY_H
#include "point.h"
typedef struct enemy{
	Point pos;
	uint8_t speed;
	uint8_t fire_rate;
	uint8_t hitpoints;
	uint8_t size;
	uint8_t death_score;
} Enemy;

// maak enum met verschillende vijanden
//
//enum = {FIRST_EN, SECOND_EN, THIRD_EN, FOURTH_EN}
#endif
