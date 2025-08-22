#include <ctype.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

#include "pangram.h"

bool is_pangram(char const *sentence) {
    if (sentence == NULL)
        return false;
    
    char c;
    int counts[26] = { 0 };
    while ((c = *sentence++)) {
        if (isalpha(c))
            counts[tolower(c) - 'a']++;
    }

    for (size_t i = 0; i < 26; ++i)
        if (!counts[i])
            return false;

    return true;
}
