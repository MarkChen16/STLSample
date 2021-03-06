#pragma once

#include <iostream>
#include <exception>

#include <algorithm>
#include <iterator>

using namespace std;

/*
定义一个新的泛型容器和迭代器，支持以下操作：
大小自动增长，每次增加100%
随机访问
根据元素获得索引
根据索引获得元素
删除元素
插入元素
*/

template<class T>
class ArrayList;

template<class T>
class arraylist_iterator;

//重载标准输出流的<<操作符
template<class T>
ostream & operator << (ostream &out, ArrayList<T> &arr)
{
	out << "ArrayList Size: " << arr.getSize() << "  Capacity: " << arr.getCapacity() << endl;

	for (auto itor = arr.begin(); itor != arr.end(); itor++)
	{
		out << *itor << endl;
	}
	
	return out;
}

//全局友元操作符重载函数，常数为左操作数必须用友元
template<class VT>
arraylist_iterator<VT> operator -(int intStep, const arraylist_iterator<VT> &iter)
{
	return arraylist_iterator<VT>(iter._ptr - intStep);
}

template<class VT>
arraylist_iterator<VT> operator +(int intStep, const arraylist_iterator<VT> &iter)
{
	return arraylist_iterator<VT>(iter._ptr + intStep);
}

//迭代器(随机访问迭代器)===============================================================
template<class T>
class arraylist_iterator : public std::iterator<std::random_access_iterator_tag, T>
{
public:
	//构造函数、复制构造函数、析构函数、赋值操作符
	explicit arraylist_iterator(T* p = nullptr)
	{
		_ptr = p;
	}

	arraylist_iterator(const arraylist_iterator &iter)
	{
		_ptr = iter._ptr;
	}

	arraylist_iterator & operator = (const arraylist_iterator &iter)
	{
		_ptr = iter._ptr;

		return *this;
	}

	//移动操作
	arraylist_iterator & operator ++()
	{
		//前缀++，运算后返回本身
		_ptr++;

		return *this;
	}

	arraylist_iterator & operator --()
	{
		//前缀--
		_ptr--;

		return *this;
	}

	arraylist_iterator operator ++(int)
	{
		//后缀++，返回新的对象再运算
		arraylist_iterator iterRev = *this;

		_ptr++;

		return iterRev;
	}

	arraylist_iterator operator --(int)
	{
		//后缀--
		arraylist_iterator iterRev = *this;

		_ptr--;

		return iterRev;
	}

	//两个迭代器的距离
	int operator -(arraylist_iterator iter)
	{
		int intRev = std::distance(iter._ptr, _ptr);

		return intRev;
	}

	//算术操作(随机访问)
	arraylist_iterator & operator -=(int intStep)
	{
		_ptr -= intStep;

		return *this;
	}

	arraylist_iterator & operator +=(int intStep)
	{
		_ptr += intStep;

		return *this;
	}

	arraylist_iterator operator -(int intStep)
	{
		return arraylist_iterator(_ptr - intStep);
	}

	arraylist_iterator operator +(int intStep)
	{
		return arraylist_iterator(_ptr + intStep);
	}

	//比较函数
	bool operator !=(const arraylist_iterator &iter)
	{
		return (_ptr != iter._ptr);
	}

	bool operator ==(const arraylist_iterator &iter)
	{
		return (_ptr == iter._ptr);
	}

	bool operator > (const arraylist_iterator &iter)
	{
		return (_ptr > iter._ptr);
	}

	bool operator < (const arraylist_iterator &iter)
	{
		return (_ptr < iter._ptr);
	}

	bool operator >= (const arraylist_iterator &iter)
	{
		//return (*this > iter || *this == iter);
		return (*this >= iter);
	}

	bool operator <= (const arraylist_iterator &iter)
	{
		//return (*this < iter || *this == iter);
		return (*this <= iter);
	}

	//取值函数
	T & operator [](int index)
	{
		T *ptrRev = _ptr + index;

		return *ptrRev;
	}

	T & operator *()
	{
		return *_ptr;
	}

