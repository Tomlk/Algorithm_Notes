#pragma once
#include "iostream"
#include "stdio.h"
#include "math.h"
using namespace std;
//A1096 Consecutive Factors
void A1096()
{
	int n;
	scanf("%d", &n);
	int first = n;
	int len = 1;
	//int start=-1;
	for (int i = 2; i <= sqrt(n); i++)
	{
		int start = i;
		int j = i;
		int result = i;
		while (n%result==0)
		{
			j++;
			result = result * j;
		}
		result = result / j;
		j--;
		if (n%result==0)
		{
			int thislen = j - start + 1;
			if (thislen > len)
			{
				first = start;
				len = thislen;
			}
		} 
	}
	printf("%d\n", len);
	for (int i = first; i < first + len; i++)
	{
		if (i == first) printf("%d", i);
		else printf("*%d", i);
	}
/*
630
*/
}
//A1059 Prime Factors
const int MAXN = 100000;
int pNum = 0;
void Find_PrimeA1059(const int n,int* prime,bool* p)
{
	for (int i = 2; i < MAXN; i++)
	{
		if (p[i] == false)
		{
			prime[pNum++] = i;
			if (pNum >= n) break;
			//É¸µô±¶Êý
			for (int j = i + i; j < MAXN; j += i)
			{
				p[j] = true;
			}
		}
	}
}
struct factor
{
	int x, cnt;
}fac[10];
void A1059()
{
	int prime[MAXN] = { 0 };
	bool p[MAXN] = { 0 };
	Find_PrimeA1059(MAXN, prime, p);
	int n, num = 0;
	scanf("%d", &n);
	if (n == 1) printf("1=1");
	else {
		printf("%d=", n);
		int sqr = (int)sqrt(1.0*n);
		for (int i = 0; i < pNum&&prime[i] <= sqr; i++)
		{
			if (n%prime[i] == 0)
			{
				fac[num].x = prime[i];
				fac[num].cnt = 0;
				while (n%prime[i] == 0)
				{
					fac[num].cnt++;
					n /= prime[i];
				}
				num++;
			}
			if (n == 1) break;
		}
		if (n != 1)
		{
			fac[num].x = n;
			fac[num++].cnt = 1;
		}
		for (int i = 0; i < num; i++)
		{
			if (i > 0) printf("*");
			printf("%d", fac[i].x);
			if (fac[i].cnt > 1)
			{
				printf("^%d", fac[i].cnt);
			}
		}

	}

}