#include "player.h"

uint8_t gravity_to_pixel(int8_t value){
    uint8_t x = 0;
    uint8_t first = 1;
    uint8_t second = 2; 


    if (value > second * -1)
        x++;
    if (value > first * -1)
        x++;
    if (value > first) // fix calibratie
        x++;
    if (value > second)
        x++;
    return x;
}

