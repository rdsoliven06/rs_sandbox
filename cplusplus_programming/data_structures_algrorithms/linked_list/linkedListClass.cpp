#include <iostream>
using namespace std;

class Node{
public:
	int num_;
	Node* next;
	Node(int num) { num_ = num, next = NULL; }
};

class LinkedList{
private:
	Node* head;
	Node* prev;
public:

	LinkedList() { head = NULL, prev = NULL; }
	void insert(int num); // insert a node in front 
	void append(int num); // insert at the end
	void reverse();	// reverse the list
	void addSorted(int num); // add node in a sorted list
	void printList(); // Output list
	Node* getNewHead(Node* newHead); // returns new head if list is empty
};

void LinkedList::insert(int num)
{
	Node* curr = new Node(num);
	curr->num_ = num;
	curr->next = head;
	head = curr;
}

void LinkedList::append(int num)
{
	Node* newNode = new Node(num);
	newNode->num_ = num;
	newNode->next = NULL;
	
	if (head == NULL)
	{
		getNewHead(newNode);
	}
	else
	{
		Node* lastNode = head;
		while (lastNode->next != NULL)
		{
			lastNode = lastNode->next;
		}
		lastNode->next = newNode;
	}
}

void LinkedList::reverse()
{
	Node* curr = head;	
	while (curr != NULL)
	{
		Node* tmp = curr->next; //store pointer
		curr->next = prev; // reverse the pointer
		prev = curr; // move prev one position
		curr = tmp; // move curr to next position
	}
	head = prev; // prev is the new head of the list
}

Node* LinkedList::getNewHead(Node* newNode)
{
	return head = newNode;
}

void LinkedList::addSorted(int num)
{
	Node* newNode = new Node(num);
	newNode->num_ = num;
	newNode->next = NULL;
	
	if (head == NULL)
	{
		getNewHead(newNode);
	}
	else
	{
		Node* curr = head;
		while (curr->next != NULL && (curr->next->num_ < newNode->num_))
		{
			curr = curr->next;
		}
		newNode->next = curr->next; // Store next curr to newNode next pointer
		curr->next = newNode; // Curr points to newNode
	}
}

void LinkedList::printList()
{
	Node* tmp = head;
	while (tmp != NULL)
	{
		cout << tmp->num_ << " ";
		tmp = tmp->next;
	}
	cout << "\n";
}

int main()
{
	LinkedList l;
	l.insert(1);
	l.insert(2);
	l.insert(4);
	l.reverse();
	l.addSorted(3);
	l.append(5);
	l.printList();
	return 0;
}
