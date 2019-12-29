#ifndef _INCL_BUL
#define _INCL_BUL

#include "point.h"
#include <stdbool.h>

// Needed for bullet.cpp

typedef struct bullet{
	Point pos;
	bool player_bullet;

} Bullet;
void add_bullet(bool player_bullet);
void remove_bullet();
#endif 

