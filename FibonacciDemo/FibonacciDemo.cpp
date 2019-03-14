// FibonacciDemo.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <iostream>
#include <vector>

using namespace std;


/*
斐波那契数列(从第三项开始每次元素是前两个元素之和，每次元素大概是前一个元素的1.618倍)：求第N个斐波那契数列的值；

算法：正推法、通项公式法、查表法
*/

int main()
{
	//查表法
	vector<__int64> lstData;
	int intN = 100;

	lstData.push_back(0);
	lstData.push_back(1);

	for (int i = 2; i < intN; i++)
	{
		lstData.push_back(lstData[i - 1] + lstData[i - 2]);
	}

	//查询第80个值
	cout << "Output: " << lstData[80 - 1] << endl;

    return 0;
}

