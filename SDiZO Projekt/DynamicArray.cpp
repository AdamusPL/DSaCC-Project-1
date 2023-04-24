#include "DynamicArray.h"
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
	int* tempArray = new int[size + 1]; //definicja tymczasowej tablicy dynamicznej o rozmiarze o 1 wiêkszym
	*tempArray = data; //element 0. = data (dodawana wartoœæ)

	for (size_t i = 0; i < size; i++)
	{
		tempArray[i + 1] = array[i]; //dodanie reszty wartosci do tymczasowej tablicy
	}

	size++; //zwiekszenie rozmiaru tablicy

	delete[] array; //zwolnienie pamieci

	array = tempArray; //przypisanie tempArray do aktualnego arraya
}

void DynamicArray::removeFromStart() {

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
}

void DynamicArray::addOnEnd(int data) {
	int* tempArray = new int[size + 1];

	for (size_t i = 0; i < size; i++)
	{
		tempArray[i] = array[i];
	}

	tempArray[size] = data;

	size++;

	delete[] array;

	array = tempArray;
}

void DynamicArray::removeFromEnd() {

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
}

void DynamicArray::insert(int index, int data) {

	if (index > size || index < 0) { //jeœli podano ujemny indeks lub indeks spoza zakresu
		cout << "Niepoprawny indeks!" << endl;
	}

	else {
		int* tempArray = new int[size + 1];

		for (size_t i = 0; i < index; i++)
		{
			tempArray[i] = array[i]; //przypisanie wartosci do tablicy tymczasowej do podanego indeksu
		}

		tempArray[index] = data; //wstawienie nowej wartoœci do arraya

		for (size_t i = index; i < size; i++)
		{
			tempArray[i + 1] = array[i]; //wype³nienie pozosta³ymi
		}

		size++;

		delete[] array;

		array = tempArray;
	}

}

void DynamicArray::removeFromChosen(int index) {

	if (index >= size || index < 0) { //jeœli podano ujemny indeks lub spoza zakresu
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
	cout << endl << endl;
}

void DynamicArray::displayTests() {
	if (size == 0) {
		cout << "Tablica jest pusta!" << endl;
	}

	else {
		for (size_t i = 0; i < size; i++)
		{
			cout << array[i] <<" ";
			//cout<<*(array+i)<<endl;
		}
	}
	cout << endl;
}

void DynamicArray::find(int val) {

	for (int i = 0; i < size; i++) {
		if (val == array[i]) {
			cout << val << " znajduje sie na indeksie: " << i << endl;
			return;
		}
	}
	
	cout << "Nie ma takiej wartosci w tablicy!" << endl;

}

void DynamicArray::menu() { //metoda menu
	int option = 1;
	while (option != 9) {
		cout << "Co chcesz zrobic:" << endl;
		cout << "=====================================" << endl;
		cout << "1. Dodac element na poczatek" << endl;
		cout << "2. Dodac element na koniec" << endl;
		cout << "3. Dodac element na konkretne miejsce" << endl;
		cout << "4. Usunac element z poczatku" << endl;
		cout << "5. Usunac element z konca" << endl;
		cout << "6. Usunac element z konkretnej pozycji" << endl;
		cout << "7. Wyswietlic tablice" << endl;
		cout << "8. Znajdz element w tablicy" << endl;
		cout << "9. Inna struktura danych" << endl;
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
		case 8:
			number = loadNumber();
			find(number); break;
		case 9: return;
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

int DynamicArray::loadIndex() { //metoda do wpisywania indeksów
	int index;
	cout << "Podaj index: ";
	cin >> index;
	cout << endl;
	return index;
}