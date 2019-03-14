// TopKDemo.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

#include <iostream>

#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

/*
Top K���⣺����һϵ�����������K�����֣�

�ѣ�������ȫ��������Ĭ���Ǵ󶥶ѣ�ÿ���ڵ��ֵ����С�������ӽڵ��ֵ��
*/

//�㷨��ƣ�ʹ��С���� O(N*lgK)��
//�����㷨�����������ݽ��п�������ȡǰ��K��Ԫ�أ�O(N*lgN)����N��K��ܶ࣬���Բ��������㷨��
void TopKAlg(vector<int> &lstInput, int intN, int intK)
{
	//1��ȡǰ��K��Ԫ�ؽ�����ѡ����������С����
	vector<int> lstOutput(lstInput.begin(), lstInput.begin()+intK);
	make_heap(lstOutput.begin(), lstOutput.end(), greater<int>());	//O(lgK)

	//2���ж�[K, N]�����ÿ��Ԫ���Ƿ���ڶѶ���ֵ(������С��ֵ)��������ڣ����滻�Ѷ���ֵ��Ȼ�����½���
	for (int i = intK; i < intN; i++)
	{
		if (lstInput[i] > lstOutput[0])
		{
			//���K�Ƚ�С�����
			//lstOutput[0] = lstInput[i];
			//make_heap(lstOutput.begin(), lstOutput.end(), greater<int>());   //O(lgK) �������lg������2Ϊ��

			//���K�Ƚϴ�����
			lstOutput.push_back(lstInput[i]);	//O(1)
			push_heap(lstOutput.begin(), lstOutput.end(), greater<int>());  //���	//O(1)
			pop_heap(lstOutput.begin(), lstOutput.end(), greater<int>());	//����	//O(1)
			lstOutput.pop_back();	//O(1)
		}
	}

	//��ӡ���
	cout << "Output: \n";
	sort_heap(lstOutput.begin(), lstOutput.end(), greater<int>());	//������֮�����������Ƕ�
	for (auto itor = lstOutput.begin(); itor != lstOutput.end(); itor++)
	{
		printf("%d\n", *itor);
	}
}


int main()
{
	//׼������
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

