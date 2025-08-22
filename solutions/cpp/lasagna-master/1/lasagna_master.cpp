#include "lasagna_master.h"

namespace lasagna_master {

int preparationTime(std::vector<std::string> const & layers, int prep_time) {
    return layers.size() * prep_time;
}

amount quantities(std::vector<std::string>const & layers) {
    int const grams_per_noodle_layer{50};
    double const liters_per_sauce_layer{0.2};
    amount total_quantity {};
    for (auto const & layer : layers) {
        if (layer == "noodles")
            total_quantity.noodles += grams_per_noodle_layer;
        else if (layer == "sauce")
            total_quantity.sauce += liters_per_sauce_layer;
    }
    return total_quantity;
}

void addSecretIngredient(std::vector<std::string>& myList, std::vector<std::string> const & otherList) {
    addSecretIngredient(myList, otherList.back());
}

std::vector<double> scaleRecipe(std::vector<double> const & original_quantities, int desired_portions) {
    double const original_scale{2.0};
    double const new_scale = desired_portions / original_scale;
    std::vector<double> new_quantities{};
    for (auto const & quantity : original_quantities)
        new_quantities.emplace_back(quantity * new_scale);
    return new_quantities;
}

void addSecretIngredient(std::vector<std::string>& myList, std::string ingredient) {
    myList.back() = ingredient;
}
    
}  // namespace lasagna_master
