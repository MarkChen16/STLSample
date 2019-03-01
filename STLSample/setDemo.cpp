#include "stdafx.h"
#include "setDemo.h"


void setDemo()
{
	//ʵ����===============================================================
	set<int> st1;		//����һ���յļ��ϣ�Ĭ������ν����less<int>()
	st1.insert(10);
	st1.insert(20);
	st1.insert(30);
	st1.insert(40);
	st1.insert(50);
	st1.insert(30);

	set<int, greater<int>> st2;	//����һ���յļ��ϣ��趨����ν����greater<int>()
	set<int> st3(st1.begin(), st1.end());
	set<int> st4(st1);

	multiset<int> mst1;
	mst1.insert(10);
	mst1.insert(10);
	mst1.insert(20);
	mst1.insert(30);
	mst1.insert(50);
	mst1.insert(30);
	mst1.insert(10);
	mst1.insert(70);

	cout<<"st1: ";
	for_each(st1.begin(), st1.end(), display<int>);
	cout<<endl;

	//����=================================================================
	st1.insert(60);		//������ֵ������
	mst1.insert(80);	//������ֵ�����ؼ���

	st1.emplace(70);	//�͵ع��죬����Ч�ʸ���
	mst1.emplace(80);

	cout<<"st1: ";
	for_each(st1.begin(), st1.end(), display<int>);
	cout<<endl;

	//����=================================================================
	cout<<"st1: ";
	for(set<int>::iterator iter = st1.begin();iter != st1.end();iter++)
	{
		cout<<*iter<<" ";
	}
	cout<<endl;

	set<int>::iterator iterFind = st1.find(50);		//���ص���50��Ԫ��
	if (iterFind != st1.end()) cout<<"50 found in st1."<<endl;
	else cout<<"50 not found in st1."<<endl;

	set<int>::iterator iterLower = st1.lower_bound(50);	//���ش��ڵ��ڲ����ĵ�һ��Ԫ�أ�û���ҵ�����end()
	
	set<int>::iterator iterUpper = st1.upper_bound(30);	//���ش��ڲ����ĵ�һ��Ԫ�أ�û���ҵ�����end()

	pair<set<int>::iterator, set<int>::iterator> pl = st1.equal_range(50);	//���ش��ڵ��ڲ����ĵ�һԪ�غʹ��ڲ����ĵ�һ��Ԫ�أ�û���ҵ�����end()

	//��������======================================================
	int intCount1 = st1.count(50);	//���ؼ�����ֵΪ50Ԫ�صĸ���

	int intCount2 = mst1.count(10);	//���ؼ�����ֵΪ10Ԫ�صĸ���

	cout<<"st1.size: "<<st1.size()<<"  st1.max_size: "<<st1.max_size()<<endl;

	set<int, less<int>>::key_compare kc1 = st1.key_comp();	//��ֵ�ȽϺ���������֪��Ԫ��֮����Ⱥ�˳��ʵֵ�ȽϺ���һ���÷�
	if (kc1(1, 3)) cout<<"key 1 than key 3 big."<<endl;
	else cout<<"key 1 not than key 3 big."<<endl;

	//ɾ��===========================================================
	st1.erase(60);		//ɾ��60��Ԫ��
	st1.erase(st1.begin(), st1.upper_bound(30));	//ɾ��ǰ��ʹ���30��Ԫ�ط�Χ
	st1.clear();

	cin.get();
}
