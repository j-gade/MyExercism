#include "grains.h"

uint64_t square(uint8_t index)
{
    if (index < 1 || index > 64)
        return 0ULL;
    return 1ULL << (index - 1);
}

uint64_t total(void)
{
    return 0ULL - 1;
}
