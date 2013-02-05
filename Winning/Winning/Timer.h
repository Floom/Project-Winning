#pragma once
#include<time.h>

class Timer
{
public:
	int secondsPassed;
	int nextTick;
	Timer()
	{
		secondsPassed = 0;
		nextTick = clock() + 1 * CLOCKS_PER_SEC;
	}
	void Update()
	{
		if(nextTick < clock())
			{
				secondsPassed++;
				//printf("time passed: %i\n",secondsPassed);
				nextTick = clock() + 1 * CLOCKS_PER_SEC;
			}
	}
};