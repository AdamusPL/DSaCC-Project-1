#include <iostream>
#include <fstream>
#include "bidirectionalList.h"
using namespace std;

struct ElemList {
	ElemList* prev;
	int data;
	ElemList* next;
};

bidirectionalList::bidirectionalList() {
	size = 0;
	head = nullptr;
	tail = nullptr;
}

void bidirectionalList::readData(int *tab, int s) { //dodanie element�w do listy z pliku tekstowego, gdy testujemy automatycznie
	size = s;
	for (int i = 0; i < s; i++) {
		addOnStart(tab[i]);
	}
}

void bidirectionalList::addOnStart(int data) {
	ElemList* p = new ElemList; //nowy "w�ze�"
	p->data = data; //dodane dane
	p->prev = NULL; //wsk. na poprzedni element NULL

	if (head == nullptr) { //je�li lista jest pusta, tzn. g�owa to nullpointer
		p->next = NULL; //wsk. na kolejny te� NULL
		head = p; //nowy w�ze� staje si� g�ow�
		tail = head;
	}

	else { //je�li lista nie jest pusta
		p->next = head; //wsk. na kolejny element to wska�nik na by�� g�ow�
		head->prev = p; //ustawienie wska�nika na wcze�niejszy element poprzedniej g�owy na nowo dodany w�ze�
		head = p; //nowy w�ze� staje si� g�ow�
	}
	
	size++;
}

void bidirectionalList::removeFromStart() {
	if (head == nullptr) {
		cout << "Lista jest pusta!" << endl;
	}

	else if (head->next == nullptr) { //jesli w liscie jest tylko jeden element
		free(head); //zwolnienie pamieci
		head = NULL; //ustawienie wskaznika glowy na null
		size--;
	}

	else {
		head = head->next; //przesuni�cie g�owy na kolejny w�ze�
		free(head->prev); //zwolnienie pami�ci by�ego w�z�a g�owy
		head->prev = NULL; //ustawienie wska�nika prev na NULL
		size--;
	}
}

void bidirectionalList::addOnEnd(int data) {
	ElemList* p = new ElemList; //nowy "w�ze�"
	p->data = data; //dodane dane
	p->next = NULL; //wsk. na kolejny element NULL

	if (head == nullptr) { //je�li lista jest pusta, tzn. g�owa to nullpointer
		p->prev = NULL; //wsk. na poprzedni te� NULL
		head = p; //nowy w�ze� staje si� g�ow�
		tail = head;
	}

	else { //je�li lista nie jest pusta
		p->prev = tail;
		tail->next = p;
		tail = p;
	}
	size++;
}

void bidirectionalList::removeFromEnd() {
	if (head == nullptr) {
		cout << "Lista jest pusta!" << endl;
	}

	else if (head->next == nullptr) { //jesli w liscie jest tylko jeden element
		free(head); //zwolnienie pamieci
		head = NULL; //ustawienie wskaznika glowy na null
		size--;
	}

	else {
		ElemList* previous = tail->prev;
		free(tail);
		previous->next = NULL;
		tail = previous;
		size--;
	}
}

void bidirectionalList::insert(int index, int data) {

	if (index > size || index < 0) {
		cout << "Niepoprawny indeks!" << endl;
		return;
	}

	ElemList* p = new ElemList; //nowy "w�ze�"
	p->data = data;

	if (head == nullptr) { //je�li lista jest pusta, tzn. g�owa to nullpointer
		p->prev = NULL; //wsk. na poprzedni NULL
		p->next = NULL; //wsk. na kolejny te� NULL
		head = p; //nowy w�ze� staje si� g�ow�
		size++;
	}

	else {
		if (index == 0) {
			bidirectionalList::addOnStart(data);
		}

		else if (index == size) {
			bidirectionalList::addOnEnd(data);
		}

		else {	
			ElemList* iterator = head;
			for (size_t i = 0; i < index - 1; i++)
			{
				iterator = iterator->next;
			}

			ElemList* temp = iterator; //w�ze� tymczasowy
			temp = iterator->next;

			p->prev = iterator; //ustawienie wsk. na kolejny element w nowym w�le
			p->next = temp; //ustawienie wsk. na poprzedni element w nowym w�le

			iterator->next = p; //ustawienie wsk. na kolejny element w w�le "na lewo"
			temp->prev = p; //ustawienie wsk. na poprzedni element w w�le "na prawo"
			size++;
		}
	}
}


