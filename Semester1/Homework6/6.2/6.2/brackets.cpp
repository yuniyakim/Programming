#include "pch.h"
#include "brackets.h"
#include "stack.h"
#include <iostream>
using namespace std;

bool isBrackets(char string[])
{
	Stack* stack = createStack();
	const int length = strlen(string);
	int i = 0;
	while (i < length)
	{
		if ((string[i] == '(') || (string[i] == '[') || (string[i] == '{'))
		{
			push(stack, string[i]);
		}
		else if (isEmpty(stack))
		{
			deleteStack(stack);
			return false;
		}
		else if (((string[i] == ')') && (valueOfHead(stack) == '(')) || ((string[i] == ']') && (valueOfHead(stack) == '[')) || ((string[i] == '}') && (valueOfHead(stack) == '{')))
		{
			deleteHead(stack);
		}
		else
		{
			deleteStack(stack);
			return false;
		}
		++i;
	}
	bool flag = isEmpty(stack);
	deleteStack(stack);
	return flag;
}