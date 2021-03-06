#include "pch.h"
#include <stdio.h>
#include <iostream>

int main()
{
	setlocale(LC_ALL, "Russian");

	FILE *file = fopen("1.3.2.txt", "r");
	
	if (!file) 
	{
		printf("Файл не найден\n");
		return 1;
	}
	else
	{
		fseek(file, 0, SEEK_END);
		int size = ftell(file);
		if (size != 0)
		{
			fseek(file, 0, SEEK_SET);
			int linesRead = 0;
			while (!feof(file) && (linesRead < 100))
			{
				char *buffer = new char[200];
				fgets(buffer, strlen(buffer), file); // считали строку
				int i = 0;
				while ((i < strlen(buffer)) && !(buffer[i] == ';'))
				{
					++i;
				}
				if (buffer[i] == ';')
				{
					while (i < strlen(buffer))
					{
						printf("%c", buffer[i]);
						++i;
					}
				}
			}
			printf("\n");
			++linesRead;
		}
		else
		{
			printf("Файл пуст\n");
		}
	}

	fclose(file);

	return 0;
}
// В некоторых языках программирования однострочные комментарии задаются не //, как в С++, а символом ";" 
// (комментарий начинается с ; и заканчивается концом строки). 
// Задача - вывести на консоль все комментарии такого вида из входного файла (вместе с символом ";"). 
// До комментария в строке может быть значимый текст, его выводить не надо. Пустые строки выводить не надо.

