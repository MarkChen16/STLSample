
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
	//ǰ�����
	cout << data;

	if (leftNode != NULL)
		leftNode->PreTraverseBTree();

	if (rightNode != NULL)
		rightNode->PreTraverseBTree();
}

void BTNode::InTraverseBTree()
{
	//�������
	if (leftNode != NULL)
		leftNode->PreTraverseBTree();

	cout << data;

	if (rightNode != NULL)
		rightNode->PreTraverseBTree();
}

void BTNode::PostTraverseBTree()
{
	//�������
	if (leftNode != NULL)
		leftNode->PreTraverseBTree();

	if (rightNode != NULL)
		rightNode->PreTraverseBTree();

	cout << data;
}

void BTNode::LevelTraverseBTree()
{
	static deque<BTNode *> q;

	//��α���
	cout << data;

	//���뺢��ѹ��˫�˶���
	if (NULL != leftNode)
		q.push_back(leftNode);

	if (NULL != rightNode)
		q.push_back(rightNode);

	//��ȡǰ��ڵ㲢����
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
