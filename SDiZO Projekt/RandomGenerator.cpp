#include <iostream>
#include <random>
#include <fstream>
#include "RWFile.h"
#include "RandomGenerator.h"
using namespace std;

#define TESTS 10000000

RandomGenerator::RandomGenerator() {}

//-------------------------------------------------------------------------
void RandomGenerator::generatePopulation()
{
	fstream file;
	int val, min, max;
	random_device rd; // non-deterministic generator
	mt19937 gen(rd()); // random engine seeded with rd()
	uniform_int_distribution<> dist(1, 1000000000); // distribute results between

	string filename = "";
	filename = "test";
	filename += ".txt";
	file.open(filename,ios::out);

	file << TESTS << endl; //wypisanie do pliku ilosci liczb w pliku

	// 1 and 1000000 inclusive
	min = INT_MAX;
	max = 0;

	for (int i = 0; i < TESTS; i++)
	{
		val = dist(gen); // pass the generator to the distribution
		if (val < min)
			min = val;
		if (val > max)
			max = val;
		file << val << endl; //wypisanie wartosci do pliku
	}

	cout << "min = " << min << " max = " << max << endl;

	file.close();
}

int RandomGenerator::generateRandomNumber() {
	int val, min, max;
	random_device rd; // non-deterministic generator
	mt19937 gen(rd()); // random engine seeded with rd()
	uniform_int_distribution<> dist(1, 1000000); // distribute results between
	// 1 and 1000000 inclusive
	min = INT_MAX;
	max = 0;
	
	val = dist(gen); // pass the generator to the distribution
	return val;
}