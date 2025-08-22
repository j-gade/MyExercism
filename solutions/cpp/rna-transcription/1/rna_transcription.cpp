#include <stdexcept>

#include "rna_transcription.h"

namespace rna_transcription {

char to_rna(char sequence) {
    char rna{0};
    switch (sequence) {
        case 'G':
            rna = 'C';
            break;
        case 'C':
            rna = 'G';
            break;
        case 'T':
            rna = 'A';
            break;
        case 'A':
            rna = 'U';
            break;
        default:
            throw std::invalid_argument("to_rna: not a valid sequence " + std::string(1, sequence));
    }
    return rna;
}

std::string to_rna(std::string_view sequence) {
    std::string rna{};
    for (auto s : sequence)
        rna.push_back(to_rna(s));

    return rna;
}
    
}  // namespace rna_transcription
