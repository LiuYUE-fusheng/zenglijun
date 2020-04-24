#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
using namespace std;
FILE* fp;//输出到文件
int re_ten();//产生10以内的整数
float fl_ten();//产生10以内浮点数
int re_hundred();//产生100以内整数
float fl_hundred();//产生100以内浮点数
int symbol();//代表加减乘除四个符号
//四则运算应用户要求调用函数
void display_single_int(int n,int rang,int add,int sub,int mul,int div,int way);
void display_single_float(int n,int rang,int add,int sub,int mul,int div,int way);
void display_brackte1(int n,int rang,int add,int sub,int mul,int div,int way);
void display_brackte2(int n,int rang,int add,int sub,int mul,int div,int way);
int main()
{
    int n,intger,brackets;//定制题目数量,整数或小数的方式,括号
    int add,sub,mul,div;//输入加减乘除的符号
    int way;//是否需要输出到文件里
    int rang;//算式范围
    printf("小学四则运算\n");
    printf("请定制题目数量：\n");
    cin>>n;
    printf("请设置最大数(0为10,1为100)\n");
    cin>>rang;
    printf("是否需要'+'(1为需要,0为不需)\n");
    cin>>add;
    printf("是否需要'-'(1为需要,0为不需)\n");
    cin>>sub;
    printf("是否需要'*'(1为需要,0为不需)\n");
    cin>>mul;
    printf("是否需要'/'(1为需要,0为不需)\n");
    cin>>div;
    printf("数字类型(1为整数,0为浮点数)\n");
    cin>>intger;
    printf("算式是否包括括号(1为需要,0为不需)\n");
    cin>>brackets;
    printf("是否需要输出到文件(1为需要,0为不需)\n");
    cin>>way;
    if(intger==1)
    {//整数
        switch(brackets)//括号出现的情况
        {
        case 1:
            display_brackte1(n,rang,add,sub,mul,div,way);
            break;
        case 0:
            display_single_int(n,rang,add,sub,mul,div,way);
            break;
        }

    }
    if(intger==0)
    {//要求浮点数出现
        switch(brackets)
        {
        case 1:
            display_brackte2(n,rang,add,sub,mul,div,way);
            break;
        case 0:
            display_single_float(n,rang,add,sub,mul,div,way);
            break;
        }
    }
    return 0;
}

//产生0~10的随机数
int re_ten()
{
    int a;
   // srand((unsigned)time(NULL));
    a = rand() % 11;
    return a;
}
//产生0~100的随机数
int re_hundred()
{
    int a;
    //srand((unsigned)time(NULL));
    a = rand() % 101;
    return a;
}
//产生0~10的随机浮点数
float fl_ten()
{
    float x,a=0.5,b=10.1;
    x=(rand()%10001)/10000.0;
    x=x*(b-a)+a;
    return x;
}

