#include <stdexcept>

#include "triangle.h"

namespace triangle {

std::domain_error side_length_exception{ "triangle: all sides must be greater than zero" };
std::domain_error invalid_triangle_exception{ "triangle: the sum of two sides must be greater or equal to the third side" };

flavor kind(double a, double b, double c) {
    if (a <= 0.0 || b <= 0.0 || c <= 0.0)
        throw side_length_exception;

    if (a + b < c || a + c < b || b + c < a)
        throw invalid_triangle_exception;

    if (a == b && a == c)
        return flavor::equilateral;

    if (a == b || a == c || b == c)
        return flavor::isosceles;

    return flavor::scalene;
}

}  // namespace triangle
