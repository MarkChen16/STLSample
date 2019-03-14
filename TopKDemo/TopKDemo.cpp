// TopKDemo.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <iostream>

#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

/*
Top K问题：计算一系列数据中最大K个数字；

堆：堆是完全二叉树，默认是大顶堆，每个节点的值均不小于左右子节点的值；
*/

//算法设计：使用小顶堆 O(N*lgK)，
//常规算法：对所有数据进行快速排序取前面K个元素，O(N*lgN)，但N比K大很多，所以不是最优算法；
void TopKAlg(vector<int> &lstInput, int intN, int intK)
{
	//1、取前面K个元素建立候选名单，构造小顶堆
	vector<int> lstOutput(lstInput.begin(), lstInput.begin()+intK);
	make_heap(lstOutput.begin(), lstOutput.end(), greater<int>());	//O(lgK)

	//2、判断[K, N]区间的每个元素是否大于堆顶的值(堆中最小的值)，如果大于，则替换堆顶的值，然后重新建堆
	for (int i = intK; i < intN; i++)
	{
		if (lstInput[i] > lstOutput[0])
		{
			//如果K比较小的情况
			//lstOutput[0] = lstInput[i];
			//make_heap(lstOutput.begin(), lstOutput.end(), greater<int>());   //O(lgK) 计算机中lg函数以2为底

			//如果K比较大的情况
			lstOutput.push_back(lstInput[i]);	//O(1)
			push_heap(lstOutput.begin(), lstOutput.end(), greater<int>());  //入堆	//O(1)
			pop_heap(lstOutput.begin(), lstOutput.end(), greater<int>());	//出堆	//O(1)
			lstOutput.pop_back();	//O(1)
		}
	}

	//打印结果
	cout << "Output: \n";
	sort_heap(lstOutput.begin(), lstOutput.end(), greater<int>());	//堆排序之后，容器不再是堆
	for (auto itor = lstOutput.begin(); itor != lstOutput.end(); itor++)
	{
		printf("%d\n", *itor);
	}
}


int main()
{
	//准备数据
	vector<int> lstData;
	int intN = 100000, intK = 10;

	srand(1);

	for (int i = 0; i < intN; i++)
	{
		//lstData.push_back(rand() % intN);
		lstData.push_back(i);
	}

	TopKAlg(lstData, intN, intK);

	cin >> intN;

    return 0;
}

