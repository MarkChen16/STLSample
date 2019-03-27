#pragma once

#include <iostream>
#include <exception>

#include <algorithm>
#include <iterator>

using namespace std;

/*
����һ���µķ��������͵�������֧�����²�����
��С�Զ�������ÿ������100%
�������
����Ԫ�ػ������
�����������Ԫ��
ɾ��Ԫ��
����Ԫ��
*/

template<class T>
class ArrayList;

template<class T>
class arraylist_iterator;

//���ر�׼�������<<������
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

//ȫ����Ԫ���������غ���������Ϊ���������������Ԫ
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

//������(������ʵ�����)===============================================================
template<class T>
class arraylist_iterator : public std::iterator<std::random_access_iterator_tag, T>
{
public:
	//���캯�������ƹ��캯����������������ֵ������
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

	//�ƶ�����
	arraylist_iterator & operator ++()
	{
		//ǰ׺++������󷵻ر���
		_ptr++;

		return *this;
	}

	arraylist_iterator & operator --()
	{
		//ǰ׺--
		_ptr--;

		return *this;
	}

	arraylist_iterator operator ++(int)
	{
		//��׺++�������µĶ���������
		arraylist_iterator iterRev = *this;

		_ptr++;

		return iterRev;
	}

	arraylist_iterator operator --(int)
	{
		//��׺--
		arraylist_iterator iterRev = *this;

		_ptr--;

		return iterRev;
	}

	//�����������ľ���
	int operator -(arraylist_iterator iter)
	{
		int intRev = std::distance(iter._ptr, _ptr);

		return intRev;
	}

	//��������(�������)
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

	//�ȽϺ���
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

	//ȡֵ����
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

//����=================================================================================
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
			throw "�����ڴ�ʧ�ܣ�";
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

	//�������
	T & at(int index)
	{
		check_index(index);

		return mArr[index];
	}

	T & operator [](int index)
	{
		return mArr[index];
	}

	//�������
	int indexOf(T & v)
	{
		for (int i = 0; i < mSize; i++)
		{
			if (mArr + i == &v) return i;
		}

		return -1;
	}

	//ɾ��Ԫ��
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

	//����Ԫ��
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
		if (index < 0 || index >= mSize) throw "�±곬������߽磡";
	}

	void resize()
	{
		if (mSize < mCapacity)
		{
			return;
		}

		//�����µ��ڴ�
		T* newArr = new T[mCapacity*2];
		if (newArr == nullptr) throw "������Сʱ�����ڴ�ʧ�ܣ�";
		
		//����Ԫ��
		for (int i = 0; i < mSize; i++)
		{
			newArr[i] = mArr[i];
		}

		delete[] mArr;

		mArr = newArr;
		mCapacity = mCapacity * 2;
	}

private:
	T* mArr;		//��̬����
	int mSize;		//��ǰ��С
	int mCapacity;	//��ǰ����

	friend ostream & operator << (ostream &out, const ArrayList<T> &arr);
};

//�º���===============================================================================
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

	//����ת����������û�з�������
	operator T()
	{
		return mSum;
	}

private:
	T mSum;
	int mTimes;
};

//�㷨=================================================================================
template<class _RanIt>
_RanIt my_unique(_RanIt beg, _RanIt end)
{
	sort(beg, end);

	return unique(beg, end);
}



