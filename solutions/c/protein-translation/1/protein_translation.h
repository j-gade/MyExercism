#ifndef PROTEIN_TRANSLATION_H
#define PROTEIN_TRANSLATION_H

#include <stdbool.h>
#include <stddef.h>

#define MAX_PROTEINS 10

typedef enum {
   UUU, UUG, UUA, UUC, UGU, UGG, UGA, UGC, UAU, UAG, UAA, UAC,
   UCU, UCG, UCA, UCC, AUG = 33, INVALID
} codons_t;

typedef enum {
   Methionine,
   Phenylalanine,
   Leucine,
   Serine,
   Tyrosine,
   Cysteine,
   Tryptophan,
} protein_t;

typedef struct {
   bool valid;
   size_t count;
   protein_t proteins[MAX_PROTEINS];
} proteins_t;

proteins_t proteins(char const * const rna);
codons_t codon(char const * const seq);

#endif
