// ArrayListDemo.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "ArrayList.h"

#include <algorithm>

using namespace std;

int main()
{
	ArrayList<int> lst;

	for (int i = 0; i < 20; i++)
	{
		lst << rand() % 100;
	}

	cout << lst;

	//调用STL算法
	sort(lst.begin(), lst.end());
	cout << lst;
	
	ArrayList<int>::iterator iter = find(lst.begin(), lst.end(), 22);

	int cnt = count(lst.begin(), lst.end(), 23);

	int intSum = for_each(lst.begin(), lst.end(), MySum<int>());

	//调用自己的算法
	ArrayList<int>::iterator fwIter = my_unique(lst.begin(), lst.end());
	lst.erase(fwIter, lst.end());

	cout << lst;

    return 0;
}

