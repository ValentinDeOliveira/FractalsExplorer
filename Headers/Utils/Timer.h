#include <cstdio>
#include <ctime>
#include <iostream>

#ifndef TIMER_H
#define TIMER_H

class Timer
{
	private:
		std::clock_t start;
		std::clock_t end;

	public:
		void startTimer();

		void showEllapsedTime();
};

#endif