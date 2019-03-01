#include "stdafx.h"
#include "stackDemo.h"

void stackDemo()
{
	//stackջ���÷�=========================================
	stack<int> s1;		//����һ���յ�ջ��Ĭ��ʹ��deque<int>
	stack<int, list<int>> s2;	//����һ���յ�ջ���ڲ��洢�ṹ����list<int>
	stack<int, vector<int>> s3;	//����һ���յ�ջ���ڲ��洢�ṹ����vector<int>

	s1.push(1);
	s1.push(2);
	s1.push(3);
	s1.push(4);
	s1.push(5);
	s1.push(6);

	s2.push(1);		//����push_back���ں������Ԫ��
	s2.top();		//һ�����������������
	s2.pop();		//����pop_back���ں���ɾ��Ԫ��

	s3.push(1);
	s3.top();
	s3.pop();	

	cout<<"s1: ";
	while(!s1.empty())
	{
		cout<<s1.top()<<" ";
		s1.pop();
	}
	cout<<endl;

	cin.get();
}
