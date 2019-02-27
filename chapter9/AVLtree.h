#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "iostream"
#include "stdio.h"
#include "algorithm"
using namespace std;
//A1066 Root of AVL Tree
typedef struct node {
	int data, height;
	node* lchild;
	node* rchild;
	node()
	{
		lchild = NULL;
		rchild = NULL;
	}
}Node;
Node* newNode(int data)
{
	Node* nnode = new Node;
	nnode->data = data;
	nnode->height = 1;
	return nnode;
}
int getHeight(Node* root)
{
	if (root == NULL) return 0;
	return root->height;
}
void updataHeight(Node* root)
{
	root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
}
//calculate the balance factor
int getBalanceFactor(Node* root)
{
	return getHeight(root->lchild) - getHeight(root->rchild);
}
//left rotate
void L(Node* &root)
{
	Node* temp = root->rchild;
	root->rchild = temp->lchild;
	temp->lchild = root;
	updataHeight(root);
	updataHeight(temp);
	root = temp;
}
//right rotate
void R(Node* &root)
{
	Node* temp = root->lchild;
	root->lchild = temp->rchild;
	temp->rchild = root;
	updataHeight(root);
	updataHeight(temp);
	root = temp;
}
void inSert(Node* &root, int data)
{
	if (root == NULL)
	{
		root = newNode(data);
		return;
	}
	if (data < root->data)
	{
		inSert(root->lchild, data);
		updataHeight(root);
		if (getBalanceFactor(root) == 2)
		{
			if (getBalanceFactor(root->lchild)== 1)//LLÐÍ
			{
				R(root);
			}
			else if (getBalanceFactor(root->lchild) == -1)//LRÐÍ
			{
				L(root->lchild);
				R(root);
			}
		}
	}
	else {
		inSert(root->rchild, data);
		updataHeight(root);
		if (getBalanceFactor(root) == -2)
		{
			if (getBalanceFactor(root->rchild) == -1)//RR
			{
				L(root);
			}
			else if (getBalanceFactor(root->rchild) == 1)
			{
				R(root->rchild);
				L(root);
			}

		}

	}
}
Node* create(int* data, int n)
{
	Node* root = NULL;
	for (int i = 0; i < n; i++)
	{
		inSert(root, data[i]);
	}
	return root;
}
void A1066()
{
	int n, data;
	Node* root = NULL;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &data);
		inSert(root, data);
	}
	printf("%d\n", root->data);
/*
5
88 70 61 96 120

7 
88 70 61 96 120 90 65
*/
}