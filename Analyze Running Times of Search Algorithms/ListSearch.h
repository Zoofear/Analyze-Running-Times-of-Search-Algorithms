#pragma once

#include <iostream>
#include <vector>

class listSearch
{
private:

	//used to sort the vector for recursive binary and iterative binary searching
	void mergeSort(std::vector<int>& list, int low, int high);

	//searches for the target by splitting the vector in half and searching through the halves
	void recursiveBinarySearch(std::vector<int>& list, int target, int low, int high);

public:
	
	//constructor
	listSearch(std::vector<int>& list);

	//function overloaded to make calling the function a lot simpler.
	void mergeSort(std::vector<int>&list)
	{
		mergeSort(list, 0 , list.size() - 1);
	}

	//function overloaded to make calling the function a lot simpler.
	void recursiveBinarySearch(std::vector<int>& list, int target)
	{
		recursiveBinarySearch(list, target, 0, list.size() - 1);
	}

	void nonRecursiveBinarySearch(const std::vector<int>& list, int target);

	int sequentialSearch(const std::vector<int>& list, int target);

};	