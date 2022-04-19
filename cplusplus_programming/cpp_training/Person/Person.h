#include <string.h>
#include <iostream>

class Person{
private:
	string firstName;
	string lastName;
	int age;
public:

	Person(); //default constructor
	Person(string fName, string lName); //constructor1
	Person(string fName, string lName, int age); //constructor2

	~Person(); //destructor

	void sayHello();
};
