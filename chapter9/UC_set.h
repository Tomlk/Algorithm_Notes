#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "iostream"
#include "stdio.h"
#include "algorithm"
using namespace std;
const int N = 1010;
int father[N];
int isRoot[N] = { 0 };
int course[N] = { 0 };
int FindFather(int x)
{
	int a = x;
	while (x != father[x])
	{
		x = father[x];
	}
	while (a != father[a])
	{
		int z = a;
		a = father[a];
		father[z] = x;
	}
	return x;
}
void Union(int a, int b)
{
	int faA = FindFather(a);
	int faB = FindFather(b);
	if (faA != faB) {
		father[faA] = faB;
	}
}
void init(int n)
{
	for (int i = 1; i <= n; i++)
	{
		father[i] = i;
		isRoot[i] = false;
	}
}
bool cmp(int a, int b)
{
	return a > b;
}

void A1107()
{
	int n, k, h;
	scanf("%d", &n);
	init(n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d:", &k);
		for (int j = 0; j < k; j++)
		{
			scanf("%d", &h);
			if (course[h] == 0)
				course[h] = i;
			Union(i, FindFather(course[h]));
		}
	}
	for (int i = 1; i <= n; i++)
		isRoot[FindFather(i)]++;

	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (isRoot[i] != 0)
		{
			ans++;
		}
	}
	printf("%d\n", ans);
	sort(isRoot + 1, isRoot + n + 1, cmp);
	for (int i = 1; i <= ans; i++)
	{
		printf("%d", isRoot[i]);
		if (i < ans) printf(" ");
	}

/*
8
3: 2 7 10
1: 4
2: 5 3
1: 4
1: 3
1: 4
4: 6 8 1 5
1: 4
*/
}