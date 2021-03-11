// Author: https://blog.csdn.net/DarkRabbit
// Fibonacci Search
// ����ʱ��ʾ�޷��ҵ�./Debug�µĽ������ͬ��.exe�ļ����޷�����

#include <vector>
#include <string>
#include <iostream>
#include "FibonacciSearch.h"
using namespace std;


struct MyElement
{
    int key;
    string data;
};

int MyFibonacciCompare(const MyElement& x,
    const MyElement& y)
{
    return x.key - y.key;
}

int main()
{
    vector<MyElement> list; // �б�
    MyElement tofind; // ��Ҫ���ҵ�Ԫ��

    MyElement me1, me2, me3;
    me1.key = 1;
    me1.data = "me1";
    me2.key = 2;
    me2.data = "me2";
    me2.key = 3;  
    me3.data = "me3";

    list.push_back(me1);
    list.push_back(me2);
    list.push_back(me3);

    tofind = me2;
    

    //extern int FibonacciSearch(const std::vector<MyElement> & list, const MyElement & element, int(*pEqual)(const MyElement&, const MyElement&));

    int index = FibonacciSearch(list,tofind,MyFibonacciCompare);


    if (index != -1)
    {
        // do something
        cout << "�ҵ����±꣺" << index << endl;
    }

    return 0;
}

