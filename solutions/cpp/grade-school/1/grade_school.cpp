#include <algorithm>

#include "grade_school.h"

namespace grade_school {

void school::add(std::string const & name, int year) {
    m_roster[year].emplace_back(name);
    std::sort(m_roster.at(year).begin(), m_roster.at(year).end());
}

std::map<int, std::vector<std::string> > school::roster() const {
    return m_roster;
}

std::vector<std::string> school::grade(int year) const {
    if (m_roster.empty())
        return std::vector<std::string> {};

    return m_roster.at(year);
}
    
}  // namespace grade_school
