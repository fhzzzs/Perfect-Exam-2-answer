/*
	Ivan Ao

	October 21, 2020

	CS A250
	Programming Exam 2
*/

#include "Student.h"
#include "EnrolledStudent.h"
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

// Add predicate function here if needed
// code below
bool compareGPA(const EnrolledStudent&, const EnrolledStudent&);
// code above

int main()
{
	EnrolledStudent es1("Kohl", "David"), es2("Smith", "Jane"), es3("Nguyen", "Thomas");
	es1.addClass("Calculus", 4.0);
	es1.addClass("History", 3.7);
	es1.addClass("English", 3.3);
	es2.addClass("Algerbra", 4.0);
	es2.addClass("Comp Sci", 3.0);
	es3.addClass("Psychology", 4.0);
	es3.addClass("History", 3.7);
	es3.addClass("Spanish", 3.7);

	vector<EnrolledStudent> students{ es1, es2, es3 };
	
	// Call the sort function from the algorithm library to sort the students by gpa in 
	// assending order and print all the students
	// Then call the sort function to sort the students by last name in assending order and 
	// again print all the students
	// Your code on below.

	vector<EnrolledStudent>::iterator iter = students.begin();
	vector<EnrolledStudent>::iterator end = students.end();

	sort(iter, end, compareGPA);
	for (auto i = iter; i != end; ++i)
	{
		cout << *i;
	}

	sort(iter, end);
	for (auto i = iter; i != end; ++i)
	{
		cout << *i;
	}
	
	// Your code above

	cout << "\n\n";



	system("pause");
	return EXIT_SUCCESS;
}

bool compareGPA(const EnrolledStudent& s1, const EnrolledStudent& s2)
{
	return s1.getGPA() < s2.getGPA();
}