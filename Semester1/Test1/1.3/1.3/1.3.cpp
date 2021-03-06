#include "pch.h"
#include <stdio.h>

void change(char mass[], int begin, int end) // функция, которая переставляет элементы
{
	int end0 = end;
	for (int i = begin, j = end; i < j; i++, j--)
	{
		int help = mass[i];
		mass[i] = mass[end0];
		mass[end0] = help;
		end0--;
	}
}

int main()
{
	FILE *file = fopen("1.3.txt", "r");
	if (!file) {
		printf("file not found!");
		return 1;
	}
	char *data[100] = {};
	int linesRead = 0;
	while (!feof(file)) {
		char *buffer = new char[100];
		const int readBytes = fscanf(file, "%s", buffer);
		if (readBytes < 0) {
			break;
		}
		data[linesRead] = buffer;
		++linesRead;
	}
	fclose(file);

	change(*data, 0, 100);

	for (int i = 0; i < 100; ++i)
	{
		FILE *out = fopen("1.3.txt", "w");
		fwrite(data, sizeof(char), 100, out);
		fclose(out);
	}
}