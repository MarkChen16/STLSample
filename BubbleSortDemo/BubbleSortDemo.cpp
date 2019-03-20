// BubbleSortDemo.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

/*
ð������O(N*N)

*/

template<class T>
void swap(T &a, T &b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

//һ��ð��
void bubble(int arr[], int n)
{
	for (int j = 0; j < n - 1; j++)
	{
		//�����ֵ������
		if (arr[j] > arr[j + 1])
		{
			swap(arr[j], arr[j + 1]);
		}
	}
}

//ð������
void BubbleSort(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		bubble(arr, n - i);
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