	T & operator ->()
	{
		return *_ptr;
	}

private:
	T* _ptr;

	template<class VT>
	friend arraylist_iterator<VT> operator -(int intStep, const arraylist_iterator<VT> &iter);

	template<class VT>
	friend arraylist_iterator<VT> operator +(int intStep, const arraylist_iterator<VT> &iter);
};

//容器=================================================================================
template<class T>
class ArrayList
{
public:
	typedef arraylist_iterator<T> iterator;

	ArrayList(int initCapacity = 10)
	{
		mArr = new T[initCapacity];
		if (mArr == nullptr)
		{
			throw "分配内存失败！";
		}

		mSize = 0;
		mCapacity = initCapacity;
	}

	virtual ~ArrayList()
	{
		if (mArr != nullptr)
		{
			delete[] mArr;
			mArr = nullptr;
		}
	}

	void operator =(const ArrayList<T> &arr)
	{
		for (int i = 0; i < arr.getSize(); i++)
		{
			this->push_back(arr[i]);
		}
	}

	//随机访问
	T & at(int index)
	{
		check_index(index);

		return mArr[index];
	}

	T & operator [](int index)
	{
		return mArr[index];
	}

	//获得索引
	int indexOf(T & v)
	{
		for (int i = 0; i < mSize; i++)
		{
			if (mArr + i == &v) return i;
		}

		return -1;
	}

	//删除元素
	void erase(int index)
	{
		check_index(index);

		for (int i = index; i < mSize - 1; i++)
		{
			mArr[i] = mArr[i + 1];
		}

		mArr[mSize - 1] = T();
		mSize--;
	}

	void erase(iterator begIt, iterator endIt)
	{
		for (iterator iter = begIt; iter != endIt; iter++)
		{
			*iter = T();
			mSize--;
		}
	}

	//插入元素
	void insert(int index, T v)
	{
		check_index(index);

		resize();

		for (int i = mSize; i > index; i--)
		{
			mArr[i] = mArr[i - 1];
		}

		mArr[index] = v;
	}

	ArrayList & operator << (T v)
	{
		push_back(v);

		return *this;
	}

	void push_front(T v)
	{
		insert(0, v);
	}

	void push_back(T v)
	{
		resize();

		mArr[mSize] = v;
		mSize++;
	}

	void pop_front()
	{
		erase(0);
	}

	void pop_back()
	{
		erase(mSize - 1);
	}

	int getSize() const
	{
		return mSize;
	}

	int getCapacity() const
	{
		return mCapacity;
	}

	iterator begin()
	{
		return iterator(mArr);
	}

	iterator end()
	{
		return iterator(mArr + mSize);
	}

protected:
	void check_index(int index)
	{
		if (index < 0 || index >= mSize) throw "下标超出数组边界！";
	}

	void resize()
	{
		if (mSize < mCapacity)
		{
			return;
		}

		//分配新的内存
		T* newArr = new T[mCapacity*2];
		if (newArr == nullptr) throw "调整大小时分配内存失败！";
		
		//复制元素
		for (int i = 0; i < mSize; i++)
		{
			newArr[i] = mArr[i];
		}

		delete[] mArr;

		mArr = newArr;
		mCapacity = mCapacity * 2;
	}

private:
	T* mArr;		//动态数组
	int mSize;		//当前大小
	int mCapacity;	//当前容量

	friend ostream & operator << (ostream &out, const ArrayList<T> &arr);
};

//仿函数===============================================================================
template<class T>
class MySum
{
public:
	MySum()
	{
		mTimes = 0;
		mSum = 0;
	}

	void operator ()(const T & val)
	{
		mTimes++;

		mSum += val*mTimes;
	}

	//类型转换操作符，没有返回类型
	operator T()
	{
		return mSum;
	}

private:
	T mSum;
	int mTimes;
};

//算法=================================================================================
template<class _RanIt>
_RanIt my_unique(_RanIt beg, _RanIt end)
{
	sort(beg, end);

	return unique(beg, end);
}



