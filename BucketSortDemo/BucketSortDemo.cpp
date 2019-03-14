// BucketSortDemo.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <iostream>
#include <vector>


using namespace std;

/*
桶排序; 以平均分布的方式对数据排序；
复杂度：O(n)
*/


int main()
{
	//准备数据
	vector<int> lstData;
	int intN = 100;

	for (int i = 0; i < intN; i++)
	{
		lstData.push_back(rand() % intN);
	}

	//准备十个桶，[0-9] [10-19] [20-29] ...
	vector<int> lstBucket[10];

	for (int i = 0; i < intN; i++)
	{
		int index = lstData[i] / 10;

		lstBucket[index].push_back(lstData[i]);
	}

	//输出结果
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

