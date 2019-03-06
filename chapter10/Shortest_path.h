#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "iostream"
#include "stdio.h"
#include "vector"
#include "math.h"
#include "stack"
#include "string"
#include "algorithm"
#include "map"
using namespace std;
//A1003 Emergency
typedef struct city {
	int number;
	int teamN;

}City;
const int maxn = 100;
const int INF = 100000000;
int G[maxn][maxn];
int w[maxn];
int set[maxn], path[maxn], dist[maxn];
int num[maxn]; //路径条数
void Dijkstra(int s, City* pc,int n)
{
	fill(dist, dist + maxn, INF);
	memset(num, 0, sizeof(w));
	dist[s] = 0;
	w[s] = pc[s].teamN;
	num[s] = 1;
	for (int i = 0; i < n; i++)
	{
		int u = -1, min = INF;
		for (int j = 0; j < n; j++)
		{
			if (set[j] == 0 && dist[j] < min)
			{
				u = j;
				min = dist[j];
			}
		}
		if (u == -1)//i 与剩下的V均不连通
			return;
		set[u] = 1;
		for (int j = 0; j < n; j++)
		{
			if (set[j] == 0 && G[u][j]!= INF)
			{
				if (dist[u] + G[u][j] < dist[j])
				{
					dist[j] = dist[u] + G[u][j];
					w[j] = w[u] + pc[j].teamN;
					num[j] = num[u];
				}
				//找到相同长度的路径
				else if (dist[u] + G[u][j] == dist[j])
				{
					if (w[u] + pc[j].teamN > w[j])
					{
						w[j] = w[u] + pc[j].teamN;
					}

					num[j] += num[u];
				}
			}
		}
	}
}
void A1003()
{
	int n, m;
	int c1, c2;
	scanf("%d %d %d %d", &n, &m, &c1, &c2);
	City* pcity = new City[n];
	for (int i = 0; i < n; i++)
	{
		pcity[i].number = i;
		int cityn;
		scanf("%d", &cityn);
		pcity[i].teamN = cityn;
	}
	for(int i=0;i<maxn;i++)
		for (int j = 0; j < maxn; j++)
		{
			G[i][j] = INF;
		}
	for (int i = 0; i < m; i++)
	{
		int a, b, W;
		scanf("%d%d%d", &a, &b, &W);
		G[a][b] = W;
	}
	Dijkstra(c1, pcity, n);
	printf("%d %d", num[c2], w[c2]);
	delete[] pcity;
/*
5 6 0 2
1 2 1 5 3
0 1 1
0 2 2
0 3 1
1 2 1
2 4 1
3 4 1


*/
}
//A1018 Public Bike Management
int Stationbikes[maxn];
int G1[maxn][maxn];
int set1[maxn], dist1[maxn];
vector<int> pre[maxn];
vector<int> tempPath, path1;
int minNeed = INF, minRemain = INF;
int w1[maxn];
void DijkstraA1018(int s,int n)
{
	fill(dist1, dist1 + maxn, INF);
	dist1[s] = 0;
	for (int i = 0; i <= n; i++)
	{
		int u = -1, min = INF;
		for (int j = 0; j <= n; j++)
		{
			if (set1[j] == 0 && dist1[j] < min)
			{
				u = j;
				min = dist1[j];
			}
		}
		if (u == -1) return;
		set1[u] = 1;
		for (int j = 0; j <= n; j++)
		{
			if (set1[j] == 0 && G1[u][j] != INF)
			{
				if (dist1[u] + G1[u][j] < dist1[j])
				{
					dist1[j] = dist1[u] + G1[u][j];
					pre[j].clear();
					pre[j].push_back(u);
				}
				else if (dist1[u] + G1[u][j] == dist1[j])
				{
					pre[j].push_back(u);
				}
			}
		}
	}


}
void DFSA1018(int v)
{
	if (v == 0)
	{
		tempPath.push_back(v);
		int need = 0, remain = 0;
		for (int i = tempPath.size() - 1; i >= 0; i--)
		{
			int id = tempPath[i];
			if (Stationbikes[id] > 0)
				remain += Stationbikes[id];
			else {
				if (remain > abs(Stationbikes[id]))
					remain -= abs(Stationbikes[id]);
				else {
					need += abs(Stationbikes[id]) - remain;
					remain = 0;
				}
			}
		}
		if (need < minNeed)
		{
			minNeed = need;
			minRemain = remain;
			path1 = tempPath;
		}
		else if (need == minNeed && remain < minRemain)
		{
			minRemain = remain;
			path1 = tempPath;
		}
		tempPath.pop_back();
		return;

	}

	tempPath.push_back(v);
	for (int i = 0; i < pre[v].size(); i++)
	{
		DFSA1018(pre[v][i]);
	}
	tempPath.pop_back();
}
void A1018()
{
	int Cmax, StationN, ProblemI, M;
	scanf("%d%d%d%d", &Cmax, &StationN, &ProblemI, &M);
	for (int i = 1; i <=StationN; i++)
	{
		int n;
		scanf("%d", &n);
		Stationbikes[i] = n;
		Stationbikes[i] -= Cmax / 2;
	}
	for (int i = 0; i < maxn; i++)
		for (int j = 0; j < maxn; j++)
		{
			G1[i][j] = INF;
		}

	for(int i=0;i<M;i++)
	{
		int a, b, W;
		scanf("%d%d%d", &a, &b, &W);
		G1[a][b] = W;
		G1[b][a]=W;
	}
	//int start = ProblemI;
	DijkstraA1018(0, StationN);
	DFSA1018(ProblemI);
	printf("%d ", minNeed);
	for (int i = path1.size() - 1; i >= 0; i--)
	{
		printf("%d", path1[i]);
		if (i > 0) printf("->");
	}
	printf(" %d",minRemain);
/*
10 3 3 5
6 7 0
0 1 1
0 2 1
0 3 3
1 3 1
2 3 1
*/
}
//A1030
int G2[maxn][maxn];
int pre2[maxn];
int Cost[maxn][maxn];
int set2[maxn], dist2[maxn], co2[maxn];
void DijkstraA1030(int s,int n)
{
	fill(dist2, dist2 + maxn, INF);
	fill(co2, co2 + maxn, INF);
	for (int i = 0; i < n; i++) pre2[i] = i;
	dist2[s] = 0;
	co2[s] = 0;
	for (int i = 0; i < n; i++)
	{
		int u = -1, min = INF;
		for (int j = 0; j < n; j++)
		{
			if (set2[j] == 0 && dist2[j] < min)
			{
				u = j;
				min = dist2[j];
			}
		}
		if (u == -1) return;
		set2[u] = 1;
		for (int j = 0; j < n; j++)
		{
			if (set2[j] == 0 && G2[u][j] != INF)
			{
				if (G2[u][j] + dist2[u] < dist2[j])
				{
					dist2[j] = G2[u][j] + dist2[u];
					co2[j] = co2[u] + Cost[u][j];
					pre2[j] = u;
				}
				else if (G2[u][j] + dist2[u] == dist2[j])
				{
					if (Cost[u][j] + co2[u] < co2[j])
					{
						co2[j] = Cost[u][j] + co2[u];
						pre2[j] = u;

					}
				}
			}
		}
	}
}
void A1030()
{
	int Vn, En, s, e;
	scanf("%d%d%d%d", &Vn, &En, &s, &e);
	int a, b, DISTANCE, COST;
	for(int i=0;i<maxn;i++)
		for (int j = 0; j < maxn; j++)
		{
			G2[i][j] = INF;
			Cost[i][j] = INF;
		}
	for (int i = 0; i < En; i++)
	{
		scanf("%d%d%d%d", &a, &b, &DISTANCE, &COST);
		G2[a][b] = DISTANCE;
		G2[b][a] = DISTANCE;
		Cost[a][b] = COST;
		Cost[b][a] = COST;
	}
	DijkstraA1030(s,Vn);
	int i = e;
	stack<int> mystack;
	mystack.push(i);
	while (i!=s)
	{
		i = pre2[i];
		mystack.push(i);
	}
	//mystack.push(i);
	while (!mystack.empty())
	{
		int t = mystack.top();
		mystack.pop();
		printf("%d ", t);
	}
	printf("%d %d", dist2[e], co2[e]);
/*
4 5 0 3
0 1 1 20
1 3 2 30
0 3 4 10
0 2 2 20
2 3 1 20
*/

}
//A1072 Gas Station
int G3[maxn][maxn];
int set3[maxn];
int dist3[maxn];
int getID(char* str,int n)
{
	int i = 0;
	int len = strlen(str);
	int num = 0;
	while (i < len)
	{
		if (str[i] != 'G')
		{
			num = num * 10 + str[i] - '0';
		}
		i++;
	}
	if (str[0] == 'G')return  n + num;
	else return num;

}
void DijkstraA1072(int s,int N,int M)
{
	memset(set3, 0, sizeof(set3));
	fill(dist3, dist3 + maxn, INF);
	dist3[s] = 0;
	for (int i = 0; i < N + M; i++)
	{
		int u = -1, min = INF;
		for (int j = 1; j <= N + M; j++)
		{
			if (set3[j] == 0 && dist3[j] < min)
			{
				u = j;
				min = dist3[j];
			}
		}
		if (u == -1) return;
		set3[u] = 1;
		for (int j = 1; j <= N + M; j++)
		{
			if (set3[j] == 0 && G3[u][j] != INF)
			{
				if (G3[u][j] + dist3[u] < dist3[j])
				{
					dist3[j] = G3[u][j] + dist3[u];
				}
			}
		}
	}

}
void A1072()
{
	int N, M, K, Ds;
	scanf("%d%d%d%d", &N, &M, &K, &Ds);
	for(int i=0;i<maxn;i++)
		for (int j = 0; j < maxn; j++)
		{
			G3[i][j] = INF;
		}

	int u, v, w;
	char city1[5];
	char city2[5];
	for (int i = 0; i < K; i++)
	{
		scanf("%s %s %d", city1, city2, &w);
		u = getID(city1,N);
		v = getID(city2,N);
		G3[u][v] = G3[v][u] = w;
	}
	double ansDis = -1, ansAvg = INF;
	int ansID = -1;
	for (int i = N + 1; i <= N + M; i++)
	{
		double minDis = INF, avg = 0;
		DijkstraA1072(i,N,M);
		for (int j = 1; j <= N; j++)
		{
			if (dist3[j] > Ds)
			{//不在服务范围
				minDis = -1;
				break;
			}

			if (dist3[j] < minDis)
				minDis = dist3[j];
			avg += 1.0*dist3[j] / N;
		}
		if (minDis == -1) continue;//不符合
		if (minDis > ansDis) //ansDis尽可能大
		{
			ansID = i;
			ansDis = minDis;
			ansAvg = avg;
		}
		else if (minDis == ansDis && avg < ansAvg)
		{
			ansID = i;
			ansAvg = avg;
		}


	}
	if (ansID == -1) printf("No Solution\n");
	else
	{
		printf("G%d ", ansID - N);
		printf("%.1f %.1f\n", ansDis, ansAvg);
	}
/*
4 3 11 5
1 2 2 
1 4 2
1 G1 4
1 G2 3
2 3 2
2 G2 1
3 4 2
3 G3 2
4 G1 3
G2 G1 1
G3 G2 2

*/

}

