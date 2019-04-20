// AVLSortTree.cpp : 定义控制台应用程序的入口点。
//

/*
一、AVL树（高度平衡的二叉查找树）：
是一种二叉排序树，其中每一个节点的左子树和右子树的高度差至多等于1。

一棵AVL树满足以下的条件:
1>它的左子树和右子树都是AVL树
2>左子树和右子树的高度差不能超过1

1>一棵n个结点的AVL树的其高度保持在0(log2(n)),不会超过3/2log2(n+1)
2>一棵n个结点的AVL树的平均搜索长度保持在0(log2(n)).
3>一棵n个结点的AVL树删除一个结点做平衡化旋转所需要的时间为0(log2(n)).

平衡因子BF = 左高LH(1)   等高EH(0)   右高RH(-1)


一、插入操作和修复平衡
	1、在适合的位置插入新节点；
	2、修复平衡
	插入在左子树：
		如果父节点是EH时，则修改为LH，继续向上递归；
		如果父节点是LH时，则需要左平衡，旋转一次或者两次；
		如果父节点是RH时，则修改为EH；
	插入在右子树：
		如果父节点是EH时，则修改为RH，继续向上递归；
		如果父节点是RH时，则需要右平衡，旋转一次或者两次；
		如果父节点是LH时，则修改为EH；

二、删除操作和修复平衡
	1、查找关键字的节点，替换并删除真后继；
	2、修复平衡
	删除在左子树：
		如果父节点是EH时，则修改为RH；
		如果父节点是LH时，则修改为EH，继续向上递归；
		如果父节点是RH时，则需要右平衡，旋转一次或者两次；
	删除在右子树：
		如果父节点是EH时，则修改为LH；
		如果父节点是LH时，则需要左平衡，旋转一次或者两次；
		如果父节点是RH时，则修改为EH，继续向上递归；


旋转操作
1) LL型
由于在A的左子树根结点B的左子树上插入结点，使A的平衡因子由1增至2而失去平衡。故需进行一次向右顺时针旋转操作； 
即将A的左孩子B向右上旋转代替A作为根结点，A向右下旋转成为B的右子树的根结点。而原来B的右子树则变成A的左子树；
2) RR型
由于在A的右子树根结点B的右子树上插入结点，使A的平衡因子由-1增至-2而失去平衡。故需进行一次向左顺时针旋转操作；
3) LR型
由于在A的左子树根结点B的右子树上插入结点，使A的平衡因子由1增至2而失去平衡。故需进行两次旋转操作，先左旋再右旋；
4) RL型
由于在A的右子树根结点B的左子树上插入结点，使A的平衡因子由-1增至-2而失去平衡。故需进行两次旋转操作，先左旋再右旋；




https://www.cnblogs.com/xlzhh/p/4222957.html

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
	avl.insert(8);
	avl.insert(6);
	avl.insert(7);

	for (long i = 0; i < 1000000; i++)
	{
		int newKey = (rand() << 16) + rand();
		avl.insert(newKey);
	}

	cout << "节点数量：" << avl.count() << endl;
	cout << "节点高度：" << avl.heigh() << endl;

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

	cout << "节点数量：" << avl.count() << endl;
	cout << "节点高度：" << avl.heigh() << endl;

	//avl.print();

	getchar();
    return 0;
}

