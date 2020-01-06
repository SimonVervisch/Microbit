#ifndef _GAME_H_
#define _GAME_H_
#include "linked-l.h"
#include "MicroBit.h" //used in game.cpp
#include <stdbool.h>

extern MicroBit uBit;


typedef struct game{
	Enemy *enemy_list;
	Bullet *bullet_array;

} Game;

/*
 * Note: There hasn't beent allocated any space
 */
extern Game game;

#define BASE_RATE_TIMING 10

#define TYPE1_BULLET_TIMER 50
#define TYPE1_MOVE_TIMER 10
/*
#define BULLET_COUNTER 10
#define BULLET_COUNTER 10
#define BULLET_COUNTER 10
#define BULLET_COUNTER 10
#define BULLET_COUNTER 10
#define BULLET_COUNTER 10
*/
#define TIMINGS_ARRAY_LENGTH 11

extern uint8_t timings_array[TIMINGS_ARRAY_LENGTH]

#define BULTIME 10
#define ENEMYTIME 10
#define PLAYERTIME 10

#define PLAYERSIDE 0
#define ENEMYSIDE 4


#endif
