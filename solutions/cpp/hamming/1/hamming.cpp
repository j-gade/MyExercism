#include <stdexcept>

#include "hamming.h"

namespace hamming {

int compute(std::string const & first_seq, std::string const & second_seq) {
    if (first_seq.length() != second_seq.length())
        throw std::domain_error("Sequences must be the same length");

    if (first_seq == second_seq)
        return 0;

    int hamming{0};
    for (size_t i{0}; i < first_seq.size(); ++i) {
        if (first_seq[i] != second_seq[i])
            ++hamming;
        }

        return hamming;

    }
}  // namespace hamming
