#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "iostream"
#include "stdio.h"
#include <cstring>
#include <cmath>
#include "vector"
#include "stack"
// B1006 output Z in changed regular
void B1006()
{
	int N;
	scanf("%d", &N);
	int B = N / 100;
	int S = N/10-B*10;
	int G = N %10;
	for (int i = 0; i < B; i++)
		printf("B");
	for (int i = 0; i < S; i++)
		printf("S");
	for (int i = 0; i < G; i++)
		printf("%d", i+1);


}
//B1021 number of G digit stastics
void B1021()
{
	int N;
	int temp;
	int index;
	double divisor;
	int a[10] = { 0 };
	scanf("%d", &N);
	int tempN = N;
	int digitN=0;
	do {
		tempN = tempN / 10;
		digitN++;
	} while (tempN != 0);
	
	for (int i = 1; i <= digitN; i++)
	{
		divisor= pow(10, i);
		temp = N % (int)divisor;
		index = temp / (divisor / 10);
		a[index]++;
	}
	for (int i = 0; i < 10; i++)
	{
		if (a[i] != 0)
			printf("%d:%d\n", i, a[i]);
	}
}
//B1031 check identity Card
void B1031()
{
	int Weight[17] = { 7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2 };
	char M[11] = { '1','0','X','9','8','7','6','5','4','3','2' };
	int N;
	scanf("%d", &N);
	vector<char*> vec;
	int notregularN = 0;
	for (int i = 0; i < N; i++)
	{
		char* str = new char[20];
		//char str[20];
		int W=0;
		//char flag;
		int index;
		scanf("%s", str);
		int j;
		for ( j = 0; j < 17; j++)
		{
			if (str[j] > '9' || str[j] < '0') break;
			W += (str[j]-'0') * Weight[j];
		}
		if (j < 17) {
			//exit no-digit
			notregularN++;
			vec.push_back(str);
		}
		else
		{
			index = W % 11;
			if (M[index] != str[17])
			{
				notregularN++;
				vec.push_back(str);
			}
		}

	}
	printf("\n");
	if (notregularN == 0)
		printf("All passesd");
	else
	{
		//printf("%d", notregularN);
		for (int i = 0; i < vec.size(); i++)
		{
			printf("%s\n", vec[i]);
			delete[] vec[i];
		}
	}

}
//B1002 Write this number
void B1002()
{
	char PY[10][5]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
	char str[101];
	//getchar();
	gets_s(str);
	int len = strlen(str);
	int ntemp;
	int sum = 0;
	for (int i = 0; i < len; i++)
	{
		ntemp = str[i] - '0';
		sum+=ntemp;
	}
	bool firstZero = true;
	
		int B = sum / 100;
		if (B == 0) ;
		else
		{
			firstZero = false;
			printf("%s ", PY[B]);
		}
		int S = (sum - B * 100) / 10;
		if (S == 0 && firstZero == false) printf("%s ",PY[S]);
		else  if(S!=0) printf("%s ", PY[S]);
		int G = sum % 10;
		if (G == 0 && firstZero == false) printf("%s", PY[G]);
		else if(G!=0) printf("%s", PY[G]);
	
}
//B1009 Say irony
void B1009()
{
	//char str[80];
	//gets_s(str);
	//int n = strlen(str);
	//int wordN = 0;
	//for (int i = 0; i < n; i++)
	//{
	//	if (str[i] == ' ') wordN++;
	//}
	//wordN++;
	////string* Str = new string[wordN];
	//stack<char*> Mystack;
	//for (int i = 0; i < n; i++)
	//{
	//	char* ss = new char[15];
	//	ss[i] = str[i];
	//	if (str[i] == ' ' || i == n - 1) Mystack.push(ss);
	//}
	//while (!Mystack.empty())
	//{
	//	printf("%s", Mystack.top());
	//	delete[] Mystack.top();
	//	Mystack.pop();
	//	if (Mystack.size()!=1)
	//	{
	//		printf(" ");
	//	}
	//}

	char str[90];
	gets_s(str);
	int len = strlen(str), r = 0, h = 0;
	//int num = 0;
	char ans[90][90];
	for (int i = 0; i < len; i++)
	{
		if (str[i] != ' ')ans[r][h++] = str[i];
		else
		{
			r++;
			h = 0;
			ans[r][h] = '\0';
		}
	}
	for (int i = r; i >= 0; i--)
	{
		printf("%s", ans[i]);
		if (i > 0)printf(" ");
	}

}
//B1014 
void B1014()
{
	char Date[7][10] = {
		"MON",
		"TUE",
		"WED",
		"THU",
		"FRI",
		"SAT",
		"SUN"
	};
	char str1[20];
	char str2[20];
	char str3[20];
	char str4[20];
	int dataindex;
	int Hour;
	//scanf("%s %s %s %s", str1, str2, str3, str4);
	gets_s(str1);
	gets_s(str2);
	gets_s(str3);
	gets_s(str4);
	int sametime = 0;
	for (int i = 0; i < strlen(str1); i++)
	{
		if (str1[i] == str2[i]) {
			sametime++;
			if (sametime == 1) {
				dataindex = str1[i] - 'A';
			}
			if (sametime == 2)
			{
				//printf(" %c ", str1[i]);
				if (str1[i] <= '9'&&str1[i] >= '0')
				{
					Hour = str1[i] - '0';
				//	printf("%d", Hour);
				}
				else  if (str1[i] >= 'A') {
					Hour = str1[i] - 'A' + 10;
					//printf("%d", Hour);
				}break;
			}
		}

	}
	int Minute;
	for (int i = 0; i < strlen(str3); i++)
	{
		if (str3[i] == str4[i]) {
			if (str3[i] >= 'a'&&str3[i] <= 'z')
			{
				Minute = i;
				break;
			}
		}
	}

	printf("%s ",Date[dataindex]);
	printf("%d:", Hour);
	if (Minute < 10)printf("0");
	printf("%d", Minute);

}
/*
3458djDkxh4hhGE
2984akDfkkkkggEdsb
s&hgsfdk
d&Hyscvnm
*/
//B1024 科学计数法
void B1024()
{
	char ENumber[20];
	gets_s(ENumber);
	int xishu;
	double D=0;
	if (ENumber[0] == '+' || ENumber[0] == '-')
	{
		if (ENumber[0] == '+') xishu = 1;
		else xishu = -1;

		int i ;
		for (i = 1; i < strlen(ENumber); i++)
		{
			if (ENumber[i] == '.')
			{
				for (int j = i-1; j >= 1; j--)
				{
					D = D+(ENumber[j] - '0')*pow(10, i - j-1);
					//printf("%lf\n", D);
				}
				//printf("%lf\n", D);
				break;
			}
		}
		int j = i+1;
		int index = j - 1;
		for (; ; i++)
		{
			if (ENumber[i] == 'E')
			{
				//printf("jinru\n");
				double Zl;
				for (; j < i; j++)
				{
					//printf("%d ", pow(10, j - index));
					Zl = (ENumber[j] - '0') / pow(10, j - index);
					D = D +Zl;
				}
				//printf("%lf\n", D);
				break;
			}
		}
		//printf("%lf", D);
		int Ex = 1;
		if (ENumber[i + 1] == '+');
		else if (ENumber[i + 1] == '-') Ex=-1;
		int e = 0;
		for (i=i+2; i < strlen(ENumber); i++)
		{
			e = e + (ENumber[i]-'0') * (pow(10, strlen(ENumber) - i-1));
		}
		e = e * Ex;
		D = D * xishu;
		printf("D:%lf\t", D);
		printf("e:%d\t", e);
		printf("%lf",D*pow(10, e));
	}
}
//B1048 数字加密
void reverse(char *s)
{
	int len = strlen(s);
	for (int i = 0; i < len / 2; i++)
	{
		int temp = s[i];
		s[i] = s[len - 1 - i];
		s[len - 1 - i] = temp;
	}
}
void B1048()
{
	char A[100];
	char B[100];
	char ans[100] = {0};
	scanf("%s", A);
	scanf("%s", B);
	int LenA = strlen(A);
	int LenB = strlen(B);
//	printf("A:%s B:%s", A, B);
	//printf("%d %d\n", strlen(A), strlen(B));
	reverse(A);
	reverse(B);
	//printf("%s %s", A, B);
	int len = LenA > LenB ? LenA : LenB;
	for (int i = 0; i < len; i++)
	{
		int numA = i < LenA ? A[i]-'0': 0;
		int numB = i < LenB ? B[i]-'0': 0;
		if (i % 2 == 0)
		{
			int temp = (numA + numB) % 13;
			if (temp == 10) ans[i] = 'J';
			else if (temp == 11) ans[i] = 'Q';
			else if (temp == 12) ans[i] = 'K';
			else ans[i] = temp + '0';
		}
		else
		{
			int temp = numB - numA;
			if (temp < 0)temp = temp + 10;
			ans[i] = temp + '0';
		}
	}
	reverse(ans);
	printf("%s", ans);
}
//A1001 A+B Format
void A1001()
{
	int A, B;
	scanf("%d %d", &A, &B);
	int sum = A + B;
	if (abs(sum) < 1000) printf("%d", sum);
	else
	{
		int temp = abs(sum);
		int r = temp % 1000;
		int l = (temp - r)/1000;
		if (sum < 0) printf("-");
		printf("%d,%d", l, r);

	}

}
//A1005 Spell It Right
void A1005()
{
	char EN[10][8] = { "zero","one","two","three","four","five","six","seven","eight","nine" };
	char num[101];
	gets_s(num);
	int sum=0;
	for (int i = 0; i < strlen(num); i++)
	{
		sum += num[i]-'0';
	}
	printf("sum:%d\n", sum);
	int c = 100;
	while (sum / pow(10, c) < 1)
	{
		c--;
	}

	printf("C: %d\n", c);
	while (c >= 0)
	{
		int temp = sum / pow(10, c);
		if(c!=0) printf("%s ", EN[temp]);
		else printf("%s", EN[temp]);
		sum = sum - temp * pow(10, c);
		c--;
	}
}
//A1035 Password
typedef struct userinfo {
	char account[20];
	char password[20];
	bool ischanged;
}Userinfo;
int just(Userinfo* p, int m)
{
	p->ischanged = false;
	int len = strlen(p->password);
	for (int i = 0; i < len; i++)
	{
		if (p->password[i] == '1') {
			p->password[i] = '@';
			p->ischanged = true;
		}
		else if (p->password[i] == '0')
		{
			p->password[i] = '%';
			p->ischanged = true;
		}
		else if (p->password[i] == 'l')
		{
			p->password[i] = 'L';
			p->ischanged = true;
		}
		else if (p->password[i] == 'O')
		{
			p->password[i] = 'o';
			p->ischanged = true;
		}
	}
	if (p->ischanged == true) return m + 1;
	else return m;
}
void A1035()
{
	
	int N;
	scanf("%d",&N);
	Userinfo* ptr = new Userinfo[N];
	int M = 0;
	for (int i = 0; i < N; i++)
	{
		scanf("%s", ptr[i].account);
		scanf("%s", ptr[i].password);
		M=just(&ptr[i], M);
	}
	if (M == 0)
		printf("There are %d accounts and no account is modified", N);
	else
	{
		printf("%d\n", M);
		for (int i = 0; i < N; i++)
		{
			if (ptr[i].ischanged == true)
			{
				printf("%s ", ptr[i].account);
				printf("%s\n", ptr[i].password);
			}
		}
	}
	delete[] ptr;

}
//A1077 Kuchiguse
void A1077()
{
	int N;
	scanf("%d", &N);
	getchar();//\n
	char str[100][40];
	int minlen = 256;
	for (int i = 0; i < N; i++)
	{
		gets_s(str[i]);//因为输入含空格
		if (strlen(str[i]) < minlen) minlen = strlen(str[i]);
		//scanf("%s",)
		reverse(str[i]);
	}
	int samelength = 0;
	for (int i = 0; i < minlen; i++)
	{
		char c = str[0][i];
		bool same = true;
		for (int j = 1; j < N; j++)
		{
			if (c != str[j][i])
			{
				same = false;
				break;
			}
		}
		if (same) samelength++;
		else break;
	}
	if (samelength >= 1)
	{
		for (int i = samelength - 1; i >= 0; i--)
		{
			printf("%c", str[0][i]);
		}
	}
	else
	{
		printf("nai");
	}
	
}
//A1082 Read Number in Chinese
void A1082()
{  
	char num[10][15] = {
		"ling","yi","er","san","si","wu","liu","qi","ba","jiu"
	};
	char wei[5][5] = {
		"Shi","Bai","Qian","Wan","Yi"
	};
	char str[15];
	gets_s(str);
	int len = strlen(str);
	int left = 0, right = len - 1;
	if (str[0] == '-')
	{
		printf("Fu");
		left++;
	}
	while (left + 4 <= right)
	{
		right -= 4;
	}
	while (left < len)
	{
		bool flag = false;
		bool isPrint = false;
		while (left <= right)
		{
			if (left > 0 && str[left] == '0')
				flag = true;
			else
			{
				if (flag == true) {
					printf(" ling");
					flag = false;
				}
				if (left > 0) printf(" ");
				printf("%s", num[str[left] - '0']);
				isPrint = true;
				if (left != right)
					printf(" %s", wei[right - left - 1]);

			}
			left++;
		}
		//left++;
		if (isPrint == true && right != len - 1)
		{
			printf(" %s", wei[(len - 1 - right) / 4 + 2]);
		}
		right += 4;
	
	}
		


}