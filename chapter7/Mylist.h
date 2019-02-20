#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "iostream"
#include "stdio.h"
#include "algorithm"
#include "list"
#include "set"
#include "queue"
using namespace std;
//B1025
typedef struct B1025node {
	int add;
	int data;
	int next;
	int order;
}B1025Node;
bool cmpB1025(B1025Node a, B1025Node b)
{
	return a.order < b.order;
}
void B1025()
{
	int firstadd;
	int N;
	int K;
	scanf("%d %d %d", &firstadd, &N, &K);
	B1025Node* nptr = new B1025Node[N];
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d %d", &nptr[i].add, &nptr[i].data, &nptr[i].next);
	}
	int count = 0;
	int ADD = firstadd;
	while (ADD!=-1)
	{
		for (int i = 0; i < N; i++)
		{
			if (nptr[i].add == ADD)
			{
				nptr[i].order = count++;
				ADD = nptr[i].next;
				break;
			}
		}
	}
	sort(nptr, nptr + N, cmpB1025);
	B1025Node* nptr2 = new B1025Node[N];
	int bais = 0;
	int j = 0;
	while (bais + K - 1 < N)
	{
		for (int i = bais + K - 1; i >= bais; i--)
		{
			nptr2[j] = nptr[i];
			j++;
		}
		bais += K;
	}

	for (int i=bais; i < N; i++)
	{
		nptr2[j] = nptr[i];
		j++;
	}

	for (int i = 0; i < N-1; i++)
	{
		nptr2[i].next = nptr2[i+1].add;
	}
	nptr2[N - 1].next = -1;

	for (int i = 0; i < N ; i++)
	{
		if (nptr2[i].next != -1)
			printf("%05d %d %05d\n", nptr2[i].add, nptr2[i].data, nptr2[i].next);
		else
			printf("%05d %d %5d\n", nptr2[i].add, nptr2[i].data, nptr2[i].next);
	}
	delete[] nptr;
	delete[] nptr2;
/*
00100 6 4
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218
*/
}
//A1032 Sharing
void A1032()
{
	typedef struct node {
		int add;
		char data;
		int next;
		int time;
	}Node;
	const int MAXN = 100001;
	Node nodelist[MAXN];
	for (int i = 0; i < MAXN; i++)
		nodelist[i].time = 0;
	int first1, first2, N;
	scanf("%d %d %d", &first1, &first2, &N);
	for (int i = 0; i < N; i++)
	{
		int add, data, next;
		scanf("%d %c %d", &add, &data, &next);
		nodelist[add].add = add;
		nodelist[add].data = data;
		nodelist[add].next = next;
		if (nodelist[add].next != -1)
			nodelist[next].time++;
	}
	bool exit = false;
	int sameADD=-1;
	for (int i = 0; i < MAXN; i++)
	{
		if (nodelist[i].time >= 2)
		{
			exit = true;
			sameADD = nodelist[i].add;
			printf("%05d", sameADD);
			break;
		}
	}
	if (!exit) printf("-1");
/*
11111 22222 9
67890 i 00002
00010 a 12345
00003 g -1
12345 D 67890
00002 n 00003
22222 B 23456
11111 L 00001
23456 e 67890
00001 o 00010
*/
}
//A1052 Linked List Sorting
typedef struct A1052node {
	int add;
	int key;
	int next;
}A1052Node;
bool cmpA1052(A1052Node a, A1052Node b)
{
	return a.key < b.key;
}
void A1052()
{
	int N, firstAdd;
	scanf("%d %d", &N, &firstAdd);
	A1052Node* nptr = new A1052Node[N];
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d %d", &nptr[i].add, &nptr[i].key, &nptr[i].next);
	}
	sort(nptr, nptr + N, cmpA1052);
	for (int i = 0; i < N; i++)
	{
		if (i < N - 1)
			nptr[i].next = nptr[i + 1].add;
		else nptr[i].next = -1;
	}

	printf("\n%d %05d\n", N, nptr[0].add);
	for (int i = 0; i < N; i++)
	{
		if (nptr[i].next != -1)
		{
			printf("%05d %d %05d\n", nptr[i].add, nptr[i].key, nptr[i].next);
		}
		else printf("%05d %d %d", nptr[i].add, nptr[i].key, nptr[i].next);
	}
	delete[] nptr;
/*
5 00001
11111 100 -1
00001 0 22222
33333 100000 11111
12345 -1 33333
22222 1000 12345
*/

}
//A1097 Deduplication on a Linked List
void A1097()
{
	typedef struct node {
		int add;
		int key;
		int next;
		bool exit;
		bool flag;
	}Node;
	const int MAXN = 100001;
	Node nodes[MAXN];
	for (int i = 0; i < MAXN; i++)
		nodes[i].flag = false;
	int firstAdd, N;
	scanf("%d %d", &firstAdd, &N);

	set<int> myset;
	for (int i = 0; i < N; i++)
	{
		int add, key, next;
		scanf("%d %d %d", &add, &key, &next);
		nodes[add].add = add;
		nodes[add].key = key;
		nodes[add].next = next;
		if (myset.count(abs(nodes[add].key)) == 0)
		{
			nodes[add].exit = true;
			myset.insert(abs(nodes[add].key));
		}
		else nodes[add].exit = false;
		nodes[add].flag = true;
	}
	int exitNodesN = myset.size();
	Node* Exitnptr = new  Node[exitNodesN];
	printf("\n");
	int address = firstAdd;
	queue<int> deletedADD;

	int i = 0;
	while (address != -1)
	{
		if (nodes[address].exit)
		{
			Exitnptr[i] = nodes[address];
			i++;
		}
		else
		{
			deletedADD.push(address);
		}
		address = nodes[address].next;
	}
	for (int i = 0; i < exitNodesN; i++)
	{
		if (i < exitNodesN - 1)
			Exitnptr[i].next = Exitnptr[i + 1].add;
		printf("%05d %d", Exitnptr[i].add, Exitnptr[i].key);
		if (Exitnptr[i].next != -1&&i< exitNodesN-1) printf(" %05d\n", Exitnptr[i].next);
		else printf(" -1\n");
	}


	while (!deletedADD.empty())
	{
		int add = deletedADD.front();
		deletedADD.pop();//³ö¶Ó
		printf("%05d %d", nodes[add].add, nodes[add].key);
		if (!deletedADD.empty()) nodes[add].next = nodes[deletedADD.front()].add;
		else nodes[add].next = -1;
		if (nodes[add].next != -1) printf(" %05d\n", nodes[add].next);
		else printf(" -1\n");
	}

	delete[] Exitnptr;
/*
00100 5
99999 -7 87654
23854 -15 00000
87654 15 -1
00000 -15 99999
00100 21 23854
*/
}
