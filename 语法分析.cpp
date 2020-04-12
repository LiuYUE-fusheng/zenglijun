#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <string.h>
#include <ctype.h>
using namespace std;

void AVE();
void EVE();
void TVE();
void E1VE();
void T1VE();
void FVE();
void VVE();
char Slice[50],n='1';
char Table[50][3];
int Sign,symbolly;
int List_n=0;
void AVE()
{
	VVE();
	if(Slice[symbolly]==':'&&Slice[symbolly+1]=='=')
	{

		symbolly=symbolly+2;
		EVE();
		printf("%s:=%s",Table[List_n-2],Table[List_n-1]);
		printf("     (:=,%s,-,%s)\n",Table[List_n-1],Table[List_n-2]);
	}
	else
	{
		printf("The assignment Symbol spelling mistakes!\n");
		Sign=1;
		exit(0);
	}
}
void VVE()
{
	if(islower(Slice[symbolly]))
	{
		Table[List_n][0]=Slice[symbolly];
		Table[List_n][1]='\0';
		List_n=List_n+1;
		symbolly=symbolly+1;
	}
	else
	{
		printf("Operand Errors!\n");
		Sign=1;
		exit(0);
	}
}
void EVE()     //E -> TE'
{
	if(Sign==0)
	{
		TVE();
		E1VE();
	}
}
void TVE()
{
	if(Sign==0)
	{
		FVE();
		T1VE();
	}
}
void E1VE()
{
	int pie;
	if(Sign==0)
	{
		if(Slice[symbolly] == '+'||Slice[symbolly]=='-')
		{
			pie=symbolly;
			symbolly=symbolly+1;
			TVE();
			char chr[3];
			chr[0]='T';
			chr[1]=n;
            chr[2]='\0';
            if(Slice[pie]=='+')
            {
                printf("%s:=%s+%s",chr,Table[List_n-2],Table[List_n-1]);                //输出三地址代码
				printf("     (+,%s,%s,%s)\n", Table[List_n-2],Table[List_n-1],chr);             //输出四元式
			}
			else
			{
				printf("%s:=%s-%s",chr,Table[List_n-2],Table[List_n-1]);               //输出三地址代码
				printf("     (-,%s,%s,%s)\n", Table[List_n-2],Table[List_n-1],chr);        //输出四元式
			}
			strcpy(Table[List_n-2],chr);
			n=n+1;
			List_n--;
			E1VE();
        }
	}
}
void T1VE()
{
    int pie;
	if(Sign==0)
	{
		if(Slice[symbolly]=='*'||Slice[symbolly] =='/')
		{
			pie=symbolly;
            symbolly++;
			FVE();
			char chr[3];
			chr[0]='T';
            chr[1]=n;
			chr[2]='\0';
			if(Slice[pie] == '*')
            {
				printf("%s:=%s*%s",chr,Table[List_n-2],Table[List_n-1]);
				printf("     (*,%s,%s,%s)\n", Table[List_n-2],Table[List_n-1],chr);
			}
			else
			{
				printf("%s:=%s/%s",chr,Table[List_n-2],Table[List_n-1]);
				printf("     (/,%s,%s,%s)\n", Table[List_n-2],Table[List_n-1],chr);
			}
            strcpy(Table[List_n-2],chr);
			List_n--;
			n=n+1;
			T1VE();
		}
	}
}
void FVE()
{
	if(Sign==0)
	{
		if(Slice[symbolly]=='(')
		{
			symbolly=symbolly+1;
			EVE();
			if(Slice[symbolly]==')')
                symbolly=symbolly+1;
			else
			{
			    Sign=1;
                printf("ERROR!\n");
                exit(0);
			}
		}
        else if(islower(Slice[symbolly]))
        {
            VVE();
        }
		else
		{
		    Sign=1;
			printf("ERROR!\n");
			exit(0);
		}
	}
}

int main()
{
		Sign = 0;
		symbolly=0;
		scanf("%s",&Slice);
		if(Slice[0] == '\0')
        {
            return 0;
        }
		AVE();
		if(Slice[symbolly]!='\0'&&Sign==0)
		{
			printf("ERROR!\n");
			exit(0);
		}
	return 0;
}
