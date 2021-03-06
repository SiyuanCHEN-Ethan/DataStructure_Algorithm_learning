//https://www.cnblogs.com/skywang12345/p/3610382.html


/*
* ����ѣ���С�ѣ�

* @ԭ���� skywang
* @�޸��� ethan

*/

#include <iomanip> //���ڵ����������ʾ
#include<iostream>
using namespace std;

template <class T>
class MinHeap 
{
private:
	T* mHeap;
	int mCapacity; //������
	int mSize;		//ʵ������

private:
	//��С�ѵ����µ����㷨
	void filterdown(int start, int end);
	//��С�ѵ����ϵ����㷨()
	void filterup(int start);

public:
    MinHeap() { new (this)MinHeap(30); } //�����䲻�Ǻܶ�
    
    MinHeap(int capacity)
    {
        mSize = 0;
        mCapacity = capacity;
        mHeap = new T[mCapacity];
    }

    ~MinHeap()
    {
        mSize = 0;
        mCapacity = 0;
        delete[] mHeap;
    }


    // ����data�ڶ�����е�����
    /*
        *����ֵ��
        * ���� -- ����data�������е�����
        * ������-- - 1
    */
    int getIndex(T data)
    {
        for (int i = 0; i < mSize; i++) //����洢���򵥱���
            if (data == mHeap[i])
                return i;

        return -1;
    }
    // ɾ����С���е�data
    int remove(T data);
    // ��data���뵽�������
    int insert(T data);
    // ��ӡ�����
    void print();
};



/*
 * ��С�ѵ����µ����㷨
 *
 * ע������ʵ�ֵĶ��У���N���ڵ�����ӵ�����ֵ��(2N+1)���Һ��ӵ�������(2N+2)��
 *
 * ����˵����
 *     start -- ���µ��ڵ����ʼλ��(һ��Ϊ0����ʾ�ӵ�1����ʼ)
 *     end   -- ������Χ(һ��Ϊ���������һ��Ԫ�ص�����)
 */
template <class T>
void MinHeap<T>::filterdown(int start, int end) //���µ�������ֵС�Ļ���������Ļ���ȥ
{
    int c = start;          // ��ǰ(current)�ڵ��λ��
    int l = 2 * c + 1;     // ��(left)���ӵ�λ��
    T tmp = mHeap[c];    // ��ǰ(current)�ڵ�Ĵ�С

    while (l <= end)
    {
        // "l"�����ӣ�"l+1"���Һ���
        if (l < end && mHeap[l] > mHeap[l + 1])
            l++;        // ������������ѡ���С�ߣ���mHeap[l+1]
        if (tmp <= mHeap[l])
            break;        //��������
        else
        {
            mHeap[c] = mHeap[l];
            c = l;
            l = 2 * l + 1;
        }
    }
    mHeap[c] = tmp;
}

/*
 * ɾ����С���е�data
 *
 * ����ֵ��
 *      0���ɹ�
 *     -1��ʧ��
 */
template <class T>
int MinHeap<T>::remove(T data)
{
    int index;
    // ���"��"�ѿգ��򷵻�-1
    if (mSize == 0)
        return -1;

    // ��ȡdata�������е�����
    index = getIndex(data);
    if (index == -1)
        return -1;

    mHeap[index] = mHeap[--mSize];        // �����Ԫ���
    filterdown(index, mSize - 1);    // ��index��λ�ÿ�ʼ�������µ���Ϊ��С��

    return 0;
}

/*
 * ��С�ѵ����ϵ����㷨(��start��ʼ����ֱ��0��������)
 *
 * ע������ʵ�ֵĶ��У���N���ڵ�����ӵ�����ֵ��(2N+1)���Һ��ӵ�������(2N+2)��
 *
 * ����˵����
 *     start -- ���ϵ��ڵ����ʼλ��(һ��Ϊ���������һ��Ԫ�ص�����)
 */
template <class T>
void MinHeap<T>::filterup(int start)
{
    int c = start;            // ��ǰ�ڵ�(current)��λ��
    int p = (c - 1) / 2;        // ��(parent)����λ��
    T tmp = mHeap[c];        // ��ǰ�ڵ�(current)�Ĵ�С

    while (c > 0)
    {
        if (mHeap[p] <= tmp)
            break;
        else
        {
            mHeap[c] = mHeap[p];
            c = p;
            p = (p - 1) / 2;
        }
    }
    mHeap[c] = tmp;
}

/*
 * ��data���뵽�������
 *
 * ����ֵ��
 *     0����ʾ�ɹ�
 *    -1����ʾʧ��
 */
template <class T>
int MinHeap<T>::insert(T data)
{
    // ���"��"�������򷵻�
    if (mSize == mCapacity)
        return -1;

    mHeap[mSize] = data;        // ��"����"���ڱ�β
    filterup(mSize);            // ���ϵ�����
    mSize++;                    // �ѵ�ʵ������+1

    return 0;
}

/*
 * ��ӡ�����
 *
 * ����ֵ��
 *     0����ʾ�ɹ�
 *    -1����ʾʧ��
 */
template <class T>
void MinHeap<T>::print()
{
    for (int i = 0; i < mSize; i++)
        cout << mHeap[i] << " ";
}


