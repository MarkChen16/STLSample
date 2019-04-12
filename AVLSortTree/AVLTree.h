#pragma once

#include <iostream>
#include <deque>

using namespace std;

#define EH		0	//�ȸ�
#define LH		1	//���
#define RH		-1	//�Ҹ�

//AVL���Ľڵ�
template <typename T>
struct AVLNode
{
	AVLNode(T t) : value(t), lchild(nullptr), rchild(nullptr), bf(EH) {}

	T value;	//�ڵ��ֵ
	int bf;		//ƽ������
	AVLNode<T>* lchild;		//��
	AVLNode<T>* rchild;		//�Һ�
};

//AVL��
template <typename T>
class AVLTree
{
public:
	AVLTree();
	~AVLTree();

	AVLNode<T>* search(T key);		//����ָ��ֵ�Ľڵ�
	bool insert(T key);				//����ָ��ֵ�Ľڵ�
	bool remove(T key);				//ɾ��ָ��ֵ�Ľڵ�
	void clear();					//���������

	int heigh();					//���ĸ߶�
	int count();					//���Ľڵ�����
	void print();					//��ӡ���

protected:
	AVLNode<T>* root;	//�������ĸ��ڵ�
	int intCount;		//�ڵ������

private:

protected:
	bool insert(AVLNode<T>* &parent, T key, bool &taller);
	bool remove(AVLNode<T>* &parent, T key, bool &lower);
	void clear(AVLNode<T>* &p);

	int heigh(AVLNode<T>* p, int intHeigh);

	void preOrder(AVLNode<T>* p);
	void inOrder(AVLNode<T>* p);
	void postOrder(AVLNode<T>* p);

	void leftBalance(AVLNode<T>* &pNodeA);		//��ƽ��
	void rightBalance(AVLNode<T>* &pNodeA);		//��ƽ��
	void rotate_L(AVLNode<T>* &k2);				//������ת
	void rotate_R(AVLNode<T>* &k2);				//������ת
};

template<typename T>
inline AVLTree<T>::AVLTree()
{
	root = nullptr;
	intCount = 0;
}

template<typename T>
inline AVLTree<T>::~AVLTree()
{
	clear(); 
}

template<typename T>
inline AVLNode<T>* AVLTree<T>::search(T key)
{
	AVLNode<T> *pNode = root;

	while (nullptr != pNode)
	{
		if (key == pNode->value)
		{
			return pNode;
		}
		else if (key > pNode->value)
		{
			pNode = pNode->rchild;
		}
		else
		{
			pNode = pNode->lchild;
		}
	}

	return nullptr;
}

template<typename T>
inline bool AVLTree<T>::insert(T key)
{
	bool isTaller = false;
	return insert(root, key, isTaller);
}

template<typename T>
inline bool AVLTree<T>::remove(T key)
{
	bool isLower = false;
	return remove(root, key, isLower);
}

template<typename T>
inline void AVLTree<T>::clear()
{
	clear(root);
	intCount = 0;
}

template<typename T>
inline int AVLTree<T>::heigh()
{
	return heigh(root, 0);
}

template<typename T>
inline int AVLTree<T>::count()
{
	return intCount;
}

template<typename T>
inline void AVLTree<T>::print()
{
	preOrder(root);
	cout << endl;
}

