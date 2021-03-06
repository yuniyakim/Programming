#include "pch.h"
#include <stdio.h>
#include <cstdlib>

void swap(int mass[], int element1, int element2)
{
	int help = mass[element1];
	mass[element1] = mass[element2];
	mass[element2] = help;
}

int partition(int mass[], int low, int high)
{
	int pivot = mass[high];
	int i = low;

	for (int j = low; j <= high - 1; ++j)
	{
		if (mass[j] <= pivot)
		{
			swap(mass, i, j);
			++i;
		}
	}
	swap(mass, i, high);
	return i;
}

void quickSort(int mass[], int low, int high)
{
	if (low < high)
	{
		int p = partition(mass, low, high);
		quickSort(mass, low, p - 1);
		quickSort(mass, p + 1, high);
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

int theMostFrequentElement(int mass[], int n)
{
	int mostFrequent = 0;
	int amountOfMostFrequent = 0;
	int amountOfPreFrequent = 1;
	int i = 0;

	for (i = 0; i < n - 1; ++i)
	{
		if (mass[i] == mass[i + 1])
		{
			++amountOfPreFrequent;
		}
		else
		{
			if (amountOfPreFrequent > amountOfMostFrequent)
			{
				amountOfMostFrequent = amountOfPreFrequent;
				mostFrequent = i;
			}
			amountOfPreFrequent = 1;
		}
	}
	if (amountOfPreFrequent > amountOfMostFrequent)
	{
		amountOfMostFrequent = amountOfPreFrequent;
		mostFrequent = i;
	}
	return mass[mostFrequent];
}

void test()
{
	int massTest[12]{ 1, 4, 8, 2, 4, 6, 12, 5, 0, 8, 12, 12 };

	quickSort(massTest, 0, 11);

	if ((massTest[1] == 1) && (massTest[8] >= massTest[7]) && (theMostFrequentElement(massTest, 12) == 12))
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
	test();

	int n = 0;

	printf("Enter the number of elements in your array n = ");
	scanf("%u", &n);

	int *mass = new int[n];

	for (int i = 0; i < n; ++i) // заполняем массив случайными числами
	{
		mass[i] = rand() % 10;
		printf("mass[%u] = %u\n", i, mass[i]);
	}
	printf("\n");

	quickSort(mass, 0, n - 1);

	printMass(mass, 0, n);

	printf("The most frequent element in array is %u", theMostFrequentElement(mass, n));

	delete[] mass;
	return 0;
}