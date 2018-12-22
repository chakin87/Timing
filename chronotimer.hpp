#ifndef CHRONOTIMER_HPP
#define	CHRONOTIMER_HPP
#include <chrono>
#include <iostream>
#include <fstream>

class chronoTimer
{
public:
	chronoTimer();//constructor 0
	chronoTimer(int numOfFilesSorted);//constructor 1
	~chronoTimer();

public://methods
private://members
	std::chrono::time_point<std::chrono::steady_clock> start,end;
	std::chrono::duration<float> duration;
	int constructorUsed, numFiles;

};

#endif // !CHRONOTIMER_HPP
