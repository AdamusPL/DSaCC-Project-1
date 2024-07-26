#pragma once
#include <iostream>
using namespace std;

class DynamicArray {
public:
	int* array;
	int size;

public:
	DynamicArray();
	DynamicArray(int*, int);
	void pushFront(int);
	void popFront();
	void pushBack(int);
	void popBack();
	void insert(int, int);
	void removeAt(int);
	void print();
	void printTests();
	void search(int);
	void menu();
	int loadNumber();
	int loadIndex();
};