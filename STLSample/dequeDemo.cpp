#include "stdafx.h"
#include "dequeDemo.h"

void dequeDemo()
{
	//实例化========================================================
	deque<int> dq1;
	deque<int> dq2(10);
	deque<int> dq3(10, 88);
	deque<int> dq4(dq3);
	deque<int> dq5(dq4.rbegin(), dq4.rend());

	//插入=========================================================
	dq1.push_front(34);		//在前面插入元素
	dq1.push_front(56);
	dq1.push_front(94);
	dq1.push_front(52);
	dq1.push_front(83);
	dq1.push_front(48);
	dq1.push_back(74);		//在后面插入元素
	dq1.push_back(39);
	dq1.push_back(63);
	dq1.push_back(68);
	dq1.push_back(68);

	dq1.insert(dq1.begin()+3, 83);		//在中间插入元素
	dq1.insert(dq1.begin()+3, 2, 83);
	dq1.insert(dq1.begin()+3, dq3.begin(), dq3.begin()+5);

	dq1.emplace_front(46);				//在中间插入元素，效率更高
	dq1.emplace_back(42);
	dq1.emplace(dq1.begin()+5, 15);

	cout<<"dq1: ";
	for_each(dq1.begin(), dq1.end(), display<int>);
	cout<<endl;

	//检索===========================================================
	cout<<"dq1.reverse_iterator: ";
	for(deque<int>::reverse_iterator riter = dq1.rbegin();riter!= dq1.rend();riter++)
	{
		cout<<*riter<<" ";
	}
	cout<<endl;

	cout<<"dq1.at(4): "<<dq1.at(4)<<"  dq1[5]: "<<dq1[5]<<endl;

	cout<<"dq1.front: "<<dq1.front()<<"  dq1.back: "<<dq1.back()<<endl;

	//其他操作=======================================================
	dq2.swap(dq3);		//交换两个容器的元素

	dq2.resize(5, 88);	//改变容器大小，并使用新值初始化所有的元素

	cout<<"dq2.size: "<<dq2.size()<<"  dq2.max_size: "<<dq2.max_size()<<endl;
	
	//删除============================================================
	dq1.pop_front();	//删除前面的元素
	dq1.pop_back();		//删除后面的元素
	dq1.erase(dq1.begin()+5);		//擦除指定的迭代器位置的元素
	dq1.erase(dq1.begin(), dq1.begin()+2);		//擦除指定的迭代器范围
	dq1.clear();		//清除所有的元素

	cin.get();
}


