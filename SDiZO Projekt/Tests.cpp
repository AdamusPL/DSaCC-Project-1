#include "Tests.h"
#include <iostream>
using namespace std;

char Tests::menu() {
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
