#include "io.h"
#include "game.h"
#define MAX_AMOUNT_ENEMIES 15
/**
 * These functions are larger than normal. This is to keep oversight and to see everything on one page
 */


// PLAYER-REPRESENTATION: 00YY YLLL - SSSS SSSS -> Y = Y-coordinate, L = lives, S is score
uint8_t * encode_player(){ 
	uint8_t *array_player = (uint8_t *)calloc(2,sizeof(uint8_t));
	// add y-coordinate and lives
	uint8_t byte_1 = player.y;
	byte_1 = byte_1 << 3;
	byte_1 = byte_1 |  player.lives;
	//score is quite big;
	uint8_t byte_2 = game.score;


	array_player[0] = byte_1;
	array_player[1] = byte_2;
	return array_player;
}
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
uint8_t *encode_enemies(){ 
	uint8_t smallest_length;
	//Boolean to check that it won't be bigger than 15 (maximum of enemies encoded)
	if(array_enemies_length > MAX_AMOUNT_ENEMIES){
		smallest_length = MAX_AMOUNT_ENEMIES;
	} else{
		smallest_length = array_enemies_length;
	}
	// bitshift right for multiplication by 2
	uint8_t *array_enemies = (uint8_t *)calloc(smallest_length <<1, sizeof(uint8_t));
	for(uint8_t i = 0; i < smallest_length; i++){
		uint8_t byte_1, byte_2;
		//load in type and then Hitpoints_left
		byte_1 = game.enemies_array[i].type;
		byte_1 = byte_1 << 3;
		byte_1 = byte_1 | game.enemies_array[i].hitpoints_left;

		//load in y-pos, then x, then last check
		byte_2 = game.enemies_array[i].pos.y;
		byte_2 = byte_2 << 3;
		byte_2 = byte_2 | game.enemies_array[i].pos.x;
		byte_2 = byte_2 <<1 ;

		//This is a boolean to check whether this is the last enemy in the row
		if(i == smallest_length - 1){
			byte_2 = byte_2 | 1;
		} else {
			byte_2 = byte_2 | 0;
		}

		uint8_t index = i << 1;

		array_enemies[index] = byte_1;
		array_enemies[index + 1] = byte_2;
	}

	return array_enemies;
}
//ENEMY-REPRESENTATION - 000T THHH - 0YYY XXXB
// -> H = Hitpoints left, B = BOOLEAN last in array, Y = y-coordinate, X = x-coordinate
void decode_enemies(uint8_t *array){ 
	//Boolean that checks if the last enemy was in the array
	uint8_t last_enemy = 0;

	uint8_t type_mask = 		0b00011000;
	uint8_t hitpoints_mask = 	0b00000111;
	uint8_t y_mask = 		0b01110000; 
	uint8_t x_mask = 		0b00001110; 
	uint8_t last_enemy_mask = 	0b00000001;
	uint8_t amount_of_enemies = 	0;
	Enemy new_array[MAX_AMOUNT_ENEMIES];  


	for(uint8_t i = 0; !last_enemy; i++){
		amount_of_enemies += 1;
		Enemy enemy;
		uint8_t index = (i << 1) +2;

		//Extract data from first byte
		last_enemy = last_enemy_mask & array[index + 1];
		uint8_t y_shifted = y_mask & array[index + 1];
		uint8_t x_shifted = x_mask & array[index + 1];

		//Extract data from second byte
		uint8_t type_shifted = type_mask & array[index];

		enemy.pos.y = y_shifted >> 4;
		enemy.pos.x = x_shifted >> 1;
		enemy.type = type_shifted >> 3;
		enemy.hitpoints_left = hitpoints_mask & array[index];
		
		//Store this freshly made enemy in an array
		new_array[i] = enemy;
	}

	//allocate the enemies array again
	array_enemies_length = array_enemies_allocated = amount_of_enemies;
	game.enemies_array = (Enemy *)calloc(amount_of_enemies, sizeof(Enemy));

	//transfer this array data to freshly allocated enemies_array
	for(uint8_t i = 0; i< amount_of_enemies; i++){
		game.enemies_array[i] = new_array[i];
	}



}

void encode_game(){
	//makes two arrays and fills them
	uint8_t *array_player = encode_player(); 
	uint8_t *array_enemies = encode_enemies(); 

	//Then fill total array
	uint8_t array_total[32] = {0};
	
	for(uint8_t i = 0; i< 2; i++){
		array_total[i] = array_player[i];
	}
	for(int i = 2; i < 32; i++){
		array_total[i] = array_enemies[i - 2];
	}

	//Store array in memory
	uBit.storage.put("key", array_total, 32);

	free(array_player);
	free(array_enemies);
}


void decode_game(){
	free(game.enemies_array);
	free(game.bullets_array);
	KeyValuePair* firstTime = uBit.storage.get("key");

	uint8_t *save_data = firstTime->value;

	decode_player(save_data);
	decode_enemies(save_data);
	initialize_after_load();
}
