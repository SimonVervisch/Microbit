#include "MicroBit.h"
#include "player.h"
#include "game.h"
#include "io.h"

uint8_t counters_array[TIMINGS_ARRAY_LENGTH];

void onButtonB(MicroBitEvent e){
	add_bullet(1, player.x, player.y);
}
void onButtonA(MicroBitEvent e){
	initialize_new_game();
}

void onButtonALongPress(MicroBitEvent e){
	encode_game();
}
void onButtonBLongPress(MicroBitEvent e){
	decode_game();
}


int check_bullets_movement(){
	if(counters_array[BULLETS] == 1){
		move_bullets();
		counters_array[BULLETS] = BULLETS_COUNTER;
		return 1;
	} else {
		counters_array[BULLETS] -= 1;
		return 0;
	}
}

void draw_bullets(){
	for(uint8_t i = 0; i < array_bullets_length; i++){
		Bullet bullet = game.bullets_array[i];
		uBit.display.image.setPixelValue(bullet.x,bullet.y, 255);
	}
}
int check_enemies_base_rate(){
	if(counters_array[ENEMY_BASE] == 1){
		counters_array[ENEMY_BASE] = ENEMY_BASE_COUNTER;
		return 1;
	} else {
		counters_array[ENEMY_BASE] -= 1;
		return 0;
	}

}

void check_enemies_movement(){
	// START with type_2, because 1 doesn't move
	for(uint8_t type = TYPE2_ENEMY;type<TYPE2_ENEMY + 1; type++){
		if(enemies_stats_array[type][CURRENT_MOVE_COUNTER] == 1){
			// here is the collision detection as well
			move_enemies(type);
			enemies_stats_array[type][CURRENT_MOVE_COUNTER] = enemies_stats_array[type][BASE_MOVE_COUNTER];
		} else {
			enemies_stats_array[type][CURRENT_MOVE_COUNTER] -= 1;
		}

	}


}

void check_enemy_generation(){
	if(counters_array[GENERATE_ENEMY] == 1){
		generate_enemy();
		counters_array[GENERATE_ENEMY] = GENERATE_ENEMY_COUNTER;
	} else {
		counters_array[GENERATE_ENEMY] -= 1;
	}

}

void check_enemy_shoot(){
	if(enemies_stats_array[TYPE1_ENEMY][CURRENT_SHOOT_COUNTER] == 1){

		for(uint8_t i = 0; i < array_enemies_length; i++){
			Enemy enemy = game.enemies_array[i];
			uint8_t counter = enemies_stats_array[enemy.type][SIZE];
			while(counter > 0){
				add_bullet(0, game.enemies_array[i].pos.x,game.enemies_array[i].pos.y + --counter);
			}
		}

		enemies_stats_array[TYPE1_ENEMY][CURRENT_SHOOT_COUNTER] = TYPE1_SHOOT_COUNTER;
	} else {
		enemies_stats_array[TYPE1_ENEMY][CURRENT_SHOOT_COUNTER] -= 1;
	}

}

void draw_enemies(){
	for(uint8_t i = 0; i < array_enemies_length; i++){
		Enemy enemy = game.enemies_array[i];
		uint8_t counter = enemies_stats_array[enemy.type][SIZE];
		while(counter > 0){
			uBit.display.image.setPixelValue(enemy.pos.x,enemy.pos.y + --counter, 255);
		}
	}
}


void space_invaders(){
	uBit.messageBus.listen(MICROBIT_ID_BUTTON_B, MICROBIT_BUTTON_EVT_CLICK, onButtonB);
	uBit.messageBus.listen(MICROBIT_ID_BUTTON_A, MICROBIT_BUTTON_EVT_CLICK, onButtonA);

	uBit.messageBus.listen(MICROBIT_ID_BUTTON_B, MICROBIT_BUTTON_EVT_LONG_CLICK, onButtonBLongPress);
	uBit.messageBus.listen(MICROBIT_ID_BUTTON_A, MICROBIT_BUTTON_EVT_LONG_CLICK, onButtonALongPress);
	player.lives = 3;
	initialize_game();

	srand(time(NULL));
	generate_enemy();

	while(1){
		//divide by 256 or shift 8 to right
		uint8_t y = gravity_to_pixel(uBit.accelerometer.getY() >> 8);

		if(check_bullets_movement()){
			if(check_enemies_base_rate()){
				// check_enemies_movement();
				check_enemy_generation();
				check_enemy_shoot();


			}
		}
		uBit.display.image.clear();
		player.y = y;

		//draw Functions
		uBit.display.image.setPixelValue(player.x, y, 255);
		draw_enemies();
		draw_bullets();
		uBit.sleep(BASE_RATE_TIMING);

	}

}



int main()
{
	// initialise the micro:bit runtime.
	uBit.init();

	//
	// Periodically read the accelerometer x and y values, and plot a 
	// scaled version of this ont the display. 
	//
	space_invaders();
}





