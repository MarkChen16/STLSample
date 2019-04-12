// AVLSortTree.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
AVLƽ���������
��һ�ֶ���������������ÿһ���ڵ�����������������ĸ߶Ȳ��������1��

ƽ������BF = ��������HL - ��������HR   ȡֵ��Χ (1, 0, -1)


�ص㣺
1���������ɾ��ʱ��ͨ��һ�λ���������ת��ʹ�ö��������±��AVL����
2��������ƽ���������ߵ����⣬ʹ�ò��ҡ������ɾ���㷨���Ӷȶ��ӽ�O(logN)

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

	for (long i = 0; i < 1000000; i++)
	{
		int newKey = (rand() << 16) + rand();
		avl.insert(newKey);
	}

	cout << "�ڵ�������" << avl.count() << endl;
	cout << "�ڵ�߶ȣ�" << avl.heigh() << endl;

	avl.insert(6);
	avl.insert(3);
	avl.insert(9);
	avl.insert(68);
	avl.insert(32);
	avl.insert(456);
	avl.insert(222);
	avl.insert(77);
	avl.insert(22);
	avl.insert(779);
	avl.insert(23);
	avl.insert(41);
	avl.insert(85);

	//avl.print();

	avl.remove(6);
	avl.remove(3);
	avl.remove(9);
	avl.remove(4);

	cout << "�ڵ�������" << avl.count() << endl;
	cout << "�ڵ�߶ȣ�" << avl.heigh() << endl;

	//avl.print();

	getchar();
    return 0;
}

