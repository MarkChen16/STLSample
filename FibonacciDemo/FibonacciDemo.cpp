// FibonacciDemo.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

#include <iostream>
#include <vector>

using namespace std;


/*
쳲���������(�ӵ����ʼÿ��Ԫ����ǰ����Ԫ��֮�ͣ�ÿ��Ԫ�ش����ǰһ��Ԫ�ص�1.618��)�����N��쳲��������е�ֵ��

�㷨�����Ʒ���ͨ�ʽ�������
*/

int main()
{
	//���
	vector<__int64> lstData;
	int intN = 100;

	lstData.push_back(0);
	lstData.push_back(1);

	for (int i = 2; i < intN; i++)
	{
		lstData.push_back(lstData[i - 1] + lstData[i - 2]);
	}

	//��ѯ��80��ֵ
	cout << "Output: " << lstData[80 - 1] << endl;

    return 0;
}

