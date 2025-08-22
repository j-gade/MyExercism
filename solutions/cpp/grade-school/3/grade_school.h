#if !defined(GRADE_SCHOOL_H)
#define GRADE_SCHOOL_H

#include <map>
#include <string>
#include <vector>

namespace grade_school {

class school {

public:
    using student = std::string;
    using student_list = std::vector<student>;
    using class_roster = std::map<int, student_list>;

    void add(student new_name, int grade);
    class_roster const & roster() const;
    student_list const & grade(int grade) const;

private:
    class_roster m_roster{};

};
    
}  // namespace grade_school

#endif // GRADE_SCHOOL_H