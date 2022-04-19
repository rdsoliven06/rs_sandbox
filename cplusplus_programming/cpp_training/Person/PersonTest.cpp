#include <iostream>
#include <string>
#include "Person.h"
using namespace std;

int main(){

	//create a Person instance using default constructor
	Person *pOne = new Person();

	//create a Person instace using 2 argument constructor
	Person *pTwo = new Person("Tom", "Thumb");

	Person *pThree = new Person("Tom", "Thumb", 15);

	return 0;
}
