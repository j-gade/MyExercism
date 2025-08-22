#include <math.h>
#include <stdlib.h>

#include "darts.h"

static scoring_t scoring[] = {{1.0F, 10}, {5.0F, 5}, {10.0F, 1}};
static size_t const score_size = sizeof(scoring) / sizeof(scoring[0]);
    
int score(coordinate_t location)
{
    float radius = sqrtf(location.x * location.x + location.y * location.y);

    int points = 0;
    for (size_t i = 0; i < score_size; ++i) {
        if (radius <= scoring[i].radius) {
            points = scoring[i].score;
            break;
        }
    }
    return points;
}