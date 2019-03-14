// CountingSortDemo.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <iostream>
#include <vector>


using namespace std;

/*
计数排序; 以出现的总数对数据排序；
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
	
	//空间换时间
	vector<int> lstCount(intN, 0);
	
	for (int i = 0; i < intN; i++)
	{
		lstCount[lstData[i]] = lstCount[lstData[i]] + 1;
	}

	//还原数据
	lstData.clear();

	for (int i = 0; i < intN; i++)
	{
		for (int j = 0; j < lstCount[i]; j++)
		{
			lstData.push_back(i);
		}
	}

	//输出结果
	cout << "Output: ";
	for (int i = 0; i < intN; i++)
	{
		cout << lstData[i] << " ";
	}
	cout << endl;

	cin >> intN;

	return 0;
}

