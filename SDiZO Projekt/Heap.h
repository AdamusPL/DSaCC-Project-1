#pragma once
class Heap {
public:
	int* data;
	int* isOccupied;
	int size;

	Heap();
	void removeFromPeak();
	void add(int);
	void menu();
};