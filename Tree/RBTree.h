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
	//类得成员函数：左旋操作
	void LeftRotate()
	{
		RBNode* child = this->GetRightChild();
		if (child == NULL)
			return;
		child->SetFather(this->father);//头节点的父节点为空
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
	//右旋操作
	void RightRotate()
	{
		RBNode* child = this->GetLeftChild();
		if (child == NULL)
			return;
		child->SetFather(this->father);//头节点的父节点为空
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
//单独的声明的函数，不再是类的成员函数
void Insert(RBNode<int>* node)
{
	//这里我们假设节点已经插入到了合适的位置,这里只按按照规则进行调整
	//将新插入节点的颜色进行调整
	node->SetColor(RED);
	//情况1-->根节点
	if (node->GetFather() == nullptr)
	{
		node->SetColor(BLACK);
		return;
	}
	//情况2-->顺理成章
	if (node->GetFather()->GetCorlor() == BLACK)
		return;
	//情况3,4,5都要对左右孩子区别开
	while (node->GetFather()->GetCorlor() == RED)
	{
		//插入的节点在爷爷节点的左子树上
		if (node->GetFather()->GetFather()->GetLeftChild() == node->GetFather())
		{
			RBNode<int>* uncle = node->GetFather()->GetFather()->GetRightChild();//得到叔叔节点
			//情况3
			if (uncle != nullptr && uncle->GetCorlor == RED)
			{
				//父节点变黑，叔叔节点变黑，爷爷节点变红，把node节点指向爷爷节点 （CSY：准备继续向上进行判断）
				node->GetFather()->SetColor(BLACK);
				uncle->SetColor(BLACK);
				node->GetFather()->GetFather()->SetColor(RED);
				node = node->GetFather()->GetFather();
			}
			//叔叔节点是黑色或者不存在
			else
			{
				//情况4：不再一条直线上
				if (node->GetFather()->GetRightChild() == node)
				{
					//父节点左旋
					node->GetFather()->LeftRotate();
				}
				//情况5：在一条直线上了
				//父节点变黑，爷爷节点变红，爷爷点右旋
				node->GetFather()->SetColor(BLACK);
				node->GetFather()->GetFather()->SetColor(BLACK);
				node->GetFather()->GetFather()->RightRotate();
				//完成跳出
				break;
			}
		}
		//插入的节点在爷爷节点的右子树上
		else
		{
			RBNode<int>* uncle = node->GetFather()->GetFather()->GetLeftChild();//得到叔叔节点
			//情况3
			if (uncle != nullptr && uncle->GetCorlor == RED)
			{
				//父节点变黑，叔叔节点变黑，爷爷节点变红，node节点指向爷爷节点
				node->GetFather()->SetColor(BLACK);
				uncle->SetColor(BLACK);
				node->GetFather()->GetFather()->SetColor(RED);
				node = node->GetFather()->GetFather();
			}
			//叔叔节点是黑色
			else
			{
				//情况4：不再一条直线上
				if (node->GetFather()->GetLeftChild() == node)
				{
					//父节点右旋
					node->GetFather()->RightRotate();
				}
				//情况5：在一条直线上了
				//父节点变黑，爷爷节点变红，爷爷点左旋
				node->GetFather()->SetColor(BLACK);
				node->GetFather()->GetFather()->SetColor(BLACK);
				node->GetFather()->GetFather()->LeftRotate();
				//完成跳出
				break;
			}
		}
	}
}
