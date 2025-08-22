#include <cmath>
#include <stdexcept>
#include <vector>

#include "nth_prime.h"

namespace nth_prime {

// First 10 primes, '1' is a placeholder.
static std::vector<unsigned int> primes{ 1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 };

unsigned int nth(unsigned int n)
{
    if (n < 1)
        throw std::domain_error("nth: n needs to be greater than 0");

    if (n < primes.size())
        return primes[n];

    // Find more primes
    for (unsigned int current_n{ 10 }; current_n < n; ++current_n) {
        unsigned int prime_candidate{ primes.back() + 2};
        for (; !is_prime(prime_candidate); prime_candidate += 2);
        primes.emplace_back(prime_candidate);
    }

    return primes.back();

}

bool is_prime(unsigned int n)
{
    unsigned int root{ static_cast<unsigned int>(std::sqrt(n)) };
    for (size_t i{ 1 }; i < primes.size() && primes[i] <= root; ++i) {
        if (!(n % primes[i]))
            return false;
    }
    return true;
}

}  // namespace nth_prime
