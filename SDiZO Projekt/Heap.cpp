#include <iostream>
#include "Heap.h"
#include "Tests.h"
#include "Time.h"
using namespace std;

Heap::Heap() {
	size = 0;
	data = new int[size];
	isOccupied = new bool[size];
}

Heap::Heap(int *d, int s) {
	data = d;
	size = s;
	isOccupied = new bool[size];
}

void Heap::add(int val) {
	Time timer;
	timer.startTimer();
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

		while (k != 0) { //naprawa kopca w górê
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
	timer.stopTimer();
}

//naprawiæ!!!!!!
void Heap::removeFromPeak() {
	Time timer;
	timer.startTimer();
	if (size == 0) { //jeœli rozmiar tablicy = 0
		cout << "Kopiec jest pusty!" << endl;
		return;
	}

	int* tempData = new int[size - 1]; //tymczasowa tablica z danymi
	tempData[0] = data[size-1]; //zamiana korzenia z ostatnim elementem tablicy

	for (size_t i = 1; i < size-1; i++)
	{
		tempData[i] = data[i]; //przekopiowanie pozostalych wartosci z poprzedniego kopca
	}

	int k = 0; //naprawa kopca w dó³
	while (2*k+2<=size-1) { //dopóki nie dotarliœmy do liœcia
		if ((2 * k + 1 < size-1) && (2 * k + 2 < size-1)) { //jeœli rodzic ma 2 synów
			if (tempData[2 * k + 1] < tempData[2 * k + 2]) { //jeœli prawy syn wiêkszy
				if (tempData[k] < tempData[2 * k + 2]) { //jeœli rodzic mniejszy od syna
					swap(tempData[k], tempData[2 * k + 2]);
					k = 2 * k + 2;
					for (size_t i = 0; i < size-1; i++)
					{
						cout << "t[" << i << "]=" << data[i] << endl;
					}
					cout << endl;
				}
				else break; //jeœli wiêkszy, zakoñcz algorytm naprawy
			}

			else { //jeœli lewy syn wiêkszy
				if (tempData[k] < tempData[2 * k + 1]) { //jeœli rodzic mniejszy od syna
					swap(tempData[k], tempData[2 * k + 1]);
					k = 2 * k + 1;
					for (size_t i = 0; i < size-1; i++)
					{
						cout << "t[" << i << "]=" << data[i] << endl;
					}
					cout << endl;
				}
				else break; //jeœli wiêkszy, zakoñcz algorytm naprawy
			}
		}

		else if ((2 * k + 1 >= size - 1) && (2 * k + 2 < size - 1)) { //jeœli tylko prawy syn istnieje
			if (tempData[k] < tempData[2 * k + 2]) { //jeœli rodzic mniejszy od syna
				swap(tempData[k], tempData[2 * k + 2]);
				k = 2 * k + 2;
			}
			else break; //jeœli wiêkszy, zakoñcz algorytm naprawy
		}

		else if ((2 * k + 1 < size - 1) && (2 * k + 2 >= size - 1)) { //jeœli tylko lewy syn istnieje
			if (tempData[k] < tempData[2 * k + 1]) { //jeœli rodzic mniejszy od syna
				swap(tempData[k], tempData[2 * k + 1]);
				k = 2 * k + 1;
			}
			else break; //jeœli wiêkszy, zakoñcz algorytm naprawy
		}
	}

	size--;
	delete[] data;
	data = tempData;
	timer.stopTimer();
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
		cout << "3. Wyswietl elementy kopca" << endl;
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