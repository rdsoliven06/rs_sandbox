#include <iostream>
#include "Person.h"
#include "Students.h"
#include <vector>
using namespace std;

int main() {

	Person p;
	Students s;

	Students *v = new Students("Vans", 27, 987654, "Computer Science");
	Students *a = new Students("Amy", 21, 061302, "Business");
	Students *m = new Students("Michelle", 28, 123456, "Business");

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
