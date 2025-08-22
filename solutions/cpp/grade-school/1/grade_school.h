#if !defined(GRADE_SCHOOL_H)
#define GRADE_SCHOOL_H

#include <map>
#include <string>
#include <vector>

namespace grade_school {

class school {
    public:
    school() {}
    std::map<int, std::vector<std::string> > roster() const;
    void add(std::string const & name, int year);
    std::vector<std::string> grade(int year) const;

    private:
    std::map<int, std::vector<std::string> > m_roster{};
    
};
    
}  // namespace grade_school

#endif // GRADE_SCHOOL_H