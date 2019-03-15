// BubbleSortDemo.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

/*
冒泡排序：O(N*N)


*/

void BubbleSort(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - i - 1; j++)	//size - i - 1 每次循环次数减少一个
		{
			//大的数值往后移
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

	printf("未进行排序之前：");
	for (i = 0; i<9; i++)
	{
		printf("%d  ", arr[i]);
	}
	printf("\n");

	BubbleSort(arr, sz);

	printf("进行排序之后：");
	for (i = 0; i<9; i++)
	{
		printf("%d  ", arr[i]);
	}
	printf("\n");

	return 0;
}

