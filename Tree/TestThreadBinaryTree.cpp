#include "ThreadBinaryTree.h"
using namespace std;

int main()
{
	ThreadTree<char> tree('#');

	tree.CreateTree();
	tree.CreateInThread();
	tree.InOrder();
	tree.PreOrder();
	tree.PostOrder();

	system("pause");
	return 0;
}