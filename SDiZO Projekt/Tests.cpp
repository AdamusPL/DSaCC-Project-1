#include "Tests.h"
#include <iostream>
using namespace std;

char Tests::menu() {
	int option = 1;
	while (option != 3) {
		cout << "Jak chcesz przetestowac dana strukture:" << endl;
		cout << "1. Wpisac dane z pliku" << endl;
		cout << "2. Wpisac dane recznie" << endl;
		cout << "3. Powrot" << endl;
		cin >> option;
		switch (option) {
		case 1:
			return 'A'; break;
		case 2:
			return 'B'; break;
		case 3:
			return; break;
		}
	}
}
