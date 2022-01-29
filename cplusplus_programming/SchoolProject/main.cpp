#include <iostream>
#include "Person.h"
#include "Students.h"
#include <vector>
using namespace std;

int main() {
	/*Person *p = new Person("Amira", 22, "323 BTS Street", "as@bts.com", "Korean", "female");
	Students *s1 = new Students("Michelle", 21, 123456, "Business");

	cout << "Amira's address is " << p->getAddress() << endl;
	cout << "Student 1's name is " << s1->getName() << endl;
	cout << "Hello World" << endl;

	delete p;
	delete s1;*/
	
	Person p;
	Students s;

	Students *v = new Students("Vans", 21, 987654, "Computer Science");
	Students *a = new Students("Amy", 22, 061302, "Business");
	Students *m = new Students("Michelle", 21, 123456, "Business");

	s.addStudentList(v);
	s.addStudentList(a);
	s.addStudentList(m);
	s.print_list();

	delete v;
	delete a;
	delete m;

	p.greetings();

	system("pause");
	return 0;
}