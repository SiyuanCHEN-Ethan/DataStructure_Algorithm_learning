#include "BinaryTree.h"

template<class T>
inline BiNode<T>* BinaryTree<T>::Create(BiNode<T>* bt)  //��Ƶ��ݹ� �����ģ����������ò���
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
		bt->rchild = Create(bt->rchild);//������ǰ������ķ�ʽ����������
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
		delete bt; //�ͷŸ��ڵ�
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