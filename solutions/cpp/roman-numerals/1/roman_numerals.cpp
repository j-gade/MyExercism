#include "roman_numerals.h"

namespace roman_numerals {

std::string ones[] = {
    "",
    "I",
    "II",
    "III",
    "IV",
    "V",
    "VI",
    "VII",
    "VIII",
    "IX"
};

std::string tens[] = {
    "",
    "X",
    "XX",
    "XXX",
    "XL",
    "L",
    "LX",
    "LXX",
    "LXXX",
    "XC"
};

std::string hundreds[] = {
    "",
    "C",
    "CC",
    "CCC",
    "CD",
    "D",
    "DC",
    "DCC",
    "DCCC",
    "CM"
};

std::string thousands[] = {
    "",
    "M",
    "MM",
    "MMM"
};
    
std::string convert(int arabic) {
    if (arabic <= 0 || arabic > 3999 )
        return "";

    std::string roman = thousands[(arabic / 1000) % 10] + hundreds[(arabic / 100) % 10] + tens[(arabic / 10) % 10] + ones[arabic % 10];
    return roman;
}

}  // namespace roman_numerals
