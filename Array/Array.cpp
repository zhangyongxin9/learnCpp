// Array.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

const int row = 6;
const int col = 5;
int test[row][col] = {
	{ 3, 4, 5 ,9,	18} ,
	{ 2, 3, 6 ,1,	2 } ,
	{ 1, 9, 2 ,9,	66 },
	{ 0, 3, 55 ,67,	33 },
	{ 1, 56, 81 ,9,	90 },
	{ 13, 13, 2 ,14,	90 },
};

void printCircleCore(int start)
{
	if (start >= row/2.0 || start >= col/2.0)
		return;

	for (int j = start; j < col-start; ++j)
		cout << " " << test[start][j];
	for (int j = start+1; j < row - start; ++j)
		cout << " " << test[j][col - start - 1];
	for (int j = col -start-1-1; j >=start; --j)
		cout << " " << test[row -start-1][j];
	for (int j = row - start - 1-1; j >= start+1;--j)
		cout << " " << test[j][start];


	printCircleCore(start + 1);
}

void printCircle()
{
	printCircleCore(0);
}

int main()
{
	printCircle();
	getchar();
	return 0;
}

