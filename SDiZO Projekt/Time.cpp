#include <iostream>
#include <fstream>
#include <iomanip>
#include <windows.h>
#include "Time.h"
using namespace std;

Time::Time() {

}

long long int read_QPC()
{
	LARGE_INTEGER count;
	QueryPerformanceCounter(&count);
	return((long long int)count.QuadPart);
}

void Time::startTimer() { //wystartowanie timera
	QueryPerformanceFrequency((LARGE_INTEGER*)&frequency);
	start = read_QPC();
}

double Time::stopTimer() { //zastopowanie timera i wypisanie up³yniêtego czasu
	elapsed = read_QPC() - start;
	cout << "Time [s] = " << fixed << setprecision(0) << (float)elapsed /
		frequency << endl;
	cout << "Time [ms] = " << setprecision(0) << (1000.0 * elapsed) /
		frequency << endl;
	cout << "Time [us] = " << setprecision(1) << (1000000.0 * elapsed) /
		frequency << endl << endl;
	
	double time = (1000000.0 * elapsed) / frequency;
	return time;
}