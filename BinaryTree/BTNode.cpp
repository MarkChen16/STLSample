
#include "stdafx.h"
#include "BTNode.h"

BTNode::BTNode()
{

}

BTNode::~BTNode()
{

}

void BTNode::PreTraverseBTree()
{
	//前序遍历
	cout << data;

	if (leftNode != NULL)
		leftNode->PreTraverseBTree();

	if (rightNode != NULL)
		rightNode->PreTraverseBTree();
}

void BTNode::InTraverseBTree()
{
	//中序遍历
	if (leftNode != NULL)
		leftNode->PreTraverseBTree();

	cout << data;

	if (rightNode != NULL)
		rightNode->PreTraverseBTree();
}

void BTNode::PostTraverseBTree()
{
	//后序遍历
	if (leftNode != NULL)
		leftNode->PreTraverseBTree();

	if (rightNode != NULL)
		rightNode->PreTraverseBTree();

	cout << data;
}

void BTNode::LevelTraverseBTree()
{
	static deque<BTNode *> q;

	//层次遍历
	cout << data;

	//插入孩子压入双端队列
	if (NULL != leftNode)
		q.push_back(leftNode);

	if (NULL != rightNode)
		q.push_back(rightNode);

	//提取前面节点并弹出
	if (q.size() != 0)
	{
		BTNode *nextNode = q.front();
		q.pop_front();

		nextNode->LevelTraverseBTree();
	}
}

void CreateBT(BTNode * tn)
{
	char ucData = 0;
	cin >> ucData;

	if (ucData == '#' || ucData == 0x00)
	{
		tn->data = '#';
		tn->leftNode = NULL;
		tn->rightNode = NULL;
	}
	else
	{
		tn->data = ucData;

		tn->leftNode = new BTNode();
		CreateBT(tn->leftNode);

		tn->rightNode = new BTNode();
		CreateBT(tn->rightNode);
	}
}

void DeleteBT(BTNode * tn)
{
	if (tn->leftNode != NULL) DeleteBT(tn->leftNode);
	if (tn->rightNode != NULL) DeleteBT(tn->rightNode);

	delete tn;
}
