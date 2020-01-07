#include "bullet.h"
#include "game.h"
#include "player.h"


void add_bullet(bool player_bullet){ // at the moment only a player can fire
	if(array_bullets_length == array_bullets_allocated){
		array_bullets_allocated += 2;
		game.bullets_array = (Bullet *)realloc(game.bullets_array, sizeof(Bullet) * array_bullets_allocated);
	}
	// is dit correct toevoegen?
	Bullet bullet;
	bullet.x = player.pos.x;
	bullet.y = player.pos.y;
	// player_bullet is boolean
	bullet.player_bullet = 1;

	game.bullets_array[array_bullets_length++] = bullet;

}
void move_bullets(){
	for(uint8_t i = 0; i < array_bullets_length; i++){
		game.bullets_array[i].x += 1;
	}

	//collision detection
	for(uint8_t i = 0; i < array_bullets_length; i++){
		Bullet bullet = game.bullets_array[i];
		for(uint8_t j = 0; j < array_enemies_length; j++){
			Enemy enemy = game.enemies_array[i];
			if(enemy.pos.x == bullet.x && enemy.pos.y == bullet.y){
				game.enemies_array[i].pos.x = LEFT_BORDER;
				game.bullets_array[i].x = RIGHT_BORDER + 1; //move out of field
			}
		}
		clean_enemies_array();
	}

	clean_bullets_array();


}
void clean_bullets_array(){
	for(uint8_t i = 0; i< array_bullets_length; i++){
		//if current bullet can be removed, make array counter
		while(game.bullets_array[i].x > RIGHT_BORDER){

			// if current bullet is the last one in the array
			if(i + 1 == array_bullets_length){

				//make array_length smaller
				array_bullets_length -= 1;
				break;

			} else {
				//else place last bullet on current bullet (to overwrite)
				game.bullets_array[i] = game.bullets_array[--array_bullets_length];
			}
		}

	}

}

