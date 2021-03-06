//https://www.cnblogs.com/WindSun/p/10871398.html
#pragma once

#include<iostream>
using namespace std;

template<typename T>
struct ThreadNode
{
	int ltag, rtag;
	ThreadNode<T>* lchild, * rchild;
	T data;

	//类似有参构造函数
	ThreadNode(const T item) :data(item), lchild(NULL), rchild(NULL), ltag(0), rtag(0) {};

};


template<typename T>
class ThreadTree
{
public:
	 //构造函数(普通)
	ThreadTree() :root(NULL) {};

	//指定结束标志RefValue的构造函数
	ThreadTree(T value) : RefValue(value), root(NULL) {};

	//使用前序遍历创建二叉树(未线索化)
	void CreateTree() { CreatePreTree(root); }

	//中序遍历对创建好的普通二叉树进行中序线索化
	void CreateInThread()
	{
		ThreadNode<T>* pre = NULL;	//第一个节点的pre置为NULL
		if (root != NULL)
		{
			createInThread(root, pre);
			pre->rchild = NULL;
			pre->rtag = 1; //处理中序遍历的最后一个节点，将最后一个节点的右子树置为空
		}
	}

    //线索化二叉树上执行中序遍历的算法
	void InOrder() { InOrder(root); }
	 //中序线索化二叉树上实现前序遍历的算法
	void PreOrder() { PreOrder(root); }
	 //中序线索二叉树的后序遍历算法
	void PostOrder() { PostOrder(root); }

private:

	ThreadNode<T>* root;
	T RefValue; //这是啥--》类似于之前的'#'标志，表示空结点

	//使用前序遍历创建二叉树（未线索化）(使用前中后顺序遍历创建的结果是一样的,只是输入不一样)
	void CreatePreTree(ThreadNode<T>*& subTree) //使用了指针的引用
	{
		T item;
		if (cin >> item)
		{
			if (item != RefValue)
			{
				subTree = new ThreadNode<T>(item); //构造节点
				if (subTree == NULL)
				{
					cout << "空间分配错误" << endl;
					exit(1);
				}
				CreatePreTree(subTree->lchild);
				CreatePreTree(subTree->rchild);
			}
			else
			{
				subTree = NULL;
			}
		}

	}

	//中序遍历对二叉树进行线索化
	void createInThread(ThreadNode<T>* current, ThreadNode<T>*& pre) /*为什么current不用引用而pre用引用呢 发现current指针从头到尾没有进行过
		赋值,而pre经常需要做pre=current处理，如果不这样处理的话，感觉递归起来还蛮麻烦的，我甚至想象不出来里面发生了啥 */
	{
		if (current == NULL)
		{
			return;
		}
		createInThread(current->lchild, pre);
		if (current->lchild == NULL)
		{
			current->lchild = pre;
			current->ltag = 1;//表示是线索
		}
		if (pre != NULL && pre->rchild == NULL)
		{
			pre->rchild = current;
			pre->rtag = 1;
		}
		pre = current;
		createInThread(current->rchild, pre);
	

	}

	//寻找中序下第一个结点
	ThreadNode<T>* First(ThreadNode<T>* current)//返回以current为根的中序线索二叉树中序遍历的第一个结点
	{
		ThreadNode<T> *p = current;
		while (!p->ltag)
			p = p->lchild;
		return p;

	}

	//寻找中序下的后继结点
	ThreadNode<T>* Next(ThreadNode<T>* current)
	{
		ThreadNode<T>* p = current->rchild;
		if (current->rtag == 0)
			return First(p); //我原以为是First（current）,这里容易错
		else
			return p;
	}

	//寻找中序下的最后一个结点
	ThreadNode<T>* Last(ThreadNode<T>* current)
	{
		ThreadNode<T>* p = current;
		while (p->rtag == 0)
			p = p->rchild;

		return p;
	}

	//寻找结点在中序下的前驱结点
	ThreadNode<T>* Prior(ThreadNode<T>* current)
	{
		ThreadNode<T>* p = current->rchild;
		if (current->ltag == 0)
			return Last(p);
			
		else
			return p;

		
	}

	//中序线索化二叉树中求父节点
	ThreadNode<T>* Parent(ThreadNode<T>* t) //不太明白为什么这样找一定能找到
	{
		ThreadNode<T>* p;
		if (t == root)
			return NULL;

		for (p = t; p->ltag == 0; p = p->lchild); //一直由t求到t作为根的子树的中序下的第一个结点p

		//情况1
		if (p->lchild != NULL) //当p左子树指向不为空，则其有前驱
		{
			//令p为p的左子树指向的结点，判断此结点是否并为空且此节点的左右子树结点的指向都不为t，再将p为p的右孩子结点
			for (p = p->lchild; p != NULL && p->lchild != t && p->rchild != t; p = p->rchild);
		}
		//情况2
		//如果上面的循环完了，由于是p==NULL结束的循环，没有找到与t相等的结点；或者就是上面一直找到了中序线索化的第一个结点了，这时候这种就要用到情况2的方法
		if (p == NULL || p->lchild == NULL)//或者是左子树为空，表明是中序线索化的第一个节点了
		{
			//找到*t为根的中序下的最后一个结点
			for (p = t; p->rtag == 0; p = p->rchild);
			//然后让他指向最后一个结点指向的结点，从这个结点开始，判以次判断它的左孩子和右孩子是否和t相等
			for (p = p->rchild; p != NULL && p->lchild != t && p->rchild != t; p = p->lchild);
		}

		return p;
	
	}

	//中序线索化二叉树上执行中序遍历的算法
	void InOrder(ThreadNode<T>* p)
	{
		for (p = First(root); p != NULL; p = Next(p))
		{
			cout << p->data << " ";
		}
		cout << endl;
	}

	//中序线索化二叉树上实现前序遍历的算法
	void PreOrder(ThreadNode<T>* p)
	{
		while (p != NULL)
		{
			cout << p->data << " ";//先访问根节点
			if (p->ltag == 0)
			{
				p = p->lchild;

			}
			else if (p->rtag==0)
			{
				p = p->rchild;
			}
			else //此时的分支表示是叶子节点,无左右子树
			{
				while (p != NULL && p->rtag == 1)
				{
					p = p->rchild; //直到找到有右子树的节点。即p->rtag为0
				}
				if (p != NULL)
				{
					p = p->rchild;
				}
			}
			
		}
		cout << endl;
	
	}

	//中序线索二叉树的后序遍历算法
	void PostOrder(ThreadNode<T>* p)
	{
		ThreadNode<T>* t = p;
		while (t->ltag == 0 || t->rtag == 0) //向左下找到后序的第一个结点
		{
			if (t->ltag == 0)
				t = t->lchild;
			else if (t->rtag == 0)
				t = t->rchild;
		}
		cout << t->data << " ";//访问第一个结点

		while ((p = Parent(t)) != NULL) //每次都先找到当前结点的父节点
		{
			/*若当前结点是父节点的右子树或者当前结点是左子树，但是这个
			父节点没有右子树，则后序下的后继为改父节点*/
			if (p->rchild == t || p->rtag == 1)
				t = p;
			else//否则，在当前结点的右子树上重复执行上面的操作
			{
				t = p->rchild;
				while (t->ltag == 0 || t->rtag == 0)
				{
					if (t->ltag == 0)
						t = t->lchild;
					else if (t->rchild == 0)
						t = t->rchild;
				}
				
			}
			

			cout << t->data << " ";
		}
	}

};


