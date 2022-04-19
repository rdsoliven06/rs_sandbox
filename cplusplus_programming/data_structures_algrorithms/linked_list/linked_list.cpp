
#include<iostream>

struct Node{
	int data;
	Node* next;
	Node (int data)
	{
		this->data = data;
		next = NULL;
	}
};

struct LinkedList{
	Node* head = NULL;
	
	// Add new node to the front of the list
	void push(int data)
	{
		Node* newNode = new Node(data);
		newNode->next = head;
		head = newNode;
	}
	// Add new node to the end of the list
	void append(int data)
	{
		Node* newNode = new Node(data);
		if (head == NULL)
		{
			head = newNode;
			return;
		}
		else
		{
			Node* last = head;
			while (last->next != NULL)
			{
				last = last->next;
			}
			last->next = newNode;
		}
	}
	
	// Reverse the linked list
	void reverse_list()
	{
		Node* curr = head;
		Node* prev = NULL;
		
		while (curr != NULL){
			Node* next = curr->next; //store next pointer
			curr->next = prev; // reverse link 
			prev = curr;
			curr = next;
		}
		head = prev;
	}
	
	// insert_list method will insert a value in a sorted list.
	void insert_list(int data)
	{
		Node* newNode = new Node(data);
		// if empty list or new value is less than head value, then set newNode as head 
		if (head == NULL || newNode->data <= head->data) 
		{
			newNode->next = head;
			head = newNode;
			return;
		}
		// iterate through the list until new value is greater than current value
		else
		{
			Node* curr = head;
			while (curr->next != NULL && curr->next->data < newNode->data)
			{
				curr = curr->next;
			}
			newNode->next = curr->next;
			curr->next = newNode;
			
		}
	}
	void print_list(){
		Node* temp = head;
		while (temp != NULL){
			std::cout << temp->data << " ";
			temp = temp->next;
		}
	}

};


int main(){
	LinkedList m;
	m.push(10);
	m.push(7);
	m.push(5);
	m.push(2);
	m.insert_list(9);
	
	std::cout << "Given Linked List\n";
	m.print_list();
	
	std::cout << "\nReversed Linked List\n";
	m.reverse_list();
	m.print_list();
	
	std::cout << "\n";
	return 0;
}
