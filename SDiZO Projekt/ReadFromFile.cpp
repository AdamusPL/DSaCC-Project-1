#include <iostream>
#include <fstream>
#include "ReadFromFile.h"
using namespace std;

ReadFromFile::ReadFromFile() {

}

void ReadFromFile::read() {
	fstream file;
	string filename;

	cout << "Podaj nazwe pliku tekstowego:" << endl;
	cin >> filename;

	file.open(filename, ios::in);

	file.close();
}