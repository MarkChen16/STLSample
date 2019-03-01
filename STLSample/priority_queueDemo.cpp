#include "stdafx.h"
#include "priority_queueDemo.h"

void priority_queueDemo()
{
	//priority_queue特殊容器的用法
	priority_queue<int> pq1;		//定义一个空的优先队列，内部存储默认采用vector<int>，使用less<int>内部排序
	priority_queue<int, deque<int>, greater<int>> pq2;		//定义一个空的优先队列，采用deque<int>存储，采用greater<int>内部排序

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
		cout<<pq1.top()<<" ";		//最大的先排在前面出来
		pq1.pop();
	}
	cout<<endl;

	cin.get();
}

