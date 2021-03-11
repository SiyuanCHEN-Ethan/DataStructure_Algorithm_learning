// Author: https://blog.csdn.net/DarkRabbit
// Fibonacci Search
// ģ������� - 쳲���������
// params:
//      list:       ���ҵ������
//      element:    ���ҵ�Ԫ��
//      pEqual:     �жϲ��ұ�׼��
//                  >0 ���ҵ�ֵ��쳲�����ֵ��
//                  =0 �ҵ���
//                  <0 ���ҵ�ֵ��쳲�����ֵС
// return:
//      int:        �ҵ�������

#include <vector>
#include "FibonacciSearch.h"
using namespace std;

template<typename T>
int FibonacciSearch(const std::vector<T>& list, const T& element, int(*pEqual)(const T&, const T&))
{
	if (pEqual == nullptr || list.empty())
	{
		return -1;
	}

	int size = list.size();//�б���

	std::vector<int> fib(2, 1);//쳲��������У�����Ϊ2��ֵ��1
	int fibBlock = 1;
	while (size > fib[fibBlock] - 1) //һ�߹������У�һ�߼����б������е�λ��
	{  //쳲������������һλҪ��size - 1��
		fibBlock++;
		if (fibBlock == fib.size())
		{
			fib.push_back(fib[fibBlock - 1] + fib[fibBlock - 2]);
		}
	}//�˳�ʱfibBlock��Ӧ�����е����һλ����ţ����±�0��ʼ��

	//���ֹ���
	int left = 0;
	int right = size - 1;
	int isEqual;
	int mid;
	int index;

	while (left <= right)
	{
		mid = left + fib[fibBlcok - 1] - 1; //��ʼȡ�����еĵ����ڶ�λ
		index = (mid >= size ? size - 1 : mid);
		//indexΪ�ָ��
		
		isEuqal = (*pEqual)(element, list[index]);
		if (isEqual > 0) //element > list[index]
		{
			left = mid + 1;
			fibBlock -= 2;
		}
		else if (isEqual < 0)
		{
			right = mid - 1;
			fibBlock -= 1;
		}
		else return index;
	}

	return -1; //left > right �˳�ѭ��

}

