// RBSortTree.cpp : 定义控制台应用程序的入口点。
//

/*
一、红黑树定义(局部平衡的二叉查找树)：
1、根节点黑色；
2、每个节点为红色/黑色；
3、红色节点下两个节点必为黑色(没有连续的红色节点)；
4、每一条从根至叶的路径上的黑节点数量相同(黑高度)；
5、每个叶节点都是黑的(NULL外部节点)；

二、插入操作和双红修正
	1、查找适合插入的位置插入，如果父亲不为空且是红色则进行双红修正；

	2、双红修正(根据父亲和叔叔判断)：
	RR-1（父亲是红色，叔叔不为空且是红色）：染黑父亲和叔叔，染红爷爷；从爷爷开始递归；

	RR-2（父亲是红色）：LL：右旋转爷爷，染黑父亲，染红爷爷；
						LR：左旋转父亲，右旋转爷爷，染黑自己，染红爷爷；
						RR：左旋转爷爷，染黑父亲，染红爷爷；
						RL：右旋转父亲，左旋转爷爷，染黑自己，染红爷爷；

	注意：旋转前维护根节点；


三、删除操作和失黑修正
	1、不断寻找被删除节点的真后继，替换删除真正删除的节点；如果该节点是红色，直接删除，如果是黑色，进行失黑修正；

	2、失黑修正
		1、判断兄弟是否红色（LB-1），旋转父亲，染黑兄弟，染红父亲；从插入节点递归；
		2、判断是否有红色侄子（LB-3），近侄子（旋转兄弟，旋转父亲，染黑父亲），远侄子（旋转父亲，染黑父亲）；
		3、判断父亲是否红色（LB-2R），染黑父亲，染红兄弟；
		4、判断父亲是否黑色（LB-2B），染红兄弟，从父亲节点递归；

	注意：旋转前维护根节点；

AVL树和红黑树的应用：
1、查找比插入和删除的次数多选择AVL树，因为AVL是高度平衡的BST，层数更少，查找更快；
2、如果查找、插入和删除的次数差不多，选择红黑树，因为红黑树的插入删除操作旋转次数更少；



https://www.bilibili.com/video/av30515237/?spm_id_from=333.788.videocard.0

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

	int size = 0, h = 0;

	//插入O(logN)
	for (int i = 0; i < intSize; i++)
	{
		rb.insert(rand());
	}

	size = rb.size();
	h = rb.heigh();

	RBTree<int>::iterator min = rb.minValue();
	RBTree<int>::iterator max = rb.maxValue();

	//查找O(logN)
	RBTree<int>::iterator iter168 = rb.search(168);

	//使用迭代器排序O(N*logN)
	RBTree<int>::iterator begin200 = rb.lower_bound(200);	//第一个大于等于200的节点
	RBTree<int>::iterator end800 = rb.upper_bound(800);		//第一个大于800的节点

	for (auto iter = begin200; iter != end800; iter++)
	{
		cout << *iter << " ";
	}

	cout << endl;

	//删除O(logN)
	for (int i = 0; i < intSize; i++)
	{
		rb.remove(rand());
	}

	size = rb.size();

	getchar();
    return 0;
}

