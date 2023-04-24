#include "RWFile.h";
#include <iostream>
#include <fstream>
using namespace std;

int* RWFile::readFromFile(int &size) { //funkcja wczytujaca dane z pliku i zwracajaca "tablice dynamiczna"
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

void RWFile::writeResultsToFile(string filename, double* results) { //wypisanie rezultatow eksperymentow do pliku txt
	fstream file;
	file.open(filename, ios::out);
	double avg = 0;

	for (int i = 0; i < 10; i++) {
		file << results[i] << endl;
		avg += results[i];
	}
	
	avg = avg / 10;

	file << endl;

	file << avg << endl;
}

char RWFile::menu() {
	int optionTest;
	cout << "Jak chcesz przetestowac dana strukture:" << endl;
	cout << "=======================================" << endl;
	cout << "1. Wpisac dane z pliku" << endl;
	cout << "2. Wpisac dane recznie" << endl;
	cout << "3. Powrot" << endl;
	cin >> optionTest;
	cout << endl;
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