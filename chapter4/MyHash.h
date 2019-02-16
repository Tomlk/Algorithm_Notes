#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "iostream"
#include "stdio.h"
#include "algorithm"
#include <cmath>
#include "cstring"
#include "vector"
using namespace std;
//B1029
void B1029()
{
	char str1[100];
	char str2[100];
	bool keywell[128] = { false };
	bool hasprint[128] = { false };
	gets_s(str1);//you 空格
	gets_s(str2);
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	for (int i = 0; i < len2; i++)
	{
		keywell[str2[i]] = true;
		if (str2[i] <= 'z'&&str2[i] >= 'a') keywell[str2[i] - 32] = true;
		else if (str2[i] <= 'Z'&&str2[i] >= 'A') keywell[str2[i] + 32] = true;
	}
	for (int i = 0; i < len1; i++)
	{
		if (keywell[str1[i]] == false)
		{
			if (hasprint[str1[i]] == false)
			{
				if (str1[i] <= 'z'&&str1[i] >= 'a')
				{
					hasprint[str1[i]] = true;
					char temp = str1[i] - 32;
					hasprint[temp] = true;
					printf("%c", temp);
				}
				else if (str1[i] <= 'Z'&&str1[i] >= 'A')
				{
					hasprint[str1[i]] = true;
					char temp = str1[i] + 32;
					hasprint[temp] = true;
					printf("%c", str1[i]);
				}
				else {
					hasprint[str1[i]] = true;
					printf("%c", str1[i]);
				}
			}
		}
	}
/*
7 This is a test
 hs s a es
*/
}
//B1033
void B1033()
{
	bool keywell[128] = { true };
	for (int i = 0; i < 128; i++)
	{
		keywell[i] = true;
	}

	char badkey[256];
	char str[100];
	gets_s(badkey);
	gets_s(str);
	int lenkeys = strlen(badkey);
	int inputlen = strlen(str);
	for (int i = 0; i < lenkeys; i++)
	{
		keywell[badkey[i]] = false;
		if (badkey[i] <= 'z'&&badkey[i] >= 'a') keywell[badkey[i] - 32] = false;
		else if(badkey[i] <= 'Z'&&badkey[i] >= 'A') keywell[badkey[i] + 32] = false;
	}
	char sdj = '+';
	if (keywell[sdj] == false)
	{
		for (int i = 'A'; i <= 'Z'; i++)
		{
			keywell[i] = false;
		}
	}
	for (int i = 0; i < inputlen; i++)
	{
		if (keywell[str[i]] == true) printf("%c", str[i]);
	}
/*
7+IE
7 This is a test
*/
}
//B1038 统计同成绩学生
void B1038()
{
	int gradenumber[101] = { 0 };
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		int temp;
		scanf("%d", &temp);
		gradenumber[temp]++;
	}

	int K;
	scanf("%d", &K);
	for (int i = 0; i < K; i++)
	{
		int temp;
		scanf("%d", &temp);
		printf("%d", gradenumber[temp]);
		if (i != K - 1) printf(" ");
	}
/*
10
60 75 90 55 75 99 82 90 75 50
3 75 90 88
*/
}
//B1039 到底买不买
void B1039()
{
	bool flag = true;
	int shengyu[128] = { 0 };
	char strtz[100];
	char strwant[100];
	gets_s(strtz);
	gets_s(strwant);
	int tzlen = strlen(strtz);
	int wantlen = strlen(strwant);
	for (int i = 0; i < tzlen; i++)
	{
		shengyu[strtz[i]]++;
	}
	for (int i = 0; i < wantlen; i++)
	{
		shengyu[strwant[i]]--;
	}
	for (int i = 0; i < wantlen; i++)
	{
		if (shengyu[strwant[i]] < 0) 
		{	
			flag = false;
			break;
		}
	}
	if (flag)
	{
		printf("Yes ");
		printf("%d", tzlen - wantlen);
		/*int sum = 0;
		for (int i = 0; i < tzlen; i++)
			sum += shengyu[strtz[i]];
		printf("%d", sum);*/
	}
	else
	{
		printf("No ");
		int negativeN = 0;
		for (int i = 0; i < wantlen; i++)
		{
			if (shengyu[strwant[i]] < 0)
				negativeN += abs(shengyu[strwant[i]]);
		}
		printf("%d", negativeN);
	}
/*
1)
ppRYYGrrYBR2258
YrR8RrY

2)
ppRYYGrrYB258
YrR8RrY
*/
}
//B1042字符统计
void B1042()
{
	int Ctime[128] = { 0 };
	char strinput[100];
	gets_s(strinput);
	int len = strlen(strinput);
	for (int i = 0; i < len; i++)
	{
		//Ctime[strinput[i]]++;
		if (strinput[i] >= 'a'&&strinput[i] <= 'z') {
			Ctime[strinput[i]]++;
			Ctime[strinput[i]-32]++;
		}
		else if (strinput[i] >= 'A'&&strinput[i] <= 'Z') { 
			Ctime[strinput[i]]++;
			Ctime[strinput[i]+32]++; }
	}
	int max = Ctime[0];
	char c;
	for (int i = 0; i < 128; i++)
	{
		//if(i>)
		if (Ctime[i] > max)
		{
			max = Ctime[i];
			c = i;
		}
	}
	//if(c>='A')
	c = c + 32;
	printf("%c %d", c, max);

/*
This is a simple TEST.  There ARE numbers and other symbols 1&2&3...
*/
}
//B1043 输出PATest
void B1043()
{
	int shengyu[128] = { 0 };
	char str[10000];
	gets_s(str);
	int len = strlen(str);
	for (int i = 0; i < len; i++)
	{
		shengyu[str[i]]++;
	}
	int i = 0;
	int Pn = 'P';
	int An = 'A';
	int Tn = 'T';
	int en = 'e';
	int sn = 's';
	int tn = 't';
	while (shengyu[Pn]>0||shengyu[An]>0|| 
		shengyu[Tn]>0|| shengyu[en]>0|| shengyu[sn]>0||shengyu[tn]>0)
	{
		if (i == 0)
		{
			if (shengyu[Pn]>0)
			{
				printf("P");
				shengyu[Pn]--;
			}
			i++;
		}
		else if (i == 1)
		{
			if (shengyu[An] > 0)
			{
				printf("A");
				shengyu[An]--;
			}
			i++;
		}
		else if(i==2)
		{
			if (shengyu[Tn] > 0)
			{
				printf("T");
				shengyu[Tn]--;
			}
			i++;
		}
		else if (i==3)
		{
			if (shengyu[en] > 0)
			{
				printf("e");
				shengyu[en]--;
			}
			i++;
		}
		else if (i==4)
		{
			if (shengyu[sn] > 0)
			{
				printf("s");
				shengyu[sn]--;
			}
			i++;
		}
		else if (i == 5)
		{
			if (shengyu[tn] > 0)
			{
				printf("t");
				shengyu[tn]--;
			}
			i=0;
		}
	}
/*
redlesPayBestPATTopTeePHPereatitAPPT
*/
}
//B1047 编程团体赛
void B1047()
{
	int teamtotalS[1001] = { 0 };
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int teamN;
		int peopleN;
		int getscore;
		scanf("%d-%d %d", &teamN, &peopleN, &getscore);
		teamtotalS[teamN] += getscore;
	}
	int championTeam = 1;
	int maxScore = teamtotalS[championTeam];
	for (int i = 0; i < 1001; i++)
	{
		if (teamtotalS[i] > maxScore)
		{
			championTeam = i;
			maxScore = teamtotalS[i];
		}
	}
	printf("%d %d", championTeam, maxScore);
