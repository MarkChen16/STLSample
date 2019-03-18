// HeapSortDemo.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

#include <iostream>

#include <vector>

#include <algorithm>

using namespace std;

/*
������������ƽ�����������
ʱ�临�Ӷȣ�O(N*lgN)

�ѵĲ��ҡ����Ӻ�ɾ����ʱ�临�Ӷȶ���O(lgN)
*/

int main()
{
	vector<int> lstData{3, 25, 66, 227, 743, 54, 93, 325, 75, 32, 89, 92, 7, 42, 24, 63, 97};

	make_heap(lstData.begin(), lstData.end());	//������

	sort_heap(lstData.begin(), lstData.end());	//������

	//�����ʾ
	for (auto itor = lstData.begin(); itor != lstData.end(); itor++)
	{
		cout << *itor << " ";
	}
	cout << endl;

    return 0;
}

