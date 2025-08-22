#include <string>
#include <vector>

namespace election {

// The election result struct is already created for you:

struct ElectionResult {
    // Name of the candidate
    std::string name{};
    // Number of votes the candidate has
    int votes{};
};

// Task 1
// vote_count takes a reference to an `ElectionResult` as an argument and will
// return the number of votes in the `ElectionResult.
int vote_count(ElectionResult& result) {
    return result.votes;
}

// Task 2
// increment_vote_count takes a reference to an `ElectionResult` as an argument
// and a number of votes (int), and will increment the `ElectionResult` by that
// number of votes.
void increment_vote_count(ElectionResult& result, int vote_count) {
    result.votes += vote_count;
    return;
}

// Task 3
// determine_result receives the reference to a final_count and returns a
// reference to the `ElectionResult` of the new president. It also changes the
// name of the winner by prefixing it with "President". The final count is given
// in the form of a `reference` to `std::vector<ElectionResult>`, a vector with
// `ElectionResults` of all the participating candidates.
ElectionResult& determine_result(std::vector<ElectionResult>& election_results) {
    int most_votes{0};
    size_t winner_index{0};
    for (auto i{0}; i < election_results.size(); ++i) {
        if (election_results[i].votes > most_votes) {
            most_votes = election_results[i].votes;
            winner_index = i;
        }
    }
    election_results[winner_index].name = "President " + election_results[winner_index].name;
    return election_results[winner_index];
}

}  // namespace election