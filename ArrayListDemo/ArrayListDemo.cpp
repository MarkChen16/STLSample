// ArrayListDemo.cpp : �������̨Ӧ�ó������ڵ㡣
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

	//����sort�㷨
	sort(lst.begin(), lst.end());
	cout << lst;
	
	//����find�㷨
	ArrayList<int>::iterator findIter = find(lst.begin(), lst.end(), 22);
	if (findIter != lst.end())
	{
		int i = findIter - lst.begin();	//��������������������
		lst.erase(i);
	}
	
	//����count�㷨
	int cnt = count(lst.begin(), lst.end(), 23);

	//ʹ���Զ���º���MySum
	int intSum = for_each(lst.begin(), lst.end(), MySum<int>());

	//�����Զ����㷨my_unique
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

