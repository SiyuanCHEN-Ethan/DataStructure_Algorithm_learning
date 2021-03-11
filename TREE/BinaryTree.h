https://www.cnblogs.com/smile233/p/8145760.html
#pragma once

#include <iostream>'

template<class T>
struct BiNode
{
	T data;
	BiNode<T> *lchid, *rchild;



};

//二叉链表类实现
template<class T>
class BinaryTree
{
public:
	BinaryTree() { root = Creat(root); }
	~BinaryTree() { Release(root); }
	void PreOrder() { PreOrder(root); }      // 递归前序遍历二叉树
	void InOrder() { InOrder(root); }        // 递归中序遍历二叉树
	void PostOrder() { PostOrder(root); }    // 递归后序遍历二叉树
	//以上做法，是为了封装的更好？
	//差一个层序遍历


private:
	BiNode<T>* root;
	BiNode<T>* Create(BiNode<T>* bt);
	void Release(BiNode<T>* bt);
	void PreOrder(BiNode<T>* bt);           // 前序遍历函数调用
	void InOrder(BiNode<T>* bt);            // 中序遍历函数调用
	void PostOrder(BiNode<T>* bt);          // 后序遍历函数调用


};