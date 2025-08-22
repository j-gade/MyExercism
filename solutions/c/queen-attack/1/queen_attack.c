#include <stdlib.h>

#include "queen_attack.h"

attack_status_t can_attack(position_t queen_1, position_t queen_2) {    
    if (!(is_valid_space(queen_1) && is_valid_space(queen_2)) || is_same_space(queen_1, queen_2))
        return INVALID_POSITION;

    if (is_same_row(queen_1, queen_2) || is_same_col(queen_1, queen_2) || is_diagonal(queen_1, queen_2))
        return CAN_ATTACK;

    return CAN_NOT_ATTACK;
}

int is_valid_space(position_t piece) {
    return piece.row < 8 && piece.column < 8;
}

int is_same_row(position_t piece_1, position_t piece_2) {
    return piece_1.row == piece_2.row;
}

int is_same_col(position_t piece_1, position_t piece_2) {
    return piece_1.column == piece_2.column;
}
int is_same_space(position_t piece_1, position_t piece_2) {
    return is_same_row(piece_1, piece_2) && is_same_col(piece_1, piece_2);
}

int is_diagonal(position_t piece_1, position_t piece_2) {
    return (abs(piece_1.row - piece_2.row) == abs(piece_1.column - piece_2.column));
}
