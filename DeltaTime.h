#pragma once
#include <chrono>

class DeltaTime
{
public:
	DeltaTime();
	double getDeltaTime() const;
	void restartClock();

private:
	double deltaTime;
	std::chrono::steady_clock::time_point t_Start;
	std::chrono::steady_clock::time_point t_End;

};