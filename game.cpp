#include "game.h"

Game game;
MicroBit uBit;
uint8_t array_enemies_allocated ;
uint8_t array_bullets_allocated ;
           
uint8_t array_enemies_length;
uint8_t array_bullets_length;

void initialize_game(){
	game.enemy_array = (Enemy *)malloc(array_enemies_allocated * sizeof(Enemy));
	game.bullet_array = (Bullet *)malloc(array_bullets_allocated * sizeof(Bullet));
	timings_array[BULLETS_INDEX] = BULLETS_COUNTER;
	timings_array[TYPE1_SHOOT_INDEX] = TYPE1_SHOOT_COUNTER;
	timings_array[TYPE1_MOVE_INDEX] = TYPE1_MOVE_COUNTER;

	array_enemies_allocated = 10;
	array_bullets_allocated = 10;

	array_enemies_length = 0;
	array_bullets_length = 0;

}


// initialization
//game.bullet_list = NULL;
//game.enemy_list = NULL;

/*
// includes state of game
//
uint8_t enemy_spawn;

void game_loop(){
//runs while game hasn't ended yet
}

void check_game_ended(){
// if lives empty
}

void update_positions(){
// dit is de logica
//bullets // check botsing

//player
//enemies

}

void draw_positions(){



}*/
