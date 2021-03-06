//https://www.cnblogs.com/WindSun/p/10871398.html
#pragma once

#include<iostream>
using namespace std;

template<typename T>
struct ThreadNode
{
	int ltag, rtag;
	ThreadNode<T>* lchild, * rchild;
	T data;

	//�����вι��캯��
	ThreadNode(const T item) :data(item), lchild(NULL), rchild(NULL), ltag(0), rtag(0) {};

};


template<typename T>
class ThreadTree
{
public:
	 //���캯��(��ͨ)
	ThreadTree() :root(NULL) {};

	//ָ��������־RefValue�Ĺ��캯��
	ThreadTree(T value) : RefValue(value), root(NULL) {};

	//ʹ��ǰ���������������(δ������)
	void CreateTree() { CreatePreTree(root); }

	//��������Դ����õ���ͨ��������������������
	void CreateInThread()
	{
		ThreadNode<T>* pre = NULL;	//��һ���ڵ��pre��ΪNULL
		if (root != NULL)
		{
			createInThread(root, pre);
			pre->rchild = NULL;
			pre->rtag = 1; //����������������һ���ڵ㣬�����һ���ڵ����������Ϊ��
		}
	}

    //��������������ִ������������㷨
	void InOrder() { InOrder(root); }
	 //������������������ʵ��ǰ��������㷨
	void PreOrder() { PreOrder(root); }
	 //���������������ĺ�������㷨
	void PostOrder() { PostOrder(root); }

private:

	ThreadNode<T>* root;
	T RefValue; //����ɶ--��������֮ǰ��'#'��־����ʾ�ս��

	//ʹ��ǰ�����������������δ��������(ʹ��ǰ�к�˳����������Ľ����һ����,ֻ�����벻һ��)
	void CreatePreTree(ThreadNode<T>*& subTree) //ʹ����ָ�������
	{
		T item;
		if (cin >> item)
		{
			if (item != RefValue)
			{
				subTree = new ThreadNode<T>(item); //����ڵ�
				if (subTree == NULL)
				{
					cout << "�ռ�������" << endl;
					exit(1);
				}
				CreatePreTree(subTree->lchild);
				CreatePreTree(subTree->rchild);
			}
			else
			{
				subTree = NULL;
			}
		}

	}

	//��������Զ���������������
	void createInThread(ThreadNode<T>* current, ThreadNode<T>*& pre) /*Ϊʲôcurrent�������ö�pre�������� ����currentָ���ͷ��βû�н��й�
		��ֵ,��pre������Ҫ��pre=current�����������������Ļ����о��ݹ����������鷳�ģ����������󲻳������淢����ɶ */
	{
		if (current == NULL)
		{
			return;
		}
		createInThread(current->lchild, pre);
		if (current->lchild == NULL)
		{
			current->lchild = pre;
			current->ltag = 1;//��ʾ������
		}
		if (pre != NULL && pre->rchild == NULL)
		{
			pre->rchild = current;
			pre->rtag = 1;
		}
		pre = current;
		createInThread(current->rchild, pre);
	

	}

	//Ѱ�������µ�һ�����
	ThreadNode<T>* First(ThreadNode<T>* current)//������currentΪ��������������������������ĵ�һ�����
	{
		ThreadNode<T> *p = current;
		while (!p->ltag)
			p = p->lchild;
		return p;

	}

	//Ѱ�������µĺ�̽��
	ThreadNode<T>* Next(ThreadNode<T>* current)
	{
		ThreadNode<T>* p = current->rchild;
		if (current->rtag == 0)
			return First(p); //��ԭ��Ϊ��First��current��,�������״�
		else
			return p;
	}

	//Ѱ�������µ����һ�����
	ThreadNode<T>* Last(ThreadNode<T>* current)
	{
		ThreadNode<T>* p = current;
		while (p->rtag == 0)
			p = p->rchild;

		return p;
	}

