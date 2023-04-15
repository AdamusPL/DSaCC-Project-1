#include "ManualTests.h"
#include "DynamicArray.h"
#include "bidirectionalList.h"
#include "Heap.h"
#include "RWFile.h"

void ManualTests::choose(int option) {
	RWFile rF;
	char optionF = rF.menu();

	if (optionF == 'A') {
		int size = 0;
		int* tab = rF.readFromFile(size);
		DynamicArray arr = DynamicArray(tab, size);
		bidirectionalList biL;
		Heap h = Heap(tab, size);

		switch (option) {
		case 1:
			arr.menu(); break;
		case 2:
			biL.readData(tab, size); //wczytanie danych testowych do listy dwukierunkowej
			biL.menu(); break;
		case 3:
			h.menu(); break;
			/*case 4: BSTTree(); break;
			case 5: redBlackTree(); break;*/
		}
	}

	else if (optionF == 'M') {
		DynamicArray arr;
		bidirectionalList biL;
		Heap h;
		switch (option) {
		case 1:
			arr.menu(); break;
		case 2:
			biL.menu(); break;
		case 3:
			h.menu(); break;
			/*case 4: BSTTree(); break;
			case 5: redBlackTree(); break;*/
		}
	}
}