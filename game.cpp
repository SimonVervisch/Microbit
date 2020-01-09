#include "game.h"
#include "player.h"

Game game;
MicroBit uBit;
Player player;
uint8_t array_enemies_allocated ;
uint8_t array_bullets_allocated ;
           
uint8_t array_enemies_length;
uint8_t array_bullets_length;
uint8_t enemies_stats_array[TYPE4_ENEMY + 1][CURRENT_SHOOT_COUNTER + 1];

void initialize_game(){
	player.x = 0;
	player.y = 2;

	array_enemies_allocated = 10;
	array_bullets_allocated = 10;

	array_enemies_length = 0;
	array_bullets_length = 0;

	game.enemies_array = (Enemy *)malloc(array_enemies_allocated * sizeof(Enemy));
	game.bullets_array = (Bullet *)malloc(array_bullets_allocated * sizeof(Bullet));

	/**
	 * Fill enemies Stats array
	 */
	enemies_stats_array[TYPE1_ENEMY][SIZE] = SIZE_TYPE1; 
	enemies_stats_array[TYPE1_ENEMY][CURRENT_SHOOT_COUNTER] = TYPE1_SHOOT_COUNTER; 
	enemies_stats_array[TYPE1_ENEMY][BASE_SHOOT_COUNTER] = TYPE2_SHOOT_COUNTER; 

	enemies_stats_array[TYPE2_ENEMY][SIZE] = SIZE_TYPE2; 
	enemies_stats_array[TYPE2_ENEMY][CURRENT_SHOOT_COUNTER] = TYPE2_SHOOT_COUNTER; 
	enemies_stats_array[TYPE2_ENEMY][BASE_SHOOT_COUNTER] = TYPE2_SHOOT_COUNTER; 
	enemies_stats_array[TYPE2_ENEMY][CURRENT_MOVE_COUNTER] = TYPE2_MOVE_COUNTER;
	enemies_stats_array[TYPE2_ENEMY][BASE_MOVE_COUNTER] = TYPE2_MOVE_COUNTER; 

	/**
	 * Fill counters Array
	 */
	counters_array[BULLETS] = BULLETS_COUNTER;
	counters_array[ENEMY_BASE] = ENEMY_BASE_COUNTER;
	counters_array[GENERATE_ENEMY] = GENERATE_ENEMY_COUNTER;


}

void reset_game(){
	uBit.display.print("You Ded!");
	free(game.enemies_array);
	free(game.bullets_array);
	initialize_game();
}

void start_after_loading(){
	array_bullets_allocated = 10;
	array_bullets_length = 0;

	game.bullets_array = (Bullet *)malloc(array_bullets_allocated * sizeof(Bullet));
	counters_array[BULLETS] = BULLETS_COUNTER;
	counters_array[ENEMY_BASE] = ENEMY_BASE_COUNTER;
	counters_array[GENERATE_ENEMY] = GENERATE_ENEMY_COUNTER;
}



