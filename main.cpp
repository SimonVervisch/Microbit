#include "MicroBit.h"
#include "player.h"
#include "game.h"

void onButtonA(MicroBitEvent e){
	add_bullet(true);
}



// scheid input, logica en display
// Dus BUTTONS
// CHECK
// DISPLAY
//
bool check_bullet_movement(){
	if(timings_array[BULLETS_INDEX] == 0){
		move_and_clean_bullets();
		timings_array[BULLETS_INDEX] = BULLETS_COUNTER;
	} else {
		timings_array[BULLETS_INDEX] -= 1;
	}
}


void space_invaders(){
	player.pos.x = 0;
	player.pos.y = 2;
	uBit.messageBus.listen(MICROBIT_ID_BUTTON_A, MICROBIT_BUTTON_EVT_CLICK, onButtonA);

	while(1){
		//divide by 256 or shift 7 to right
		uint8_t y = gravity_to_pixel(uBit.accelerometer.getY() >> 7);

		check_bullet_movement(game->bullet_array);
		uBit.display.image.clear();
		player.pos.y = y;
		uBit.display.image.setPixelValue(player.pos.x, y, 255);
		node_t * bullet_list = game.bullet_list;
		if(bullet_list != NULL){
			display_bullets(bullet_list);
			move_bullet(&bullet_list->bullet);
		}
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





