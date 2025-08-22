#include <stdlib.h>

#include "roman_numerals.h"

char *to_roman_numeral(unsigned int number) {
    if (number <= 0 || number > 3999)
        return NULL;

    char* roman = (char*)malloc(MAX_ROMAN_CHARS);
    if (roman == NULL)
        return NULL;

    int i = 0;
    unsigned int factor = 1000;
    while (number >= factor) {
        roman[i++] = 'M';
        number -= factor;
    }

    factor = 900;
    while (number >= factor) {
        roman[i++] = 'C';
        roman[i++] = 'M';
        number -= factor;
    }

    factor = 500;
    while (number >= factor) {
        roman[i++] = 'D';
        number -= factor;
    }

    factor = 400;
    while (number >= factor) {
        roman[i++] = 'C';
        roman[i++] = 'D';
        number -= factor;
    }

    factor = 100;
    while (number >= factor) {
        roman[i++] = 'C';
        number -= factor;
    }

    factor = 90;
    while (number >= factor) {
        roman[i++] = 'X';
        roman[i++] = 'C';
        number -= factor;
    }

    factor = 50;
    while (number >= factor) {
        roman[i++] = 'L';
        number-= factor;
    }

    factor = 40;
    while (number >= factor) {
        roman[i++] = 'X';
        roman[i++] = 'L';
        number -= factor;
    }

    factor = 10;
    while (number >= factor) {
        roman[i++] = 'X';
        number -= factor;
    }

    factor = 9;
    while (number >= factor) {
        roman[i++] = 'I';
        roman[i++] = 'X';
        number -= factor;
    }

    factor = 5;
    while (number >= factor) {
        roman[i++] = 'V';
        number -= factor;
    }

    factor = 4;
    while (number >= factor) {
        roman[i++] = 'I';
        roman[i++] = 'V';
        number -= factor;
    }

    factor = 1;
    while (number >= factor) {
        roman[i++] = 'I';
        number -= factor;
    }

    roman[i] = '\0';
    return roman;
    
}