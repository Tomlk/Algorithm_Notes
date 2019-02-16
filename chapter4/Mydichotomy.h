#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "iostream"
#include "stdio.h"
#include "algorithm"
#include <cmath>
#include "string"
#include "vector"
using namespace std;
//B1030
bool cmpB1030(int a, int b)
{
	return a < b;
}
int binarySearch(int* a,int n,int i, long long x)
{
	if (a[n - 1] <= x) return n;
	int l = i + 1, r = n - 1, mid;
	while (l < r)
	{
		mid = (l + r) / 2;
		if (a[mid] <= x)
		{
			l = mid + 1;
		}
		else
		{
			r = mid;
		}
	}
	return l;
}
void B1030()
{
	int N, p;
	scanf("%d %d", &N, &p);
	int* a = new int[N];
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &a[i]);
	}
	sort(a, a + N, cmpB1030);
	int i = 0, j = N - 1;
	int ans = 1;
	for (int i = 0; i < N; i++)
	{
		int j = binarySearch(a, N, i, (long long)a[i] * p);
		ans = max(ans, j - i);

	}
	printf("%d\n", ans);
	delete[] a;
/*
10 8
2 3 20 4 5 1 6 7 8 9
*/
}
//A1010 Radix
long long Map[256];
long long inf = (1 << 63) - 1;
void init() {
	for (char c = '0'; c <= '9'; c++)
	{
		Map[c] = c - '0';
	}
	for (char c = 'a'; c <= 'z'; c++)
	{
		Map[c] = c - 'a' + 10;
	}
}
long long convertNum10(char a[], long long radix, long long t)
{
	long long ans = 0;
	int len = strlen(a);
	for (int i = 0; i < len; i++)
	{
		ans = ans * radix + Map[a[i]];
		if (ans<0 || ans>t) return -1;
	}
	return ans;
}
int cmpA1010(char N2[], long long radix, long long t)
{
	int len = strlen(N2);
	long long num = convertNum10(N2, radix, t);
	if (num < 0) return 1;
	if (t > num) return -1;
	else if (t == num) return 0;
	else return 1;
}
long long binarySearch(char N2[], long long left, long long right, long long t)
{
	long long mid;
	while (left <= right)
	{
		mid = (left + right) / 2;
		int flag = cmpA1010(N2, mid, t);
		if (flag == 0) return mid;
		else if (flag == -1) left = mid + 1;
		else right = mid - 1;
	}
	return -1;
}
int findLargestDigit(char N2[])
{
	int ans = -1, len = strlen(N2);
	for (int i = 0; i < len; i++)
	{
		if (Map[N2[i]] > ans)
		{
			ans = Map[N2[i]];
		}
	}
	return ans + 1;
}
void A1010()
{
	char N1[20], N2[20], temp[20];
	int tag, radix;
	init();
	scanf("%s %s %d %d", N1, N2, &tag, &radix);
	if (tag == 2)
	{
		strcpy(temp, N1);
		strcpy(N1, N2);
		strcpy(N2, temp);
	}
	long long t = convertNum10(N1, radix, inf);
	long long low = findLargestDigit(N2);
	long long high = max(low, t) + 1;
	long long ans = binarySearch(N2, low, high, t);
	if (ans == -1) printf("Impossible\n");
	else printf("%lld\n", ans);
	//return 0;
/*
6 110 1 10
*/
}
//A1044
int upper_boundA1044(int L, int R, int x,int* a)
{
	int left = L, right = R, mid;
	while (left < right)
	{
		mid = (left + right) / 2;
		if (a[mid] > x)
		{
			right = mid;
		}
		else {
			left = mid + 1;
		}
	}
	return left;
}
void A1044()
{
	int N, S;
	int nearS = 100000010;
	scanf("%d %d", &N, &S);
	int* sum = new int[N+1];
	sum[0] = 0;
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &sum[i]);
		sum[i] += sum[i - 1];
	}
	for (int i = 1; i <= N; i++)
	{

		int j = upper_boundA1044(i, N + 1, sum[i - 1] + S,sum);
		if (sum[j - 1] - sum[i - 1] == S)
		{
			nearS = S;
			break;
		}
		else if (j <= N && sum[j] - sum[i - 1] < nearS)
		{
			nearS = sum[j] - sum[i - 1];
		}
	}
	for (int i = 1; i <= N; i++)
	{
		int j = upper_boundA1044(i, N + 1, sum[i - 1] + nearS,sum);
		if (sum[j - 1] - sum[i - 1] == nearS)
		{
			printf("%d-%d\n", i, j - 1);
		}
	}
	delete[] sum;
/*
16 15
3 2 1 5 4 6 8 9 16 10 15 11 9 12 14 13

5 13
2 4 5 7 9
*/
}
//A1048  Find Coins 二分查找做法
int searchA1048(int l, int r, int x,int* a)
{
	int mid;
	while (l <= r)
	{
		mid = (l + r) / 2;
		if (a[mid] == x) return mid;
		else if (a[mid] > x) r = mid - 1;
		else l = mid + 1;
	}
	return -1;
}
void A1048_2f()
{
	int n, m;
	scanf("%d %d", &n, &m);
	int* a = new int[n];
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	bool flag = false;
	for (int i = 0; i < n; i++)
	{
		int j = searchA1048(0, n - 1, m - a[i], a);
		if (j != i && j != -1)
		{
			printf("%d %d", a[i], m - a[i]);
			flag = true;
			break;
		}
	}

	if (!flag) printf("No Solution");
	delete[] a;
/*
8 15
1 2 8 7 2 4 11 15

7 14
1 8 7 2 4 11 15
*/
}

