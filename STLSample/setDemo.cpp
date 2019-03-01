#include "stdafx.h"
#include "setDemo.h"


void setDemo()
{
	//实例化===============================================================
	set<int> st1;		//定义一个空的集合，默认排序谓词是less<int>()
	st1.insert(10);
	st1.insert(20);
	st1.insert(30);
	st1.insert(40);
	st1.insert(50);
	st1.insert(30);

	set<int, greater<int>> st2;	//定义一个空的集合，设定排序谓词是greater<int>()
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

	//插入=================================================================
	st1.insert(60);		//插入新值到集合
	mst1.insert(80);	//插入新值到多重集合

	st1.emplace(70);	//就地构造，插入效率更高
	mst1.emplace(80);

	cout<<"st1: ";
	for_each(st1.begin(), st1.end(), display<int>);
	cout<<endl;

	//检索=================================================================
	cout<<"st1: ";
	for(set<int>::iterator iter = st1.begin();iter != st1.end();iter++)
	{
		cout<<*iter<<" ";
	}
	cout<<endl;

	set<int>::iterator iterFind = st1.find(50);		//返回等于50的元素
	if (iterFind != st1.end()) cout<<"50 found in st1."<<endl;
	else cout<<"50 not found in st1."<<endl;

	set<int>::iterator iterLower = st1.lower_bound(50);	//返回大于等于参数的第一个元素，没有找到返回end()
	
	set<int>::iterator iterUpper = st1.upper_bound(30);	//返回大于参数的第一个元素，没有找到返回end()

	pair<set<int>::iterator, set<int>::iterator> pl = st1.equal_range(50);	//返回大于等于参数的第一元素和大于参数的第一个元素，没有找到返回end()

	//其他操作======================================================
	int intCount1 = st1.count(50);	//返回集合中值为50元素的个数

	int intCount2 = mst1.count(10);	//返回集合中值为10元素的个数

	cout<<"st1.size: "<<st1.size()<<"  st1.max_size: "<<st1.max_size()<<endl;

	set<int, less<int>>::key_compare kc1 = st1.key_comp();	//键值比较函数，可以知道元素之间的先后顺序，实值比较函数一样用法
	if (kc1(1, 3)) cout<<"key 1 than key 3 big."<<endl;
	else cout<<"key 1 not than key 3 big."<<endl;

	//删除===========================================================
	st1.erase(60);		//删除60的元素
	st1.erase(st1.begin(), st1.upper_bound(30));	//删除前面和大于30的元素范围
	st1.clear();

	cin.get();
}
