#include <iostream>
#include <vector>
#include "Heap.h"
using namespace std;

Heap::Heap() { //constructor for heap while testing it manually
	size = 0;
	data = new int[size];
	isOccupied = new bool[size];
}

Heap::Heap(int *d, int s) { //constructor for heap while testing it automatically
	data = d;
	size = s;
	isOccupied = new bool[size];
}

void Heap::insert(int val) {
	int* tempData = new int[size+1]; //temporary array with data

	if (size == 0) {
		*tempData = val;
	}

	else {
		int k = size;

		for (size_t i = 0; i < size; i++)
		{
			tempData[i] = data[i]; //write all values to tempArray
		}

		tempData[k] = val; //write new value at the end of array

		while (k != 0) { //repair heap upwards
			if (tempData[k] > tempData[(k - 1) / 2]) { //if new node has larger value than its parent's
				swap(tempData[k], tempData[(k - 1) / 2]); //swap
				k = (k - 1) / 2;
			}

			else break;

		}
	}

	delete[] data;
	data = tempData;
	size++;
}

void Heap::deleteRoot() {
	if (size == 0) { //if array size = 0
		cout << "Heap is empty!" << endl;
		return;
	}

	int* tempData = new int[size - 1]; //temporary array with data
	tempData[0] = data[size-1]; //swap root with last array element

	for (size_t i = 1; i < size-1; i++)
	{
		tempData[i] = data[i]; //copy the rest of values from the previous heap
	}

	int k = 0; //repair heap downwards
	while (2*k+2<=size-1) { //while we don't reach leaf node
		if ((2 * k + 1 < size-1) && (2 * k + 2 < size-1)) { //if parent has 2 children
			if (tempData[2 * k + 1] < tempData[2 * k + 2]) { //if right child has larger value
				if (tempData[k] < tempData[2 * k + 2]) { //jeœli parent has lower value than child
					swap(tempData[k], tempData[2 * k + 2]);
					k = 2 * k + 2;
				}
				else break; //if larger, end repair algorithm
			}

			else { //if left child has larger value
				if (tempData[k] < tempData[2 * k + 1]) { //if parent has lower value than child
					swap(tempData[k], tempData[2 * k + 1]);
					k = 2 * k + 1;
				}
				else break; //if larger, end repair algorithm
			}
		}

		else if ((2 * k + 1 >= size - 1) && (2 * k + 2 < size - 1)) { //if only right child exists
			if (tempData[k] < tempData[2 * k + 2]) { //if parent has lower value than child
				swap(tempData[k], tempData[2 * k + 2]);
				k = 2 * k + 2;
			}
			else break; //if larger, end repair algorithm
		}

		else if ((2 * k + 1 < size - 1) && (2 * k + 2 >= size - 1)) { //if only left child exists
			if (tempData[k] < tempData[2 * k + 1]) { //if parent has lower value than child
				swap(tempData[k], tempData[2 * k + 1]);
				k = 2 * k + 1;
			}
			else break; //if larger, end repair algorithm
		}
	}

	size--;
	delete[] data;
	data = tempData;
}

void Heap::print() {
	if (size == 0) {
		cout << "Heap is empty!" << endl;
		return;
	}

	for (size_t i = 0; i < size; i++)
	{
		cout << "t[" << i << "]=" << data[i] << endl;
	}
	cout << endl;
}


void Heap::printTree() {
	if (size == 0) {
		cout << "Heap is empty!" << endl;
		return;
	}

	int offset = 50;
	int offsetSmall = 5;
	int row = 1;
	int leftSon = 0;
	int rightSon = 0;
	bool stop = false;

	for (int j = 0; j < size; j++) {
		if (rightSon >= size) {
			rightSon = size - 1;
			stop = true;
		}

		for (int k = 0; k < offset; k++) {
			cout << " ";
		}

		int loops = 1;
		for (int k = leftSon; k <= rightSon; k++) {
			cout << data[k];
			if (loops % 2 == 0) {
				for (int i = 0; i < offsetSmall; i++) {
					cout << " ";
				}
			}
			else {
				for (int i = 0; i < 20; i++) {
					cout << " ";
				}
			}
			loops++;
		}

		leftSon = 2 * leftSon + 1;
		row *= 2;
		rightSon += row;
		offset-=10;
		offsetSmall--;
		cout << endl << endl;
		if (stop) break;
	}
	

}

void Heap::search(int val) {

	for (int i = 0; i < size; i++) {
		if (val == data[i]) {
			cout << val << " is in index: " << i << endl;
			return;
		}
	}

	cout << "That value doesn't exist in the heap!" << endl;
}

void Heap::menu() { //menu
	int option = 1;
	while (option != 5) {
		cout << "What would you want to do?:" << endl;
		cout << "==============================" << endl;
		cout << "1. Add element to the heap" << endl;
		cout << "2. Remove heap's root" << endl;
		cout << "3. Print heap's elements" << endl;
		cout << "4. Print heap as tree" << endl;
		cout << "5. Find specific element in the heap" << endl;
		cout << "6. Choose the other data structure" << endl;
		cin >> option;
		int number, index;
		cout << endl;

		switch (option) {
		case 1:
			number = loadNumber();
			insert(number); break;
		case 2:
			deleteRoot(); break;
		case 3:
			print(); break;
		case 4:
			printTree(); break;
		case 5:
			number = loadNumber();
			search(number); break;
		case 6:
			return;
		}
	}
}

int Heap::loadNumber() { //read numbers method
	int number;
	cout << "Give the number: ";
	cin >> number;
	cout << endl;
	return number;
}