template<typename T>
inline bool AVLTree<T>::insert(AVLNode<T>* &parent, T key, bool &taller)
{
	if (nullptr == parent)
	{
		//�ҵ�����λ��
		parent = new AVLNode<T>(key);
		intCount++;

		taller = true;
		return true;
	}
	else
	{
		if (key == parent->value)
		{
			//����Ѿ�����
			taller = false;
			return false;
		}
		else if (key < parent->value)
		{
			//������������
			if (!insert(parent->lchild, key, taller)) return false;

			if (taller)
			{
				switch (parent->bf)
				{
				case EH:
					//�ȸ߱�Ϊ���
					parent->bf = LH;
					taller = true;	//���������޸ĸ��ڵ��ƽ������
					break;
				case LH:
					//�����Ҫƽ��
					leftBalance(parent);
					taller = false;	//ƽ��֮�󣬲��������޸ĸ��ڵ��ƽ������
					break;
				case RH:
					//�Ҹ߱�Ϊ�ȸ�
					parent->bf = EH;
					taller = false;	//ԭ�����Ҹߣ������������뵼��ƽ��
					break;
				}
			}
		}
		else
		{
			//������������
			if (!insert(parent->rchild, key, taller)) return false;

			if (taller)
			{
				switch (parent->bf)
				{
				case EH:
					//�ȸ߱�Ϊ�Ҹ�
					parent->bf = RH;
					taller = true;	//���������޸ĸ��ڵ��ƽ������
					break;
				case LH:
					//��߱�Ϊ�ȸ�
					parent->bf = EH;
					taller = false;	//ԭ������ߣ������������뵼��ƽ��
					break;
				case RH:
					//�Ҹ���Ҫƽ��
					rightBalance(parent);
					taller = false;	//ƽ��֮�󣬲��������޸ĸ��ڵ��ƽ������
					break;
				}
			}
		}
	}

	return true;
}

template<typename T>
inline bool AVLTree<T>::remove(AVLNode<T>* &parent, T key, bool & lower)
{
	bool isLeft = false, isRight = false;

	if (nullptr == parent)
	{
		//û���ҵ�
		lower = false;
		return false;
	}
	else if (key < parent->value)
	{
		//��������ɾ������
		if (!remove(parent->lchild, key, lower)) return false;

		isLeft = true;
	}
	else if (key > parent->value)
	{
		//��������ɾ������
		if (!remove(parent->rchild, key, lower)) return false;

		isRight = true;
	}
	else
	{
		AVLNode<T> *pDel = nullptr;
		
		if (nullptr == parent->rchild)
		{
			//��ɾ�ڵ���Һ���Ϊ��
			pDel = parent;
			parent = parent->lchild;

			delete pDel;
			pDel = nullptr;

			intCount--;

			lower = true;
			return true;
		}
		else
		{
			//��ɾ�ڵ���Һ��Ӳ�Ϊ�գ�����滻
			AVLNode<T>* parentNode = parent;
			pDel = parent->rchild;

			while (nullptr != pDel->lchild)
			{
				parentNode = pDel;
				pDel = pDel->lchild;
			}

			parent->value = pDel->value;
			if (!remove(parent->rchild, pDel->value, lower)) return false;

			isRight = true;
		}
	}

	//����нڵ㱻ɾ��
	if (lower)
	{
		if (isLeft == true)
		{
			switch (parent->bf)
			{
			case EH:
				//ûɾ֮ǰEH��ɾ��RH��
				parent->bf = RH;
				lower = false;
				break;
			case LH:
				//ûɾ֮ǰLH��ɾ��EH;
				parent->bf = EH;
				lower = true;
				break;
			case RH:
				//ûɾ֮ǰRH��ɾ�����Ҳ�ƽ��
				rightBalance(parent);
				lower = false;
				break;
			}
		}
		else if (isRight == true)
		{
			switch (parent->bf)
			{
			case EH:
				//ûɾ֮ǰEH��ɾ��LH��
				parent->bf = LH;
				lower = false;
				break;
			case LH:
				//ûɾ֮ǰLH��ɾ������ƽ��
				leftBalance(parent);
				lower = false;
				break;
			case RH:
				//ûɾ֮ǰRH��ɾ��EH;
				parent->bf = EH;
				lower = true;
				break;
			}
		}
	}

	return true;
}

template<typename T>
inline void AVLTree<T>::preOrder(AVLNode<T>* p)
{
	if (nullptr == p) return;

	cout << p->value << "(" << p->bf << ")" << " ";
	inOrder(p->lchild);
	inOrder(p->rchild);
}

