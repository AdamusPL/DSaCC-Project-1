#include "AutoTests.h"
#include "RandomGenerator.h"
#include "RWFile.h"
#include "DynamicArray.h"
#include "bidirectionalList.h"
#include "Heap.h"
#include "Time.h"

void AutoTests::testDynamicArray() {
	RandomGenerator rng;
	RWFile rF;
	Time timer;
	int* results = new int[10]; //tablica na rezultaty testow, ktora potem zostanie wpisana do pliku txt

	//addOnStart
	for (int i = 0; i < 10; i++) { //10 testow
		rng.generatePopulation(); //stworzenie pliku txt z losowymi liczbami
		int size = 0;
		int* tab=rF.readFromFile(size); //wczytanie zawartosci tego txt
		DynamicArray arr = DynamicArray(tab,size);
		int val = rng.generateRandomNumber(); //wylosowanie wartosci do wpisania do tablicy
		timer.startTimer(); //wystartowanie timera
		arr.addOnStart(val);
		int time = timer.stopTimer(); //zatrzymanie timera
		results[i] = time;
		arr.display(); //wyswietlenie zawartosci tablicy
	}

	rF.writeResultsToFile("testArray.txt", results);

	//removeFromStart
	for (int i = 0; i < 10; i++) { //10 testow
		rng.generatePopulation(); //stworzenie pliku txt z losowymi liczbami
		int size = 0;
		int* tab = rF.readFromFile(size); //wczytanie zawartosci tego txt
		DynamicArray arr = DynamicArray(tab, size);
		int val = rng.generateRandomNumber(); //wylosowanie wartosci do wpisania do tablicy
		timer.startTimer(); //wystartowanie timera
		arr.removeFromStart();
		int time = timer.stopTimer(); //zatrzymanie timera
		results[i] = time;
		arr.display(); //wyswietlenie zawartosci tablicy
	}

	rF.writeResultsToFile("testArray.txt", results);

}

void AutoTests::testBidirectionalList() {
	for (int i = 0; i < 10; i++) {

	}
}

void AutoTests::testHeap() {
	for (int i = 0; i < 10; i++) {

	}
}

void AutoTests::choice(int option) {
	switch (option) {
	case 1:
		testDynamicArray(); break;
	
	case 2:
		testBidirectionalList(); break;
	case 3:
		testHeap(); break;
	}
}