#pragma once
class Time {
public:
	long long int frequency, start, elapsed;
	Time();
	void startTimer();
	double stopTimer();
};