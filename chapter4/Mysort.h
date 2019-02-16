#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "iostream"
#include "stdio.h"
#include "algorithm"
#include <cmath>
#include "vector"
using namespace std;
//B1015德才论
typedef struct studentB1015 {
	char id[10];
	int Dgrade;
	int Cgrade;
	int sumgrade;
	int type; //1德才全尽 2德胜才 3德才兼亡_德胜才 4德才兼亡_德输才 5不及格
}StudentB1015;
bool cmpB1015(StudentB1015 a, StudentB1015 b)
{
	if (a.type != b.type) return a.type<b.type;
	else if (a.sumgrade != b.sumgrade) return a.sumgrade > b.sumgrade;
	else if (a.Dgrade != b.Dgrade) return a.Dgrade > b.Dgrade;
	else return strcmp(a.id, b.id)<0;
}
void B1015()
{
	int N, L, H;
	scanf("%d %d %d", &N, &L, &H);
	StudentB1015* sptr = new StudentB1015[N];
	int m = N;
	for (int i = 0; i < N; i++)
	{
		scanf("%s%d%d", sptr[i].id, &sptr[i].Dgrade, &sptr[i].Cgrade);
		sptr[i].sumgrade = sptr[i].Dgrade + sptr[i].Cgrade;
		if (sptr[i].Dgrade < L || sptr[i].Cgrade < L)
		{
			sptr[i].type = 5;
			m--;
		}
		else if (sptr[i].Dgrade >= H && sptr[i].Cgrade >= H) sptr[i].type = 1;
		else if (sptr[i].Dgrade >= H && sptr[i].Cgrade < H) sptr[i].type = 2;
		else if (sptr[i].Dgrade >= sptr[i].Cgrade) sptr[i].type = 3;
		else sptr[i].type = 4;
	}
	sort(sptr, sptr + N, cmpB1015);
	printf("%d\n",m);
	for (int i = 0; i < m; i++)
	{
		printf("%s %d %d\n", sptr[i].id, sptr[i].Dgrade, sptr[i].Cgrade);
	}

	delete[] sptr;
/*
14 60 80
10000001 64 90
10000002 90 60
10000011 85 80
10000003 85 80
10000004 80 85
10000005 82 77
10000006 83 76
10000007 90 78
10000008 75 79
10000009 59 90



10000010 88 45
10000012 80 100
10000013 90 99
10000014 66 60
*/
}
//A1012The Best Rank
typedef struct studentA1012 {
	int ID;
	int grade[4]; //A C M E
	int bestRank;
	char BestFlag;
}StudentA1012;
int now;
bool cmpA1012(StudentA1012 a,StudentA1012 b)
{
	return a.grade[now] > b.grade[now];
}
void A1012()
{
	char flag[4] = { 'A','C','M','E' };
	int N,M;
	scanf("%d %d", &N, &M);
	StudentA1012* sptr = new StudentA1012[N];
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d %d %d", &sptr[i].ID, &sptr[i].grade[1], &sptr[i].grade[2], &sptr[i].grade[3]);
		sptr[i].grade[0] = sptr[i].grade[1] + sptr[i].grade[2] + sptr[i].grade[3];
		sptr[i].bestRank = N;
		sptr[i].BestFlag = 'A';
	}
	for ( now= 0; now < 4; now++)
	{
		sort(sptr, sptr + N, cmpA1012);
		//printf("now:%d\n", now);
		for (int i = 0; i < N; i++)
		{
			//printf("%d %d\n", i+1, sptr[i].ID);
			if (sptr[i].bestRank > (i + 1)) {
			//	printf("%d %d\n", sptr[i].bestRank, (i + 1));
				sptr[i].bestRank = i + 1;
				sptr[i].BestFlag = flag[now];
			}
		}
	}
	for (int i = 0; i < M; i++)
	{
		int sid;
		scanf("%d", &sid);
		bool findS = false;
		for (int j = 0; j < N; j++)
		{
			if (sptr[j].ID == sid) {
				findS = true;
				printf("%d %c\n", sptr[j].bestRank, sptr[j].BestFlag);
				break;
			}
		}
		if (!findS) printf("N/A\n");
	}


	delete[] sptr;
	/*
5 6
310101 98 85 88
310102 70 95 88
310103 82 87 94
310104 91 91 91
310105 85 90 90
	*/
}
//A1016Phone Bills
typedef struct callInfor {
	char name[25];
	int month, dd, hh, mm;
	bool status;
}CallInfor;
int CallPrice[24] = { 10,10,10,10,10,10,20,20,20,15,15,15,15,15,15,15,20,30,20,15,15,10,10,10 };
bool cmpA1016(CallInfor a, CallInfor b)
{
	int s = strcmp(a.name, b.name);
	if (s != 0) return s < 0;
	else if (a.month != b.month) return a.month < b.month;
	else if (a.dd != b.dd) return a.dd < b.dd;
	else if (a.hh != b.hh) return a.hh < b.hh;
	else return a.mm < b.mm;
}
void get_ans(int on, int off, CallInfor* ptr,int& time, int& money)
{
	CallInfor temp = ptr[on];
	while (temp.dd < ptr[off].dd || temp.hh < ptr[off].hh || temp.mm < ptr[off].mm)
	{
		time++;
		money += CallPrice[temp.hh];
		temp.mm++;
		if (temp.mm >= 60)
		{
			temp.mm = 0;
			temp.hh++;
		}
		if (temp.hh >= 24)
		{
			temp.hh = 0;
			temp.dd++;
		}
	}
}
void A1016()
{
	
	int N;
	scanf("%d", &N);
	CallInfor* callptr = new CallInfor[N];
	char line[10];
	for (int i = 0; i < N; i++)
	{
		scanf("%s", callptr[i].name);
		scanf("%d:%d:%d:%d", &callptr[i].month, &callptr[i].dd, &callptr[i].hh, &callptr[i].mm);
		scanf("%s", line);
		if (strcmp(line, "on-line") == 0) callptr[i].status = true;
		else callptr[i].status= false;
	}
	sort(callptr, callptr + N, cmpA1016);
	int on = 0, off, next;
	while (on < N)
	{
		int needprint = 0;
		next = on;
		while (next < N&&strcmp(callptr[next].name, callptr[on].name) == 0)
		{
			if (needprint == 0 && callptr[next].status == true) needprint = 1;
			else if (needprint == 1 && callptr[next].status == false) needprint = 2;

			next++;
		}

		if (needprint < 2)
		{
			on = next;
			continue;
		}
		int AllMoney = 0;
		printf("%s %02d\n", callptr[on].name, callptr[on].month);
		while (on < next)
		{
			while (on < next - 1 && !(callptr[on].status == true && callptr[on + 1].status == false))
			{
				on++;
			}
			off = on + 1;
			if (off == next)
			{
				on = next;
				break;
			}
			printf("%02d:%02d:%02d", callptr[on].dd, callptr[on].hh, callptr[on].mm);
			printf("%02d:%02d:%02d", callptr[off].dd, callptr[off].hh, callptr[off].mm);
			int time = 0, money = 0;
			get_ans(on, off, callptr,time, money);
			AllMoney += money;
			printf("%d $%.2f\n", time, money / 100.0);
			on = off + 1;
		}
		printf("Total amount: $%.2f\n", AllMoney / 100.0);
	}
	delete[] callptr;


/*
10
CYLL 01:01:06:01 on-line
CYLL 01:28:16:05 off-line
CYJJ 01:01:07:00 off-line
CYLL 01:01:08:03 off-line
CYJJ 01:01:05:59 on-line
aaa 01:01:01:03 on-line
aaa 01:02:00:01 on-line
CYLL 01:28:15:41 on-line
aaa 01:05:02:24 on-line
aaa 01:04:23:59 off-line
*/
}
//A1025PAT Ranking

