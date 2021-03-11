// Author: https://blog.csdn.net/DarkRabbit
// Fibonacci Search
// 模板有序表 - 斐波那契查找
// params:
//      list:       查找的有序表
//      element:    查找的元素
//      pEqual:     判断查找标准，
//                  >0 查找的值比斐波那契值大
//                  =0 找到了
//                  <0 查找的值比斐波那契值小
// return:
//      int:        找到的数字

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

	int size = list.size();//列表长度

	std::vector<int> fib(2, 1);//斐波那契数列，个数为2，值都1
	int fibBlock = 1;
	while (size > fib[fibBlock] - 1) //一边构造数列，一边计算列表在数列的位置
	{  //斐波那契数列最后一位要比size - 1大
		fibBlock++;
		if (fibBlock == fib.size())
		{
			fib.push_back(fib[fibBlock - 1] + fib[fibBlock - 2]);
		}
	}//退出时fibBlock对应于数列的最后一位的序号（从下标0开始）

	//二分过程
	int left = 0;
	int right = size - 1;
	int isEqual;
	int mid;
	int index;

	while (left <= right)
	{
		mid = left + fib[fibBlcok - 1] - 1; //初始取数列中的倒数第二位
		index = (mid >= size ? size - 1 : mid);
		//index为分割点
		
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

	return -1; //left > right 退出循环

}

