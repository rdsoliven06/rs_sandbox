//Written by Riad Soliven
#include <stdio.h>
#define LEN 10 //length of the array

//function declarations
int count_odd(int[],int);
int find_sum(int[],int);

int main(){

	int arr[LEN] = {1,2,3,4,5,6,7,8,9,10};
	int count = 0;	
	int sum = 0;
	
	count = count_odd(arr,count);
	printf("The total odd numbers in the array is: %d\n", count);
	
	sum = find_sum(arr,sum);
	printf("The sum of all odd numbers in the array is: %d\n", sum);

	return 0;
}

/*Note: This function will count the odd numbers in the array.*/
int count_odd(int arr[], int count){
	count=0;
	int i;
	for (i=0;i<LEN;i++){
		if(arr[i] % 2 != 0){
			count++;
		}
	}
	return count;
}

/*Note: This function will sum the odd numbers in the array.*/
int find_sum(int arr[], int sum){
	sum=0;
	int i;
	for(i=0; i<LEN;i++){
		if(arr[i] %2 != 0){
			sum+=arr[i];
		}
	}
	return sum;
}

	
