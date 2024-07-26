#include "AutoTests.h"
#include "RandomGenerator.h"
#include "FileReaderWriter.h"
#include "DynamicArray.h"
#include "DoublyLinkedList.h"
#include "Heap.h"
#include "BST.h"
#include "Time.h"

//-------------------Dynamic Array tests----------------
void AutoTests::testDynamicArray() {
	RandomGenerator rng;
	FileReaderWriter fRW;
	Time timer;
	double* results = new double[10]; //array for test results whose elements will be written to the .txt file

	//pushFront()
	for (int i = 0; i < 10; i++) { //10 tests
		rng.generatePopulation(); //create .txt file with random numbers
		int size = 0;
		int* tab=fRW.readFromFile(size); //read .txt content
		DynamicArray arr = DynamicArray(tab,size);
		int val = rng.generateRandomNumber(); //random values which will be written to dynamic array
		timer.startTimer(); //start timer
		arr.pushFront(val);
		int time = timer.stopTimer(); //stop timer
		results[i] = time;
	}

	fRW.writeResultsToFile("testArrayPushFront.txt", results);

	//popFront()
	for (int i = 0; i < 10; i++) { //10 tests
		rng.generatePopulation(); //create .txt file with random numbers
		int size = 0;
		int* tab = fRW.readFromFile(size); //read .txt content
		DynamicArray arr = DynamicArray(tab, size);
		timer.startTimer(); //start timer
		arr.popFront();
		int time = timer.stopTimer(); //stop timer
		results[i] = time;

	}

	fRW.writeResultsToFile("testArrayPopFront.txt", results);

	//pushEnd()
	for (int i = 0; i < 10; i++) { //10 tests
		rng.generatePopulation(); //create .txt file with random numbers
		int size = 0;
		int* tab = fRW.readFromFile(size); //read .txt content
		DynamicArray arr = DynamicArray(tab, size);
		int val = rng.generateRandomNumber(); //generate random values to write to array
		timer.startTimer(); //start timer
		arr.pushBack(val);
		int time = timer.stopTimer(); //stop timer
		results[i] = time;

	}

	fRW.writeResultsToFile("testArrayPushBack.txt", results);

	//popEnd()
	for (int i = 0; i < 10; i++) { //10 tests
		rng.generatePopulation(); //create .txt file with random numbers
		int size = 0;
		int* tab = fRW.readFromFile(size); //read .txt content
		DynamicArray arr = DynamicArray(tab, size);
		timer.startTimer(); //start timer
		arr.popBack();
		int time = timer.stopTimer(); //stop timer
		results[i] = time;

	}

	fRW.writeResultsToFile("testArrayPopBack.txt", results);

	//insert()
	for (int i = 0; i < 10; i++) { //10 tests
		rng.generatePopulation(); //create .txt file with random numbers
		int size = 0;
		int* tab = fRW.readFromFile(size); //read .txt content
		DynamicArray arr = DynamicArray(tab, size);
		int val = rng.generateRandomNumber(); //generate random values to write to array
		timer.startTimer(); //start timer
		arr.insert(arr.size/2,val);
		int time = timer.stopTimer(); //stop timer
		results[i] = time;

	}

	fRW.writeResultsToFile("testArrayInsert.txt", results);

	//removeAt()
	for (int i = 0; i < 10; i++) { //10 tests
		rng.generatePopulation(); //create .txt file with random numbers
		int size = 0;
		int* tab = fRW.readFromFile(size); //read .txt content
		DynamicArray arr = DynamicArray(tab, size);
		timer.startTimer(); //start timer
		arr.removeAt(arr.size/2);
		int time = timer.stopTimer(); //stop timer
		results[i] = time;

	}

	fRW.writeResultsToFile("testArrayRemoveAt.txt", results);

	//search()
	for (int i = 0; i < 10; i++) { //10 tests
		rng.generatePopulation(); //create .txt file with random numbers
		int size = 0;
		int* tab = fRW.readFromFile(size); //read .txt content
		DynamicArray arr = DynamicArray(tab, size);
		cout << "Array size: " << arr.size << endl;
		int val = arr.array[arr.size / 2]; //to make it find middle element of array
		timer.startTimer(); //start timer
		arr.search(val);
		int time = timer.stopTimer(); //stop timer
		results[i] = time;

	}

	fRW.writeResultsToFile("testArraySearch.txt", results);
}

