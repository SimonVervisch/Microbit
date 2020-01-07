#ifndef _INCL_BUL
#define _INCL_BUL



typedef struct bullet{

	uint8_t x:3;
	uint8_t y:3;
	uint8_t player_bullet:1;

} Bullet;

void add_bullet(bool player_bullet);
void move_and_clean_bullets();
#endif 

