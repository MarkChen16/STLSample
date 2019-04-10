#pragma once

#include <iostream>
#include <deque>

using namespace std;


//����������Ľڵ�ṹ
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

//�����������
template <typename T>
class BSTree
{
public:
	BSTree();
	~BSTree();

	void preOrder();    //ǰ�����������
	void inOrder();        //�������������
	void postOrder();    //�������������
	void layerOrder();    //��α���������

	BSNode<T>* search_recursion(T key);        //�ݹ�ؽ��в���
	BSNode<T>* search_Iterator(T key);        //�����ؽ��в���

	T search_minimun(); //������СԪ��
	T search_maximum(); //�������Ԫ��

	BSNode<T>* successor(BSNode<T>* x);    //����ָ���ڵ�ĺ�̽ڵ�
	BSNode<T>* predecessor(BSNode<T>* x);    //����ָ���ڵ��ǰ���ڵ�

	void insert(T key);    //����ָ��ֵ�ڵ�
	bool remove(T key);    //ɾ��ָ��ֵ�ڵ�
	void destory();        //���ٶ�����

	size_t height();	   //���ĸ߶�
	size_t count();		   //�ڵ�����
	void print();		   //��ӡ���

private:
	BSNode<T>* root;	//�������ĸ��ڵ�
	size_t mCount;		//�ڵ������

	deque< BSNode<T>* > layerList;	//����������

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

//���캯��
template<typename T>
BSTree<T>::BSTree()
{
	root = nullptr;
	mCount = 0;
}

//��������
template<typename T>
BSTree<T>::~BSTree()
{
	if (nullptr != root) destory();
}

/*ǰ������㷨*/
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

/*��������㷨*/
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

/*��������㷨*/
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

/*��α����㷨*/
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

	//����Լ�
	cout << p->value << " ";

	//����󺢺��Һ�
	if (nullptr != p->lchild) layerList.push_back(p->lchild);
	if (nullptr != p->rchild) layerList.push_back(p->rchild);

	//����ǰ��һ���ݹ����
	if (layerList.size() > 0)
	{
		BSNode<T> *currNode = layerList.front();
		layerList.pop_front();

		layerOrder(currNode);
	}
}

/*Ѱ����ǰ���ڵ�(��������)*/
template <typename T>
BSNode<T>* BSTree<T>::predecessor(BSNode<T>* pnode)
{
	//�����������
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

		while (pparent != nullptr && pparent->lchild == pnode)	//�������ѭ�������ǵ��������������Ϊ�ڶ������
		{
			pnode = pparent;
			pparent = pparent->parent;
		}

		return pparent;
	}
}

/*Ѱ�����̽ڵ�(��������)*/
template <typename T>
BSNode<T>* BSTree<T>::successor(BSNode<T>* pnode)
{
	//�����������
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

/*����ָ��Ԫ�صĽڵ㣨�ǵݹ飩*/
template <typename T>
BSNode<T>* BSTree<T>::search_Iterator(T key)
{
	BSNode<T> * pnode = root;

	while (pnode != nullptr)
	{
		if (key == pnode->value)    //�ҵ�
		{
			return pnode;
		}
		if (key > pnode->value)        //�ؼ��ֱȽڵ�ֵ���ڽڵ�����������
		{
			pnode = pnode->rchild;
		}
		else
		{
			pnode = pnode->lchild; //�ؼ��ֱȽڵ�ֵС���ڽڵ�����������
		}
	}

	return nullptr;
}

/*����ָ��Ԫ�صĽڵ㣨�ݹ飩*/
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

	//cout << "-->" << pnode->value << endl; //�����������·��

	if (key > pnode->value)
	{
		return search(pnode->rchild, key);
	}
	else
	{
		return search(pnode->lchild, key);
	}
};

/*�����½ڵ�*/
template <typename T>
void BSTree<T>::insert(T key)
{
	//Ѱ�Һ��ʵĲ���λ��
	BSNode<T>* pparent = nullptr;
	BSNode<T>* pnode = root;

	while (pnode != nullptr)
	{
		pparent = pnode;

		if (key > pnode->value)	pnode = pnode->rchild;
		else if (key < pnode->value) pnode = pnode->lchild;
		else break;
	}

	//�����µ�Ҷ�ӽڵ�
	pnode = new BSNode<T>(key); //��Ԫ�ص�ֵ�����½ڵ�

	if (pparent == nullptr)            //����ǿ���
	{
		root = pnode;                  //���½ڵ�Ϊ��
	}
	else
	{
		if (key > pparent->value)
			pparent->rchild = pnode; //�����½ڵ�Ϊ�丸�ڵ����
		else
			pparent->lchild = pnode; //���Һ�
	}

	pnode->parent = pparent;        //ָ���½ڵ�ĸ��ڵ� 
	mCount++;
}

/*ɾ��ָ���ڵ�*/
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
				//�������������ɾ�ڵ�ֻ��������������������û�к���
				pdel = pnode;
			}
			else
			{
				//���һ����ɾ�ڵ�ͬʱ��������������ɾ���ýڵ��ǰ��
				pdel = predecessor(pnode);
			}

			//��ʱ����ɾ�ڵ�ֻ��һ�����ӣ���û�к��ӣ�������ú���ָ��
			BSNode<T>* pchild = nullptr;
			if (pdel->lchild != nullptr) pchild = pdel->lchild;
			else pchild = pdel->rchild;

			//�ú���ָ��ɾ���ڵ�ĸ��ڵ�
			if (pchild != nullptr) pchild->parent = pdel->parent;

			//���Ҫɾ���Ľڵ���ͷ�ڵ㣬ע�����root��ֵ
			if (pdel->parent == nullptr) root = pchild;

			//���Ҫɾ���Ľڵ㲻��ͷ�ڵ㣬Ҫע���������˫�׽ڵ�ָ���µĺ��ӽڵ�
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

/*Ѱ����СԪ��*/
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

/*Ѱ�����Ԫ��*/
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

/*���ٶ�����*/
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

/*���ĸ߶�*/
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

/*�ڵ������*/
template<typename T>
size_t BSTree<T>::count()
{
	return mCount;
}

/*��ӡ���������*/
template<typename T>
void BSTree<T>::print()
{
	inOrder();
}
