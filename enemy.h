#ifndef _ENEMY_H
#define _ENEMY_H
#include "point.h"

/*
 * Enemies have friendly fire off -> They can't shoot each other.
 * This is because they want to reduce the amounts of collision -> They can move through each other. 
 */
typedef struct enemy{
	Point pos;
	// uint8_t speed; // is encoded in timers
	uint8_t type: 3;
	uint8_t hitpoints_left: 3;
} Enemy;


void generate_enemy();
void move_enemies(uint8_t type);
void clean_enemies_array();
void enemies_add_bullets();

#endif
