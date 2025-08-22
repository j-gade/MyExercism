#include "parallel_letter_frequency.h"

#include <cctype>

namespace parallel_letter_frequency {

std::unordered_map<char, int> frequency(std::vector<std::string_view> texts) {
    std::unordered_map<char, int> letter_freq;
    for (auto text : texts) {
        for (auto c : text) {
            if (std::isalpha(c)) {
                letter_freq[std::tolower(c)]++;
            }
        }
    }
    return letter_freq;
}
    
}
