#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "iostream"
#include "stdio.h"
#include "vector"
#include "queue"
#include "string"
#include "map"
using namespace std;
//A1013 Battle over cities
const int N = 111;
vector<int> G[N];
bool visited[N];
int currentedPoint;
void DFS(int v)
{
	if (v == currentedPoint) return;
	visited[v] = true;
	for (int i = 0; i < G[v].size(); i++)
	{
		if (visited[G[v][i]] == false)
		{
			DFS(G[v][i]);
		}
	}

}
void A1013()
{
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		G[a].push_back(b);
		G[b].push_back(a);
	}
	for (int query = 0; query < k; query++)
	{
		scanf("%d", &currentedPoint);
		memset(visited, false, sizeof(visited));//对每一个visited数组元素赋值为false
		int block = 0;
		for (int i = 1; i <= n; i++)
		{
			if (i != currentedPoint && visited[i] == false)
			{
				DFS(i);
				block++;
			}
		}
		printf("%d\n", block - 1);
	}
/*
3 2 3
1 2
1 3 
1 2 3
*/
}
//A1021 Deepest Root
typedef struct node {
	int data;
	vector<node*> link;
}Node;
void BfsA1021(Node* start,Node* pnode,int n)
{
	//traversal 观察是否连通
	bool* visited = new bool[n+1];
	int componentN = 0;
	memset(visited, false, sizeof(visited));
	queue<Node*> Q;

	bool connected = false;
	while (!connected)
	{
		Q.push(start);
		while (!Q.empty())
		{
			Node* temp = Q.front();
			Q.pop();
			visited[temp->data] = true;
			for (int i = 0; i < temp->link.size(); i++)
			{
				if (visited[temp->link[i]->data] == false)
				{
					Q.push(temp->link[i]);
				}
			}
		}
			 connected = true;
		for (int i = 1; i <= n; i++)
			if (visited[i] == false)
			{
				connected = false;
				start = &pnode[i];
				break;
			}
		componentN++;
	}

	if (componentN == 1)
	{
		//memset(visited, false, sizeof(visited));
		for (int i = 1; i <= n; i++)
			visited[i] = false;
		int* depth1 = new int[n + 1];
		int* depth2 = new int[n + 1];
		queue<Node*> Q1;
		Q1.push(start);
		int Nowdepth = 1;
		depth1[start->data] = Nowdepth;
		while (!Q1.empty())
		{
			Node* temp = Q1.front();
			Q1.pop();
			visited[temp->data] = true;
			if (temp->link.size() != 0)
			{
				//printf("%d link size is :%d\n", temp->data, temp->link.size());
				Nowdepth++;
			}
			for (int i = 0; i < temp->link.size(); i++)
			{
				if (visited[temp->link[i]->data] == false)
				{
					depth1[temp->link[i]->data] = Nowdepth;
					//printf("%d nowdepth:%d\n", temp->link[i]->data, Nowdepth);
					Q1.push(temp->link[i]);
				}
			}
		}
		int max1 = depth1[1];
		int maxindex = 1;
		for (int i = 1; i <= n; i++)
		{
			if (depth1[i] > max1)
			{
				max1 = depth1[i];
				maxindex = i;
			}
		}		
		start = &pnode[maxindex];
		for (int i = 1; i <= n; i++)
			visited[i] = false;
		Q1.push(start);
		 Nowdepth = 1;
		depth2[start->data] = Nowdepth;
		while (!Q1.empty())
		{
			Node* temp = Q1.front();
			Q1.pop();
			visited[temp->data] = true;
			if (temp->link.size() != 0)
			{
			//	printf("%d link size is :%d\n", temp->data, temp->link.size());
				Nowdepth++;
			}
			for (int i = 0; i < temp->link.size(); i++)
			{
				if (visited[temp->link[i]->data] == false)
				{
					depth2[temp->link[i]->data] = Nowdepth;
				//	printf("%d nowdepth:%d\n", temp->link[i]->data, Nowdepth);
					Q1.push(temp->link[i]);
				}
			}
		}
		int max2 = depth2[1];
		maxindex = 1;
		for (int i = 1; i <= n; i++)
		{
			if (depth2[i] > max2)
			{
				max2 = depth2[i];
				maxindex = i;
			}
		}
		for (int i = 1; i <= n; i++)
		{
			if (depth1[i] == max1 || depth2[i] == max2)
			{
				printf("%d\n", i);
			}
		}
		//for (int i = 1; i <= n; i++)
		//	printf("%d ", depth1[i]);
		//printf("\n");
		//for (int i = 1; i <= n; i++)
		//	printf("%d ", depth2[i]);
		delete[] depth1;
		delete[] depth2;
	}
	else {
		printf("Error:%dcomponents", componentN);
	}
	delete[] visited;


}
void A1021()
{
	int n;
	scanf("%d", &n);
	int a, b;
	Node* pNode = new Node[n+1];
	for (int i = 0; i < n - 1; i++)
	{
		scanf("%d%d", &a, &b);
		pNode[a].data = a;
		pNode[b].data = b;
		pNode[a].link.push_back(&pNode[b]);
		pNode[b].link.push_back(&pNode[a]);

	}
	BfsA1021(&pNode[1], pNode, n);

	delete[] pNode;
/*
5
1 2 
1 3
1 4
2 5

5
1 3 
1 4
2 5
3 4

*/
}
//A1034 Head of a Gang
map<int, string> intToString;//ID->name
map<string, int> stringToInt;//name->ID
map<string, int> Gang; //head->numbers
const int maxN = 2010;
int G2[maxN][maxN] = { 0 }, weight[maxN] = { 0 };
int n, k, numPerson = 0;
bool vis[maxN] = { false };
void DFs(int nowVisit, int& head, int& numMember, int& totalValue)
{
	numMember++;
	vis[nowVisit] = true;
	if (weight[nowVisit] > weight[head])
	{
		head = nowVisit;
	}
	for (int i = 0; i < numPerson; i++)
	{
		if (G2[nowVisit][i] > 0)
		{
			totalValue += G2[nowVisit][i];
			G2[nowVisit][i] = G2[i][nowVisit] = 0;
			if (vis[i] == false)
			{
				DFs(i, head, numMember, totalValue);
			}
		}
	}
}
void DFSTravesal()
{
	for (int i = 0; i < numPerson; i++)
	{
		if (vis[i] == false)
		{
		//	printf("come\n");
			int head = i, numMember = 0, totalValue = 0;
			DFs(i, head, numMember, totalValue);
			//printf("numMember::%d", numMember);
			if (numMember > 2 && totalValue > k)
			{
				Gang[intToString[head]] = numMember;
			//	printf("%d\n", Gang.size());
			}
		}
	}
}
int change(string str)
{
	if (stringToInt.find(str) != stringToInt.end())
	{
		return stringToInt[str];
	}
	else {
		stringToInt[str] = numPerson;
		intToString[numPerson] = str;
		return numPerson++;
	}
}
void A1034()
{
	int w;
	string str1, str2;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
	{
		cin >> str1 >> str2 >> w;
		int id1 = change(str1);
		int id2 = change(str2);
		weight[id1] += w;
		weight[id2] += w;
		G2[id1][id2] += w;
		G2[id2][id1] += w;
	}
	DFSTravesal();
	printf("%d\n", Gang.size());
	map<string, int>::iterator it;
	//迭代器输出map
	for (it = Gang.begin(); it != Gang.end(); it++)
	{
		cout << it->first << " " << it->second << endl;
	}
/*
8 59
AAA BBB 10
BBB AAA 20
AAA CCC 40
DDD EEE 5
EEE DDD 70
FFF GGG 30
GGG HHH 20
HHH FFF 10

8 70
AAA BBB 10
BBB AAA 20
AAA CCC 40
DDD EEE 5
EEE DDD 70
FFF GGG 30
GGG HHH 20
HHH FFF 10
*/
}

