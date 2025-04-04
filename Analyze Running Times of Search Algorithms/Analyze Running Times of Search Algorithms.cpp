// Analyze Running Times of Search Algorithms.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include "listSearch.h"
int main() {
	// Create a random number generator using the Mersenne Twister engine
	std::mt19937 rng(std::random_device{}());

	std::uniform_int_distribution<int> distribution(1, 100);

	// The number of items stored in vector
	int n = 1000000;

	// Accumulator variable for the time to find/not find a target using Recursive Binary Search
	double SumRBS = 0;
	// Accumulator variable for the time to find/not find a target using Iterative Binary Search.
	double SumIBS = 0;
	// Accumulator variable for the time to find/not find a target using Sequential search
	double SumSeqS = 0;

	for (int j = 0; j <= 10; j++)
		{

			std::vector<int> list(n);

			for (int i = 0; i < list.size(); i++)
			{
				int rn = distribution(rng);

				list[i] = rn;
			}

			int target = distribution(rng);

			listSearch list1(list);

			auto start_time = std::chrono::high_resolution_clock::now();

			list1.mergeSort();

			list1.recursiveBinarySearch(target);

			auto end_time = std::chrono::high_resolution_clock::now();

			auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();

			SumRBS = SumRBS + static_cast<double>(duration);
		}

	std::cout << "Average Running Time for Recursive Binary Search in microseconds is, " << SumRBS / 10 << "\n";


	for (int j = 0; j <= 10; j++)
	{

		std::vector<int> list(n);

		for (int i = 0; i < list.size(); i++)
		{
			int rn = distribution(rng);

			list[i] = rn;
		}

		int target = distribution(rng);

		listSearch list1(list);

		auto start_time = std::chrono::high_resolution_clock::now();

		list1.mergeSort();

		list1.nonRecursiveBinarySearch(target);

		auto end_time = std::chrono::high_resolution_clock::now();

		auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();

		SumIBS = SumIBS + static_cast<double>(duration);
	}

	std::cout << "Average Running Time for Iterative Binary Search in microseconds is, " << SumIBS / 10 << "\n";

	for (int j = 0; j <= 10; j++)
	{

		std::vector<int> list(n);

		for (int i = 0; i < list.size(); i++)
		{
			int rn = distribution(rng);

			list[i] = rn;
		}

		int target = distribution(rng);

		listSearch list1(list);

		auto start_time = std::chrono::high_resolution_clock::now();

		list1.sequentialSearch(target);

		auto end_time = std::chrono::high_resolution_clock::now();

		auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time).count();

		SumSeqS = SumSeqS + static_cast<double>(duration);
	}

	std::cout << "Average Running Time for Sequential Search in nanoseconds is, " << SumSeqS / 10 << "\n";

	std::cout << "Testing without timing the sorting method\n";

	SumRBS = 0;

	SumIBS = 0;

	SumSeqS = 0;

	for (int j = 0; j <= 10; j++)
	{

		std::vector<int> list(n);

		for (int i = 0; i < list.size(); i++)
		{
			int rn = distribution(rng);

			list[i] = rn;
		}

		int target = distribution(rng);

		listSearch list1(list);

		list1.mergeSort();

		auto start_time = std::chrono::high_resolution_clock::now();

		list1.recursiveBinarySearch(target);

		auto end_time = std::chrono::high_resolution_clock::now();

		auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time).count();

		SumRBS = SumRBS + static_cast<double>(duration);
	}

	std::cout << "Average Running Time for Recursive Binary Search in nanoseconds is, " << SumRBS / 10 << "\n";

	for (int j = 0; j <= 10; j++)
	{

		std::vector<int> list(n);

		for (int i = 0; i < list.size(); i++)
		{
			int rn = distribution(rng);

			list[i] = rn;
		}

		int target = distribution(rng);

		listSearch list1(list);

		list1.mergeSort();

		auto start_time = std::chrono::high_resolution_clock::now();

		list1.nonRecursiveBinarySearch(target);

		auto end_time = std::chrono::high_resolution_clock::now();

		auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time).count();

		SumIBS = SumIBS + static_cast<double>(duration);
	}

	std::cout << "Average Running Time for Iterative Binary Search in nanoseconds is, " << SumIBS / 10 << "\n";

	for (int j = 0; j <= 10; j++)
	{

		std::vector<int> list(n);

		for (int i = 0; i < list.size(); i++)
		{
			int rn = distribution(rng);

			list[i] = rn;
		}

		int target = distribution(rng);

		listSearch list1(list);

		auto start_time = std::chrono::high_resolution_clock::now();

		list1.sequentialSearch(target);

		auto end_time = std::chrono::high_resolution_clock::now();

		auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time).count();

		SumSeqS = SumSeqS + static_cast<double>(duration);
	}

	std::cout << "Average Running Time for Sequential Search in nanoseconds is, " << SumSeqS / 10 << "\n";

	std::cout << "Testing using the same randomized vector for each search algorithm.\n";
	
	SumRBS = 0;

	SumIBS = 0;

	SumSeqS = 0;

	for (int j = 0; j <= 10; j++)
	{

		std::vector<int> list(n);

		for (int i = 0; i < list.size(); i++)
		{
			int rn = distribution(rng);

			list[i] = rn;
		}

		int target = distribution(rng);

		listSearch list1(list);

		//Timing for thee Sequential Search
		auto start_time1 = std::chrono::high_resolution_clock::now();

		list1.sequentialSearch(target);

		auto end_time1 = std::chrono::high_resolution_clock::now();
		
		auto duration1 = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time1 - start_time1).count();
		
		//Adding for the Sequential Search
		SumSeqS = SumSeqS + static_cast<double>(duration1);
		
		//Sorting for the binary search algorithms
		list1.mergeSort();

		//Timing for the Recursive Binary Search
		auto start_time2 = std::chrono::high_resolution_clock::now();

		list1.recursiveBinarySearch(target);

		auto end_time2 = std::chrono::high_resolution_clock::now();

		auto duration2 = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time2 - start_time2).count();

		//Adding for Recursive Binary Search
		SumRBS = SumRBS + static_cast<double>(duration2);

		//Timing Iterative Binary Search
		auto start_time3 = std::chrono::high_resolution_clock::now();

		list1.nonRecursiveBinarySearch(target);

		auto end_time3 = std::chrono::high_resolution_clock::now();

		//Adding for the Iterative Binary Search
		auto duration3 = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time3 - start_time3).count();

		SumIBS = SumIBS + static_cast<double>(duration3);
	}

	std::cout << "Average Running Time for Recursive Binary Search in nanoseconds is, " << SumRBS / 10 << "\n";
	
	std::cout << "Average Running Time for Iterative Binary Search in nanoseconds is, " << SumIBS / 10 << "\n";
	
	std::cout << "Average Running Time for Sequential Search in nanoseconds is, " << SumSeqS / 10 << "\n";


}
