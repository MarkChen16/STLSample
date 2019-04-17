// RBSortTree.cpp : 定义控制台应用程序的入口点。
//

/*
一、红黑树定义(局部平衡的BST)：
1、根节点黑色；
2、每个节点为红色/黑色；
3、红色节点下两个节点必为黑色(没有连续的红色节点)；
4、每一条从根至叶的路径上的黑节点数量相同(黑等高)；
5、每个叶节点都是黑的；

二、插入操作和双红修正



三、删除操作和失黑修正



*/

#include "stdafx.h"
#include "RBTree.h"


int main()
{
	int intSize = 1000000;
	RBTree<int> rb;

	//左旋转
	//rb.insert(10);
	//rb.insert(5);
	//rb.insert(15);
	//rb.insert(3);
	//rb.insert(2);
	//rb.insert(1);
	//return 0;

	//右旋转
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

