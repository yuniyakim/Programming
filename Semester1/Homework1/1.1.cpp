#include "pch.h"
#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
	int x, sqrx;
	cout << "x = ";
	cin >> x;
	sqrx = x * x;
	cout << "Result is " << (sqrx + x)*(sqrx + 1) + 1;
	return 0;
}