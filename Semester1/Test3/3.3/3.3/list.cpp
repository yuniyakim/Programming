#include "pch.h"
#include "list.h"
#include <iostream>
using namespace std;

struct List
{
	int value;
	List *next;
};

List *createList()
{
	return nullptr;
}

void deleteList(List *list)
{
	List *temp = list;
	while (temp != nullptr)
	{
		List *temp2 = temp;
		temp = temp->next;
		delete temp2;
	}
}

List *addIntoList(List *list, int value)
{
	List *newList = new List{ value, nullptr };
	if (list == nullptr)
	{
		list = newList;
	}
	else
	{
		List *temp = list;
		while (temp->next != nullptr)
		{
			temp = temp->next;
		}
		temp->next = newList;
	}
	return list;
}

bool isEmptyList(List *list)
{
	return list == nullptr;
}

bool existsList(List *list, int value)
{
	if (isEmptyList(list))
	{
		return false;
	}

	List *temp = list;
	while (temp != nullptr)
	{
		if (value == temp->value)
		{
			return true;
		}
		temp = temp->next;
	}
	return false;
}

int valueOfElement(List *list)
{
	return list->value;
}

List *nextOfList(List *list)
{
	List *temp = list->next;
	return temp;
}

int numberOfRecords(List *list)
{
	int numberOfRecords = 0;
	List *temp = list;
	while (temp != nullptr)
	{
		temp = nextOfList(temp);
		++numberOfRecords;
	}
	return numberOfRecords;
}

void printList(List *list)
{
	const int number = numberOfRecords(list);
	List *temp = list;
	for (int i = 0; i < number; ++i)
	{
		cout << valueOfElement(temp) << endl;
		temp = nextOfList(temp);
	}
}

void nextNullptr(List *list)
{
	list->next = nullptr;
}

void nextTo(List *list, List *list2)
{
	list->next = list2;
}