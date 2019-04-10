// 6.1BinarySortTree.cpp : 定义控制台应用程序的入口点。
//

/*
二叉搜索树(二叉排序树、二叉排序树)：
（1）若左子树不空，则左子树上所有结点的值均小于它的根结点的值；
（2）若右子树不空，则右子树上所有结点的值均大于它的根结点的值；
（3）左子树、右子树也分别为二叉排序树；

查找：如果相等当前节点则返回节点，如果小于当前节点则在左子树中继续查找，如果大于当前节点则在右子树继续查找，O(logN)
删除：O(logN)
插入：把新值作为叶子节点插入，O(logN)

如果出现左斜树或右斜树的情况，查找、删除和插入为O(N)；

结构优化：如果是左斜树或者右斜树，算法效率等于N，为了效率接近logN，可以采用其他自平衡的二叉搜索树，比如AVL树、红黑树；

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

	cout << "最大元素:" << bst.search_maximum() << endl;
	cout << "最小元素:" << bst.search_minimun() << endl;
	cout << "节点数量:" << bst.count() << endl;
	cout << "树的高度:" << bst.height() << endl;

	cout << "前序遍历：" << endl;
	bst.preOrder();
	cout << "中序遍历：" << endl;
	bst.inOrder();
	cout << "后序遍历：" << endl;
	bst.postOrder();
	cout << "层次遍历：" << endl;
	bst.layerOrder();

	cout << "===============================================" << endl;
	cout << "删除元素99 35 35 95 62" << endl;
	bst.remove(99);
	bst.remove(35);
	bst.remove(35);
	bst.remove(95);
	bst.remove(62);

	cout << "最大元素:" << bst.search_maximum() << endl;
	cout << "最小元素:" << bst.search_minimun() << endl;
	cout << "节点数量:" << bst.count() << endl;
	cout << "树的高度:" << bst.height() << endl;

	cout << "前序遍历：" << endl;
	bst.preOrder();
	cout << "中序遍历：" << endl;
	bst.inOrder();
	cout << "后序遍历：" << endl;
	bst.postOrder();
	cout << "层次遍历：" << endl;
	bst.layerOrder();

	bst.destory();

	getchar();
    return 0;
}

