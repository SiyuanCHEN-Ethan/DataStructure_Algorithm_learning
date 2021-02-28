#include <iostream>
#include "DoubleLink.h"

using namespace std;

void int_test()
{
	int iarr[4] = { 10,20,30,40 };

	cout << "开始测试 int 数据 " << endl;

	//创建双向链表
	DoubleLink<int>* pdlink = new DoubleLink<int>();

	pdlink->insert(0, 20);
	pdlink->append_last(10);
	pdlink->insert_first(30);

	cout << "is_empty()=" << pdlink->is_empty() << endl;
	// 双向链表的大小
	cout << "size()=" << pdlink->size() << endl;

	// 打印双向链表中的全部数据
	int sz = pdlink->size();
	for (int i = 0; i < sz; i++)
		cout << "pdlink(" << i << ")=" << pdlink->get(i) << endl;

}

int main()
{
	int_test();
	system("pause");
	return 0;
}