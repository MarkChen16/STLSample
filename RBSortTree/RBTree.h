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

	RBTree():mRoot(nullptr), mHot(nullptr), mSize(0)
	{
	}

	~RBTree()
	{
		clear();
	}

	//查找、插入、删除
	iterator search(T v);
	iterator insert(T v);
	bool remove(T v);
	bool remove(iterator &iter);

	//获得最大值和最小值
	iterator minValue();
	iterator maxValue();

	//获得区间范围
	iterator lower_bound(T v);		//返回不小于v的迭代器
	iterator upper_bound(T v);		//返回大于v的迭代器

	//清除整棵树
	void clear();

	//返回树的大小
	int size();

	//返回树的高
	int heigh();

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

	int heigh(RB_Node *p, int intHeigh);	//计算树的高

	void removeTree(RB_Node * &p);		//删除树(dfs后序遍历)

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
		//找出右子树最靠左的节点
		RB_Node *ptn = rc;
		if (ptn == nullptr) return ptn;

		while (ptn->lc != nullptr)
		{
			ptn = ptn->lc;
		}

		return ptn;
	}

	//找出前继(迭代器使用)
	RB_Node *leftNode()
	{
		RB_Node *ptn = this;

		if (lc == nullptr)
		{
			//没有左节点：向上查找右孩子是自己的父节点
			while (ptn->ftr != nullptr && ptn->ftr->lc == ptn)
			{
				ptn = ptn->ftr;
			}

			ptn = ptn->ftr;
		}
		else
		{
			//如果有左节点：向下查找左子树最靠的节点
			ptn = ptn->lc;
			while (ptn->rc != nullptr)
			{
				ptn = ptn->rc;
			}
		}

		return ptn;
	}

	//找出后继(迭代器使用)
	RB_Node *rightNode()
	{
		RB_Node *ptn = this;

		if (rc == nullptr)
		{
			//没有右孩节点：找到左孩子是自己的父节点
			while (ptn->ftr != nullptr && ptn->ftr->rc == ptn)
			{
				ptn = ptn->ftr;
			}

			ptn = ptn->ftr;
		}
		else
		{
			//如果有右孩节点：向下找出右子树最靠左的节点
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
	iterator(iterator const& iter) :realNode(iter.realNode) {}

	iterator& operator =(iterator const& iter)
	{
		realNode = iter.realNode;
		return *this;
	}

	T operator *()
	{
		return realNode->val;
	}

	bool operator ==(iterator const& iter)
	{
		return realNode == iter.realNode;
	}

	bool operator !=(iterator const& iter)
	{
		return realNode != iter.realNode;
	}

	bool operator !()
	{
		return !realNode;
	}

	iterator& operator ++(int)
	{
		if (realNode != nullptr) realNode = realNode->rightNode();
		return *this;
	}

	iterator& operator --(int)
	{
		if (realNode != nullptr) realNode = realNode->leftNode();
		return *this;
	}
};

template<class T>
inline void RBTree<T>::init(T v)
{
	//插入第一个节点，设置为黑色
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
	//RR-1（父亲是红色，LL和RR旋转一下，染色两次；LR和RL旋转两次，染色两次）
	//RR-2（父亲是红色，叔叔不为空且是红色，染色三次，向上递归爷爷节点）
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
			pGftr->rbc = RB_COLOR_RED;		//染红爷爷

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
inline void RBTree<T>::SolveLostBlack(RB_Node *nn)
{
	while (nn != mRoot) {
		RB_Node* pftr = nn->ftr;
		RB_Node* bthr = bro(nn);

		//LB-1：判断兄弟是否红色
		if (bthr->rbc == RB_COLOR_RED) 
		{
			//LB-1
			bthr->rbc = RB_COLOR_BLACK;
			pftr->rbc = RB_COLOR_RED;

			if (mRoot == pftr) 
			{
				mRoot = bthr;
			}

			if (pftr->lc == nn) 
			{
				zag(pftr);
			}
			else 
			{
				zig(pftr);
			}

			//重新赋值兄弟和父亲节点继续递归
			bthr = bro(nn);
			pftr = nn->ftr;
		}

		//LB-3：是否有红色侄子
		if (bthr->lc && bthr->lc->rbc == RB_COLOR_RED)
		{
			//LB-3
			RB_COLOR oldRBc = pftr->rbc;
			pftr->rbc = RB_COLOR_BLACK;

			if (pftr->lc == nn) 
			{
				//近侄子
				if (mRoot == pftr)
				{
					mRoot = bthr->lc;
				}

				zig(bthr); zag(pftr);
			}
			else 
			{
				//远侄子
				bthr->lc->rbc = RB_COLOR_BLACK;
				if (mRoot == pftr)
				{
					mRoot = bthr;
				}

				zig(pftr);
			}

			pftr->ftr->rbc = oldRBc;
			return;
		}
		else if (bthr->rc && bthr->rc->rbc == RB_COLOR_RED)
		{
			//LB-3
			RB_COLOR oldRBc = pftr->rbc;
			pftr->rbc = RB_COLOR_BLACK;

			if (pftr->lc == nn) 
			{
				bthr->rc->rbc = RB_COLOR_BLACK;
				if (mRoot == pftr)
				{
					mRoot = bthr;
				}

				zag(pftr);
			}
			else 
			{
				if (mRoot == pftr)
				{
					mRoot = bthr->rc;
				}

				zag(bthr); zig(pftr);
			}

			pftr->ftr->rbc = oldRBc;
			return;
		}

		if (pftr->rbc == RB_COLOR_RED)
		{
			//LB-2R：父亲是红色
			bthr->rbc = RB_COLOR_RED;
			pftr->rbc = RB_COLOR_BLACK;
			return;
		}
		else 
		{
			//LB-2B：父亲是黑色，兄弟也是黑色
			bthr->rbc = RB_COLOR_RED;
			nn = pftr;
		}
	}
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
inline int RBTree<T>::heigh(RB_Node * p, int intHeigh)
{
	if (nullptr != p) intHeigh++;
	else return intHeigh;

	int h1 = heigh(p->lc, intHeigh);
	int h2 = heigh(p->rc, intHeigh);

	return h1 > h2 ? h1 : h2;
}

template<class T>
inline void RBTree<T>::removeTree(RB_Node * &p)
{
	if (p == nullptr) return;

	if (p->lc != nullptr) removeTree(p->lc);
	if (p->rc != nullptr) removeTree(p->rc);

	delete p;
	p = nullptr;
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
	//查找是否已经存在
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

	//作为红色节点插入到其他位置，并做双红修正
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
inline bool RBTree<T>::remove(T v)
{
	RB_Node* ptn = find(v);
	RB_Node* node_suc = nullptr;

	//没有找到
	if (ptn == nullptr) 
	{
		return false;
	}

	//查找真后继
	while (ptn->lc || ptn->rc) 
	{
		if (!(ptn->lc)) 
		{
			node_suc = ptn->rc;
		}
		else if (!(ptn->rc)) 
		{
			node_suc = ptn->lc;
		}
		else
		{
			node_suc = ptn->succ();
		}

		ptn->val = node_suc->val;	//替换为后继的值
		ptn = node_suc;				//后继作为删除的节点
	}

	if (ptn->rbc == RB_COLOR_BLACK) 
	{
		//如果删除的节点是黑色的，处理失黑修正
		SolveLostBlack(ptn);
	}

	//设置父节点的左孩或右孩为空
	if (ptn->ftr)
	{
		if (ptn->ftr->lc == ptn) 
		{
			ptn->ftr->lc = NULL;
		}
		else
		{
			ptn->ftr->rc = NULL;
		}
	}

	//判断是否根节点
	if (mRoot == ptn) 
	{
		mRoot = NULL;
	}
	
	delete ptn;
	--mSize;

	return true;
}

template<class T>
inline bool RBTree<T>::remove(iterator &iter)
{
	RB_Node* ptn = iter.realNode;
	RB_Node* node_suc = nullptr;

	//迭代器指向NULL
	if (ptn == nullptr)
	{
		return false;
	}

	//修改迭代器指向下一个节点，没有的话，则指向上一个节点
	iter.realNode = ptn->right_node();
	if (!(iter.realNode)) 
	{
		iter.realNode = ptn->left_node();
	}

	//查找后继或者前驱
	while (ptn->lc || ptn->rc) 
	{
		if (!(ptn->lc)) 
		{
			node_suc = ptn->rc;
		}
		else if (!(ptn->rc))
		{
			node_suc = ptn->lc;
		}
		else 
		{
			node_suc = ptn->succ();
		}

		ptn->val = node_suc->val;
		ptn = node_suc;
	}

	//失黑修正
	if (ptn->rbc == RB_COLOR_BLACK) {
		SolveLostBlack(ptn);
	}

	//设置父节点的左孩或右孩为空
	if (ptn->ftr) 
	{
		if (ptn->ftr->lc == ptn)
		{
			ptn->ftr->lc = NULL;
		}
		else
		{
			ptn->ftr->rc = NULL;
		}
	}

	//判断是否根节点
	if (mRoot == ptn) 
	{
		mRoot = NULL;
	}

	delete ptn;
	mSize--;

	return true;
}

template<class T>
	typename
inline RBTree<T>::iterator RBTree<T>::minValue()
{
	RB_Node *ptn = mRoot;
	while (ptn->lc != nullptr)
	{
		ptn = ptn->lc;
	}

	return iterator(ptn);
}

template<class T>
	typename
inline RBTree<T>::iterator RBTree<T>::maxValue()
{
	RB_Node *ptn = mRoot;
	while (ptn->rc != nullptr)
	{
		ptn = ptn->rc;
	}

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

	if (mHot != nullptr)
	{
		if (mHot->val >= v)
		{
			ptn = mHot;
		}
		else
		{
			ptn = mHot->rightNode();
		}
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

	if (mHot != nullptr)
	{
		if (mHot->val > v)
		{
			ptn = mHot;
		}
		else
		{
			ptn = mHot->rightNode();
		}
	}

	return iterator(ptn);
}

template<class T>
inline void RBTree<T>::clear()
{
	removeTree(mRoot);
	mHot = nullptr;
	mSize = 0;
}

template<class T>
inline int RBTree<T>::size()
{
	return mSize;
}

template<class T>
inline int RBTree<T>::heigh()
{
	return heigh(mRoot, 0);
}

template<class T>
inline bool RBTree<T>::empty()
{
	return mSize == 0;
}

template<class T>
	typename
inline RBTree<T>::iterator RBTree<T>::begin()
{
	//找出最左的节点
	RB_Node *ptn = mRoot;
	while (ptn->lc != nullptr)
	{
		ptn = ptn->lc;
	}

	return iterator(ptn);
}

template<class T>
	typename
inline RBTree<T>::iterator RBTree<T>::end()
{
	return iterator(nullptr);
}

