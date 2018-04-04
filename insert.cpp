/******************************
*Author: Andrew Soback
*******************************/

#include "insert.hpp"
#include <iostream>

/*********************************************************
*Copied from https://www.geeksforgeeks.org/insertion-sort/
**********************************************************/
void insertSort(int arr[], int size)
{
	int key, j;
	for (int i = 1; i < size; i++)
	{
		key = arr[i];
		j = i - 1;

		/* Move elements of arr[0..i-1], that are
		greater than key, to one position ahead
		of their current position */
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}

	/*
	//print array, to check that sort works correctly
	//Leave commented out for sorting large arrays
	for (int x = 0; x < size; x++) {
		std::cout << arr[x] << " ";
	}
	std::cout << std::endl;
	*/
}