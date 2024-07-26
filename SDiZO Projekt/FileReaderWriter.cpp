#include "FileReaderWriter.h";
#include <iostream>
#include <fstream>
using namespace std;

int* FileReaderWriter::readFromFile(int &size) { //read data from file and return dynamic array
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
				cout << "File reading error" << endl;
				break;
			}
			else tab[i] = val;
		}

		file.close();

		return tab;
	}
	else cout << "File opening error" << endl;
}

void FileReaderWriter::writeResultsToFile(string filename, double* results) { //print tests result to .txt file
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

char FileReaderWriter::menu() {
	int optionTest;
	cout << "How would you like test the specific data structure?:" << endl;
	cout << "====================================================" << endl;
	cout << "1. Read data from file" << endl;
	cout << "2. Read data manually" << endl;
	cout << "3. Return" << endl;
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