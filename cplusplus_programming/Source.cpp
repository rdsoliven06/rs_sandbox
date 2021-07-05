#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Items {
public:
	int price = 0;
	string item_name;
};

class Grocery {
private:
	int capacity;

public:
	vector<Items> fruits;
	string item;
	void add_item(Items item);
	void print_items();
	void calc_total_cost();
	void print_item_price();
};

//Inheritance
class Costco: public Grocery, public Items {
public:
	int c_apple_price = 7; //costco apple price is much higher
	void compare_price();
		
};

void Costco::compare_price() {
	/*if (this->fruits[0].price <  c_apple_price) {
		cout << "Costco apple price is more expensive." << endl;
	}*/
	cout << this->fruits[0].price << endl;
}

void Grocery::calc_total_cost() {
	int sum = 0;
	for (int i = 0; i < fruits.size(); i++) {
		sum += this->fruits[i].price;
	}
	cout << sum << endl;
}
void Grocery::print_item_price() {
	for (int i = 0; i < fruits.size(); i++) {
		cout << this->fruits[i].price << endl;
	}
}

void Grocery::add_item(Items item) {
	this->fruits.push_back(item);
}

void Grocery::print_items() {
	for (int i = 0; i < fruits.size(); i++) {
		cout << this->fruits[i].item_name << endl;
	}
}


int main() {
	Grocery p; //Grocery object
	Costco c; //Costco Object

	Items orange, apple;
	orange.price = 10;
	apple.price = 5;
	orange.item_name = "orange";
	apple.item_name = "apple";

	p.add_item(orange);
	p.add_item(apple);

	p.print_items();
	p.print_item_price();
	p.calc_total_cost();

	//cout << c.c_apple_price << endl;
	c.compare_price();
	cout << "Hello world" << endl;
	system("pause");
	return 0;
}