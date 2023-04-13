#include <iostream>
#include "bidirectionalList.h"
#include "Time.h"
using namespace std;

struct ElemList {
	ElemList* prev;
	int data;
	ElemList* next;
};

bidirectionalList::bidirectionalList() {
	size = 0;
}

ElemList* head = nullptr; //head na poczatku nullptr

void bidirectionalList::addOnStart(int data) {
	Time timer;
	timer.startTimer();
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
	size++;
	timer.stopTimer();
}

void bidirectionalList::removeFromStart() {
	Time timer;
	timer.startTimer();
	if (head == nullptr) {
		cout << "Lista jest pusta!" << endl;
	}

	else if (head->next == nullptr) { //jesli w liscie jest tylko jeden element
		free(head); //zwolnienie pamieci
		head = NULL; //ustawienie wskaznika glowy na null
		size--;
	}

	else {
		head = head->next; //przesuniêcie g³owy na kolejny wêze³
		free(head->prev); //zwolnienie pamiêci by³ego wêz³a g³owy
		head->prev = NULL; //ustawienie wskaŸnika prev na NULL
		size--;
	}
	timer.stopTimer();
}

void bidirectionalList::addOnEnd(int data) {
	Time timer;
	timer.startTimer();
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
	size++;
	timer.stopTimer();
}

void bidirectionalList::removeFromEnd() {
	Time timer;
	timer.startTimer();
	if (head == nullptr) {
		cout << "Lista jest pusta!" << endl;
	}

	else if (head->next == nullptr) { //jesli w liscie jest tylko jeden element
		free(head); //zwolnienie pamieci
		head = NULL; //ustawienie wskaznika glowy na null
		size--;
	}

	else {
		ElemList* iterator = head;
		while (iterator->next != NULL) { //dopóki kolejny wêze³ nie jest nullem
			iterator = iterator->next; //iterujemy do ostatniego elementu w liœcie
		}
		
		iterator=iterator->prev;
		free(iterator->next); //zwolnienie pamiêci z ostatniego elementu listy
		iterator->next = NULL; //ustawienie wskaŸnika next na NULL
		size--;
	}
	timer.stopTimer();
}

void bidirectionalList::insert(int index, int data) {
	Time timer;
	timer.startTimer();
	ElemList* p = new ElemList; //nowy "wêze³"
	p->data = data;

	if (head == nullptr) { //jeœli lista jest pusta, tzn. g³owa to nullpointer
		p->prev = NULL; //wsk. na poprzedni NULL
		p->next = NULL; //wsk. na kolejny te¿ NULL
		head = p; //nowy wêze³ staje siê g³ow¹
	}

	else {
		if (index == 0) {
			addOnStart(data);
		}

		else if (index == size - 1) {
			addOnEnd(data);
		}

		else {	
			ElemList* iterator = head;
			for (size_t i = 0; i < index - 1; i++)
			{
				iterator = iterator->next;
			}

			ElemList* temp = iterator; //wêze³ tymczasowy
			temp = iterator->next;

			p->prev = iterator; //ustawienie wsk. na kolejny element w nowym wêŸle
			p->next = temp; //ustawienie wsk. na poprzedni element w nowym wêŸle

			iterator->next = p; //ustawienie wsk. na kolejny element w wêŸle "na lewo"
			temp->prev = p; //ustawienie wsk. na poprzedni element w wêŸle "na prawo"
		}
	}
	size++;
	timer.stopTimer();
}


void bidirectionalList::removeFromChosen(int index) {
	Time timer;
	timer.startTimer();

	if (head == nullptr) { 
		cout << "Lista jest pusta!" << endl;
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

			ElemList* temp; //wêze³ tymczasowy
			temp = iterator->next->next;
			temp->prev = iterator;
			free(iterator->next);
			iterator->next = temp;
		}
	}
	size++;
	timer.stopTimer();
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
		while (iterator->next != NULL) {
			iterator = iterator->next; //przeiterowanie do koñca listy
		}

		while (iterator != NULL) {
			cout << iterator->data << " ";
			iterator = iterator->prev; //cofniecie do poprzedniego wêz³a
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