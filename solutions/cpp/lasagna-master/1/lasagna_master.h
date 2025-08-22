#pragma once
#include <string>
#include <vector>

namespace lasagna_master {

struct amount {
    int noodles;
    double sauce;
};

// Task 1: Estimate the preparation time
int preparationTime(std::vector<std::string> const & layers, int prep_time = 2);

// Task 2: Compute the amounts of noodles and sauce needed
amount quantities(std::vector<std::string>const & layers);

// Task 3: Add the secret ingredient
void addSecretIngredient(std::vector<std::string>& myList, std::vector<std::string> const & otherList);

// Task 4: Scale the recipe
std::vector<double> scaleRecipe(std::vector<double> const & quantities_for_two, int desired_portions);

// Task 5: Unlock the Family Secret
void addSecretIngredient(std::vector<std::string>& myList, std::string ingredient);

}  // namespace lasagna_master