//A1087 All Roads to Rome
typedef struct cityA1087 {
	int index;
	string name;
	int happiness;
	cityA1087()
	{
		happiness = 0;
	}
}CityA1087;
map<int, string> index2name;
map<string, int> name2index;
vector<int> pre4[maxn];
int set4[maxn];
int dist4[maxn];
int G4[maxn][maxn],Weights4[maxn];
int RoutesN[maxn];
int Co4[maxn];
int pathnowN[maxn];//当前顶点个数
void DjkstraA1087(int s,int n)
{
	fill(dist4,dist4+maxn,INF);
	memset(set4, 0, sizeof(set4));
	memset(RoutesN, 0, sizeof(RoutesN));
	memset(pathnowN, 0, sizeof(pathnowN));

	RoutesN[s] = 1;
	dist4[s] = 0;
	for (int i = 0; i < n; i++)
	{
		int u = -1, min = INF;
		for(int j=0;j<n;j++)
		{ 
			if (set4[j]==0&&dist4[j] < min)
			{
				u = j;
				min = dist4[j];
			}
		}
		if (u == -1) return;
		set4[u] = 1;
		for (int j = 0; j < n; j++)
		{
			if (set4[j] == 0 && G4[u][j] != INF)
			{
				if (G4[u][j] + dist4[u] < dist4[j])
				{
					dist4[j] = G4[u][j] + dist4[u];
					Co4[j] = Co4[u] + Weights4[j];
					RoutesN[j] = RoutesN[u];
					pre4[j].clear();
					pre4[j].push_back(u);
					pathnowN[j] = pathnowN[u] + 1;
				}
				else if (G4[u][j] + dist4[u] == dist4[j])
				{
					RoutesN[j] += RoutesN[u];
					if (Co4[u] + Weights4[j] > Co4[j])
					{
						Co4[j] = Co4[u] + Weights4[j];
						pre4[j].clear();
						pre4[j].push_back(u);
						pathnowN[j] = pathnowN[u] + 1;
					}
					else if (Co4[u] + Weights4[j] == Co4[j])
					{
						double uAvg = 1.0*(Co4[u] + Weights4[j]) / (pathnowN[u] + 1);
						double vAvg = 1.0*(Co4[j]) / pathnowN[j];
						if (uAvg > vAvg) //need Change
						{
							pre4[j].clear();
							pre4[j].push_back(u);
							pathnowN[j] = pathnowN[u] + 1;
						}
					}
				}
			}
		}

	}
}
void A1087()
{
	int vn, en;
	string start;
	cin >> vn >> en >> start;
	CityA1087* pCity = new CityA1087[vn];
	pCity[0].index = 0;
	pCity[0].name = start;
	Weights4[0] = 0;
	index2name[0] = start;
	name2index[start] = 0;
	for (int i = 1; i < vn; i++)
	{
		string na;
		int ha;
		cin >> na >> ha;
		pCity[i].index = i;
		pCity[i].name = na;
		pCity[i].happiness = ha;
		name2index[na] = i;
		Weights4[i] = ha;
		index2name[i] = na;
		name2index[na] = i;
		name2index[na] = i;
	}
	string city1, city2;
	int city1n, city2n;

	for(int i=0;i<maxn;i++)
		for (int j = 0; j < maxn; j++)
		{
			G4[i][j] = INF;
			G4[j][i] = INF;
		}
	for (int i = 0; i < en; i++)
	{
		int cost;
		cin >> city1 >> city2 >> cost;
		//index2name[i]=
		city1n = name2index[city1];
		city2n = name2index[city2];
		//printf("city1 %d city2 %d\n", city1n, city2n);
		G4[city1n][city2n] = cost;
		G4[city2n][city1n] = cost;
	}
	 DjkstraA1087( name2index[start], vn);
	 int end = name2index["ROM"];
	// printf("%d %d %d", RoutesN[end], dist4[end], Co4[end]);
	 printf("%d %d %d %d\n", RoutesN[end], dist4[end], Co4[end], Co4[end] / pathnowN[end]);
	 stack<int> mystack;
	 int temp = end;
	 mystack.push(temp);
	 while (!pre4[temp].empty())
	 {
		 mystack.push(pre4[temp][0]);
		 temp = pre4[temp][0];
	 }
	// cout << start ;
	 while (!mystack.empty())
	 {
		 temp = mystack.top();
		 mystack.pop();
		 cout << index2name[temp];
		 if (temp != end)
			 cout << "->";
	 }
	delete[] pCity;
/*
6 7 HZH
ROM 100
PKN 40
GDN 55
PRS 95
BLN 80
ROM GDN 1
BLN ROM 1
HZH PKN 1
PRS ROM 2
BLN HZH 2
PKN GDN 1
HZH PRS 1
*/
}
