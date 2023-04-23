#include "AutoTests.h"
#include "RandomGenerator.h"
#include "RWFile.h"
#include "DynamicArray.h"
#include "bidirectionalList.h"
#include "Heap.h"
#include "BSTTree.h"
#include "Time.h"

//-----------------------------------Testy tablicy dynamicznej----------------
void AutoTests::testDynamicArray() {
	//RandomGenerator rng;
	//RWFile rF;
	//Time timer;
	//int* results = new int[10]; //tablica na rezultaty testow, ktora potem zostanie wpisana do pliku txt

	////addOnStart
	//for (int i = 0; i < 10; i++) { //10 testow
	//	rng.generatePopulation(); //stworzenie pliku txt z losowymi liczbami
	//	int size = 0;
	//	int* tab=rF.readFromFile(size); //wczytanie zawartosci tego txt
	//	DynamicArray arr = DynamicArray(tab,size);
	//	int val = rng.generateRandomNumber(); //wylosowanie wartosci do wpisania do tablicy
	//	timer.startTimer(); //wystartowanie timera
	//	arr.addOnStart(val);
	//	int time = timer.stopTimer(); //zatrzymanie timera
	//	results[i] = time;
	//	//arr.displayTests(); //wyswietlenie zawartosci tablicy
	//}

	//rF.writeResultsToFile("testArrayAOS.txt", results);

	////removeFromStart
	//for (int i = 0; i < 10; i++) { //10 testow
	//	rng.generatePopulation(); //stworzenie pliku txt z losowymi liczbami
	//	int size = 0;
	//	int* tab = rF.readFromFile(size); //wczytanie zawartosci tego txt
	//	DynamicArray arr = DynamicArray(tab, size);
	//	timer.startTimer(); //wystartowanie timera
	//	arr.removeFromStart();
	//	int time = timer.stopTimer(); //zatrzymanie timera
	//	results[i] = time;
	//	//arr.displayTests(); //wyswietlenie zawartosci tablicy
	//}

	//rF.writeResultsToFile("testArrayRFS.txt", results);

	////addOnEnd
	//for (int i = 0; i < 10; i++) { //10 testow
	//	rng.generatePopulation(); //stworzenie pliku txt z losowymi liczbami
	//	int size = 0;
	//	int* tab = rF.readFromFile(size); //wczytanie zawartosci tego txt
	//	DynamicArray arr = DynamicArray(tab, size);
	//	int val = rng.generateRandomNumber(); //wylosowanie wartosci do wpisania do tablicy
	//	timer.startTimer(); //wystartowanie timera
	//	arr.addOnEnd(val);
	//	int time = timer.stopTimer(); //zatrzymanie timera
	//	results[i] = time;
	//	//arr.displayTests(); //wyswietlenie zawartosci tablicy
	//}

	//rF.writeResultsToFile("testArrayAOE.txt", results);

	////removeFromEnd
	//for (int i = 0; i < 10; i++) { //10 testow
	//	rng.generatePopulation(); //stworzenie pliku txt z losowymi liczbami
	//	int size = 0;
	//	int* tab = rF.readFromFile(size); //wczytanie zawartosci tego txt
	//	DynamicArray arr = DynamicArray(tab, size);
	//	timer.startTimer(); //wystartowanie timera
	//	arr.removeFromEnd();
	//	int time = timer.stopTimer(); //zatrzymanie timera
	//	results[i] = time;
	//	//arr.displayTests(); //wyswietlenie zawartosci tablicy
	//}

	//rF.writeResultsToFile("testArrayRFE.txt", results);

	////insert
	//for (int i = 0; i < 10; i++) { //10 testow
	//	rng.generatePopulation(); //stworzenie pliku txt z losowymi liczbami
	//	int size = 0;
	//	int* tab = rF.readFromFile(size); //wczytanie zawartosci tego txt
	//	DynamicArray arr = DynamicArray(tab, size);
	//	int val = rng.generateRandomNumber(); //wylosowanie wartosci do wpisania do tablicy
	//	timer.startTimer(); //wystartowanie timera
	//	arr.insert(arr.size/2,val);
	//	int time = timer.stopTimer(); //zatrzymanie timera
	//	results[i] = time;
	//	//arr.displayTests(); //wyswietlenie zawartosci tablicy
	//}

	//rF.writeResultsToFile("testArrayI.txt", results);

	////removeFromChosen
	//for (int i = 0; i < 10; i++) { //10 testow
	//	rng.generatePopulation(); //stworzenie pliku txt z losowymi liczbami
	//	int size = 0;
	//	int* tab = rF.readFromFile(size); //wczytanie zawartosci tego txt
	//	DynamicArray arr = DynamicArray(tab, size);
	//	timer.startTimer(); //wystartowanie timera
	//	arr.removeFromChosen(arr.size/2);
	//	int time = timer.stopTimer(); //zatrzymanie timera
	//	results[i] = time;
	//	//arr.displayTests(); //wyswietlenie zawartosci tablicy
	//}

	//rF.writeResultsToFile("testArrayRFC.txt", results);

	////find naprawic jeszcze bo nie zawsze srodkowy element wyszukuje, przez to ze czasem jest kilka kluczy o tych samych wartosciach w strukturze
	//for (int i = 0; i < 10; i++) { //10 testow
	//	rng.generatePopulation(); //stworzenie pliku txt z losowymi liczbami
	//	int size = 0;
	//	int* tab = rF.readFromFile(size); //wczytanie zawartosci tego txt
	//	DynamicArray arr = DynamicArray(tab, size);
	//	cout << "Rozmiar tablicy: " << arr.size << endl;
	//	int val = arr.array[arr.size / 2]; //œrodkowy element tablicy zeby znalazl
	//	timer.startTimer(); //wystartowanie timera
	//	arr.find(val);
	//	int time = timer.stopTimer(); //zatrzymanie timera
	//	results[i] = time;
	//	//arr.displayTests(); //wyswietlenie zawartosci tablicy
	//}

	//rF.writeResultsToFile("testArrayF.txt", results);
}








