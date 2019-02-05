#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "iostream"
#include "stdio.h"
#include <cmath>
#include "vector"
using namespace std;

//B1041 Exam chair number
void B1041()
{
	typedef struct examStudent
	{
		long long studentN;
		int Snum;
		int Rnum;

	}ExamStudent;
	int studentN;
	scanf("%d", &studentN);
	ExamStudent* ptr = new ExamStudent[studentN];

	for (int i = 0; i < studentN; i++)
	{
		cin >> ptr[i].studentN >> ptr[i].Snum >> ptr[i].Rnum;

	}
	for (int i = 0; i < studentN; i++)
	{
		printf("%d\n",ptr[i].Rnum);

	}
	printf("Please input the number of student you want to search: ");
	int n;
	scanf("%d", &n);
	printf("Please input %d SJH: ",n);
	int* arraySj = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arraySj[i];
	}

	for(int i=0;i<n;i++)
	for (int j = 0; j < studentN; j++)
	{
		if (ptr[j].Snum == arraySj[i])
		{
			//cout << ptr[j].studentN << " " << ptr[j].Rnum << endl;
			printf("%lld %d\n", ptr[j].studentN, ptr[j].Rnum);
			break;
		}
	}


	delete[] ptr;
	delete[]  arraySj;

}

//B1004 Grade sort
void B1004()
{
	typedef struct student {
		char name[15];  //name 为数组
		char stuN[15];	// stuN 为数组
		int score;
	}MyStudent;
	
	int Number;
	scanf("%d", &Number);
	MyStudent* ptr = new MyStudent[Number];
	MyStudent minStudent;
	minStudent.score = 101;
	MyStudent maxStudent;
	maxStudent.score = -1;
	for (int i = 0; i < Number; i++)
	{
		scanf("%s%s%d", ptr[i].name, ptr[i].stuN, &ptr[i].score);//数组不用加&
		if (ptr[i].score > maxStudent.score) maxStudent = ptr[i];
		if (ptr[i].score < minStudent.score) minStudent = ptr[i];
	}
	printf("%s %s\n", maxStudent.name, maxStudent.stuN);
	printf("%s %s", minStudent.name, minStudent.stuN);


	delete[] ptr;
}

//B1028 population common check
typedef struct person {
	char name[5];//array
	int yy, mm, dd;

}Person;
bool LessEqu(Person a, Person b)
{
	if (a.yy != b.yy) return a.yy <= b.yy;
	else if (a.mm != b.mm) return a.mm <= b.mm;
	else return a.dd <= b.dd;
}
bool MoreEque(Person a, Person b)
{
	if (a.yy != b.yy) return a.yy >= b.yy;
	else if (a.mm != b.mm) return a.mm >= b.mm;
	else return a.dd >= b.dd;
}
void B1028()
{

	int N;
	scanf("%d", &N);
	Person* Pptr = new Person[N];
	Person oldest, yongest,left,right;
	oldest.yy = 2014, oldest.mm = 9,oldest.dd = 6;
	right.yy = 2014, right.mm = 9, right.dd = 6;
	yongest.yy = 1814, yongest.mm = 9, yongest.dd = 6;
	left.yy = 1814, left.mm = 9, left.dd = 6;
	bool first = true;
	int validN = N;
	for (int i = 0; i < N; i++)
	{
		scanf("%s %d/%d/%d", Pptr[i].name, &Pptr[i].yy, &Pptr[i].mm, &Pptr[i].dd);
		if (first)
		{
			if (LessEqu(Pptr[i], right)&&MoreEque(Pptr[i], left))
			{
				oldest = yongest = Pptr[i];
				first = false;
				continue;
			}
			validN--;
			continue;
		}

		else
		{
			if (LessEqu(Pptr[i], right) && MoreEque(Pptr[i], left))
			{
				if (LessEqu(Pptr[i], oldest)) oldest = Pptr[i];
				if (MoreEque(Pptr[i], yongest))yongest = Pptr[i];
				continue;
			}
			validN--;
		}
	}
	printf("%d %s %s", validN, oldest.name, yongest.name);
}  //B1028 population common checkfinish

//B1032  excavator technology
void B1032()
{
	typedef struct school {
		int number;
		int score;
	}School;
	School max_school;
	//max_school.score = 0;
	int N;
	scanf("%d", &N);
	School* Sptr = new School[N];
	for (int i = 0; i < N; i++)
	{
		//scanf("")
		scanf_s("%d%d", &Sptr[i].number, &Sptr[i].score);
	}
	vector<School*> Vec;
	for (int i = 0; i < N; i++)
	{
		bool exit = false;
		for (int j = 0; j < Vec.size(); j++)
		{
			if (Sptr[i].number == Vec[j]->number)
			{
				exit = true;
				Vec[j]->score += Sptr[i].score;
				break;
			}
		}
		if (!exit)
		{
			Vec.push_back(&Sptr[i]);
		}
	}
	int max_score = 0;
	int Number=-1;
	for (int i = 0;i < Vec.size(); i++)
	{
		if (Vec[i]->score > max_score)
		{
			max_score = Vec[i]->score;
			Number =Vec[i]->number;
		}

	}
	printf("%d %d", Number, max_score);

	delete[] Sptr;
}

