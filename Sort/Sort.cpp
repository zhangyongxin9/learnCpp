// Sort.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
using namespace std;

//--快速排序
int partition(int data[], int start, int end)
{
	int keyValue = data[start];
	int i = start;
	int j = end;
	while (i < j)
	{
		while (data[j] >= keyValue && i < j)
			--j;
		while (data[i] <= keyValue && i < j)
			++i;

		if (i < j)
			swap(data[i], data[j]);
	}
	swap(data[start], data[i]);
	return i;
}

void quickSort(int data[], int len,int start,int end)
{
	if (start == end)
		return;

	int index = partition(data , start, end);
	
	if(index>start)
		quickSort(data, len, start, index-1);
	if (index < end)
		quickSort(data, len, index +1, end);
}

void printSort( int data[],int len)
{
	quickSort(data, len, 0, len - 1);
	for (int i=0; i<len;++i)
		cout << data[i] << " " << endl;
}

int main()
{
	int data[] = { 3,8,2,7,6,1,9,0};
	printSort(data, sizeof(data) / sizeof(data[0]) );
	 
	getchar();
	return 0;
}

