#include "game.h"

Game game;
MicroBit uBit;
uint8_t array_enemies_allocated ;
uint8_t array_bullets_allocated ;
           
uint8_t array_enemies_length;
uint8_t array_bullets_length;
uint8_t enemies_stats_array[TYPE5_ENEMY + 1][HP_TOTAL+1];

void initialize_game(){
	array_enemies_allocated = 10;
	array_bullets_allocated = 10;

	array_enemies_length = 0;
	array_bullets_length = 0;

	game.enemies_array = (Enemy *)malloc(array_enemies_allocated * sizeof(Enemy));
	game.bullets_array = (Bullet *)malloc(array_bullets_allocated * sizeof(Bullet));

	enemies_stats_array[TYPE1_ENEMY][SIZE_ENEMY] = SIZE_ENEMY_1; 
	enemies_stats_array[TYPE2_ENEMY][SIZE_ENEMY] = SIZE_ENEMY_2;

	timings_array[BULLETS] = BULLETS_COUNTER;
	timings_array[GENERATE_ENEMY] = GENERATE_ENEMY_COUNTER;
//	timings_array[TYPE1_SHOOT_INDEX] = TYPE1_SHOOT_COUNTER;
	timings_array[TYPE1_MOVE] = TYPE1_MOVE_COUNTER;


}