//A1011 World Cup Betting
void A1011()
{
	double Aarray[3][3] = { 0 };
	double marked[3] = { 0 };
	//for (int i = 0; i < 3; i++)
	//{
	//	cin >> Aarray[i][0] >> Aarray[i][1] >> Aarray[i][2];
	//	
	//}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			scanf_s("%lf", &Aarray[i][j]);//lf 为double
		}
	}
	double sum = 0;
	for (int i = 0; i < 3; i++)
	{
		int index = 0;
		double max = Aarray[i][0];
		for (int j = 0; j < 3; j++)
		{
			if (Aarray[i][j] > max)
			{
				index = j;
				max = Aarray[i][j];
			}

		}
		if (index == 0) printf("W ");
		else if (1 == index) printf("T ");
		else printf("L ");
		marked[i] = max;
		//sum += max;
	}
	sum = (marked[0] * marked[1] * marked[2] * 0.65 - 1) * 2;
	printf("%.2f", sum);

}

//A1006 Sign In and Sign out
void A1006()
{
	typedef struct person
	{
		char ID[15];
		int Jhh, Jmm, Jss;
		int Chh, Cmm, Css;
	}Person ;
	Person unlockPerson, lockPerson;
	unlockPerson.Jhh = 23; unlockPerson.Jmm = 59; unlockPerson.Jss = 59;
	lockPerson.Chh = 0; lockPerson.Cmm = 0; lockPerson.Css = 0;
	int N;
	scanf("%d", &N);
	Person* ptr = new Person[N];
	for (int i = 0; i < N; i++)
	{
		int tempEarly,tempLate,tempJ,tempC;
		tempEarly = unlockPerson.Jhh * 3600 + 60 * unlockPerson .Jmm+ unlockPerson.Jss;
		tempLate = lockPerson.Chh * 3600 + 60 * lockPerson.Cmm+lockPerson.Css;
	/*	scanf_s("%s %d:%d:%d %d:%d:%d", ptr[i].ID, &ptr[i].Jhh,&ptr[i].Jmm, &ptr[i].Jss,
			&ptr[i].Chh, &ptr[i].Cmm, &ptr[i].Css);*/
		scanf("%s %d:%d:%d", ptr[i].ID, &ptr[i].Jhh, &ptr[i].Jmm, &ptr[i].Jss);
		scanf("%d:%d:%d", &ptr[i].Chh, &ptr[i].Cmm, &ptr[i].Css); //分开写
		tempJ = 3600 * ptr[i].Jhh + 60 * ptr[i].Jmm + ptr[i].Jss;
		tempC = 3600 * ptr[i].Chh + 60 * ptr[i].Cmm + ptr[i].Css;
		if (tempJ < tempEarly) unlockPerson = ptr[i];
		if (tempC > tempLate)  lockPerson = ptr[i];

	}

	printf("%s %s", unlockPerson.ID, lockPerson.ID);

	delete[] ptr;
}

//A1036 Boys vs Girls
void A1036()
{
	typedef struct student {
		char name[15];
		char sex;
		char ID[15];
		int grade;
	}Student;
	bool Mexit = false;
	bool Fexit = true;
	int N;
	scanf("%d", &N);
	Student lowestMs;
	Student highestFs;
	lowestMs.grade = 100;
	highestFs.grade = 0;
	Student* ptr = new Student[N];
	for (int i = 0; i < N; i++)
	{
		cin >> ptr[i].name >> ptr[i].sex >> ptr[i].ID >> ptr[i].grade;
	//	scanf_s("%s%c%s%d", ptr[i].name, &ptr[i].sex, ptr[i].ID, &ptr[i].grade);
		/*scanf_s("%s", ptr[i].name);
		scanf_s("%c", &ptr[i].sex);
		scanf_s("%s %d", ptr[i].ID, &ptr[i].grade);*/
		if (ptr[i].sex == 'M') Mexit = true;
		if (ptr[i].sex == 'F') Fexit = true;
		if (ptr[i].grade > highestFs.grade&&ptr[i].sex == 'F') highestFs = ptr[i];
		if (ptr[i].grade < lowestMs.grade&&ptr[i].sex == 'M') lowestMs = ptr[i];


	}
	if (Fexit) {
		printf("%s %s\n", highestFs.name, highestFs.ID);

	}
	else  printf("Absent\n");
	if (Mexit) {
		printf("%s %s\n", lowestMs.name, lowestMs.ID);
	}
	else printf("Absent\n");

	if (Mexit&&Fexit)
	{
		printf("%d", highestFs.grade - lowestMs.grade);
	}
	else printf("NA");
	delete[] ptr;
}