float fl_hundred()
{
    float a=0.5,b=100.1;
    float x;
    x=(rand()%101)/100.0;
    x=x*(b-a)+a;
    return x;

}
//产生1到4代表加减乘除
int symbol()
{
    int a,b;
    //srand((unsigned)time(NULL));
    a = rand() % 100;
    b=a/25;
    b++;
    return b;
}
//整数+单一运算
void display_single_int(int n,int rang,int add,int sub,int mul,int div,int way)
{
    int a,b,c,i;
    srand(time(0));//根据系统时间设置随机数种子
    fp = fopen("D:\\text.txt", "w");
    for(i=0;i<n;i++)
    {
          c=symbol();
          if(rang==0)
          {
              a=re_ten();
              b=re_ten();
          }
          if(rang==1)
          {//产生0-100的整数
              a=re_hundred();
              b=re_hundred();
          }
        if(add==1&&c==1)//允许加号出现
        {
            cout<<a<<"+"<<b<<"="<<endl;
            if(way==1)
            {
              if ((fp = fopen("D:\\text.txt", "a")) == NULL)
			  {//输入文件失败
				 printf("error！\n");
				 exit(0);
              }
              else
              {
                  fprintf(fp,"%d+%d=\n",a,b);
              }
            }
        }
        if(sub==1&&c==2)
        {
            if(a>b)
            {
                cout<<a<<"-"<<b<<"="<<endl;
                if(way==1)
            {
              if ((fp = fopen("D:\\text.txt", "a")) == NULL)
			  {
				 printf("error！\n");
				 exit(0);
              }
              else
              {
                  fprintf(fp,"%d-%d=\n",a,b);
              }
            }
            }
            else
            {
                cout<<b<<"-"<<a<<"="<<endl;
                if(way==1)
            {//用户要求输出到文件里
              if ((fp = fopen("D:\\text.txt", "a")) == NULL)
			  {
				 printf("error！\n");
				 exit(0);
              }
              else
              {
                  fprintf(fp,"%d+%d=\n",b,a);
              }
            }
            }
        }
        if(mul==1&&c==3)
        {
            cout<<a<<"*"<<b<<"="<<endl;
            if(way==1)
            {
              if ((fp = fopen("D:\\text.txt", "a")) == NULL)
			  {
				 printf("error！\n");
				 exit(0);
              }
              else
              {
                  fprintf(fp,"%d*%d=\n",a,b);
              }
            }
        }
        if(div==1&&c==4)
        {
             cout<<a<<"/"<<b<<"="<<endl;
             if(way==1)
            {
              if ((fp = fopen("D:\\text.txt", "a")) == NULL)
			  {
				 printf("error！\n");
				 exit(0);
              }
              else
              {
                  fprintf(fp,"%d/%d=\n",a,b);
              }
            }
        }

    }

}

