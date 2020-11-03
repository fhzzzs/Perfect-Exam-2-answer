/*
	Ivan Ao

	October 21, 2020

	CS A250
	Programming Exam 2
*/

#include "EnrolledStudent.h"
#include <iomanip>

using namespace std;

EnrolledStudent::EnrolledStudent() : Student{}, courses{} {}

EnrolledStudent::EnrolledStudent (const string& lName, const string& fName)
	: Student{ lName, fName }, courses{} {}

void EnrolledStudent::addClass(const string& className, const double classGrade)
{
	courses[className] = classGrade;
}

double EnrolledStudent::getGPA() const
{
	double total = 0.0;
	for (const auto& i : courses)
	{
		total += i.second;
	}

	return total / courses.size();
}

bool EnrolledStudent::operator<(const EnrolledStudent& s2) const
{
	return (getLastName() < s2.getLastName());
}

ostream& operator<<(ostream& out, const EnrolledStudent& s1)
{
	out << "Student Name: " << s1.getFirstName() << " " << s1.getLastName() << "\n";
	out	<< "GPA: " << setprecision(1) << fixed << s1.getGPA() << "\n";
	out	<< "Course Grades:\n";
	out << setprecision(2) << fixed;
	for (const auto& i : s1.courses)
	{
		out << setw(12) << left << i.first
			<< "- "  << i.second << "\n";
	}
	out << endl;    //clear the buffer

	return out;
}