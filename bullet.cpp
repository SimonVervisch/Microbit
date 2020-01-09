#include "bullet.h"
#include "game.h"
#include "player.h"


void add_bullet(uint8_t player_bullet,uint8_t shooter_x, uint8_t shooter_y){ // at the moment only a player can fire
	if(array_bullets_length == array_bullets_allocated){
		array_bullets_allocated += 2;
		game.bullets_array = (Bullet *)realloc(game.bullets_array, sizeof(Bullet) * array_bullets_allocated);
	}
	// is dit correct toevoegen?
	Bullet bullet;
	bullet.player_bullet = player_bullet;
	bullet.x = shooter_x;
	bullet.y = shooter_y;
	// player_bullet is boolean

	game.bullets_array[array_bullets_length++] = bullet;


}
void move_bullets(){

	for(uint8_t i = 0; i < array_bullets_length; i++){
		if(game.bullets_array[i].player_bullet){
			game.bullets_array[i].x += 1;
		} else{
			if(game.bullets_array[i].x == 0){
				game.bullets_array[i].x = RIGHT_BORDER + 1;
				game.bullets_array[i].player_bullet = 1;
			} else{
				game.bullets_array[i].x -= 1;
			}
		}
	}

	//collision detection
	general_collision_detection();



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

