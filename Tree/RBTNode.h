//������Ľ�����ͽṹ��
#pragma once

enum Color
{
		Red,
		Black
};

template<typename T>
struct RBTNode
{
	T data;
	Color RB;
	RBTNode<T>* lchild, * rchild;

};