	//Ѱ�ҽ���������µ�ǰ�����
	ThreadNode<T>* Prior(ThreadNode<T>* current)
	{
		ThreadNode<T>* p = current->rchild;
		if (current->ltag == 0)
			return Last(p);
			
		else
			return p;

		
	}

	//�������������������󸸽ڵ�
	ThreadNode<T>* Parent(ThreadNode<T>* t) //��̫����Ϊʲô������һ�����ҵ�
	{
		ThreadNode<T>* p;
		if (t == root)
			return NULL;

		for (p = t; p->ltag == 0; p = p->lchild); //һֱ��t��t��Ϊ���������������µĵ�һ�����p

		//���1
		if (p->lchild != NULL) //��p������ָ��Ϊ�գ�������ǰ��
		{
			//��pΪp��������ָ��Ľ�㣬�жϴ˽���Ƿ�Ϊ���Ҵ˽ڵ��������������ָ�򶼲�Ϊt���ٽ�pΪp���Һ��ӽ��
			for (p = p->lchild; p != NULL && p->lchild != t && p->rchild != t; p = p->rchild);
		}
		//���2
		//��������ѭ�����ˣ�������p==NULL������ѭ����û���ҵ���t��ȵĽ�㣻���߾�������һֱ�ҵ��������������ĵ�һ������ˣ���ʱ�����־�Ҫ�õ����2�ķ���
		if (p == NULL || p->lchild == NULL)//������������Ϊ�գ������������������ĵ�һ���ڵ���
		{
			//�ҵ�*tΪ���������µ����һ�����
			for (p = t; p->rtag == 0; p = p->rchild);
			//Ȼ������ָ�����һ�����ָ��Ľ�㣬�������㿪ʼ�����Դ��ж��������Ӻ��Һ����Ƿ��t���
			for (p = p->rchild; p != NULL && p->lchild != t && p->rchild != t; p = p->lchild);
		}

		return p;
	
	}

	//������������������ִ������������㷨
	void InOrder(ThreadNode<T>* p)
	{
		for (p = First(root); p != NULL; p = Next(p))
		{
			cout << p->data << " ";
		}
		cout << endl;
	}

	//������������������ʵ��ǰ��������㷨
	void PreOrder(ThreadNode<T>* p)
	{
		while (p != NULL)
		{
			cout << p->data << " ";//�ȷ��ʸ��ڵ�
			if (p->ltag == 0)
			{
				p = p->lchild;

			}
			else if (p->rtag==0)
			{
				p = p->rchild;
			}
			else //��ʱ�ķ�֧��ʾ��Ҷ�ӽڵ�,����������
			{
				while (p != NULL && p->rtag == 1)
				{
					p = p->rchild; //ֱ���ҵ����������Ľڵ㡣��p->rtagΪ0
				}
				if (p != NULL)
				{
					p = p->rchild;
				}
			}
			
		}
		cout << endl;
	
	}

	//���������������ĺ�������㷨
	void PostOrder(ThreadNode<T>* p)
	{
		ThreadNode<T>* t = p;
		while (t->ltag == 0 || t->rtag == 0) //�������ҵ�����ĵ�һ�����
		{
			if (t->ltag == 0)
				t = t->lchild;
			else if (t->rtag == 0)
				t = t->rchild;
		}
		cout << t->data << " ";//���ʵ�һ�����

		while ((p = Parent(t)) != NULL) //ÿ�ζ����ҵ���ǰ���ĸ��ڵ�
		{
			/*����ǰ����Ǹ��ڵ�����������ߵ�ǰ��������������������
			���ڵ�û����������������µĺ��Ϊ�ĸ��ڵ�*/
			if (p->rchild == t || p->rtag == 1)
				t = p;
			else//�����ڵ�ǰ�������������ظ�ִ������Ĳ���
			{
				t = p->rchild;
				while (t->ltag == 0 || t->rtag == 0)
				{
					if (t->ltag == 0)
						t = t->lchild;
					else if (t->rchild == 0)
						t = t->rchild;
				}
				
			}
			

			cout << t->data << " ";
		}
	}

};


