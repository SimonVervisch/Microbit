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
#define BULLETS_COUNTER 30
#define TYPE1_SHOOT_COUNTER 50
#define TYPE1_MOVE_COUNTER 63

// #define BULLET_COUNTER 10
// #define BULLET_COUNTER 10
// #define BULLET_COUNTER 10
// #define BULLET_COUNTER 10
// #define BULLET_COUNTER 10
//
#define GENERATE_ENEMY_COUNTER 63


/**
 * Indexes of the counter array. 
 */
#define TIMINGS_ARRAY_LENGTH 11
#define BULLETS 0 
#define TYPE1_SHOOT 1 
// #define BULLET 0 
// #define BULLET 0 
// #define BULLET 0 
#define TYPE1_MOVE 6 
// #define BULLET 0 
// #define BULLET 0 
// #define BULLET 0 
//
#define GENERATE_ENEMY 10
#define TYPE_1_ENEMY 0
#define TYPE_2_ENEMY 1
#define TYPE_3_ENEMY 2
#define TYPE_4_ENEMY 3
#define TYPE_5_ENEMY 4

#define SIZE_ENEMY 0
#define SCORE_WHEN_DEATH 1
#define HP 2


extern uint8_t timings_array[TIMINGS_ARRAY_LENGTH];
extern uint8_t enemies_stats_array[TYPE_5_ENEMY + 1][HP + 1];

void initialize_game();

#define LEFT_BORDER 5
#define RIGHT_BORDER 4


#endif
