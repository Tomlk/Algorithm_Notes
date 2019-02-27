#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "iostream"
#include "algorithm"
#include "stdio.h"
#include "queue"
#include "stack"
#include "algorithm"
using namespace std;
typedef struct node{
	int data;
	node* lchild;
	node* rchild;
}Node;
const int maxn = 50;
int pre[maxn], in[maxn], post[maxn];
int n;
Node* create(int postL, int postR, int inL, int inR)
{
	if (postL > postR) return NULL;
	Node* root = new Node;
	root->data = post[postR];
	int k;
	for (k = inL; k <= inR; k++)
	{
		if (in[k] == post[postR])
			break;
	}
	int numLeft = k - inL;
	root->lchild = create(postL, postL + numLeft - 1, inL, k - 1);
	root->rchild = create(postL + numLeft, postR - 1, k + 1, inR);
	return root;
}
int num = 0;
void BFS(Node* root)
{
	queue<Node*> q;
	q.push(root);
	while (!q.empty())
	{
		Node* now = q.front();
		q.pop();
		printf("%d", now->data);
		num++;
		if (num < n) printf(" ");
		if (now->lchild != NULL) q.push(now->lchild);
		if (now->rchild != NULL) q.push(now->rchild);
	}
}
void BFS2(Node* root)
{
	queue<Node*> q;
	q.push(root);
	while (!q.empty())
	{
		Node* now = q.front();
		q.pop();
		printf("%d ", now->data);
		num++;
		if (num < n) printf(" ");
		if (now->rchild != NULL) q.push(now->rchild);
		if (now->lchild != NULL) q.push(now->lchild);
	}
}
void Xigou(Node* pnode)
{
	if (pnode->lchild != NULL || pnode->rchild != NULL)
	{
		if (pnode->lchild != NULL) Xigou(pnode->lchild);
		if (pnode->rchild != NULL) Xigou(pnode->rchild);
	}
	delete pnode;
	pnode = NULL;
}
void A1020()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &post[i]);
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &in[i]);
	}
	Node* node = create(0, n - 1, 0, n - 1);
	BFS(node);
	Xigou(node);
	//delete 

/*
7
2 3 1 5 7 6 4
1 2 3 4 5 6 7
*/
}
//A1086 Tree Traversals Again

int pre1[maxn];
int in1[maxn];
Node* createby_inpre(int prel, int prer, int inl, int inr)
{
	if (prel > prer) return NULL;
	Node* root = new Node;
	root->data = pre1[prel];
	int k;
	for (k = inl; k <= inr; k++)
	{
		if (in1[k] == pre1[prel])
			break;
	}
	root->lchild = createby_inpre(prel + 1, prel + k - inl, inl, k - 1);
	root->rchild = createby_inpre(prel + k - inl + 1, prer, k + 1, inr);
	return root;
}
void PostSearch(Node* nptr)
{
	if (nptr != NULL)
	{
			PostSearch(nptr->lchild);
			PostSearch(nptr->rchild);
		printf("%d ", nptr->data);
	}
}
void A1086()
{
	int n;
	scanf("%d", &n);
	//int pushn = 0, popn = 0;
	char actionS[10];
	int number;
	int i = 0, j = 0;
	stack<int> mystack;
	while (!(i == n && j == n))
	{
		scanf("%s",actionS);
		if (strcmp(actionS, "Push") == 0)
		{
			scanf("%d", &number);
			mystack.push(number);
			pre1[i] = number;
			i++;
		}
		else if (strcmp(actionS, "Pop") == 0)
		{
			int temp = mystack.top();
			mystack.pop();
			in1[j] = temp;
			j++;
		}
	}
	for (int i = 0; i < n; i++)
		printf("%d ", pre1[i]);
	printf("\n");
	for (int i = 0; i < n; i++)
		printf("%d ", in1[i]);
	printf("\n");
	Node* root = createby_inpre(0, n - 1,0, n - 1);
	//printf("%d", root->data);
	PostSearch(root);
	Xigou(root);
/*
6
Push 1
Push 2
Push 3
Pop
Pop
Push 4
Pop
Pop
Push 5
Push 6
Pop
Pop

*/
}

//A1102 Invert a Binary Tree
void RIL_print(Node* node)
{
	if (node != NULL)
	{
		RIL_print(node->rchild);
		printf("%d ", node->data);
		RIL_print(node->lchild);
	}
}
void A1102()
{
	int n;
	scanf("%d", &n);
	Node* pnode = new Node[n];
	//char cL[100];
	//char cR[100];
	bool isRoot[100];
	for (int i = 0; i < n; i++)
		isRoot[i] = true;
	for (int i = 0; i < n; i++)
	{
		char l, r;
		scanf("%*c%c %c", &l, &r); //»òÕßÓÃgetchar
		if (l == '-') pnode[i].lchild = NULL;
		else {
			int index = l - '0';
			isRoot[index] = false;
			pnode[i].lchild = &pnode[index];
		}
		if (r == '-') pnode[i].rchild = NULL;
		else {
			int index = r - '0';
			isRoot[index] = false;
			pnode[i].rchild = &pnode[index];
		}
		pnode[i].data = i;
	}
	//search root
	Node* root = NULL;
	for (int i = 0; i < n; i++)
	{
		if (isRoot[i] == true) {
			root = &pnode[i];
		}
	}
	//for (int i = 0; i < n; i++)
	//{
	//	printf("%d\t", pnode[i].data);
	//}
	BFS2(root);
	printf("\n");
	RIL_print(root);
	delete[] pnode;
/*
8
1 -
- -
0 -
2 7
- -
- -
5 -
4 6
*/
}
