// AVLSortTree.cpp : 定义控制台应用程序的入口点。
//

/*
AVL平衡二叉树：
是一种二叉排序树，其中每一个节点的左子树和右子树的高度差至多等于1。
平衡因子BF = 左子树高HL - 右子树高HR   取值范围 (1, 0, -1)

特点：
1、插入或者删除时，通过一次或者两次旋转，使用二叉树重新变成AVL树；
2、由于自平衡解决了左斜树和右斜树的问题，使用查找、插入和删除算法复杂度都接近O(logN)

*/


#include "stdafx.h"
#include "AVLTree.h"

int main()
{
	AVLTree<int> avl;
	//LL旋转
	//avl.insert(8);
	//avl.insert(7);
	//avl.insert(6);

	//RR旋转
	//avl.insert(8);
	//avl.insert(9);
	//avl.insert(10);

	//RL旋转
	//avl.insert(8);
	//avl.insert(10);
	//avl.insert(9);

	//LR旋转
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

