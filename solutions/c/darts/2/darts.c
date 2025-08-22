#include <math.h>
#include <stdlib.h>

#include "darts.h"

static scoring_t scoring[] = {{1.0F, 10}, {5.0F, 5}, {10.0F, 1}};
static size_t const scoring_size = sizeof(scoring) / sizeof(scoring[0]);
    
uint8_t score(coordinate_t location)
{
    float radius = hypot(location.x, location.y);

    int points = 0;
    for (size_t i = 0; i < scoring_size; ++i) {
        if (radius <= scoring[i].radius) {
            points = scoring[i].score;
            break;
        }
    }
    return points;
}