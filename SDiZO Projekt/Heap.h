#pragma once
class Heap {
public:
	int* data;
	bool* isOccupied;
	int size;

	Heap();
	Heap(int*, int);
	void deleteRoot();
	void insert(int);
	void menu();
	void print();
	void printTree();
	void search(int);
	int loadNumber();
};