#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <stdio.h>

int main()
{
	int n;
	printf("n = ");
	scanf_s("%u", &n);
	for (; n != 1; n--)
	{
		for (int i = n - 1; i != 1; i--)
		{
			if (n % i == 0)
			{
				break;
			}
			if (i == 2)
			{
				printf("%u  ", n);
			}
		}
	}
	printf("%u", 2);
	return 0;
}