// RBSortTree.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
һ�����������(�ֲ�ƽ���BST)��
1�����ڵ��ɫ��
2��ÿ���ڵ�Ϊ��ɫ/��ɫ��
3����ɫ�ڵ��������ڵ��Ϊ��ɫ(û�������ĺ�ɫ�ڵ�)��
4��ÿһ���Ӹ���Ҷ��·���ϵĺڽڵ�������ͬ(�ڵȸ�)��
5��ÿ��Ҷ�ڵ㶼�Ǻڵģ�

�������������˫������



����ɾ��������ʧ������



*/

#include "stdafx.h"
#include "RBTree.h"


int main()
{
	int intSize = 1000000;
	RBTree<int> rb;

	//����ת
	//rb.insert(10);
	//rb.insert(5);
	//rb.insert(15);
	//rb.insert(3);
	//rb.insert(2);
	//rb.insert(1);
	//return 0;

	//����ת
	//rb.insert(10);
	//rb.insert(5);
	//rb.insert(15);
	//rb.insert(18);
	//rb.insert(20);
	//rb.insert(25);
	//return 0;

	for (int i = 0; i < intSize; i++)
	{
		rb.insert(i);
	}

    return 0;
}

