#include "AutoTests.h"
#include "RandomGenerator.h"
#include "ReadFile.h"
#include "DynamicArray.h"
#include "bidirectionalList.h"
#include "Heap.h"

void AutoTests::testDynamicArray() {
	RandomGenerator rng;
	ReadFile rF;

	for (int i = 0; i < 10; i++) {
		rng.generatePopulation();
		int size = 0;
		int* tab=rF.readFromFile(size);
		DynamicArray arr = DynamicArray(tab,size);
		int val = rng.generateRandomNumber();
		arr.addOnStart(val);
		arr.display();
	}
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