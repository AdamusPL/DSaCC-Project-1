#include <iostream>
#include "DynamicArray.h"
#include "bidirectionalList.h"
using namespace std;

/*void bidirectionalList() {}

void binaryHeap(){}

void BSTTree(){}

void redBlackTree(){}*/

int main() {
	DynamicArray arr;
	bidirectionalList biL;
	int option = 1;
	while (option != 6) {
		cout << "Wybierz strukture:" << endl;
		cout << "1. Tablica dynamiczna" << endl;
		cout << "2. Lista dwukierunkowa" << endl;
		cout << "3. Kopiec binarny" << endl;
		cout << "4. Drzewo przeszukiwan binarnych BST" << endl;
		cout << "5. Drzewo czerwono-czarne" << endl;
		cout << "6. Wyjscie" << endl;
		cin >> option;
		switch (option) {
		case 1:
			arr.menu(); break;
		case 2:
			biL.menu(); break;
			/*case 3: binaryHeap(); break;
			case 4: BSTTree(); break;
			case 5: redBlackTree(); break;
			case 6: exit(0);*/
		}

	}

	return 0;
}