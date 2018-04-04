/******************************
*Author: Andrew Soback
*******************************/

#include "shell.hpp"
#include <iostream>

/****************************************************
*Copied from https://www.geeksforgeeks.org/shellsort/
*****************************************************/
void shellSort(int arr[], int size)
{
	// Start with a big gap, then reduce the gap
	for (int gap = size / 2; gap > 0; gap /= 2)
	{
		// Do a gapped insertion sort for this gap size.
		// The first gap elements a[0..gap-1] are already in gapped order
		// keep adding one more element until the entire array is
		// gap sorted 
		for (int i = gap; i < size; i += 1)
		{
			// add a[i] to the elements that have been gap sorted
			// save a[i] in temp and make a hole at position i
			int temp = arr[i];

			// shift earlier gap-sorted elements up until the correct 
			// location for a[i] is found
			int j;
			for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
				arr[j] = arr[j - gap];

			//  put temp (the original a[i]) in its correct location
			arr[j] = temp;
		}
	}

	/*
	//print array, for testing purposes
	for (int x = 0; x < size; x++) {
		std::cout << arr[x] << " ";
	}
	std::cout << std::endl;
	*/
}