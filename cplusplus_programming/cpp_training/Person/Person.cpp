#include "Person.h"
#include <iostream>
#include <string.h>

Person::Person(){}

Person::Person(string fName, string lName){
	firstName = fName;
	lastName = lName;
}

Person::Person(string fName, string lName, int age){
	firstName = fName;
	lastName = lName;
	age = age;
}


Person::~Person(){}

