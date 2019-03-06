#pragma once
#include "iostream"
#include "stdio.h"
using namespace std;
const int maxn = 10001;
//A1007 Maximum Subsequence Sum
void A1007()
{
	int a[maxn];	//序列
	int dp[maxn]; //dp[i]表示最后一个元素为a[i]的最大和
	int s[maxn] = {0}; //s[i]表示获得dp[i]最大和的第一个数字索引j

	int n;
	scanf_s("%d", &n);
	bool flag = false;
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &a[i]);
		if (a[i] > 0)
		{
			flag = true;
		}
	}
	if (flag == false)
	{
		printf("0 %d %d", a[0], a[n - 1]);
	}
	//start
	dp[0] = a[0];
	for (int i = 1; i < n; i++)
	{
		//state transform
		if (dp[i - 1] + a[i] > a[i])
		{
			dp[i] = dp[i - 1] + a[i];
			s[i] = s[i - 1];
		}
		else {
			dp[i] = a[i];
			s[i] = i;
		}
	}
	int max = dp[0];
	int index = 0;
	for (int i = 1; i < n; i++)
	{
		if (dp[i] > max)
		{
			index = i;
			max = dp[i];
		}
		//printf("%d ", dp[i]);
	}
	printf("\n%d %d %d", max, s[index], index);
/*
10
-10 1 2 3 4 -5 -23 3 7 -21
*/
}