#include "protein_translation.h"

namespace protein_translation {

const int codon_length = 3;

std::string const translate_codon(std::string_view codon)
{
    if (codon == "UCU" || codon == "UCC" || codon == "UCA" || codon == "UCG")
        return "Serine";
    else if (codon == "UAA" || codon == "UAG" || codon == "UGA")
        return "STOP";
    else if (codon == "UUU" || codon == "UUC")
        return "Phenylalanine";
    else if (codon == "UUA" || codon == "UUG")
        return "Leucine";
    else if (codon == "UAU" || codon == "UAC")
        return "Tyrosine";
    else if (codon == "UGU" || codon == "UGC")
        return "Cysteine";
    else if (codon == "UGG")
        return "Tryptophan";
    else if (codon == "AUG")
        return "Methionine";
    else return "INVALID";
}
std::vector<std::string> proteins(std::string_view rna)
{
    std::vector<std::string> protein_list;
    if (rna.empty() || rna.size() % 3 != 0)
        return protein_list;

    std::string next_protein;
    for (size_t i = 0; i < rna.size(); i += codon_length) {
        next_protein = translate_codon(rna.substr(i, codon_length));
        if (next_protein == "STOP")
            break;
        if (next_protein == "INVALID") {
            protein_list.clear();
            break;
        }
        protein_list.emplace_back(next_protein);
    }
    return protein_list;
}
}  // namespace protein_translation
