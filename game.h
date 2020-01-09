#ifndef _GAME_H_
#define _GAME_H_
#include "MicroBit.h" //used in game.cpp
#include "enemy.h"
#include "bullet.h"
#include <stdbool.h>

extern MicroBit uBit;

// The array is dynamically allocated and will remember the length
extern uint8_t array_enemies_allocated;
extern uint8_t array_bullets_allocated;

extern uint8_t array_enemies_length;
extern uint8_t array_bullets_length;


typedef struct game{
	Enemy *enemies_array;
	Bullet *bullets_array;
	uint8_t score;
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
// This is a counter that is 500 ms. You have enemies that shoot faster than they move and the opposite. Generation speeds also is something in between
#define ENEMY_BASE_COUNTER 10
#define GENERATE_ENEMY_COUNTER 8 //2000 ms
#define BOSS_BASE_COUNTER 2


/**
 * Indexes of the counter array. 
 */
#define TIMINGS_ARRAY_LENGTH 4
#define BULLETS 0 
#define ENEMY_BASE 1
#define GENERATE_ENEMY 2
#define BOSS_COUNTER 3

#define TYPE1_ENEMY 0
#define TYPE2_ENEMY 1
#define TYPE3_ENEMY 2
#define TYPE4_ENEMY 3
/**
 * Indexes in the enemies_stats_array
 */
#define SIZE 0
#define SCORE 1
#define HP_TOTAL 2
#define BASE_MOVE_COUNTER 3
#define BASE_SHOOT_COUNTER 4
#define CURRENT_MOVE_COUNTER 5 
#define CURRENT_SHOOT_COUNTER 6
/**
 * Values in the enemies_stats_array
 */

#define SIZE_TYPE1 1
#define SIZE_TYPE2 2
#define SIZE_TYPE3 2
#define SIZE_TYPE4 4

#define SCORE_TYPE1 1
#define SCORE_TYPE2 2
#define SCORE_TYPE3 3
#define SCORE_TYPE4 6

#define HP_TYPE1 0
#define HP_TYPE2 2
#define HP_TYPE3 2
#define HP_TYPE4 7


// #define TYPE1_MOVE_COUNTER NOT NECESSARY
#define TYPE1_SHOOT_COUNTER 6

#define TYPE2_MOVE_COUNTER 9
#define TYPE2_SHOOT_COUNTER 5

#define TYPE3_MOVE_COUNTER 6
#define TYPE3_SHOOT_COUNTER 6

#define TYPE4_MOVE_COUNTER 20
#define TYPE4_SHOOT_COUNTER 10
/**
 * Definition of enemy Stats. This is a big array that keeps all info on the enemies
 */
extern uint8_t counters_array[TIMINGS_ARRAY_LENGTH];
extern uint8_t enemies_stats_array[TYPE4_ENEMY + 1][CURRENT_SHOOT_COUNTER + 1];

void initialize_game();
void initialize_new_game();
void initialize_after_load();
void reset_game();
void general_collision_detection();
void player_dead();

// can't go negative with uint8_t -> picked a pixel to the right
#define LEFT_BORDER 6
#define RIGHT_BORDER 4

#endif
