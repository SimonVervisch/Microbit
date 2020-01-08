#ifndef _ENEMY_H
#define _ENEMY_H
#include "point.h"
typedef struct enemy{
	Point pos;
	// uint8_t speed; // is encoded in timers
	uint8_t type: 3;
	uint8_t hitpoints_left: 3;
} Enemy;


void generate_enemy();
void move_enemies();
void clean_enemies_array();
void enemies_add_bullets();

#endif
