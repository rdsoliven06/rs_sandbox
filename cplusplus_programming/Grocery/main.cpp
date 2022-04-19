#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Grocery{
private:
	int price;
public:
	vector<string> items;
	void calc_total_cost();

};


void Grocery::calc_total_cost(){
	this->price = 10;
	cout << this->price << endl;
}


int main(){
	Grocery p;
	
	p.items(orange);
	
	cout << p.items << endl;
	p.calc_total_cost();

	return 0;
}

