#include "MicroBit.h"
#include "player.h"

MicroBit uBit;
Player player;

void space_invaders(){
	player.pos.x = 0;
	player.pos.y = 2;

	while(1){
		uint8_t y = gravity_to_pixel(uBit.accelerometer.getY() / 256);

		uBit.display.image.clear();
		uBit.display.image.setPixelValue(player.pos.x, y, 255);
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