/*
6
3-10 99
11-5 87
102-1 0
102-3 100
11-9 89
3-2 61
*/
}
//A1041 Be Unique
void A1041()
{
	int N;
	scanf("%d", &N);
	int* bettingqueue = new int[N];
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &bettingqueue[i]);
	}
	int numberTime[10001] = { 0 };
	for (int i = 0; i < N; i++)
	{
		numberTime[bettingqueue[i]]++;
	}
	bool getreward = false;
	int winnerN = 0;
	for (int i = 0; i < N; i++)
	{
		if (numberTime[bettingqueue[i]] == 1)
		{
			winnerN = bettingqueue[i];
			getreward = true;
			break;

		}
	}
	if (getreward) printf("%d", winnerN);
	else printf("None");
	delete[] bettingqueue;
/*
7 5 31 5 88 67 88 17

5 888 666 666 888 888
*/
}
//A1050 String Subtraction
void A1050()
{
	char S1[10000];
	char S2[10000];
	char S[10000];
	gets_s(S1);
	gets_s(S2);
	bool strflag[128] = { false };
	for (int i = 0; i < strlen(S2); i++)
	{
		strflag[S2[i]] = true;
	}
	for (int i = 0; i < strlen(S1); i++)
	{
		if (!strflag[S1[i]])
		{
			printf("%c", S1[i]);
		}
	}
/*
They are students
aeiou
*/
}
//B1005 继续(3n+1)的猜想
bool cmpB1005(int a, int b)
{
	return a > b;
}
void B1005()
{
	int n, m, a[110];
	scanf("%d", &n);
	bool HashTable[10000] = { 0 };
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		m = a[i];
		while (m!=1)
		{
			if (m % 2 == 1) m = (3 * m + 1) / 2;
			else m = m / 2;
			HashTable[m] = true;
		}
	}

	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (HashTable[a[i]] == false) count++;
	}
	sort(a, a + n, cmpB1005);
	for (int i = 0; i < n; i++)
	{
		if (HashTable[a[i]] == false)
		{
			printf("%d", a[i]);
			count--;
			if (count > 0) printf(" ");
		}
	}
/*
6
3 5 6 7 8 11
*/
}
//A1048 Find Coins
bool cmpA1048(int a, int b)
{
	return a < b;
}
void A1048()
{
	int coinN;
	int Price;
	scanf("%d %d", &coinN,&Price);
	int* coinMe = new int[coinN];
	for (int i = 0; i < coinN; i++)
	{
		scanf("%d", &coinMe[i]);
	}
	sort(coinMe, coinMe + coinN, cmpA1048);
	bool hasWay = false;
	int coin1;
	int coin2;
	for (int i = 0; i < coinN; i++)
	{
		for (int j = i + 1; j < coinN; j++)
		{
			if (coinMe[i] +coinMe[j] == Price)
			{
				coin1 = coinMe[i];
				coin2 = coinMe[j];
				hasWay = true;
				break;
			}
			
		}
		if (hasWay) break;
	}
	if (hasWay) printf("%d %d", coin1, coin2);
	else printf("No Solution");
	delete[] coinMe;
/*
8 15
1 2 8 7 2 4 11 15

7 14
1 8 7 2 4 11 15
*/
}