#pragma once


#include "stdafx.h"

class BTNode;

//创建二叉树
void CreateBT(BTNode *tn);

//删除二叉树
void DeleteBT(BTNode *tn);

class BTNode
{
public:
	BTNode();
	~BTNode();

	//前序遍历
	void PreTraverseBTree();

	//中序遍历
	void InTraverseBTree();

	//后序遍历
	void PostTraverseBTree();

	//层次遍历
	void LevelTraverseBTree();

private:
	char data;
	BTNode *leftNode;
	BTNode *rightNode;

	friend void CreateBT(BTNode *tn);
	friend void DeleteBT(BTNode *tn);
};