void bidirectionalList::removeFromChosen(int index) {

	if (head == nullptr) { //je�li g�owa jest pusta
		cout << "Lista jest pusta!" << endl;
	}

	else if (index >= size || index<0) { //je�li podano niepoprawny indeks
		cout << "Taki indeks w tablicy nie istnieje!" << endl;
	}

	else {
		if (index == 0) {
			removeFromStart();
		}

		else if (index == size - 1) {
			removeFromEnd();
		}

		else {
			ElemList* iterator = head;
			for (size_t i = 0; i < index - 1; i++)
			{
				iterator = iterator->next;
			}

			ElemList* temp; //w�ze� tymczasowy
			temp = iterator->next->next;
			temp->prev = iterator;
			free(iterator->next);
			iterator->next = temp;
		}
		size--;
	}

}


void bidirectionalList::displayFromStart() {
	if (head == nullptr) {
		cout << "Lista jest pusta!" << endl;
	}
	else {
		ElemList* iterator = new ElemList;
		iterator = head;
		while (iterator != NULL) {
			cout << iterator->data << " ";
			iterator = iterator->next;
		}
		cout << endl;
	}
}

void bidirectionalList::displayFromEnd() {
	if (head == nullptr) {
		cout << "Lista jest pusta!" << endl;
	}

	else {
		ElemList* iterator = tail;

		while (iterator != NULL) {
			cout << iterator->data << " ";
			iterator = iterator->prev;
		}

		cout << endl;
	}
}

void bidirectionalList::find(int val) {
	int position = 0;
	ElemList* iterator = new ElemList;
	iterator = head;
	while (iterator != NULL) {
		if (val == iterator->data) {
			cout << val << " znajduje sie na pozycji: " << position << " od lewej strony" << endl;
			return;
		}
		position++;
		iterator = iterator->next;
	}
	cout << "Taka wartosc nie wystepuje w liscie!" << endl;
}

int bidirectionalList::middle() {
	ElemList* iterator = new ElemList;
	iterator = head;
	int i = 0;

	while (i != size / 2) {
		iterator = iterator->next;
		i++;
	}

	return iterator->data;
}

void bidirectionalList::menu() { //metoda menu
	int option = 1;
	while (option != 10) {
		cout << "Co chcesz zrobic:" << endl;
		cout << "1. Dodac element na poczatek" << endl;
		cout << "2. Dodac element na koniec" << endl;
		cout << "3. Dodac element na konkretne miejsce" << endl;
		cout << "4. Usunac element z poczatku" << endl;
		cout << "5. Usunac element z konca" << endl;
		cout << "6. Usunac element z konkretnej pozycji" << endl;
		cout << "7. Wyswietlic liste od poczatku" << endl;
		cout << "8. Wyswietlic liste od konca" << endl;
		cout << "9. Znajdz element w liscie" << endl;
		cout << "10. Inna struktura danych" << endl;
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
			displayFromStart(); break;
		case 8:
			displayFromEnd(); break;
		case 9:
			number = loadNumber();
			find(number); break;
		case 10: return;
		}
	}
}

int bidirectionalList::loadNumber() { //metoda do wpisywania liczb
	int number;
	cout << "Podaj liczbe: ";
	cin >> number;
	cout << endl;
	return number;
}

int bidirectionalList::loadIndex() { //metoda do wpisywania indeks�w
	int index;
	cout << "Podaj index: ";
	cin >> index;
	cout << endl;
	return index;
}