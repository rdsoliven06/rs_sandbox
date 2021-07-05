#ifndef PERSON_INCLUDE
#define PERSON_INCLUDE
#include <string>
using namespace std;

class Person {
private:
	string Name;
	int Age;
	string Address;
	string EmailAddress;
	string Ethnicity;
	string Gender;

public:
	Person();
	Person(string name, int age);
	Person(string name, int age, string address, string emailAddress, string ethnicity, string gender);
	~Person();

	//setters
	void setName(string name);
	void setAge(int age);
	void setAddress(string address);
	void setEmailAddress(string emailAddress);
	void setGender(string gender);

	//getters
	int getAge();
	string getName();
	string getAddress();
	string getEmailAddress();
	string getEthnicity();
	string getGender();

	void greetings();

};

#endif