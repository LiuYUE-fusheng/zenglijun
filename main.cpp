#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int arr[10],N;
	int proSum=0,maxSum= 0;
	scanf("%d",&N);
	for(int k=0;k<N;k++)
    {
        scanf("%d",&arr[k]);
    }

	for(int i=0;i<N;i++)
	{

        if(proSum<0)
			proSum = arr[i];
		else
			proSum = proSum+arr[i];
		if(maxSum < proSum)
			maxSum = proSum;
			printf("��%dΪ�ұ߽���Ӷκ����ֵ��%d\n",arr[i],maxSum);
	}
	printf("���������ֵΪ%d\n",maxSum);
	return 0;
}
