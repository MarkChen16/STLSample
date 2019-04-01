#pragma once


#include "stdafx.h"

class BTNode;

//����������
void CreateBT(BTNode *tn);

//ɾ��������
void DeleteBT(BTNode *tn);

class BTNode
{
public:
	BTNode();
	~BTNode();

	//ǰ�����
	void PreTraverseBTree();

	//�������
	void InTraverseBTree();

	//�������
	void PostTraverseBTree();

	//��α���
	void LevelTraverseBTree();

private:
	char data;
	BTNode *leftNode;
	BTNode *rightNode;

	friend void CreateBT(BTNode *tn);
	friend void DeleteBT(BTNode *tn);
};

