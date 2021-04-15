/*Note: This function is for deposit option. It will ask the user for the amount, calculate the new balance, display the deposited amount
	and the new balance, set current balance to new balance.*/

int deposit_option(int current_balance){
	int new_balance = 0;
	int deposit_amnt;

	printf("Please enter the amount: ");
	scanf("%d", &deposit_amnt);
	new_balance = (deposit_amnt + current_balance); //subtract current balance to entered withdrawal amount
	printf("\nYour deposited amount is $%d. Your new balance is $%d.\n", deposit_amnt, new_balance);
	current_balance = new_balance;
	printf("\n\t\t ==========*Thank you for banking with Advanced Learning ATM* =========\n");
	
	return current_balance;
}