typedef struct studentA1025 {
	char ID[15];
	int score;
	int TatalRank;
	int location;
	int locationRank;

}StudentA1025;
bool cmpA1025(StudentA1025 a, studentA1025 b)
{
	if (a.score != b.score) return a.score > b.score;
	else return strcmp(a.ID, b.ID) < 0;
}

void A1025()
{
	int N;
	studentA1025* sptr;
	scanf("%d", &N);
	sptr = new studentA1025[1000];
	//int *kr = new int[N];
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		int n;
		scanf("%d", &n);
		for (int j = 0; j < n; j++)
		{
		int locationN = i + 1;
		scanf("%s", sptr[sum].ID);
		scanf("%d", &sptr[sum].score);
		sptr[sum].location = locationN;
		sum++;
		}
		sort(sptr + sum - n, sptr + sum, cmpA1025);
		int inc = 0;
		for (int j = sum - n; j < sum; j++)
		{
			sptr[sum - n].locationRank = 1;
			if (j > sum-n)
			{
				if (sptr[j].score == sptr[j-1].score)
				{
					sptr[j].locationRank = sptr[j-1].locationRank;
					inc++;;
				}
				else {
					sptr[j].locationRank = sptr[j - 1].locationRank +inc+1;
					inc=0;
				}
			}
		}
	}
	sort(sptr, sptr + sum, cmpA1025);
	int inc = 0;
	for (int i = 0; i < sum; i++)
	{
		sptr[0].TatalRank = 1;
		if (i > 0)
		{
			if (sptr[i].score == sptr[i - 1].score)
			{
				sptr[i].TatalRank = sptr[i - 1].TatalRank;
				inc++;
			}
			else {
				sptr[i].TatalRank = sptr[i - 1].TatalRank +inc+1;
				inc=0;
			}
		}

	}
	for (int i = 0; i < sum; i++)
	{
		printf("%s ", sptr[i].ID);
		printf("%d %d %d", sptr[i].TatalRank, sptr[i].location, sptr[i].locationRank);
		printf("\n");
	}


