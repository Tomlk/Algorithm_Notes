#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "iostream"
#include "stdio.h"
#include "algorithm"
#include <cmath>
#include "string"
#include "stack"
#include "vector"
using namespace std;
//Pop Sequence
void A1051()
{
	int capacity, length, sequenceN;
	scanf("%d %d %d", &capacity, &length, &sequenceN);
	for (int i = 0; i < sequenceN; i++)
	{

		stack<int> newStack;
		while (!newStack.empty()) newStack.pop();
	//	printf("size:%d", newStack.size());
		int* a = new int[length];
		for (int j = 0; j < length; j++)
			scanf("%d", &a[j]);
		int current = 0;
		bool flag = true;
		for (int j = 0; j < length; j++)
		{
			newStack.push(j + 1);
			if (newStack.size() > capacity)
			{
				flag = false;
				break;
			}
			while (newStack.empty()==false && newStack.top() == a[current])
			{
				newStack.pop();
				current++;
			}
		}

		if (newStack.empty() == true && flag == true)
			printf("YES\n");
		else printf("NO\n");
		delete[] a;
	}
/*
5 7 5
1 2 3 4 5 6 7
3 2 1 7 5 6 4
7 6 5 4 3 2 1
5 6 4 3 7 2 1
1 7 6 5 4 3 2
*/
	
}