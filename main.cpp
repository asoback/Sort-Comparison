/******************************
*Author: Andrew Soback
*Description: Comparing sorting speeds
*of insertion and shell sort.
*******************************/

#include "insert.hpp"
#include "shell.hpp"
#include <time.h>
#include <iostream>
#include <cstdlib>
using std::cout;
using std::endl;
using std::cin;

void comparison(int*, int*, int);
int getInt(int, int);
char yesNo();
void fillArrays(int*, int*, int);

int main() 
{
	srand(time(nullptr));
	int n;
	int *arrayPtr = nullptr;
	int *arrayCopy = nullptr;
	char cont = 'y';

	//Introduction
	cout << "Exploring the difference between insertion sort and shell sort\n\n" << endl;

	//This loop is for comparing the two functions
	while (cont == 'y')
	{
		cout << "Enter a number to randomly fill the array" << endl;
		cout << "Warning, larger numbers can sometimes take a while to compute." << endl;
		n = getInt(1, 1000000);
		arrayPtr = new int[n];
		arrayCopy = new int[n];
		fillArrays(arrayPtr, arrayCopy, n);
		comparison(arrayPtr, arrayCopy, n);

		delete[]arrayPtr;
		delete[]arrayCopy;

		cout << "\n\nWould you like to run another comparison?" << endl;
		cont = yesNo();
	}

	std::cin.get();
	return 0;
}

//This function takes two arrays, and uses two sorting methods, and times them.
void comparison(int *arr1, int *arr2, int n) 
{
	clock_t t;
	cout << "Sorting with insertion..." << endl;
	t = clock();
	insertSort(arr1, n);
	t = clock() - t;
	cout << "This process took " << t << " clock ticks, or "
		<< (float)t / CLOCKS_PER_SEC << "seconds.";

	cout << "\n" << endl;
	cout << "Sorting with shell sort... " << endl;
	t = clock();
	shellSort(arr2, n);
	t = clock() - t;
	cout << "This process took " << t << " clock ticks, or "
		<< (float)t / CLOCKS_PER_SEC << "seconds." << endl;
}

//Gets an integer from the user, takes min and max integer inputs.
//Input is validated.
int getInt(int min, int max)
{
	int userIn;
	cin >> userIn;
	while (!cin || userIn < min || userIn > max)
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << "You either did not enter a number, or entered a number outside my range." << endl;
		cout << "Try a number between " << min << " and " << max << "." << endl;
		cin >> userIn;
	}
	cin.get();
	return userIn;
}

//Gets a 'y' or 'n' from the user, used for
//choosing whether or not to run a comparison again.
char yesNo()
{
	char yN;
	cout << "Enter 'y' for yes, or 'n' for no: ";
	cin >> yN;
	yN = tolower(yN);
	while (yN != 'n' && yN != 'y')
	{
		cout << "It looks like the wrong key was pressed, try again: ";
		cin >> yN;
		yN = tolower(yN);
	}
	return yN;
}

//Takes two arrays and fills them with random numbers. Both arrays are the same.
void fillArrays(int* arr, int* arrCopy, int size) 
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 10;
		arrCopy[i] = arr[i];
	}
}