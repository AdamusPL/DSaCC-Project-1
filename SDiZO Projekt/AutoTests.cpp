#include "AutoTests.h";
#include <iostream>
#include <fstream>
using namespace std;

int* AutoTests::readFromFile(int &size) {
	fstream file;
	string filename;
	
	cout << "Podaj nazwe pliku" << endl;
	cin >> filename;

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