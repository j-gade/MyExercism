#ifndef DARTS_H
#define DARTS_H

#include <stdint.h>

typedef struct {
    float x;
    float y;
} coordinate_t;

typedef struct {
    float radius;
    int score;
} scoring_t;

uint8_t score(coordinate_t location);

#endif
