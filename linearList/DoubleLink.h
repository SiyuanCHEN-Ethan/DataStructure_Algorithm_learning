//https://blog.csdn.net/fanjiule/article/details/80986659

#pragma once

#include <iostream>
using namespace std;

//一个节点
template<class T>
struct DNode  //为什么不写成class 而用struct呢？
{
public:
	T value;
	DNode* prev;
	DNode* next;

	DNode() {};
	DNode(T t, DNode* prev, DNode* next) {
		this->value = t;
		this->prev = prev;
		this->next = next;
	}

};

//双向链表基本操作
template<class T>
class DoubleLink
{
public:
	DoubleLink();
	~DoubleLink();

	int size();
	int is_empty();
	
	T get(int index); //获取节点
	T get_first();
	T get_last();

	int insert(int index, T t);
	int insert_first(T t);
	int append_last(T t);

	int del(int index);
	int delete_first();
	int delete_last();

private:
	int count;
	DNode<T>* phead;

private:
	DNode<T>* get_node(int index);  //这些设定为private的意义是？ 

};

//具体实现
template<class T>
DoubleLink<T>::DoubleLink() : count(0)  //使用初始化列表的构造函数？
{
	//创建表头，注意表头没有存储数据
	phead = new DNode<T>();
	phead->prev = phead->next = phead; //？ 为什么等于phead
	//设置链表计数为0
	//count=0

}

//析构函数
template<class T>
DoubleLink<T>::~DoubleLink()
{
	//删除所有节点
	DNode<T>* ptemp;
	DNode<T>* pnode = phead->next;

	while (pnode != phead)
	{
		ptemp = pnode;
		pnode = pnode->next;
		delete ptemp; //删除的时候选择了这样顺序去删，这样prev链接过来的指针也会都没了
	}

	//删除表头
	delete phead;
	phead = NULL;
}

//返回节点数目
template<class T>
int DoubleLink<T>::size()
{
	return count;
}

//返回链表是否为空，是，则返回1，否则返回0
template<class T>
int DoubleLink<T>::is_empty()
{
	return count == 0;

}

//获取第index位置的节点
template<class T>
DNode<T>* DoubleLink<T>::get_node(int index)
{
	//判断参数有效性
	if (index < 0 || index >= count)
	{
		cout << "get node failed! the index in out of bound!" << endl;
		return NULL;
	}

	//正向查找
	if (index <= count / 2)
	{
		int i = 0;
		DNode<T>* pindex = phead->next;
		while (i++ < index) {// 关注i++的特性;考虑时考虑比如index是2，这样去检验，应该是没问题的
			pindex = pindex->next;
		}
		return pindex;
	}

	//反向查找
	int j = 0;
	int rindex = count - index - 1;
	DNode<T>* prindex = phead->prev; // 反推分析 应该需要此指针指向链表正序的最后一个节点
	while (j++ < rindex) {
		prindex = prindex->prev; // ?感觉循环截止条件不对
	}

	return prindex;
}

//获取第index位置的节点的值
template<class T>
T DoubleLink<T>::get(int index)
{
	return get_node(index)->value;
}

//获取第一个节点的值
template<class T>
T DoubleLink<T>::get_first()
{
	return get_node(0)->value;
}


//获取最后一个节点的值
template<class T>
T DoubleLink<T>::get_last()
{
	return get_node(count - 1)->value;
}

//将节点插入到第index位置之前
template<class T>
int DoubleLink<T>::insert(int index, T t)  //成功时用0作为返回值合适吗？
{
	if (index == 0)
		return insert_first(t);

	DNode<T>* pindex = get_node(index);
	DNode<T>* pnode = new DNode<T>(t, pindex->prev, pindex);
	pindex->prev->next = pnode;
	pindex->prev = pnode;

	count++;

	return 0;

}

//将节点插入到第一个节点处 (?我觉得其实可以用和插到一般的index位置的函数来做)
template<class T>
int DoubleLink<T>::insert_first(T t)
{
	DNode<T>* pnode = new DNode<T>(t, phead, phead->next);
	phead->next->prev = pnode;
	phead->next = pnode;
	count++;
	return 0;
}


// 将节点追加到链表的末尾
template<class T>
int DoubleLink<T>::append_last(T t)
{
	DNode<T>* pnode = new DNode<T>(t, phead->prev, phead);
	phead->prev->next = pnode;
	phead->prev = pnode;
	count++;

	return 0;
}

//删除index位置的节点
template<class T>
int DoubleLink<T>::del(int index)
{
	DNode<T>* pindex = get_node(index);
	pindex->next->prev = pindex->prev;
	pindex->prev->next = pindex->next;

	delete pindex;

	count--;
	return 0;
}



// 删除第一个节点
template<class T>
int DoubleLink<T>::delete_first()
{
	return del(0);
}

// 删除最后一个节点
template<class T>
int DoubleLink<T>::delete_last()
{
	return del(count - 1);
}

