#ifndef DARTS_H
#define DARTS_H

typedef struct {
    float x;
    float y;
} coordinate_t;

typedef struct {
    float radius;
    int score;
} scoring_t;

int score(coordinate_t location);

#endif
