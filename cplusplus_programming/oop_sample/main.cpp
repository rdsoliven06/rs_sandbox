/*This program is for learning purposes only.
It covers the idea of 4 main components of OPP:
1. Encapsulation - idea of bundling data for preventing outside of class to directly access data.
2. Abstraction - hiding complex things behind a procedure to make things simple. 
3. Inheritance - derived class inherit from a parent class.  )
4. Polymorphism - ability of an object or a method to use many forms. The most common use of
polymorhpishm is when a parent class reference is used to refer to a child class object.
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
	void setName(string name){ Name = name; } //setter
	string getName(){ return Name; } //getter
	
	void setCompany(string company){ Company = company; }
	string getCompany(){ return Company; }
	
	void setAge(int age){ 
		if (age >= 18){
			Age = age;
		} 
	}
	int getAge() { return Age; }
	
	//Constructor, must be public
	Employee(string name, string company, int age){
		Name = name;
		Company = company;
		Age = age;
	}
		
	void introduce_yourself(){
		cout << "Name - " << Name << endl;
		cout << "Company - " << Company << endl;
		cout << "Age - " << Age << endl;
	}
	
	void ask_for_promotion(){
		if (Age > 30){
			cout << Name << " got promoted!" << endl;
		}
		else{
			cout << Name << " Sorry, NO promotion for you!" << endl;
		}
	}
	
	/*when virtual is invoke, the program checks if there is the same function in its 
	inherited classes. If there is, it executes that instead*/
	virtual void work(){
		cout << Name << " is checking email, task backlog, peforming tasks..." << endl;
	}
	
};

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
	
	void fix_bug(){
		cout << Name << " fixed bug using " << fav_programming_language << endl;
	}
	
	void work(){
		cout << Name << " is writing " << fav_programming_language << " code" << endl;
	}
	
};

class Teacher:public Employee {
public:
	string Subject;
	void prepare_lesson(){
		cout << Name << " is preparing " << Subject << " lesson " << endl;
	}
	Teacher(string name, string company, int age, string subject)
		:Employee(name,company,age)
	{
		Subject = subject;
	}
	
	void work(){
		cout << Name << " is teaching " << Subject << endl;
	}
};

int main(){
	Developer d = Developer("Jhun Rey", "Tesla", 28, "C++");
	//d.fix_bug();
	//d.ask_for_promotion();

	Teacher t = Teacher("Jack",  "Cool School", 35, "History");
	//t.prepare_lesson();
	//t.ask_for_promotion();
	
	//d.work();
	//t.work();
	
	//The most common use of polymorhpishm is when a parent class reference is used to refer 
	//to a child class object
	Employee *e1 = &d;
	Employee *e2 = &t;
	
	e1->work();
	e2->work();
	
	return 0;
}
