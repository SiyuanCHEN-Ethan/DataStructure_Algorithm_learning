//���˳��洢���Ա�Ļ�������

//��������ʼ�����жϿձ�������Ա�����Ԫ�ء�����Ԫ�ء�����Ԫ�ء�ɾ��Ԫ�ء�����Ԫ�ظ���

#include <iostream>
using namespace std;
const int MaxSize = 100;//�ɸ��ݾ����������


class SeqList
{
private:
	int data[MaxSize];//���Ԫ������
	int length;//������Ա�ĳ���

public:
	SeqList()
	{
		length = 0;
	}
	SeqList(int a[], int n);//�вι���
	~SeqList();//��������
	int Length()
	{
		return length; //�����Ա�ĳ���
	}
	int Get(int i);//��λ�������Ա��е�i��Ԫ��,�����ظ�Ԫ��
	int Locate(int x);//��ֵ����
	void Insert(int i, int x);
	int Delete(int i);//����ֵ?
	void PrintList();//���������Ԫ��
};

//�вι���
SeqList::SeqList(int a[], int n)
{
	if (n > MaxSize) throw "�����Ƿ�";
	for (int i = 0; i < n; i++)
	{
		data[i] = a[i];
	}
	length = n;
}

//˳���λ�����㷨
int SeqList::Get(int i)
{
	if (i<1 && i>length) throw "����λ�÷Ƿ�";
	else return data[i - 1];
}

//��ֵ�����㷨
int SeqList::Locate(int x)
{
	for (int i = 0; i != length; i++)
	{
		if (data[i] == x)
			return i + 1;
	}
	
	return 0;
}

//�������
void SeqList::Insert(int i, int x)
{
	if (i > MaxSize) throw "����";
	if (i<1 || i>length + 1) throw "λ��"; 

	for (int j = length; j >= i; j--)
	{
		data[j] = data[j - 1];
	}
	data[i - 1] = x;
	length++;
}

int SeqList::Delete(int i)//����ֵΪ��ɾ����Ŷ�Ӧ��Ԫ�ص�ֵ
{
	if (length == 0) throw "����";
	if (i<1 || i>length + 1) throw "λ��";
	int x = data[i - 1];
	for (int jj = i; jj < length; jj++)
	{
		data[jj - 1] = data[jj];
	}
	--length;
	return x;
}

void SeqList::PrintList() //������ӡ���Ա��е�����ֵ
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
	cout << "������飺";
	s1.PrintList();
	cout << endl;
	cout << "��λ���ң�";
	cout << s1.Get(1) << endl;
	cout << "��ֵ���ң�";
	cout << s1.Locate(4) << endl;
	cout << "���������";
	s1.Insert(3, 10);
	s1.PrintList();
	cout << endl;
	cout << "ɾ��������";
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
	cout << "���Ԫ��Ϊ��";
	cout << max;
	cout << "��СԪ��Ϊ��";
	cout << min;
	
}