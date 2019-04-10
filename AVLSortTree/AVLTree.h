#pragma once


#define LH +1	//���
#define EH 0	//�ȸ�
#define RH -1	//�Ҹ�

//AVL���Ľڵ�
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

//�����������
template <typename T>
class AVLTree
{
public:
	AVLTree();
	~AVLTree();

	AVLNode<T>* search_Iterator(T key);        //�����ؽ��в���
	AVLNode<T>* search_recursion(T key);        //�ݹ�ؽ��в���

	AVLNode<T>* successor(AVLNode<T>* x);      //����ָ���ڵ�ĺ�̽ڵ�
	AVLNode<T>* predecessor(AVLNode<T>* x);    //����ָ���ڵ��ǰ���ڵ�

	void insert(T key);		//����ָ��ֵ�ڵ�
	bool remove(T key);		//ɾ��ָ��ֵ�ڵ�
	void clear();			//���ٶ�����
	void print();			//��ӡ���

protected:
	AVLNode<T>* root;	//�������ĸ��ڵ�

private:

protected:
	AVLNode<T>* search(AVLNode<T>* & p, T key);
	bool remove(AVLNode<T>*  p, T key);
	void inOrder(AVLNode<T>* p);
	void clear(AVLNode<T>* &p);
};



