// HeapSortDemo.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <iostream>

#include <vector>

#include <algorithm>

using namespace std;

/*
堆排序：利用自平衡二叉树排序
时间复杂度：O(N*lgN)

堆的查找、增加和删除的时间复杂度都是O(lgN)
*/

int main()
{
	vector<int> lstData{3, 25, 66, 227, 743, 54, 93, 325, 75, 32, 89, 92, 7, 42, 24, 63, 97};

	make_heap(lstData.begin(), lstData.end());	//创建堆

	sort_heap(lstData.begin(), lstData.end());	//堆排序

	//输出显示
	for (auto itor = lstData.begin(); itor != lstData.end(); itor++)
	{
		cout << *itor << " ";
	}
	cout << endl;

    return 0;
}

