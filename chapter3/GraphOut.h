#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "iostream"
#include "stdio.h"
#include <cmath>
#include "vector"
//square
void B1036()
{
	int N;
	char C;
	scanf("%d %c", &N,&C);
	int row;
	if (N % 2 == 0) row = N / 2;
	else row = N / 2 + 1;

	for (int i = 0; i < row; i++)
	{
		if (i == 0||i==row-1) {
			for (int j = 0; j < N; j++)
				printf("%c", C);
			printf("\n\n");
		}
		else
		{
			printf("%c", C);
			for (int j = 0; j < N - 2; j++)
				printf(" ");
			printf("%c\n\n", C);
		}
	}
}

void B1027()
{
	int N;
	char C;
	scanf("%d %c", &N, &C);
	int sum = 1;
	int temp = 1;
	int kgs = 0;
	while (sum < N)
	{
		temp += 2;
		sum += 2 * (temp);
	}
	int realUsed = sum - 2 * (temp);
	temp -= 2;
	int temp2 = temp;
	while (temp != 1)
	{
		for (int i = 0; i < kgs; i++)
			printf(" ");
		for (int i = 0; i < temp; i++)
			printf("%c", C);
		printf("\n\n\n");
		temp -= 2;
		kgs++;
	}
	for (int i = 0; i < kgs; i++)
		printf(" ");
	printf("%c\n\n\n", C);
	temp += 2;
	kgs--;
	while (temp <= temp2)
	{
		for (int i = 0; i < kgs; i++)
			printf(" ");
		for (int i = 0; i < temp; i++)
			printf("%c", C);
		printf("\n\n\n");
		temp += 2;
		kgs--;
	}
	printf("%d", N - realUsed);

}

//Hello World for U
void A1031() {

	char str[20];
	scanf("%s", str);
	int Len = strlen(str);
	int n1 = 0;
	int n2=0;
	for ( n1 = 1; n1 < 100; n1++)
	{
		n2 = Len - 2 * n1 + 2;
		if (n1 <= n2) n1++;
		else
		{
			n1--;
			n2= Len - 2 * n1 + 2;
			break;
		}

	}
	printf("%d %d %d\n", Len, n1, n2);

	int index;
	for (int i = 0; i < n1 - 1; i++)
	{
		printf("%c", str[i]);
		for (int j = 0; j < n2 - 2; j++)
			printf(" ");
		printf("%c\n\n", str[Len - 1 - i]);
		if (i == n1 - 2) index = i;

	}
	for (int i = index+1; i < index + n2+1; i++)
	{
		printf("%c", str[i]);

	}

}