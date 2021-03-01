#include <iostream>
#include "CircularQueue.h"

Status CircularQueue::InitQueue()
{
	Q.base = new QElemType[MAX_QUEUE_SIZE];
	Q.front = 0;
	Q.rear = 0;
	return OK;
}

//ѭ�������󳤶�
int CircularQueue::QueueLength()
{
	return (Q.rear - Q.front + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

//��Ӳ���
Status CircularQueue::EnQueue(QElemType val)	//�ڶ�β��������
{
	//���������ж�
	if (((Q.rear + 1) % MAX_QUEUE_SIZE) == Q.front)
		return ERROR;
	Q.base[Q.rear] = val;
	Q.rear = ((Q.rear + 1) % MAX_QUEUE_SIZE);

	return OK;
}

//���Ӳ�������val�洢��Ԫ��ֵ ����ζ�ŵ���ʱӦ����ǰ������ڴ棩
Status CircularQueue::DeQueue(QElemType* val)
{
	//�����ж��Ƿ�Ϊ��
	if (Q.front == Q.rear)
		return ERROR;

	*val = Q.base[Q.front];
	
	Q.front = (Q.front + 1) & MAX_QUEUE_SIZE;
	return OK;

}

//�����Ƿ�Ϊ��
bool CircularQueue::QueueEmpty()
{
	if (Q.front == Q.rear)
		return true;
	else
		return false;
}

//��ͷ��β��ӡ
//Status CircularQueue::PrintQueue()
//{
//	if (Q.front == Q.rear)
//	{
//		cout << "����Ϊ��" << endl;
//		return ERROR;
//	}
//
//	for (int i=Q.front;i<Q.rear;i++)
//}

//����ͷ������
QElemType CircularQueue::GetHead()
{
	if (Q.front == Q.rear)
	{
		cout << "����Ϊ��" << endl;
		return;
	}

	return Q.base[Q.front];
}




//���ٶ���
Status CircularQueue::DestroyQueue()			
{
	delete Q.base;
	Q.front = 0;
	Q.rear = 0;
	return OK;
}

//��ն���
Status CircularQueue::ClearQueue()
{
	DestroyQueue();
	InitQueue();
	return OK;
}