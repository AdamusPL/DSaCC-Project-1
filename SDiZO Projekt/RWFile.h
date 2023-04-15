#pragma once
#include <string>
using namespace std;

class RWFile {

public:
	int* readFromFile(int &);
	void writeResultsToFile(string,int*);
	char menu();
};