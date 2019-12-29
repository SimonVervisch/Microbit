#include "MicroBit.h"
#include "player.h"
#include "game.h"

void onButtonA(MicroBitEvent e){
	add_bullet(true);
}


void space_invaders(){
	player.pos.x = 0;
	player.pos.y = 2;
	uBit.messageBus.listen(MICROBIT_ID_BUTTON_A, MICROBIT_BUTTON_EVT_CLICK, onButtonA);

	while(1){
		uint8_t y = gravity_to_pixel(uBit.accelerometer.getY() / 256);

//		uBit.display.image.clear();
		//uBit.display.image.setPixelValue(player.pos.x, y, 255);
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





