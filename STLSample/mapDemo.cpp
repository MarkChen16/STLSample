#include "stdafx.h"
#include "mapDemo.h"

typedef pair<int, string> MYPAIR;

void displayPair(const MYPAIR &v)
{
	cout<<v.first<<":"<<v.second<<" ";
}

void mapDemo()
{
	//实例化=====================================================
	map<int, string> mp1;		//定义一个空的映射，默认是less<int>排序
	mp1.insert(MYPAIR(122, "陈琼英"));
	mp1.insert(MYPAIR(243, "陈宥佳"));
	mp1.insert(MYPAIR(244, "陈贵全"));
	mp1.insert(MYPAIR(232, "郭春芳"));
	mp1.insert(MYPAIR(781, "陈贵清"));
	mp1.insert(MYPAIR(126, "陈美琼"));
	mp1.insert(MYPAIR(442, "陈琼秀"));

	multimap<int, string> mmp;
	mmp.insert(MYPAIR(100, "A"));
	mmp.insert(MYPAIR(100, "B"));
	mmp.insert(MYPAIR(100, "C"));
	mmp.insert(MYPAIR(200, "E"));
	mmp.insert(MYPAIR(300, "F"));
	mmp.insert(MYPAIR(200, "G"));

	map<int, string, greater<int>> mp2;		//定义一个空的映射，以greater<int>排序
	map<int, string> mp3(mp1);	//复制一个新的映射
	map<int, string> mp4(mp3.begin(), mp3.end());

	//插入========================================================
	mp1.insert(MYPAIR(100, "张三"));
	mp1.insert(MYPAIR(100, "李四"));
	mp3.insert(mp1.begin(), mp1.upper_bound(500));

	mp1.emplace(MYPAIR(100, "张三丰"));

	cout<<"mp1: ";
	for_each(mp1.begin(), mp1.end(), displayPair);
	cout<<endl;

	//检索=========================================================
	cout<<"mp1.iterator: ";
	for(map<int, string>::iterator iter = mp1.begin();iter != mp1.end();iter++)
	{
		MYPAIR value = *iter;
		cout<<value.first<<":"<<value.second<<" ";
	}
	cout<<endl;

	map<int, string>::iterator iterFind = mp1.find(232);		//查找指定键值的元素
	if (iterFind != mp1.end()) cout<<"232 found in mp1, the value is "<<(*iterFind).second<<endl;
	else cout<<"232 not found in mp1."<<endl;

	map<int, string>::iterator iterLower = mp1.lower_bound(300);	//返回大于等于300键值的元素迭代器

	map<int, string>::iterator iterUpper = mp1.upper_bound(500);	//返回大于500键值的元素迭代器

	pair<map<int, string>::iterator, map<int, string>::iterator> pm = mp1.equal_range(400);		//返回lower_bound(400)、upper_bound(400)的数值对

	//其他操作=======================================================
	int intCount1 = mp1.count(200);		//统计键值为200的个数

	int intCount2 = mp1.count(232);		//统计键值为232的个数

	int intCount3 = mmp.count(100);		//统计键值为100的个数

	cout<<"mp1.size: "<<mp1.size()<<"mp1.max_size: "<<mp1.max_size()<<endl;		//容器的大小，容器的最大大小

	map<int, string>::key_compare kc1 = mp1.key_comp();
	if (kc1(100, 200)) cout<<"key 100 than key 200 big."<<endl;
	else cout<<"key 100 than key 200 small."<<endl;

	//删除===========================================================
	mp3.swap(mp4);			//两个容器交换所有的元素
	mp1.erase(100);			//删除键值为100的元素
	mp1.erase(mp1.find(232), mp1.find(244));	//删除键值为232到244范围的元素，但不包括244键值的元素
	mp1.clear();

	cin.get();
}