//浮点数+单一运算时
void display_single_float(int n,int rang,int add,int sub,int mul,int div,int way)
{
    int c,i;
    float a,b;
    srand(time(0));//根据系统时间设置随机数种子
    fp = fopen("D:\\text.txt", "w");
    for(i=0;i<n;i++)
    {
          c=symbol();
          if(rang==0)
          {
              a=fl_ten();
              b=fl_ten();
          }
          if(rang==1)
          {
              a=re_hundred();
              b=re_hundred();
          }
        if(add==1&&c==1)
        {
            printf("%.2f+%.2f=\n",a,b);
            if(way==1)
            {
              if ((fp = fopen("D:\\text.txt", "a")) == NULL)
			  {
				 printf("error！\n");
				 exit(0);
              }
              else
              {
                  fprintf(fp,"%.2f+%.2f=\n",a,b);
              }
            }
        }
        if(sub==1&&c==2)
        {
            if(a>b)
            {
               printf("%.2f-%.2f=\n",a,b);
                if(way==1)
               {
                   if ((fp = fopen("D:\\text.txt", "a")) == NULL)
			      {
				    printf("error！\n");
				    exit(0);
                  }
                   else
                  {
                  fprintf(fp,"%.2f-%.2f=\n",a,b);
                  }
               }
            }
            else
            {
                printf("%.2f-%.2f=\n",b,a);
                if(way==1)
               {
                   if ((fp = fopen("D:\\text.txt", "a")) == NULL)
			      {
				     printf("error！\n");
				     exit(0);
                  }
                   else
                  {
                     fprintf(fp,"%.1f-%.1f=\n",b,a);
                  }
               }
            }
        }
        if(mul==1&&c==3)
        {
            printf("%.2f*%.2f=\n",a,b);
            if(way==1)
            {
              if ((fp = fopen("D:\\text.txt", "a")) == NULL)
			  {
				 printf("error！\n");
				 exit(0);
              }
              else
              {
                  fprintf(fp,"%.2f*%.2f=\n",a,b);
              }
            }
        }
        if(div==1&&c==4)
        {
             printf("%.2f/%.2f=\n",a,b);
             if(way==1)
            {
              if ((fp = fopen("D:\\text.txt", "a")) == NULL)
			  {
				 printf("error！\n");
				 exit(0);
              }
              else
              {
                  fprintf(fp,"%.2f/%.2f=\n",a,b);
              }
            }
        }

    }

}
//整数+括号运算式子
void display_brackte1(int n,int rang,int add,int sub,int mul,int div,int way)
{
    srand(time(0));//根据系统时间设置随机数种子
    fp = fopen("D:\\text.txt", "w");
    int a,b,c,d,c1;
    for(int i=0;i<n;i++)
    {
         c=symbol();//1到4随机函数
         if(rang==0)
          {
              a=re_ten();
              b=re_ten();
              d=re_ten();
          }
         if(rang==1)
          {
              a=re_hundred();
              b=re_hundred();
              d=re_hundred();
          }
          if(add==1&&c==1)
          {
              c1=symbol();
              if(sub==1&&c1==2)
              {
                  printf("%d-(%d+%d)\n",d,a,b);
                  if(way==1)
                  {
                      fprintf(fp,"%d-(%d+%d)\n",d,a,b);
                  }

              }
              if(mul==1&&c1==3)
              {
                  printf("%d*(%d+%d)\n",d,a,b);
                  if(way==1)
                  {
                      fprintf(fp,"%d*(%d+%d)\n",d,a,b);
                  }

              }
               if(div==1&&c1==4)
              {
                  printf("(%d+%d)/%d\n",a,b,d);
                  if(way==1)
                  {
                      fprintf(fp,"%d+%d)/%d\n",a,b,d);
                  }

              }
          }
          if(sub==1&&c==2)
          {
              c1=symbol();
              if(add==1&&c1==1)
              {
                  printf("%d-(%d+%d)\n",d,a,b);
                  if(way==1)
                  {
                      fprintf(fp,"%d-(%d+%d)\n",d,a,b);
                  }
              }
              if(mul==1&&c1==3)
              {
                  printf("%d*(%d-%d)\n",d,a,b);
                  if(way==1)
                  {
                      fprintf(fp,"%d*(%d-%d)\n",d,a,b);
                  }
              }
               if(div==1&&c1==4)
              {
                  printf("(%d-%d)/%d\n",a,b,d);
                  if(way==1)
                  {
                      fprintf(fp,"(%d-%d)/%d\n",a,b,d);
                  }
              }
          }
          if(mul==1&&c==3)
          {
              c1=symbol();
              if(add==1&&c1==1)
              {
                  printf("(%d+%d)/%d\n",a,b,d);
                  if(way==1)
                  {
                      fprintf(fp,"(%d+%d)/%d\n",a,b,d);
                  }
              }
              if(sub==1&&c1==2)
              {
                  printf("%d/(%d-%d)\n",d,a,b);
                  if(way==1)
                  {
                      fprintf(fp,"%d/(%d-%d)\n",d,a,b);
                  }
              }
              if(div==1&&c1==4)
              {
                  printf("%d*(%d/%d)\n",d,a,b);
                  if(way==1)
                  {
                      fprintf(fp,"%d*(%d/%d)\n",d,a,b);
                  }

              }

          }
          if(div==1&&c==4)
          {
              c1=symbol();
              if(add==1&&c1==1)
              {
                  printf("(%d+%d)/%d\n",a,b,d);
                  if(way==1)
                  {
                      fprintf(fp,"(%d+%d)/%d\n",a,b,d);
                  }
              }
              if(sub==1&&c1==2)
              {
                  printf("%d/(%d-%d)\n",d,a,b);
                  if(way==1)
                  {
                      fprintf(fp,"%d/(%d-%d)\n",d,a,b);
                  }
              }
              if(mul==1&&c1==3)
              {
                  printf("(%d*%d)/%d\n",a,b,d);
                  if(way==1)
                  {
                      fprintf(fp,"(%d*%d)/%d\n",a,b,d);
                  }
              }
          }
    }
}
//浮点数+括号
void display_brackte2(int n,int rang,int add,int sub,int mul,int div,int way)
{
    srand(time(0));//根据系统时间设置随机数种子
    fp = fopen("D:\\text.txt", "w");
    int c,c1,i;
    float a,b,d;
    for(i=0;i<n;i++)
    {
         c=symbol();//1到4随机函数
         if(rang==0)
          {
              a=fl_ten();
              b=fl_ten();
              d=fl_ten();
          }
         if(rang==1)
          {
              a=fl_hundred();
              b=fl_hundred();
              d=fl_hundred();
          }
          if(add==1&&c==1)
          {
              c1=symbol();
              if(sub==1&&c1==2)
              {
                  printf("%.2f-(%.2f+%.2f)\n",d,a,b);
                  if(way==1)
                  {
                      fprintf(fp,"%.2f-(%.2f+%.2f)\n",d,a,b);
                  }

              }
              if(mul==1&&c1==3)
              {
                  printf("%.2f*(%.2f+%.2f)\n",d,a,b);
                  if(way==1)
                  {
                      fprintf(fp,"%.2f*(%.2f+%.2f)\n",d,a,b);
                  }

              }
               if(div==1&&c1==4)
              {
                  printf("(%.2f+%.2f)/%.2f\n",a,b,d);
                  if(way==1)
                  {
                      fprintf(fp,"%.2f+%.2f)/%.2f\n",a,b,d);
                  }

              }
          }
          if(sub==1&&c==2)
          {
              c1=symbol();
              if(add==1&&c1==1)
              {
                  printf("%.2f-(%.2f+%.2f)\n",d,a,b);
                  if(way==1)
                  {
                      fprintf(fp,"%.2f-(%.2f+%.2f)\n",d,a,b);
                  }
              }
              if(mul==1&&c1==3)
              {
                  printf("%.2f*(%.2f-%.2f)\n",d,a,b);
                  if(way==1)
                  {
                      fprintf(fp,"%.2f*(%.2f-%.2f)\n",d,a,b);
                  }
              }
               if(div==1&&c1==4)
              {
                  printf("(%.2f-%.2f)/%.2f\n",a,b,d);
                  if(way==1)
                  {
                      fprintf(fp,"(%.2f-%.2f)/%.2f\n",a,b,d);
                  }
              }
          }
          if(mul==1&&c==3)
          {
              c1=symbol();
              if(add==1&&c1==1)
              {
                  printf("(%.2f+%.2f)/%.2f\n",a,b,d);
                  if(way==1)
                  {
                      fprintf(fp,"(%.2f+%.2f)/%.2f\n",a,b,d);
                  }
              }
              if(sub==1&&c1==2)
              {
                  printf("%.2f/(%.2f-%.2f)\n",d,a,b);
                  if(way==1)
                  {
                      fprintf(fp,"%.2f/(%.2f-%.2f)\n",d,a,b);
                  }
              }
              if(div==1&&c1==4)
              {
                  printf("%.2f*(%.2f/%.2f)\n",d,a,b);
                  if(way==1)
                  {
                      fprintf(fp,"%.2f*(%.2f/%.2f)\n",d,a,b);
                  }

              }

          }
          if(div==1&&c==4)
          {
              c1=symbol();
              if(add==1&&c1==1)
              {
                  printf("(%.2f+%.2f)/%.2f\n",a,b,d);
                  if(way==1)
                  {
                      fprintf(fp,"(%.2f+%.2f)/%.2f\n",a,b,d);
                  }
              }
              if(sub==1&&c1==2)
              {
                  printf("%.2f/(%.2f-%.2f)\n",d,a,b);
                  if(way==1)
                  {
                      fprintf(fp,"%.2f/(%.2f-%.2f)\n",d,a,b);
                  }
              }
              if(mul==1&&c1==3)
              {
                  printf("(%.2f*%.2f)/%.2f\n",a,b,d);
                  if(way==1)
                  {
                      fprintf(fp,"(%.2f*%.2f)/%.2f\n",a,b,d);
                  }
              }
          }
    }
}
