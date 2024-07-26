#include <iostream>
#include <fstream>
#include "DoublyLinkedList.h"
using namespace std;

struct ElemList {
	ElemList* prev;
	int data;
	ElemList* next;
};

DoublyLinkedList::DoublyLinkedList() {
	size = 0;
	head = nullptr;
	tail = nullptr;
}

void DoublyLinkedList::readData(int *tab, int s) { //add elements to list from .txt file while testing automatically
	size = s;
	for (int i = 0; i < s; i++) {
		pushFront(tab[i]);
	}
}

void DoublyLinkedList::pushFront(int data) {
	ElemList* p = new ElemList; //new node
	p->data = data; //added data
	p->prev = NULL; //pointer on the previous element - NULL

	if (head == nullptr) { //if list is empty
		p->next = NULL; //pointer on the next element - NULL
		head = p; //new node is the new head
		tail = head;
	}

	else { //if list is not empty
		p->next = head; //pointer on next element is the pointer on the previous head
		head->prev = p; //set pointer on the previous element of the previous head on new added node
		head = p; //new node is the new head
	}
	
	size++;
}

void DoublyLinkedList::popFront() {
	if (head == nullptr) {
		cout << "List is empty!" << endl;
	}

	else if (head->next == nullptr) { //if there's only one element in the list
		free(head); //free up memory
		head = NULL; //set head pointer as nullpointer
		size--;
	}

	else {
		head = head->next; //move head to the next node
		free(head->prev); //free up memory of the previous head node
		head->prev = NULL; //set pointer of the previous element - NULL
		size--;
	}
}

void DoublyLinkedList::pushBack(int data) {
	ElemList* p = new ElemList; //new node
	p->data = data; //adding data
	p->next = NULL; //pointer on the next element - NULL

	if (head == nullptr) { //if list is empty
		p->prev = NULL; //pointer on the previous element - NULL
		head = p; //new node is the new head
		tail = head;
	}

	else { //if list is not empty
		p->prev = tail;
		tail->next = p;
		tail = p;
	}
	size++;
}

void DoublyLinkedList::popBack() {
	if (head == nullptr) {
		cout << "List is empty!" << endl;
	}

	else if (head->next == nullptr) { //if there's only one element in the list
		free(head); //free up memory
		head = NULL; //set head pointer on NULL
		size--;
	}

	else {
		ElemList* previous = tail->prev; //come back to the previous node in the list
		free(tail); //free up memory
		previous->next = NULL; //and set pointer on the next element - NULL
		tail = previous; //previous list element is the new tail
		size--;
	}
}

void DoublyLinkedList::insert(int index, int data) {

	if (index > size || index < 0) {
		cout << "Incorrect index!" << endl;
		return;
	}

	ElemList* p = new ElemList; //new node
	p->data = data;

	if (head == nullptr) { //if list is empty
		p->prev = NULL; //pointer on the previous element <=> NULL
		p->next = NULL; //pointer on the next element <=> NULL
		head = p; //new node is the new head
		size++;
	}

	else {
		if (index == 0) {
			DoublyLinkedList::pushFront(data);
		}

		else if (index == size) {
			DoublyLinkedList::pushBack(data);
		}

		else {	
			ElemList* iterator = head;
			for (size_t i = 0; i < index - 1; i++)
			{
				iterator = iterator->next;
			}

			ElemList* temp = iterator; //temporary node
			temp = iterator->next;

			p->prev = iterator; //set pointer on the next element in the new node
			p->next = temp; //set pointer on the previous element in the new node

			iterator->next = p; //set pointer on the next element in the previous node
			temp->prev = p; //set pointer on the previous element in the next node
			size++;
		}
	}
}


void DoublyLinkedList::removeAt(int index) {

	if (head == nullptr) { //if head is empty
		cout << "List is empty!" << endl;
	}

	else if (index >= size || index<0) { //if index number is incorrect
		cout << "That index doesn't exist in the list!" << endl;
	}

	else {
		if (index == 0) {
			popFront();
		}

		else if (index == size - 1) {
			popBack();
		}

		else {
			ElemList* iterator = head;
			for (size_t i = 0; i < index - 1; i++)
			{
				iterator = iterator->next;
			}

			ElemList* temp; //temporary node
			temp = iterator->next->next;
			temp->prev = iterator;
			free(iterator->next);
			iterator->next = temp;
		}
		size--;
	}

}


void DoublyLinkedList::printFromFront() {
	if (head == nullptr) {
		cout << "List is empty!" << endl;
	}
	else {
		ElemList* iterator = new ElemList;
		iterator = head;
		while (iterator != NULL) {
			cout << iterator->data << " ";
			iterator = iterator->next;
		}
		cout << endl;
	}
	cout << endl;
}

void DoublyLinkedList::printFromBack() {
	if (head == nullptr) {
		cout << "List is empty!" << endl;
	}

	else {
		ElemList* iterator = tail;

		while (iterator != NULL) {
			cout << iterator->data << " ";
			iterator = iterator->prev;
		}

		cout << endl;
	}
	cout << endl;
}

void DoublyLinkedList::search(int val) {
	int position = 0;
	ElemList* iterator = new ElemList;
	iterator = head;
	while (iterator != NULL) {
		if (val == iterator->data) {
			cout << val << " is on the position: " << position << " counting from head" << endl;
			return;
		}
		position++;
		iterator = iterator->next;
	}
	cout << "That value doesn't exist in the list!" << endl;
}

int DoublyLinkedList::middle() {
	ElemList* iterator = new ElemList;
	iterator = head;
	int i = 0;

	while (i != size / 2) {
		iterator = iterator->next;
		i++;
	}

	return iterator->data;
}

void DoublyLinkedList::menu() { //menu
	int option = 1;
	while (option != 10) {
		cout << "What would you like to do?:" << endl;
		cout << "=====================================" << endl;
		cout << "1. Add element at the front" << endl;
		cout << "2. Add element at the back" << endl;
		cout << "3. Add element at the specific index" << endl;
		cout << "4. Remove element from the front" << endl;
		cout << "5. Remove element from the back" << endl;
		cout << "6. Remove element from the specific index" << endl;
		cout << "7. Print elements of the list from the front" << endl;
		cout << "8. Print elements of the list from the back" << endl;
		cout << "9. Find index of the specific element of the list" << endl;
		cout << "10. Choose the other data structure" << endl;
		cin >> option;
		int number, index;
		cout << endl;

		switch (option) {
		case 1:
			number = loadNumber();
			pushFront(number); break;
		case 2:
			number = loadNumber();
			pushBack(number); break;
		case 3:
			number = loadNumber();
			index = loadIndex();
			insert(index, number); break;
		case 4:
			popFront(); break;
		case 5:
			popBack(); break;
		case 6:
			index = loadIndex();
			removeAt(index); break;
		case 7:
			printFromFront(); break;
		case 8:
			printFromBack(); break;
		case 9:
			number = loadNumber();
			search(number); break;
		case 10: return;
		}
	}
}

int DoublyLinkedList::loadNumber() { //method to read numbers from user
	int number;
	cout << "Give the number: ";
	cin >> number;
	cout << endl;
	return number;
}

int DoublyLinkedList::loadIndex() { //method to read index from user
	int index;
	cout << "Give the index: ";
	cin >> index;
	cout << endl;
	return index;
}