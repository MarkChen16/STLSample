#pragma once

#include <exception>

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

template<class T, int InitCapacity = 10>
class ArrayList
{
public:
	ArrayList()
	{
		mData = new T[InitCapacity];
		if (mData == nullptr)
		{
			throw "分配内存失败！";
		}

		mSize = 0;
		mCapacity = InitCapacity;
	}

	virtual ~ArrayList()
	{
		delete[] mData;
	}

	//随机访问
	T at(int index)
	{
		check_index(index);

		return mData[index];
	}

	T operator [](int index)
	{
		return mData[index];
	}

	//获得索引
	int indexOf(T v)
	{
		for (int i = 0; i < mSize; i++)
		{
			if (mData[i] == v) return i;
		}
	}

	//删除元素
	void erase(int index)
	{
		check_index(index);



	}

	//插入元素
	void insert(int index, T v)
	{
		check_index(index);


	}

	//迭代器
	class itorator
	{
	public:
		itorator(T* v)
		{

		}

		~itorator()
		{

		}

		

	private:


	};
	
protected:
	void check_index(int index)
	{
		if (index < 0 || index >= mSize) throw "下标超出数组边界！"
	}

private:
	T* mData;		//动态数组
	int mSize;		//当前大小
	int mCapacity;	//当前容量
};

