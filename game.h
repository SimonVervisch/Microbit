#ifndef _GAME_H_
#define _GAME_H_
#include "linked-l.h"
struct game{
	Player player;
	node_e *enemies;
	node_b *bullets;

} Game;

#define BULTIME 10
#define ENEMYTIME 10
#define PLAYERTIME 10


#endif
