// BubbleSortDemo.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

/*
ð������O(N*N)


*/

void BubbleSort(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - i - 1; j++)	//size - i - 1 ÿ��ѭ����������һ��
		{
			//�����ֵ������
			if (arr[j] > arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}

int main()
{
	int i = 0;
	int sz = 0;

	int arr[9] = { 1,6,9,3,2,8,4,5,7 };
	sz = sizeof(arr) / sizeof(arr[1]);

	printf("δ��������֮ǰ��");
	for (i = 0; i<9; i++)
	{
		printf("%d  ", arr[i]);
	}
	printf("\n");

	BubbleSort(arr, sz);

	printf("��������֮��");
	for (i = 0; i<9; i++)
	{
		printf("%d  ", arr[i]);
	}
	printf("\n");

	return 0;
}

