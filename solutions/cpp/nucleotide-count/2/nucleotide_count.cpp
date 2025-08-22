#include <stdexcept>

#include "nucleotide_count.h"

namespace nucleotide_count {

std::map<char, int> count(std::string_view sequence)
{
    std::map<char, int> nucleotides{ {'A', 0 }, {'C', 0}, {'G', 0}, {'T', 0} };

    for (auto c : sequence) {
        auto n = nucleotides.find(c);
        if (n == nucleotides.end())
            throw std::invalid_argument("count: invalid nucleotide");
        n->second++;
    }

    return nucleotides;
}

}  // namespace nucleotide_count
