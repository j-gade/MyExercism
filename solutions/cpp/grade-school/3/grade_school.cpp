#include <algorithm>

#include "grade_school.h"

namespace grade_school {

void school::add(school::student new_name, int grade)
{
    if (m_roster.empty() || m_roster.find(grade) == m_roster.end()) {
        m_roster[grade].emplace_back(new_name);
        return;
    }

    auto const & name_position = std::lower_bound(m_roster.at(grade).begin(), m_roster.at(grade).end(), new_name);
    m_roster.at(grade).insert(name_position, new_name);
}

school::class_roster const & school::roster() const
{
    return m_roster;
}

namespace {
    school::student_list const & none{};
}

school::student_list const & school::grade(int grade) const
{
    if (m_roster.empty() || m_roster.find(grade) == m_roster.end())
        return none;

    return m_roster.at(grade);
}

}  // namespace grade_school
