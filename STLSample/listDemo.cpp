#include "stdafx.h"

//����ʽ������list˫������
void listDemo()
{
	//ʵ����==============================================================
	list<int> lt1;
	list<int> lt2(10);
	list<int> lt3(10, 8);
	list<int> lt4(lt3);
	list<int> lt5(lt4.begin(), lt4.end());

	//����===============================================================
	lt1.push_front(32);		//��ǰ�����
	lt1.push_front(34);
	lt1.push_front(45);
	lt1.push_front(23);
	lt1.push_front(83);
	lt1.push_back(70);		//�ں������
	lt1.push_back(92);
	lt1.push_back(39);
	lt1.push_back(68);
	lt1.push_back(85);

	list<int>::iterator iterList = find_if(lt1.begin(), lt1.end(), bind2nd(equal_to<int>(), 70));	//�ҵ�70�ĵ�����
	if (iterList == lt1.end()) return;	//û���ҵ�

	lt1.insert(iterList, 78);		//�ڵ�����λ�ò���̶�ֵ
	lt1.insert(iterList, 3, 86);	//�ڵ�����λ�ò���N���̶�ֵ
	lt1.insert(iterList, lt3.begin(), lt3.end());		//�ڵ�����λ�ò�����һ����������Χ

	lt1.emplace_front(90);		//�൱��push_front����Ч�ʸ���
	lt1.emplace_back(100);		//�൱��push_back����Ч�ʸ���
	lt1.emplace(lt1.begin(), 88);	//�൱��insert����Ч�ʸ���

	//����=================================================================
	cout<<"list.iterator: ";	//����������������
	for(list<int>::iterator iter = lt1.begin();iter!= lt1.end();iter++)
	{
		display<int>(*iter);
	}
	cout<<endl;

	cout<<"list.reverse_iterator: ";	//����������������
	for(list<int>::reverse_iterator riter = lt1.rbegin();riter != lt1.rend();riter++)
	{
		display<int>(*riter);
	}
	cout<<endl;

	//front����ǰ���Ԫ��	back���غ����Ԫ��
	cout<<"lt1.front: "<<lt1.front()<<"  lt1.back��"<<lt1.back()<<endl;

	//����===============================================================
	lt1.sort();			//����ʹ��sort�㷨��ֻ��ʹ�ó�Ա����sort����
	cout<<"lt1: ";
	for_each(lt1.begin(), lt1.end(), display<int>);
	cout<<endl;

	lt1.sort(greater<int>());		//�Ӵ�С����
	cout<<"lt1: ";
	for_each(lt1.begin(), lt1.end(), display<int>);
	cout<<endl;

	//��������==========================================================
	lt1.reverse();		//�б�ת

	lt2.swap(lt3);		//������������������Ԫ��

	lt2.resize(5);
	cout<<"list.size: "<<lt2.size()<<"  list.max_size: "<<lt2.max_size()<<endl;

	//�����㷨=========================================================
	lt1.sort();			//��С��������

	lt1.remove(45);		//ɾ�����е���45��Ԫ��

	lt1.merge(lt3);		//�ϲ���һ������������Ԫ��

	lt1.merge(lt2, less<int>());	//��������ϲ���һ������

	lt1.remove_if(bind2nd(less_equal<int>(), 10));	//ɾ������С�ڵ���10��Ԫ��

	lt1.splice(lt1.end(), lt4);		//��ָ��λ��ƴ����һ��������Ԫ�أ���ɾ����һ���������ƶ���Ԫ��

	lt1.unique();		//ȥ��

	lt1.sort(greater<int>());		//�Ӵ�С����

	cout<<"lt1: ";
	for_each(lt1.begin(), lt1.end(), display<int>);
	cout<<endl;

	//ɾ��=============================================================
	lt1.pop_front();	//ɾ��ǰ���Ԫ��
	lt1.pop_back();		//ɾ�������Ԫ��
	lt1.erase(lt1.begin());	//������һ��Ԫ��
	lt1.clear();			//������е�Ԫ��

	cin.get();
}

