#pragma once


#include <iostream>
#include <vector>
#include <list>

using namespace std;

//散列函数
class hashFun
{
public:
	//散列函数：将关键字转换为整数
	int operator ()(string szKey) const
	{
		int intRev = 0;

		int varOld = 1;
		int i = 1;

		//折叠法转换为整型关键字
		for each (auto var in szKey)
		{
			int tmp = var * var * varOld * i++;
			if (0 == tmp) break;

			varOld = var;

			intRev += tmp;
		}

		return intRev;
	}

};

//关键字比较函数
class equalFun
{
public:
	//关键字比较函数
	bool operator ()(string key1, string key2) const
	{
		return key1 == key2;
	}
};


template<class TKey, class TValue, class THashFun = hashFun, class TEqualFun  = equalFun>
class HashTable
{
public:
	typedef pair<TKey, TValue> HT_DATA;

	HashTable(int num)
		:arr(num, list<HT_DATA>()), intSize(num), intCount(0)
	{

	}

	TValue& operator [](TKey key)
	{
		//计算散列值获取桶的编号
		int intHash = THashFun()(key) % intSize;		//散列函数：取余数法

		list<HT_DATA> &bucket = arr[intHash];

		//遍历桶查找关键字：链地址法防冲突
		list<HT_DATA>::iterator iter = bucket.begin();

		while (iter != bucket.end())
		{
			if (TEqualFun()(key, (*iter).first))
			{
				return (*iter).second;
			}

			iter++;
		}

		//没有找到关键字，则插入桶
		bucket.push_back(make_pair(key, TValue()));
		intCount++;

		return bucket.back().second;
	}

	void insertData(TKey key, TValue value)
	{
		//计算散列值获取桶的编号
		int intHash = THashFun()(key) % intSize;		//散列函数：取余数法

		list<HT_DATA> *bucket = &arr[intHash];

		//遍历桶查找关键字
		list<HT_DATA>::iterator iter = bucket->begin();

		while (iter != bucket->end())
		{
			if (TEqualFun()(key, (*iter).first))
			{
				(*iter).second = value;
				return;
			}

			iter++;
		}

		//没有找到关键字，则插入桶
		bucket->push_back(make_pair(key, value));
		intCount++;
	}

	void removeData(TKey key)
	{
		//计算散列值获取桶的编号
		int intHash = THashFun()(key) % intSize;		//散列函数：取余数法

		list<HT_DATA> &bucket = arr[intHash];

		//遍历桶查找关键字
		list<HT_DATA>::iterator iter = bucket.begin();
		while (iter != bucket.end())
		{
			if (TEqualFun()((*iter).first, key))
			{
				bucket.erase(iter);
				return;
			}

			iter++;
		}
	}

	void clearData()
	{
		for each (auto var in arr)
		{
			var.clear();
		}

		intCount = 0;
	}

	int getCount()
	{
		return intCount;
	}

	int getSize()
	{
		return intSize;
	}

private:
	vector< list<HT_DATA> > arr;		//数据元素
	int intCount;						//元素的数量
	int intSize;						//表的大小
};

