

#ifndef ENROLLEDSTUDENT_H
#define ENROLLEDSTUDENT_H

#include "Student.h"
#include <map>

class EnrolledStudent : public Student
{
    friend std::ostream& operator<<(std::ostream& out, const EnrolledStudent& s1);

public:
    EnrolledStudent();
    EnrolledStudent(const std::string& lName, const std::string& fName);
    void addClass(const std::string& className, const double classGrade);
    double getGPA() const;
    bool operator<(const EnrolledStudent& s2) const;

private:
    std::map<std::string, double> courses;
};

#endif