// AVLSortTree.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
AVLƽ���������
��һ�ֶ���������������ÿһ���ڵ�����������������ĸ߶Ȳ��������1��
ƽ������BF = ��������HL - ��������HR   ȡֵ��Χ (1, 0, -1)

�ص㣺
1���������ɾ��ʱ��ͨ��һ�λ���������ת��ʹ�ö��������±��AVL����
2��������ƽ��������б������б�������⣬ʹ�ò��ҡ������ɾ���㷨���Ӷȶ��ӽ�O(logN)

*/


#include "stdafx.h"
#include "AVLTree.h"

int main()
{
	AVLTree<int> avl;
	//LL��ת
	//avl.insert(8);
	//avl.insert(7);
	//avl.insert(6);

	//RR��ת
	//avl.insert(8);
	//avl.insert(9);
	//avl.insert(10);

	//RL��ת
	//avl.insert(8);
	//avl.insert(10);
	//avl.insert(9);

	//LR��ת
	//avl.insert(8);
	//avl.insert(6);
	//avl.insert(7);

	for (int i = 0; i < 260000; i++)
	{
		int newKey = rand();
		avl.insert(newKey);
	}

	avl.insert(8);
	avl.insert(6);
	avl.insert(4);
	avl.insert(9);
	avl.insert(7);
	avl.insert(5);

	avl.print();

	avl.remove(6);
	avl.remove(7);
	avl.remove(4);

	avl.print();

	getchar();
    return 0;
}

