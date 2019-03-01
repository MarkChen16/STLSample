#include "stdafx.h"
#include "unchangeAlg.h"

template<class T>
class IfOddMultiple
{
public:
	IfOddMultiple(const T &v)
	{
		mMultipleX = v;
		mCount = 0;
	}

	void operator()(T &elem)
	{
		if (elem%2 == 1)
		{
			elem = elem * this->mMultipleX;
		}

		mCount+=elem;
		cout<<elem<<" ";
	}

	operator int()
	{
		return mCount;
	}

private:
	T mMultipleX;

	T mCount;
};

bool greaterComfun(const int &elem1, const int &elem2)
{
	if (elem2 >= 100) return false;

	return elem2 > elem1;
}

bool sumTo100(const int &elem1, const int &elem2)
{
	return (elem1+elem2)==100;
}

bool mupltiTo2(const int &elem1, const int &elem2)
{
	return elem1*2 == elem2;
}

void unchangeAlg()
{
	//初始化========================================================
	vector<int> vt;
	list<int> lt;
	deque<int> dq;

	set<int> st;
	map<int, string> mp;
	typedef pair<int, string> MYPAIR;

	vt.push_back(21);
	vt.push_back(331);
	vt.push_back(11);
	vt.push_back(22);
	vt.push_back(45);
	vt.push_back(237);
	vt.push_back(31);
	vt.push_back(31);
	vt.push_back(31);
	vt.push_back(22);
	vt.push_back(45);

	lt.push_front(142);
	lt.push_front(126);
	lt.push_front(25);
	lt.push_front(74);
	lt.push_front(74);
	lt.push_front(22);
	lt.push_front(33);
	lt.push_front(33);
	lt.push_front(95);
	lt.push_front(34);

	dq.push_front(12);
	dq.push_front(12);
	dq.push_front(34);
	dq.push_front(56);
	dq.push_front(17);
	dq.push_front(17);
	dq.push_front(17);
	dq.push_front(23);
	dq.push_front(46);
	dq.push_front(58);
	dq.push_front(75);
	dq.push_front(26);
	dq.push_front(13);

	st.insert(12);
	st.insert(3);
	st.insert(12);
	st.insert(467);
	st.insert(36);
	st.insert(23);
	st.insert(632);
	st.insert(31);

	mp.insert(MYPAIR(121,"A"));
	mp.insert(MYPAIR(314,"B"));
	mp.insert(MYPAIR(121,"C"));
	mp.insert(MYPAIR(45,"E"));
	mp.insert(MYPAIR(22,"W"));
	mp.insert(MYPAIR(12,"F"));
	mp.insert(MYPAIR(12,"H"));

	int intCount = 0;

	//for_each()循环算法 =======================================================
	for_each(vt.begin(), vt.end(), display<int>);		//所有元素打印出来
	cout<<endl;

	intCount = for_each(vt.begin(), vt.end(), IfOddMultiple<int>(2));		//如果是奇数，乘于2再打印出来，最终返回所有元素的总和。
	cout<<"= "<<intCount<<endl;

	//count() count_if()统计算法 ================================================
	intCount = count(lt.begin(), lt.end(), 33);		//统计容器中33的个数
	cout<<"33 count is "<<intCount<<endl;
	
	intCount = count_if(lt.begin(), lt.end(), bind2nd(greater<int>(), 50));		//统计容器中大于50的个数
	cout<<"greater 50 count is "<<intCount<<endl;

	//min_element() max_element()最小、最大算法 ========================================
	list<int>::iterator iterMin = min_element(lt.begin(), lt.end());		//找出最小的元素，返回迭代器
	if(iterMin != lt.end())	cout<<"min is "<<*iterMin<<endl;

	list<int>::iterator iterMax = max_element(lt.begin(), lt.end(), greaterComfun);		//找出100以下的最大值
	if(iterMax != lt.end())	cout<<"max_com is "<<*iterMax<<endl;

	//find() find_if()搜索算法1 ===================================================
	list<int>::iterator iterFind = find(lt.begin(), lt.end(), 126);			//找出第一个指定值的元素，返回迭代器
	if (iterFind != lt.end()) cout<<"126 found in lt."<<endl;
	else cout<<"126 not found in lt."<<endl;

	iterFind = find_if(lt.begin(), lt.end(), bind2nd(greater<int>(), 150));	//找出第一个大于150的元素，返回迭代器
	if (iterFind != lt.end()) cout<<"greater 150 is "<<*iterFind<<endl;
	else cout<<"greater 150 not found in lt."<<endl;

	//search_n()搜索算法2 =========================================================
	deque<int>::iterator iterSea = search_n(dq.begin(), dq.end(), 3, 17);	//找出第一个3个17的元素起始位置
	if (iterSea != dq.end()) cout<<"17*3 pos is "<<distance(dq.begin(), iterSea)+1<<endl;		
	else cout<<"17*3 not found in dq."<<endl;

	iterSea = search_n(dq.begin(), dq.end(), 3, 20, greater<int>());		//找出第一个3个连续大于20的元素起始位置
	if (iterSea != dq.end()) cout<<"3 times greater 20 pos is "<<distance(dq.begin(), iterSea)+1<<endl;
	else cout<<"3 times greater 20 not found in dq."<<endl;

	//search() 搜索算法3 ==========================================================
	list<int> lt1;
	lt1.push_front(12);
	lt1.push_front(34);
	lt1.push_front(56);

	iterSea = search(dq.begin(), dq.end(), lt1.begin(), lt1.end());		//找出第一个56 34 12子区间的位置
	if (iterSea != dq.end()) cout<<"56 34 12 found in dq."<<endl;
	else cout<<"56 34 12 not found in dq."<<endl;

	list<int> lt2;
	lt2.push_back(42);
	lt2.push_back(77);
	lt2.push_back(15);

	iterSea = search(dq.begin(), dq.end(), lt2.begin(), lt2.end(),sumTo100);	//找出第一个42 77 15相加都等于100的子区间的位置
	if (iterSea != dq.end()) cout<<"42 77 15 add x equal to 100 found in dq."<<endl;
	else cout<<"42 77 15 add x equal to 100 not found in dq."<<endl;

	//find_first_of() find_end() 搜索算法的用法与以上算法一样

	//adjacent_find()搜索算法 ==============================================
	iterSea = adjacent_find(dq.begin(), dq.end());				//找出本容器中第一对连续相等的元素位置
	if (iterSea != dq.end()) cout<<"two equal x found in dq."<<endl;
	else cout<<"two equal x found in dq."<<endl;

	iterSea = adjacent_find(dq.begin(), dq.end(), mupltiTo2);		//找出本容器中第一对前元素等于后元素乘于2的元素位置
	if (iterSea != dq.end()) cout<<"elem1 == elem2*2 found in dq."<<endl;
	else cout<<"elem1 == elem2*2 found in dq."<<endl;

	//equal() 比较算法 ====================================================
	list<int> lt3;
	lt3.push_front(12);
	lt3.push_front(38);
	lt3.push_front(56);

	bool bSame1 = equal(lt1.begin(), lt1.end(), lt3.begin());		//所有元素全部相等

	list<int> lt4;
	lt4.push_front(11);
	lt4.push_front(33);
	lt4.push_front(55);

	bool bSame2 = equal(lt1.begin(), lt1.end(), lt4.begin(), greater<int>());	//满足谓词条件，第一人数组每个元素大于第二个数组的每个元素
	//mismatch() 比较算法 =================================================
	list<int> lt5;
	lt5.push_back(11);
	lt5.push_back(33);
	lt5.push_back(55);

	vector<int> v5;
	v5.push_back(22);
	v5.push_back(44);
	v5.push_back(66);
	v5.push_back(88);

	pair<list<int>::iterator, vector<int>::iterator> p1 = mismatch(lt5.begin(), lt5.end(), v5.begin());		//找到第一对匹配失败的元素组

	pair<list<int>::iterator, vector<int>::iterator> p2 = mismatch(lt5.begin(), lt5.end(), v5.begin(), less<int>());	//匹配谓词条件

	//lexicographical_compare() 比较算法 ==================================
	bool bComp = lexicographical_compare(lt5.begin(), lt5.end(), v5.begin(), v5.end());

	cin.get();
}
