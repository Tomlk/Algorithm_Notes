#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "iostream"
#include "stdio.h"
#include "algorithm"
using namespace std;
//A1098 Insertion or Heap Sort
const int maxn = 111;
int origin[maxn], tempOri[maxn], changed[maxn];
int n;
bool isSame(int* A, int* B)
{
	for (int i = 1; i <= n; i++)
	{
		if (A[i] != B[i]) return false;
	}
	return true;
}
bool insertSort()
{
	bool flag = false;
	for (int i = 2; i <= n; i++)
	{
		if (i != 2 && isSame(tempOri, changed))
		{
			flag = true;
		}
		sort(tempOri+1, tempOri +i + 1);
		if (flag == true)
			return true;
	}
	return false;
}
void HeapAdjust(int low, int high)
{
	int temp;
	while (2 * low <= high)//exist lchild
	{
		int i = 2 * low;
		if (i+1 <= high && tempOri[i+1] > tempOri[i])//rchild exist and bigger than lchild
		{
			i++;
		}
		if (tempOri[i] > tempOri[low])
		{
			//exchange
			swap(tempOri[low], tempOri[i]);
			low = i;//continue from this node
		}
		else {
			break;
		}
	}
}
void Heap_sort(int n)
{
	bool flag = false;
	for (int i = n / 2; i >= 1; i--)
		HeapAdjust(i, n);
	for (int i = n; i > 1; i--)
	{
		if (i != n && isSame(tempOri, changed))
			flag = true;
		swap(tempOri[1], tempOri[i]);
		HeapAdjust(1, i - 1);
		if (flag == true)
		{
			//printf("Insertion Sort\n");
			for (int i = 1; i <= n; i++)
			{
				printf("%d", tempOri[i]);
				if (i < n) printf(" ");
			}
			printf("\n");
			return;
		}
	}
}
void A1098()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &origin[i]);
		tempOri[i] = origin[i];
	}
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &changed[i]);
	}
	if (insertSort())
	{
		printf("Insertion Sort\n");
		for (int i = 1; i <= n; i++)
		{
			printf("%d", tempOri[i]);
			if (i < n) printf(" ");
		}
		printf("\n");
	}
	else {
		printf("Heap Sort\n");
		for (int i = 1; i <= n; i++)
		{
			tempOri[i] = origin[i];
		}
		Heap_sort(n);
	}
/*
10
3 1 2 8 7 5 9 4 6 0
1 2 3 7 8 5 9 4 6 0

10
3 1 2 8 7 5 9 4 6 0
6 4 5 1 0 3 2 7 8 9
*/
}