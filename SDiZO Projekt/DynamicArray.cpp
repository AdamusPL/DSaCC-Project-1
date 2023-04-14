#include "DynamicArray.h"
#include "Time.h"
using namespace std;

DynamicArray::DynamicArray() {
	size = 0;
	array = new int[size];
}

DynamicArray::DynamicArray(int *d, int s) {
	size = s;
	array = d;
}

void DynamicArray::addOnStart(int data) {
	Time timer;
	timer.startTimer();
	int* tempArray = new int[size + 1]; //definicja tymczasowej tablicy dynamicznej o rozmiarze o 1 wi�kszym
	*tempArray = data; //element 0. = data (dodawana warto��)

	for (size_t i = 0; i < size; i++)
	{
		tempArray[i + 1] = array[i]; //dodanie reszty wartosci do tymczasowej tablicy
	}

	size++; //zwiekszenie rozmiaru tablicy

	delete[] array; //zwolnienie pamieci

	array = tempArray; //przypisanie tempArray do aktualnego arraya
	timer.stopTimer();
}

void DynamicArray::removeFromStart() {
	Time timer;
	timer.startTimer();

	if (size == 0) {
		cout << "Tablica jest pusta!" << endl;
	}

	else {
		int* tempArray = new int[size - 1]; //definicja tymczasowej tablicy dynamicznej o rozmiarze o 1 mniejszym
		for (size_t i = 0; i < size; i++)
		{
			tempArray[i] = array[i + 1]; //dodanie reszty wartosci do tymczasowej tablicy
		}
		size--;

		delete[] array;

		array = tempArray;
	}
	timer.stopTimer();
}

void DynamicArray::addOnEnd(int data) {
	Time timer;
	timer.startTimer();
	int* tempArray = new int[size + 1];

	for (size_t i = 0; i < size; i++)
	{
		tempArray[i] = array[i];
	}

	tempArray[size] = data;

	size++;

	delete[] array;

	array = tempArray;
	timer.stopTimer();
}

void DynamicArray::removeFromEnd() {
	Time timer;
	timer.startTimer();

	if (size == 0) {
		cout << "Tablica jest pusta!" << endl;
	}

	else {
		int* tempArray = new int[size - 1];
		for (size_t i = 0; i < size - 1; i++)
		{
			tempArray[i] = array[i]; //dodanie reszty wartosci do tymczasowej tablicy
		}

		size--;

		delete[] array;

		array = tempArray;
	}

	timer.stopTimer();
}

void DynamicArray::insert(int index, int data) {
	Time timer;
	timer.startTimer();

	if (index > size || index < 0) { //je�li podano ujemny indeks lub indeks spoza zakresu
		cout << "Niepoprawny indeks!" << endl;
	}

	else {
		int* tempArray = new int[size + 1];

		for (size_t i = 0; i < index; i++)
		{
			tempArray[i] = array[i]; //przypisanie wartosci do tablicy tymczasowej do podanego indeksu
		}

		tempArray[index] = data; //wstawienie nowej warto�ci do arraya

		for (size_t i = index; i < size; i++)
		{
			tempArray[i + 1] = array[i]; //wype�nienie pozosta�ymi
		}

		size++;

		delete[] array;

		array = tempArray;
	}
	
	timer.stopTimer();
}

void DynamicArray::removeFromChosen(int index) {
	Time timer;
	timer.startTimer();

	if (index >= size || index < 0) { //je�li podano ujemny indeks lub spoza zakresu
		cout << "Niepoprawny indeks!" << endl;
	}

	else {
		int* tempArray = new int[size - 1];
		for (size_t i = 0; i < index; i++)
		{
			tempArray[i] = array[i]; //dodanie reszty wartosci do tymczasowej tablicy
		}

		size--;

		for (size_t i = index; i < size; i++)
		{
			tempArray[i] = array[i + 1]; //dodanie reszty wartosci do tymczasowej tablicy
		}

		delete[] array;

		array = tempArray;
	}

	timer.stopTimer();
}

void DynamicArray::display() {
	if (size == 0) {
		cout << "Tablica jest pusta!" << endl;
	}
	else {
		for (size_t i = 0; i < size; i++)
		{
			cout << "t[" << i << "]=" << array[i] << endl;
			//cout<<*(array+i)<<endl;
		}
	}
	cout << endl;
}

void DynamicArray::menu() { //metoda menu
	int option = 1;
	while (option != 8) {
		cout << "Co chcesz zrobic:" << endl;
		cout << "1. Dodac element na poczatek" << endl;
		cout << "2. Dodac element na koniec" << endl;
		cout << "3. Dodac element na konkretne miejsce" << endl;
		cout << "4. Usunac element z poczatku" << endl;
		cout << "5. Usunac element z konca" << endl;
		cout << "6. Usunac element z konkretnej pozycji" << endl;
		cout << "7. Wyswietlic tablice" << endl;
		cout << "8. Inna struktura danych" << endl;
		cin >> option;
		int number, index;
		cout << endl;

		switch (option) {
		case 1:
			number = loadNumber();
			addOnStart(number); break;
		case 2:
			number = loadNumber();
			addOnEnd(number); break;
		case 3:
			number = loadNumber();
			index = loadIndex();
			insert(index, number); break;
		case 4:
			removeFromStart(); break;
		case 5:
			removeFromEnd(); break;
		case 6:
			index = loadIndex();
			removeFromChosen(index); break;
		case 7:
			display(); break;
		case 8: return;
		}
	}
}

int DynamicArray::loadNumber() { //metoda do wpisywania liczb
	int number;
	cout << "Podaj liczbe: ";
	cin >> number;
	cout << endl;
	return number;
}

int DynamicArray::loadIndex() { //metoda do wpisywania indeks�w
	int index;
	cout << "Podaj index: ";
	cin >> index;
	cout << endl;
	return index;
}