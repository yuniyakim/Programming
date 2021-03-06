#include "pch.h"
#include "stack.h"
#include <iostream>
using namespace std;

struct Element
{
	char value;
	Element *next;
};

struct Stack
{
	Element *head;
};

Stack* createStack()
{
	return new Stack{ nullptr };
}

void deleteStack(Stack* stack)
{
	while (stack->head != nullptr) 
	{
		Element *temp = stack->head->next;
		delete stack->head;
		stack->head = temp;
	}
	delete stack;
}

void push(Stack* stack, char value)
{
	if (isEmpty(stack))
	{
		Element *head = new Element{ value, nullptr };
		stack->head = head;
	}
	else
	{
		Element *element = new Element{ value, stack->head };
		stack->head = element;
	}
}

char pop(Stack* stack)
{
	char const value = stack->head->value;
	Element *temp = stack->head->next;
	delete stack->head;
	stack->head = temp;
	return value;
}

bool isEmpty(Stack* stack)
{
	return stack->head == nullptr;
}

void deleteHead(Stack* stack)
{
	Element *temp = stack->head->next;
	delete stack->head;
	stack->head = temp;
}

char valueOfHead(Stack* stack)
{
	return stack->head->value;
}