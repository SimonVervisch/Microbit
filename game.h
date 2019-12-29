#ifndef _GAME_H_
#define _GAME_H_
#include "linked-l.h"
#include "MicroBit.h"
//used in game.cpp
#include <stdbool.h>

extern MicroBit uBit;


typedef struct game{
	node_e *enemy_list;
	node_b *bullet_list;

} Game;

/*
 * Note: There hasn't beent allocated any space
 */
extern Game game;

#define BULTIME 10
#define ENEMYTIME 10
#define PLAYERTIME 10

#define PLAYERSIDE 0
#define ENEMYSIDE 4


#endif
