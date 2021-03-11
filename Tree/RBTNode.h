//红黑树的结点类型结构体
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
