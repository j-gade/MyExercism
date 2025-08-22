#if !defined(PROTEIN_TRANSLATION_H)
#define PROTEIN_TRANSLATION_H

#include <unordered_map>
#include <string>
#include <string_view>
#include <vector>

namespace protein_translation {

std::string const translate_codon(std::string_view codon);

std::vector<std::string> proteins(std::string_view rna);

}  // namespace protein_translation

#endif // PROTEIN_TRANSLATION_H
