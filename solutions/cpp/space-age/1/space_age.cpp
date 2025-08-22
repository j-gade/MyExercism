#include "space_age.h"

namespace space_age {

std::int64_t space_age::seconds() const {
    return m_seconds;
}

double space_age::on_mercury() const {
    return m_seconds / mercury_orbital_period;
}

double space_age::on_venus() const {
    return m_seconds / venus_orbital_period;
}

double space_age::on_earth() const {
    return m_seconds / earth_orbital_period;
}

double space_age::on_mars() const {
    return m_seconds / mars_orbital_period;
}

double space_age::on_jupiter() const {
    return m_seconds / jupiter_orbital_period;
}

double space_age::on_saturn() const {
    return m_seconds / saturn_orbital_period;
}

double space_age::on_uranus() const {
    return m_seconds / uranus_orbital_period;
}

double space_age::on_neptune() const {
    return m_seconds / neptune_orbital_period;
}

}  // namespace space_age
