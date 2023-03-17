#include <iostream>
#include "bidirectionalList.h"
using namespace std;

struct ElemList {
	ElemList* prev;
	int data;
	ElemList* next;
};

bidirectionalList::bidirectionalList() {

}

ElemList* head = nullptr; //head na poczatku nullptr

void bidirectionalList::addOnStart(int data) {
	ElemList* p = new ElemList; //nowy "wêze³"
	p->data = data; //dodane dane
	p->prev = NULL; //wsk. na poprzedni element NULL

	if (head == nullptr) { //jeœli lista jest pusta, tzn. g³owa to nullpointer
		p->next = NULL; //wsk. na kolejny te¿ NULL
	}

	else { //jeœli lista nie jest pusta
		p->next = head; //wsk. na kolejny element to wskaŸnik na by³¹ g³owê
		head->prev = p; //ustawienie wskaŸnika na wczeœniejszy element poprzedniej g³owy na nowo dodany wêze³
	}
	head = p; //nowy wêze³ staje siê g³ow¹

}

void bidirectionalList::removeFromStart() {

}

void bidirectionalList::addOnEnd(int data) {
	ElemList* p = new ElemList; //nowy "wêze³"
	p->data = data; //dodane dane
	p->next = NULL; //wsk. na kolejny element NULL

	if (head == nullptr) { //jeœli lista jest pusta, tzn. g³owa to nullpointer
		p->prev = NULL; //wsk. na poprzedni te¿ NULL
		head = p; //nowy wêze³ staje siê g³ow¹
	}

	else { //jeœli lista nie jest pusta
		ElemList* iterator = new ElemList;
		iterator = head;

		while (iterator->next != NULL) { //dopóki kolejny wêze³ nie jest nullem
			iterator = iterator->next; //iterujemy do ostatniego elementu w liœcie
		}

		iterator->next = p; //ustawienie kolejnego elementu listy by³ego poprzedniego ostatniego elementu jako p

		p->prev = iterator; //ustawienie w nowym wêŸle wskaŸnika na poprzedni wêze³
	}
}

void bidirectionalList::removeFromEnd() {

}

void bidirectionalList::insert(int index, int data) {
	ElemList* p = new ElemList; //nowy "wêze³"
	p->data = data;

	if (head == nullptr) { //jeœli lista jest pusta, tzn. g³owa to nullpointer
		p->prev = NULL; //wsk. na poprzedni NULL
		p->next = NULL; //wsk. na kolejny te¿ NULL
		head = p; //nowy wêze³ staje siê g³ow¹
	}

	else {
		ElemList* iterator = head;
		for (size_t i = 0; i < index - 1; i++)
		{
			iterator = iterator->next;
		}

		p->prev = iterator;
		iterator->next = p;


	}
}

void bidirectionalList::removeFromChosen(int index) {

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
		ElemList* iterator = head;
		while (iterator != NULL) {
			cout << iterator->data << " ";
			iterator = iterator->prev;
		}
		cout << endl;
	}
}

void bidirectionalList::menu() { //metoda menu
	int option = 1;
	while (option != 9) {
		cout << "Co chcesz zrobic:" << endl;
		cout << "1. Dodac element na poczatek" << endl;
		cout << "2. Dodac element na koniec" << endl;
		cout << "3. Dodac element na konkretne miejsce" << endl;
		cout << "4. Usunac element z poczatku" << endl;
		cout << "5. Usunac element z konca" << endl;
		cout << "6. Usunac element z konkretnej pozycji" << endl;
		cout << "7. Wyswietlic liste od poczatku" << endl;
		cout << "8. Wyswietlic liste od konca" << endl;
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
			displayFromStart(); break;
		case 8:
			displayFromEnd(); break;
		case 9: return;
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

int bidirectionalList::loadIndex() { //metoda do wpisywania indeksów
	int index;
	cout << "Podaj index: ";
	cin >> index;
	cout << endl;
	return index;
}