//-----------------Doubly Linked List tests---------------
void AutoTests::testDoublyLinkedList() {
	RandomGenerator rng;
	FileReaderWriter fRW;
	Time timer;
	double* results = new double[10]; //array for test results whose elements will be written to the .txt file

	//pushFront()
	for (int i = 0; i < 1; i++) { //10 tests
		rng.generatePopulation(); //create .txt file with random numbers
		int size = 0;
		int* tab=fRW.readFromFile(size); //read .txt content
		DoublyLinkedList dLL;
		dLL.readData(tab,size);
		int val = rng.generateRandomNumber(); //generate random values to write to array
		timer.startTimer(); //start timer
		dLL.pushFront(val);
		double time = timer.stopTimer(); //stop timer
		results[i] = time;

	}

	fRW.writeResultsToFile("testDoublyLinkedListPushFront.txt", results);

	//popFront()
	for (int i = 0; i < 10; i++) { //10 tests
		rng.generatePopulation(); //create .txt file with random numbers
		int size = 0;
		int* tab = fRW.readFromFile(size); //read .txt content
		DoublyLinkedList dLL;
		dLL.readData(tab, size);
		timer.startTimer(); //start timer
		dLL.popFront();
		double time = timer.stopTimer(); //stop timer
		results[i] = time;

	}

	fRW.writeResultsToFile("testDoublyLinkedListPopFront.txt", results);

	//pushBack()
	for (int i = 0; i < 10; i++) { //10 tests
		rng.generatePopulation(); //create .txt file with random numbers
		int size = 0;
		int* tab = fRW.readFromFile(size); //read .txt content
		DoublyLinkedList dLL;
		dLL.readData(tab, size);
		int val = rng.generateRandomNumber(); //generate random values to write to array
		timer.startTimer(); //start timer
		dLL.pushBack(val);
		double time = timer.stopTimer(); //stop timer
		results[i] = time;

	}

	fRW.writeResultsToFile("testDoublyLinkedListPushBack.txt", results);

	//popBack()
	for (int i = 0; i < 10; i++) { //10 tests
		rng.generatePopulation(); //create .txt file with random numbers
		int size = 0;
		int* tab = fRW.readFromFile(size); //read .txt content
		DoublyLinkedList dLL;
		dLL.readData(tab, size);
		timer.startTimer(); //start timer
		dLL.popBack();
		double time = timer.stopTimer(); //stop timer
		results[i] = time;

	}

	fRW.writeResultsToFile("testDoublyLinkedListPopBack.txt", results);

	//insert()
	for (int i = 0; i < 10; i++) { //10 tests
		rng.generatePopulation(); //create .txt file with random numbers
		int size = 0;
		int* tab = fRW.readFromFile(size); //read .txt content
		DoublyLinkedList dLL;
		dLL.readData(tab, size);
		int val = rng.generateRandomNumber(); //generate random values to write to array
		timer.startTimer(); //start timer
		dLL.insert(dLL.size/2,val);
		double time = timer.stopTimer(); //stop timer
		results[i] = time;

	}

	fRW.writeResultsToFile("testDoublyLinkedListInsert.txt", results);

	//removeAt()
	for (int i = 0; i < 10; i++) { //10 tests
		rng.generatePopulation(); //create .txt file with random numbers
		int size = 0;
		int* tab = fRW.readFromFile(size); //read .txt content
		DoublyLinkedList dLL;
		dLL.readData(tab, size);
		timer.startTimer(); //start timer
		dLL.removeAt(dLL.size/2);
		double time = timer.stopTimer(); //stop timer
		results[i] = time;

	}

	fRW.writeResultsToFile("testDoublyLinkedListRemoveAt.txt", results);

	//search()
	for (int i = 0; i < 10; i++) { //10 tests
		rng.generatePopulation(); //create .txt file with random numbers
		int size = 0;
		int* tab = fRW.readFromFile(size); //read .txt content
		DoublyLinkedList dLL;
		dLL.readData(tab, size);
		int val = dLL.middle(); //in order to find middle element from list
		timer.startTimer(); //start timer
		dLL.search(val);
		double time = timer.stopTimer(); //stop timer
		results[i] = time;

	}

	fRW.writeResultsToFile("testDoublyLinkedListFind.txt", results);
}

