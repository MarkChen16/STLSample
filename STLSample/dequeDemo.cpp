#include "stdafx.h"
#include "dequeDemo.h"

void dequeDemo()
{
	//ʵ����========================================================
	deque<int> dq1;
	deque<int> dq2(10);
	deque<int> dq3(10, 88);
	deque<int> dq4(dq3);
	deque<int> dq5(dq4.rbegin(), dq4.rend());

	//����=========================================================
	dq1.push_front(34);		//��ǰ�����Ԫ��
	dq1.push_front(56);
	dq1.push_front(94);
	dq1.push_front(52);
	dq1.push_front(83);
	dq1.push_front(48);
	dq1.push_back(74);		//�ں������Ԫ��
	dq1.push_back(39);
	dq1.push_back(63);
	dq1.push_back(68);
	dq1.push_back(68);

	dq1.insert(dq1.begin()+3, 83);		//���м����Ԫ��
	dq1.insert(dq1.begin()+3, 2, 83);
	dq1.insert(dq1.begin()+3, dq3.begin(), dq3.begin()+5);

	dq1.emplace_front(46);				//���м����Ԫ�أ�Ч�ʸ���
	dq1.emplace_back(42);
	dq1.emplace(dq1.begin()+5, 15);

	cout<<"dq1: ";
	for_each(dq1.begin(), dq1.end(), display<int>);
	cout<<endl;

	//����===========================================================
	cout<<"dq1.reverse_iterator: ";
	for(deque<int>::reverse_iterator riter = dq1.rbegin();riter!= dq1.rend();riter++)
	{
		cout<<*riter<<" ";
	}
	cout<<endl;

	cout<<"dq1.at(4): "<<dq1.at(4)<<"  dq1[5]: "<<dq1[5]<<endl;

	cout<<"dq1.front: "<<dq1.front()<<"  dq1.back: "<<dq1.back()<<endl;

	//��������=======================================================
	dq2.swap(dq3);		//��������������Ԫ��

	dq2.resize(5, 88);	//�ı�������С����ʹ����ֵ��ʼ�����е�Ԫ��

	cout<<"dq2.size: "<<dq2.size()<<"  dq2.max_size: "<<dq2.max_size()<<endl;
	
	//ɾ��============================================================
	dq1.pop_front();	//ɾ��ǰ���Ԫ��
	dq1.pop_back();		//ɾ�������Ԫ��
	dq1.erase(dq1.begin()+5);		//����ָ���ĵ�����λ�õ�Ԫ��
	dq1.erase(dq1.begin(), dq1.begin()+2);		//����ָ���ĵ�������Χ
	dq1.clear();		//������е�Ԫ��

	cin.get();
}


