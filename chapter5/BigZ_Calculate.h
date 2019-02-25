#pragma once
#include "stdio.h"
#include "iostream"
#include "string.h"
using namespace std;
//B1017
typedef struct bign {
	int d[1010];
	int len;
	bign()
	{
		memset(d, 0, sizeof(d));//clean memory
		len = 0;
	}
}Bign;
Bign change(char str[])
{
	Bign a;
	a.len = strlen(str);
	for (int i = 0; i < a.len; i++)
	{
		a.d[i] = str[a.len - i - 1] - '0';
	}
	return a;
}
Bign divide(Bign a, int b, int& r)
{
	Bign c;
	c.len = a.len;
	for (int i = a.len - 1; i >= 0; i--)
	{
		r = r * 10 + a.d[i];
		if (r < b) c.d[i] = 0;
		else {
			c.d[i] = r / b;
			r = r % b;
		}
	}
	while (c.len - 1 >= 1 && c.d[c.len - 1] == 0)
	{
		c.len--;
	}
	return c;
}
Bign multi(Bign a, int b)
{
	Bign c;
	int carry = 0;
	for (int i = 0; i < a.len; i++)
	{
		int temp = a.d[i] * b + carry;
		c.d[c.len++] = temp % 10;
		carry = temp / 10;
	}
	while (carry != 0)
	{
		c.d[c.len++] = carry % 10;
		carry /= 10;
	}
	return c;
}

void B1017()
{
	char str1[1010];
	int b, r=0;
	scanf("%s%d", str1, &b);
	Bign a = change(str1);
	Bign result = divide(a, b, r);

	for (int i = result.len - 1; i >= 0; i--)
		printf("%d", result.d[i]);
	printf(" %d", r);
//123456789050987654321 7
}
bool JudgeA1023(Bign a, Bign b)
{
	if (a.len != b.len) return false;
	int count[10] = { 0 };
	for (int i = 0; i < a.len; i++)
	{
		count[a.d[i]]--;
		count[b.d[i]]++;
	}
	for (int i = 0; i < 10; i++)
	{
		if (count[i] == 0) continue;
		else return false;
	}
	return true;
}
void A1023()
{
	char str[21];
	scanf("%s", str);
	Bign a = change(str);
	Bign b = multi(a, 2);
	if (JudgeA1023(a, b)) printf("Yes\n");
	else printf("No\n");
	for (int i = 0; i < b.len; i++)
	{
		printf("%d", b.d[b.len-i-1]);
	}
/*
1234567899
*/
}

//A1024 Palindromic Number
typedef struct myPnum {

	int a[20];
	int b[20];
	int len;
	myPnum()
	{
		len = 0;
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
	}
}MyPnum;
bool IsPalindromicN(MyPnum n)
{
	for (int i = 0; i < n.len/2; i++)
	{
		if (n.a[i] == n.a[n.len - i - 1]) continue;
		else return false;
	}
	return true;
}
MyPnum Str2Pnum(char* str)
{
	int len = strlen(str);
	MyPnum pnum;
	pnum.len = len;
	for (int i = 0; i < len; i++)
	{
		pnum.a[i] = str[i]-'0';
		pnum.b[i] = str[len - i - 1]-'0';
	}
	return pnum;
}
void PrintMyPnum(MyPnum a,int k)
{
	int time = 0;
	while (!IsPalindromicN(a))
	{
		time++;
		MyPnum c;
		int carry = 0;
		for (int i = 0; i < a.len; i++)
		{
			int temp = a.b[i] + a.a[i] + carry;
			c.b[c.len++] = temp % 10;
			carry = temp / 10;
		}
		while (carry != 0)
		{
			c.b[c.len++] = carry % 10;
			carry /= 10;
		}
		for (int i = 0; i < c.len; i++)
		{
			c.a[i] = c.b[c.len - i - 1];
		}
		a = c;
		if (time == k) break;
	}
	for (int i = 0; i < a.len; i++)
	{
		printf("%d", a.a[i]);
	}
	printf("\n%d", time);
}
void A1024()
{
	char strN[20];
	int k;
	scanf("%s%d", strN, &k);
	MyPnum n = Str2Pnum(strN);
	PrintMyPnum(n, k);
/*
67 3

69 3
*/
}