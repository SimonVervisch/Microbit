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
void move_and_clean_bullets(){
	for(uint8_t i = 0; i < array_bullets_length; i++){
		game.bullets_array[i].x += 1;
	}

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

