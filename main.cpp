#include "MicroBit.h"
#include "player.h"
#include "game.h"

uint8_t timings_array[TIMINGS_ARRAY_LENGTH];


void onButtonA(MicroBitEvent e){
	add_bullet(1);
}

// scheid input, logica en display
// Dus BUTTONS
// CHECK
// DISPLAY
//
int check_bullets_movement(){
	if(timings_array[BULLETS] == 0){
		move_and_clean_bullets();
		timings_array[BULLETS] = BULLETS_COUNTER;
		return 1;
	} else {
		timings_array[BULLETS] -= 1;
		return 0;
	}
}

void draw_bullets(){
	for(uint8_t i = 0; i < array_bullets_length; i++){
		Bullet bullet = game.bullets_array[i];
		uBit.display.image.setPixelValue(bullet.x,bullet.y, 255);
	}
}

int check_enemies_movement(){
	if(timings_array[TYPE1_MOVE] == 0){
		move_and_clean_enemies();
		timings_array[TYPE1_MOVE] = TYPE1_MOVE_COUNTER;
		return 1;
	} else {
		timings_array[TYPE1_MOVE] -= 1;
		return 0;
	}

}

void check_enemy_generation(){
	if(timings_array[GENERATE_ENEMY] == 0){
		generate_enemy();
		timings_array[GENERATE_ENEMY] = GENERATE_ENEMY_COUNTER;
	} else {
		timings_array[GENERATE_ENEMY] -= 1;
	}

}

void draw_enemies(){
	for(uint8_t i = 0; i < array_enemies_length; i++){
		Enemy enemy = game.enemies_array[i];
		uBit.display.image.setPixelValue(enemy.pos.x,enemy.pos.y, 255);
	}
}


void space_invaders(){
	player.pos.x = 0;
	player.pos.y = 2;
	uBit.messageBus.listen(MICROBIT_ID_BUTTON_A, MICROBIT_BUTTON_EVT_CLICK, onButtonA);
	initialize_game();

	srand(time(NULL));

	while(1){
		//divide by 256 or shift 7 to right
		uint8_t y = gravity_to_pixel(uBit.accelerometer.getY() >> 7);

		if(check_bullets_movement()){
			if(check_enemies_movement()){
				check_enemy_generation();
			}

		}
		uBit.display.image.clear();
		player.pos.y = y;
		//draw Functions
		uBit.display.image.setPixelValue(player.pos.x, y, 255);
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





