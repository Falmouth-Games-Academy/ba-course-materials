#include "Timer.h"

void Timer::Start()
{
	QueryPerformanceCounter(&start);
}
     
void Timer::Stop()
{
    QueryPerformanceCounter(&stop);
            
	LastTime.QuadPart = stop.QuadPart - start.QuadPart;
}
    
float Timer::GetTime()
{
	LARGE_INTEGER freq;
	QueryPerformanceFrequency((LARGE_INTEGER *)&freq);

	return (float)(LastTime.QuadPart / (float)freq.QuadPart);
}
    
float Timer::GetmS()
{
    return GetTime() * 1000.0f;
}
     