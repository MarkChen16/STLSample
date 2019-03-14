// CountingSortDemo.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

#include <iostream>
#include <vector>


using namespace std;

/*
��������; �Գ��ֵ���������������
���Ӷȣ�O(n)
*/

int main()
{
	//׼������
	vector<int> lstData;
	int intN = 100;

	for (int i = 0; i < intN; i++)
	{
		lstData.push_back(rand() % intN);
	}
	
	//�ռ任ʱ��
	vector<int> lstCount(intN, 0);
	
	for (int i = 0; i < intN; i++)
	{
		lstCount[lstData[i]] = lstCount[lstData[i]] + 1;
	}

	//��ԭ����
	lstData.clear();

	for (int i = 0; i < intN; i++)
	{
		for (int j = 0; j < lstCount[i]; j++)
		{
			lstData.push_back(i);
		}
	}

	//������
	cout << "Output: ";
	for (int i = 0; i < intN; i++)
	{
		cout << lstData[i] << " ";
	}
	cout << endl;

	cin >> intN;

	return 0;
}

