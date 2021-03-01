#include <iostream>
#include "CircularQueue.h"


void test01()
{
	CircularQueue Cq;
	Cq.InitQueue();
	cout << Cq.QueueEmpty() << endl;
	Cq.EnQueue(10);
	

	QElemType* a=new QElemType;
	Cq.DeQueue(a);
	cout << *a << endl;

	QElemType b;
	b=Cq.GetHead();
	cout << b << endl;


}

int main()
{
	test01();
	system("pause");
	return 0;
}