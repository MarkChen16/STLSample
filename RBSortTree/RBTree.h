#pragma once

//找出x节点的兄弟
#define bro(x) (((x)->ftr->lc == (x))? ((x)->ftr->rc) : ((x)->ftr->lc))

//定义节点的颜色
typedef bool RB_COLOR;
#define RB_COLOR_RED	true
#define RB_COLOR_BLACK	false

//红黑树定义
template<class T>
class RBTree
{
public:
	struct iterator;

	RBTree():mRoot(nullptr), mHot(nullptr), mSize(0){}

	//查找、插入、删除
	iterator search(T v);
	iterator insert(T v);
	bool remove(T v);
	bool remove(iterator iter);

	//获得范围
	iterator lower_bound(T v);
	iterator upper_bound(T v);

	//清除整棵树
	void clear();

	//返回树的大小
	int size();

	//返回是否为空树
	bool empty();

	iterator begin();			//返回开始的迭代器
	static iterator end();		//返回结束的迭代器

protected:
	struct RB_Node;

	RB_Node *mRoot;		//根节点
	RB_Node *mHot;		//父节点
	int mSize;			//节点的数量

	void init(T);		//树的初始化

	RB_Node *zig(RB_Node *);	//左平衡
	RB_Node *zag(RB_Node *);	//右平衡

	void SolveDoubleRed(RB_Node *);		//双红修正
	void SolveLostBlack(RB_Node *);		//失黑修正

	RB_Node *find(T v);	//查找节点

	void removeTree(RB_Node *);		//删除树(dfs后序遍历)


private:

};

//红黑树节点定义
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

	//找出真后继(简化后继函数，删除时使用)
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

	//找出前继
	RB_Node *leftNode()
	{
		RB_Node *ptn = this;

		if (lc == nullptr)
		{
			//没有左节点：找到自己是父节点的右孩子
			while (ptn->ftr != nullptr && ptn->ftr->lc == ptn)
			{
				ptn = ptn->ftr;
			}

			ptn = ptn->ftr;
		}
		else
		{
			//如果有左节点
			ptn = ptn->lc;
			while (ptn->rc != nullptr)
			{
				ptn = ptn->rc;
			}
		}

		return ptn;
	}

	//找出后继
	RB_Node *rightNode()
	{
		RB_Node *ptn = this;

		if (rc == nullptr)
		{
			//没有右节点：找到自己是父节点的右孩子
			while (ptn->ftr != nullptr && ptn->ftr->rc == ptn)
			{
				ptn = ptn->ftr;
			}

			ptn = ptn->ftr;
		}
		else
		{
			//如果有左节点
			ptn = ptn->rc;
			while (ptn->lc != nullptr)
			{
				ptn = ptn->lc;
			}
		}

		return ptn;
	}
};

//迭代器
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
	//性质一：根节点是黑色的
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
			//ptn是父亲的左孩
			ptn->ftr->lc = ptn->lc;
		}
		else
		{ 
			//ptn是父亲的右孩
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
			//ptn是父亲的左孩
			ptn->ftr->lc = ptn->rc;
		}
		else
		{
			//ptn是父亲的右孩
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
	//双红修正
	//RR-0 (没有出现双红)
	//RR-1（父亲是红色，出现双红，叔叔是黑色，LL和RR旋转一下，染色两次；LR和RL旋转两次，染色两次）
	//RR-2（父亲是红色，出现双红，叔叔是红色，染色三次，向上递归爷爷节点）
	while ( (nn->ftr != nullptr) && nn->ftr->rbc == RB_COLOR_RED )	//排除递归到根和RR-0情况
	{
		RB_Node *pFtr = nn->ftr;		//父节点
		RB_Node *pGftr = pFtr->ftr;		//祖父节点
		RB_Node *pUncle = bro(pFtr);	//叔叔

		if (pUncle != nullptr && pUncle->rbc == RB_COLOR_RED)
		{
			//RR-2情况：染色三次
			pFtr->rbc = RB_COLOR_BLACK;		//染黑父亲
			pUncle->rbc = RB_COLOR_BLACK;	//染黑叔叔
			pGftr->rbc = RB_COLOR_RED;		//当红爷爷

			nn = pGftr;						//从爷爷开始递归，重复以上操作
		}
		else
		{
			//RR-1情况
			if (pGftr->lc == pFtr)
			{
				//在左子树插入
				if (pFtr->lc == nn)
				{
					//左子树的左孩位置插入，旋转一次和染色两次
					if (pGftr == mRoot)
					{
						mRoot = pFtr;
					}

					zig(pGftr);		//左平衡

					pFtr->rbc = RB_COLOR_BLACK;		//染黑父亲
					pGftr->rbc = RB_COLOR_RED;		//染红爷爷
				}
				else
				{
					//左子树的右孩位置插入，旋转两次和染色两次
					if (pGftr == mRoot)
					{
						mRoot = nn;
					}

					zag(pFtr);	//右平衡
					zig(pGftr);	//左平衡

					nn->rbc = RB_COLOR_BLACK;		//染黑自己
					pGftr->rbc = RB_COLOR_RED;		//染红爷爷
				}
			}
			else
			{
				//在右子树插入
				if (pFtr->rc == nn)
				{
					//右子树的右孩位置插入，旋转一次和染色两次
					if (pGftr == mRoot)
					{
						mRoot = pFtr;
					}

					zag(pGftr);	//右平衡

					pFtr->rbc = RB_COLOR_BLACK;		//染黑父亲
					pGftr->rbc = RB_COLOR_RED;		//染红爷爷
				}
				else
				{
					//异向旋转两次，染色两次
					if (pGftr == mRoot)
					{
						mRoot = nn;
					}

					zig(pFtr);	//左平衡
					zag(pGftr);	//右平衡

					nn->rbc = RB_COLOR_BLACK;		//染黑自己
					pGftr->rbc = RB_COLOR_RED;		//染红爷爷
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

	//是空树时，当黑节点插入到根节点
	if (mHot == nullptr)
	{
		init(v);
		return iterator(mRoot);
	}

	//当红节点插入到其他位置，并做双红修正
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

	//双红修正
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

