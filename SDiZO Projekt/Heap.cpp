#include <iostream>
#include "Heap.h"
using namespace std;

Heap::Heap() {
	size = 0;
	data = new int[size];
	isOccupied = new bool[size];
}

void Heap::add(int val) {
	int* tempData = new int[size+1]; //tymczasowa tablica z danymi

	if (size == 0) {
		*tempData = val;
	}

	else {
		int k = size;

		for (size_t i = 0; i < size; i++)
		{
			tempData[i] = data[i]; //wpisanie wszystkich wartosci do tempArray
		}

		tempData[k] = val; //wpisanie nowej wartosci w ostatnie miejsce tablicy

		while (k != 0) {
			if (tempData[k] > tempData[(k - 1) / 2]) { //jesli wstawiany wêze³ jest wiêkszy od jego aktualnego ojca
				swap(tempData[k], tempData[(k - 1) / 2]); //zamieniamy
				k = (k - 1) / 2;
			}

			else break;

		}
	}

	delete[] data;
	data = tempData;
	size++;
}

//naprawiæ!!!!!!
void Heap::removeFromPeak() {
	if (size == 0) {
		cout << "Kopiec jest pusty!" << endl;
		return;
	}

	int* tempData = new int[size - 1]; //tymczasowa tablica z danymi
	tempData[0] = data[size-1]; //zamiana korzenia z ostatnim elementem tablicy

	for (size_t i = 1; i < size-1; i++)
	{
		tempData[i] = data[i];
	}

	int k = 0;
	while (k != size) {
		if (tempData[2 * k + 1] < tempData[2 * k + 2]) { //sprawdzenie który syn jest wiêkszy
			if (tempData[k] < tempData[2 * k + 2]) { //sprawdzenie 
				swap(tempData[k], tempData[2 * k + 2]);
				k = 2 * k + 2;
			}
			else break;
		}
		
		else {
			if (tempData[k] < tempData[2 * k + 1]) {
				swap(tempData[k], tempData[2 * k + 1]);
				k = 2 * k + 1;
			}
			else break;
		}

		
	}

	delete[] data;
	data = tempData;
	size++;
}

void Heap::display() {
	if (size == 0) {
		cout << "Kopiec jest pusty!" << endl;
		return;
	}

	for (size_t i = 0; i < size; i++)
	{
		cout << "t[" << i << "]=" << data[i] << endl;
	}
}

void Heap::menu() { //metoda menu
	int option = 1;
	while (option != 4) {
		cout << "Co chcesz zrobic:" << endl;
		cout << "1. Dodac element do kopca" << endl;
		cout << "2. Usunac szczyt kopca" << endl;
		cout << "3. Wyswielt elementy kopca" << endl;
		cout << "4. Inna struktura danych" << endl;
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
			display(); break;
		case 4:
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