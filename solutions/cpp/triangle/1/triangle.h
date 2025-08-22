#if !defined(TRIANGLE_H)
#define TRIANGLE_H

#include <stdexcept>

namespace triangle {

enum class flavor {
    scalene,
    isosceles,
    equilateral
};

template<typename T, typename U, typename V>
flavor kind(T a, U b, V c) {
    if (a <= 0 || b <= 0 || c <= 0)
        throw std::domain_error("triangle: cannot have side length less or equal to zero");
 
    if ((a + b < c) || (b + c < a) || (a + c < b))
        throw std::domain_error("triangle: the sum of two sides must be greater or equal to the third");
 
    if (a == b && a == c)
        return flavor::equilateral;
 
    if (a == b || a == c || b == c)
        return flavor::isosceles;
 
    return flavor::scalene;
}

}  // namespace triangle

#endif // TRIANGLE_H