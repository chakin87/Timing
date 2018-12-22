#include "Headers/chronoTimer.hpp"

chronoTimer::chronoTimer():constructorUsed(0)
{
	start = std::chrono::high_resolution_clock::now();
}

chronoTimer::chronoTimer(int numOfFilesSorted) : 
	constructorUsed(1), numFiles(numOfFilesSorted)
{
	start = std::chrono::high_resolution_clock::now();
}


chronoTimer::~chronoTimer()
{ 
	if (constructorUsed == 0) {
		end = std::chrono::high_resolution_clock::now();
		duration = end - start;
		std::cout << duration.count() << " seconds" << std::endl;
		std::cout << duration.count()*1000 << " ms" << std::endl;
		return;
	}
	else if (constructorUsed == 1) {
		end = std::chrono::high_resolution_clock::now();
		duration = end - start;
		//std::cout << duration.count() << " seconds" << std::endl;
		//std::cout << duration.count() * 1000 << " ms" << std::endl;
		
		std::ofstream myFile("numbers.csv", std::ios::app);
		myFile << numFiles << "," << duration.count()*1000 << std::endl;
		myFile.close();
		return;
	}
}
