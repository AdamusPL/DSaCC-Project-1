#include <iostream>
#include "Heap.h"
using namespace std;

Heap::Heap() {
	size = 0;
	data = new int[size];
	isOccupied = new bool[size];
}

//w wariancie z tablic¹!!!!!!!!
void Heap::add(int val) {
	int* tempArray = new int[size+1];

	if (size == 0) {
		*data = val;
		*isOccupied = true;
	}

	else {

	}
	size++;
}

void Heap::removeFromPeak() {
	
}

void Heap::menu() { //metoda menu
	int option = 1;
	while (option != 3) {
		cout << "Co chcesz zrobic:" << endl;
		cout << "1. Dodac element do kopca" << endl;
		cout << "2. Usunac szczyt kopca" << endl;
		cout << "3. Inna struktura danych" << endl;
		cin >> option;
		int number, index;
		cout << endl;

		switch (option) {
		case 1:
			number = loadNumber();
			add(number); break;
		case 2:
			removeFromPeak(); break;
		case 3:
			return;
		}
	}
}

int Heap::loadNumber() { //metoda do wpisywania liczb
	int number;
	cout << "Podaj liczbe: ";
	cin >> number;
	cout << endl;
	return number;
}