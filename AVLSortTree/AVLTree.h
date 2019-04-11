#pragma once

#include <iostream>
#include <deque>

using namespace std;


//AVL���Ľڵ�
template <typename T>
struct AVLNode
{
	AVLNode(T t) : value(t), lchild(nullptr), rchild(nullptr), height(0) {}

	AVLNode() = default;

	T value;
	AVLNode<T>* lchild;
	AVLNode<T>* rchild;

	int height;		//ƽ������
};

//�����������
template <typename T>
class AVLTree
{
public:
	AVLTree();
	~AVLTree();

	AVLNode<T>* search(T key);        //�����ؽ��в���

	void insert(T key);		//����ָ��ֵ�ڵ�
	void remove(T key);		//ɾ��ָ��ֵ�ڵ�
	void clear();			//���ٶ�����

	int count();			//���Ľڵ�����
	void print();			//��ӡ���

protected:
	AVLNode<T>* root;	//�������ĸ��ڵ�
	int intCount;

private:

protected:
	void insert(AVLNode<T>* &parent, T key);
	void remove(AVLNode<T>* &pNode, T key);
	void clear(AVLNode<T>* &p);

	void inOrder(AVLNode<T>* p);

	int height(AVLNode<T>* p);

	void rotateLL(AVLNode<T>* &k2);	//��������������������ڵ�ʱ��ת
	void rotateRR(AVLNode<T>* &k2);	//��������������������ڵ�ʱ��ת
	void rotateLR(AVLNode<T>* &k2);	//��������������������ڵ�ʱ��ת
	void rotateRL(AVLNode<T>* &k2);	//��������������������ڵ�ʱ��ת
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
	intCount = 0;
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
inline void AVLTree<T>::insert(T key)
{
	insert(root, key);
}

template<typename T>
inline void AVLTree<T>::remove(T key)
{
	remove(root, key);
}

template<typename T>
inline void AVLTree<T>::clear()
{
	clear(root);
}

template<typename T>
inline int AVLTree<T>::count()
{
	return intCount;
}

template<typename T>
inline void AVLTree<T>::print()
{
	inOrder(root);
	cout << endl;
}

template<typename T>
inline void AVLTree<T>::insert(AVLNode<T>* &parent, T key)
{
	if (nullptr == parent)
	{
		//���뵽Ҷ�ӽڵ�
		parent = new AVLNode<T>(key);
		intCount++;
	}
	else if (key > parent->value)
	{
		//������������
		insert(parent->rchild, key);

		//������ж��Ƿ���Ҫ��ת
		if (height(parent->lchild) - height(parent->rchild) == -2)
		{
			if (key > parent->rchild->value)
			{
				//���������Һ�
				rotateRR(parent);
			}
			else
			{
				//����������
				rotateRL(parent);
			}
		}
	}
	else
	{
		//������������
		insert(parent->lchild, key);

		//������ж��Ƿ���Ҫ��ת
		if (height(parent->lchild) - height(parent->rchild) == 2)
		{
			if (key <= parent->lchild->value)
			{
				//����������
				rotateLL(parent);
			}
			else
			{
				//���������Һ�
				rotateLR(parent);
			}
		}
	}

	//����Ҷ�ӽڵ��������еĸ��ڵ��ƽ������
	parent->height = height(parent->lchild) - height(parent->rchild);
}

template<typename T>
inline void AVLTree<T>::remove(AVLNode<T>*& pNode, T key)
{
	if (nullptr == pNode)
	{
		return;
	}
	else if (key > pNode->value)
	{
		//��������ɾ������
		remove(pNode->rchild, key);

		//ɾ��֮����ת
		if (height(pNode->lchild) - height(pNode->rchild) == 2)
		{
			if (height(pNode->lchild->lchild) > height(pNode->lchild->rchild))
			{
				rotateLL(pNode);
			}
			else
			{
				rotateLR(pNode);
			}
		}
	}
	else if (key < pNode->value)
	{
		//��������ɾ������
		remove(pNode->lchild, key);

		//ɾ��֮����ת
		if (height(pNode->lchild) - height(pNode->rchild) == -2)
		{
			if (height(pNode->rchild->rchild) > height(pNode->rchild->lchild))
			{
				rotateRR(pNode);
			}
			else
			{
				rotateRL(pNode);
			}
		}
	}
	else if (key == pNode->value && pNode->lchild != nullptr && pNode->rchild != nullptr)
	{
		//�ҳ�ǰ��
		AVLNode<T>* parentNode = pNode;
		AVLNode<T>* preNode = pNode->lchild;

		while (nullptr != preNode->rchild)
		{
			parentNode = preNode;
			preNode = preNode->rchild;
		}

		//ǰ���滻��ɾ��ǰ��
		pNode->value = preNode->value;
		remove(parentNode, preNode->value);
	}
	else
	{
		//���汻ɾ�ڵ�ĺ��ӽڵ�
		AVLNode<T>* pChild = pNode->lchild == NULL ? pNode->rchild : pNode->lchild;
		
		delete pNode;
		pNode = pChild;

		intCount--;
	}

	if (nullptr != pNode)
	{
		pNode->height = height(pNode->lchild) - height(pNode->rchild);
	}
}

template<typename T>
inline void AVLTree<T>::inOrder(AVLNode<T>* p)
{
	if (nullptr == p) return;

	inOrder(p->lchild);
	cout << p->value << "(" << p->height << ")" << " ";
	inOrder(p->rchild);
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
inline int AVLTree<T>::height(AVLNode<T>* p)
{
	if (nullptr == p)
	{
		return 0;
	}
	else
	{
		if (p->height > 0)
		{
			return height(p->lchild) + 1;
		}
		else
		{
			return height(p->rchild) + 1;
		}

		//int h1 = height(p->lchild) + 1;
		//int h2 = height(p->rchild) + 1;

		//return h1 > h2 ? h1 : h2;
	}
}

template<typename T>
inline void AVLTree<T>::rotateLL(AVLNode<T>*& k2)
{
	AVLNode<T> *k1 = k2->lchild;

	k2->lchild = k1->rchild;
	k1->rchild = k2;

	k2->height = height(k2->lchild) - height(k2->rchild);
	k1->height = height(k1->lchild) - height(k1->rchild);

	k2 = k1;
}

template<typename T>
inline void AVLTree<T>::rotateRR(AVLNode<T>*& k2)
{
	AVLNode<T> *k1 = k2->rchild;

	k2->rchild = k1->lchild;
	k1->lchild = k2;

	k1->height = height(k1->lchild), height(k1->rchild);
	k2->height = height(k2->lchild), height(k2->rchild);

	k2 = k1;
}

template<typename T>
inline void AVLTree<T>::rotateLR(AVLNode<T>*& k3)
{
	rotateRR(k3->lchild);
	rotateLL(k3);
}

template<typename T>
inline void AVLTree<T>::rotateRL(AVLNode<T>*& k3)
{
	rotateLL(k3->rchild);
	rotateRR(k3);
}

