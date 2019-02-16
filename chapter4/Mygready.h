#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "iostream"
#include "stdio.h"
#include "algorithm"
#include <cmath>
#include "string"
#include "vector"
using namespace std;
//B1023
void B1023()
{
	int NumberN[10] = { 0 };
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &NumberN[i]);
	}
	for (int i = 1; i < 10; i++)
	{
		if (NumberN[i] > 0) {
			printf("%d", i);
			NumberN[i]--;
			break;
		}
	}
	int i = 0;
	while (i<10)
	{
		while (NumberN[i] > 0)
		{
			printf("%d", i);
			NumberN[i]--;
		}
		i++;
	}
/*
2 2 0 0 0 3 0 0 1 0
*/
}
//B1020 
typedef struct mooncake {
	double store;
	double sell;
	double price;
}Mooncake;
bool cmpB1020(Mooncake a, Mooncake b)
{
	return a.price > b.price;
}
void B1020()
{
	
	int N, NEED;
	scanf("%d %d", &N, &NEED);
	Mooncake* mptr = new Mooncake[N];
	for (int i = 0; i < N; i++)
	{
		scanf("%lf", &mptr[i].store);
	}
	for (int i = 0; i < N; i++)
	{
		scanf("%lf", &mptr[i].sell);
		mptr[i].price = mptr[i].sell / mptr[i].store;
	}
	sort(mptr, mptr + N, cmpB1020);
	double sum=0;
	while (NEED > 0)
	{
		for (int i = 0; i < N; i++)
		{
			if (NEED < mptr[i].store)
			{
				sum += mptr[i].price*NEED;
				NEED = 0;
				break;
			}
			else {
				NEED -= mptr[i].store;
				sum += mptr[i].price*mptr[i].store;
			}
		}
	}
	printf("%.2f", sum);
	delete[] mptr;
/*
3 20
18 15 10
72 72 45
*/
}
//A1033 To Fill or Not to Fill
typedef struct gasStation {
	double price;
	double distance;
}GasStation;
bool cmpA1033(GasStation a, GasStation b)
{
	return a.distance < b.distance;
}
bool cmpA1033_2(GasStation a, GasStation b)
{
	return a.price < b.price;
}
void A1033()
{	
	int Capacity;
	int D;
	int gasconsume;
	int GasSN;
	scanf("%d %d %d %d", &Capacity, &D, &gasconsume, &GasSN);
	GasStation* gptr = new GasStation[GasSN+1];
	for (int i = 0; i < GasSN; i++)
	{
		scanf("%lf %lf", &gptr[i].price, &gptr[i].distance);
	}
	gptr[GasSN].price = 0;
	gptr[GasSN].distance = D;
	sort(gptr, gptr + GasSN, cmpA1033);
	double distanceruned = 0;
	int now = 0;
	double consumedM = 0, nowTank = 0;
	bool canarrive = true;
	while (now < GasSN)
	{
		bool flag = false;
		int intentedG=-1;
		for (int i = now+1; i <= GasSN; i++)
		{
			if(gptr[i].price<gptr[i].price)
			{ 
				if ((gptr[i].distance - gptr[now].distance) <= 600)
				{
					intentedG = i;
					flag = true;
					break;
				}
			}
		}
		if (flag)
		{
			printf("flag true\n");
			double needGas=(gptr[intentedG].distance - gptr[now].distance)/12;
			double addGas = 0;
			if (nowTank < needGas) {
				//add gas
				addGas = needGas - nowTank;
				nowTank = needGas;
			}
			else; //don't need add gas

			consumedM += addGas * gptr[now].price;
			//arrive
			now = intentedG;
			nowTank -= needGas;
			printf("arrive %d£¬cost %lf totalCost %lf\n", now, addGas * gptr[now].price, consumedM);
		}
		else {//
			//intentedG
			printf("flag false\n");
			double distanceNow = gptr[now].distance;
			sort(gptr, gptr + GasSN, cmpA1033_2);
			int now2;
			for (now2 = 0; now2 < GasSN; now2++)
			{
				if (gptr[now2].distance == distanceNow) break;
			}
			for (int i = 0; i <= GasSN; i++)
			{
				if (gptr[i].distance > gptr[now2].distance)
				{
					if ((gptr[i].distance - gptr[now2].distance) <= 600)
					{
						printf("%lf\n", gptr[i].distance);
						intentedG = i;
						break;
					}
					else {
						continue;
					}
				}
			}
			if (intentedG != -1)
			{
				//add Gas
				int addgas = Capacity - nowTank;
				nowTank = Capacity;
				consumedM += addgas * gptr[now2].price;
				//arrive
				now2 = intentedG;
				nowTank -= addgas;
				printf("arrive %d£¬cost %lf totalCost %lf\n", now2, addgas * gptr[now2].price, consumedM);

			}
			else
			{
				printf("The maximum travel distance=%.2f", gptr[now2].distance);
				canarrive = false;
				break;
			}

		int distanceNow2 = now2;
		sort(gptr, gptr + GasSN, cmpA1033);
		for (now = 0; now < GasSN; now++)
			if (gptr[now].distance == distanceNow2) break;
		}


	}
	if (canarrive)
		printf("%.2f", consumedM);
	delete[] gptr;
/*
50 1300 12 8
6.00 1250
7.00 600
7.00 150
7.10 0
7.20 200
7.50 400
7.30 1000
6.85 300

*/

}
//A1037 Magic Coupon
bool cmpA1037(int a, int b)
{
	if (a < 0 &&  b< 0) {
		return a < b;
	}
	else  return a > b;

}
void A1037()
{
	int n1,n2;
	scanf("%d",&n1);
	int* set1 = new int[n1];
	for (int i = 0; i < n1; i++)
		scanf("%d", &set1[i]);
	scanf("%d", &n2);
	int* set2 = new int[n2];
	for (int i = 0; i < n2; i++)
		scanf("%d", &set2[i]);

	sort(set1, set1 + n1, cmpA1037);
	sort(set2, set2 + n2, cmpA1037);
	for (int i = 0; i < n1; i++)
		printf("%d ", set1[i]);
	for (int i = 0; i < n2; i++)
		printf("%d ", set2[i]);
	printf("\n");
	int sum = 0;
	int i = 0;
	int j = 0;
	while (i < n1&&j < n2)
	{
		if (set1[i] > 0 && set2[j] > 0)
		{
			sum += set1[i] * set2[j];
			j++;
			i++;
		}
		else if (set1[i] < 0 && set2[j]>0) j++;
		else if (set1[i] > 0 && set2[j] < 0)
		{
			i++;
		}
		else if (set1[i] < 0 && set2[j] < 0)
		{
			sum += set1[i] * set2[j];
			i++;
			j++;
		}
	}
	printf("%d", sum);
	delete[] set1;
	delete[] set2;


/*
4
1 2 4 -1
4
7 6 -2 -3
*/
}
//A1067 Sort with Swap(0,*)
bool hassorted(int* aa,int n)
{
	bool flag = true;
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			if (aa[j] < aa[i]) {
				flag = false;
				break;
			}
		}
		if (!flag) break;

		printf("come in2\n");
	}

	return flag;
}
void A1067()
{
	int N;
	scanf("%d", &N);
	int* a = new int[N];
	for (int i = 0; i < N; i++)
		scanf("%d", &a[i]);
	int exchange_T = 0;
	while (!hassorted(a, N)) {
		//printf("come in1\n");
		for (int i = 0; i < N; i++)
		{

			if (a[i] == 0)
			{
				printf("find a[%d]\n", i);
				if (i != 0)
				{
					for(int j=0;j<N;j++)
						if (a[j] == i)
						{

							int temp = a[j];
							a[j] = a[i];
							a[i] = temp;
							exchange_T++;
							break;
						}
					for (int k = 0; k < N; k++)
					{
						printf("%d ", a[k]);
						if (k == N - 1) printf("\n");
					}

				}
				else
				{
					for(int j=0;j<N;j++)
						if (a[j] != j)
						{

							int temp = a[j];
							a[j] = a[i];
							a[i] = temp;
							exchange_T++;
							break;
						}
					for (int k = 0; k < N; k++)
					{
						printf("%d ", a[k]);
						if (k == N - 1) printf("\n");
					}

				}
				break;
			}
		}


	}
	printf("%d", exchange_T);
/*
10 3 5 7 2 6 4 9 0 8 1
*/

	delete[] a;

}
//A1038 Recover the Smallest Number
bool cmpA1038(string a, string b)
{
	return a + b < b + a;
}
void A1038()
{
	int n;
	cin >> n;
	string* pstring = new string[n];
	for (int i = 0; i < n; i++)
	{
		cin >> pstring[i];
	}
	sort(pstring, pstring + n, cmpA1038);
	string ans;
	for (int i = 0; i < n; i++)
	{
		ans += pstring[i];
	}

	int size = ans.size();
	while (ans.size()!=0&&ans[0] == '0')
	{
		ans.erase(ans.begin());
	}
	if (ans.size() == 0) printf("0");
	else cout << ans;
	delete[] pstring;
/*
5 32 321 3214 0229 87
*/
}