//	for (int i = 0; i < N; i++)
	//	delete[] sptr[i];
	delete[] sptr;
//	delete[] kr;
//	delete[] ssptr;
}

//A1028 List Sorting
typedef struct studentA1028 {
	int ID;
	char name[20];
	int score;
	int flag;
}StudentA1028;
bool cmpA1028(studentA1028 a, StudentA1028 b)
{
	if (a.flag == 1)
	{
		return a.ID < b.ID;
	}
	else if (a.flag == 2)
	{
		int s = strcmp(a.name, b.name);
		if (s != 0) return s < 0;
		else return a.ID < b.ID;
		//return strcmp(a.name, b.name) < 0;
	}
	else if (a.flag == 3)
	{
		return a.score < b.score;
	}
	return true;
}
void A1028()
{
	int N, C;
	scanf("%d %d", &N, &C);
	StudentA1028* sptr = new StudentA1028[N];
	for (int i = 0; i < N; i++)
	{
		scanf("%d %s %d", &sptr[i].ID, sptr[i].name, &sptr[i].score);
		sptr[i].flag = C;
	}
	sort(sptr, sptr + N, cmpA1028);
	for (int i = 0; i < N; i++)
	{
		printf("%06d %s %d\n", sptr[i].ID, sptr[i].name, sptr[i].score);
	}
	delete[] sptr;
/*
4 2
000007 James 85
000010 Amy 90
000001 Zoe 60
000002 James 98
*/
}

//A1055 The World's Richest
typedef struct personA1055 {

	char name[20];
	int age;
	int worth;
}PersonA1055;
bool cmpA1055(PersonA1055 a, PersonA1055 b)
{
	if (a.worth != b.worth) return a.worth > b.worth;
	else if (a.age != b.age) return a.age < b.age;
	else return strcmp(a.name, b.name) < 0;
}
void A1055()
{
	int n, k;
	scanf("%d %d", &n, &k);
	PersonA1055* pptr = new PersonA1055[n];
	for (int i = 0; i < n; i++)
	{
		scanf("%s %d %d", pptr[i].name, &pptr[i].age, &pptr[i].worth);
	}
	sort(pptr, pptr + n, cmpA1055);
	for (int i = 0; i < k; i++)
	{
		int maxn;
		int mina;
		int maxa;
		scanf("%d %d %d", &maxn,&mina, &maxa);
		int tempn = 0;
		printf("Case #%d:\n", i + 1);
		for (int j = 0; j < n; j++)
		{
			if (tempn == maxn) break;
			else {
				if (pptr[j].age >= mina && pptr[j].age <= maxa) {
					printf("%s %d %d\n", pptr[j].name, pptr[j].age, pptr[j].worth);
					tempn++;
					}
				
			}
			
		}
		if (tempn == 0)
			printf("None");
	}
	delete[] pptr;
/*
12 4
Zoe_Bill 35 2333
Bob_Volk 24 5888
Anny_Cin 95 999999
Williams 30 -22
Cindy 76 76000
Alice 18 88888
Joe_Mike 32 3222
Michael 5 300000
Rosemary 40 5888
Dobby 24 5888
Billy 24 5888
Nobody 5 0
4 15 45
4 30 35
4 5 95
1 45 50
*/
}

