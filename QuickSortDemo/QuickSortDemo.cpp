// QuickSortDemo.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

/*
快速排序：分而治之，O(N*lgN)

*/

void QuickSort(int arr[], int left, int right)
{
	int i = left;
	int j = right;

	if (i >= j) return;

	//取第一个为中间数
	int tmp = arr[i];

	while (i < j)
	{
		//大的话移到右边
		while ((arr[j] > tmp) && (i < j))
		{
			j--;
		}
		arr[i] = arr[j];

		//小的移到左边
		while ((arr[i] < tmp) && (i < j))
		{
			i++;
		}
		arr[j] = arr[i];
	}

	//赋值中间数
	arr[i] = tmp;

	QuickSort(arr, left, i - 1);	//递归中间数左边的元素
	QuickSort(arr, j + 1, right);	//递归中间数右边的元素
}

int main()
{
	int i = 0;
	int arr[9] = { 5, 6, 7, 1, 4, 9, 3, 2, 8 };

	printf("未排序前：");
	for (i = 0; i<9; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	QuickSort(arr, 0, 8);//传入要排序数组，i的值和j的值。

	printf("实现排序之后：");
	for (i = 0; i<9; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}