//-----------------Testy listy dwukierunkowej---------------
void AutoTests::testBidirectionalList() { //pozmieniac na biL
	RandomGenerator rng;
	RWFile rF;
	Time timer;
	double* results = new double[10]; //tablica na rezultaty testow, ktora potem zostanie wpisana do pliku txt

	////addOnStart
	//for (int i = 0; i < 1; i++) { //10 testow
	//	rng.generatePopulation(); //stworzenie pliku txt z losowymi liczbami
	//	int size = 0;
	//	int* tab=rF.readFromFile(size); //wczytanie zawartosci tego txt
	//	bidirectionalList biL;
	//	biL.readData(tab,size);
	//	int val = rng.generateRandomNumber(); //wylosowanie wartosci do wpisania do tablicy
	//	timer.startTimer(); //wystartowanie timera
	//	biL.addOnStart(val);
	//	double time = timer.stopTimer(); //zatrzymanie timera
	//	results[i] = time;
	//	//arr.displayTests(); //wyswietlenie zawartosci tablicy
	//}

	//rF.writeResultsToFile("testBiLAOS.txt", results);

	////removeFromStart
	//for (int i = 0; i < 10; i++) { //10 testow
	//	rng.generatePopulation(); //stworzenie pliku txt z losowymi liczbami
	//	int size = 0;
	//	int* tab = rF.readFromFile(size); //wczytanie zawartosci tego txt
	//	bidirectionalList biL;
	//	biL.readData(tab, size);
	//	timer.startTimer(); //wystartowanie timera
	//	biL.removeFromStart();
	//	double time = timer.stopTimer(); //zatrzymanie timera
	//	results[i] = time;
	//	//arr.displayTests(); //wyswietlenie zawartosci tablicy
	//}

	//rF.writeResultsToFile("testBiLRFS.txt", results);

	//addOnEnd
	for (int i = 0; i < 10; i++) { //10 testow
		rng.generatePopulation(); //stworzenie pliku txt z losowymi liczbami
		int size = 0;
		int* tab = rF.readFromFile(size); //wczytanie zawartosci tego txt
		bidirectionalList biL;
		biL.readData(tab, size);
		int val = rng.generateRandomNumber(); //wylosowanie wartosci do wpisania do tablicy
		timer.startTimer(); //wystartowanie timera
		biL.addOnEnd(val);
		double time = timer.stopTimer(); //zatrzymanie timera
		results[i] = time;
		//arr.displayTests(); //wyswietlenie zawartosci tablicy
	}

	rF.writeResultsToFile("testBiLAOE.txt", results);

	//removeFromEnd
	for (int i = 0; i < 10; i++) { //10 testow
		rng.generatePopulation(); //stworzenie pliku txt z losowymi liczbami
		int size = 0;
		int* tab = rF.readFromFile(size); //wczytanie zawartosci tego txt
		bidirectionalList biL;
		biL.readData(tab, size);
		timer.startTimer(); //wystartowanie timera
		biL.removeFromEnd();
		double time = timer.stopTimer(); //zatrzymanie timera
		results[i] = time;
		//arr.displayTests(); //wyswietlenie zawartosci tablicy
	}

	rF.writeResultsToFile("testBiLRFE.txt", results);

	//insert
	//for (int i = 0; i < 10; i++) { //10 testow
	//	rng.generatePopulation(); //stworzenie pliku txt z losowymi liczbami
	//	int size = 0;
	//	int* tab = rF.readFromFile(size); //wczytanie zawartosci tego txt
	//	bidirectionalList biL;
	//	biL.readData(tab, size);
	//	int val = rng.generateRandomNumber(); //wylosowanie wartosci do wpisania do tablicy
	//	timer.startTimer(); //wystartowanie timera
	//	biL.insert(biL.size/2,val);
	//	double time = timer.stopTimer(); //zatrzymanie timera
	//	results[i] = time;
	//	//arr.displayTests(); //wyswietlenie zawartosci tablicy
	//}

	//rF.writeResultsToFile("testBiLI.txt", results);

	////removeFromChosen
	//for (int i = 0; i < 10; i++) { //10 testow
	//	rng.generatePopulation(); //stworzenie pliku txt z losowymi liczbami
	//	int size = 0;
	//	int* tab = rF.readFromFile(size); //wczytanie zawartosci tego txt
	//	bidirectionalList biL;
	//	biL.readData(tab, size);
	//	timer.startTimer(); //wystartowanie timera
	//	biL.removeFromChosen(biL.size/2);
	//	double time = timer.stopTimer(); //zatrzymanie timera
	//	results[i] = time;
	//	//arr.displayTests(); //wyswietlenie zawartosci tablicy
	//}

	//rF.writeResultsToFile("testBiLRFC.txt", results);

	////find
	//for (int i = 0; i < 10; i++) { //10 testow
	//	rng.generatePopulation(); //stworzenie pliku txt z losowymi liczbami
	//	int size = 0;
	//	int* tab = rF.readFromFile(size); //wczytanie zawartosci tego txt
	//	bidirectionalList biL;
	//	biL.readData(tab, size);
	//	int val = biL.middle(); //œrodkowy element tablicy zeby znalazl
	//	timer.startTimer(); //wystartowanie timera
	//	biL.find(val);
	//	double time = timer.stopTimer(); //zatrzymanie timera
	//	results[i] = time;
	//	//arr.displayTests(); //wyswietlenie zawartosci tablicy
	//}

	//rF.writeResultsToFile("testBiLF.txt", results);
}









