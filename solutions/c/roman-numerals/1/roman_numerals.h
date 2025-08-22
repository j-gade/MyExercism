#ifndef ROMAN_NUMERALS_H
#define ROMAN_NUMERALS_H

// Buffer large enough to hold the largest roman numeral:
// MMMDCCCLXXXVIII = 3888
#define MAX_ROMAN_CHARS 16

char *to_roman_numeral(unsigned int number);

#endif
