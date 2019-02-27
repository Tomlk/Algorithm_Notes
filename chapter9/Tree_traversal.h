#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "iostream"
#include "vector"
#include "stack"
#include "queue"
#include "algorithm"
using namespace std;
//A1079 Total Sales of Supply Chain
const int maxn = 100010;
double price, r;
typedef struct node {
	int data;
	int depth;
	vector<int> child;
}Node;
void BFS_search(Node* start,Node* pNode)
{
	//int depth = -1;
	double sum = 0;
	queue<Node*> Myqueue;
	Myqueue.push(start);
	while (!Myqueue.empty())
	{
	//	depth++;
		Node* Nnode = Myqueue.front();
		Myqueue.pop();
		if (Nnode->child.empty())// leaf node
		{
		//	printf("%d\t", Nnode->data);
			sum += price* Nnode->data*pow(r + 1, Nnode->depth);
		//	printf("%lf\t", sum);

		}
		else {
			for (int i = 0; i < Nnode->child.size(); i++)
			{
				Myqueue.push(&pNode[Nnode->child[i]]);
			//	printf("%d come in queue\n", Nnode->child[i]);
			}
		}
	}
	printf("%.1lf", sum);


}
void A1079()
{
	int n;
	scanf("%d%lf%lf", &n, &price, &r);
	r /= 100;
	Node* pNode = new Node[n];
	for (int i = 0; i < n; i++)
	{
		int k;
		scanf("%d", &k);
		if (k == 0)
		{
			scanf("%d", &pNode[i].data);
		}
		else {
			for (int j = 0; j < k; j++)
			{
				int child;
				scanf("%d", &child);
				pNode[i].child.push_back(child);
			}
		}
		//scanf("")
	}
	pNode[0].depth = 0;
	for (int i = 0; i < n; i++)
	{
		if (pNode[i].child.empty() == false)
		{
			for (int j = 0; j < pNode[i].child.size(); j++)
			{
				pNode[pNode[i].child[j]].depth = pNode[i].depth + 1;
			//	printf("%d depth is %d\n", pNode[i].child[j], pNode[i].depth + 1);
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (pNode[i].child.empty() == false)
		{
			for (int j = 0; j < pNode[i].child.size(); j++)
			{
				pNode[pNode[i].child[j]].depth = pNode[i].depth + 1;
				//printf("%d depth is %d\n", pNode[i].child[j], pNode[i].depth + 1);
			}
		}
	}
	//for (int i = 0; i < n; i++)
	//{
	//	if(pNode[i].child.empty())
	//	printf(" %d\t%d", pNode[i].data,pNode[i].depth);
	//}


	BFS_search(pNode, pNode);
	delete[] pNode;
/*
10 1.80 1.00
3 2 3 5
1 9
1 4
1 7
0 7
2 6 1
1 8
0 9
0 4
0 3
*/
}
//A1090 Highest Price in Supply Chain
void DFS_search(Node* start,Node* pNode,int n)
{
	double* Pprice = new double[n];
	bool* visited = new bool[n];
	for (int i = 0; i < n; i++)
	{
		visited[i] = false;
		Pprice[i] = 0;
	}
	stack<Node*> Mystack;
	Mystack.push(start);
	while (!Mystack.empty())
	{
		Node* temp = Mystack.top();
		Mystack.pop();
		Pprice[temp->data] = price * pow(1 + r, temp->depth);
		printf("%lf %d %lf\n", price, temp->depth, Pprice[temp->data]);
		visited[temp->data] = true;
		for (int i = 0; i < temp->child.size(); i++)
		{
			if (visited[temp->child[i]] == false)
			{
				Mystack.push(&pNode[temp->child[i]]);
			}
		}
	}
	double max = Pprice[0];
	for (int i = 0; i < n; i++)
	{
		if (Pprice[i] > max)
		{
			max = Pprice[i];
		}
	}
	int time = 0;
	for (int i = 0; i < n; i++)
	{
		if (Pprice[i] == max)
		{
			time++;
		}
	}
	printf("%.2lf %d", max, time);

	delete[] Pprice;
	delete[] visited;
}
void BFS_depth(Node* start,Node* pNode)
{
	queue<Node*> Myqueue;
	start->depth = 0;
	Myqueue.push(start);
	while (!Myqueue.empty())
	{
		Node* temp = Myqueue.front();
		Myqueue.pop();
		for (int i = 0; i < temp->child.size(); i++)
		{

			pNode[temp->child[i]].depth = temp->depth + 1;
			Myqueue.push(&pNode[temp->child[i]]);
		}
	}
}
void A1090()
{
	int n;
	scanf("%d %lf %lf", &n, &price, &r);
	r /= 100;
	Node* pNode = new Node[n];
	Node* root=NULL;
	for (int i = 0; i < n; i++)
	{
		pNode[i].data = i;
		int parent;
		scanf("%d", &parent);
		if (parent >= 0 && parent < n)
		{
			pNode[parent].child.push_back(i);
		}
		else {
			root = &pNode[i];
		}
	}
	BFS_depth(root, pNode);
	DFS_search(root, pNode, n);
	delete[] pNode;
/*
9 1.80 1.00
1 5 4 4 -1 4 5 3 6
*/
}
//A1094 The Largest Generation

void BFSA1094(Node* root,Node* pNode)
{
	queue<Node*> MyQ;
	root->depth = 1;
	MyQ.push(root);
	int depthNumber[100] = {0};
	//depthNumber[root->depth]++;
	while (!MyQ.empty())
	{
		Node* temp = MyQ.front();
	//	printf("%d", temp->depth);
		depthNumber[temp->depth]++;
		MyQ.pop();
		for (int i = 0; i < temp->child.size(); i++)
		{
			pNode[temp->child[i]].depth = temp->depth + 1;
			MyQ.push(&pNode[temp->child[i]]);
		}
	}

	//for (int i = 1; i < 30; i++)
	//	printf("%d ", depthNumber[i]);
	int maxN = 0;
	int depth = 1;
	for (int i = 1; i < 100; i++)
	{
		if (depthNumber[i] > maxN)
		{
			maxN = depthNumber[i];
			depth = i;
		}
	}
	printf("%d %d", maxN, depth);
	
}
void A1094()
{
	int n;
	int m;
	scanf("%d %d", &n, &m);
	Node* pNode = new Node[n + 1];//用第1到第n个
	bool* Isroot = new bool[n + 1];
	for (int i = 1; i < n + 1; i++)
		Isroot[i] = true;
	for (int i = 0; i < m; i++)
	{
		int index, childn;
		scanf("%d %d", &index, &childn);
		for (int j = 0; j < childn; j++)
		{
			int child;
			scanf("%d", &child);
			Isroot[child] = false;
			pNode[index].child.push_back(child);
		}
	}
	Node* root = NULL;
	for (int i = 1; i < n + 1; i++)
	{
		if (Isroot[i] == true)
		{
			printf("root:%d\n", i);
			root = &pNode[i];
			break;
		}
	}
	BFSA1094(root, pNode);
	delete[] Isroot;
	delete[] pNode;
/*
23 13
21 1 23
01 4 03 02 04 05
03 3 06 07 08
06 2 12 13
13 1 21
08 2 15 16
02 2 09 10
11 2 19 20
17 1 22
05 1 11
07 1 14
09 1 17
10 1 18
*/

}
//A1106 Lowest Price in Supply Chain

void DFS_searchA1106(Node* start, Node* pNode, int n)
{
	double* Pprice = new double[n];
	bool* visited = new bool[n];
	for (int i = 0; i < n; i++)
	{
		visited[i] = false;
		Pprice[i] = 0;
	}
	stack<Node*> Mystack;
	Mystack.push(start);
	while (!Mystack.empty())
	{
		Node* temp = Mystack.top();
		Mystack.pop();
		Pprice[temp->data] = price * pow(1 + r, temp->depth);
		printf("%lf %d %lf\n", price, temp->depth, Pprice[temp->data]);
		visited[temp->data] = true;
		for (int i = 0; i < temp->child.size(); i++)
		{
			if (visited[temp->child[i]] == false)
			{
				Mystack.push(&pNode[temp->child[i]]);
			}
		}
	}
	double min;
	for (int i = 0; i < n; i++)
	{
		if (pNode[i].child.empty())
		{
			min = Pprice[i];
			break;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (Pprice[i] < min&&pNode[i].child.empty())
		{
			min = Pprice[i];
		}
	}
	int time = 0;
	for (int i = 0; i < n; i++)
	{
		if (Pprice[i] == min && pNode[i].child.empty())
		{
			time++;
		}
	}
	printf("%.4lf %d", min, time);

	delete[] Pprice;
	delete[] visited;
}
void A1106()
{
	int n;
	scanf("%d %lf %lf", &n, &price, &r);
	r /= 100;
	Node* pNode = new Node[n];
	bool* isRoot = new bool[n];
	for (int i = 0; i < n; i++)
		isRoot[i] = true;
	for (int i = 0; i < n; i++)
	{
		pNode[i].data = i;
		int childn;
		scanf("%d", &childn);
		if (childn == 0) continue;
		for (int j = 0; j < childn; j++)
		{
			int child;
			scanf("%d", &child);
			isRoot[child] = false;
			pNode[i].child.push_back(child);
		}
	}
	Node* root = NULL;
	for (int i = 0; i < n; i++)
	{
		if (isRoot[i] == true)
		{
			root = &pNode[i];
			break;
		}
	}
	BFS_depth(root, pNode);
	for (int i = 0; i < n; i++)
		printf("%d ", pNode[i].depth);
	DFS_searchA1106(root, pNode, n);
	delete[] pNode;
	delete[] isRoot;
/*
10 1.80 1.00
3 2 3 5
1 9
1 4
1 7
0 
2 6 1
1 8
0 
0 
0 
*/
}
//A1004 Counting Leaves

void BFSA1004(Node* root, Node* pNode)
{
	queue<Node*> MyQ;
	root->depth = 1;
	MyQ.push(root);
	int depthNumber[100] = { 0 };
	int deepestD = 0;
	while (!MyQ.empty())
	{
		Node* temp = MyQ.front();
		//	printf("%d", temp->depth);
		if(temp->child.empty())
			depthNumber[temp->depth]++;
		MyQ.pop();
		for (int i = 0; i < temp->child.size(); i++)
		{
			pNode[temp->child[i]].depth = temp->depth + 1;
			if (pNode[temp->child[i]].depth > deepestD) deepestD = pNode[temp->child[i]].depth;
			MyQ.push(&pNode[temp->child[i]]);
		}
	}

	for (int i = 1; i <=deepestD; i++)
		printf("%d ", depthNumber[i]);
	//int maxN = 0;
	//int depth = 1;
	//for (int i = 1; i < 100; i++)
	//{
	//	if (depthNumber[i] > maxN)
	//	{
	//		maxN = depthNumber[i];
	//		depth = i;
	//	}
	//}
	//printf("%d %d", maxN, depth);

}
void A1004()
{
	int n, m;
	scanf("%d %d", &n, &m);
	Node* pNode = new Node[n+1];
	bool* isRoot = new bool[n+1];
	for (int i = 1; i < n + 1; i++)
		isRoot[i] = true;
	for (int i = 0; i < m; i++)
	{
		int index,childn;
		scanf("%d %d", &index,&childn);
		pNode[index].data = index;
		for (int j = 0; j < childn; j++)
		{
			int child;
			scanf("%d", &child);
			isRoot[child] = false;
			pNode[index].child.push_back(child);
		}
		//scanf("%d", &pNode[i].data);
	}
	Node* root = NULL;
	for (int i = 1; i < n+1; i++)
	{
		if (isRoot[i] == true)
		{
			root = &pNode[i];
			break;
		}	
	}
	BFSA1004(root, pNode);
	delete[] pNode;
/*
2 1
01 1 02
*/
/*
10 6
1 3 3 4 6
2 1 10
3 1 5
4 1 8
6 2 7 2
7 1 9
*/
}
//A1053 Path of Equal Weight
typedef struct wNode {
	int index;
	int depth;
	int weight;
	vector<wNode*> child;
}WNode;
void DFSA1053(WNode* root, int X,int n)
{
	vector<int> Path;
	stack<WNode*> Mystack;
	bool* visited = new bool[n];
	for (int i = 0; i < n; i++)
		visited[i] = false;
	root->depth = 1;
	Mystack.push(root);
	while (!Mystack.empty())
	{
		WNode* temp = Mystack.top();
		Mystack.pop();
		//printf("%d ", temp->index);
		visited[temp->index] = true;
		while (Path.size() != temp->depth - 1)
			Path.pop_back();
		Path.push_back(temp->weight);

		int sum = 0;
		for (int i = 0; i < Path.size(); i++)
			sum += Path[i];
		//printf(":%d ", sum);
		if (sum > X) {
			//Path.pop_back();
			continue;
		}
		else if (sum == X&&temp->child.empty())
		{
			for (int i = 0; i < Path.size(); i++)
				printf("%d ", Path[i]);
			printf("\n");
			//Path.pop_back();
			continue;
		}
		else {
			//children come in
			for (int i = 0; i < temp->child.size(); i++)
			{
				if (!visited[temp->child[i]->index])
				{
					temp->child[i]->depth = temp->depth + 1;
					Mystack.push(temp->child[i]);
				}
			}
		}

	}
	delete[] visited;

}
bool cmpA1053(WNode*a, WNode*b)
{
	return a->weight <b->weight;
}
void A1053()
{
	int n, no_leafn, WEIGHT;
	scanf("%d %d %d", &n, &no_leafn, &WEIGHT);
	WNode* pWnode = new WNode[n];
	bool* isRoot = new bool[n];
	for (int i = 0; i < n ; i++)
		isRoot[i] = true;
	for (int i = 0; i < n; i++)
	{
		int w;
		scanf("%d", &w);
		pWnode[i].index = i;
		pWnode[i].weight = w;
	}
	for(int i=0;i<no_leafn;i++)
	{ 
		int childn, index;
		scanf("%d %d", &index, &childn);
		for (int j = 0; j < childn; j++)
		{
			int child;
			scanf("%d", &child);
			pWnode[index].child.push_back(&pWnode[child]);
			isRoot[child] = false;
		}
		sort(pWnode[i].child.begin(), pWnode[i].child.end(), cmpA1053);
	}

	WNode* root = NULL;
	for (int i= 0; i < n ; i++)
	{
		if (isRoot[i] == true)
		{
			root = &pWnode[i];
			break;
		}
	}
	DFSA1053(root, WEIGHT, n);
	delete[] pWnode;
/*
20 9 24
10 2 4 3 5 10 2 18 9 7 2 2 1 3 12 1 8 6 2 2
00 4 01 02 03 04
02 1 05
04 2 06 07
03 3 11 12 13
06 1 09
07 2 08 10
16 1 15
13 3 14 16 17
17 2 18 19
*/
}