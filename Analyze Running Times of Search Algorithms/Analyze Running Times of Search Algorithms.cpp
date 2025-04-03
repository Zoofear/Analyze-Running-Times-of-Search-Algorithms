// Analyze Running Times of Search Algorithms.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "listSearch.h"
int main(){
	std::vector<int> list = {37, 25, 84, 3, 90, 154, 54, 78, 109, 128};

	listSearch list1(list);

	std::cout << "The list \n";
	list1.printList();

	list1.mergeSort();

	std::cout << "List sorted via merge sort \n";
	list1.printList();

	std::cout << "Searching for the target 54 using the recursive binary search algorithm \n";
	int target1 = 54;

	int index = list1.recursiveBinarySearch(target1);

	std::cout << target1 << " found at location " << index << "\n";

	std::cout << "Searching for the target 99 using the recursive binary search algorithm \n";
	int target2 = 99;

	index = list1.recursiveBinarySearch(target2);

	std::cout << target2 << " was not found, retrurn value is " << index << "\n";
	
	std::cout << "Searching for the target 84 using the iterative binary search algorithm \n";
	target1 = 84;

	index = list1.nonRecursiveBinarySearch(target1);

	std::cout << target1 << " found at location " << index << "\n";

	std::cout << "Searching for the target 27 using the iterative binary search algorithm \n";
	target2 = 27;

	index = list1.nonRecursiveBinarySearch(target2);

	std::cout << target2 << " was not found, retrurn value is " << index << "\n";

	std::cout << "Searching for the target 109 using the sequential search algorithm \n";
	target1 = 109;

	index = list1.nonRecursiveBinarySearch(target1);

	std::cout << target1 << " found at location " << index << "\n";

	std::cout << "Searching for the target 300 using the sequential search algorithm \n";
	target2 = 300;

	index = list1.nonRecursiveBinarySearch(target2);

	std::cout << target2 << " was not found, retrurn value is " << index << "\n";

}
