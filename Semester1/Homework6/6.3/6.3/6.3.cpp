#include "pch.h"
#include "fromInfixIntoPostfix.h"
#include "test.h"
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	test();

	char input[50]{};
	char output[50]{};
	cout << "Введите арифметическое выражение в инфиксной форме " << endl;
	cin.getline(input, 50);
	fromInfixIntoPostfix(input, output);
	cout << "Результат в постфиксной форме: " << output;
	return 0;
}