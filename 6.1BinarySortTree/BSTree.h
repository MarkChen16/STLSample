#pragma once

#include <iostream>
#include <deque>

using namespace std;


//二叉查找树的节点结构
template <typename T>
struct BSNode
{
	BSNode(T t) : value(t), lchild(nullptr), rchild(nullptr) {}

	BSNode() = default;

	T value;
	BSNode<T>* lchild;
	BSNode<T>* rchild;
	BSNode<T>* parent;
};

//二叉查找树类
template <typename T>
class BSTree
{
public:
	BSTree();
	~BSTree();

	void preOrder();    //前序遍历二叉树
	void inOrder();        //中序遍历二叉树
	void postOrder();    //后序遍历二叉树
	void layerOrder();    //层次遍历二叉树

	BSNode<T>* search_recursion(T key);        //递归地进行查找
	BSNode<T>* search_Iterator(T key);        //迭代地进行查找

	T search_minimun(); //查找最小元素
	T search_maximum(); //查找最大元素

	BSNode<T>* successor(BSNode<T>* x);    //查找指定节点的后继节点
	BSNode<T>* predecessor(BSNode<T>* x);    //查找指定节点的前驱节点

	void insert(T key);    //插入指定值节点
	bool remove(T key);    //删除指定值节点
	void destory();        //销毁二叉树

	size_t height();	   //树的高度
	size_t count();		   //节点数量
	void print();		   //打印输出

private:
	BSNode<T>* root;	//二叉树的根节点
	size_t mCount;		//节点的数量

	deque< BSNode<T>* > layerList;	//层次输出变量

private:
	BSNode<T>* search(BSNode<T>* & p, T key);
	bool remove(BSNode<T>*  p, T key);

	void preOrder(BSNode<T>* p);
	void inOrder(BSNode<T>* p);
	void postOrder(BSNode<T>* p);
	void layerOrder(BSNode<T> *p);

	T search_minimun(BSNode<T>* p);
	T search_maximum(BSNode<T>* p);
	void destory(BSNode<T>* &p);

	size_t height(BSNode<T>* p, size_t h);
};

//构造函数
template<typename T>
BSTree<T>::BSTree()
{
	root = nullptr;
	mCount = 0;
}

//析构函数
template<typename T>
BSTree<T>::~BSTree()
{
	if (nullptr != root) destory();
}

/*前序遍历算法*/
template <typename T>
void BSTree<T>::preOrder()
{
	preOrder(root);
	cout << endl;
}

template <typename T>
void BSTree<T>::preOrder(BSNode<T> *p)
{
	if (p != nullptr)
	{
		cout << p->value << " ";
		preOrder(p->lchild);
		preOrder(p->rchild);
	}
}

/*中序遍历算法*/
template <typename T>
void BSTree<T>::inOrder()
{
	inOrder(root);
	cout << endl;
}

template<typename T>
void BSTree<T>::inOrder(BSNode<T>* p)
{
	if (p != nullptr)
	{
		inOrder(p->lchild);
		cout << p->value << " ";
		inOrder(p->rchild);
	}
}

/*后序遍历算法*/
template <typename T>
void BSTree<T>::postOrder()
{
	postOrder(root);
	cout << endl;
}

template <typename T>
void BSTree<T>::postOrder(BSNode<T>* p)
{
	if (p != nullptr)
	{
		postOrder(p->lchild);
		postOrder(p->rchild);
		cout << p->value << " ";
	}
}

/*层次遍历算法*/
template<typename T>
void BSTree<T>::layerOrder()
{
	layerList.clear();

	layerOrder(root);
	cout << endl;
}

template<typename T>
void BSTree<T>::layerOrder(BSNode<T> *p)
{
	if (nullptr == p) return;

	//输出自己
	cout << p->value << " ";

	//添加左孩和右孩
	if (nullptr != p->lchild) layerList.push_back(p->lchild);
	if (nullptr != p->rchild) layerList.push_back(p->rchild);

	//弹出前面一个递归调用
	if (layerList.size() > 0)
	{
		BSNode<T> *currNode = layerList.front();
		layerList.pop_front();

		layerOrder(currNode);
	}
}

/*寻找其前驱节点(中序排序)*/
template <typename T>
BSNode<T>* BSTree<T>::predecessor(BSNode<T>* pnode)
{
	//如果有左子树
	if (nullptr != pnode->lchild)
	{
		pnode = pnode->lchild;

		while (pnode->rchild != nullptr)
		{
			pnode = pnode->rchild;
		}

		return pnode;
	}
	else
	{
		BSNode<T>* pparent = pnode->parent;

		while (pparent != nullptr && pparent->lchild == pnode)	//如果进入循环，则是第三种情况；否则为第二种情况
		{
			pnode = pparent;
			pparent = pparent->parent;
		}

		return pparent;
	}
}

/*寻找其后继节点(中序排序)*/
template <typename T>
BSNode<T>* BSTree<T>::successor(BSNode<T>* pnode)
{
	//如果有右子树
	if (pnode->rchild != nullptr)
	{
		pnode = pnode->rchild;

		while (pnode->lchild != nullptr)
		{
			pnode = pnode->lchild;
		}

		return pnode;
	}
	else
	{
		BSNode<T>* pparent = pnode->parent;

		while (pparent != nullptr&& pparent->rchild == pnode)
		{
			pnode = pparent;
			pparent = pparent->parent;
		}

		return pparent;
	}
};

