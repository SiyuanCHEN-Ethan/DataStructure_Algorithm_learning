#include "BinaryTree.h"

template<class T>
inline BiNode<T>* BinaryTree<T>::Create(BiNode<T>* bt)  //设计到递归 这样的，不用内联好不好
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
inline void BinaryTree<T>::Release(BiNode<T>* bt)
{
	if (bt != NULL)
	{
		Release(bt->lchid);
		Release(bt->rchild);
		delete bt; //释放根节点
	}
}

template<class T>
inline void BinaryTree<T>::PreOrder(BiNode<T>* bt)
{
	if (bt == NULL)
		return;
	cout << bt->data;
	PreOrder(bt->lchid);
	PreOrder(bt->rchild);
}