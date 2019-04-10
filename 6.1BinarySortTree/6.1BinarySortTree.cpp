// 6.1BinarySortTree.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
����������(����������������������)��
��1�������������գ��������������н���ֵ��С�����ĸ�����ֵ��
��2�������������գ��������������н���ֵ���������ĸ�����ֵ��
��3����������������Ҳ�ֱ�Ϊ������������

���ң������ȵ�ǰ�ڵ��򷵻ؽڵ㣬���С�ڵ�ǰ�ڵ������������м������ң�������ڵ�ǰ�ڵ������������������ң�O(logN)
ɾ����O(logN)
���룺����ֵ��ΪҶ�ӽڵ���룬O(logN)

���������б������б������������ҡ�ɾ���Ͳ���ΪO(N)��

�ṹ�Ż����������б��������б�����㷨Ч�ʵ���N��Ϊ��Ч�ʽӽ�logN�����Բ���������ƽ��Ķ���������������AVL�����������

*/


#include "stdafx.h"
#include "BSTree.h"

#include <iostream>

using namespace std;

int main()
{
	cout << "===============================================" << endl;
	BSTree<int> bst;
	bst.insert(62);
	bst.insert(58);
	bst.insert(47);
	bst.insert(51);
	bst.insert(35);
	bst.insert(35);
	bst.insert(37);
	bst.insert(88);
	bst.insert(73);
	bst.insert(99);
	bst.insert(93);
	bst.insert(95);

	cout << "���Ԫ��:" << bst.search_maximum() << endl;
	cout << "��СԪ��:" << bst.search_minimun() << endl;
	cout << "�ڵ�����:" << bst.count() << endl;
	cout << "���ĸ߶�:" << bst.height() << endl;

	cout << "ǰ�������" << endl;
	bst.preOrder();
	cout << "���������" << endl;
	bst.inOrder();
	cout << "���������" << endl;
	bst.postOrder();
	cout << "��α�����" << endl;
	bst.layerOrder();

	cout << "===============================================" << endl;
	cout << "ɾ��Ԫ��99 35 35 95 62" << endl;
	bst.remove(99);
	bst.remove(35);
	bst.remove(35);
	bst.remove(95);
	bst.remove(62);

	cout << "���Ԫ��:" << bst.search_maximum() << endl;
	cout << "��СԪ��:" << bst.search_minimun() << endl;
	cout << "�ڵ�����:" << bst.count() << endl;
	cout << "���ĸ߶�:" << bst.height() << endl;

	cout << "ǰ�������" << endl;
	bst.preOrder();
	cout << "���������" << endl;
	bst.inOrder();
	cout << "���������" << endl;
	bst.postOrder();
	cout << "��α�����" << endl;
	bst.layerOrder();

	bst.destory();

	getchar();
    return 0;
}

