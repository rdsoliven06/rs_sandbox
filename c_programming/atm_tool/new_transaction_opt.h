/*Note: This function is for user to make another transaction. It will ask user if they want to make new transaction.
	If user input is other than 1 or 0, print error message. Ask user again.*/

int new_transaction_opt(){
	int new_transaction;

	do {
		printf("\nDo you wish to perform another transaction? Press 1[Yes] 0[No]");
		scanf("%d", &new_transaction);
		//Print error message if input is not 0 or 1
		if (new_transaction > 1 || new_transaction < 0){
			error_message();
		}
	}while (new_transaction > 1 || new_transaction < 0);

	return new_transaction;
}
