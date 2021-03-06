#include "myMinHeap.hpp"

int main()
{
    int a[] = { 80, 40, 30, 60, 90, 70, 10, 50, 20 };
    int i, len = (sizeof(a)) / (sizeof(a[0]));
    MinHeap<int>* tree = new MinHeap<int>();

    cout << "== 依次添加: ";
    for (i = 0; i < len; i++)
    {
        cout << a[i] << " ";
        tree->insert(a[i]);
    }

    cout << "\n== 最 小 堆: ";
    tree->print();

    i = 15;
    tree->insert(i);
    cout << "\n== 添加元素: " << i;
    cout << "\n== 最 小 堆: ";
    tree->print();

    i = 10;
    tree->remove(i);
    cout << "\n== 删除元素: " << i;
    cout << "\n== 最 小 堆: ";
    tree->print();
    cout << endl;

    return 0;
}
