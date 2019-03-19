#pragma once
#include "iostream"
#include "algorithm"
#include "stdio.h"
#include "map"
#include "math.h"
using namespace std;
const int maxc = 201;
const int maxn = 1000;
//A1007
//Solution 2

int A[maxn], B[maxn], dp[maxn][maxn];
void A1007_()
{
	int n, m;
	scanf_s("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		scanf_s("%d", &A[i]);
	}
	int L;
	scanf_s("%d", &L);
	for (int i = 1; i <= L; i++)
	{
		scanf_s("%d", &B[i]);
	}
	//edges
	for (int i = 0; i <= m; i++)
		dp[i][0] = 0;
	for (int i = 0; i <= L; i++)
		dp[0][i] = 0;
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= L; j++)
		{
			int MAX = max(dp[i - 1][j], dp[i][j - 1]);
			if (A[i] == B[j])
			{
				dp[i][j] = dp[i-1][j-1]+ 1;
			}
			else
				dp[i][j] = MAX;
		}
	}
	printf("%d", dp[m][L]);
/*
6
5 2 3 1 5 6
12 2 2 4 1 5 5 6 3 1 1 5 6
*/

}