//-----------Testy kopca-------------------
void AutoTests::testHeap() {
	//RandomGenerator rng;
	//RWFile rF;
	//Time timer;
	//int* results = new int[10]; //tablica na rezultaty testow, ktora potem zostanie wpisana do pliku txt

	////add
	//for (int i = 0; i < 10; i++) { //10 testow
	//	rng.generatePopulation(); //stworzenie pliku txt z losowymi liczbami
	//	int size = 0;
	//	int* tab = rF.readFromFile(size); //wczytanie zawartosci tego txt
	//	Heap h = Heap(tab, size);
	//	int val = rng.generateRandomNumber(); //wylosowanie wartosci do wpisania do tablicy
	//	timer.startTimer(); //wystartowanie timera
	//	h.add(val);
	//	int time = timer.stopTimer(); //zatrzymanie timera
	//	results[i] = time;
	//	//arr.displayTests(); //wyswietlenie zawartosci tablicy
	//}

	//rF.writeResultsToFile("testHeapA.txt", results);

	////removeFromPeak
	//for (int i = 0; i < 10; i++) { //10 testow
	//	rng.generatePopulation(); //stworzenie pliku txt z losowymi liczbami
	//	int size = 0;
	//	int* tab = rF.readFromFile(size); //wczytanie zawartosci tego txt
	//	Heap h = Heap(tab, size);
	//	timer.startTimer(); //wystartowanie timera
	//	h.removeFromPeak();
	//	int time = timer.stopTimer(); //zatrzymanie timera
	//	results[i] = time;
	//	//arr.displayTests(); //wyswietlenie zawartosci tablicy
	//}

	//rF.writeResultsToFile("testHeapRFP.txt", results);

	////find
	//for (int i = 0; i < 10; i++) { //10 testow
	//	rng.generatePopulation(); //stworzenie pliku txt z losowymi liczbami
	//	int size = 0;
	//	int* tab = rF.readFromFile(size); //wczytanie zawartosci tego txt
	//	Heap h = Heap(tab, size);
	//	timer.startTimer(); //wystartowanie timera
	//	int val = h.data[h.size / 2];
	//	h.find(val);
	//	int time = timer.stopTimer(); //zatrzymanie timera
	//	results[i] = time;
	//	//arr.displayTests(); //wyswietlenie zawartosci tablicy
	//}

	//rF.writeResultsToFile("testHeapF.txt", results);

}


