#if !defined(TRIANGLE_H)
#define TRIANGLE_H

namespace triangle {

enum class flavor {
    scalene,
    isosceles,
    equilateral
};

flavor kind(double a, double b, double c);

}  // namespace triangle

#endif // TRIANGLE_H