#include "bullet.h"
#include "game.h"
#include "player.h"


void add_bullet(bool player_bullet){ // at the moment only a player can fire



}
#define RIGHT_BORDER 4
void move_and_clean_bullets(){
	for(uint8_t i = 0; i < array_bullets_length; i++){
		game->bullet_array[i].pos.x += 1;
	}
	for(uint8_t i = 0; i< array_bullets_length; i++){
		//if current bullet can be removed, make array counter
		while(game->bullet_array[i].pos.x > RIGHT_BORDER){
			if(i + 1 == array_bullets_length){
				array_bullets_length -= 1;
			} else {
				game->bullets_array[i] = game->bullets_array[--array_bullets_length];
			}
		}

	}
}

void remove_bullet(){
	//pop_node_e

}
