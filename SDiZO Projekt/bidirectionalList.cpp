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
	ElemList* p = new ElemList; //nowy "w�ze�"
	p->data = data; //dodane dane
	p->prev = NULL; //wsk. na poprzedni element NULL

	if (head == nullptr) { //je�li lista jest pusta, tzn. g�owa to nullpointer
		p->next = NULL; //wsk. na kolejny te� NULL
	}

	else { //je�li lista nie jest pusta
		p->next = head; //wsk. na kolejny element to wska�nik na by�� g�ow�
		head->prev = p; //ustawienie wska�nika na wcze�niejszy element poprzedniej g�owy na nowo dodany w�ze�
	}

	head = p; //nowy w�ze� staje si� g�ow�
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
		head = head->next; //przesuni�cie g�owy na kolejny w�ze�
		free(head->prev); //zwolnienie pami�ci by�ego w�z�a g�owy
		head->prev = NULL; //ustawienie wska�nika prev na NULL
		size--;
	}
	timer.stopTimer();
}

void bidirectionalList::addOnEnd(int data) {
	Time timer;
	timer.startTimer();
	ElemList* p = new ElemList; //nowy "w�ze�"
	p->data = data; //dodane dane
	p->next = NULL; //wsk. na kolejny element NULL

	if (head == nullptr) { //je�li lista jest pusta, tzn. g�owa to nullpointer
		p->prev = NULL; //wsk. na poprzedni te� NULL
		head = p; //nowy w�ze� staje si� g�ow�
	}

	else { //je�li lista nie jest pusta
		ElemList* iterator = new ElemList;
		iterator = head;

		while (iterator->next != NULL) { //dop�ki kolejny w�ze� nie jest nullem
			iterator = iterator->next; //iterujemy do ostatniego elementu w li�cie
		}

		iterator->next = p; //ustawienie kolejnego elementu listy by�ego poprzedniego ostatniego elementu jako p

		p->prev = iterator; //ustawienie w nowym w�le wska�nika na poprzedni w�ze�
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
		while (iterator->next != NULL) { //dop�ki kolejny w�ze� nie jest nullem
			iterator = iterator->next; //iterujemy do ostatniego elementu w li�cie
		}
		
		iterator=iterator->prev;
		free(iterator->next); //zwolnienie pami�ci z ostatniego elementu listy
		iterator->next = NULL; //ustawienie wska�nika next na NULL
		size--;
	}
	timer.stopTimer();
}

void bidirectionalList::insert(int index, int data) {
	Time timer;
	timer.startTimer();
	ElemList* p = new ElemList; //nowy "w�ze�"
	p->data = data;

	if (head == nullptr) { //je�li lista jest pusta, tzn. g�owa to nullpointer
		p->prev = NULL; //wsk. na poprzedni NULL
		p->next = NULL; //wsk. na kolejny te� NULL
		head = p; //nowy w�ze� staje si� g�ow�
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

			ElemList* temp = iterator; //w�ze� tymczasowy
			temp = iterator->next;

			p->prev = iterator; //ustawienie wsk. na kolejny element w nowym w�le
			p->next = temp; //ustawienie wsk. na poprzedni element w nowym w�le

			iterator->next = p; //ustawienie wsk. na kolejny element w w�le "na lewo"
			temp->prev = p; //ustawienie wsk. na poprzedni element w w�le "na prawo"
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

			ElemList* temp; //w�ze� tymczasowy
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
			iterator = iterator->next; //przeiterowanie do ko�ca listy
		}

		while (iterator != NULL) {
			cout << iterator->data << " ";
			iterator = iterator->prev; //cofniecie do poprzedniego w�z�a
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

int bidirectionalList::loadIndex() { //metoda do wpisywania indeks�w
	int index;
	cout << "Podaj index: ";
	cin >> index;
	cout << endl;
	return index;
}