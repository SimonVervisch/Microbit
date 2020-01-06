#ifndef _INCL_BUL
#define _INCL_BUL

#include "point.h"
#include <stdbool.h>


typedef struct bullet{
	Point pos;
	bool player_bullet;

} Bullet;

void add_bullet(bool player_bullet);
void remove_bullet();
void move_bullet(Bullet *bullet);
#endif 