//-----------Heap tests-------------------
void AutoTests::testHeap() {
	RandomGenerator rng;
	FileReaderWriter fRW;
	Time timer;
	double* results = new double[10]; //array for test results whose elements will be written to the .txt file

	//insert()
	for (int i = 0; i < 10; i++) { //10 tests
		rng.generatePopulation(); //create .txt file with random numbers
		int size = 0;
		int* tab = fRW.readFromFile(size); //read .txt content
		Heap h = Heap(tab, size);
		int val = rng.generateRandomNumber(); //generate random values to write to array
		timer.startTimer(); //start timer
		h.insert(val);
		int time = timer.stopTimer(); //stop timer
		results[i] = time;

	}

	fRW.writeResultsToFile("testHeapInsert.txt", results);

	//deleteRoot()
	for (int i = 0; i < 10; i++) { //10 tests
		rng.generatePopulation(); //create .txt file with random numbers
		int size = 0;
		int* tab = fRW.readFromFile(size); //read .txt content
		Heap h = Heap(tab, size);
		timer.startTimer(); //start timer
		h.deleteRoot();
		int time = timer.stopTimer(); //stop timer
		results[i] = time;

	}

	fRW.writeResultsToFile("testHeapDeleteRoot.txt", results);

	//search()
	for (int i = 0; i < 10; i++) { //10 tests
		rng.generatePopulation(); //create .txt file with random numbers
		int size = 0;
		int* tab = fRW.readFromFile(size); //read .txt content
		Heap h = Heap(tab, size);
		timer.startTimer(); //start timer
		int val = h.data[h.size / 2];
		h.search(val);
		int time = timer.stopTimer(); //stop timer
		results[i] = time;

	}

	fRW.writeResultsToFile("testHeapSearch.txt", results);

}

//--------------BST Tests---------------------------
void AutoTests::testBST() {
	RandomGenerator rng;
	FileReaderWriter fRW;
	Time timer;
	double* results = new double[10]; //array for test results whose elements will be written to the .txt file

	for (int i = 0; i < 10; i++) { //10 tests
		rng.generatePopulation(); //create .txt file with random numbers
		int size = 0;
		int* tab = fRW.readFromFile(size); //read .txt content
		int val = rng.generateRandomNumber(); //generate random values to write to array
		BST bst;
		bst.readData(tab, size);
		timer.startTimer(); //start timer
		bst.insert(val);
		double time = timer.stopTimer(); //stop timer
		results[i] = time;

	}

	fRW.writeResultsToFile("testBSTInsert.txt", results);

	for (int i = 0; i < 10; i++) { //10 tests
		rng.generatePopulation(); //create .txt file with random numbers
		int size = 0;
		int* tab = fRW.readFromFile(size); //read .txt content
		int val = rng.generateRandomNumber(); //generate random values to write to array
		bool found = false;
		while (!found) { //while random generated value is not found in data
			val = rng.generateRandomNumber();
			for (int i = 0; i < size; i++) {
				if (tab[i] == val) {
					found = true;
					break;
				}
			}
		}
		BST bst;
		bst.readData(tab, size);
		timer.startTimer(); //start timer
		bst.deleteNode(val);
		double time = timer.stopTimer(); //stop timer
		results[i] = time;

	}

	fRW.writeResultsToFile("testBSTDeleteNode.txt", results);

	for (int i = 0; i < 10; i++) { //10 tests
		rng.generatePopulation(); //create .txt file with random numbers
		int size = 0;
		int* tab = fRW.readFromFile(size); //read .txt content
		int val = rng.generateRandomNumber(); //generate random values to write to array
		bool found = false;
		while (!found) { //while random generated value is not found in data
			val = rng.generateRandomNumber();
			for (int i = 0; i < size; i++) {
				if (tab[i] == val) {
					found = true;
					break;
				}
			}
		}
		BST bst;
		bst.readData(tab, size);
		BST::Node* p;
		timer.startTimer(); //start timer
		p=bst.search(bst.root, val);
		double time = timer.stopTimer(); //stop timer
		if (p != nullptr) cout << "Found " << val << " in BST" << endl;
		results[i] = time;

	}

	fRW.writeResultsToFile("testBSTSearch.txt", results);
}

void AutoTests::choice(int option) {
	switch (option) {
	case 1:
		testDynamicArray(); break;
	case 2:
		testDoublyLinkedList(); break;
	case 3:
		testHeap(); break;
	case 4:
		testBST(); break;
	}
}