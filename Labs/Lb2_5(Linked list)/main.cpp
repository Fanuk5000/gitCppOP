#include <iostream>
#include <string>

// 1. addToEnd: Implement an inline function for adding an element to the end of the list
// 2. removeFromEnd: Implement an inline function for removing the last element from the list
// 3. searchElement: Implement an inline function for searching for an element by value in the list and returning the pointer to the found element. If the element is not found, the function should return nullptr.
// 4. reverseList: Implement an inline function for reversing the list
// 5. sortList: Implement an inline function for sorting the list in ascending order using the bubble sort algorithm.
// 6. toTwoWayList: Implement an inline function for converting the singly linked list to a two-way circular linked list.
// 7. clearList: Implement an inline function for clearing the list and releasing the memory for all nodes using the delete operator.

using namespace std;
struct Node
{
	int data;
	Node *next; // pointer to next element
};

// inline - it is makes our method kinda built into main

inline void addToFront(Node **head, int value) // ** to change the node, * is to change the value
{
	Node *newNode = new Node;
	newNode->data = value; //(*newNode).data
	newNode->next = *head; // where it will input
	*head = newNode;
}

inline void addToEnd(Node **head, int value) // 1. addToEnd
{
	Node *newNode = new Node;
	newNode->data = value;
	newNode->next = nullptr; // where it will input

	if (*head == nullptr) // if the node is empty, the new node is head
	{
		*head = newNode;
		return;
	}

	Node *current = *head;
	while (current->next != nullptr) // goes through linked list until it finds nullptr
	{
		current = current->next; // and sets index of current near the nullptr
	}
	current->next = newNode;
}

inline void delFromFront(Node **head)
{
	if (*head != nullptr) // nullptr point to nothing
	{
		Node *temp = *head;
		*head = (*head)->next;
		delete temp;
	}
}

inline void delFromEnd(Node **head) // 2. removeFromEnd
{
	if (*head == nullptr)
		return;

	if ((*head)->next == nullptr)
	{
		delete *head;
		*head = nullptr;
		return;
	}

	Node *current = *head;
	while (current->next->next != nullptr)
	{
		current = current->next;
	}

	Node *lastNode = current->next;
	current->next = nullptr;
	delete lastNode;
}

inline Node *findElement(Node *head, int findValue) // 3. searchElement
{
	Node *current = head;

	while (current != nullptr and current->data != findValue)
	{
		current = current->next;
	}
	if (current == nullptr)
	{
		return nullptr;
	}
	return current;
}

inline void reverseList(Node **head) // 4. reverseList
{
	if (*head == nullptr or (*head)->next == nullptr)
		return;

	Node *end = nullptr;
	while (*head != end)
	{
		Node *prev = nullptr;
		Node *current = *head;
		while (current->next != end)
		{
			prev = current;
			current = current->next;
		}
		if (prev != nullptr)
		{
			prev->next = nullptr;
			current->next = *head;
			*head = current;
		}
		end = current;
	}
}

inline void printList(Node *head)
{
	Node *current = head;

	while (current != nullptr)
	{
		cout << current->data << " - > ";
		current = current->next;
	}
	cout << "Null" << endl;
}

int main()
{
	Node *head = nullptr;
	addToFront(&head, 1);
	addToFront(&head, 5);
	addToFront(&head, 10);
	addToEnd(&head, 2);

	cout << "List after adding elements: ";
	printList(head);

	Node *founded = findElement(head, 3);
	cout << ((founded != nullptr) ? "Found: " : "Node not found") << ((founded != nullptr) ? to_string(founded->data) : "") << endl;

	delFromFront(&head);
	cout << "List after delete front: ";
	printList(head);

	reverseList(&head);
	cout << "List after reverse: ";
	printList(head);

	delFromEnd(&head);
	cout << "List after delete end: ";
	printList(head);

	while (head != nullptr)
		delFromFront(&head);
	return 0;
}