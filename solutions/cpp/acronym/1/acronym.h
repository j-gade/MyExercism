#if !defined(ACRONYM_H)
#define ACRONYM_H

#include <cctype>
#include <string>
#include <string_view>
#include <vector>

namespace acronym {

std::string replace(std::string const& in_string, std::string_view to_find, char to_replace);
std::vector<std::string> split(std::string const & words);
std::string acronym(std::string const & phrase);

}  // namespace acronym

#endif // ACRONYM_H