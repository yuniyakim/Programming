#include "pch.h"
#include <stdio.h>

int main()
{
	char brackets[100] = "";
	printf("Enter your string ");
	scanf("%s", brackets);
	int a = 0;
	for (int i = 0; i < 100; i++)
	{
		if ((a >= 0) && (brackets[i] != '\0'))
		{
			if (brackets[i] == '(')
			{
				a++;
			}
			else
			{
				a--;
			}
		}
		else
			if (brackets[i] == '\0')
			{
				(a == 0 ? printf("Right") : printf("Wrong"));
				break;
			}
			else
			{
				printf("Wrong");
				break;
			}
	}
	return 0;
}