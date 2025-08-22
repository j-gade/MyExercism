#include "collatz_conjecture.h"

int steps(int start) {
    if (start < 1) {
        return ERROR_VALUE;
    }

    int steps = 0;
    while (start != 1) {
        start = (start % 2) ? (3 * start + 1) : (start / 2);
        ++steps;
    }
    return steps;
}