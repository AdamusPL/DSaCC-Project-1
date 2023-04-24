#pragma once
#include <string>
using namespace std;

class RWFile {

public:
	int* readFromFile(int &);
	void writeResultsToFile(string,double*);
	char menu();
};