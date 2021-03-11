// Author: https://blog.csdn.net/DarkRabbit
// Fibonacci Search
// 编译时提示无法找到./Debug下的解决方案同名.exe文件，无法运行

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
    vector<MyElement> list; // 列表
    MyElement tofind; // 需要查找的元素

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
        cout << "找到了下标：" << index << endl;
    }

    return 0;
}

