#include "enemy.h"
#include "game.h"

void generate_enemy(){
	if(array_enemies_length == array_enemies_allocated){
		array_enemies_allocated += 2;
		game.enemies_array = (Enemy *)realloc(game.enemies_array, sizeof(Enemy) * array_enemies_allocated);
	}
	// is dit correct toevoegen?
	Enemy enemy;
	enemy.pos.x = RIGHT_BORDER; 
	enemy.pos.y = rand() % 5; 
	enemy.type = TYPE_1_ENEMY;
	game.enemies_array[array_enemies_length++] = enemy;
	array_enemies_length += 1;

}

void move_and_clean_enemies(){
	for(uint8_t i = 0; i < array_enemies_length; i++){
		if(game.enemies_array[i].pos.x == 0){
			game.enemies_array[i].pos.x = LEFT_BORDER;
		} else {
			game.enemies_array[i].pos.x -= 1;
		}
	}
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
/*

   void can_shoot_again(Enemy* enemy){
   static uint8_t shoot-ratio;
   }

   bool can_be_drawn(){
// check if not too big
}

bool moves_out_screen(){

}
*/
