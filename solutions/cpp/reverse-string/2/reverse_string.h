#if !defined(REVERSE_STRING_H)
#define REVERSE_STRING_H

#include <string>
#include <string_view>

namespace reverse_string {

std::string reverse_string(std::string_view original);

}  // namespace reverse_string

#endif // REVERSE_STRING_H