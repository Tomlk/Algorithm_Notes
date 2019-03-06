#pragma once
#include "iostream"
#include "stdio.h"
#include "map"
#include "math.h"
using namespace std;
const int maxc = 201;
const int maxn = 10001;
//A1045 Favorite Color Stripe
//Solution one LIS
map<int, int> M;
void A1045()
{
	int n,m;
	scanf_s("%d %d", &n, &m);
	int A[maxn], dp[maxn];
	for (int i = 0; i < m; i++)
	{
		int temp;
		scanf_s("%d", &temp);
		M[temp] = i;
	}
	int L, num = 0;
	scanf_s("%d", &L);
	for (int i = 0; i < L; i++)
	{
		int temp;
		scanf_s("%d", &temp);
		if (M.find(temp) != M.end())
		{
			A[num++] = M[temp];
		}
	}
	//start
	int ans = -1;
	for (int i = 0; i < num; i++)
	{
		dp[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (A[j] <= A[i] && dp[i] < dp[j] + 1)
			{
				dp[i] = dp[j] + 1;
			}
		}
		printf("dp[%d] %d\n", i, dp[i]);
		//对每个i都找到其dp[i]
		ans = ans > dp[i] ? ans : dp[i];
	}
	for (int i = 0; i < num; i++)
		printf("%d ", A[i]);
	printf("\n%d", ans);
/*
6
5 2 3 1 5 6
12 2 2 4 1 5 5 6 3 1 1 5 6
*/

}