#pragma once

class bidirectionalList {
public:
	int size;
	bidirectionalList();
	void readData(int*, int);
	void addOnStart(int);
	void removeFromStart();
	void addOnEnd(int);
	void removeFromEnd();
	void insert(int, int);
	void removeFromChosen(int);
	void displayFromStart();
	void displayFromEnd();
	void find(int);
	void menu();
	int loadNumber();
	int loadIndex();

};
