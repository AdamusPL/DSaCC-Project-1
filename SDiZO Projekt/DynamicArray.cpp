#include "DynamicArray.h"
using namespace std;

DynamicArray::DynamicArray() {
	size = 0;
	array = new int[size];
}

DynamicArray::DynamicArray(int *d, int s) {
	size = s;
	array = d;
}

void DynamicArray::pushFront(int data) {
	int* tempArray = new int[size + 1]; //temporary array definition that has size+1 size
	*tempArray = data; // no. 0 element = data

	for (size_t i = 0; i < size; i++)
	{
		tempArray[i + 1] = array[i]; //add the rest of elements to temporary array
	}

	size++; //enlarge array size

	delete[] array; //free up memory (delete previous array)

	array = tempArray; //change pointer to new array
}

void DynamicArray::popFront() {

	if (size == 0) {
		cout << "Array is empty!" << endl;
	}

	else {
		int* tempArray = new int[size - 1]; //define temporary array that has size-1 size
		for (size_t i = 0; i < size; i++)
		{
			tempArray[i] = array[i + 1]; //add the rest of values to temporary array
		}
		size--;

		delete[] array;

		array = tempArray;
	}
}

void DynamicArray::pushBack(int data) {
	int* tempArray = new int[size + 1];

	for (size_t i = 0; i < size; i++)
	{
		tempArray[i] = array[i];
	}

	tempArray[size] = data;

	size++;

	delete[] array;

	array = tempArray;
}

void DynamicArray::popBack() {

	if (size == 0) {
		cout << "Array is empty!" << endl;
	}

	else {
		int* tempArray = new int[size - 1];
		for (size_t i = 0; i < size - 1; i++)
		{
			tempArray[i] = array[i]; //add the rest of values to the temporary array
		}

		size--;

		delete[] array;

		array = tempArray;
	}
}

void DynamicArray::insert(int index, int data) {

	if (index > size || index < 0) { //if index is negative or index is larger than size of array
		cout << "Incorrect index!" << endl;
	}

	else {
		int* tempArray = new int[size + 1];

		for (size_t i = 0; i < index; i++)
		{
			tempArray[i] = array[i]; //assign values to temporary array until given index
		}

		tempArray[index] = data; //write new value to array

		for (size_t i = index; i < size; i++)
		{
			tempArray[i + 1] = array[i]; //fill with the rest of values
		}

		size++;

		delete[] array;

		array = tempArray;
	}

}

void DynamicArray::removeAt(int index) {

	if (index >= size || index < 0) { //if index is negative or index is larger than size of array
		cout << "Incorrect index!" << endl;
	}

	else {
		int* tempArray = new int[size - 1];
		for (size_t i = 0; i < index; i++)
		{
			tempArray[i] = array[i]; //add the rest of values to the temporary array
		}

		size--;

		for (size_t i = index; i < size; i++)
		{
			tempArray[i] = array[i + 1]; //add the rest of values to the temporary array
		}

		delete[] array;

		array = tempArray;
	}

}

void DynamicArray::print() {
	if (size == 0) {
		cout << "Array is empty!" << endl;
	}
	else {
		for (size_t i = 0; i < size; i++)
		{
			cout << "t[" << i << "]=" << array[i] << endl;
			//cout<<*(array+i)<<endl;
		}
	}
	cout << endl << endl;
}

void DynamicArray::printTests() {
	if (size == 0) {
		cout << "Array is empty!" << endl;
	}

	else {
		for (size_t i = 0; i < size; i++)
		{
			cout << array[i] <<" ";
			//cout<<*(array+i)<<endl;
		}
	}
	cout << endl;
}

void DynamicArray::search(int val) {

	for (int i = 0; i < size; i++) {
		if (val == array[i]) {
			cout << val << " is in the index: " << i << endl;
			return;
		}
	}
	
	cout << "That value doesn't exist in array!" << endl;

}

void DynamicArray::menu() { //menu
	int option = 1;
	while (option != 9) {
		cout << "What would you want to do?:" << endl;
		cout << "=====================================" << endl;
		cout << "1. Add element at the front" << endl;
		cout << "2. Add element at the back" << endl;
		cout << "3. Add element at the specific index" << endl;
		cout << "4. Remove element from the front" << endl;
		cout << "5. Remove element from the back" << endl;
		cout << "6. Remove element from the specific index" << endl;
		cout << "7. Print array" << endl;
		cout << "8. Find index of the specific element of the array" << endl;
		cout << "9. Choose the other data structure" << endl;
		cin >> option;
		int number, index;
		cout << endl;

		switch (option) {
		case 1:
			number = loadNumber();
			pushFront(number); break;
		case 2:
			number = loadNumber();
			pushBack(number); break;
		case 3:
			number = loadNumber();
			index = loadIndex();
			insert(index, number); break;
		case 4:
			popFront(); break;
		case 5:
			popBack(); break;
		case 6:
			index = loadIndex();
			removeAt(index); break;
		case 7:
			print(); break;
		case 8:
			number = loadNumber();
			search(number); break;
		case 9: return;
		}
	}
}

int DynamicArray::loadNumber() { //read numbers method
	int number;
	cout << "Give the number: ";
	cin >> number;
	cout << endl;
	return number;
}

int DynamicArray::loadIndex() { //read index method
	int index;
	cout << "Give the index: ";
	cin >> index;
	cout << endl;
	return index;
}