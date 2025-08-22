#include <stdexcept>

#include "collatz_conjecture.h"

namespace collatz_conjecture {

int steps(int x) {
    if (x < 1)
        throw std::domain_error("steps: x must be greater than 0");

    int step_count{0};
    while (x != 1) {
        x = (x % 2) ? (3 * x + 1) : (x / 2);
        ++step_count;
    }
    return step_count;
}
    
}  // namespace collatz_conjecture
