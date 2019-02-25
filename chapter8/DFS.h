#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "iostream"
#include "stdio.h"
#include "algorithm"
#include "vector"
#include "math.h"
using namespace std;
//A1103
int n, k, p;
int maxFacSum = -1;
vector<int> fac, ans, temp;
void init()
{
	int i = 0,temp = 0;
	while (temp <= n)
	{
		fac.push_back(temp);
		temp = pow(++i, p);
	}
}
void DFS(int index, int nowK, int sum, int facSum)
{
	if (sum == n && nowK == k)
	{
		if (facSum > maxFacSum)
		{
			ans = temp;
			maxFacSum = facSum;
		}
		return;
	}
	if (sum > n || nowK > k) return;
	if (index - 1 >= 0)
	{
		temp.push_back(index);
		DFS(index, nowK + 1, sum + fac[index], facSum + index);
		temp.pop_back();
		DFS(index - 1, nowK, sum, facSum);
	}
}
void A1103()
{
	scanf("%d %d %d", &n, &k, &p);
	init();
	DFS(fac.size() - 1, 0, 0, 0);
	if (maxFacSum == -1) printf("Impossible\n");
	else {
		printf("%d=%d^%d", n, ans[0], p);
		for (int i = 1; i < ans.size(); i++)
			printf("+ %d^%d", ans[i], p);
	}
/*
169 5 2
169 167 3
*/
}