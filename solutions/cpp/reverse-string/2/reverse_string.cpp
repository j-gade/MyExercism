#include "reverse_string.h"

#include <algorithm>

namespace reverse_string {

// This is a standard library approach but before I looked into the "Dig Deeper"
// section https://exercism.org/tracks/cpp/exercises/reverse-string/dig_deeper.
// In that respect, I probably would have used "Direct Construction" approach
// instead of this.

std::string reverse_string(std::string_view original)
{
    if (original.empty())
        return std::string{};

    std::string reversed{ original };
    std::reverse_copy(std::begin(original), std::end(original), std::begin(reversed));
    return reversed;
}

}  // namespace reverse_string
