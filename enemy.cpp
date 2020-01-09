#include "enemy.h"
#include "game.h"


void generate_enemy(){
	static uint8_t type_1 = 1;
	if(array_enemies_length == array_enemies_allocated){
		array_enemies_allocated += 2;
		game.enemies_array = (Enemy *)realloc(game.enemies_array, sizeof(Enemy) * array_enemies_allocated);
	}
	Enemy enemy;
	enemy.pos.x = RIGHT_BORDER; 
	enemy.pos.y = rand() % 5;
	if(type_1){
		enemy.type = TYPE1_ENEMY;
		type_1 = 0;
	} else {
		enemy.type = TYPE2_ENEMY;
		type_1 = 1;
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
	for(uint8_t i = 0; i < array_bullets_length; i++){
		Bullet bullet = game.bullets_array[i];
		if(!bullet.player_bullet){
			continue;
		}
		for(uint8_t j = 0; j < array_enemies_length; j++){
			Enemy enemy = game.enemies_array[j];
			if(enemy.pos.x == bullet.x && enemy.pos.y == bullet.y){
				game.enemies_array[j].pos.x = LEFT_BORDER;
				game.bullets_array[i].x = RIGHT_BORDER + 1; //move out of field
				break;
			}
		}
		clean_bullets_array();
		clean_enemies_array();
	}

	for(uint8_t i = 0; i< array_enemies_length; i++){
		if(game.enemies_array[i].pos.x == LEFT_BORDER){
			reset_game();
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

