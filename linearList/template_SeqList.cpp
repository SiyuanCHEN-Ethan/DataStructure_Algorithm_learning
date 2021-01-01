#include <iostream>
using namespace std;

const int LIST_INIT_SIZE = 100; //初始分配量
const int LISTINCREMENT = 10; //线性表存储空间的分配增量

template<typename ElemType>
class SqList
{
private:
	ElemType* elem; //存储空间基地址
	int length;		//当前长度
	int ListSize; //当前分配的存储容量，以sizeof(ElemType)为单位

public:
	SqList()
	{
		elem = new ElemType[LIST_INIT_SIZE];
		length = 0;
		ListSize = LIST_INIT_SIZE;
	}
	SqList(int init_size)
	{
		elem = new ElemType[init_size];
		length = 0;  //length 是否暂时仍应该为0呢
		ListSize = init_size;
	}
	SqList(int init_size, ElemType init_elem)
	{
		elem = new ElemType[init_size];
		length = init_size;  
		ListSize = init_size;

		for (int i = 0; i < length; i++)
		{
			elem[i] = init_elem;
		}
	}
	~SqList()
	{
		length = 0;
		ListSize = 0;
		delete[] elem;
	}

	void ClearList(); //将线性表置空
	
	bool ListIsEmpty();

	ElemType GetElem(int i); //返回线性表中元素的值

	int ListLength();

	//判断线性表中第一个与e相等的数据元素的位序，如果不存在则返回-1
	int LocateElem(ElemType e);

	// 在线性表中第i个位置之前插入新的数据元素e，线性表的长度加1，i<=i<=length
	void ListInsert(int i, ElemType e);

	//在顺序线性表中删除第i个元素，i的合法值为1<=i<=length,返回值为该元素的值
	ElemType ListDelete(int i);

};

template<typename ElemType>
void SqList<ElemType>::ClearList()
{
	for (int i = 0; i != length; i++)
	{
		elem[i] = NULL;
	}
}
template<typename ElemType>
bool SqList<ElemType>::ListIsEmpty()
{
	if (!elem)
		return true;
	else if length == 0
		return true;
	else
		return false;
}

template<typename ElemType>
ElemType SqList<ElemType>::GetElem(int i)//返回线性表中元素的值
{
	return elem[i - 1];
}

//获取线性表长度
template<typename ElemType>
int SqList<ElemType>::ListLength()
{
	return length;
}

//判断线性表中第一个与e相等的数据元素的位序，如果不存在则返回-1
template<typename ElemType>
int SqList<ElemType>::LocateElem(ElemType e)
{
	for (int i = 0; i != length; i++)
	{
		if (elem[i] == e)
			return i + 1;
	}
	if (i == length)
		return -1;
}

// 在线性表中第i个位置之前插入新的数据元素e，线性表的长度加1，i<=i<=length
template<typename ElemType>
void SqList<ElemType>::ListInsert(int i, ElemType e)
{
	if (i < 1 || i > length + 1)
		return; //i值不合法
	if (length >= ListSize) // 当前存储空间已满，增加分配
	{
		ElemType* newbase = new ElemType[ListSize + LISTINCREMENT];
		elem = newbase;
		ListSize += LISTINCREMENT;
	}

	ElemType* q = &elem[i - 1];
	for (ElemType* p = &elem[length - 1]; p >= q; --p)
		*(p + 1) = *p;
	*q = e;
	++length;
}

//在顺序线性表中删除第i个元素，i的合法值为1<=i<=length,返回值为该元素的值
template<typename ElemType>
ElemType SqList<ElemType>::ListDelete(int i)
{
	if (i < 1 || i > length + 1)
		return; //i值不合法
	ElemType* p = &elem[i - 1];
	ElemType* q = &elem[length - 1];
	for (++p; p <= q; ++p)
		*(p - 1) = *p;
	--length;
} 


//写一个测试程序,2021/1/1测试成功
void test01()
{
	struct ElemType
	{
		int m_Age;
		char m_Name;
	};
	ElemType elem1,elem2;
	elem1.m_Age = 20;
	elem1.m_Name = 'c';

	elem2.m_Age = 22;
	elem2.m_Name = 'g';

	SqList<ElemType> m_SqList(10);
	m_SqList.ListInsert(1, elem1);
	m_SqList.ListInsert(2, elem2);

	ElemType elem3 = m_SqList.GetElem(2);
	cout << elem3.m_Age << " " << elem3.m_Name << endl;

}


//主函数
int main()
{
	test01();

	system("pause");
	return 0;
}