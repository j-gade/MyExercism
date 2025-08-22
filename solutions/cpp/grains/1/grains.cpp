#include "grains.h"

namespace grains {

uint64_t square(unsigned num)
{
    if (num == 0)
        return 0ULL;
    return 1ULL << (num - 1);
}

uint64_t total()
{
    uint64_t sum{ 0ULL };
    for (auto i{ 1 }; i <= 64; ++i)
        sum += square(i);

    return sum;
}
}  // namespace grains
