#include <windows.h>
#include <iostream>
#include <iomanip>
using namespace std;
//-------------------------------------------------------------------------
long long int read_QPC()
{
	LARGE_INTEGER count;
	QueryPerformanceCounter(&count);
	return((long long int)count.QuadPart);
}
//-------------------------------------------------------------------------
void main(void)
{
	long long int frequency, start, elapsed;
	QueryPerformanceFrequency((LARGE_INTEGER*)&frequency);
	start = read_QPC();
	Sleep(1000); // kod ktorego czas wykonania mierzymy
	elapsed = read_QPC() - start;
	cout << "Time [s] = " << fixed << setprecision(3) << (float)elapsed /
		frequency << endl;
	cout << "Time [ms] = " << setprecision(0) << (1000.0 * elapsed) /
		frequency << endl;
	cout << "Time [us] = " << setprecision(0) << (1000000.0 * elapsed) /
		frequency << endl << endl;
	system("PAUSE");
}