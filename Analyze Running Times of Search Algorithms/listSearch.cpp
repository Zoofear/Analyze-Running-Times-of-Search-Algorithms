#pragma once

#include <iostream>
#include <vector>
#include "listSearch.h"

//functions

void listSearch::mergeSort(std::vector<int>& vec)
{
	int size = vec.size();

	//basecase
	if (size <= 1)
	{
		return;
	}
	
	//splitting the lists
	int middle = size / 2;
	std::vector<int> leftlist(middle);
	std::vector<int> rightlist(size - middle);

	//copying the lists
	int j = 0;
	for ( int i = 0; i < size; i++)
	{
		if (i < middle)
		{
			leftlist[i] = vec[i];
		}
		else
		{
			rightlist[j] = vec[i];
			j++;
		}
	}
	
	//recursive calls
	mergeSort(leftlist);
	mergeSort(rightlist);
	merge(vec, leftlist, rightlist);
}
void listSearch::merge(std::vector<int>& vec, std::vector<int> leftlist, std::vector<int> rightlist)
{
	int leftsize = vec.size() / 2;
	int rightsize = vec.size() - leftsize;
	//original vector index
	int i = 0;

	//left vector index
	int l = 0;

	//right vector index
	int r = 0;

	while (l < leftsize && r < rightsize)
	{
		if (leftlist[l] < rightlist[r])
		{
			vec[i] = leftlist[l];
			i++;
			l++;
		}
		else
		{
			vec[i] = rightlist[r];
			i++;
			r++;
		}
	}
	while (l < leftsize)
	{
		vec[i] = leftlist[l];
		i++;
		l++;
	}
	while (r < rightsize)
	{
		vec[i] = rightlist[r];
		i++;
		r++;
	}
}

int listSearch::recursiveBinarySearch(std::vector<int>& vec, int target, int low, int high)
{
	if (low <= high)
	{
		int mid = low + (high - low) / 2; //For splitting the array in half when searching

		if (vec[mid] == target)
		{
			return mid; //target Found
		}
		else if (vec[mid] < target)
		{
			return recursiveBinarySearch(vec, target, mid + 1, high);
		}
		else
		{
			return recursiveBinarySearch(vec, target, low, mid - 1);
		}
	}
	else
	{
		return -1; //target not found
	}
}

int listSearch::nonRecursiveBinarySearch(const std::vector<int>& vec, int target)
{
	int low = 0;
	int high = vec.size() - 1;

	while (low <= high)
	{
		int mid = low + (high - low) / 2;

		if (vec[mid] == target)
		{
			return mid; //target found
		}
		else if (vec[mid] < target)
		{
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}
	return -1; //target not found
}

int listSearch::sequentialSearch(const std::vector<int>& vec, int target)
{
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i] == target)
		{
			return i;//target found
		}
	}

	return -1; //Target not found
}