//A1075 PAT Judge
typedef struct examinee {
	int ID;
	int score[10];
	int totalscore;
	bool submitted;
	int CsolveN;
}ExamineeA1075;
bool cmpA1075(ExamineeA1075 a, ExamineeA1075 b)
{
	if (a.totalscore != b.totalscore) return a.totalscore > b.totalscore;
	else if (a.CsolveN != b.CsolveN) return a.CsolveN > b.CsolveN;
	else return a.ID < b.ID;
}
void A1075()
{
	int usern;
	int problemn;
	int subn;
	scanf("%d %d %d", &usern, &problemn, &subn);
	int* pscore = new int[problemn];
	for (int i = 0; i < problemn; i++)
		scanf("%d", &pscore[i]);
ExamineeA1075* eptr = new ExamineeA1075[usern];
for (int i = 0; i < usern; i++)
{
	eptr[i].ID = i + 1;
	for (int index = 0; index < 6; index++)
		eptr[i].score[index] = -1;
	eptr[i].totalscore = 0;
	eptr[i].submitted = false;
	eptr[i].CsolveN = 0;
}
for (int i = 0; i < subn; i++)
{
	int id, probelmid, getscore;
	scanf("%d %d %d", &id, &probelmid, &getscore);
	for (int j = 0; j < usern; j++)
	{
		if (eptr[j].ID == id)
		{
			//eptr[j].submitted = true;
			if (getscore >= eptr[j].score[probelmid - 1])
			{
				if (getscore == -1)
				{
					eptr[j].score[probelmid - 1] = 0;
					break;
				}
				eptr[j].score[probelmid - 1] = getscore;

			}
			if (getscore == pscore[probelmid - 1]) eptr[i].CsolveN++;

			int temp = 0;
			for (int qq = 0; qq < problemn; qq++)
			{
				//int temp = 0;
				if (eptr[j].score[qq] != -1)
				{
					temp += eptr[j].score[qq];
				}
				//eptr[j].totalscore = temp;
			}
			eptr[j].totalscore = temp;
			eptr[j].submitted = true;

		}



	}
}

sort(eptr, eptr + usern, cmpA1075);

for (int i = 0; i < usern; i++)
{
	if (eptr[i].submitted == true)
	{
		printf("%06d %d ", eptr[i].ID, eptr[i].totalscore);
		for (int j = 0; j < problemn; j++)
		{

			if (eptr[i].score[j] != -1) printf("%d ", eptr[i].score[j]);
			else printf("- ");
			if (j == problemn - 1)
			{
				printf("\t%d", eptr[i].CsolveN);
				printf("\n");
			}
		}
	}
}
delete[] pscore;
delete[] eptr;
/*
7 4 20
20 25 25 30
000002 2 12
000007 4 17
000005 1 19
000007 2 25
000005 1 20
000002 2 2
000005 1 15
000001 1 18
000004 3 25
000002 2 25
000005 3 22
000006 4 -1
000001 2 18
000002 1 20
000004 1 15
000002 4 18
000001 3 4
000001 4 2
000005 2 -1
000004 2 0
*/

}

//A1083 List Grades
typedef struct studentA1083 {
	char name[10];
	char ID[20];
	int grade;
}StudentA1083;
bool cmpA1083(StudentA1083 a, StudentA1083 b)
{
	if (a.grade != b.grade) return a.grade > b.grade;
	else return strcmp(a.ID, b.ID) < 0;
}
void A1083()
{
	int n;
	scanf("%d", &n);
	StudentA1083* sptr = new StudentA1083[n];
	for (int i = 0; i < n; i++)
	{
		scanf("%s %s %d", sptr[i].name, sptr[i].ID, &sptr[i].grade);
	}
	int ming, maxg;
	scanf("%d %d", &ming, &maxg);

	sort(sptr, sptr + n, cmpA1083);

	int number = 0;
	for (int i = 0; i < n; i++)
	{
		if (sptr[i].grade < ming) break;
		else if(sptr[i].grade>=ming&&sptr[i].grade<=maxg) {
			number++;
			printf("%s %s\n", sptr[i].name, sptr[i].ID);
		}
	}
	if (number == 0) printf("NONE");

	delete[] sptr;
/*
4
Tom CS0000001 59
Joe Math990112 89
Mike CS991301 100
Mary EE990830 95
60 100
*/
}

