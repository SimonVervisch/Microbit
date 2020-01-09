#include "io.h"
#include "player.h"
#include "game.h"
#define MAX_AMOUNT_ENEMIES 15

// PLAYER-REPRESENTATION: 00YY YLLL - SSSS SSSS -> Y = Y-coordinate, L = lives, S is score
void encode_player(uint8_t **array_player){ // change size 
	*array_player = (uint8_t *)calloc(2,sizeof(uint8_t));
	array_player = (uint8_t **)calloc(1,sizeof(uint8_t*));
	uint8_t byte_1 = player.y;
	//score is quite big;
	uint8_t byte_2 = game.score;

	byte_1 = byte_1 << 3;
	byte_1 = player.lives;

	*array_player[0] = byte_1;
	*array_player[1] = byte_2;
}

	
//ENEMY Representation - 
void encode_enemies(uint8_t **array_enemies){ // change size key
	uint8_t smallest_length;
	if(array_enemies_length > MAX_AMOUNT_ENEMIES){
		smallest_length = MAX_AMOUNT_ENEMIES;
	} else{
		smallest_length = array_enemies_length;
	}
	// bitshift right for multiplication by 2
	*array_enemies = (uint8_t *)calloc(smallest_length <<2, sizeof(uint8_t));
	array_enemies = (uint8_t **)calloc(1, sizeof(uint8_t *));
	for(uint8_t i = 0; i < smallest_length; i++){
		uint8_t byte_1, byte_2;
		//boolean to check whether this is the last enemy
		byte_1 = smallest_length << 3;
		byte_1 = game.enemies_array[i].hitpoints_left;
		byte_1 = byte_1 << 1;

		if(i == smallest_length - 1){
			byte_2 = 1;
		} else {
			byte_2 = 0;
		}

		byte_2 = game.enemies_array[i].pos.x;
		byte_2 = byte_2 << 3;
		byte_2 = game.enemies_array[i].pos.y;

		uint8_t index = i << 1;

		*array_enemies[index] = byte_1;
		*array_enemies[index + 1] = byte_2;
	}
}

void encode_game(){
	uint8_t *array_1= {0 }; 
	uint8_t *array_2; 
	encode_player(&array_1);
	encode_enemies(&array_2);

	uint8_t array_total[32] = {0};

	for(uint8_t i = 0; i< 2; i++){
		array_total[i] = array_1[i];
	}
	for(int i = 2; i < 32; i++){
		array_total[i] = array_2[i - 2];
	}

	free(&array_2);
	free(&array_1);
	free(array_1);
	free(array_2);
}

// PLAYER-REPRESENTATION: 00YY YLLL - SSSS SSSS -> Y = Y-coordinate, L = lives, S is score
void decode_player(uint8_t *array){ 

	uint8_t y_mask = 	0b00111000; 
	uint8_t lives_mask = 	0b00000111; 
	uint8_t shifted_y = y_mask & array[0];


	player.x = 0;
	player.y = shifted_y >>3;
	player.lives = lives_mask & array[0];
	game.score = array[1];
	

} 
//ENEMY-REPRESENTATION - 000T THHH - 0YYY XXXB
// -> H = Hitpoints left, B = BOOLEAN last in array, Y = y-coordinat, X = x-coordinate
// -> L = Length total array (only encoded in first enemy);
void decode_enemies(uint8_t *array){ 
	uint8_t last_enemy = 0;

	uint8_t type_mask = 		0b00011000;
	uint8_t hitpoints_mask = 	0b00000111;
	uint8_t last_enemy_mask = 	0b00000001;
	uint8_t y_mask = 		0b01110000; 
	uint8_t x_mask = 		0b00001110; 
	uint8_t amount_of_enemies = 	0;
	Enemy new_array[MAX_AMOUNT_ENEMIES];  
	

	for(uint8_t i = 0; !last_enemy; i++){
		amount_of_enemies += 1;
		Enemy enemy;
		uint8_t index = i << 1;

		last_enemy = last_enemy_mask & array[index + 1];

		uint8_t type_shifted = type_mask & array[index];
		uint8_t y_shifted = y_mask & array[index + 1];
		uint8_t x_shifted = x_mask & array[index + 1];

		enemy.pos.y = y_shifted >> 5;
		enemy.pos.x = x_shifted >> 1;
		enemy.type = type_shifted >> 4;
		enemy.hitpoints_left = hitpoints_mask & array[index];
		new_array[i] = enemy;
	}

	array_enemies_length = array_bullets_allocated = amount_of_enemies;
	game.enemies_array = (Enemy *)calloc(amount_of_enemies, sizeof(Enemy));

	for(uint8_t i = 0; i< amount_of_enemies; i++){
		game.enemies_array[i] = new_array[i];
	}

	

}

void decode_game(){
	free(game.enemies_array);
	free(game.bullets_array);
	// decode_player(/**/);
	// decode_enemies(/**/);
	// initialize_after_load();
}
