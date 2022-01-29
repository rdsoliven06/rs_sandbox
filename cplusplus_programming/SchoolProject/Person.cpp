#include "Person.h"
#include <iostream>
using namespace std;

//default constructor
Person::Person(){}

Person::Person(string name, int age) {
	Name = name;
	Age = age;
}

Person::Person(string name, int age, string address, string emailAddress, string ethnicity, string gender) {
	Name = name;
	Age = age;
	Address = address;
	EmailAddress = emailAddress;
	Ethnicity = ethnicity;
	Gender = gender;
}

Person::~Person(){
	//cout << "calling Person destructor here..." << endl;
}

//setters
void Person::setName(string name) {
	this->Name = name;
}
void Person::setAge(int age) {
	this->Age = age;
}
void Person::setAddress(string address) {
	this->Address = address;
}
void Person::setEmailAddress(string emailAddress) {
	this->EmailAddress = emailAddress;
}
void Person::setGender(string gender) {
	this->Gender = gender;
}

//getters

string Person::getName() {
	return this->Name;
}
int Person::getAge() {
	return this->Age;
}
string Person::getAddress() {
	return this->Address;
}
string Person::getEmailAddress() {
	return this->EmailAddress;
}
string Person::getEthnicity() {
	return this->Ethnicity;
}
string Person::getGender() {
	return this->Gender;
}

void Person::greetings() {
	cout << "Good morning from Person class! " << endl;
}
