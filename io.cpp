#include "io.h"
#include "player.h"
#include "game.h"


uint8_t *encode_player(){ // change size 
	uint8_t array[2];
	uint8_t byte_1 = player.y;
	//score is quite big;
	uint8_t byte_2 = game.score;

	byte_1 = byte_1 << 3;
	byte_1 = player.lives;

	array[1] = byte_1;
	array[2] = byte_2;

	return array

	

uint8_t *encode_enemies(Game* game){ // change size key
	uint8_t smallest_length;
	if(array_enemies_length > 15){
		smallest_length = 15;
	} else{
		smallest_length = array_enemies_length;
	}
	// bitshift right for multiplication by 2
	uint8_t array[smallest_length << 1];
	for(uint8_t i = 0; i < smallest_length; i++){
		uint8_t byte_1;
		uint8_t byte_2;
		//boolean to check whether this is the last enemy
		byte_2 = game.enemies_array[i].hitpoints_left;
		byte_2 = byte_2 << 1;

		if(i == smallest_length - 1){
			byte_2 = 1;
		} else {
			byte_2 = 0;
		}

		byte_1 = game.enemies_array[i].x;
		byte_1 = byte_1 << 3;
		byte_1 = game.enemies_array[i].y;

		uint8_t index = i << 1;

		array[index] = byte_1;
		array[index + 1] = byte_2;

	}
}

/*
void encode_game(Game* game){
	// encode player and enemies
}

void decode_player(Player* player){ // change size 

} 

void decode_enemies(Game* game){ // change size key

}

void decode_game(Game* game){
	// encode player and enemies
}
*/
