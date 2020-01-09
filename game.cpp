#include "game.h"
#include "player.h"

Game game;
MicroBit uBit;
Player player;
uint8_t array_enemies_allocated;
uint8_t array_bullets_allocated;

uint8_t array_enemies_length;
uint8_t array_bullets_length;
uint8_t enemies_stats_array[TYPE4_ENEMY + 1][CURRENT_SHOOT_COUNTER + 1];

void initialize_game(){
	player.x = 0;
	player.lives = 3;

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

void initialize_new_game(){

	char string[10];
	uBit.display.print("Game Over");
	sprintf(string, "%d", game.score);
	uBit.display.print(string);
	reset_game();

}

void reset_game(){
	free(game.enemies_array);
	free(game.bullets_array);
	initialize_game();
}

void player_dead(){
	if(player.lives >= 0){
		player.lives -= 1;
		char lives[10];
		sprintf(lives, "%d", player.lives);
		uBit.display.print(lives);
		reset_game();
	} else {
		initialize_new_game();
	}
}

void general_collision_detection(){
	for(uint8_t i = 0; i < array_bullets_length; i++){
		Bullet bullet = game.bullets_array[i];
		if(!bullet.player_bullet){
			if(bullet.x == player.x && bullet.y == player.y){
				player_dead();

			} else {
				for(uint8_t k = 0; k < array_bullets_length; k++){
					Bullet bullet2 = game.bullets_array[k];
					if(k == i){
						continue;
					}
					if(bullet2.x == bullet.x && bullet2.y == bullet.y){
						game.bullets_array[i].x = RIGHT_BORDER + 1;
						game.bullets_array[k].x = RIGHT_BORDER + 1;
					}
				}
			}
		}
		for(uint8_t j = 0; j < array_enemies_length; j++){
			Enemy enemy = game.enemies_array[j];
			uint8_t counter = enemies_stats_array[enemy.type][SIZE];
			if(enemy.pos.x == bullet.x){
				while(counter > 0){
					if((enemy.pos.y + --counter) == bullet.y){
						game.enemies_array[j].pos.x = LEFT_BORDER;
						game.bullets_array[i].x = RIGHT_BORDER + 1; //move out of field
						break;

					}

				}
			}
		}
		clean_bullets_array();
		clean_enemies_array();
	}
}


void initialize_after_load(){
	array_bullets_allocated = 10;
	array_bullets_length = 0;

	game.bullets_array = (Bullet *)calloc(array_bullets_allocated , sizeof(Bullet));
	counters_array[BULLETS] = BULLETS_COUNTER;
	counters_array[ENEMY_BASE] = ENEMY_BASE_COUNTER;
	counters_array[GENERATE_ENEMY] = GENERATE_ENEMY_COUNTER;

	enemies_stats_array[TYPE1_ENEMY][CURRENT_SHOOT_COUNTER] = TYPE1_SHOOT_COUNTER; 

	enemies_stats_array[TYPE2_ENEMY][CURRENT_SHOOT_COUNTER] = TYPE2_SHOOT_COUNTER; 
	enemies_stats_array[TYPE2_ENEMY][CURRENT_MOVE_COUNTER] = TYPE2_MOVE_COUNTER;

}



