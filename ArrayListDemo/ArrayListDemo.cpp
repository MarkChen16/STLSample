// ArrayListDemo.cpp : �������̨Ӧ�ó������ڵ㡣
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

	//����STL�㷨
	sort(lst.begin(), lst.end());
	cout << lst;
	
	ArrayList<int>::iterator iter = find(lst.begin(), lst.end(), 22);

	int cnt = count(lst.begin(), lst.end(), 23);

	int intSum = for_each(lst.begin(), lst.end(), MySum<int>());

	//�����Լ����㷨
	ArrayList<int>::iterator fwIter = my_unique(lst.begin(), lst.end());
	lst.erase(fwIter, lst.end());

	cout << lst;

    return 0;
}