//A1076 Forwards on Weibo
int G3[maxN][maxN];
void BFSA1076(int n,int start,int k)
{
	printf("%d:\n", start);
	bool Cangets[maxN];
	bool visited[maxN];
	for (int i = 1; i <= n; i++)
	{
		Cangets[i] = false;
		visited[i] = false;

	}queue<int> myQueue;
	int level = 0;
	myQueue.push(start);
	while (!myQueue.empty())
	{
		int temp = myQueue.front();
		myQueue.pop();
		visited[temp] = true;
		bool flag = false;
		for (int i = 1; i <= n; i++)
		{
			//printf("G3[%d][%d]is %d ;", temp, i, G3[temp][i]);
			//printf("visited[%d] is %d \n", i, visited[i]);
			if (G3[temp][i] == 1&&visited[i]==false&&Cangets[i]==false)
			{
				flag = true;
				myQueue.push(i);
				Cangets[i] = true;
				//printf("%d can get to\n", i);
			}
		}
		if (flag)
			level++;
		if (level >= k)
			break;
	}
	int getNum = 0;
	for (int i = 1; i <= n; i++)
	{
		if (Cangets[i] == true)
			getNum++;
	}
	printf("%d\n", getNum);
}
void A1076()
{
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++)
	{
		int ReachN;
		int To;
		scanf("%d", &ReachN);
		for (int j = 0; j < ReachN; j++)
		{
			scanf("%d", &To);
			G3[To][i] = 1;
		}
	}
	int kcn;
	vector<int> vec;
	scanf("%d", &kcn);
	for (int i = 0; i < kcn; i++)
	{
		int temp;
		scanf("%d", &temp);
		vec.push_back(temp);
	}
	//printf("%d\n", vec.size());
	for (int i = 0; i < vec.size(); i++)
	{
		int start = vec[i];
		BFSA1076(n, start, k);
	}
/*
7 3
3 2 3 4
0
2 5 6 
2 3 1 
2 3 4
1 4
1 5
2 2 6
*/
}
