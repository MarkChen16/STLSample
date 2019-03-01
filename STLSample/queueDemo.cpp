
#include "stdafx.h"
#include "queueDemo.h"

void queueDemo()
{
	//queue�����������÷�========================================
	queue<int> q1;	//����һ���յĶ��У�����deque<int>
	queue<int, list<int>> q2;	//����һ���յĶ��У�����list<int>

	q1.push(1);
	q1.push(2);
	q1.push(3);
	q1.push(4);
	q1.push(5);
	q1.push(6);

	q2.push(1);	//����push_back���ں������Ԫ��
	q2.front();	//���е�һ��Ԫ��
	q2.back();	//�������һ��Ԫ��
	q2.pop();	//����pop_front����ǰ��ɾ��Ԫ��

	cout<<"q1: ";
	while(!q1.empty())
	{
		cout<<q1.front()<<" ";

		q1.pop();
	}
	cout<<endl;

	cin.get();
}
