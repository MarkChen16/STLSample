#include "stdafx.h"
#include "mapDemo.h"

typedef pair<int, string> MYPAIR;

void displayPair(const MYPAIR &v)
{
	cout<<v.first<<":"<<v.second<<" ";
}

void mapDemo()
{
	//ʵ����=====================================================
	map<int, string> mp1;		//����һ���յ�ӳ�䣬Ĭ����less<int>����
	mp1.insert(MYPAIR(122, "����Ӣ"));
	mp1.insert(MYPAIR(243, "��嶼�"));
	mp1.insert(MYPAIR(244, "�¹�ȫ"));
	mp1.insert(MYPAIR(232, "������"));
	mp1.insert(MYPAIR(781, "�¹���"));
	mp1.insert(MYPAIR(126, "������"));
	mp1.insert(MYPAIR(442, "������"));

	multimap<int, string> mmp;
	mmp.insert(MYPAIR(100, "A"));
	mmp.insert(MYPAIR(100, "B"));
	mmp.insert(MYPAIR(100, "C"));
	mmp.insert(MYPAIR(200, "E"));
	mmp.insert(MYPAIR(300, "F"));
	mmp.insert(MYPAIR(200, "G"));

	map<int, string, greater<int>> mp2;		//����һ���յ�ӳ�䣬��greater<int>����
	map<int, string> mp3(mp1);	//����һ���µ�ӳ��
	map<int, string> mp4(mp3.begin(), mp3.end());

	//����========================================================
	mp1.insert(MYPAIR(100, "����"));
	mp1.insert(MYPAIR(100, "����"));
	mp3.insert(mp1.begin(), mp1.upper_bound(500));

	mp1.emplace(MYPAIR(100, "������"));

	cout<<"mp1: ";
	for_each(mp1.begin(), mp1.end(), displayPair);
	cout<<endl;

	//����=========================================================
	cout<<"mp1.iterator: ";
	for(map<int, string>::iterator iter = mp1.begin();iter != mp1.end();iter++)
	{
		MYPAIR value = *iter;
		cout<<value.first<<":"<<value.second<<" ";
	}
	cout<<endl;

	map<int, string>::iterator iterFind = mp1.find(232);		//����ָ����ֵ��Ԫ��
	if (iterFind != mp1.end()) cout<<"232 found in mp1, the value is "<<(*iterFind).second<<endl;
	else cout<<"232 not found in mp1."<<endl;

	map<int, string>::iterator iterLower = mp1.lower_bound(300);	//���ش��ڵ���300��ֵ��Ԫ�ص�����

	map<int, string>::iterator iterUpper = mp1.upper_bound(500);	//���ش���500��ֵ��Ԫ�ص�����

	pair<map<int, string>::iterator, map<int, string>::iterator> pm = mp1.equal_range(400);		//����lower_bound(400)��upper_bound(400)����ֵ��

	//��������=======================================================
	int intCount1 = mp1.count(200);		//ͳ�Ƽ�ֵΪ200�ĸ���

	int intCount2 = mp1.count(232);		//ͳ�Ƽ�ֵΪ232�ĸ���

	int intCount3 = mmp.count(100);		//ͳ�Ƽ�ֵΪ100�ĸ���

	cout<<"mp1.size: "<<mp1.size()<<"mp1.max_size: "<<mp1.max_size()<<endl;		//�����Ĵ�С������������С

	map<int, string>::key_compare kc1 = mp1.key_comp();
	if (kc1(100, 200)) cout<<"key 100 than key 200 big."<<endl;
	else cout<<"key 100 than key 200 small."<<endl;

	//ɾ��===========================================================
	mp3.swap(mp4);			//���������������е�Ԫ��
	mp1.erase(100);			//ɾ����ֵΪ100��Ԫ��
	mp1.erase(mp1.find(232), mp1.find(244));	//ɾ����ֵΪ232��244��Χ��Ԫ�أ���������244��ֵ��Ԫ��
	mp1.clear();

	cin.get();
}