/*查找指定元素的节点（非递归）*/
template <typename T>
BSNode<T>* BSTree<T>::search_Iterator(T key)
{
	BSNode<T> * pnode = root;

	while (pnode != nullptr)
	{
		if (key == pnode->value)    //找到
		{
			return pnode;
		}
		if (key > pnode->value)        //关键字比节点值大，在节点右子树查找
		{
			pnode = pnode->rchild;
		}
		else
		{
			pnode = pnode->lchild; //关键字比节点值小，在节点左子树查找
		}
	}

	return nullptr;
}

/*查找指定元素的节点（递归）*/
template <typename T>
BSNode<T>* BSTree<T>::search_recursion(T key)
{
	return search(root, key);
}

template <typename T>
BSNode<T>* BSTree<T>::search(BSNode<T>* & pnode, T key)
{
	if (pnode == nullptr) return nullptr;

	if (pnode->value == key)
	{
		return pnode;
	}

	//cout << "-->" << pnode->value << endl; //可以输出查找路径

	if (key > pnode->value)
	{
		return search(pnode->rchild, key);
	}
	else
	{
		return search(pnode->lchild, key);
	}
};

/*插入新节点*/
template <typename T>
void BSTree<T>::insert(T key)
{
	//寻找合适的插入位置
	BSNode<T>* pparent = nullptr;
	BSNode<T>* pnode = root;

	while (pnode != nullptr)
	{
		pparent = pnode;

		if (key > pnode->value)	pnode = pnode->rchild;
		else if (key < pnode->value) pnode = pnode->lchild;
		else break;
	}

	//插入新的叶子节点
	pnode = new BSNode<T>(key); //以元素的值构建新节点

	if (pparent == nullptr)            //如果是空树
	{
		root = pnode;                  //则新节点为根
	}
	else
	{
		if (key > pparent->value)
			pparent->rchild = pnode; //否则新节点为其父节点的左孩
		else
			pparent->lchild = pnode; //或右孩
	}

	pnode->parent = pparent;        //指明新节点的父节点 
	mCount++;
}

/*删除指定节点*/
template <typename T>
bool BSTree<T>::remove(T key)
{
	return remove(root, key);
}

template <typename T>
bool BSTree<T>::remove(BSNode<T>* pnode, T key)
{
	if (pnode != nullptr)
	{
		if (pnode->value == key)
		{
			BSNode<T>* pdel = nullptr;

			if (pnode->lchild == nullptr || pnode->rchild == nullptr)
			{
				//情况二、三：被删节点只有左子树或右子树，或没有孩子
				pdel = pnode;
			}
			else
			{
				//情况一：被删节点同时有左右子树，则删除该节点的前驱
				pdel = predecessor(pnode);
			}

			//此时，被删节点只有一个孩子（或没有孩子），保存该孩子指针
			BSNode<T>* pchild = nullptr;
			if (pdel->lchild != nullptr) pchild = pdel->lchild;
			else pchild = pdel->rchild;

			//让孩子指向被删除节点的父节点
			if (pchild != nullptr) pchild->parent = pdel->parent;

			//如果要删除的节点是头节点，注意更改root的值
			if (pdel->parent == nullptr) root = pchild;

			//如果要删除的节点不是头节点，要注意更改它的双亲节点指向新的孩子节点
			else if (pdel->parent->lchild == pdel)
			{
				pdel->parent->lchild = pchild;
			}
			else
			{
				pdel->parent->rchild = pchild;
			}

			if (pnode->value != pdel->value) pnode->value = pdel->value;

			delete pdel;
			mCount--;

			return true;
		}
		else if (key > pnode->value)
		{
			remove(pnode->rchild, key);
		}
		else
		{
			remove(pnode->lchild, key);
		}
	}
	else
	{
		return false;
	}
}

/*寻找最小元素*/
template <typename T>
T BSTree<T>::search_minimun()
{
	return search_minimun(root);
}

template <typename T>
T BSTree<T>::search_minimun(BSNode<T>* p)
{
	if (nullptr == p) return T();

	if (p->lchild != nullptr) return search_minimun(p->lchild);

	return p->value;
}

/*寻找最大元素*/
template <typename T>
T BSTree<T>::search_maximum()
{
	return search_maximum(root);
}

template <typename T>
T BSTree<T>::search_maximum(BSNode<T>*p)
{
	if (nullptr == p) return T();

	if (p->rchild != nullptr) return search_maximum(p->rchild);

	return p->value;
}

/*销毁二叉树*/
template<typename T>
void BSTree<T>::destory()
{
	destory(root);
	mCount = 0;
}

template <typename T>
void BSTree<T>::destory(BSNode<T>* &p)
{
	if (p != nullptr)
	{
		if (p->lchild != nullptr) destory(p->lchild);
		if (p->rchild != nullptr) destory(p->rchild);

		delete p;
		p = nullptr;
	}
}

/*树的高度*/
template<typename T>
size_t BSTree<T>::height()
{
	return height(root, 0);
}

template<typename T>
size_t BSTree<T>::height(BSNode<T>* p, size_t h)
{
	if (nullptr != p) h++;
	else return h;

	size_t h1 = height(p->lchild, h);
	size_t h2 = height(p->rchild, h);

	if (h1 > h2) return h1;
	else return h2;
}

/*节点的数量*/
template<typename T>
size_t BSTree<T>::count()
{
	return mCount;
}

/*打印输出二叉树*/
template<typename T>
void BSTree<T>::print()
{
	inOrder();
}
