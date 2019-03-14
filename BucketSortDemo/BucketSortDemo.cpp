// BucketSortDemo.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

#include <iostream>
#include <vector>


using namespace std;

/*
Ͱ����; ��ƽ���ֲ��ķ�ʽ����������
���Ӷȣ�O(n)
*/


int main()
{
	//׼������
	vector<int> lstData;
	int intN = 100;

	for (int i = 0; i < intN; i++)
	{
		lstData.push_back(rand() % intN);
	}

	//׼��ʮ��Ͱ��[0-9] [10-19] [20-29] ...
	vector<int> lstBucket[10];

	for (int i = 0; i < intN; i++)
	{
		int index = lstData[i] / 10;

		lstBucket[index].push_back(lstData[i]);
	}

	//������
	for (int i= 0; i < 10; i++)
	{
		printf("%d Bucket: ", i);
		for (auto itor = lstBucket[i].begin(); itor < lstBucket[i].end(); itor++)
		{
			cout << *itor << " ";
		}
		cout << endl;
	}

	cin >> intN;

    return 0;
}

