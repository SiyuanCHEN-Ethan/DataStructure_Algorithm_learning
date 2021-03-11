#pragma once

enum COLOR
{
	RED,BLACK
};

template<typename T>
class RBNode
{
public:
	RBNode(T value, COLOR col)
	{
		data = value;
		color = col;
		lefChild = NULL;
		rightChild = NULL;
		father = NULL;
	}
	void SetData(T value)
	{
		data = value;
	}
	T GetDAta()
	{
		return data;
	}
	void SetLeftChild(RBNode* left)
	{
		lefChild = left;
	}
	RBNode* GetLeftChild()
	{
		return lefChild;
	}
	void SetRightChild(RBNode* right)
	{
		rightChild = right;
	}
	RBNode* GetRightChild()
	{
		return rightChild;
	}
	void SetFather(RBNode* par)
	{
		father = par;
	}
	RBNode* GetFather()
	{
		return father;
	}
	void SetColor(COLOR col)
	{
		COLOR = col;
	}
	COLOR GetCorlor()
	{
		return color;
	}
private:
	T data;
	RBNode<T>* lefChild;
	RBNode<T>* rightChild;
	RBNode<T>* father;
	COLOR color;

public:
	//��ó�Ա��������������
	void LeftRotate()
	{
		RBNode* child = this->GetRightChild();
		if (child == NULL)
			return;
		child->SetFather(this->father);//ͷ�ڵ�ĸ��ڵ�Ϊ��
		if (this->father != NULL)
		{
			if (this->father->GetLeftChild() == this)
			{
				this->father->SetLeftChild(child);
			}
			else
			{
				this->father->SetRightChild(child);
			}
		}
		this->father = child;
		this->rightChild = child->GetLeftChild();
		child->SetLeftChild(this);
	}
	//��������
	void RightRotate()
	{
		RBNode* child = this->GetLeftChild();
		if (child == NULL)
			return;
		child->SetFather(this->father);//ͷ�ڵ�ĸ��ڵ�Ϊ��
		if (this->father != NULL)
		{
			if (this->father->GetLeftChild() == this)
			{
				this->father->SetLeftChild(child);
			}
			else
			{
				this->father->SetRightChild(child);
			}
		}
		this->father = child;
		this->LeftChild = child->GetRightChild();
		child->SetRightChild(this);
	}
};
//�����������ĺ�������������ĳ�Ա����
void Insert(RBNode<int>* node)
{
	//�������Ǽ���ڵ��Ѿ����뵽�˺��ʵ�λ��,����ֻ�����չ�����е���
	//���²���ڵ����ɫ���е���
	node->SetColor(RED);
	//���1-->���ڵ�
	if (node->GetFather() == nullptr)
	{
		node->SetColor(BLACK);
		return;
	}
	//���2-->˳�����
	if (node->GetFather()->GetCorlor() == BLACK)
		return;
	//���3,4,5��Ҫ�����Һ�������
	while (node->GetFather()->GetCorlor() == RED)
	{
		//����Ľڵ���үү�ڵ����������
		if (node->GetFather()->GetFather()->GetLeftChild() == node->GetFather())
		{
			RBNode<int>* uncle = node->GetFather()->GetFather()->GetRightChild();//�õ�����ڵ�
			//���3
			if (uncle != nullptr && uncle->GetCorlor == RED)
			{
				//���ڵ��ڣ�����ڵ��ڣ�үү�ڵ��죬��node�ڵ�ָ��үү�ڵ� ��CSY��׼���������Ͻ����жϣ�
				node->GetFather()->SetColor(BLACK);
				uncle->SetColor(BLACK);
				node->GetFather()->GetFather()->SetColor(RED);
				node = node->GetFather()->GetFather();
			}
			//����ڵ��Ǻ�ɫ���߲�����
			else
			{
				//���4������һ��ֱ����
				if (node->GetFather()->GetRightChild() == node)
				{
					//���ڵ�����
					node->GetFather()->LeftRotate();
				}
				//���5����һ��ֱ������
				//���ڵ��ڣ�үү�ڵ��죬үү������
				node->GetFather()->SetColor(BLACK);
				node->GetFather()->GetFather()->SetColor(BLACK);
				node->GetFather()->GetFather()->RightRotate();
				//�������
				break;
			}
		}
		//����Ľڵ���үү�ڵ����������
		else
		{
			RBNode<int>* uncle = node->GetFather()->GetFather()->GetLeftChild();//�õ�����ڵ�
			//���3
			if (uncle != nullptr && uncle->GetCorlor == RED)
			{
				//���ڵ��ڣ�����ڵ��ڣ�үү�ڵ��죬node�ڵ�ָ��үү�ڵ�
				node->GetFather()->SetColor(BLACK);
				uncle->SetColor(BLACK);
				node->GetFather()->GetFather()->SetColor(RED);
				node = node->GetFather()->GetFather();
			}
			//����ڵ��Ǻ�ɫ
			else
			{
				//���4������һ��ֱ����
				if (node->GetFather()->GetLeftChild() == node)
				{
					//���ڵ�����
					node->GetFather()->RightRotate();
				}
				//���5����һ��ֱ������
				//���ڵ��ڣ�үү�ڵ��죬үү������
				node->GetFather()->SetColor(BLACK);
				node->GetFather()->GetFather()->SetColor(BLACK);
				node->GetFather()->GetFather()->LeftRotate();
				//�������
				break;
			}
		}
	}
}
