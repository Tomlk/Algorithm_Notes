#pragma once
#include "iostream"
#include "stdio.h"
#include "math.h"
#include "vector"
using namespace std;
//B1007
bool isPrime(int a)
{
	if (a <= 1) return false;
	int sqr = (int)sqrt(1.0*a);
	for (int i = 2; i <= sqr; i++)
	{
		if (a%i == 0) return false;
	}
	return true;
}
void B1007()
{
	int N;
	scanf("%d", &N);
	int i = 5;
	int number = 0;
	while (i <= N)
	{
		if (isPrime(i)&&isPrime(i-2))
			number++;
		i += 2;
	}
	printf("%d", number);

}
//B1013
//筛法
const int maxn = 100000;
bool p[maxn] = { 0 };
int prime[maxn] = { 0 };
int index = 0;
void Find_Prime(int n)
{
	for (int i = 2; i < maxn; i++)
	{
		if (p[i] == false)
		{
			prime[index++] = i;
			if (index >= n) break;
			//筛掉倍数
			for (int j = i + i; j < maxn; j += i)
			{
				p[j] = true;
			}
		}
	}
}
void Brutal()
{
	int m, n;
	scanf("%d %d", &m, &n);
	int index = 0;
	int a = 1;
	while (index < m)
	{

		if (isPrime(++a))
		{
			index++;
		}
	}
	int i = 0;
	//index = m;
	while (index <= n)
	{
		if (isPrime(a))
		{
			i++;
			if (i == 10) {
				i = 0;
				printf("%d\n",a);
			}
			else
				printf("%d ", a);
			index++;
		}
		a++;
	}
}
void B1013()
{
	int m, n;
	scanf("%d %d", &m, &n);
	Find_Prime(n);
	int index = 0;
	for (int i = m - 1; i < n; i++)
	{
		index++;
		if (index == 10)
		{
			printf("%d\n", prime[i]);
			index = 0;
		}
		else
		{
			printf("%d ", prime[i]);
		}
	}
	//Brutal();
}
//A1015 Reversible Primes
void A1015()
{
	int N, D;
	int data[20];
	while (scanf("%d", &N) != EOF)
	{
		if (N < 0) break;
		int N1 = N;
		scanf("%d", &D);
		int i = 0;
		while (N / D != 0)
		{
			int temp = N % D;
			N = N / D;
			data[i] = temp;
			i++;
		}
		data[i] = N % D;
		int len = i+1;
		int N2=0;
		for (int i = 0; i < len ; i++)
		{
			N2 += data[i]*pow(D, len - 1 - i);
			//printf("%d ", data[i]);
		}
		//printf("%d\t", N2);
		//printf("%d %d\n", N, N2);
		if (isPrime(N1) && isPrime(N2))
		{
			printf("Yes\n");
		}
		else printf("No\n");

	}

	//printf("%d", isPrime(29));
}
//A1078 Hashing
void A1078()
{
	const int N = 11111;
	bool hashTable[N] = { 0 };
	int n, TSize, a;
	scanf("%d %d", &TSize, &n);
	while (!isPrime(TSize))
	{
		TSize++;
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a);
		int M = a % TSize;
		if (hashTable[M] == false)
		{
			hashTable[M] = true;
			if (i == 0) printf("%d", M);
			else printf(" %d", M);
		}
		else {
			int step;
			for (step = 1; step < TSize; step++)
			{
				M = (a + step * step) % TSize;//仅仅正向
				if (hashTable[M] == false)
				{
					hashTable[M] = true;
					if (i == 0) printf("%d", M);
					else printf(" %d", M);
					break;
				}
			}
			if (step >= TSize)
			{
				if (i > 0) printf(" ");
				printf("-");
			}
		}
	}

/*
4 4
10 6 4 15
*/
}