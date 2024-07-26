#pragma once

class DoublyLinkedList {
public:
	struct ElemList {
		ElemList* prev;
		int data;
		ElemList* next;
	};

	ElemList* head;
	ElemList* tail;

	int size;
	DoublyLinkedList();
	void readData(int*,int);
	void pushFront(int);
	void popFront();
	void pushBack(int);
	void popBack();
	void insert(int, int);
	void removeAt(int);
	void printFromFront();
	void printFromBack();
	void search(int);
	int middle();
	void menu();
	int loadNumber();
	int loadIndex();

};
