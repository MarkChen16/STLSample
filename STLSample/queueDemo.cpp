
#include "stdafx.h"
#include "queueDemo.h"

void queueDemo()
{
	//queue特殊容器的用法========================================
	queue<int> q1;	//定义一个空的队列，采用deque<int>
	queue<int, list<int>> q2;	//定义一个空的队列，采用list<int>

	q1.push(1);
	q1.push(2);
	q1.push(3);
	q1.push(4);
	q1.push(5);
	q1.push(6);

	q2.push(1);	//调用push_back，在后面插入元素
	q2.front();	//队列第一个元素
	q2.back();	//队列最后一个元素
	q2.pop();	//调用pop_front，在前面删除元素

	cout<<"q1: ";
	while(!q1.empty())
	{
		cout<<q1.front()<<" ";

		q1.pop();
	}
	cout<<endl;

	cin.get();
}
