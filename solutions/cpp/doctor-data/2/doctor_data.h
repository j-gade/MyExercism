// doctor_data.h
// Second iteration: add const and references
#pragma once

#include <string>

namespace star_map {

enum class System {
     Sol
    ,AlphaCentauri
    ,BetaHydri
    ,DeltaEridani
    ,EpsilonEridani
    ,Omicron2Eridani
};

} // namespace star_map

namespace heaven {

class Vessel {
    public:
    Vessel(std::string new_name, int new_generation, star_map::System new_system = star_map::System::Sol )
        : name{new_name}, generation{new_generation}, current_system{new_system} {}

    Vessel replicate(std::string new_name) {
        return Vessel{new_name, generation+1};
    }

    void make_buster() {
        ++busters;
        return;
    }

    bool shoot_buster() {
        if (busters > 0) {
            --busters;
            return true;
        }
        return false;
    }
    
    std::string name{};
    int generation{0};
    star_map::System current_system{star_map::System::Sol};
    int busters{0};
};

std::string get_older_bob(Vessel const & vessel_one, Vessel const & vessel_two);
bool in_the_same_system(Vessel const & vessel_one, Vessel const & vessel_two);

} // namespace heaven
