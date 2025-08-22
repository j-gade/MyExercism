#include <array>
#include <string>
#include <vector>

// Round down all provided student scores.
std::vector<int> round_down_scores(std::vector<double> student_scores) {
    std::vector<int> rounded_scores{};
    for (auto score : student_scores)
        rounded_scores.emplace_back(score);
    return rounded_scores;
}


// Count the number of failing students out of the group provided.
int count_failed_students(std::vector<int> student_scores) {
    int count{};
    for (auto score : student_scores)
        if (score <= 40)
            ++count;
    return count;
}

// Determine how many of the provided student scores were 'the best' based on the provided threshold.
std::vector<int> above_threshold(std::vector<int> student_scores, int threshold) {
    std::vector<int> best{};
    for (auto score : student_scores)
        if (score >= threshold)
            best.emplace_back(score);
    return best;
}

// Create a list of grade thresholds based on the provided highest grade.
std::array<int, 4> letter_grades(int highest_score) {
    int interval = (highest_score - 40)/4;
    std::array<int, 4> grades {};
    for (int i = 0; i < 4; ++i)
        grades[i] = 41 + (interval * i);
    return grades;
}

// Organize the student's rank, name, and grade information in ascending order.
std::vector<std::string> student_ranking(std::vector<int> student_scores, std::vector<std::string> student_names) {
    int size = (student_scores.size() <= student_names.size() ? student_scores.size() : student_names.size());
    std::vector<std::string> ranking{};
    for (int i = 0; i < size; ++i) {
        ranking.push_back(std::to_string(i + 1) + ". " + student_names[i] + ": " + std::to_string(student_scores[i]));
    }
    return ranking;
}

// Create a string that contains the name of the first student to make a perfect score on the exam.
std::string perfect_score(std::vector<int> student_scores, std::vector<std::string> student_names) {
    int size = (student_scores.size() <= student_names.size() ? student_scores.size() : student_names.size());
    std::string perfect {};
    for (int i = 0; i < size; ++i)
        if (student_scores[i] == 100) {
            perfect = student_names[i];
            break;
        }
    return perfect;
}
