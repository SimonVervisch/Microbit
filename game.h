#ifndef _GAME_H_
#define _GAME_H_
#include "MicroBit.h" //used in game.cpp
#include "enemy.h"
#include "bullet.h"
#include <stdbool.h>

extern MicroBit uBit;

// Allocated the correct amount of 
extern uint8_t array_enemies_allocated ;
extern uint8_t array_bullets_allocated ;

extern uint8_t array_enemies_length;
extern uint8_t array_bullets_length;


typedef struct game{
	Enemy *enemy_array;
	Bullet *bullet_array;

} Game;

/*
 * Note: There hasn't beent allocated any space
 */
extern Game game;



// The speed at which the player can move and shoot (in milliseconds)
#define BASE_RATE_TIMING 10 
#define BULLETS_COUNTER 20
#define TYPE1_SHOOT_COUNTER 50
#define TYPE1_MOVE_COUNTER 100

// #define BULLET_COUNTER 10
// #define BULLET_COUNTER 10
// #define BULLET_COUNTER 10
// #define BULLET_COUNTER 10
// #define BULLET_COUNTER 10


/**
 * Indexes of the counter array. 
 */
#define TIMINGS_ARRAY_LENGTH 9
#define BULLETS_INDEX 0 
#define TYPE1_SHOOT_INDEX 1 
// #define BULLET_INDEX 0 
// #define BULLET_INDEX 0 
// #define BULLET_INDEX 0 
#define TYPE1_MOVE_INDEX 5 
// #define BULLET_INDEX 0 
// #define BULLET_INDEX 0 
// #define BULLET_INDEX 0 


extern uint8_t timings_array[TIMINGS_ARRAY_LENGTH];

void initialize_game();

#define PLAYERSIDE 0
#define ENEMYSIDE 4


#endif
