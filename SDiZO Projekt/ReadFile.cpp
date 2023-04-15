#include "ReadFile.h";
#include <iostream>
#include <fstream>
using namespace std;

int* ReadFile::readFromFile(int &size) {
	fstream file;
	string filename="test.txt";

	file.open(filename, ios::in);

	if (file.is_open()) {
		file >> size;
		int* tab=new int[size];

		for (int i = 0; i < size; i++) {
			int val;
			file >> val;
			if (file.fail()) {
				cout << "Blad pliku - wczytywania" << endl;
				break;
			}
			else tab[i] = val;
		}

		file.close();

		return tab;
	}
	else cout << "Blad pliku - otwarcia" << endl;
}

char ReadFile::menu() {
	int optionTest;
	cout << "Jak chcesz przetestowac dana strukture:" << endl;
	cout << "1. Wpisac dane z pliku" << endl;
	cout << "2. Wpisac dane recznie" << endl;
	cout << "3. Powrot" << endl;
	cin >> optionTest;
	switch (optionTest) {
	case 1:
		return 'A'; break;
	case 2:
		return 'M'; break;
	case 3:
		return 'X'; break;
	}
	return 'X';
}