//--------------Testy BST---------------------------
void AutoTests::testBST() {
	RandomGenerator rng;
	RWFile rF;
	Time timer;
	double* results = new double[10]; //tablica na rezultaty testow, ktora potem zostanie wpisana do pliku txt

	//for (int i = 0; i < 10; i++) { //10 testow
	//	rng.generatePopulation(); //stworzenie pliku txt z losowymi liczbami
	//	int size = 0;
	//	int* tab = rF.readFromFile(size); //wczytanie zawartosci tego txt
	//	int val = rng.generateRandomNumber(); //wylosowanie wartosci do wpisania do tablicy
	//	BSTTree bst;
	//	bst.readData(tab, size);
	//	timer.startTimer(); //wystartowanie timera
	//	bst.add(val);
	//	double time = timer.stopTimer(); //zatrzymanie timera
	//	results[i] = time;
	//	//arr.displayTests(); //wyswietlenie zawartosci tablicy
	//}

	//rF.writeResultsToFile("testBSTA.txt", results);

	//for (int i = 0; i < 10; i++) { //10 testow
	//	rng.generatePopulation(); //stworzenie pliku txt z losowymi liczbami
	//	int size = 0;
	//	int* tab = rF.readFromFile(size); //wczytanie zawartosci tego txt
	//	int val = rng.generateRandomNumber(); //wylosowanie wartosci do wpisania do tablicy
	//	bool found = false;
	//	while (!found) { //dopoki nie znajdzie wylosowanej wartosci w danych
	//		val = rng.generateRandomNumber();
	//		for (int i = 0; i < size; i++) {
	//			if (tab[i] == val) {
	//				found = true;
	//				break;
	//			}
	//		}
	//	}
	//	BSTTree bst;
	//	bst.readData(tab, size);
	//	timer.startTimer(); //wystartowanie timera
	//	bst.deleteNode(val);
	//	double time = timer.stopTimer(); //zatrzymanie timera
	//	results[i] = time;
	//	//arr.displayTests(); //wyswietlenie zawartosci tablicy
	//}

	//rF.writeResultsToFile("testBSTDN.txt", results);

	for (int i = 0; i < 10; i++) { //10 testow
		rng.generatePopulation(); //stworzenie pliku txt z losowymi liczbami
		int size = 0;
		int* tab = rF.readFromFile(size); //wczytanie zawartosci tego txt
		int val = rng.generateRandomNumber(); //wylosowanie wartosci do wpisania do tablicy
		bool found = false;
		while (!found) { //dopoki nie znajdzie wylosowanej wartosci w danych
			val = rng.generateRandomNumber();
			for (int i = 0; i < size; i++) {
				if (tab[i] == val) {
					found = true;
					break;
				}
			}
		}
		BSTTree bst;
		bst.readData(tab, size);
		BSTTree::Node* p;
		timer.startTimer(); //wystartowanie timera
		p=bst.search(bst.root, val);
		double time = timer.stopTimer(); //zatrzymanie timera
		if (p != nullptr) cout << "Znaleziono " << val << " w BST" << endl;
		results[i] = time;
		//arr.displayTests(); //wyswietlenie zawartosci tablicy
	}

	rF.writeResultsToFile("testBSTS.txt", results);
}

void AutoTests::choice(int option) {
	switch (option) {
	case 1:
		testDynamicArray(); break;
	case 2:
		testBidirectionalList(); break;
	case 3:
		testHeap(); break;
	case 4:
		testBST(); break;
	}
}