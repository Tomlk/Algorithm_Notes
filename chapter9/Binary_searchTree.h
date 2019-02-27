#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "iostream"
#include "stdio.h"
#include "vector"
#include "algorithm"
#include "queue"
using namespace std;
typedef struct node {
	int data;
	node* left;
	node* right;
	node()
	{
		left = NULL;
		right = NULL;
	}
}Node;
//A1043
void Insert_node(Node* &root, int data)//传的是root的地址
{
	if (root == NULL)
	{
		root = new Node;
		root->data = data;
		return;
	}
	if (data < root->data) Insert_node(root->left, data);
	else Insert_node(root->right, data);

}
vector<int> PreS;
vector<int> MirrorPreS;
void Pre_Travesal(Node* node)
{
	if (node != NULL)
	{
		PreS.push_back(node->data);
		//printf("%d ", node->data);
		Pre_Travesal(node->left);
		Pre_Travesal(node->right);
	}
}
void Mirror_Search(Node* node)
{
	if (node != NULL)
	{
		MirrorPreS.push_back(node->data);
		//printf("%d ", node->data);
		Mirror_Search(node->right);
		Mirror_Search(node->left);
	}
}
void Post_print(Node* node)
{
	if (node != NULL)
	{
		Post_print(node->left);
		Post_print(node->right);
		printf("%d ", node->data);
		
	}
}
void A1043()
{
	int n;
	scanf("%d", &n);
	//Node* pNode = new Node[n];
	Node* root=NULL;
	printf("%x %x\n", root, &root);
	vector<int> Sequence;
	for (int i = 0; i < n; i++)
	{
		int nowdata;
		scanf("%d", &nowdata);
		Sequence.push_back(nowdata);
		printf("%x %x\n", root,&root);

		Insert_node(root, nowdata);	
	}
	Pre_Travesal(root);
	Mirror_Search(root);
	bool flag1 = true;
	for (int i = 0; i < Sequence.size(); i++)
	{
		if (PreS[i] == Sequence[i]) continue;
		else {
			flag1 = false;
			break;
		}
	}
	bool flag2 = true;
	for (int i = 0; i < Sequence.size(); i++)
	{
		if (MirrorPreS[i] == Sequence[i]) continue;
		else {
			flag2 = false;
			break;
		}
	}
	if (flag1 || flag2)
	{
		printf("YES\n");
		Post_print(root);
	}
	else printf("NO");

	

	//delete[] pNode;
/*
7
8 6 5 7 10 8 11

7
8 6 8 5 10 9 11
*/
}

//A1064 Complete Binary Search Tree
int index = 0;
void InOreder(int root, int* cbt, int* number,int n)
{
	if (root > n) return;
	InOreder(2 * root,cbt,number,n);
	cbt[root] = number[index++];
	InOreder(2 * root + 1, cbt, number, n);
}
void A1064()
{
	const int maxn = 100;
	int n;
	scanf("%d", &n);
	int number[maxn] = { 0 };
	int CBT[maxn] = { 0 };
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &number[i]);
	}
	sort(number, number + n);
	InOreder(1,CBT,number,n);
	for (int i = 1; i <= n; i++)
		printf("%d ", CBT[i]);
/*
10
1 2 3 4 5 6 7 8 9 0
*/
}
//A1099 Build a Binary Search Tree
void InOrder(Node* node,int &index,int* Weight)
{
	if (node != NULL)
	{
		InOrder(node->left, index,Weight);
		node->data = Weight[index];
		index++;
		InOrder(node->right, index, Weight);
	}
}
void BFS_s(Node* root)
{
	queue<Node*> Q;
	Q.push(root);
	while (!Q.empty())
	{
		Node* temp = Q.front();
		Q.pop();
		printf("%d ", temp->data);
		if (temp->left != NULL)
			Q.push(temp->left);
		if (temp->right != NULL)
			Q.push(temp->right);
	}
}
void A1099()
{
	int n;
	scanf("%d", &n);
	Node* pNode = new Node[n];
	int* Weight = new int[n];
	bool notroot[100] = { 0 };
	for (int i = 0; i < n; i++)
	{
		int left, right;
		scanf("%d %d", &left, &right);
		if (left != -1)
		{
			pNode[i].left = &pNode[left];
			notroot[left] = true;
		}
		if (right != -1)
		{
			pNode[i].right = &pNode[right];
			notroot[right] = true;
		}
	}
	for (int i = 0; i < n; i++)
		scanf("%d", &Weight[i]);
	int rootIndex = 0;
	for (int i = 0; i < n; i++)
	{
		if (notroot[i] == 0)
		{
			rootIndex = i;
			break;
		}
	}
	sort(Weight, Weight + n);
	int index = 0;
	InOrder(&pNode[rootIndex], index, Weight);
	BFS_s(&pNode[rootIndex]);
	delete[] Weight;
	delete[] pNode;
/*
9
1 6
2 3
-1 -1
-1 4
5 -1
-1 -1
7 -1
-1 8
-1 -1
73 45 11 58 82 25 67 38 42
*/
}