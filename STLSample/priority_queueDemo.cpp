#include "stdafx.h"
#include "priority_queueDemo.h"

void priority_queueDemo()
{
	//priority_queue�����������÷�
	priority_queue<int> pq1;		//����һ���յ����ȶ��У��ڲ��洢Ĭ�ϲ���vector<int>��ʹ��less<int>�ڲ�����
	priority_queue<int, deque<int>, greater<int>> pq2;		//����һ���յ����ȶ��У�����deque<int>�洢������greater<int>�ڲ�����

	pq1.push(4);
	pq1.push(2);
	pq1.push(6);
	pq1.push(7);
	pq1.push(1);
	pq1.push(3);

	pq2.push(1);	//push_back
	pq2.top();		//front
	pq2.pop();		//pop_back

	cout<<"pq1: ";
	while(!pq1.empty())
	{
		cout<<pq1.top()<<" ";		//����������ǰ�����
		pq1.pop();
	}
	cout<<endl;

	cin.get();
}

