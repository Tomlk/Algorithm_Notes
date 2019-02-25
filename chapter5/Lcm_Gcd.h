#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "iostream"
using namespace std;
//B1008
int gcd(int a, int b) //Õ·×ªÏà³ý·¨
{
	if (b == 0) return a;
	else return gcd(b, a&b);
}
void B1008()
{
	int a[110];
	int n,m, temp, pos, next;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	m = m % n;
	if (m != 0)
	{
		int d = gcd(m, n);
		for (int i = n - m; i < n - m + d; i++)
		{
			temp = a[i];
			pos = i;
			do {
				next = (pos - m + n) % n;
				if (next != i) a[pos] = a[next];
				else a[pos] = temp;
				pos = next;
			} while (pos != i);
		}
	}
	for (int i = 0; i < n; i++)
	{
		printf("%d", a[i]);
		if (i < n - 1) printf(" ");
	}
}