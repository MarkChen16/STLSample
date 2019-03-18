#pragma once

#include <exception>

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

template<class T, int InitCapacity = 10>
class ArrayList
{
public:
	ArrayList()
	{
		mData = new T[InitCapacity];
		if (mData == nullptr)
		{
			throw "�����ڴ�ʧ�ܣ�";
		}

		mSize = 0;
		mCapacity = InitCapacity;
	}

	virtual ~ArrayList()
	{
		delete[] mData;
	}

	//�������
	T at(int index)
	{
		check_index(index);

		return mData[index];
	}

	T operator [](int index)
	{
		return mData[index];
	}

	//�������
	int indexOf(T v)
	{
		for (int i = 0; i < mSize; i++)
		{
			if (mData[i] == v) return i;
		}
	}

	//ɾ��Ԫ��
	void erase(int index)
	{
		check_index(index);



	}

	//����Ԫ��
	void insert(int index, T v)
	{
		check_index(index);


	}

	//������
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
		if (index < 0 || index >= mSize) throw "�±곬������߽磡"
	}

private:
	T* mData;		//��̬����
	int mSize;		//��ǰ��С
	int mCapacity;	//��ǰ����
};

