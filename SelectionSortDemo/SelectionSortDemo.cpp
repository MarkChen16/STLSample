// SelectionSortDemo.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"


/*
ѡ������O(N*N)

*/

template<class T>
void swap(T &a, T &b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

//һ��ѡ��
int indexOfMax(int arr[], int n)
{
	int maxIndex = 0;

	for (int i = 1; i < n; i++)
	{
		if (arr[i] > arr[maxIndex])
		{
			maxIndex = i;
		}
	}

	return maxIndex;
}


void SelectionSort(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		int indexMax = indexOfMax(arr, n - i);
		
		//������ֵ���ں���
		swap(arr[indexMax], arr[n - i - 1]);
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

	SelectionSort(arr, sz);

	printf("��������֮��");
	for (i = 0; i<9; i++)
	{
		printf("%d  ", arr[i]);
	}
	printf("\n");

	return 0;
}

