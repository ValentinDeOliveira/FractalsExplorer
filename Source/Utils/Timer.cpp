#include "..\..\Headers\Utils\Timer.h"

void Timer::startTimer()
{
	start = std::clock();
}

void Timer::showEllapsedTime()
{
	if (start != NULL) {
		double duration;
		duration = (std::clock() - (double)start) / (double)CLOCKS_PER_SEC;

		std::cout << "Ellapsed time: " << duration << '\n';
	}

	else {
		std::cerr << "Timer has not been started: " << std::endl;
	}
}
