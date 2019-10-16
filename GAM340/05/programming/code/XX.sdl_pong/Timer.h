#pragma once
#include <windows.h>

class Timer
{
public:
	void Start();
	void Stop();

	float GetTime();
	float GetmS();

private:
	LARGE_INTEGER start, stop, LastTime;
}; 
