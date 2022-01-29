#include "Students.h"
#include "Person.h"
#include <iostream>

Students::Students(){}
Students::Students(int studentId, string major, string club, int grade, string honor) {
	StudentId = studentId;
	Major = major;
	Club = club;
	Grade = grade;
	Honor = honor;
}

Students::Students(string name, int age, int studentId, string major)
	:Person(name, age)
{
	StudentId = studentId;
	Major = major;

}

Students::~Students(){
	//cout << "calling Student destructor here.." << endl;
	
}

//setters
void Students::setStudentId(int studentId) {
	this->StudentId = studentId;
}
void Students::setGrade(int grade) {
	this->Grade = grade;
}

void Students::setMajor(string major) {
	this->Major = major;
}

//getters
int Students::getStudentId() {
	return this->StudentId;
}
int Students::getGrade() {
	return this->Grade;
}
string Students::getMajor() {
	return this->Major;
}
void Students::addStudentList(Students *s) {
	this->student_list.push_back(*s);
}

void Students::print_list() {
	for (int i = 0; i < student_list.size(); i++) {
		cout << this->student_list[i].getName() << endl;
		cout << this->student_list[i].getAge() << endl;
		cout << this->student_list[i].getStudentId() << endl;
		cout << this->student_list[i].getMajor() <<  endl;
		cout << " " << endl;

	}
}

void Students::greetings() {
	cout << "Good afternoon from Students class " << endl;
}