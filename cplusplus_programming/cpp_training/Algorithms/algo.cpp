#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;


void leftRotateByOne(int arr[], int n){
	
	int temp = arr[0]; //store first element to temp
	int i;
	
	for (i=0; i<n-1;i++)
	{
	    arr[i] = arr[i+1];
	}
	arr[n-1] = temp; //assign temp to last position
}

void leftRotate(int arr[], int d, int n)
{
	for (int i = 0; i < d;i++)
	{
		leftRotateByOne(arr,n);
	}
}

void rightRotateByOne(int arr[], int n)
{
	int i;
    int temp = arr[n-1]; //store last element to temp
    
    for (i = n - 1; i > 0; i--)
    {
    	arr[i] = arr[i-1];
    }
    arr[0] = temp; //assign temp to first position
}

void rightRotate(int arr[], int d, int n)
{
	for (int i = 0; i < d; i++)
	{
	    rightRotateByOne(arr,n);
	}
}


void printArray(int arr[], int n)
{
	for (int i=0;i<n;i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}


class node{
public:
	int data;
	struct node *next;
};


int main(){
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int d = 2;
    
    struct node* head = NULL;
    head = (struct node *) malloc(sizeof(struct node)); 
    head->data = 6;
    head->next = NULL;
    
    cout << head->data << endl;
    
    
    
    
    //leftRotate(arr,d,n);
    //rightRotateByOne(arr,n);
    //rightRotate(arr,d,n);
    //printArray(arr,n);

	return 0;
}
