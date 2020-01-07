#include "enemy.h"
#include "game.h"

void generate_enemy(){
	if(array_enemies_length == array_enemies_allocated){
		array_enemies_allocated += 2;
		game.enemies_array = (Enemy *)realloc(game.enemies_array, sizeof(Enemy) * array_enemies_allocated);
	}
	// is dit correct toevoegen?
	Enemy enemy;
	enemy.pos.x = rand() % 5; //generate random number between 0 - 4
	enemy.pos.y = 4; //this is the rightmost pixel 
	enemy.type = TYPE_1_ENEMY;
	game.enemies_array[array_enemies_length++] = enemy;
	array_enemies_length += 1;

}

void move_enemies(){
	for(uint8_t i = 0; i < array_enemies_length; i++){
        game.enemies_array[i].x += 1;
}
for(uint8_t i = 0; i< array_enemies_length; i++){
        //if current enemies can be removed, make array counter
        while(game.enemies_array[i].x > RIGHT_BORDER){
                // if current bullet is the last one in the array
                if(i + 1 == array_enemies_length){
                        //make array_length smaller
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
