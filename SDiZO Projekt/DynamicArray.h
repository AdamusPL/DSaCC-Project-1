#pragma once
#include <iostream>
using namespace std;

class DynamicArray {
protected:
	int* array;
	int size;

public:
	DynamicArray();
	DynamicArray(int*, int);
	void addOnStart(int);
	void removeFromStart();
	void addOnEnd(int);
	void removeFromEnd();
	void insert(int, int);
	void removeFromChosen(int);
	void display();
	void find(int);
	void menu();
	int loadNumber();
	int loadIndex();
};