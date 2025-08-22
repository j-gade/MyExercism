#include "reverse_string.h"

#include <algorithm>

namespace reverse_string {

std::string reverse_string(std::string_view string)
{
    std::string reversed{ string };
    std::reverse_copy(std::begin(string), std::end(string), std::begin(reversed));
    return reversed;
}

}  // namespace reverse_string
