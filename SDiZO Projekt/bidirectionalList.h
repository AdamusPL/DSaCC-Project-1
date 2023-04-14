#pragma once

class bidirectionalList {
public:
	int size;
	bidirectionalList();
	void readData(int* tab, int size);
	void addOnStart(int);
	void removeFromStart();
	void addOnEnd(int);
	void removeFromEnd();
	void insert(int, int);
	void removeFromChosen(int);
	void displayFromStart();
	void displayFromEnd();
	void menu();
	int loadNumber();
	int loadIndex();

};
