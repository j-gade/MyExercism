#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "reverse_string.h"

char* reverse(char const * value) {
    size_t length = strlen(value);
    char* reversed = (char*)malloc(length + 1);
    assert(reversed != NULL);

    char* temp = reversed;
    while (length-- > 0)
        *reversed++ = *(value + length);
    *reversed = '\0';

    return temp;
}