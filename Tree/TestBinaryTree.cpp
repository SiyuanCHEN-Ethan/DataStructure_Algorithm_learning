#include "BinaryTree.h"
#include "cirqueue.h"
#include "BinaryTree.hpp"
using namespace std;



int main()
{

     BinaryTree<char> * bitree = new BinaryTree<char>();        // 创建一棵二叉树,使用new就调用的构造函数
 
     bitree->PreOrder();                             // 前序遍历
     cout << endl;
     bitree->InOrder();                              // 中序遍历
     cout << endl;
     bitree->PostOrder();                            // 后序遍历
     cout << endl;
     bitree->LeverOrder();                           // 层序遍历
     delete bitree;

     system("pause");
     return 0; 
}