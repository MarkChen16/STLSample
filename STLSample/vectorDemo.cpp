#include "stdafx.h"
#include "vectorDemo.h"

bool IsOdd(const int v)
{
	return (v%2 == 1);
}

void vectorDemo()
{
	//ʵ����================================================================
	vector<int> vt1;				//��
	vector<int> vt2(10);			//10��Ĭ��ֵ
	vector<int> vt3(10, 88);			//10��88
	vector<int> vt4(vt3);			//���ƹ���
	vector<int> vt5(vt4.begin(), vt4.end());	//���Ƶ�������Χ

	//����==================================================================
	vt1.push_back(13);	//�ں������Ԫ��
	vt1.push_back(34);
	vt1.push_back(27);
	vt1.push_back(76);
	vt1.push_back(45);
	vt1.push_back(78);
	vt1.push_back(93);
	vt1.push_back(70);
	vt1.push_back(54);
	vt1.push_back(61);
	vt1.push_back(37);
	vt1.push_back(56);
	vt1.push_back(61);
	vt1.push_back(78);
	vt1.push_back(80);
	vt1.push_back(100);
	vt1.push_back(94);
	vt1.push_back(80);

	vt1.insert(vt1.begin()+3, 100);		//�ڵ�����Ԫ��ǰ����̶�ֵ
	vt1.insert(vt1.begin(), 3, 90);		//��ǰ�����3���̶�ֵ
	vt1.insert(vt1.end(), vt3.begin(), vt3.begin()+3);	//�ں�������������Χ

	vt1.emplace(vt1.begin(), 33);		//�൱��insert�������ǹ������ͨ�������ڴ�Ч�ʸ���
	vt1.emplace_back(44);				//�൱��push_back����Ч�ʸ���

	cout<<"vt1_Insert: ";
	for_each(vt1.begin(), vt1.end(), display<int>);
	cout<<endl;
	
	//����==================================================================
	cout<<"vt1_display: ";		//ʹ������������������
	for(vector<int>::iterator iter = vt1.begin();iter != vt1.end();iter++)
	{
		display<int>(*iter);
	}
	cout<<endl;

	cout<<"vt1_rdisplay: ";		//ʹ�÷���������������
	for(vector<int>::reverse_iterator iter = vt1.rbegin();iter != vt1.rend();iter++)
	{
		display<int>(*iter);
	}
	cout<<endl;

	cout<<"vt1[3]: "<<vt1[3]<<"  vt1 at(4): "<<vt1.at(4)<<endl;

	cout<<"vt1 front: "<<vt1.front()<<"  vt1 back: "<<vt1.back()<<endl;

	//����=================================================================
	sort(vt1.begin(), vt1.end());	//��С��������

	cout<<"vt1: ";
	for_each(vt1.rbegin(), vt1.rend(), display<int>);
	cout<<endl;

	sort(vt1.begin(), vt1.end(), greater<int>());		//�Ӵ�С����

	cout<<"vt1: ";
	for_each(vt1.rbegin(), vt1.rend(), display<int>);
	cout<<endl;

	//��������=============================================================
	vt2.swap(vt3);	//������������������Ԫ��

	cout<<"vt1.szie: "<<vt1.size()<<"  vt1.capacity: "<<vt1.capacity()<<"  vt1.max_size: "<<vt1.max_size()<<endl;

	vt1.reserve(100);	//Ԥ�ȷ����ڴ�
	cout<<"vt1.szie: "<<vt1.size()<<"  vt1.capacity: "<<vt1.capacity()<<"  vt1.max_size: "<<vt1.max_size()<<endl;

	vt1.resize(5);
	vt1.reserve(10);	//Ԥ�ȷ�����ڴ�ֻ�ܱ�󣬲�����С
	cout<<"vt1.szie: "<<vt1.size()<<"  vt1.capacity: "<<vt1.capacity()<<"  vt1.max_size: "<<vt1.max_size()<<endl;

	cout<<"vt1: ";
	for_each(vt1.rbegin(), vt1.rend(), display<int>);
	cout<<endl;


	//ɾ��================================================================
	vt1.pop_back();		//ɾ�������Ԫ��
	vt1.erase(vt1.begin(), vt1.begin()+2);	//������������Χ
	vt1.clear();		//������е�Ԫ��
	vt1.shrink_to_fit();

	cin.get();
	return;

	cout<<"vectorʵ����==========================================================="<<endl;
	vector<int> v1;		//��ʼ��һ���յ�����
	vector<int> v2(5);	//��ʼ��һ������5��Ԫ�ص�����
	for(int i=0;i < 10;i++)
	{
		v1.push_back(i);	//��δβ����Ԫ��
	}

	vector<int> v3(v1.begin(), v1.begin()+5);	//ʹ����һ�������ĵ�������Χ��ʼ��
	vector<int> v4(6, 8);		//��ʼ������6��Ĭ��ֵΪ8Ԫ�ص�����
	vector<int> v5(v2);			//ʹ����һ��������ʼ��

	cout<<"v1: ";
	for_each(v1.begin(), v1.end(), display<int>);
	cout<<endl;

	cout<<"v2: ";
	for_each(v2.begin(), v2.end(), display<int>);
	cout<<endl;

	cout<<"v3: ";
	for_each(v3.begin(), v3.end(), display<int>);
	cout<<endl;

	cout<<"v4: ";
	for_each(v4.begin(), v4.end(), display<int>);
	cout<<endl;

	cout<<"v5: ";
	for_each(v5.begin(), v5.end(), display<int>);
	cout<<endl;

	cin.get();

	cout<<"vector����==========================================================="<<endl;
	v1.push_back(3);		//�ں������Ԫ��
	v1.push_back(7);

	v1.insert(v1.begin()+2, 8);				//�ڵ�������λ���ϲ���Ԫ��
	v1.insert(v1.begin()+2, 3, 7);			//�ڵ�������λ���ϲ���3��7
	v1.insert(v1.begin(), v5.begin(), v5.end());		//�ڵ�������λ���ϲ����������Χ

	v2.push_back(2);
	v2.push_back(2);
	v2.push_back(6);

	v4.push_back(1);
	v4.push_back(6);
	v4.push_back(8);
	
	v5.push_back(5);
	v5.push_back(5);
	v5.push_back(7);

	cout<<"v1: ";
	for_each(v1.begin(), v1.end(), display<int>);
	cout<<endl;

	cout<<"v2: ";
	for_each(v2.begin(), v2.end(), display<int>);
	cout<<endl;

	cout<<"v3: ";
	for_each(v3.begin(), v3.end(), display<int>);
	cout<<endl;

	cout<<"v4: ";
	for_each(v4.begin(), v4.end(), display<int>);
	cout<<endl;

	cout<<"v5: ";
	for_each(v5.begin(), v5.end(), display<int>);
	cout<<endl;

	cin.get();

	cout<<"vectorɾ��==========================================================="<<endl;
	v2.pop_back();		//ɾ�����һ��Ԫ��
	v4.erase(v4.begin(), v4.begin()+2);		//ɾ��ǰ������Ԫ��
	v5.clear();		//ɾ�����е�Ԫ��

	cout<<"v1: ";
	for_each(v1.begin(), v1.end(), display<int>);
	cout<<endl;

	cout<<"v2: ";
	for_each(v2.begin(), v2.end(), display<int>);
	cout<<endl;

	cout<<"v3: ";
	for_each(v3.begin(), v3.end(), display<int>);
	cout<<endl;

	cout<<"v4: ";
	for_each(v4.begin(), v4.end(), display<int>);
	cout<<endl;

	cout<<"v5: ";
	for_each(v5.begin(), v5.end(), display<int>);
	cout<<endl;

	cin.get();

	cout<<"vector����==========================================================="<<endl;
	sort(v1.begin(), v1.end());		//��С��������
	sort(v2.begin(), v2.end(), greater<int>());		//�Ӵ�С����

	cout<<"v1: ";
	for_each(v1.begin(), v1.end(), display<int>);
	cout<<endl;

	cout<<"v2: ";
	for_each(v2.begin(), v2.end(), display<int>);
	cout<<endl;

	cin.get();

	cout<<"vector����==========================================================="<<endl;
	cout<<"v1[3]: "<<v1[3]<<endl;
	cout<<"v1.at(4): "<<v1.at(4)<<endl;
	cout<<"v1.begin(): "<<*v1.begin()<<endl;
	cout<<"v1.front(): "<<v1.front()<<endl;		//ָ��ǰ���Ԫ��
	cout<<"v1.back(): "<<v1.back()<<endl;		//ָ������Ԫ��
	cout<<"v1.begin(): "<<*v1.begin()<<endl;  //begin()��������Ҳ��ǰ��Ԫ��
	cout<<"--v1.end(): "<<*(--v1.end())<<endl;  //end()��������һ��Ҳ�Ǻ���Ԫ��

	cin.get();

	cout<<"vector��������==========================================================="<<endl;
	v1.swap(v2);		//����������Ԫ�ؽ���

	v2.reserve(1000);		//֪��Ҫ�ö��٣�Ԥ�ȷ�����ڴ棬����Ƶ�������ڴ�
	cout<<"v2.size: "<<v2.size()<<" capactity: "<<v2.capacity()<<" max_size: "<<v2.max_size()<<endl; 

	cout<<"v1: ";
	for_each(v1.begin(), v1.end(), display<int>);
	cout<<endl;

	cout<<"v2: ";
	for_each(v2.begin(), v2.end(), display<int>);
	cout<<endl;

	v2.resize(10);		//0 - newsize����֮�ڵ�Ԫ�ر�����֮�ⲻ��������

	cout<<"v2: ";
	for_each(v2.begin(), v2.end(), display<int>);
	cout<<endl;

	cin.get();

	cout<<"�����㷨==========================================================="<<endl;
	vector<int> v6;
	v6.push_back(46);
	v6.push_back(87);
	v6.push_back(100);
	v6.push_back(76);
	v6.push_back(92);
	v6.push_back(100);
	v6.push_back(65);
	v6.push_back(78);
	v6.push_back(80);
	v6.push_back(100);
	v6.push_back(72);
	v6.push_back(34);
	v6.push_back(47);
	v6.push_back(60);
	v6.push_back(0);
	v6.push_back(60);

	//for_each()�����㷨: �������Ԫ��
	cout<<"v6: ";
	for_each(v6.begin(), v6.end(), display<int>);
	cout<<endl;

	//find() �����㷨���ҳ���һ������65��Ԫ��
	vector<int>::iterator itorFind = find(v6.begin(), v6.end(), 65);
	if (itorFind != v6.end()) cout<<"65 found in v6."<<endl;
	else cout<<"65 not found in v6."<<endl;

	//find_if() ν�ʲ����㷨���ҳ����������ĵ�һ��Ԫ��
	vector<int>::iterator itorFindif = find_if(v6.begin(), v6.end(), IsOdd);
	if (itorFindif != v6.end()) cout<<"the frist odd is "<<*itorFindif<<endl;
	else cout<<"odd not found in v6."<<endl;

	//count() ͳ���㷨��ͳ�Ƶ���100Ԫ�صĸ���
	int intCount1 = count(v6.begin(), v6.end(), 100);
	cout<<"equal 100 count: "<<intCount1<<endl;

	//count_if() ν��ͳ���㷨��ͳ�Ʒ�������Ԫ�صĸ���
	int intCount2 = count_if(v6.begin(), v6.end(), bind2nd(greater_equal<int>(), 60));
	cout<<"greater_equal 60 count: "<<intCount2<<endl;

	//replace()  �滻�㷨������ֵ�滻����0��Ԫ��
	replace(v6.begin(), v6.end(), 0, 10);

	//replace_if()  ν���滻�㷨������ֵ�滻����������Ԫ��
	replace_if(v6.begin(), v6.end(), bind2nd(equal_to<int>(), 60), 61);

	cout<<"v6: ";
	for_each(v6.begin(), v6.end(), display<int>);
	cout<<endl;

	//copy()  �����㷨�� ����Ԫ�ص���һ������ָ��λ�ã�������ԭ��λ�õ�Ԫ��
	vector<int> v7(10, 0);		//����֮ǰ��ȷ������Ҫ���㹻�Ĵ�С
	copy(v6.begin(), v6.begin()+10, v7.begin());

	//copy_if()  ν�ʸ����㷨��������������Ԫ�ظ��Ƶ���һ������
	copy_if(v6.begin(), v6.end(), v7.begin(), bind1st(less<int>(), 80));

	cout<<"v7: ";
	for_each(v7.begin(), v7.end(), display<int>);
	cout<<endl;

	//unique()  ȥ���㷨������-��ȥ��-��ɾ��
	v7.push_back(78);
	v7.push_back(91);
	v7.push_back(91);

	sort(v7.begin(), v7.end());	//������
	vector<int>::iterator iterV7 = unique(v7.begin(), v7.end());   //��ȡ�ظ���Ԫ�ص�����
	v7.erase(iterV7, v7.end());		//ɾ�������ظ���Ԫ��

	//unique_copy()  ȥ�ظ����㷨��
	vector<int> v8;
	v8.push_back(10);
	v8.push_back(20);
	v8.push_back(30);
	v8.push_back(20);
	v8.push_back(10);
	v8.push_back(50);
	
	vector<int> v9(v8.size());	//��ʼ����Сһ��������

	sort(v8.begin(), v8.end());	//������
	vector<int>::iterator iterV9 = unique_copy(v8.begin(), v8.end(), v9.begin());	//ȥ�ظ��Ƶ���һ������
	v9.erase(iterV9, v9.end());	//ɾ�������Ԫ��

	//binary_search()  ���ֲ����㷨��
	

	cin.get();
}