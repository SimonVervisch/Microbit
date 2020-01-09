#include "enemy.h"
#include "game.h"


void generate_enemy(){
	static uint8_t type = 1;
	if(array_enemies_length == array_enemies_allocated){
		array_enemies_allocated += 2;
		game.enemies_array = (Enemy *)realloc(game.enemies_array, sizeof(Enemy) * array_enemies_allocated);
	}
	/*
	if(--timings_array[BOSS_COUNTER] == 1){

	}
	*/
	Enemy enemy;
	enemy.pos.x = RIGHT_BORDER; 
	enemy.pos.y = rand() % (5 - enemies_stats_array[type][SIZE]);
	if(type){
		enemy.type = type;
		type = 0;
	} else {
		enemy.type = type;
		type = 1;
	}
	game.enemies_array[array_enemies_length++] = enemy;

}

void move_enemies(uint8_t type){
	for(uint8_t i = 0; i < array_enemies_length; i++){
		if(game.enemies_array[i].type == type){
			if(game.enemies_array[i].pos.x == 0){
				game.enemies_array[i].pos.x = LEFT_BORDER;
			} else {
				game.enemies_array[i].pos.x -= 1;
			}
		}
	}
	general_collision_detection();

	for(uint8_t i = 0; i< array_enemies_length; i++){
		if(game.enemies_array[i].pos.x == LEFT_BORDER){
			player_dead();
		}
	}

}


void clean_enemies_array(){
	for(uint8_t i = 0; i< array_enemies_length; i++){

		while(game.enemies_array[i].pos.x == LEFT_BORDER){

			if(i + 1 == array_enemies_length){

				array_enemies_length -= 1;
				break;
			} else {
				//else place last bullet on current bullet (to overwrite)
				game.enemies_array[i] = game.enemies_array[--array_enemies_length];
			}
		}
	}
}

