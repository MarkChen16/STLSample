#include "stdafx.h"

//序列式容器：list双向链表
void listDemo()
{
	//实例化==============================================================
	list<int> lt1;
	list<int> lt2(10);
	list<int> lt3(10, 8);
	list<int> lt4(lt3);
	list<int> lt5(lt4.begin(), lt4.end());

	//插入===============================================================
	lt1.push_front(32);		//在前面插入
	lt1.push_front(34);
	lt1.push_front(45);
	lt1.push_front(23);
	lt1.push_front(83);
	lt1.push_back(70);		//在后面插入
	lt1.push_back(92);
	lt1.push_back(39);
	lt1.push_back(68);
	lt1.push_back(85);

	list<int>::iterator iterList = find_if(lt1.begin(), lt1.end(), bind2nd(equal_to<int>(), 70));	//找到70的迭代器
	if (iterList == lt1.end()) return;	//没有找到

	lt1.insert(iterList, 78);		//在迭代器位置插入固定值
	lt1.insert(iterList, 3, 86);	//在迭代器位置插入N个固定值
	lt1.insert(iterList, lt3.begin(), lt3.end());		//在迭代器位置插入另一个迭代器范围

	lt1.emplace_front(90);		//相当于push_front，但效率更高
	lt1.emplace_back(100);		//相当于push_back，但效率更高
	lt1.emplace(lt1.begin(), 88);	//相当于insert，但效率更高

	//检索=================================================================
	cout<<"list.iterator: ";	//正向迭代器遍历输出
	for(list<int>::iterator iter = lt1.begin();iter!= lt1.end();iter++)
	{
		display<int>(*iter);
	}
	cout<<endl;

	cout<<"list.reverse_iterator: ";	//反向迭代器遍历输出
	for(list<int>::reverse_iterator riter = lt1.rbegin();riter != lt1.rend();riter++)
	{
		display<int>(*riter);
	}
	cout<<endl;

	//front返回前面的元素	back返回后面的元素
	cout<<"lt1.front: "<<lt1.front()<<"  lt1.back："<<lt1.back()<<endl;

	//排序===============================================================
	lt1.sort();			//不能使用sort算法，只能使用成员函数sort排序
	cout<<"lt1: ";
	for_each(lt1.begin(), lt1.end(), display<int>);
	cout<<endl;

	lt1.sort(greater<int>());		//从大到小排序
	cout<<"lt1: ";
	for_each(lt1.begin(), lt1.end(), display<int>);
	cout<<endl;

	//其他操作==========================================================
	lt1.reverse();		//列表反转

	lt2.swap(lt3);		//交换两个容器的所有元素

	lt2.resize(5);
	cout<<"list.size: "<<lt2.size()<<"  list.max_size: "<<lt2.max_size()<<endl;

	//特殊算法=========================================================
	lt1.sort();			//从小到大排序

	lt1.remove(45);		//删除所有等于45的元素

	lt1.merge(lt3);		//合并另一个容器的所有元素

	lt1.merge(lt2, less<int>());	//按照升序合并另一个容器

	lt1.remove_if(bind2nd(less_equal<int>(), 10));	//删除所有小于等于10的元素

	lt1.splice(lt1.end(), lt4);		//在指定位置拼接另一个容器的元素，并删除另一个容器的移动的元素

	lt1.unique();		//去重

	lt1.sort(greater<int>());		//从大到小排序

	cout<<"lt1: ";
	for_each(lt1.begin(), lt1.end(), display<int>);
	cout<<endl;

	//删除=============================================================
	lt1.pop_front();	//删除前面的元素
	lt1.pop_back();		//删除后面的元素
	lt1.erase(lt1.begin());	//擦除第一个元素
	lt1.clear();			//清除所有的元素

	cin.get();
}

