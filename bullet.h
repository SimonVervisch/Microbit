#ifndef _INCL_BUL
#define _INCL_BUL

#include <stdint.h>

typedef struct bullet{

	uint8_t x:3;
	uint8_t y:3;
	uint8_t player_bullet:1;

} Bullet;

void add_bullet(uint8_t player_bullet, uint8_t shooter_x, uint8_t shooter_y);
void move_bullets();
void clean_bullets_array();
#endif 

