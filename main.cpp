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
void display_bullet(Bullet bullet){

	uBit.display.image.setPixelValue(bullet.pos.x, bullet.pos.y, 255);
}

void space_invaders(){
	player.pos.x = 0;
	player.pos.y = 2;
	uBit.messageBus.listen(MICROBIT_ID_BUTTON_A, MICROBIT_BUTTON_EVT_CLICK, onButtonA);

	while(1){
		uint8_t y = gravity_to_pixel(uBit.accelerometer.getY() >> 7);
		

		uBit.display.image.clear();
		player.pos.y = y;
		uBit.display.image.setPixelValue(player.pos.x, y, 255);
		node_b * bullet_list = game.bullet_list;
		if(bullet_list != NULL){
			display_bullets(bullet_list);
			move_bullet(&bullet_list->bullet);
		}
		uBit.sleep(10);

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





