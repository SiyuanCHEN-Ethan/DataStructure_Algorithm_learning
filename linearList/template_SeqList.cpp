#include <iostream>
using namespace std;

const int LIST_INIT_SIZE = 100; //��ʼ������
const int LISTINCREMENT = 10; //���Ա�洢�ռ�ķ�������

template<typename ElemType>
class SqList
{
private:
	ElemType* elem; //�洢�ռ����ַ
	int length;		//��ǰ����
	int ListSize; //��ǰ����Ĵ洢��������sizeof(ElemType)Ϊ��λ

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
		length = 0;  //length �Ƿ���ʱ��Ӧ��Ϊ0��
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

	void ClearList(); //�����Ա��ÿ�
	
	bool ListIsEmpty();

	ElemType GetElem(int i); //�������Ա���Ԫ�ص�ֵ

	int ListLength();

	//�ж����Ա��е�һ����e��ȵ�����Ԫ�ص�λ������������򷵻�-1
	int LocateElem(ElemType e);

	// �����Ա��е�i��λ��֮ǰ�����µ�����Ԫ��e�����Ա�ĳ��ȼ�1��i<=i<=length
	void ListInsert(int i, ElemType e);

	//��˳�����Ա���ɾ����i��Ԫ�أ�i�ĺϷ�ֵΪ1<=i<=length,����ֵΪ��Ԫ�ص�ֵ
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
ElemType SqList<ElemType>::GetElem(int i)//�������Ա���Ԫ�ص�ֵ
{
	return elem[i - 1];
}

//��ȡ���Ա���
template<typename ElemType>
int SqList<ElemType>::ListLength()
{
	return length;
}

//�ж����Ա��е�һ����e��ȵ�����Ԫ�ص�λ������������򷵻�-1
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

// �����Ա��е�i��λ��֮ǰ�����µ�����Ԫ��e�����Ա�ĳ��ȼ�1��i<=i<=length
template<typename ElemType>
void SqList<ElemType>::ListInsert(int i, ElemType e)
{
	if (i < 1 || i > length + 1)
		return; //iֵ���Ϸ�
	if (length >= ListSize) // ��ǰ�洢�ռ����������ӷ���
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

//��˳�����Ա���ɾ����i��Ԫ�أ�i�ĺϷ�ֵΪ1<=i<=length,����ֵΪ��Ԫ�ص�ֵ
template<typename ElemType>
ElemType SqList<ElemType>::ListDelete(int i)
{
	if (i < 1 || i > length + 1)
		return; //iֵ���Ϸ�
	ElemType* p = &elem[i - 1];
	ElemType* q = &elem[length - 1];
	for (++p; p <= q; ++p)
		*(p - 1) = *p;
	--length;
} 


//дһ�����Գ���,2021/1/1���Գɹ�
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


//������
int main()
{
	test01();

	system("pause");
	return 0;
}