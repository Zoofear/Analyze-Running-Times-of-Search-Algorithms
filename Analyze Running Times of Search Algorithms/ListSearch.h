#pragma once

#include <iostream>
#include <vector>

class listSearch
{
private:

	//initialized vector needed for the class
	std::vector<int>& vec;

	//searches for the target by splitting the vector in half and searching through the halves
	int recursiveBinarySearch(std::vector<int>& vec, int target, int low, int high);

	//sorting the vector
	void mergeSort(std::vector<int>& vec);

	//a function for merge sort
	void merge(std::vector<int>& vec, std::vector<int> leftlist, std::vector<int> rightlist);

	int nonRecursiveBinarySearch(const std::vector<int>& vec, int target);

	int sequentialSearch(const std::vector<int>& vec, int target);


public:

	//constructor
	listSearch(std::vector<int>& list):vec(list){}

	//sorting the vector, overloaded for simplicity
	void mergeSort()
	{
		mergeSort(vec);
	}

	//function overloaded to make calling the function a lot simpler.
	int recursiveBinarySearch(int target)
	{
		return recursiveBinarySearch(vec, target, 0, vec.size() - 1);
	}

	//function overloaded to make calling the function a lot simpler.
	int nonRecursiveBinarySearch(int target)
	{
		return nonRecursiveBinarySearch(vec, target);
	}

	//function overloaded to make calling the function a lot simpler.
	int sequentialSearch(int target)
	{
		return sequentialSearch(vec, target);
	}

	void printList()
	{
		int size = vec.size();
		for (int i = 0; i < size; i++)
		{
			std::cout << vec[i] << " -> ";
		}

		std::cout << "end\n";
	}
};