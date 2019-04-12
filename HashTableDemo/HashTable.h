#pragma once


#include <iostream>
#include <vector>

using namespace std;

template<class TKey>
class HashTable
{
public:
	HashTable(int num, TKey nullVal);
	~HashTable();

	TKey& operator [](TKey key)
	{
		int index = searchData(key);

		if (index >= 0 && index < size)
		{
			//�����򷵻�
			return elem[index];
		}
		else
		{
			//�����ڣ������󷵻�
			return elem[insertData(key)];
		}
	}

	int searchData(TKey key);
	int insertData(TKey key);
	void removeData(TKey key);
	void clearData();

	int getCount();
	int getSize();
	void show();

private:
	vector<TKey> elem;		//����Ԫ��
	const TKey NULL_VALUE;		//��ֵ
	int count;				//Ԫ�ص�����
	int size;				//��Ĵ�С

	int hashFun(TKey key);	//ɢ�к���
};

template<class TKey>
inline HashTable<TKey>::HashTable(int num, TKey nullVal)
	:elem(num, nullVal), NULL_VALUE(nullVal), count(0), size(num)
{

}

template<class TKey>
inline HashTable<TKey>::~HashTable()
{
}

template<class TKey>
inline int HashTable<TKey>::searchData(TKey key)
{
	int intHash = hashFun(key);
	int intAddr = intHash;

	while (elem[intAddr] != key)
	{
		intAddr = (intAddr + 1) % size;		//����̽�ⷨ�����ͻ

		if (elem[intAddr] == NULL_VALUE || intAddr == intHash)
		{
			return -1;
		}
	}

	return intAddr;
}

template<class TKey>
inline int HashTable<TKey>::insertData(TKey key)
{
	int intHash = hashFun(key);
	int intAddr = intHash;

	while (elem[intAddr] != NULL_VALUE)
	{
		intAddr = (intAddr + 1) % size;		//�����ͻ���������̽�ⷨ

		//û�пռ���
		if (intAddr == intHash) return -1;

		//�Ѿ��������滻
		if (elem[intAddr] == key)
		{
			elem[intAddr] = key;
			return intAddr;
		}
	}

	//����µ�����
	elem[intAddr] = key;
	count++;

	return intAddr;
}

template<class TKey>
inline void HashTable<TKey>::removeData(TKey key)
{
	int index = searchData(key);

	if (index >= 0)
	{
		elem[index] = NULL_VALUE;
		count--;
	}
}

template<class TKey>
inline void HashTable<TKey>::clearData()
{
	for (int i = 0; i < elem.size(); i++)
	{
		elem[i] = NULL_VALUE;
	}

	count = 0;
}

template<class TKey>
inline int HashTable<TKey>::getCount()
{
	return count;
}

template<class TKey>
inline int HashTable<TKey>::getSize()
{
	return size;
}

template<class TKey>
inline void HashTable<TKey>::show()
{
	for each (auto var in elem)
	{
		if (var == NULL_VALUE)
		{
			cout << "NULL" << endl;
		}
		else
		{
			cout << (const char *)var << endl;
		}
	}
}

template<class TKey>
inline int HashTable<TKey>::hashFun(TKey key)
{
	return key % size;	//ɢ�к���������������
}
