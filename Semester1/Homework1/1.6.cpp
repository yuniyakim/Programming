#include "pch.h"
#include <stdio.h>

int main()
{
	char s1[100] = "";
	char s2[100] = "";
	int n = 0;
	int length1 = 0;
	int length2 = 0;
	printf("Enter string 1 ");
	scanf("%s", s1);
	for (int i = 0; s1[i] != '\0'; i++)
	{
		length1++;
	}
	printf("Enter string 2 ");
	scanf("%s", s2);
	for (int i = 0; s2[i] != '\0'; i++)
	{
		length2++;
	}
	for (int i = 0; i <= length1 - length2; i++)
	{
		if (s1[i] == s2[0])
		{
			int help = 0;
			for (int l = 0; l < length2; l++)
			{
				if (s1[i + l] == s2[l])
				{
					help++;
				}
			}
			if (help == length2)
			{
				n++;
			}
		}
	}
	printf("The number of entries is %u", n);
	return 0;
}
