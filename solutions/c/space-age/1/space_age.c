#include "space_age.h"

// List of orbital periods by planet
static float orbital_periods[] = {
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
    if (planet < MERCURY || planet > NEPTUNE || !seconds)
        return -1;

    return (float)seconds / orbital_periods[planet];
}
