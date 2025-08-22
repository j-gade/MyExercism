#include <cctype>
#include "pangram.h"

namespace pangram {
bool is_pangram(std::string text)
{
    char counts[26] = { 0 };
    for (char const& c : text) {
        if (std::isalpha(c))
            counts[std::tolower(c) - 'a']++;
    }
 
    for (int i{ 0 }; i < 26; ++i)
        if (counts[i] == 0)
            return false;
    return true;
}
}  // namespace pangram
