#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "iostream"
#include "stdio.h"
#include "algorithm"
#include "queue"
#include "math.h"
using namespace std;
//A1091 Acute Stroke
typedef struct node {
	int x, y, z;
}Node;
Node mynode;
int N;
int m, slice, T;
int pixel[1290][130][61];
bool inq[1290][130][61] = { false };
int X[6] = { 0,0,0,0,1,-1 };
int Y[6] = { 0,0,1,-1,0,0 };
int Z[6] = { 1,-1,0,0,0,0 };
bool judege(int x, int y, int z)
{
	if (x >= N || x < 0 || y >= m || y < 0 || z >= slice || z < 0) return false;
	if (pixel[x][y][z] == 0 || inq[x][y][z] == true) return false;
	return true;
}
int BFS(int x, int y, int z)
{
	int tot = 0;
	queue<Node> Q;
	mynode.x = x, mynode.y = y, mynode.z = z;
	Q.push(mynode);
	inq[x][y][z] = true;
	while (!Q.empty())
	{
		Node top = Q.front();
		Q.pop();
		tot++;
		for (int i = 0; i < 6; i++)
		{
			int newX = top.x + X[i];
			int newY = top.y + Y[i];
			int newZ = top.z + Z[i];
			if (judege(newX, newY, newZ))
			{
				mynode.x = newX, mynode.y = newY, mynode.z = newZ;
				Q.push(mynode);
				inq[newX][newY][newZ] = true;
			}
		}
	}
	if (tot >= T) return tot;
	else return 0;
}
void A1091()
{
	scanf("%d %d %d %d", &N, &m, &slice, &T);
	for(int z=0;z<slice;z++)
		for(int x=0;x< N;x++)
			for (int y = 0; y < m; y++)
			{
				scanf("%d", &pixel[x][y][z]);
			}
	int ans = 0;
	for (int z = 0; z < slice; z++)
	{
		for (int x = 0; x < N; x++)
		{
			for (int y = 0; y < m; y++)
			{
				if (pixel[x][y][z] == 1 && inq[x][y][z] == false)
					ans+=BFS(x, y, z);
			}
		}
	}
	printf("%d\n", ans);
/*
3 4 5 2
1 1 1 1 
1 1 1 1
1 1 1 1
0 0 1 1 
0 0 1 1
0 0 1 1
1 0 1 1
0 1 0 0
0 0 0 0
1 0 1 1
0 0 0 0
0 0 0 0
0 0 0 1
0 0 0 1
1 0 0 0
*/
}