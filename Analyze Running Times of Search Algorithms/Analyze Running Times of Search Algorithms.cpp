// Analyze Running Times of Search Algorithms.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <random>
#include "listSearch.h"
int main(){
		// Create a random number generator using the Mersenne Twister engine
	std::mt19937 rng(std::random_device{}());
		
	std::uniform_int_distribution<int> distribution(1, 100);

	std::vector<int> list(5);

	for (int i = 0; i < list.size(); i++)
	{
		int rn = distribution(rng);

		list[i] = rn;

		std::cout << list[i] << " -> ";
	}

	std::cout << "end " << std::endl;
	
}
