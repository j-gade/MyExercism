#include <stdio.h>
#include <strings.h>
#include "raindrops.h"

void convert(char result[], int drops) {
    int divisible_by_3 = !(drops % 3);
    int divisible_by_5 = !(drops % 5);
    int divisible_by_7 = !(drops % 7);

    if (!(divisible_by_3 || divisible_by_5 || divisible_by_7)) {
        sprintf(result, "%d", drops);
        return;
    }

    char* curpos = result;
    int n = 0;
    if (divisible_by_3) {
        n = sprintf(curpos, "%s", "Pling");
        if (n <= 0)
            return;
    }
    if (divisible_by_5) {
        curpos += n;
        n = sprintf(curpos, "%s", "Plang");
        if (n <= 0)
            return;
    }
    if (divisible_by_7) {
        curpos += n;
        n = sprintf(curpos, "%s", "Plong");
    }
}