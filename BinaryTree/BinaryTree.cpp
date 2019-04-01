// BinaryTree.cpp : 定义控制台应用程序的入口点。
//

/*
二叉树：
节点数量为n
度为2
有序的树，左子树 < 节点 < 右子树
表示法：双亲表示法、孩子表示法、双亲孩子表示法、孩子兄弟表示法
存储结构：顺序存储和链式存储

满二叉树和完全二叉树的高度为log2(n)+1，i层的节点数量最多是2^(i-1)

*/


#include "stdafx.h"
#include "BTNode.h"

int main()
{
	
	BTNode *head = new BTNode();

	//ABE##F##CG##H##
	CreateBT(head);

	head->PreTraverseBTree();
	cout << endl;

	head->InTraverseBTree();
	cout << endl;

	head->PostTraverseBTree();
	cout << endl;

	head->LevelTraverseBTree();
	cout << endl;

	DeleteBT(head);

    return 0;
}

