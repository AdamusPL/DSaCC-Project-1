#pragma once
#include <iostream>
using namespace std;

class DynamicArray {
protected:
	int* array;
	int size;

public:
	DynamicArray();
	void addOnStart(int);
	void removeFromStart();
	void addOnEnd(int);
	void removeFromEnd();
	void insert(int, int);
	void removeFromChosen(int);
	void display();
	void menu();
	int loadNumber();
	int loadIndex();
};