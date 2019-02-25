#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "iostream"
#include "math.h"
using namespace std;
typedef long long ll;
//A0181 Rational Sum
ll gcd(ll a, ll b)
{
	return b == 0 ? a : gcd(b, a%b);
}
typedef struct fraction {
	ll up, down;
}Fraction;
//»¯¼ò
Fraction reduction(Fraction result)
{
	if (result.down < 0)
	{
		result.down = -result.down;
		result.up = -result.up;
	}
	if (result.up == 0) result.down = 1;
	else {
		ll d = gcd(abs(result.up), abs(result.down));

		result.down /= d;
		result.up /= d;
	}
	return result;
}
Fraction Add(Fraction a, Fraction b)
{
	Fraction result;
	result.up = a.up*b.down + a.down*b.up;
	result.down = a.down*b.down;
	return reduction(result);
}
void showResult(Fraction r)
{
	reduction(r);
	if (r.down == 1) printf("%lld\n", r.up);
	else if (abs(r.up) > abs(r.down))
	{
		printf("%lld %lld/%lld\n", r.up / r.down, r.up%r.down, r.down);
	}
	else printf("%lld/%lld\n", r.up, r.down);
}
void A1081()
{
	int n;
	scanf("%d", &n);
	Fraction* Fptr = new Fraction[n];
	Fraction sum;
	sum.up = 0;
	sum.down = 1;
	for (int i = 0; i < n; i++)
	{
		scanf("%lld/%lld", &Fptr[i].up, &Fptr[i].down);
		sum = Add(sum, Fptr[i]);

	}

	sum=reduction(sum);

	showResult(sum);
	delete[] Fptr;
/*
5
2/5 4/15 1/30 -2/60 8/3

3
1/3 -1/6 1/8
*/
}
//B1034 Rational Arithmetic
Fraction Sub(Fraction a, Fraction b)
{
	Fraction result;
	result.up = a.up*b.down - a.down*b.up;
	result.down = a.down*b.down;
	return reduction(result);
}
Fraction Mul(Fraction a, Fraction b)
{
	Fraction result;
	result.up = a.up*b.up;
	result.down = a.down*b.down;
	return reduction(result);
}
Fraction Div(Fraction a, Fraction b)
{
	Fraction result;
	result.up = a.up*b.down;
	result.down = a.down*b.up;
	return reduction(result);
}
void showResult2(Fraction r)
{
	reduction(r);
	if (r.up < 0) printf("(");
	if (r.down == 1) printf("%lld", r.up);
	else if (abs(r.up) > abs(r.down))
	{
		printf("%lld %lld/%lld", r.up / r.down, r.up%r.down, r.down);
	}
	else printf("%lld/%lld", r.up, r.down);
	if (r.up < 0) printf(")");
}
void PrintPrecess(Fraction a, Fraction b, char c)
{
	bool flag = true;
	showResult2(a);
	printf("%c", c);
	showResult2(b);
	printf("=");
	Fraction result;
	if (c == '+') result = Add(a, b);
	else if (c == '-') result = Sub(a, b);
	else if (c == '*') result = Mul(a, b);
	else if (c == '/')
	{
		if(b.up!=0)
		result = Div(a, b);
		else flag = false;
	}
	if(flag)
	showResult2(result);
	else printf("Inf");
	printf("\n");
}
void B1034()
{
	Fraction a, b;
	scanf("%lld/%lld %lld/%lld", &a.up, &a.down, &b.up, &b.down);
	a = reduction(a);
	b = reduction(b);
	PrintPrecess(a, b, '+');
	PrintPrecess(a, b, '-');
	PrintPrecess(a, b, '*');
	PrintPrecess(a, b, '/');
/*
2/3 -4/2

5/3 0/6
*/



}