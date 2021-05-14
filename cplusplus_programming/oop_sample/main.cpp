/*This program is for learning purposes only.
It covers the idea of 4 main components of OPP:
1. Encapsulation - idea of bundling data for preventing outside of class to directly access data.
2. Abstraction - hiding complex things behind a procedure to make things simple. 
3. Inheritance - derived class inherit from a parent class.  
4. Polymorphism - the ability of an object or a method to use in many forms. 
*/
#include <iostream>
using namespace std;

//An abstract class
//Abstraction Demonstration
class AbstractEmployee {
	virtual void ask_for_promotion() = 0; //abstract function
};


class Employee:AbstractEmployee {
private:
	string Company;
	int Age;
	
protected:
	string Name;
public:
	/*Function Declarations*/
	
	//setters
	void setName(string name);
	void setCompany(string company);
	void setAge(int age);
	//getters
	string getName(void); 
	string getCompany(void);
	int getAge(void);
	
	void introduce_yourself(void);
	void ask_for_promotion(void);	
	
	/*Constructor, must be public*/
	Employee(string name, string company, int age){
		Name = name;
		Company = company;
		Age = age;
	}
	
	/*when virtual is invoke, the program checks if there is the same function in its 
	inherited classes. If there is, it executes that instead*/
	virtual void work(){
		cout << Name << " is checking email, task backlog, performing tasks..." << endl;
	}
	
};


/*Employee Class function definitions start here*/
void Employee::setName(string name){
	Name = name;
}
void Employee::setCompany(string company){ 
	Company = company; 
}
void Employee::setAge(int age){ 
	if (age >= 18){
		Age = age;
	} 
}

string Employee::getName(void){ 
	return Name; 
}

string Employee::getCompany(void){
	return Company;
}

int Employee::getAge(void){
	return Age;
}

void Employee::introduce_yourself(void){
	cout << "Name - " << Name << endl;
	cout << "Company - " << Company << endl;
	cout << "Age - " << Age << endl;
}

void Employee::ask_for_promotion(){
	if (Age > 30){
		cout << Name << " got promoted!" << endl;
	}
	else{
		cout << Name << " Sorry, NO promotion for you!" << endl;
	}
}
	
/*Employee Class function definitions end here*/


//Template
//child class:parent class
//Note: public Employee allows user to access functions inside the parent class
class Developer: public Employee {
public:
	string fav_programming_language;
	
	//constructor
	Developer(string name, string company, int age, string fav_prog_lang)
		:Employee(name,company,age)
	{
		fav_programming_language = fav_prog_lang;
	}
	
	/*Function Declarations*/
	void fix_bug(void);
	void work(void);
	
};

void Developer::fix_bug(void){
	cout << Name << " fixed bug using " << fav_programming_language << endl;
}
void Developer::work(void){
	cout << Name << " is writing " << fav_programming_language << "." <<endl;
}

class Teacher:public Employee {
public:
	string Subject;
	void prepare_lesson(void);
	void work(void);
	
	//constructor
	Teacher(string name, string company, int age, string subject)
		:Employee(name,company,age)
	{
		Subject = subject;
	}
};

void Teacher::prepare_lesson(void){
	cout << Name << " is preparing " << Subject << " lessoon." << endl;
}

void Teacher::work(void){
	cout << Name << " is also teaching " << Subject << "." << endl;
}

int main(){
	Developer d = Developer("Jhun Rey", "Tesla", 28, "C++");
	Teacher t = Teacher("Jack",  "Cool School", 35, "History");
	
	//The most common use of polymorhpishm is when a parent class reference is used to refer 
	//to a child class object
	Employee *e1 = &d;
	Employee *e2 = &t;
	
	//Access functions under developer and teacher classes
	//Using Pointers
	Developer *e01 = &d;
	Teacher *e02 = &t;
	
	e1->work();
	e2->work();
	
	e01->fix_bug();
	e02->prepare_lesson();
	
	
	return 0;
}
