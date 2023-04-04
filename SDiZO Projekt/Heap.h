#pragma once
class Heap {
public:
	int* data;
	bool* isOccupied;
	int size;

	Heap();
	Heap(int* data);
	void removeFromPeak();
	void add(int);
	void menu();
	void display();
	int loadNumber();
};