#pragma once
class Heap {
public:
	int* data;
	bool* isOccupied;
	int size;

	Heap();
	Heap(int*, int);
	void removeFromPeak();
	void add(int);
	void menu();
	void display();
	void displayTree();
	void find(int);
	int loadNumber();
};