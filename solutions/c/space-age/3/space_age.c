#include "space_age.h"

// List of orbital periods by planet
static float const orbital_periods[] = {
    MERCURY_ORBITAL_PERIOD,
    VENUS_ORBITAL_PERIOD,  
    EARTH_ORBITAL_PERIOD,  
    MARS_ORBITAL_PERIOD,   
    JUPITER_ORBITAL_PERIOD,
    SATURN_ORBITAL_PERIOD, 
    URANUS_ORBITAL_PERIOD, 
    NEPTUNE_ORBITAL_PERIOD
};

float age(planet_t planet, int64_t seconds)
{
    return (planet >= MERCURY && planet <= NEPTUNE && seconds) ?
        (float)seconds / (orbital_periods[planet] * SECONDS_PER_EARTH_YEAR) :
        -1.0F;
}
