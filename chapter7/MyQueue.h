#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "iostream"
#include "stdio.h"
#include "algorithm"
#include "queue"
using namespace std;
//A1056
void A1056()
{
	typedef struct mouse {
		int weight;
		int R;
	}Mouse;
	int np,ng, order;
	scanf("%d %d", &np, &ng);
	Mouse* mptr = new Mouse[np];
	for (int i = 0; i < np; i++)
		scanf("%d", &mptr[i].weight);

	queue<int> q;
	for (int i = 0; i < np; i++)
	{
		scanf("%d", &order);
		q.push(order);
	}
	int temp = np, group;
	while (q.size() != 1)
	{
		//calculate group numbers
		if (temp%ng == 0) group = temp / ng;
		else group = temp / ng + 1;

		for (int i = 0; i < group; i++) {
			int k = q.front();
			for (int j = 0; j < ng; j++)
			{
				if (i*ng + j >= temp) break;
				int front = q.front();
				if (mptr[front].weight > mptr[k].weight) k = front;
				mptr[front].R = group + 1;
				q.pop();
			}
			q.push(k);
		}
		temp = group;
	}
	mptr[q.front()].R = 1;
	for (int i = 0; i < np; i++)
	{
		printf("%d",mptr[i].R);
		if (i < np - 1) printf(" ");
	}
	delete[] mptr;
/*
11 3
25 18 0 46 37 3 19 22 57 56 10
6 0 8 7 10 5 9 1 4 2 3
*/
}