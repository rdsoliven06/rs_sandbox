#include <stdio.h>
#include <stdlib.h> //malloc

typedef struct nodes{
	int data;
	struct nodes *next;
} node;

void push(node **head_ref, int new_data){
	node *new_node = malloc(sizeof(node)); //allocate node
	new_node->data = new_data; //put in the data
	new_node->next = *head_ref; //make next of new node as head
	*head_ref = new_node; //move the head to point to the new node
}

void append(node **head_ref, int new_data){
	node *new_node = malloc(sizeof(node)); //allocate new node
	node *last = *head_ref;
	new_node->data = new_data; //place data
	new_node->next = NULL; //this new node is going to be the last node so make next of it as NULL
	
	if (*head_ref == NULL){ //if the linked list is empty, then make the new node as head
		*head_ref = new_node;
		return;
	}
	
	while(last->next != NULL){
		last = last->next; //else traverse until the last node
	}		
	last->next = new_node; //change the next of last node
	return;
}
		
void empty_list(node *head){
	node *ptr = head;
	if (ptr == NULL){
		printf("This is an empty list.\n");
	}
}

void print_list(node *head){
	node *ptr = head; //ptr equals to the head pointer
	while (ptr != NULL){
		printf("%d\n", ptr->data);
		ptr = ptr->next;
	}
	empty_list(head);
}

int main(){
	node *head = NULL; //start with an empty list
	append(&head,6);
	push(&head, 7);	
	push(&head, 1);
	print_list(head);

	return 0;
}
