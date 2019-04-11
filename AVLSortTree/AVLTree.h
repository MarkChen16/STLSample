#pragma once

#include <iostream>
#include <deque>

using namespace std;


//AVL树的节点
template <typename T>
struct AVLNode
{
	AVLNode(T t) : value(t), lchild(nullptr), rchild(nullptr), height(0) {}

	AVLNode() = default;

	T value;
	AVLNode<T>* lchild;
	AVLNode<T>* rchild;

	int height;		//平衡因子
};

//二叉查找树类
template <typename T>
class AVLTree
{
public:
	AVLTree();
	~AVLTree();

	AVLNode<T>* search(T key);        //迭代地进行查找

	void insert(T key);		//插入指定值节点
	void remove(T key);		//删除指定值节点
	void clear();			//销毁二叉树

	int count();			//树的节点数量
	void print();			//打印输出

protected:
	AVLNode<T>* root;	//二叉树的根节点
	int intCount;

private:

protected:
	void insert(AVLNode<T>* &parent, T key);
	void remove(AVLNode<T>* &pNode, T key);
	void clear(AVLNode<T>* &p);

	void inOrder(AVLNode<T>* p);

	int height(AVLNode<T>* p);

	void rotateLL(AVLNode<T>* &k2);	//在左子树的左子树插入节点时旋转
	void rotateRR(AVLNode<T>* &k2);	//在右子树的右子树插入节点时旋转
	void rotateLR(AVLNode<T>* &k2);	//在左子树的右子树插入节点时旋转
	void rotateRL(AVLNode<T>* &k2);	//在右子树的左子树插入节点时旋转
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
		//插入到叶子节点
		parent = new AVLNode<T>(key);
		intCount++;
	}
	else if (key > parent->value)
	{
		//在右子树插入
		insert(parent->rchild, key);

		//插入后判断是否需要旋转
		if (height(parent->lchild) - height(parent->rchild) == -2)
		{
			if (key > parent->rchild->value)
			{
				//右子树的右孩
				rotateRR(parent);
			}
			else
			{
				//右子树的左孩
				rotateRL(parent);
			}
		}
	}
	else
	{
		//在左子树插入
		insert(parent->lchild, key);

		//插入后判断是否需要旋转
		if (height(parent->lchild) - height(parent->rchild) == 2)
		{
			if (key <= parent->lchild->value)
			{
				//左子树的左孩
				rotateLL(parent);
			}
			else
			{
				//左子树的右孩
				rotateLR(parent);
			}
		}
	}

	//更新叶子节点上面所有的父节点的平衡因子
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
		//在右子树删除孩子
		remove(pNode->rchild, key);

		//删除之后旋转
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
		//在左子树删除孩子
		remove(pNode->lchild, key);

		//删除之后旋转
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
		//找出前驱
		AVLNode<T>* parentNode = pNode;
		AVLNode<T>* preNode = pNode->lchild;

		while (nullptr != preNode->rchild)
		{
			parentNode = preNode;
			preNode = preNode->rchild;
		}

		//前驱替换，删除前驱
		pNode->value = preNode->value;
		remove(parentNode, preNode->value);
	}
	else
	{
		//保存被删节点的孩子节点
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