template<typename T>
inline void AVLTree<T>::inOrder(AVLNode<T>* p)
{
	if (nullptr == p) return;

	inOrder(p->lchild);
	cout << p->value << "(" << p->bf << ")" << " ";
	inOrder(p->rchild);
}

template<typename T>
inline void AVLTree<T>::postOrder(AVLNode<T>* p)
{
	if (nullptr == p) return;

	inOrder(p->lchild);
	inOrder(p->rchild);
	cout << p->value << "(" << p->bf << ")" << " ";
}

template<typename T>
inline void AVLTree<T>::clear(AVLNode<T>* &p)
{
	if (nullptr == p) return;

	clear(p->lchild);
	clear(p->rchild);

	delete p;
	p = nullptr;
}

template<typename T>
inline int AVLTree<T>::heigh(AVLNode<T>* p, int intHeigh)
{
	if (nullptr != p) intHeigh++;
	else return intHeigh;

	int h1 = heigh(p->lchild, intHeigh);
	int h2 = heigh(p->rchild, intHeigh);

	return h1 > h2 ? h1 : h2;
}

template<typename T>
inline void AVLTree<T>::leftBalance(AVLNode<T>*& pNodeA)
{
	AVLNode<T>* lNode = nullptr, *lrNode = nullptr;

	lNode = pNodeA->lchild;

	switch (lNode->bf)
	{
	case LH:
		//LL����תһ��
		lNode->bf = pNodeA->bf = EH;
		rotate_R(pNodeA);
		break;
	case EH:
		//�������
		lNode->bf = RH;
		pNodeA->bf = LH;
		rotate_R(pNodeA);
		break;
	case RH:
		//LR����ת����
		lrNode = lNode->rchild;

		switch (lrNode->bf)
		{
		case EH:
			lNode->bf = EH;
			pNodeA->bf = EH;
			break;
		case LH:
			lNode->bf = EH;
			pNodeA->bf = RH;
			break;
		case RH:
			lNode->bf = LH;
			pNodeA->bf = EH;
			break;
		}

		lrNode->bf = EH;
		rotate_L(pNodeA->lchild);
		rotate_R(pNodeA);

		break;
	}
}

template<typename T>
inline void AVLTree<T>::rightBalance(AVLNode<T>*& pNodeA)
{
	AVLNode<T>* rNode = nullptr, *rlNode = nullptr;

	rNode = pNodeA->rchild;

	switch (rNode->bf)
	{
	case RH:
		//RR����תһ��
		pNodeA->bf = rNode->bf = EH;
		rotate_L(pNodeA);
		break;
	case EH:
		//�������
		rNode->bf = LH;
		pNodeA->bf = RH;
		rotate_L(pNodeA);
		break;
	case LH:
		//RL����ת����
		rlNode = rNode->lchild;
		switch (rlNode->bf)
		{
		case EH:
			rNode->bf = EH;
			pNodeA->bf = EH;
			break;
		case LH:
			rNode->bf = RH;
			pNodeA->bf = EH;
			break;
		case RH:
			rNode->bf = EH;
			pNodeA->bf = LH;
			break;
		}

		rlNode->bf = EH;
		rotate_R(pNodeA->rchild);
		rotate_L(pNodeA);

		break;
	}
}

template<typename T>
inline void AVLTree<T>::rotate_L(AVLNode<T>*& k2)
{
	/*
	������ת
			k2
				\
				 k1
					\
					new

	*/

	AVLNode<T>* k1 = k2->rchild;

	k2->rchild = k1->lchild;
	k1->lchild = k2;

	k2 = k1;
}

template<typename T>
inline void AVLTree<T>::rotate_R(AVLNode<T>*& k2)
{
	/*
	������ת
			k2
		 /
		k1
	 /
	new

	*/
	AVLNode<T> *k1 = k2->lchild;

	k2->lchild = k1->rchild;
	k1->rchild = k2;

	k2 = k1;
}
