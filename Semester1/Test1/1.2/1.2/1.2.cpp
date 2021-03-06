#include "pch.h"
#include <stdio.h>
#include <cstdlib>

int arraySize(int mass[], int first, int last)
{
	return last - first + 1;
}

void swap(int mass[], int element1, int element2)
{
	int help = mass[element1];
	mass[element1] = mass[element2];
	mass[element2] = help;
}

void selectionSort(int mass[], int n)
{
	for (int i = 0; i < n; ++i)
	{
		int numberOfMinimum = i;
		for (int k = i + 1; k < n; ++k)
		{
			if (mass[k] < mass[numberOfMinimum])
			{
				numberOfMinimum = k;
			}
		}
		swap(mass, i, numberOfMinimum);
	}
}

void printMass(int mass[], int low, int high)
{
	for (int i = low; i < high; ++i)
	{
		printf("mass[%u] = %u\n", i, mass[i]);
	}
	printf("\n");
}

void test()
{
	int massTest[10]{ 4, 6, 13, 1, 9, 5, 1, 4, 2, 7 };
	selectionSort(massTest, 10);
	if ((massTest[3] == 4) && (massTest[0] == massTest[1]) && (massTest[2] < massTest[9]) && (massTest[7] >= massTest[5]))
	{
		printf("Test passed\n");
	}
	else
	{
		printf("Test failed\n");
	}
	printf("\n");
}

int main()
{
	int const n = 10;

	test();
	
	int mass[n] = { 0 };

	for (int i = 0; i < n; ++i)
	{
		printf("Enter the number %u of your array ", i);
		scanf("%u", &mass[i]);
	}

	printf("\n");

	selectionSort(mass, n);

	printMass(mass, 0, n);

	return 0;
}