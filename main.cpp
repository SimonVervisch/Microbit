/*
The MIT License (MIT)

copyright (c) 2016 british broadcasting corporation.
this software is provided by lancaster university by arrangement with the bbc.

permission is hereby granted, free of charge, to any person obtaining a
copy of this software and associated documentation files (the "software"),
to deal in the software without restriction, including without limitation
the rights to use, copy, modify, merge, publish, distribute, sublicense,
and/or sell copies of the software, and to permit persons to whom the
software is furnished to do so, subject to the following conditions:

the above copyright notice and this permission notice shall be included in
all copies or substantial portions of the software.

the software is provided "as is", without warranty of any kind, express or
implied, including but not limited to the warranties of merchantability,
fitness for a particular purpose and noninfringement. in no event shall
the authors or copyright holders be liable for any claim, damages or other
liability, whether in an action of contract, tort or otherwise, arising
from, out of or in connection with the software or the use or other
dealings in the software.
*/

#include "MicroBit.h"
#include "player.h"

MicroBit uBit;
Player player;
/*
int gravity_to_pixel(int value){
    uint8_t x = 0;
    uint8_t first = 1;
    uint8_t second = 2; 


    if (value > second * -1)
        x++;
    if (value > first * -1)
        x++;
    if (value > first)
        x++;
    if (value > second)
        x++;
    return x;
}
*/

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





