#include <iostream>
#include "DynamicArray.h"
#include "DoublyLinkedList.h"
#include "Heap.h"
#include "ManualTests.h"
#include "FileReaderWriter.h"
#include "AutoTests.h"
using namespace std;

int main() {
	int option = 1;
	while (option != 6) { //menu, data structure choice
		cout << "Choose data structure:" << endl;
		cout << "====================================" << endl;
		cout << "1. Dynamic Array" << endl;
		cout << "2. Doubly Linked List" << endl;
		cout << "3. Binary heap" << endl;
		cout << "4. BST" << endl;
		cout << "5. Exit" << endl;
		cin >> option; //choosing option
		cout << endl;
		if (option == 5) exit(0);

		int optionT = 0;
		while (optionT != 3) {
			cout << "Choose tests method: " << endl;
			cout << "======================" << endl;
			cout << "1. Manual" << endl;
			cout << "2. Automatic" << endl;
			cout << "3. Return" << endl;
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