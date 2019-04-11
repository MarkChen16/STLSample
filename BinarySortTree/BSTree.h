#pragma once

#include <iostream>
#include <deque>

using namespace std;


//����������Ľڵ�ṹ
template <typename T>
struct BSNode
{
	BSNode(T t) : value(t), lchild(nullptr), rchild(nullptr), parent(nullptr){}

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

	BSNode<T>* search_Iterator(T key);        //�����ؽ��в���
	BSNode<T>* search_recursion(T key);        //�ݹ�ؽ��в���

	T search_minimun(); //������СԪ��
	T search_maximum(); //�������Ԫ��

	BSNode<T>* predecessor(BSNode<T>* x);    //����ָ���ڵ��ǰ���ڵ�
	BSNode<T>* successor(BSNode<T>* x);    //����ָ���ڵ�ĺ�̽ڵ�

	void insert(T key);    //����ָ��ֵ�ڵ�
	bool remove(T key);    //ɾ��ָ��ֵ�ڵ�
	void clear();        //���ٶ�����

	size_t height();	   //���ĸ߶�
	size_t count();		   //�ڵ�����
	void print();		   //��ӡ���

protected:
	BSNode<T>* root;	//�������ĸ��ڵ�
	size_t mCount;		//�ڵ������

private:
	deque< BSNode<T>* > layerList;	//����������

protected:
	BSNode<T>* search(BSNode<T>* & p, T key);
	bool remove(BSNode<T>*  p, T key);

	void preOrder(BSNode<T>* p);
	void inOrder(BSNode<T>* p);
	void postOrder(BSNode<T>* p);
	void layerOrder(BSNode<T> *p);

	T search_minimun(BSNode<T>* p);
	T search_maximum(BSNode<T>* p);
	void clear(BSNode<T>* &p);

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
	if (nullptr != root) clear();
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

	//����ؼ��ֵ�Ҷ�ӽڵ�
	pnode = new BSNode<T>(key); //��Ԫ�ص�ֵ�����½ڵ�

	//����ǿ���
	if (pparent == nullptr)
	{
		root = pnode;  //���½ڵ�Ϊ��
	}
	else
	{
		if (key > pparent->value) pparent->rchild = pnode; //���ڸ��ڵ㣬���뵽�Һ�
		else pparent->lchild = pnode; //С����ȸ��ڵ㣬���뵽��
	}

	pnode->parent = pparent;        //ָ�����ڵ� 
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

			//�����ǰ�����桢���Ӽ̳С�ֱ��ɾ��
			if (pnode->lchild != nullptr && pnode->rchild != nullptr)
			{
				//���һ����ɾ�ڵ�ͬʱ������������ǰ������
				pdel = predecessor(pnode);
			}
			else if (pnode->lchild == nullptr && pnode->rchild == nullptr)
			{
				//���������ɾ�ڵ�û������������ֱ��ɾ��
				pdel = pnode;
			}
			else
			{
				//���������ɾ�ڵ�ֻ��������������ֻ����������ֱ��ɾ������Ӽ̳�
				pdel = pnode;
			}

			//���ı�ɾ�ڵ�ĺ��ӽڵ�ĸ��ڵ�=================================================================
			//��ʱ����ɾ�ڵ�ֻ���󺢻��Һ�������û�к��ӣ�����ú���ָ��
			BSNode<T>* pchild = nullptr;
			if (nullptr != pdel->lchild)
			{
				pchild = pdel->lchild;
			}
			else if (nullptr != pdel->rchild)
			{
				pchild = pdel->rchild;
			}

			//�ú���ָ��ɾ���ڵ�ĸ��ڵ�
			if (nullptr != pchild)
			{
				pchild->parent = pdel->parent;
			}

			//���ı�ɾ�ڵ�ĸ��ڵ�ĺ��ӽڵ�=================================================================
			BSNode<T>* pdelParent = pdel->parent;
			if (pdelParent == nullptr)
			{
				//�����ɾ�ڵ���ͷ�ڵ㣬ע�����root��ֵ
				root = pchild;
			}
			else if (pdelParent->lchild == pdel)
			{
				//����˫�׽ڵ�ָ���µĺ��ӽڵ�
				pdelParent->lchild = pchild;
			}
			else if (pdelParent->rchild == pdel)
			{
				//����˫�׽ڵ�ָ���µĺ��ӽڵ�
				pdelParent->rchild = pchild;
			}

			//�滻����ɾ���ڵ��ֵ=================================================================
			if (pnode->value != pdel->value) pnode->value = pdel->value;

			//�ͷű�ɾ�ڵ���ڴ�
			delete pdel;
			mCount--;

			return true;
		}
		else if (key > pnode->value)
		{
			return remove(pnode->rchild, key);
		}
		else
		{
			return remove(pnode->lchild, key);
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
void BSTree<T>::clear()
{
	clear(root);
	mCount = 0;
}

template <typename T>
void BSTree<T>::clear(BSNode<T>* &p)
{
	if (p != nullptr)
	{
		if (p->lchild != nullptr) clear(p->lchild);
		if (p->rchild != nullptr) clear(p->rchild);

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
