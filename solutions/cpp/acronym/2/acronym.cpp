#include "acronym.h"
#include <sstream>

namespace acronym {
std::string replace(std::string const& in_string, std::string_view to_find, char to_replace) {
    std::string result = in_string;
    for (char& c : result) {
        if (to_find.find_first_of(c) != std::string_view::npos) {
            c = to_replace;
        }
    }
    return result;
}

std::vector<std::string> split(std::string const & words, char delim) {
    std::vector<std::string> tokens;
    std::string token;
    std::stringstream word_stream(words);
    while (std::getline(word_stream, token, delim)) {
        if (token != "") {
            tokens.push_back(token);
        }
    }
    return tokens;
}

std::string acronym(std::string const & phrase)
{
    std::string words = replace(phrase, "-_", ' ');
    std::vector<std::string> word_list = split(words, ' ');
    std::ostringstream abbreviation;
    for (std::string const& word : word_list) {
        abbreviation.put(std::toupper(word[0]));
    }
    return abbreviation.str();
}
}  // namespace acronym
