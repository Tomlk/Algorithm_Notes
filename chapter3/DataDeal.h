#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "iostream"
#include "stdio.h"
#include <cmath>
#include "vector"
using namespace std;
//B1022
void B1022()
{
	//除基取余法
	int A, B;
	int D;
	vector<int> vec;
	scanf("%d %d %d", &A, &B, &D);
	int sum = A + B;
	int temp = sum;
	int Y;
	while (temp / D != 0)
	{
		Y = temp % D;
		temp = temp / D;
		vec.push_back(Y);
	}
	Y = temp % D;
	vec.push_back(Y);
	while (!vec.empty())
	{
		temp = vec.back();
		printf("%d", temp);
		vec.pop_back();
		
	}
}
//B1037
void B1037()
{
	int g1, s1, k1;//should pay
	int g2, s2, k2;//really pay
	scanf("%d.%d.%d %d.%d.%d", &g1, &s1, &k1, &g2, &s2, &k2);
	int total1 = g1 * 17 * 29 + s1 * 29 + k1;
	int total2 = g2 * 17 * 29 + s2 * 29 + k2;
	int  Cha = total2 - total1;
	int temp = abs(Cha);
	int g3, s3, k3;
	k3 = temp % 29;
	s3 = (temp - k3) % (17 * 29);
	s3 = s3 / 29;
	g3 = (temp - k3 - 29 * s3) / (17 * 29);
	if (Cha < 0) printf("-");
	printf("%d.%d.%d", g3, s3, k3);



}
//A1019 General Palindromic Number
void A1019()
{
	//除基取余法
	int A;
	int D;
	vector<int> vec;
	scanf("%d %d", &A, &D);
	int temp = A;
	int Y;
	while (temp / D != 0)
	{
		Y = temp % D;
		temp = temp / D;
		vec.push_back(Y);
	}	
	Y = temp % D;
	vec.push_back(Y);
	int len = vec.size();
	bool flag = true;
	for (int i=0; i < len / 2; i++)
	{
		if (vec[i] == vec[len - 1 - i]) continue;
		else
		{
			flag = false;
		}
	}
	if (flag) printf("Yes\n");
	else printf("No\n");
	while (!vec.empty())
	{
		temp = vec.back();
		printf("%d", temp);
		vec.pop_back();

	}
}
//A1027 Color in Mars
void A1027()
{
	//10进制数转13进制数
	int r1, g1, b1;
	//int r2, g2, b2;
	scanf("%d %d %d", &r1, &g1, &b1);
	int a[3];
	a[0] = r1;
	a[1] = g1;
	a[2] = b1;
	int temp = r1;
	int D = 13;
	int Y;
	vector<int> vec;
	printf("#");
	for (int i = 0; i < 3; i++)
	{
		vec.clear();
		temp = a[i];
		while (temp / D != 0)
		{
			Y = temp % D;
			temp = temp / D;
			vec.push_back(Y);
		}
		Y = temp % D;
		vec.push_back(Y);
		while (!vec.empty())
		{
			temp = vec.back();
			if (temp < 10)
				printf("%d", temp);
			else if (temp == 10) printf("A");
			else if (temp == 11)printf("B");
			else printf("C");
			vec.pop_back();
		}
	}
}

//A1058 A+B in Hogwarts
void A1058()
{
	int g1, s1, k1;//should pay
	int g2, s2, k2;//really pay
	scanf("%d.%d.%d %d.%d.%d", &g1, &s1, &k1, &g2, &s2, &k2);
	int total1 = g1 * 17 * 29 + s1 * 29 + k1;
	int total2 = g2 * 17 * 29 + s2 * 29 + k2;
	int  Sum = total2 + total1;
	int temp = abs(Sum);
	int g3, s3, k3;
	k3 = temp % 29;
	s3 = (temp - k3) % (17 * 29);
	s3 = s3 / 29;
	g3 = (temp - k3 - 29 * s3) / (17 * 29);
	if (Sum < 0) printf("-");
	printf("%d.%d.%d", g3, s3, k3);

}