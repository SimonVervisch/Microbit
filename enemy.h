#ifndef _ENEMY_H
#define _ENEMY_H
#include "point.h"
typedef struct enemy{
	Point pos;
	// uint8_t speed; // is encoded in timers
	uint8_t type: 3;
	uint8_t hitpoints: 4;
} Enemy;

#endif
