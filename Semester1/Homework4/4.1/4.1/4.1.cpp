#include "pch.h"
#include "stdio.h"
#include "binaryNumbers.h"
#include <iostream>
#include "test.h"

int main()
{
	//test();

	int number1 = 0;
	int array1[8]{ 0 };
	
	int number2 = 0;
	int array2[8]{ 0 };

	int sum[8]{ 0 };

	setlocale(LC_ALL, "Russian");

	printf("Введите первое число в диапазоне [-128; 127]\n");
	scanf("%d", &number1);
	intoTwosComplement(number1, array1);
	if ((number1 >= -128) && (number1 <= 127))
	{
		printf("Дополнительный код числа %d = ", number1);
		printBinaryNumber(array1);
	}
	
		
	printf("Введите второе число в диапазоне [-128; 127]\n");
	scanf("%d", &number2);
	intoTwosComplement(number2, array2);
	if ((number2 >= -128) && (number2 <= 127))
	{
		printf("Дополнительный код числа %d = ", number2);
		printBinaryNumber(array2);
	}
	
	sumOfTwosComplements(number1, number2, array1, array2, sum);
	if (((number1 >= 0) && (number2 >= 0) && (number1 + number2 < 128)) || ((number1 < 0) && (number2 < 0) && 
		(moduleOfNumber(number1) + moduleOfNumber(number2) < 128)) || ((number1 < 0) && (number2 >= 0)) || ((number1 >= 0) && (number2 < 0)))
	{
		printf("Сумма дополнительных кодов равна ");
		printBinaryNumber(sum);
		printf("Сумма чисел равна %d\n", fromTwosComplement(sum));
	}

	return 0;
}

