#include <stdlib.h>

#include "resistor_color.h"

uint16_t color_code(resistor_band_t color)
{
    return (uint16_t) color;
}

resistor_band_t color_list[] = {
     BLACK
    ,BROWN
    ,RED
    ,ORANGE
    ,YELLOW
    ,GREEN
    ,BLUE
    ,VIOLET
    ,GREY
    ,WHITE
};

resistor_band_t* colors() {
    return color_list;
}
