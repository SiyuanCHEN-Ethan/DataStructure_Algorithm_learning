#include <iostream>
#include "DoubleLink.h"

using namespace std;

void int_test()
{
	int iarr[4] = { 10,20,30,40 };

	cout << "��ʼ���� int ���� " << endl;

	//����˫������
	DoubleLink<int>* pdlink = new DoubleLink<int>();

	pdlink->insert(0, 20);
	pdlink->append_last(10);
	pdlink->insert_first(30);

	cout << "is_empty()=" << pdlink->is_empty() << endl;
	// ˫������Ĵ�С
	cout << "size()=" << pdlink->size() << endl;

	// ��ӡ˫�������е�ȫ������
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