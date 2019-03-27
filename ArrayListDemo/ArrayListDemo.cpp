// ArrayListDemo.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <vector>

#include "ArrayList.h"

#include <algorithm>

using namespace std;

int main()
{
	vector<int> lstInt{1, 2, 3, 4, 5};
	int i1 = distance(lstInt.end(), lstInt.begin());	//-5
	int i3 = lstInt.begin() - lstInt.end();	//-5

	int i2 = distance(lstInt.begin(), lstInt.end());	//5
	int i4 = lstInt.end() - lstInt.begin();	//5

	ArrayList<int> lst(10);

	for (int i = 0; i < 100; i++)
	{
		lst << rand() % 100;
	}
	cout << lst;

	int i5 = distance(lst.end(), lst.begin());
	int i6 = lst.begin() - lst.end();

	int i7 = distance(lst.begin(), lst.end());
	int i8 = lst.end() - lst.begin();

	auto iter1 = 5 + lst.begin();
	auto iter2 = 5 - lst.end();

	//调用sort算法
	sort(lst.begin(), lst.end());
	cout << lst;
	
	//调用find算法
	ArrayList<int>::iterator findIter = find(lst.begin(), lst.end(), 22);
	if (findIter != lst.end())
	{
		int i = findIter - lst.begin();	//随机迭代器相减等于索引
		lst.erase(i);
	}
	
	//调用count算法
	int cnt = count(lst.begin(), lst.end(), 23);

	//使用自定义仿函数MySum
	int intSum = for_each(lst.begin(), lst.end(), MySum<int>());

	//调用自定义算法my_unique
	ArrayList<int>::iterator fwIter = my_unique(lst.begin(), lst.end());
	if (fwIter != lst.end())
	{
		lst.erase(fwIter, lst.end());
	}
	cout << lst;

	int i = 0;
	cin >> i;

    return 0;
}

