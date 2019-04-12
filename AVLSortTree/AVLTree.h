#pragma once

#include <iostream>
#include <deque>

using namespace std;

#define EH		0	//等高
#define LH		1	//左高
#define RH		-1	//右高

//AVL树的节点
template <typename T>
struct AVLNode
{
	AVLNode(T t) : value(t), lchild(nullptr), rchild(nullptr), bf(EH) {}

	T value;	//节点的值
	int bf;		//平衡因子
	AVLNode<T>* lchild;		//左孩
	AVLNode<T>* rchild;		//右孩
};

//AVL树
template <typename T>
class AVLTree
{
public:
	AVLTree();
	~AVLTree();

	AVLNode<T>* search(T key);		//查找指定值的节点
	bool insert(T key);				//插入指定值的节点
	bool remove(T key);				//删除指定值的节点
	void clear();					//清除二叉树

	int heigh();					//树的高度
	int count();					//树的节点数量
	void print();					//打印输出

protected:
	AVLNode<T>* root;	//二叉树的根节点
	int intCount;		//节点的数量

private:

protected:
	bool insert(AVLNode<T>* &parent, T key, bool &taller);
	bool remove(AVLNode<T>* &parent, T key, bool &lower);
	void clear(AVLNode<T>* &p);

	int heigh(AVLNode<T>* p, int intHeigh);

	void preOrder(AVLNode<T>* p);
	void inOrder(AVLNode<T>* p);
	void postOrder(AVLNode<T>* p);

	void leftBalance(AVLNode<T>* &pNodeA);		//左平衡
	void rightBalance(AVLNode<T>* &pNodeA);		//右平衡
	void rotate_L(AVLNode<T>* &k2);				//向左旋转
	void rotate_R(AVLNode<T>* &k2);				//向右旋转
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
		//找到插入位置
		parent = new AVLNode<T>(key);
		intCount++;

		taller = true;
		return true;
	}
	else
	{
		if (key == parent->value)
		{
			//如果已经存在
			taller = false;
			return false;
		}
		else if (key < parent->value)
		{
			//在左子树插入
			if (!insert(parent->lchild, key, taller)) return false;

			if (taller)
			{
				switch (parent->bf)
				{
				case EH:
					//等高变为左高
					parent->bf = LH;
					taller = true;	//继续向上修改父节点的平衡因子
					break;
				case LH:
					//左高需要平衡
					leftBalance(parent);
					taller = false;	//平衡之后，不再向上修改父节点的平衡因子
					break;
				case RH:
					//右高变为等高
					parent->bf = EH;
					taller = false;	//原来是右高，在左子树插入导入平衡
					break;
				}
			}
		}
		else
		{
			//在右子树插入
			if (!insert(parent->rchild, key, taller)) return false;

			if (taller)
			{
				switch (parent->bf)
				{
				case EH:
					//等高变为右高
					parent->bf = RH;
					taller = true;	//继续向上修改父节点的平衡因子
					break;
				case LH:
					//左高变为等高
					parent->bf = EH;
					taller = false;	//原来是左高，在右子树插入导入平衡
					break;
				case RH:
					//右高需要平衡
					rightBalance(parent);
					taller = false;	//平衡之后，不再向上修改父节点的平衡因子
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
		//没有找到
		lower = false;
		return false;
	}
	else if (key < parent->value)
	{
		//在左子树删除孩子
		if (!remove(parent->lchild, key, lower)) return false;

		isLeft = true;
	}
	else if (key > parent->value)
	{
		//在右子树删除孩子
		if (!remove(parent->rchild, key, lower)) return false;

		isRight = true;
	}
	else
	{
		AVLNode<T> *pDel = nullptr;
		
		if (nullptr == parent->rchild)
		{
			//被删节点的右孩子为空
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
			//被删节点的右孩子不为空，后继替换
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

	//如果有节点被删除
	if (lower)
	{
		if (isLeft == true)
		{
			switch (parent->bf)
			{
			case EH:
				//没删之前EH，删后RH；
				parent->bf = RH;
				lower = false;
				break;
			case LH:
				//没删之前LH，删后EH;
				parent->bf = EH;
				lower = true;
				break;
			case RH:
				//没删之前RH，删后导致右不平衡
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
				//没删之前EH，删后LH；
				parent->bf = LH;
				lower = false;
				break;
			case LH:
				//没删之前LH，删后导致左不平衡
				leftBalance(parent);
				lower = false;
				break;
			case RH:
				//没删之前RH，删后EH;
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
		//LL：旋转一次
		lNode->bf = pNodeA->bf = EH;
		rotate_R(pNodeA);
		break;
	case EH:
		lNode->bf = RH;
		pNodeA->bf = LH;
		rotate_R(pNodeA);
		break;
	case RH:
		//LR：旋转两次
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
		//RR：旋转一次
		pNodeA->bf = rNode->bf = EH;
		rotate_L(pNodeA);
		break;
	case EH:
		rNode->bf = LH;
		pNodeA->bf = RH;
		rotate_L(pNodeA);
		break;
	case LH:
		//RL：旋转两次
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
	向左旋转
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
	向右旋转
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
