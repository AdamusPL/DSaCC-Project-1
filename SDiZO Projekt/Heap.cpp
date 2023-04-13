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

		while (k != 0) { //naprawa kopca w g�r�
			if (tempData[k] > tempData[(k - 1) / 2]) { //jesli wstawiany w�ze� jest wi�kszy od jego aktualnego ojca
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

//naprawi�!!!!!!
void Heap::removeFromPeak() {
	Time timer;
	timer.startTimer();
	if (size == 0) { //je�li rozmiar tablicy = 0
		cout << "Kopiec jest pusty!" << endl;
		return;
	}

	int* tempData = new int[size - 1]; //tymczasowa tablica z danymi
	tempData[0] = data[size-1]; //zamiana korzenia z ostatnim elementem tablicy

	for (size_t i = 1; i < size-1; i++)
	{
		tempData[i] = data[i]; //przekopiowanie pozostalych wartosci z poprzedniego kopca
	}

	int k = 0; //naprawa kopca w d�
	while (2*k+2<=size-1) { //dop�ki nie dotarli�my do li�cia
		if ((2 * k + 1 < size-1) && (2 * k + 2 < size-1)) { //je�li rodzic ma 2 syn�w
			if (tempData[2 * k + 1] < tempData[2 * k + 2]) { //je�li prawy syn wi�kszy
				if (tempData[k] < tempData[2 * k + 2]) { //je�li rodzic mniejszy od syna
					swap(tempData[k], tempData[2 * k + 2]);
					k = 2 * k + 2;
					for (size_t i = 0; i < size-1; i++)
					{
						cout << "t[" << i << "]=" << data[i] << endl;
					}
					cout << endl;
				}
				else break; //je�li wi�kszy, zako�cz algorytm naprawy
			}

			else { //je�li lewy syn wi�kszy
				if (tempData[k] < tempData[2 * k + 1]) { //je�li rodzic mniejszy od syna
					swap(tempData[k], tempData[2 * k + 1]);
					k = 2 * k + 1;
					for (size_t i = 0; i < size-1; i++)
					{
						cout << "t[" << i << "]=" << data[i] << endl;
					}
					cout << endl;
				}
				else break; //je�li wi�kszy, zako�cz algorytm naprawy
			}
		}

		else if ((2 * k + 1 >= size - 1) && (2 * k + 2 < size - 1)) { //je�li tylko prawy syn istnieje
			if (tempData[k] < tempData[2 * k + 2]) { //je�li rodzic mniejszy od syna
				swap(tempData[k], tempData[2 * k + 2]);
				k = 2 * k + 2;
			}
			else break; //je�li wi�kszy, zako�cz algorytm naprawy
		}

		else if ((2 * k + 1 < size - 1) && (2 * k + 2 >= size - 1)) { //je�li tylko lewy syn istnieje
			if (tempData[k] < tempData[2 * k + 1]) { //je�li rodzic mniejszy od syna
				swap(tempData[k], tempData[2 * k + 1]);
				k = 2 * k + 1;
			}
			else break; //je�li wi�kszy, zako�cz algorytm naprawy
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