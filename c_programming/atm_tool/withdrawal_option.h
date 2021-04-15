/*Note: This function is for withdrawal option. It will ask the user to enter desired amount, calculate new balance,
	display withdrawal amount and the new balance, and set current balance to new balance, finally return
	current balance.*/
int withdrawal_option(int current_balance){
	int withdrawal_amnt;
	int new_balance = 0;

	printf("Please enter the amount: ");
	scanf("%d", &withdrawal_amnt);
	new_balance = (current_balance - withdrawal_amnt); //subtract current balance to withdrawal amount
	printf("\nYour withdrawal amount is $%d. Your new balance is $%d.\n", withdrawal_amnt, new_balance);
	current_balance = new_balance;

	return current_balance;
}
