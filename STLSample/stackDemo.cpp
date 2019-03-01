#include "stdafx.h"
#include "stackDemo.h"

void stackDemo()
{
	//stack栈的用法=========================================
	stack<int> s1;		//定义一个空的栈，默认使用deque<int>
	stack<int, list<int>> s2;	//定义一个空的栈，内部存储结构采用list<int>
	stack<int, vector<int>> s3;	//定义一个空的栈，内部存储结构采用vector<int>

	s1.push(1);
	s1.push(2);
	s1.push(3);
	s1.push(4);
	s1.push(5);
	s1.push(6);

	s2.push(1);		//调用push_back，在后面插入元素
	s2.top();		//一摞盘子最上面的盘子
	s2.pop();		//调用pop_back，在后面删除元素

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
