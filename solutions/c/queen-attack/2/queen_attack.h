#ifndef QUEEN_ATTACK_H
#define QUEEN_ATTACK_H

#include <stdbool.h>
#include <stdint.h>

typedef enum { CAN_NOT_ATTACK, CAN_ATTACK, INVALID_POSITION } attack_status_t;

typedef struct {
   uint8_t row;
   uint8_t column;
} position_t;

attack_status_t can_attack(position_t queen_1, position_t queen_2);

bool is_valid_space(position_t piece);
bool is_same_row(position_t piece_1, position_t piece_2);
bool is_same_col(position_t piece_1, position_t piece_2);
bool is_same_space(position_t piece_1, position_t piece_2);
bool is_diagonal(position_t piece_1, position_t piece_2);

#endif