//A1080 Graduate Admission
typedef struct applicant {
	int id;
	int GE;
	int IE;
	int Vs[10];
	int sum;
	int lqS;
}ApplicatnA1080;
bool cmpA1080(ApplicatnA1080 a, ApplicatnA1080 b)
{
	int suma,sumb;
	suma = a.GE + a.IE;
	sumb = b.GE + b.IE;
	if (suma != sumb) return suma > sumb;
	else return a.GE > b.GE;
}
bool cmp1080b(ApplicatnA1080 a, ApplicatnA1080 b)
{
	return a.id < b.id;
}
void A1080()
{
	int applicantN, schoolN, choiceN;
	scanf("%d %d %d", &applicantN, &schoolN, &choiceN);
	int* Schoolsys = new int[schoolN];
	ApplicatnA1080* aptr = new ApplicatnA1080[applicantN];
	for (int i = 0; i < schoolN; i++)
		scanf("%d", &Schoolsys[i]);
	for (int i = 0; i < applicantN; i++)
	{
		scanf("%d %d", &aptr[i].GE, &aptr[i].IE);
		for (int j = 0; j < choiceN; j++)
			scanf("%d", &aptr[i].Vs[j]);
		aptr[i].sum = aptr[i].GE + aptr[i].IE;
		aptr[i].id = i;
		aptr[i].lqS = -1;

	}
	sort(aptr, aptr + applicantN, cmpA1080);
	for (int i = 0; i < applicantN; i++)
	{
		if (i == 0) {
			aptr[i].lqS = aptr[i].Vs[0];
			Schoolsys[aptr[i].Vs[0]]--;
		}
		else {
			for (int j = 0; j < choiceN; j++)
			{
				if (Schoolsys[aptr[i].Vs[j]] > 0)
				{
					aptr[i].lqS = aptr[i].Vs[j];
					Schoolsys[aptr[i].Vs[j]]--;
					break;
				}
				else {
					if (aptr[i - 1].sum == aptr[i].sum&&aptr[i - 1].GE == aptr[i].GE)
					{
						if (aptr[i - 1].lqS == aptr[i].Vs[j]) aptr[i].lqS = aptr[i].Vs[j];
					}
				}
			}
		}
	}

	sort(aptr, aptr + applicantN, cmp1080b);
	for (int i = 0; i < schoolN; i++)
	{
		for (int j = 0; j < applicantN; j++)
		{
			if (aptr[j].lqS == i) printf("%d ", aptr[j].id);
		}
		printf("\n");
	}
	delete[] Schoolsys;
	delete[] aptr;

/*
11 6 3
2 1 2 2 2 3
100 100 0 1 2
60 60 2 3 5
100 90 0 3 4
90 100 1 2 0
90 90 5 1 3
80 90 1 0 2
80 80 0 1 2
80 80 0 1 2
80 70 1 3 2
70 80 1 2 3
100 100 0 2 4
*/
}

//A1095 Cars on Campus
typedef struct carInfor {
	char name[10];
	int time;
	int hh;
	int mm;
	int ss;
	bool in;
}CarInfor;
bool cmpA1095(CarInfor a, CarInfor b)
{
	return a.time < b.time;
}
void A1095()
{
	int n, k;
	scanf("%d %d", &n, &k);
	CarInfor* ciptr = new CarInfor[n];
	for (int i = 0; i < n; i++)
	{
		int hh, mm, ss;
		char status[4];
		scanf("%s %d:%d:%d %s", ciptr[i].name, &hh, &mm, &ss, status);
		ciptr[i].hh = hh;
		ciptr[i].mm = mm;
		ciptr[i].ss = ss;
		ciptr[i].time = hh * 3600 + mm * 60 + ss;
		if (strcmp(status, "in")==0) ciptr[i].in = true;
		else ciptr[i].in = false;
	}
	sort(ciptr, ciptr + n, cmpA1095);
	for (int i = 0; i < n; i++)
	{
		
		printf("%s %d:%d:%d %d\n", ciptr[i].name, ciptr[i].hh, ciptr[i].mm, ciptr[i].ss, ciptr[i].in);
	}

	int temptime;
	int hh, mm, ss;
	//int num = 0;
	for (int i = 0; i < k; i++)
	{
		int num = 0;
		scanf("%d:%d:%d", &hh, &mm, &ss);
		temptime = hh * 3600 + mm * 60 + ss;
		for (int j = 0; j < n; j++)
		{
			if (ciptr[j].time <= temptime) {
				if (ciptr[j].in == true) num++;
				else num--;
			}
			else break;
		}
		printf("%d\n", num);
	}
	delete[] ciptr;
/*
16 7
JH007BD 18:00:01 in
ZD00001 11:30:08 out
DB8888A 13:00:00 out
ZA3Q625 23:59:50 out
ZA133CH 10:23:00 in
ZD00001 04:09:59 in
JH007BD 05:09:59 in
ZA3Q625 11:42:01 out
JH007BD 05:10:33 in
ZA3Q625 06:30:50 in
JH007BD 12:23:42 out
ZA3Q625 23:55:00 in
JH007BD 12:24:23 out
ZA133CH 17:11:22 out
JH007BD 18:07:01 out
DB8888A 06:30:50 in
05:10:00
06:30:50
11:00:00
12:23:42
*/
}
