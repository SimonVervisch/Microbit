#ifndef _GAME_H_
#define _GAME_H_
#include "linked-l.h"
#include "MicroBit.h" //used in game.cpp
#include <stdbool.h>

extern MicroBit uBit;

// 10 seems like an appropriate number to initaliaze the array with
#define INITIALIZATION_ARRAY 10

typedef struct game{
	Enemy enemy_list[INITIALIZATION_ARRAY];
	Bullet *bullet_array[INITIALIZATION_ARRAY];

} Game;

/*
 * Note: There hasn't beent allocated any space
 */
extern Game game;

// The speed at which the player can move and shoot (in milliseconds)
#define BASE_RATE_TIMING 10 
#define TYPE1_BULLET_TIMER 50
#define TYPE1_MOVE_TIMER 10

// #define BULLET_COUNTER 10
// #define BULLET_COUNTER 10
// #define BULLET_COUNTER 10
// #define BULLET_COUNTER 10
// #define BULLET_COUNTER 10
// #define BULLET_COUNTER 10


/**
 * Indexes of the counter array. 
 */
#define TIMINGS_ARRAY_LENGTH 9
#define BULLET_INDEX 0 
#define TYPE1_BULLET_INDEX 1 
// #define BULLET_INDEX 0 
// #define BULLET_INDEX 0 
// #define BULLET_INDEX 0 
#define TYPE1_MOVE_INDEX 5 
// #define BULLET_INDEX 0 
// #define BULLET_INDEX 0 
// #define BULLET_INDEX 0 


extern uint8_t timings_array[TIMINGS_ARRAY_LENGTH]


#define PLAYERSIDE 0
#define ENEMYSIDE 4


#endif
