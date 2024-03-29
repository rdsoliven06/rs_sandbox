#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <limits>
using namespace std;



//Parent Class
class ATM {
private:
	int ActualPin;
public:
	int UserPin, Options, NewTransaction;
	int current_balance = 3000; //user's current balance

	void set_actual_pin(int); //setter
	int get_actual_pin(void); //getter

	void print_current_time(void);
	void print_error_message(void);
	void print_current_balance(int);
};

/*Display the system's time and prints ATM welcome message*/
void ATM::print_current_time(void){
	time_t timeNow = time(NULL);
	cout << "\t\t\t\t" << ctime(&timeNow);
	cout <<"\t\t ==========*Welcome to Advanced Learning ATM*==========" << endl;
}
/*Setter: sets the pin for user*/
void ATM::set_actual_pin(int actualPin){
	ActualPin =  actualPin;
}
/*Getter: get the value of the user's pin*/
int ATM::get_actual_pin(void){
	return ActualPin;
}
/*Display error message when user enter invalid choice*/
void ATM::print_error_message(void){
	cout << "Invalid pin. Please try again. " << endl;
}
/*Display the current balance*/
void ATM::print_current_balance(int current_balance){
        if (current_balance <= 0)
        {
            cout << "Your current balance is $" << current_balance << endl;
        }
        else
        {
	    cout << "Your current balance is $" << current_balance << endl;
        }
}

/*Derived Class: Pin - this class will ask the user to enter their pin*/
class Pin:public ATM {
public:
	int pin;
	int enter_pin(void);
};

int Pin::enter_pin(void){
	cout << "Please enter pin: ";
	cin >> pin;
	return pin;
}

/*Derived Class: Transaction - this class is specifically used for making transactions in ATM.
transaction_options() - display the available transactions.
new_transaction() - determine if the user wants to perform new transaction.
*/
class Transaction:public ATM {
public:
	int option;
	int new_transaction;
	
	int transaction_options(void);
	int new_transaction_options(void);
};

int Transaction::transaction_options(void){
	cout << "\t\t===========*Available Transactions*==========" << endl;
	cout << "\t\t1.Withdraw" << endl;
	cout << "\t\t2.Deposit" << endl;
	cout << "\t\t3.Check Balance" << endl;
	cout << "\n\nPlease select the option: ";
	cin  >> option;       
	return option;
}

int Transaction::new_transaction_options(void){
	do {
		cout << "Do you wish to perform another transaction? Press 1[Yes] 0[No]";
		cin >> new_transaction;
		
		if (new_transaction > 1 || new_transaction < 0 || !new_transaction)
                {
                        cin.clear();
                        cin.ignore(numeric_limits<int>::max(), '\n');
			print_error_message();
                        continue;
		}
                else
                {
                        break;
                }
	}while (new_transaction < 0 || new_transaction > 1);
	
	return new_transaction;
}

/*Derived Class: Withdrawal - this class performs the withdrawal feature of the ATM machine.
withdrawal_options()- this function performs the withdrawal operatioN.
*/
class Withdrawal: public ATM {
public:
	int withdrawal_amnt;
	int new_balance = 0;
	int withdrawal_options(int);
};

//
int Withdrawal::withdrawal_options(int current_balance){
	cout << "Please enter the amount: ";
	cin >> withdrawal_amnt;
	new_balance = (current_balance - withdrawal_amnt);
	current_balance = new_balance;
	cout << "Your withdrawal amount is $" << withdrawal_amnt << ".Your new balance is $" << new_balance << "." << endl;
	return current_balance;
}

/*Derived Class: Deposit - this class performs the deposit feature of the ATM machine.
deposit_function() - this function performs the deposit operation.
*/
class Deposit: public ATM {
public:
	int new_balance = 0;
	int deposit_amnt;
	int deposit_option(int);
};

int Deposit::deposit_option(int current_balance){
	cout << "Please enter the amount: ";
	cin >> deposit_amnt;
	
	new_balance = (deposit_amnt + current_balance);
	cout << "Your deposited amount is $" << deposit_amnt << ".Your new balance is $" << new_balance << "." << endl;
	current_balance = new_balance;
	cout << "\t\t==========*Thank you for banking with Advanced Learning ATM* ==========" << endl;
	return current_balance;
}

int main(){
	//Objects Declaration
	ATM atm;
	Pin p;
	Transaction t;
	Withdrawal w;
	Deposit d;
	
	int failed_attempts = 0;
	
	//print current time and welcome msg
	atm.print_current_time();
	//set actual user pin
	atm.set_actual_pin(1234);
	//Assign entered pin to UserPin variable
	atm.UserPin = p.enter_pin();
	
	/*If user enters invalid pin up to 2 times, print error messsage*/
	while(atm.UserPin != atm.get_actual_pin() && failed_attempts != 3){
		if (failed_attempts < 2){
			atm.print_error_message();
			atm.UserPin = p.enter_pin();
		}
		failed_attempts++;
	}
	
	/*If user enters invalid pin the 3rd time, print invalid input and end the program.
	Otherwise, continue with the program. Ask user to perform any transaction.*/
	if (failed_attempts == 3){
		cout << "Too many invalid inputs!";
                cout << "Ending program now.... start over.." << endl;
	}
	else if (atm.UserPin == atm.get_actual_pin()){
		do {
			atm.Options = t.transaction_options();
			switch(atm.Options){
				case 1:
					atm.current_balance = w.withdrawal_options(atm.current_balance);
					break;
				case 2:
					atm.current_balance = d.deposit_option(atm.current_balance);
					break;
				case 3:
					atm.print_current_balance(atm.current_balance);
					break;
				default:
					cout << "Error: Please select between option1-3." << endl;
					atm.Options = t.transaction_options();
			}
			t.new_transaction = t.new_transaction_options();
		}while (t.new_transaction == 1);
	}
	else {
		//do nothing
	}			
	
	return 0;
}

	
	
