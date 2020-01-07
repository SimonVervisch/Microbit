#include "MicroBit.h"
#include "player.h"
#include "game.h"

uint8_t timings_array[TIMINGS_ARRAY_LENGTH];


void onButtonA(MicroBitEvent e){
	add_bullet(true);
}

// scheid input, logica en display
// Dus BUTTONS
// CHECK
// DISPLAY
//
void check_bullet_movement(){
	if(timings_array[BULLETS] == 0){
		move_and_clean_bullets();
		timings_array[BULLETS] = BULLETS_COUNTER;
	} else {
		timings_array[BULLETS] -= 1;
	}
}

void draw_bullets(){
	for(uint8_t i = 0; i < array_bullets_length; i++){
		Bullet bullet = game.bullet_array[i];
		uBit.display.image.setPixelValue(bullet.x,bullet.y, 255);
	}
}


void space_invaders(){
	player.pos.x = 0;
	player.pos.y = 2;
	uBit.messageBus.listen(MICROBIT_ID_BUTTON_A, MICROBIT_BUTTON_EVT_CLICK, onButtonA);
	initialize_game();

	while(1){
		//divide by 256 or shift 7 to right
		uint8_t y = gravity_to_pixel(uBit.accelerometer.getY() >> 7);

		check_bullet_movement();
		uBit.display.image.clear();
		player.pos.y = y;
		//draw Functions
		uBit.display.image.setPixelValue(player.pos.x, y, 255);
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





