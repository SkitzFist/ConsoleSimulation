#include "DeltaTime.h"

DeltaTime::DeltaTime()
{
	//config

	//setup
	deltaTime = 0.00;
	t_Start = std::chrono::steady_clock::now();
	t_End = std::chrono::steady_clock::now();
	//debug
}

double DeltaTime::getDeltaTime() const
{
	return deltaTime;
}

void DeltaTime::restartClock()
{
	t_End = std::chrono::steady_clock::now();
	std::chrono::duration<double> runTime = t_End - t_Start;
	deltaTime = runTime.count();
	t_Start = std::chrono::steady_clock::now();

}
