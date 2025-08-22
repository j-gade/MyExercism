#include "protein_translation.h"

static int const nucleotides[128] = {[0] = -1, ['U'] =  0, ['G'] = 1, ['A'] = 2, ['C'] = 3};

codons_t codon(char const * const seq) {
    codons_t codon = UUU;
    int digit = 16;
    int c;
     for (size_t i = 0; i < 3; ++i) {
        switch (c = seq[i])
        {
        case 'U':
        case 'G':
        case 'A':
        case 'C':
            break;
        
        default:
            return INVALID;
            break;
        }

        codon += nucleotides[c] * digit;
        digit /= 4;
    }

    return codon;
}

proteins_t proteins(char const * const rna) {
    proteins_t proteins = { .valid = true, .count = 0};

    if (!rna) {
        proteins.valid = false;
        return proteins;
    }

    for (size_t i = 0; rna[i] != '\0'; i += 3) {
        codons_t next_codon = codon(rna + i);
        switch (next_codon) {
            case UUU:
            case UUC:
                proteins.proteins[proteins.count++] = Phenylalanine;
                break;
            case UUG:
            case UUA:
                proteins.proteins[proteins.count++] = Leucine;
                break;
            case UGG:
                proteins.proteins[proteins.count++] = Tryptophan;
                break;
            case UGU:
            case UGC:
                proteins.proteins[proteins.count++] = Cysteine;
                break;
            case UAU:
            case UAC:
                proteins.proteins[proteins.count++] = Tyrosine;
                break;
            case UGA:
            case UAG:
            case UAA:
                return proteins;
                break;
            case UCU:
            case UCG:
            case UCA:
            case UCC:
                proteins.proteins[proteins.count++] = Serine;
                break;
            case AUG:
                proteins.proteins[proteins.count++] = Methionine;
                break;
            default:
                proteins.valid = false;
                return proteins;
                break;
        }
    }
    return proteins;
}
