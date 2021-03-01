//https://blog.csdn.net/nichengwuxiao/article/details/78861635
//˳��洢ѭ������

#pragma once

#include <iostream>
using namespace std;

#define Status bool
#define OK 0
#define ERROR 1
#define MAX_QUEUE_SIZE 100
typedef int QElemType; //��intΪ������ѭ�����У���Ҫ�޸ģ��ڴ˴���int�޸ļ���




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
	Status DestroyQueue();		//���ٶ���
	Status ClearQueue();			//��ն���
	bool QueueEmpty();			//�����Ƿ�Ϊ��
	int QueueLength();			//���г���
	Status EnQueue(QElemType val);	//�ڶ�β��������
	Status DeQueue(QElemType* val);	//ɾ����ͷ
	QElemType GetHead();
	
	//Status PrintQueue();					//��ͷ��β��ӡ


private:
	SqQueue Q;
};