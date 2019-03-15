// QuickSortDemo.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

/*
�������򣺷ֶ���֮��O(N*lgN)

*/

void QuickSort(int arr[], int left, int right)
{
	int i = left;
	int j = right;

	if (i >= j) return;

	//��һ��Ϊ�м���
	int tmp = arr[i];

	while (i < j)
	{
		//��Ļ��Ƶ��ұ�
		while ((arr[j] > tmp) && (i < j))
		{
			j--;
		}
		arr[i] = arr[j];

		//С���Ƶ����
		while ((arr[i] < tmp) && (i < j))
		{
			i++;
		}
		arr[j] = arr[i];
	}

	//��ֵ�м���
	arr[i] = tmp;

	//�м���
	for (int t = 0; t<9; t++)
	{
		printf("%d ", arr[t]);
	}
	printf("\n");

	QuickSort(arr, left, i - 1);	//�ݹ��м�����ߵ�Ԫ��
	QuickSort(arr, j + 1, right);	//�ݹ��м����ұߵ�Ԫ��
}

int main()
{
	int i = 0;
	int arr[9] = { 5, 6, 7, 1, 4, 9, 3, 2, 8 };

	printf("δ����ǰ��");
	for (i = 0; i<9; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	QuickSort(arr, 0, 8);//����Ҫ�������飬i��ֵ��j��ֵ��

	printf("ʵ������֮��");
	for (i = 0; i<9; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}

