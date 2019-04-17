#pragma once

//�ҳ�x�ڵ���ֵ�
#define bro(x) (((x)->ftr->lc == (x))? ((x)->ftr->rc) : ((x)->ftr->lc))

//����ڵ����ɫ
typedef bool RB_COLOR;
#define RB_COLOR_RED	true
#define RB_COLOR_BLACK	false

//���������
template<class T>
class RBTree
{
public:
	struct iterator;

	RBTree():mRoot(nullptr), mHot(nullptr), mSize(0){}

	//���ҡ����롢ɾ��
	iterator search(T v);
	iterator insert(T v);
	bool remove(T v);
	bool remove(iterator iter);

	//��÷�Χ
	iterator lower_bound(T v);
	iterator upper_bound(T v);

	//���������
	void clear();

	//�������Ĵ�С
	int size();

	//�����Ƿ�Ϊ����
	bool empty();

	iterator begin();			//���ؿ�ʼ�ĵ�����
	static iterator end();		//���ؽ����ĵ�����

protected:
	struct RB_Node;

	RB_Node *mRoot;		//���ڵ�
	RB_Node *mHot;		//���ڵ�
	int mSize;			//�ڵ������

	void init(T);		//���ĳ�ʼ��

	RB_Node *zig(RB_Node *);	//��ƽ��
	RB_Node *zag(RB_Node *);	//��ƽ��

	void SolveDoubleRed(RB_Node *);		//˫������
	void SolveLostBlack(RB_Node *);		//ʧ������

	RB_Node *find(T v);	//���ҽڵ�

	void removeTree(RB_Node *);		//ɾ����(dfs�������)


private:

};

//������ڵ㶨��
template<class T>
struct RBTree<T>::RB_Node
{
	T val;
	RB_COLOR rbc;

	RB_Node *ftr;
	RB_Node *lc;
	RB_Node *rc;

	RB_Node(T v = T(), RB_COLOR rbcolor = true, RB_Node *f = nullptr, RB_Node *lchild = nullptr, RB_Node *rchild = nullptr)
		:val(v), rbc(rbcolor), ftr(f), lc(lchild), rc(rchild)
	{

	}

	//�ҳ�����(�򻯺�̺�����ɾ��ʱʹ��)
	RB_Node *succ()
	{
		RB_Node *ptn = rc;
		if (ptn == nullptr) return ptn;

		while (ptn->lc != nullptr)
		{
			ptn = ptn->lc;
		}

		return ptn;
	}

	//�ҳ�ǰ��
	RB_Node *leftNode()
	{
		RB_Node *ptn = this;

		if (lc == nullptr)
		{
			//û����ڵ㣺�ҵ��Լ��Ǹ��ڵ���Һ���
			while (ptn->ftr != nullptr && ptn->ftr->lc == ptn)
			{
				ptn = ptn->ftr;
			}

			ptn = ptn->ftr;
		}
		else
		{
			//�������ڵ�
			ptn = ptn->lc;
			while (ptn->rc != nullptr)
			{
				ptn = ptn->rc;
			}
		}

		return ptn;
	}

	//�ҳ����
	RB_Node *rightNode()
	{
		RB_Node *ptn = this;

		if (rc == nullptr)
		{
			//û���ҽڵ㣺�ҵ��Լ��Ǹ��ڵ���Һ���
			while (ptn->ftr != nullptr && ptn->ftr->rc == ptn)
			{
				ptn = ptn->ftr;
			}

			ptn = ptn->ftr;
		}
		else
		{
			//�������ڵ�
			ptn = ptn->rc;
			while (ptn->lc != nullptr)
			{
				ptn = ptn->lc;
			}
		}

		return ptn;
	}
};

//������
template<class T>
struct RBTree<T>::iterator
{
protected:
	RB_Node *realNode;

public:
	iterator(RB_Node * p = nullptr) :realNode(p) {}
	iterator(T const& val) :realNode(find(val)) {}
	iterator(iterator const& iter) :realNode(iter->realNode) {}

