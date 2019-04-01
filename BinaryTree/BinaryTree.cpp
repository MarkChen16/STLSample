// BinaryTree.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
��������
�ڵ�����Ϊn
��Ϊ2
��������������� < �ڵ� < ������
��ʾ����˫�ױ�ʾ�������ӱ�ʾ����˫�׺��ӱ�ʾ���������ֵܱ�ʾ��
�洢�ṹ��˳��洢����ʽ�洢

������������ȫ�������ĸ߶�Ϊlog2(n)+1��i��Ľڵ����������2^(i-1)

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

