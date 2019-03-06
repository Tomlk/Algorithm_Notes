#pragma once
#include "iostream"
#include "algorithm"
#include "stdio.h"
#include "map"
#include "math.h"
using namespace std;
const int maxn = 1001;
//A1040 Longest Symmetric String
void A1040Brutal()
{
	char str[1001];
	gets_s(str);
	int len = strlen(str);
	int Max = 0;
	for (int i = 0; i < len; i++)
	{
		int pindex = i;
		int pl = 0;
		int pl2 = 0;
		for (int j = len - 1; j > i; j--)
		{
			int temp = j;
			while (str[pindex] == str[temp]&& temp >pindex)
			{
				pl += 2;
				pindex++;
				temp--;
			}
			if (temp == pindex)
			{
				pl += 1;
				if (pl > pl2)
				{
					pl2 = pl;
				}
			}
			else {
				pl = 0;
			}
		}
		if (pl2 > Max)
		{
			Max = pl2;
		}
		
	}
	printf("%d", Max);

}

char S[maxn];
int dp[maxn][maxn];
void A1040()
{
	gets_s(S);
	int len = strlen(S);
	int ans = 1;
	memset(dp, 0, sizeof(dp));
	
	/*for(int i=0;i<maxn;i++)
		for(int j=0;j<maxn;j++)
			dp[i][j]=0;*/
	
	for (int i = 0; i < len; i++)
	{
		dp[i][i] = 1;
		if (i < len - 1)
		{
			if (S[i] == S[i + 1])
			{
				dp[i][i + 1] = 1;
				ans = 2;
			}
		}
	}
	//for (int i = 0; i < len; i++)
	//	for (int j = 0; j < len; j++)
	//	{
	//		printf("%d ", dp[i][j]);
	//		if (j == len - 1)
	//			printf("\n");
	//	}
	for (int L = 3; L <= len; L++)
	{
		//L从小到大
		for (int i = 0; i + L - 1 < len; i++)
		{
			int j = i + L - 1;
			if (S[i] == S[j] && dp[i + 1][j - 1] == 1)
			{
				dp[i][j] = 1;
				ans = L;
			}
		}
	}
	//printf("\n");
	//for (int i = 0; i < len; i++)
	//	for (int j = 0; j < len; j++)
	//	{
	//		printf("%d ", dp[i][j]);
	//		if (j == len - 1)
	//			printf("\n");
	//	}
	
	printf("%d", ans);


//Is PAT&TAP symmetric?
}
