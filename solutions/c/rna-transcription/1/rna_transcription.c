#include <stdlib.h>
#include <string.h>

#include "rna_transcription.h"

char *to_rna(const char *dna)
{
    char *rna = (char*)malloc(strlen(dna) + 1);
    if (rna == NULL)
        return NULL;
    
    char *rna_start = rna;
    char n;
    while ((n = *dna++)) {
        switch (n) {
            case    'G' : *rna++ = 'C';
            break;
            case    'C' : *rna++ = 'G';
            break;
            case    'T' : *rna++ = 'A';
            break;
            case    'A' : *rna++ = 'U';
            break;
            default :
                *rna = '\0';
                return rna_start;
        }
    }
    *rna = n;
    return rna_start;
}
