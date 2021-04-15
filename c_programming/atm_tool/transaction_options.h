/*Note: This function will ask the user for available transactions.*/
int transaction_options(void){
	int option;
	printf("\n\t\t ==========*Available Transactions*==========\n");
	printf("\t\t1.Withdraw\n");
	printf("\t\t2.Deposit\n");
	printf("\t\t3.Check Balance\n");
	printf("\n\nPlease select the option: ");
	scanf("%d", &option);

	return option;
}
