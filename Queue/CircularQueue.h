//https://blog.csdn.net/nichengwuxiao/article/details/78861635
//顺序存储循环队列

#pragma once

#include <iostream>
using namespace std;

#define Status bool
#define OK 0
#define ERROR 1
#define MAX_QUEUE_SIZE 100
typedef int QElemType; //以int为例创建循环队列，如要修改，在此处将int修改即可




typedef struct
{
	QElemType* base;
	int front;
	int rear;

}SqQueue;

class CircularQueue
{
public:
	Status InitQueue();
	int QueueLength();
	Status DestroyQueue();		//销毁队列
	Status ClearQueue();			//清空队列
	bool QueueEmpty();			//队列是否为空
	int QueueLength();			//队列长度
	Status EnQueue(QElemType val);	//在队尾插入数据
	Status DeQueue(QElemType* val);	//删除队头
	QElemType GetHead();
	
	//Status PrintQueue();					//从头到尾打印


private:
	SqQueue Q;
};