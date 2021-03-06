#include "BinaryTree.h"
#include "cirqueue.h"
#include <iostream>

using namespace std;

template<class T>
BiNode<T>* BinaryTree<T>::Create(BiNode<T>* bt)  //涉及到递归 这样的，不用内联好不好
{
	T ch;
	cin >> ch;

	if (ch == '#')
		bt = NULL;
	else
	{
		bt = new BiNode<T>;
		bt->data = ch;
		bt->lchild = Create(bt->lchild);
		bt->rchild = Create(bt->rchild);//以类似前序遍历的方式建立二叉树
	}
	return bt;

}

template<class T>
void BinaryTree<T>::Release(BiNode<T>* bt)
{
	if (bt != NULL)
	{
		Release(bt->lchild);
		Release(bt->rchild);
		delete bt; //释放根节点 在释放某结点时，该结点的左右都子树已经释放，所以应该采用后序遍历。
	}
}

template<class T>
void BinaryTree<T>::PreOrder(BiNode<T>* bt)
{
	if (bt == NULL)
		return;
	cout << bt->data;
	PreOrder(bt->lchild);
	PreOrder(bt->rchild);
}

template<class T>
void BinaryTree<T>::InOrder(BiNode<T>* bt)
{
	if (bt == NULL)
		return;
	InOrder(bt->lchild);
	cout << bt->data;
	InOrder(bt->rchild);
}

template<class T>
void BinaryTree<T>::PostOrder(BiNode<T>* bt)
{
	if (bt == NULL)
		return;
	PostOrder(bt->lchild);
	PostOrder(bt->rchild);
	cout << bt->data;
}

template<class T>
void BinaryTree<T>::LeverOrder()
{
	queue<BiNode<T>*> Q; // queue<T> Q 不行吗? 应该是不行的，因为之前定义data[]的时候用的是<T> 所以这里确实应该如这里
	Q.front = Q.rear = -1;
	if (root == NULL)
		return;

	Q.data[++Q.rear] = root; //首先入队root
	while (Q.front!=Q.rear) //相等时即队空
	{
		BiNode<T>* q = Q.data[++Q.front];    // 出队
		cout << q->data<<endl; // 根里的数据
		if (q->lchild != NULL)
			Q.data[++Q.rear] = q->lchild;    // 左孩子入队
		if (q->rchild != NULL)
			Q.data[++Q.rear] = q->rchild;    // 右孩子入队
	}

//}
//
//
//int main()
//{
//
//	BinaryTree<char>* bitree = new BinaryTree<char>();        // 创建一棵二叉树,使用new就调用的构造函数
//
//	bitree->PreOrder();                             // 前序遍历
//	cout << endl;
//	bitree->InOrder();                              // 中序遍历
//	cout << endl;
//	bitree->PostOrder();                            // 后序遍历
//	cout << endl;
//	bitree->LeverOrder();                           // 层序遍历
//	delete bitree;
//
//	system("pause");
//	return 0;
}