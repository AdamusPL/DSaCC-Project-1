#include "ManualTests.h"
#include "DynamicArray.h"
#include "DoublyLinkedList.h"
#include "Heap.h"
#include "BST.h"
#include "FileReaderWriter.h"

void ManualTests::choose(int option) {
	FileReaderWriter rF;
	char optionF = rF.menu();

	if (optionF == 'A') {
		int size = 0;
		int* tab = rF.readFromFile(size);
		DynamicArray arr = DynamicArray(tab, size);
		DoublyLinkedList dLL;
		Heap h = Heap(tab, size);
		BST bst;

		switch (option) {
		case 1:
			arr.menu(); break;
		case 2:
			dLL.readData(tab, size); //read test data to doubly linked list
			dLL.menu(); break;
		case 3:
			h.menu(); break;
		case 4:
			bst.readData(tab, size);
			bst.menu();
		}
	}

	else if (optionF == 'M') {
		DynamicArray arr;
		DoublyLinkedList dLL;
		Heap h;
		BST bst;
		switch (option) {
		case 1:
			arr.menu(); break;
		case 2:
			dLL.menu(); break;
		case 3:
			h.menu(); break;
		case 4: 
			bst.menu(); break;
		}
	}
}