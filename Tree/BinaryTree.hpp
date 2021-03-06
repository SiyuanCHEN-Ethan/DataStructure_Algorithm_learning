#include "BinaryTree.h"
#include "cirqueue.h"
#include <iostream>

using namespace std;

template<class T>
BiNode<T>* BinaryTree<T>::Create(BiNode<T>* bt)  //�漰���ݹ� �����ģ����������ò���
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
void BinaryTree<T>::Release(BiNode<T>* bt)
{
	if (bt != NULL)
	{
		Release(bt->lchild);
		Release(bt->rchild);
		delete bt; //�ͷŸ��ڵ� ���ͷ�ĳ���ʱ���ý������Ҷ������Ѿ��ͷţ�����Ӧ�ò��ú��������
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
	queue<BiNode<T>*> Q; // queue<T> Q ������? Ӧ���ǲ��еģ���Ϊ֮ǰ����data[]��ʱ���õ���<T> ��������ȷʵӦ��������
	Q.front = Q.rear = -1;
	if (root == NULL)
		return;

	Q.data[++Q.rear] = root; //�������root
	while (Q.front!=Q.rear) //���ʱ���ӿ�
	{
		BiNode<T>* q = Q.data[++Q.front];    // ����
		cout << q->data<<endl; // ���������
		if (q->lchild != NULL)
			Q.data[++Q.rear] = q->lchild;    // �������
		if (q->rchild != NULL)
			Q.data[++Q.rear] = q->rchild;    // �Һ������
	}

//}
//
//
//int main()
//{
//
//	BinaryTree<char>* bitree = new BinaryTree<char>();        // ����һ�ö�����,ʹ��new�͵��õĹ��캯��
//
//	bitree->PreOrder();                             // ǰ�����
//	cout << endl;
//	bitree->InOrder();                              // �������
//	cout << endl;
//	bitree->PostOrder();                            // �������
//	cout << endl;
//	bitree->LeverOrder();                           // �������
//	delete bitree;
//
//	system("pause");
//	return 0;
}