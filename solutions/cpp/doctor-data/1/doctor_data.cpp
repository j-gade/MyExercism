// doctor_data.cpp
#include <string>

#include "doctor_data.h"

namespace heaven {

std::string get_older_bob(Vessel vessel_one, Vessel vessel_two) {
    return vessel_one.generation < vessel_two.generation ? vessel_one.name : vessel_two.name;
}

bool in_the_same_system(Vessel vessel_one, Vessel vessel_two) {
    return vessel_one.current_system == vessel_two.current_system;
}
    
} // namespace heaven