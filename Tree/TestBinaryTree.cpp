#include "BinaryTree.h"
#include "cirqueue.h"
#include "BinaryTree.hpp"
using namespace std;



int main()
{

     BinaryTree<char> * bitree = new BinaryTree<char>();        // ����һ�ö�����,ʹ��new�͵��õĹ��캯��
 
     bitree->PreOrder();                             // ǰ�����
     cout << endl;
     bitree->InOrder();                              // �������
     cout << endl;
     bitree->PostOrder();                            // �������
     cout << endl;
     bitree->LeverOrder();                           // �������
     delete bitree;

     system("pause");
     return 0; 
}