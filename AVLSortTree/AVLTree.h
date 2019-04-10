#pragma once


#define LH +1	//左高
#define EH 0	//等高
#define RH -1	//右高

//AVL树的节点
template <typename T>
struct AVLNode
{
	AVLNode(T t) : value(t), lchild(nullptr), rchild(nullptr), height(0) {}

	AVLNode() = default;

	T value;
	AVLNode<T>* lchild;
	AVLNode<T>* rchild;

	int height;
};

//二叉查找树类
template <typename T>
class AVLTree
{
public:
	AVLTree();
	~AVLTree();

	AVLNode<T>* search_Iterator(T key);        //迭代地进行查找
	AVLNode<T>* search_recursion(T key);        //递归地进行查找

	AVLNode<T>* successor(AVLNode<T>* x);      //查找指定节点的后继节点
	AVLNode<T>* predecessor(AVLNode<T>* x);    //查找指定节点的前驱节点

	void insert(T key);		//插入指定值节点
	bool remove(T key);		//删除指定值节点
	void clear();			//销毁二叉树
	void print();			//打印输出

protected:
	AVLNode<T>* root;	//二叉树的根节点

private:

protected:
	AVLNode<T>* search(AVLNode<T>* & p, T key);
	bool remove(AVLNode<T>*  p, T key);
	void inOrder(AVLNode<T>* p);
	void clear(AVLNode<T>* &p);
};