	iterator& operator =(iterator const& iter)
	{
		realNode = iter->realNode;
		return *this;
	}

	T operator *()
	{
		return realNode->val;
	}

	bool operator ==(iterator const& iter)
	{
		return realNode == iter->realNode;
	}

	bool operator !()
	{
		return !realNode;
	}

	iterator& operator ++()
	{
		realNode = realNode->rightNode();
		return *this;
	}

	iterator& operator --()
	{
		realNode = realNode->leftNode();
		return *this;
	}
};

template<class T>
inline void RBTree<T>::init(T v)
{
	//����һ�����ڵ��Ǻ�ɫ��
	mRoot = new RB_Node(v, RB_COLOR_BLACK);
	mSize = 1;
}

template<class T>
	typename
inline RBTree<T>::RB_Node * RBTree<T>::zig(RB_Node *ptn)
{
	ptn->lc->ftr = ptn->ftr;
	if (ptn->ftr != nullptr)
	{
		if (ptn->ftr->lc == ptn)
		{
			//ptn�Ǹ��׵���
			ptn->ftr->lc = ptn->lc;
		}
		else
		{ 
			//ptn�Ǹ��׵��Һ�
			ptn->ftr->rc = ptn->lc;
		}
	}

	if (ptn->lc->rc != nullptr)
	{
		ptn->lc->rc->ftr = ptn;
	}

	ptn->ftr = ptn->lc;
	ptn->lc = ptn->lc->rc;
	ptn->ftr->rc = ptn;

	return ptn->ftr;
}

template<class T>
	typename
inline RBTree<T>::RB_Node * RBTree<T>::zag(RB_Node *ptn)
{
	ptn->rc->ftr = ptn->ftr;
	if (ptn->ftr != nullptr)
	{
		if (ptn->ftr->lc == ptn)
		{
			//ptn�Ǹ��׵���
			ptn->ftr->lc = ptn->rc;
		}
		else
		{
			//ptn�Ǹ��׵��Һ�
			ptn->ftr->rc = ptn->rc;
		}
	}

	if (ptn->rc->lc != nullptr)
	{
		ptn->rc->lc->ftr = ptn;
	}

	ptn->ftr = ptn->rc;
	ptn->rc = ptn->rc->lc;
	ptn->ftr->lc = ptn;

	return ptn->ftr;
}

template<class T>
inline void RBTree<T>::SolveDoubleRed(RB_Node *nn)
{
	//˫������
	//RR-0 (û�г���˫��)
	//RR-1�������Ǻ�ɫ������˫�죬�����Ǻ�ɫ��LL��RR��תһ�£�Ⱦɫ���Σ�LR��RL��ת���Σ�Ⱦɫ���Σ�
	//RR-2�������Ǻ�ɫ������˫�죬�����Ǻ�ɫ��Ⱦɫ���Σ����ϵݹ�үү�ڵ㣩
	while ( (nn->ftr != nullptr) && nn->ftr->rbc == RB_COLOR_RED )	//�ų��ݹ鵽����RR-0���
	{
		RB_Node *pFtr = nn->ftr;		//���ڵ�
		RB_Node *pGftr = pFtr->ftr;		//�游�ڵ�
		RB_Node *pUncle = bro(pFtr);	//����

		if (pUncle != nullptr && pUncle->rbc == RB_COLOR_RED)
		{
			//RR-2�����Ⱦɫ����
			pFtr->rbc = RB_COLOR_BLACK;		//Ⱦ�ڸ���
			pUncle->rbc = RB_COLOR_BLACK;	//Ⱦ������
			pGftr->rbc = RB_COLOR_RED;		//����үү

			nn = pGftr;						//��үү��ʼ�ݹ飬�ظ����ϲ���
		}
		else
		{
			//RR-1���
			if (pGftr->lc == pFtr)
			{
				//������������
				if (pFtr->lc == nn)
				{
					//����������λ�ò��룬��תһ�κ�Ⱦɫ����
					if (pGftr == mRoot)
					{
						mRoot = pFtr;
					}

					zig(pGftr);		//��ƽ��

					pFtr->rbc = RB_COLOR_BLACK;		//Ⱦ�ڸ���
					pGftr->rbc = RB_COLOR_RED;		//Ⱦ��үү
				}
				else
				{
					//���������Һ�λ�ò��룬��ת���κ�Ⱦɫ����
					if (pGftr == mRoot)
					{
						mRoot = nn;
					}

					zag(pFtr);	//��ƽ��
					zig(pGftr);	//��ƽ��

					nn->rbc = RB_COLOR_BLACK;		//Ⱦ���Լ�
					pGftr->rbc = RB_COLOR_RED;		//Ⱦ��үү
				}
			}
			else
			{
				//������������
				if (pFtr->rc == nn)
				{
					//���������Һ�λ�ò��룬��תһ�κ�Ⱦɫ����
					if (pGftr == mRoot)
					{
						mRoot = pFtr;
					}

					zag(pGftr);	//��ƽ��

					pFtr->rbc = RB_COLOR_BLACK;		//Ⱦ�ڸ���
					pGftr->rbc = RB_COLOR_RED;		//Ⱦ��үү
				}
				else
				{
					//������ת���Σ�Ⱦɫ����
					if (pGftr == mRoot)
					{
						mRoot = nn;
					}

					zig(pFtr);	//��ƽ��
					zag(pGftr);	//��ƽ��

					nn->rbc = RB_COLOR_BLACK;		//Ⱦ���Լ�
					pGftr->rbc = RB_COLOR_RED;		//Ⱦ��үү
				}
			}

			break;
		}
	}

	if (nn == mRoot) nn->rbc = RB_COLOR_BLACK;
}

