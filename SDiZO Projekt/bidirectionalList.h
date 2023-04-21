#pragma once

class bidirectionalList {
public:
	struct ElemList {
		ElemList* prev;
		int data;
		ElemList* next;
	};

	ElemList* head;
	ElemList* tail;

	int size;
	bidirectionalList();
	void readData(int*,int);
	void addOnStart(int);
	void removeFromStart();
	void addOnEnd(int);
	void removeFromEnd();
	void insert(int, int);
	void removeFromChosen(int);
	void displayFromStart();
	void displayFromEnd();
	void find(int);
	int middle();
	void menu();
	int loadNumber();
	int loadIndex();

};
