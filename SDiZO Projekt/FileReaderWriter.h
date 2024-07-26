#pragma once
#include <string>
using namespace std;

class FileReaderWriter {

public:
	int* readFromFile(int &);
	void writeResultsToFile(string,double*);
	char menu();
};