#ifndef STUDENTS_INCLUDE
#define STUDENTS_INCLUDE
#include "Person.h"
#include <string>
#include <vector>
using namespace std;

class Students: public Person{
private:
	int StudentId;
	int Grade;
	vector<Students> student_list; 

public:
	string Major;
	string Club;
	string Honor;
	
	Students(); //default constructor
	Students(int studentId, string major, string club, int grade, string honor);
	Students(string name, int age, int studentId, string major);
	~Students(); //default destructor

	//setters
	void setStudentId(int studentId);
	void setGrade(int grade);
	void setMajor(string major);

	//getters
	int getStudentId();
	int getGrade();
	string getMajor();

	void addStudentList(Students *s); //passing Student object to the student_list vector
	void print_list();
	void greetings();
};

#endif