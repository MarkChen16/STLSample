#pragma once


#include <iostream>
#include <vector>
#include <list>

using namespace std;

//ɢ�к���
class hashFun
{
public:
	//ɢ�к��������ؼ���ת��Ϊ����
	int operator ()(string szKey) const
	{
		int intRev = 0;

		int varOld = 1;
		int i = 1;

		//�۵���ת��Ϊ���͹ؼ���
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

//�ؼ��ֱȽϺ���
class equalFun
{
public:
	//�ؼ��ֱȽϺ���
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
		//����ɢ��ֵ��ȡͰ�ı��
		int intHash = THashFun()(key) % intSize;		//ɢ�к�����ȡ������

		list<HT_DATA> &bucket = arr[intHash];

		//����Ͱ���ҹؼ��֣�����ַ������ͻ
		list<HT_DATA>::iterator iter = bucket.begin();

		while (iter != bucket.end())
		{
			if (TEqualFun()(key, (*iter).first))
			{
				return (*iter).second;
			}

			iter++;
		}

		//û���ҵ��ؼ��֣������Ͱ
		bucket.push_back(make_pair(key, TValue()));
		intCount++;

		return bucket.back().second;
	}

	void insertData(TKey key, TValue value)
	{
		//����ɢ��ֵ��ȡͰ�ı��
		int intHash = THashFun()(key) % intSize;		//ɢ�к�����ȡ������

		list<HT_DATA> *bucket = &arr[intHash];

		//����Ͱ���ҹؼ���
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

		//û���ҵ��ؼ��֣������Ͱ
		bucket->push_back(make_pair(key, value));
		intCount++;
	}

	void removeData(TKey key)
	{
		//����ɢ��ֵ��ȡͰ�ı��
		int intHash = THashFun()(key) % intSize;		//ɢ�к�����ȡ������

		list<HT_DATA> &bucket = arr[intHash];

		//����Ͱ���ҹؼ���
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
	vector< list<HT_DATA> > arr;		//����Ԫ��
	int intCount;						//Ԫ�ص�����
	int intSize;						//��Ĵ�С
};

