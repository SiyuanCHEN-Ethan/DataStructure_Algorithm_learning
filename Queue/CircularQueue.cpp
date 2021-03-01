#include <iostream>
#include "CircularQueue.h"

Status CircularQueue::InitQueue()
{
	Q.base = new QElemType[MAX_QUEUE_SIZE];
	Q.front = 0;
	Q.rear = 0;
	return OK;
}

//循环队列求长度
int CircularQueue::QueueLength()
{
	return (Q.rear - Q.front + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

//入队操作
Status CircularQueue::EnQueue(QElemType val)	//在队尾插入数据
{
	//队列满的判断
	if (((Q.rear + 1) % MAX_QUEUE_SIZE) == Q.front)
		return ERROR;
	Q.base[Q.rear] = val;
	Q.rear = ((Q.rear + 1) % MAX_QUEUE_SIZE);

	return OK;
}

//出队操作，用val存储其元素值 （意味着调用时应该提前分配好内存）
Status CircularQueue::DeQueue(QElemType* val)
{
	//首先判断是否为空
	if (Q.front == Q.rear)
		return ERROR;

	*val = Q.base[Q.front];
	
	Q.front = (Q.front + 1) & MAX_QUEUE_SIZE;
	return OK;

}

//队列是否为空
bool CircularQueue::QueueEmpty()
{
	if (Q.front == Q.rear)
		return true;
	else
		return false;
}

//从头到尾打印
//Status CircularQueue::PrintQueue()
//{
//	if (Q.front == Q.rear)
//	{
//		cout << "队列为空" << endl;
//		return ERROR;
//	}
//
//	for (int i=Q.front;i<Q.rear;i++)
//}

//返回头部数据
QElemType CircularQueue::GetHead()
{
	if (Q.front == Q.rear)
	{
		cout << "队列为空" << endl;
		return;
	}

	return Q.base[Q.front];
}




//销毁队列
Status CircularQueue::DestroyQueue()			
{
	delete Q.base;
	Q.front = 0;
	Q.rear = 0;
	return OK;
}

//清空队列
Status CircularQueue::ClearQueue()
{
	DestroyQueue();
	InitQueue();
	return OK;
}