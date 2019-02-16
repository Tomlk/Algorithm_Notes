#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "iostream"
#include "stdio.h"
#include "algorithm"
#include <cmath>
#include "string"
#include "vector"
using namespace std;
//B1030
void B1030_2()
{
	int N, p;
	scanf("%d %d", &N, &p);
	int* a = new int[N];
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &a[i]);
	}
	sort(a, a + N);
	int i = 0, j = 0;
	int count = 1;
	while (i < N&&j < N)
	{
		while (j < N&&a[j] <= (long long)a[i] * p) {
			count = max(count, j - i + 1);
			j++;
		}
		i++;
	}
	printf("%d", count);
/*
10 8
2 3 20 4 5 1 6 7 8 9
*/
}
//B1035
void Exchange(int &a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
bool isSame(int* a1, int* a2,int n)
{
	bool flag = true;
	for (int i = 0; i < n; i++)
	{
		if (a1[i] == a2[i])
			continue;
		else {
			flag = false;
			break;
		}
	}
	return flag;
}
bool insertSort(int* a, int* b,int n)
{
	int flag = 0;
	int flag2 = 0;
	for(int i=0;i<n;i++)
		for (int j = i; j > 0; j--)
		{
			if (a[j] < a[j - 1])
			{				
				Exchange(a[j], a[j - 1]);
				if (isSame(a, b,n))
				{
					flag ++;
				}
			}
			else
			{
				if (flag != 0)
				{
					flag2++;
					if (flag2 >= 2) return true;
				}
				break;
			}
		}
	return false;
}
void mergeSort(int* a, int* b, int n)
{
	bool flag = false;
	for (int step = 2; step / 2 <= n; step *= 2)
	{
		if (step != 2 &&isSame(a, b, n)) flag = true;

		for (int i = 0; i < n; i += step)
			sort(a + i, a + min(i + step, n));

		if (flag == true) return;
	}
}
void B1035()
{
	int n;
	scanf("%d", &n);
	int* originA = new int[n];
	int* tempA = new int[n];
	int* changedA = new int[n];
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &originA[i]);
		tempA[i] = originA[i];
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &changedA[i]);
		
	}
	if (insertSort(originA, changedA,n))
	{
		printf("Insertion sort\n");
		for (int i = 0; i < n; i++)
		{
			if (i < n - 1)
				printf("%d ", originA[i]);
			else printf("%d", originA[i]);
		}
	}
	else 
	{
		mergeSort(tempA, changedA, n);
		printf("Merge sort\n");
		for (int i = 0; i < n; i++)
		{
			if (i < n - 1)
				printf("%d ", tempA[i]);
			else printf("%d", tempA[i]);
		}
	}

	delete[] originA;
	delete[] tempA;
	delete[] changedA;
/*
10
3 1 2 8 7 5 9 4 6 0
1 2 3 7 8 5 9 4 6 0

10
3 1 2 8 7 5 9 4 0 6
1 3 2 8 5 7 4 9 0 6
*/

}
//A1029 Median
void A1029()
{
	int n1, n2, N;
	scanf("%d", &n1);
	int* pa1 = new int[n1];
	for (int i = 0; i < n1; i++)
	{
		scanf("%d", &pa1[i]);
	}
	scanf("%d", &n2);
	int* pa2 = new int[n2];
	for (int i = 0; i < n2; i++)
		scanf("%d", &pa2[i]);

	int* pa3 = new int[n1 + n2];
	for (int i = 0; i < n1 + n2; i++)
	{
		if (i < n1)
			pa3[i] = pa1[i];
		else
			pa3[i] = pa2[i - n1];

	}
	sort(pa3, pa3 + n1 + n2);
	int index = (n1 + n2) / 2;
	printf("%d", pa3[index]);
	delete[] pa1;
	delete[] pa2;
	delete[] pa3;

/*
4 11 12 13 14
5 9 10 15 16 17
*/
}

//A1048 Find Coins   tow points ½â·¨
void A1048Twopoints()
{
	int n, m;
	scanf("%d %d", &n, &m);
	int* a = new int[n];
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);
	int i = 0, j = n - 1;
	while (i < j)
	{
		if (a[i] + a[j] == m) break;
		else if (a[i] + a[j] < m)
		{
			i++;
		}
		else {
			j--;
		}
	}
	if (i < j)
		printf("%d %d", a[i], a[j]);
	else printf("No solution");
	delete[] a;
/*
6 14
4 10 7 7 2 12
*/
}
//B1040 
void B1040()
{
	const int MAXN = 10010;
	char str[MAXN];
	gets_s(str);
	int len = strlen(str);
	int leftNumP[MAXN] = { 0 };
	for (int i = 0; i < len; i++)
	{
		if (i > 0) leftNumP[i] = leftNumP[i - 1];
		if (str[i] == 'P') leftNumP[i]++;
	}
	int ans = 0, rightNumT = 0;
	for (int i = len - 1; i >= 0; i--)
	{
		if (str[i] == 'T')
			rightNumT++;
		else if (str[i] == 'A')
			ans = (ans + leftNumP[i] * rightNumT) % 1000000007;
	}
	printf("%d", ans);
/*
APPAPT
*/
}
//B1045
void B1045()
{
	int n;
	scanf("%d", &n);
	int* a = new int[n];
	int* leftMax = new int[n];
	int* rightMin = new int[n];
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	leftMax[0] = 0;
	rightMin[n - 1] = 1000000;
	for (int i = 1; i < n; i++)
	{
		if (a[i-1] > leftMax[i - 1]) leftMax[i] = a[i-1];
		else leftMax[i] = leftMax[i - 1];
	}
	for (int i = n - 2; i >= 0; i--)
	{
		if (a[i+1] < rightMin[i + 1]) rightMin[i] = a[i+1];
		else rightMin[i] = rightMin[i + 1];
	}
	int total = 0;
	for (int i = 0; i < n; i++)
	{
		if (leftMax[i] <= a[i] && rightMin[i] >= a[i]) total++;
	}
	printf("%d\n", total);
	int time = 0;
	for (int i = 0; i < n; i++)
	{

		if (leftMax[i] <= a[i]&&rightMin[i]>=a[i])
		{
			if (time <= total - 1)
				printf("%d ", a[i]);
			else printf("%d", a[i]);
		}
	}
	delete[] a;
	delete[] leftMax;
	delete[] rightMin;
/*
5
1 3 2 4 5
*/
}