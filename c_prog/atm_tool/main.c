#include<stdio.h>
#include <time.h> //time_t
#include "time.h"
#include "enter_pin.h"
#include "error_message.h"
#include "transaction_options.h"
#include "withdrawal_option.h"
#include "print_current_balance.h"
#include "deposit_option.h"
#include "new_transaction_opt.h"

int main(){

	int user_pin, options, new_transaction;
	const int actual_pin = 1234;
	int failed_attempts = 0;
	int current_balance = 3000; //customer's current balance

	//print current time
	current_time();

	//print welcome message
	printf("\n\t\t ==========*Welcome to Advanced Learning ATM*==========\n");

	/*Note: User will enter his or her pin. If the pin is invalid, print error message.*/
	user_pin = enter_pin();

	while (user_pin != actual_pin && failed_attempts != 3){
		if (failed_attempts < 2){
			error_message();
			user_pin = enter_pin();
		}
		failed_attempts++;
	}

	/*Note: If user input invalid pin 3 times in a row, end the program.
		If pin is correct, proceed to the program.*/
	if (failed_attempts == 3){
		printf("\nToo many invalid inputs!\n");
	}
	else if (user_pin == actual_pin){
		do {
			options = transaction_options();
			switch(options){
				case 1:
					current_balance = withdrawal_option(current_balance);
					break;
				case 2:
					current_balance = deposit_option(current_balance);
					break;
				case 3:
					print_current_balance(current_balance);
					break;
				default:
					printf("\nERROR: Please select between option1-3.\n");
					options = transaction_options();
			}
			/*Note: If user input new_transaction other than 1 or 0, print error message.
				Ask user to do another transaction.*/
			new_transaction = new_transaction_opt();

		}while (new_transaction == 1);
		if (new_transaction == 0){
			printf("\nThank you for using the Advanced Learning ATM. See you next time!\n");
		}
	}
	else{
		//do nothing
	}
	return 0;
}
