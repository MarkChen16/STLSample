#include "stdafx.h"
#include "vectorDemo.h"

bool IsOdd(const int v)
{
	return (v%2 == 1);
}

void vectorDemo()
{
	//实例化================================================================
	vector<int> vt1;				//空
	vector<int> vt2(10);			//10个默认值
	vector<int> vt3(10, 88);			//10个88
	vector<int> vt4(vt3);			//复制构造
	vector<int> vt5(vt4.begin(), vt4.end());	//复制迭代器范围

	//插入==================================================================
	vt1.push_back(13);	//在后面插入元素
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

	vt1.insert(vt1.begin()+3, 100);		//在第三个元素前插入固定值
	vt1.insert(vt1.begin(), 3, 90);		//在前面插入3个固定值
	vt1.insert(vt1.end(), vt3.begin(), vt3.begin()+3);	//在后面插入迭代器范围

	vt1.emplace(vt1.begin(), 33);		//相当于insert，但不是构造对象，通过拷贝内存效率更高
	vt1.emplace_back(44);				//相当于push_back，但效率更高

	cout<<"vt1_Insert: ";
	for_each(vt1.begin(), vt1.end(), display<int>);
	cout<<endl;
	
	//检索==================================================================
	cout<<"vt1_display: ";		//使用正向迭代器遍历输出
	for(vector<int>::iterator iter = vt1.begin();iter != vt1.end();iter++)
	{
		display<int>(*iter);
	}
	cout<<endl;

	cout<<"vt1_rdisplay: ";		//使用反向迭代器遍历输出
	for(vector<int>::reverse_iterator iter = vt1.rbegin();iter != vt1.rend();iter++)
	{
		display<int>(*iter);
	}
	cout<<endl;

	cout<<"vt1[3]: "<<vt1[3]<<"  vt1 at(4): "<<vt1.at(4)<<endl;

	cout<<"vt1 front: "<<vt1.front()<<"  vt1 back: "<<vt1.back()<<endl;

	//排序=================================================================
	sort(vt1.begin(), vt1.end());	//从小到大排序

	cout<<"vt1: ";
	for_each(vt1.rbegin(), vt1.rend(), display<int>);
	cout<<endl;

	sort(vt1.begin(), vt1.end(), greater<int>());		//从大到小排序

	cout<<"vt1: ";
	for_each(vt1.rbegin(), vt1.rend(), display<int>);
	cout<<endl;

	//其他操作=============================================================
	vt2.swap(vt3);	//交换两个容器的所有元素

	cout<<"vt1.szie: "<<vt1.size()<<"  vt1.capacity: "<<vt1.capacity()<<"  vt1.max_size: "<<vt1.max_size()<<endl;

	vt1.reserve(100);	//预先分配内存
	cout<<"vt1.szie: "<<vt1.size()<<"  vt1.capacity: "<<vt1.capacity()<<"  vt1.max_size: "<<vt1.max_size()<<endl;

	vt1.resize(5);
	vt1.reserve(10);	//预先分配的内存只能变大，不能缩小
	cout<<"vt1.szie: "<<vt1.size()<<"  vt1.capacity: "<<vt1.capacity()<<"  vt1.max_size: "<<vt1.max_size()<<endl;

	cout<<"vt1: ";
	for_each(vt1.rbegin(), vt1.rend(), display<int>);
	cout<<endl;


	//删除================================================================
	vt1.pop_back();		//删除后面的元素
	vt1.erase(vt1.begin(), vt1.begin()+2);	//擦除迭代器范围
	vt1.clear();		//清除所有的元素
	vt1.shrink_to_fit();

	cin.get();
	return;

	cout<<"vector实例化==========================================================="<<endl;
	vector<int> v1;		//初始化一个空的向量
	vector<int> v2(5);	//初始化一个包含5个元素的向量
	for(int i=0;i < 10;i++)
	{
		v1.push_back(i);	//在未尾增加元素
	}

	vector<int> v3(v1.begin(), v1.begin()+5);	//使用另一个向量的迭代器范围初始化
	vector<int> v4(6, 8);		//初始化包含6个默认值为8元素的向量
	vector<int> v5(v2);			//使用另一个向量初始化

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

	cout<<"vector增加==========================================================="<<endl;
	v1.push_back(3);		//在后面添加元素
	v1.push_back(7);

	v1.insert(v1.begin()+2, 8);				//在迭代器的位置上插入元素
	v1.insert(v1.begin()+2, 3, 7);			//在迭代器的位置上插入3个7
	v1.insert(v1.begin(), v5.begin(), v5.end());		//在迭代器的位置上插入迭代器范围

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

	cout<<"vector删除==========================================================="<<endl;
	v2.pop_back();		//删除最后一个元素
	v4.erase(v4.begin(), v4.begin()+2);		//删除前面两个元素
	v5.clear();		//删除所有的元素

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

	cout<<"vector排序==========================================================="<<endl;
	sort(v1.begin(), v1.end());		//从小到大排序
	sort(v2.begin(), v2.end(), greater<int>());		//从大到小排序

	cout<<"v1: ";
	for_each(v1.begin(), v1.end(), display<int>);
	cout<<endl;

	cout<<"v2: ";
	for_each(v2.begin(), v2.end(), display<int>);
	cout<<endl;

	cin.get();

	cout<<"vector检索==========================================================="<<endl;
	cout<<"v1[3]: "<<v1[3]<<endl;
	cout<<"v1.at(4): "<<v1.at(4)<<endl;
	cout<<"v1.begin(): "<<*v1.begin()<<endl;
	cout<<"v1.front(): "<<v1.front()<<endl;		//指向前面的元素
	cout<<"v1.back(): "<<v1.back()<<endl;		//指向后面的元素
	cout<<"v1.begin(): "<<*v1.begin()<<endl;  //begin()迭代器，也是前面元素
	cout<<"--v1.end(): "<<*(--v1.end())<<endl;  //end()迭代器减一，也是后面元素

	cin.get();

	cout<<"vector其他操作==========================================================="<<endl;
	v1.swap(v2);		//两个容量的元素交换

	v2.reserve(1000);		//知道要用多少，预先分配好内存，避免频繁分配内存
	cout<<"v2.size: "<<v2.size()<<" capactity: "<<v2.capacity()<<" max_size: "<<v2.max_size()<<endl; 

	cout<<"v1: ";
	for_each(v1.begin(), v1.end(), display<int>);
	cout<<endl;

	cout<<"v2: ";
	for_each(v2.begin(), v2.end(), display<int>);
	cout<<endl;

	v2.resize(10);		//0 - newsize区间之内的元素保留，之外不做保留；

	cout<<"v2: ";
	for_each(v2.begin(), v2.end(), display<int>);
	cout<<endl;

	cin.get();

	cout<<"常见算法==========================================================="<<endl;
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

	//for_each()遍历算法: 输出所有元素
	cout<<"v6: ";
	for_each(v6.begin(), v6.end(), display<int>);
	cout<<endl;

	//find() 查找算法：找出第一个等于65的元素
	vector<int>::iterator itorFind = find(v6.begin(), v6.end(), 65);
	if (itorFind != v6.end()) cout<<"65 found in v6."<<endl;
	else cout<<"65 not found in v6."<<endl;

	//find_if() 谓词查找算法：找出符合条件的第一个元素
	vector<int>::iterator itorFindif = find_if(v6.begin(), v6.end(), IsOdd);
	if (itorFindif != v6.end()) cout<<"the frist odd is "<<*itorFindif<<endl;
	else cout<<"odd not found in v6."<<endl;

	//count() 统计算法：统计等于100元素的个数
	int intCount1 = count(v6.begin(), v6.end(), 100);
	cout<<"equal 100 count: "<<intCount1<<endl;

	//count_if() 谓词统计算法：统计符合条件元素的个数
	int intCount2 = count_if(v6.begin(), v6.end(), bind2nd(greater_equal<int>(), 60));
	cout<<"greater_equal 60 count: "<<intCount2<<endl;

	//replace()  替换算法：用新值替换等于0的元素
	replace(v6.begin(), v6.end(), 0, 10);

	//replace_if()  谓词替换算法：用新值替换符合条件的元素
	replace_if(v6.begin(), v6.end(), bind2nd(equal_to<int>(), 60), 61);

	cout<<"v6: ";
	for_each(v6.begin(), v6.end(), display<int>);
	cout<<endl;

	//copy()  复制算法： 复制元素到另一个容器指定位置，将覆盖原有位置的元素
	vector<int> v7(10, 0);		//复制之前，确保容器要有足够的大小
	copy(v6.begin(), v6.begin()+10, v7.begin());

	//copy_if()  谓词复制算法：将符合条件的元素复制到另一个容器
	copy_if(v6.begin(), v6.end(), v7.begin(), bind1st(less<int>(), 80));

	cout<<"v7: ";
	for_each(v7.begin(), v7.end(), display<int>);
	cout<<endl;

	//unique()  去重算法：排序-》去重-》删除
	v7.push_back(78);
	v7.push_back(91);
	v7.push_back(91);

	sort(v7.begin(), v7.end());	//先排序
	vector<int>::iterator iterV7 = unique(v7.begin(), v7.end());   //获取重复的元素迭代器
	v7.erase(iterV7, v7.end());		//删除所有重复的元素

	//unique_copy()  去重复制算法：
	vector<int> v8;
	v8.push_back(10);
	v8.push_back(20);
	v8.push_back(30);
	v8.push_back(20);
	v8.push_back(10);
	v8.push_back(50);
	
	vector<int> v9(v8.size());	//初始化大小一样的容器

	sort(v8.begin(), v8.end());	//先排序
	vector<int>::iterator iterV9 = unique_copy(v8.begin(), v8.end(), v9.begin());	//去重复制到另一个容器
	v9.erase(iterV9, v9.end());	//删除多余的元素

	//binary_search()  二分查找算法：
	

	cin.get();
}