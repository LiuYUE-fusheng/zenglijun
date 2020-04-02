#include<iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main()
{
	int arr[10], N;
	int proSum = 0, maxSum = 0;
	cin >> N;
	for (int k = 0; k < N; k++)
	{
		cin >> arr[k];
	}

	for (int i = 0; i < N; i++)
	{

		if (proSum < 0)
			proSum = arr[i];
		else
			proSum = proSum + arr[i];
		if (maxSum < proSum)
			maxSum = proSum;
		cout << "以" << arr[i] << "为右边界的子段和最大和为：" << maxSum << endl;
	}
	if (N < 0)
	{
		cout << "该序列最大值为0" << endl;
	}
	else
	{
		cout << "该序列最大值为" << maxSum << endl;
	}

	return 0;
}
