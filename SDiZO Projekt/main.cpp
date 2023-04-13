#include <iostream>
#include "DynamicArray.h"
#include "bidirectionalList.h"
#include "Heap.h"
#include "Tests.h"
#include "AutoTests.h"
using namespace std;

int main() {
	int option = 1;
	while (option != 6) {
		cout << "Wybierz strukture:" << endl;
		cout << "1. Tablica dynamiczna" << endl;
		cout << "2. Lista dwukierunkowa" << endl;
		cout << "3. Kopiec binarny" << endl;
		cout << "4. Drzewo przeszukiwan binarnych BST" << endl;
		cout << "5. Drzewo czerwono-czarne" << endl;
		cout << "6. Wyjscie" << endl;
		cin >> option; //wyb�r opcji
		if (option == 6) exit(0);

		Tests t;
		char optionT = t.menu();

		if (optionT == 'A') {
			AutoTests aT;
			int size=0;
			int* tab = aT.readFromFile(size);
			DynamicArray arr;
			bidirectionalList biL;
			Heap h=Heap(tab,size);

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

		else if(optionT=='M'){
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

	return 0;
}