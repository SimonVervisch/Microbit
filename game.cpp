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

void reset_counters(){
	counters_array[BULLETS] = BULLETS_COUNTER;
	counters_array[ENEMY_BASE] = ENEMY_BASE_COUNTER;
	counters_array[GENERATE_ENEMY] = GENERATE_ENEMY_COUNTER;

	enemies_stats_array[TYPE1_ENEMY][CURRENT_SHOOT_COUNTER] = TYPE1_SHOOT_COUNTER; 

	enemies_stats_array[TYPE2_ENEMY][CURRENT_SHOOT_COUNTER] = TYPE2_SHOOT_COUNTER; 
	enemies_stats_array[TYPE2_ENEMY][CURRENT_MOVE_COUNTER] = TYPE2_MOVE_COUNTER;
	enemies_stats_array[TYPE3_ENEMY][CURRENT_SHOOT_COUNTER] = TYPE3_SHOOT_COUNTER; 
	enemies_stats_array[TYPE3_ENEMY][CURRENT_MOVE_COUNTER] = TYPE3_MOVE_COUNTER;
	enemies_stats_array[TYPE4_ENEMY][CURRENT_SHOOT_COUNTER] = TYPE4_SHOOT_COUNTER; 
	enemies_stats_array[TYPE4_ENEMY][CURRENT_MOVE_COUNTER] = TYPE4_MOVE_COUNTER;
}

void initialize_game(){
	player.x = 0;

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
	enemies_stats_array[TYPE1_ENEMY][SCORE] = SCORE_TYPE1; 
	enemies_stats_array[TYPE1_ENEMY][HP_TOTAL] = HP_TYPE1; 

	enemies_stats_array[TYPE1_ENEMY][BASE_SHOOT_COUNTER] = TYPE2_SHOOT_COUNTER; 

	enemies_stats_array[TYPE2_ENEMY][SIZE] = SIZE_TYPE2; 
	enemies_stats_array[TYPE2_ENEMY][SCORE] = SCORE_TYPE2; 
	enemies_stats_array[TYPE1_ENEMY][HP_TOTAL] = HP_TYPE2; 
	enemies_stats_array[TYPE2_ENEMY][BASE_SHOOT_COUNTER] = TYPE2_SHOOT_COUNTER; 
	enemies_stats_array[TYPE2_ENEMY][BASE_MOVE_COUNTER] = TYPE2_MOVE_COUNTER; 

	enemies_stats_array[TYPE3_ENEMY][SIZE] = SIZE_TYPE3; 
	enemies_stats_array[TYPE3_ENEMY][SCORE] = SCORE_TYPE3; 
	enemies_stats_array[TYPE1_ENEMY][HP_TOTAL] = HP_TYPE3; 
	enemies_stats_array[TYPE3_ENEMY][BASE_SHOOT_COUNTER] = TYPE3_SHOOT_COUNTER; 
	enemies_stats_array[TYPE3_ENEMY][BASE_MOVE_COUNTER] = TYPE3_MOVE_COUNTER; 

	enemies_stats_array[TYPE4_ENEMY][SIZE] = SIZE_TYPE4; 
	enemies_stats_array[TYPE4_ENEMY][SCORE] = SCORE_TYPE4; 
	enemies_stats_array[TYPE1_ENEMY][HP_TOTAL] = HP_TYPE4; 
	enemies_stats_array[TYPE4_ENEMY][BASE_SHOOT_COUNTER] = TYPE4_SHOOT_COUNTER; 
	enemies_stats_array[TYPE4_ENEMY][BASE_MOVE_COUNTER] = TYPE4_MOVE_COUNTER; 
	reset_counters();
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
		uBit.display.scroll("Lives: ");
		ManagedString s(player.lives);
		uBit.display.scroll(s);
		reset_game();
	} else {
		initialize_new_game();
	}
}

void add_score(uint8_t score){
	if((game.score - score) < 58){
		game.score += score;
	} else{
		uBit.display.scroll("Max score: 64 reached. Play again");
		player.lives = 3;
		reset_game();
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
					if(bullet2.player_bullet){
						if(k == i){
							continue;
						}
						if(bullet2.x == bullet.x && bullet2.y == bullet.y){
							uBit.display.print("re");
							game.bullets_array[i].x = RIGHT_BORDER + 1;
							game.bullets_array[k].x = RIGHT_BORDER + 1;
						}
					}
				}
			}
			continue;
		}
		for(uint8_t j = 0; j < array_enemies_length; j++){
			Enemy enemy = game.enemies_array[j];
			uint8_t counter = enemies_stats_array[enemy.type][SIZE];
			if(enemy.pos.x == bullet.x){
				while(counter > 0){
					if((enemy.pos.y + --counter) == bullet.y){
						if(enemy.hitpoints_left >= 0){
							game.enemies_array[j].hitpoints_left -= 1;
						} else{
							game.enemies_array[j].pos.x = LEFT_BORDER;
							add_score(enemies_stats_array[enemy.type][SCORE]);
						}
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

}




