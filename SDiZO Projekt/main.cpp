#include <iostream>
#include "DynamicArray.h"
#include "bidirectionalList.h"
#include "Heap.h"
#include "ManualTests.h"
#include "RWFile.h"
#include "AutoTests.h"
using namespace std;

int main() {
	int option = 1;
	while (option != 6) { //menu, wybor struktury
		cout << "Wybierz strukture:" << endl;
		cout << "====================================" << endl;
		cout << "1. Tablica dynamiczna" << endl;
		cout << "2. Lista dwukierunkowa" << endl;
		cout << "3. Kopiec binarny" << endl;
		cout << "4. Drzewo przeszukiwan binarnych BST" << endl;
		cout << "5. Wyjscie" << endl;
		cin >> option; //wybór opcji
		cout << endl;
		if (option == 5) exit(0);

		int optionT = 0;
		while (optionT != 3) {
			cout << "Wybierz rodzaj testow: " << endl;
			cout << "======================" << endl;
			cout << "1. Manualne" << endl;
			cout << "2. Automatyczne" << endl;
			cout << "3. Powrot" << endl;
			cin >> optionT;
			cout << endl;
			ManualTests mT;
			AutoTests aT;

			switch (optionT) {
			case 1:
				mT.choose(option); break;
			case 2:
				aT.choice(option); break;
				break;
			case 3:
				break;
			}
		}

	}

	return 0;
}