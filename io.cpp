#include "io.h"
#include "game.h"
#define MAX_AMOUNT_ENEMIES 15

// PLAYER-REPRESENTATION: 00YY YLLL - SSSS SSSS -> Y = Y-coordinate, L = lives, S is score
uint8_t * encode_player(){ // change size 
	uint8_t *array_player = (uint8_t *)calloc(2,sizeof(uint8_t));
	uint8_t byte_1 = player.y;
	//score is quite big;
	uint8_t byte_2 = game.score;

	byte_1 = byte_1 << 3;
	byte_1 = player.lives;

	array_player[0] = byte_1;
	array_player[1] = byte_2;
	return array_player;
}
void decode_player(uint8_t *array){ 

	uint8_t y_mask = 	0b00111000; 
	uint8_t lives_mask = 	0b00000111; 
	uint8_t shifted_y = y_mask & array[0];


	player.x = 0;
	// player.y = shifted_y >>3;
	player.lives = lives_mask & array[0];
	game.score = array[1];


} 


//ENEMY-REPRESENTATION - 000T THHH - 0YYY XXXB
uint8_t *encode_enemies(){ // change size key
	uint8_t smallest_length;
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
		byte_1 = smallest_length << 3;
		byte_1 = game.enemies_array[i].hitpoints_left;

		//load in y-pos, then x, then last check
		byte_2 = game.enemies_array[i].pos.y;
		byte_2 = byte_2 << 3;
		byte_2 = game.enemies_array[i].pos.x;
		byte_2 = byte_2 <<1 ;

		if(i == smallest_length - 1){
			byte_2 = 1;
		} else {
			byte_2 = 0;
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
		uint8_t index = i << 1;

		last_enemy = last_enemy_mask & array[index + 1];
		uint8_t y_shifted = y_mask & array[index + 1];
		uint8_t x_shifted = x_mask & array[index + 1];

		uint8_t type_shifted = type_mask & array[index];
		uBit.serial.send("Enemy\r\n");
		uBit.serial.sendChar((y_shifted >>4) + '0');
		uBit.serial.send("\r\n");
		uBit.serial.sendChar((x_shifted >>3) + '0');
		uBit.serial.send("\r\n");

		enemy.pos.y = y_shifted >> 4;
		enemy.pos.x = x_shifted >> 1;
		enemy.type = type_shifted >> 3;
		enemy.hitpoints_left = hitpoints_mask & array[index];
		new_array[i] = enemy;
	}

	//calloc is hier 0
	array_enemies_length = array_enemies_allocated = amount_of_enemies;
	game.enemies_array = (Enemy *)calloc(amount_of_enemies, sizeof(Enemy));

	for(uint8_t i = 0; i< amount_of_enemies; i++){
		game.enemies_array[i] = new_array[i];
	}



}

void encode_game(){
	uint8_t *array_player = encode_player(); 
	uint8_t *array_enemies = encode_enemies(); 

	uint8_t array_total[32] = {0};

	for(uint8_t i = 0; i< 2; i++){
		array_total[i] = array_player[i];
	}
	for(int i = 2; i < 32; i++){
		array_total[i] = array_enemies[i - 2];
	}
	uBit.storage.put("key", array_total, 32);

	free(array_player);
	free(array_enemies);
}


void decode_game(){
	free(game.enemies_array);
	free(game.bullets_array);
	uBit.serial.send("test\r\n");
	KeyValuePair* firstTime = uBit.storage.get("key");

	uBit.serial.send("test\r\n");
	uint8_t *save_data = firstTime->value;

	uBit.serial.send("test\r\n");

	decode_player(save_data);
	uBit.serial.send("test\r\n");
	decode_enemies(save_data);
	uBit.serial.send("test\r\n");
	// delete save_data;
	initialize_after_load();
}
