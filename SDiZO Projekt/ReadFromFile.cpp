#include <iostream>
#include <fstream>
#include "ReadFromFile.h"
using namespace std;

ReadFromFile::ReadFromFile() {

}

void ReadFromFile::read() {
	fstream file;
	file.open("test.txt", ios::in);

	file.close();
}