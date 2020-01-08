#include "game.h"
#include "player.h"

Game game;
MicroBit uBit;
Player player;
uint8_t array_enemies_allocated ;
uint8_t array_bullets_allocated ;
           
uint8_t array_enemies_length;
uint8_t array_bullets_length;
uint8_t enemies_stats_array[TYPE5_ENEMY + 1][SHOOT_COUNTER + 1];

void initialize_game(){
	player.pos.x = 0;
	player.pos.y = 2;
	array_enemies_allocated = 10;
	array_bullets_allocated = 10;

	array_enemies_length = 0;
	array_bullets_length = 0;

	game.enemies_array = (Enemy *)malloc(array_enemies_allocated * sizeof(Enemy));
	game.bullets_array = (Bullet *)malloc(array_bullets_allocated * sizeof(Bullet));

	enemies_stats_array[TYPE1_ENEMY][SIZE_ENEMY] = SIZE_ENEMY_1; 
	enemies_stats_array[TYPE2_ENEMY][SIZE_ENEMY] = SIZE_ENEMY_2;
	enemies_stats_array[TYPE1_ENEMY][MOVE_COUNTER] = TYPE1_MOVE_COUNTER; 
	enemies_stats_array[TYPE2_ENEMY][MOVE_COUNTER] = TYPE2_MOVE_COUNTER; 

	timings_array[BULLETS] = BULLETS_COUNTER;
	timings_array[GENERATE_ENEMY] = GENERATE_ENEMY_COUNTER;
	timings_array[TYPE1_MOVE] = TYPE1_MOVE_COUNTER;
	timings_array[TYPE2_MOVE] = TYPE2_MOVE_COUNTER;
//	timings_array[TYPE1_SHOOT_INDEX] = TYPE1_SHOOT_COUNTER;


}

void reset_game(){
	uBit.display.print("You Ded!");
	free(game.enemies_array);
	free(game.bullets_array);
	initialize_game();
}


