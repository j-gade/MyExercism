#ifndef SPACE_AGE_H
#define SPACE_AGE_H

#include <stdint.h>

#define SECONDS_PER_EARTH_YEAR   (31557600.0F)
#define MERCURY_ORBITAL_PERIOD   (0.2408467F)
#define VENUS_ORBITAL_PERIOD     (0.61519726F)
#define EARTH_ORBITAL_PERIOD     (1.0F)
#define MARS_ORBITAL_PERIOD      (1.8808158F)
#define JUPITER_ORBITAL_PERIOD   (11.862615F)
#define SATURN_ORBITAL_PERIOD    (29.447498F)
#define URANUS_ORBITAL_PERIOD    (84.016846F)
#define NEPTUNE_ORBITAL_PERIOD   (164.79132F)

typedef enum planet {
   MERCURY,
   VENUS,
   EARTH,
   MARS,
   JUPITER,
   SATURN,
   URANUS,
   NEPTUNE,
} planet_t;

float age(planet_t planet, int64_t seconds);

#endif
