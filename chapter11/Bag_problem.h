#pragma once
#include "iostream"
#include "algorithm"
#include "stdio.h"
#include "map"
#include "math.h"
using namespace std;
//A1068 Find More Coins
const int maxn = 10001;
const int maxv = 110;
int w[maxn], dp[maxv] = { 0 };
bool choice[maxn][maxv], flag[maxn];
bool cmp(int a, int b)
{
	return a > b;
}
void A1068()
{
	int n, m;
	scanf_s("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf_s("%d", &w[i]);
	}
	sort(w + 1, w + n + 1, cmp);//9 8 7 5 4 3 2 1
	for (int i = 1; i <= n; i++)
	{
		for (int v = m; v >= w[i]; v--)
		{
			if (dp[v] <= dp[v - w[i]]+w[i])//dp[9]=0<=dp[9-9]+9 dp[9]=9<=dp[9-8]+8
			{								//dp[8]=0<=dp[8-8]+8
				dp[v] = dp[v - w[i]] + w[i];//dp[9]=9 dp[8]=8
				choice[i][v] = 1;//放入第i件物品//choice[1][9]=1 choice[2][8]=1
			}
			else choice[i][v] = 0;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		printf("%d:",w[i]);
		for (int j = 1; j <= m; j++)
			printf("%d ", choice[i][j]);
		printf("\n");
	}
	if (dp[m] != m)  printf("No solution");//无解
	else {
		//记录最优路径
		int k = n, num = 0, v = m;
		while (k >= 0)
		{
			if (choice[k][v] == 1)
			{
				flag[k] = true;
				v -= w[k];
				num++;
			}
			else flag[k] = false;
			k--;
		}
		//输出方案
		for (int i = n; i >= 1; i--)
		{
			if (flag[i] == true)
			{
				printf("%d", w[i]);
				num--;
				if (num > 0) printf(" ");
			}

		}
	}
/*
8 9
5 9 8 7 2 3 4 1 

4 8
7 2 4 3
*/
}