template<class T>
	typename
inline RBTree<T>::RB_Node * RBTree<T>::find(T v)
{
	RB_Node *ptn = mRoot;
	mHot = nullptr;

	while (ptn != nullptr && ptn->val != v)
	{
		mHot = ptn;
		if (v > ptn->val)
		{
			ptn = ptn->rc;
		}
		else
		{
			ptn = ptn->lc;
		}
	}

	return ptn;
}

template<class T>
	typename
inline RBTree<T>::iterator RBTree<T>::search(T v)
{
	return iterator(find(v));
}

template<class T>
	typename
inline RBTree<T>::iterator RBTree<T>::insert(T v)
{
	RB_Node *ptn = find(v);

	if (ptn != nullptr)
	{
		return iterator(ptn);
	}

	//�ǿ���ʱ�����ڽڵ���뵽���ڵ�
	if (mHot == nullptr)
	{
		init(v);
		return iterator(mRoot);
	}

	//����ڵ���뵽����λ�ã�����˫������
	mSize++;
	ptn = new RB_Node(v, RB_COLOR_RED, mHot);

	if (mHot->val > v)
	{
		mHot->lc = ptn;
	}
	else
	{
		mHot->rc = ptn;
	}

	//˫������
	SolveDoubleRed(ptn);

	return iterator(ptn);
}

template<class T>
	typename
inline RBTree<T>::iterator RBTree<T>::lower_bound(T v)
{
	RB_Node *ptn = mRoot;
	mHot = nullptr;

	while (ptn != nullptr)
	{
		mHot = ptn;
		if (ptn->val >= v)
		{
			ptn = ptn->lc;
		}
		else
		{
			ptn = ptn->rc;
		}
	}

	if (mHot->val >= v)
	{
		ptn = mHot;
	}
	else
	{
		ptn = mHot->rightNode();
	}

	return iterator(ptn);
}

template<class T>
	typename
inline RBTree<T>::iterator RBTree<T>::upper_bound(T v)
{
	RB_Node *ptn = mRoot;
	mHot = nullptr;

	while (ptn != nullptr)
	{
		mHot = ptn;
		if (ptn->val > v)
		{
			ptn = ptn->lc;
		}
		else
		{
			ptn = ptn->rc;
		}
	}

	if (mHot->val > v)
	{
		ptn = mHot;
	}
	else
	{
		ptn = mHot->rightNode();
	}

	return iterator(ptn);
}

