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
	Enemy *enemies_array;
	Bullet *bullets_array;

} Game;
/*
 * Note: There hasn't beent allocated any space
 */
extern Game game;


// The speed at which the player can move and shoot (in milliseconds)
#define BASE_RATE_TIMING 10 
/*
 * Calculation = bullet_speed * enemy_speed * enemy_generation !Enemy Generation will change!
 *
 * TIMING GUIDELINES: 100-200 ms bullet speed
 * Enemy movement 1500 - 2000 ms
 * Enemy Generation 4000 - 6000 ms
 */
#define BULLETS_COUNTER 5
// #define BULLET_COUNTER 10
// #define BULLET_COUNTER 10
// #define BULLET_COUNTER 10
// #define BULLET_COUNTER 10
//
#define GENERATE_ENEMY_COUNTER 2


/**
 * Indexes of the counter array. 
 */
#define TIMINGS_ARRAY_LENGTH 11
#define BULLETS 0 
#define TYPE1_SHOOT 1 
#define TYPE2_SHOOT 2 
// #define BULLET 0 
// #define BULLET 0 
// #define BULLET 0 
#define TYPE1_MOVE 6 
#define TYPE2_MOVE 7 
// #define BULLET 0 
// #define BULLET 0 
// #define BULLET 0 
//
#define GENERATE_ENEMY 10
#define TYPE1_ENEMY 0
#define TYPE2_ENEMY 1
#define TYPE3_ENEMY 2
#define TYPE4_ENEMY 3
#define TYPE5_ENEMY 4

#define SIZE_ENEMY 0
#define SCORE_WHEN_DEATH 1
#define HP_TOTAL 2
#define MOVE_COUNTER 3
#define SHOOT_COUNTER 4

#define SIZE_ENEMY_1 1
#define SIZE_ENEMY_2 2
#define TYPE1_MOVE_COUNTER 30
//#define TYPE1_SHOOT_COUNTER 50
#define TYPE2_MOVE_COUNTER 5
// #define TYPE2_SHOOT_COUNTER 50

extern uint8_t timings_array[TIMINGS_ARRAY_LENGTH];
extern uint8_t enemies_stats_array[TYPE5_ENEMY + 1][SHOOT_COUNTER + 1];

void initialize_game();
void reset_game();

#define LEFT_BORDER 0
#define RIGHT_BORDER 4
#define DEBUG_MODE 0


#endif
