//完成顺序存储线性表的基本功能

//包括：初始化、判断空表、清空线性表、返回元素、查找元素、插入元素、删除元素、返回元素个数

#include <iostream>
using namespace std;
const int MaxSize = 100;//可根据具体情况定义


class SeqList
{
private:
	int data[MaxSize];//存放元素数据
	int length;//存放线性表的长度

public:
	SeqList()
	{
		length = 0;
	}
	SeqList(int a[], int n);//有参构造
	~SeqList();//析构函数
	int Length()
	{
		return length; //求线性表的长度
	}
	int Get(int i);//按位查找线性表中第i个元素,并返回该元素
	int Locate(int x);//按值查找
	void Insert(int i, int x);
	int Delete(int i);//返回值?
	void PrintList();//遍历输出各元素
};

//有参构造
SeqList::SeqList(int a[], int n)
{
	if (n > MaxSize) throw "参数非法";
	for (int i = 0; i < n; i++)
	{
		data[i] = a[i];
	}
	length = n;
}

//顺序表按位查找算法
int SeqList::Get(int i)
{
	if (i<1 && i>length) throw "查找位置非法";
	else return data[i - 1];
}

//按值查找算法
int SeqList::Locate(int x)
{
	for (int i = 0; i != length; i++)
	{
		if (data[i] == x)
			return i + 1;
	}
	
	return 0;
}

//插入操作
void SeqList::Insert(int i, int x)
{
	if (i > MaxSize) throw "上溢";
	if (i<1 || i>length + 1) throw "位置"; 

	for (int j = length; j >= i; j--)
	{
		data[j] = data[j - 1];
	}
	data[i - 1] = x;
	length++;
}

int SeqList::Delete(int i)//返回值为被删除序号对应的元素的值
{
	if (length == 0) throw "下溢";
	if (i<1 || i>length + 1) throw "位置";
	int x = data[i - 1];
	for (int jj = i; jj < length; jj++)
	{
		data[jj - 1] = data[jj];
	}
	--length;
	return x;
}

void SeqList::PrintList() //遍历打印线性表中的所有值
{
	for (int jj = 0; jj < length; jj++)
		cout << data[jj] << " ";
	cout << endl;
}

int main()
{
	int a[100];
	for (int i = 0; i < 10; i++)
	{
		cin >> a[i];
	}
	SeqList s1(a, 10);
	cout << "输出数组：";
	s1.PrintList();
	cout << endl;
	cout << "按位查找：";
	cout << s1.Get(1) << endl;
	cout << "按值查找：";
	cout << s1.Locate(4) << endl;
	cout << "插入操作：";
	s1.Insert(3, 10);
	s1.PrintList();
	cout << endl;
	cout << "删除操作：";
	s1.Delete(3);
	s1.PrintList();
	cout << endl;
	int max = -100000000;
	int min = 100000000;
	for (int i = 0; i < 10; i++)
	{
		if (a[i] > max)max = a[i];
		if (a[i] < min)min = a[i];
	}
	cout << "最大元素为：";
	cout << max;
	cout << "最小元素为：";
	cout << min;
	
}