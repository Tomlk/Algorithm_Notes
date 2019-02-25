#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "iostream"
#include "algorithm"
#include "stdio.h"
using namespace std;
//B1003
void B1003()
{
	int N;
	scanf("%d", &N);
	while (--N >= 0)
	{
		char str[100];
		scanf("%s",str);
		int len = strlen(str);
		int P_num = 0;
		int T_num = 0;
		int loc_P, loc_T;
		int others_num = 0;
		for (int i = 0; i < len; i++)
		{
			if (str[i] == 'P') {
				P_num++;
				loc_P = i;
			}
			else if (str[i] == 'T')
			{
				T_num++;
				loc_T = i;
			}
			else if (str[i] != 'A')
			{
				others_num++;
			}
		}
		bool flag=true;
		if (others_num != 0) flag = false;
		else if (P_num == 1 && T_num == 1 && loc_P < loc_T - 1)
		{
			for (int i = loc_P + 1; i < loc_T; i++)
			{
				if (str[i] == 'A') continue;
				else {
					flag = false;
					break;
				}
			}
		}
		else flag = false;

		if (flag) printf("YES\n");
		else printf("NO\n");

	}
}
//B1019
void to_array(int n, int* num)
{
	for (int i = 0; i < 4; i++)
	{
		num[i] = n % 10;
		n /= 10;
	}
}
int to_number(int* num)
{
	int sum = 0;
	for (int i = 0; i < 4; i++)
		sum = sum * 10 + num[i];
	return sum;
}
bool cmpB10191(int a,int b)
{
	return a > b;
}
bool cmpB10192(int a, int b)
{
	return a < b;
}
void B1019()
{
	int number;
	scanf("%d", &number);
	int sort1[4];
	int sort2[4];
	while (number != 6174)
	{
		to_array(number, sort1);
		sort(sort1, sort1 + 4, cmpB10191);
		int temp1 = to_number(sort1);
		to_array(number, sort2);
		sort(sort2, sort2 + 4, cmpB10192);//sort(sort2,sort2+4);
		int temp2 = to_number(sort2);
		number = temp1 - temp2;
		printf("%04d-%04d=%04d\n", temp1, temp2, number);
	}
}
//B1049 
void B1049()
{
	int n;
	scanf("%d", &n);
	double* a = new double[n];
	for (int i = 0; i < n; i++)
		scanf("%lf", &a[i]);
	double sum = 0;
	for (int i = 0; i < n; i++)

	{
		for (int j = 0; j < n - i; j++)
		{
			int n = i + 1;
			for (int z = j; z < j + i + 1; z++)
				sum += a[z];
		}
	}
	printf("%lf", sum);
	delete[] a;
/*
4
0.1 0.2 0.3 0.4
*/
}
//A1008 elevator
void A1008()
{
	int totaltime = 0;
	int n;
	scanf("%d", &n);
	int* a = new int[n];
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	totaltime += n * 5;
	totaltime += a[0] * 6;
	for (int i = 0; i < n - 1; i++)
	{
		int temp = abs(a[i] - a[i + 1]);
		if (a[i] > a[i + 1])
			totaltime += temp * 4;
		else
			totaltime += temp * 6;

	}
	printf("%d", totaltime);
	delete[] a;
/*
3 2 3 1
*/
}
//A1049 Counting Ones
void A1049()
{
	int n, a = 1, ans = 0;
	int left, now, right;
	scanf("%d", &n);
	while (n / a != 0)
	{
		left = n / (a * 10);
		now = n / a % 10;
		right = n % a;
		if (now == 0) ans += left * a;
		else if (now == 1) ans += left * a + right + 1;
		else ans += (left + 1)*a;
		a *= 10;
	}
	printf("%d\n", ans);
}
