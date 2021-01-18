
//https://www.cnblogs.com/jingmoxukong/p/3827011.html


//单链表的结点定义
template<class T>
struct LinkNode
{
	T data;
	LinkNode<T>* next;
	LinkNode(LinkNode<T>* ptr = NULL) { next = ptr };//！这边使用struct构造结构体的方式不太熟悉
	LinkNode(const T& item, LinkNode<T>* ptr = NULL) 
	{
		next = ptr;
		data = item;
	}

};

//带头节点的单链表定义
template<class T>
class LinkList
{
private:
	LinkNode<T>* head;
public:
	//无参构造函数
	LinkList(){ head = new LinkNode<T>;}
	
	//带参构造函数
	LinkList(const T& item) { head = new LinkNode<T>(item); }

	//拷贝构造函数
	LinkList(LinkList<T>& List);

	//析构函数
	~LinkList() { Clear(); }

	//重载函数:赋值
	LinkList<T>& operator=(LinkList<T>& List) { this->head = List->head; }

	//链表清空
	void Clear();

	//获取链表长度
	int Length() const;

	//获取链表头节点
	LinkNode<T>* GetHead() const{ return this->head; }

	//设置链表头结点
	void SetHead(LinkNode<T>* p) { this->head = p; }

	//查找数据的位置，返回第一个找到的满足该数值的结点指针
	LinkNode<T>* Find(T& item);


	/* 定位位置：返回链表中第pos个元素的地址，如果pos<0或pos超出链表最大个数返回NULL */
	LinkNode<T>* Locate(int pos); 

	//在指定位置pos插入值为item的结点，失败返回flase
	bool Insert(T& item, int pos);	

	//删除指定位置pos上的结点 item就是该结点存放的数据，失败返回false
	bool Remove(int pos, T& item);

	//获取指定位置pos的结点的值(如果单纯是返回值，不对其进行赋值的话，不应该用
	//引用作为返回值，直接T类型，进行值拷贝应该就好)
	T GetData(int pos) { return Locate(pos)->data; }

	//设置指定pos位置节点的值,有问题就返回false
	bool SetData(int pos, T& item) { Locate(pos)->data = item; }

	//查询链表是否为空
	bool IsEmpty() const ;

	//打印链表
	void PrintList() const;

	//交换链表节点位置
	void Swap(LinkNode<T>* m, LinkNode<T>* n); //方便实现排序以及逆置
	//链表排序
	void SortList();
	//链表逆置
	void ReverseList();


};

//拷贝构造函数
template<class T>
LinkList<T>::LinkList(LinkList<T>& List)
{
	;
}

//获取链表长度
template<class T>
int LinkList<T>::Length() const
{
	int count = 0;
	LinkNode<T>* p = head->next;
	while (NULL != p)
	{
		p = p->next;
		++count;
	}
	return count;
}

//打印链表
template<class T>
void LinkList<T>::PrintList() const
{
	int count = 0;
	LinkNode<T>* p = head;

	while (NULL != p)
	{
		p = p->next;
		cout << p->data << " ";
		++count;
		if (count % 10 == 0)
			cout << endl; 
	}

}
/* 定位位置：返回链表中第pos个元素的地址，如果pos<0或pos超出链表最大个数返回NULL */
template<class T>
LinkNode<T>* LinkList<T>::Locate(int pos)
{
	int i = 0;
	LinkNode<T>* p = head;

	if pos < 0
		return NULL;

	while (NULL != p && i < pos)
	{
		p = p->next;
		++i;
	}
	return p;
}

//在指定位置pos插入值为item的结点，失败返回flase
template<class T>
bool LinkList<T>::Insert(T& item, int pos)
{
	LinkNode<T>* p = Locata(pos);
	if (NULL == p)
		return false;

	LinkNode<T>* node = new LinkNode<T>(item);
	if (NULL = node)
	{		
		cout << "分配内存失败" << endl;
		exit(1);
	}
	node->next = p->next;
	p->next = node;
	return true;

}

//删除指定位置pos上的结点 item就是该结点存放的数据，失败返回false
template<class T>
bool LinkList<T>::Remove(int pos, T& item)
{
	LinkNode<T>* p = Locate(pos+1);//如果想删掉第二个元素，是否应该定位到第一个元素的节点地址呢？（或者通过遍历求出上一个节点的地址）
	if (NULL = p || NULL = p->next) //猜想这里应该是按添加了尾结点的做法来进行筛选的
		return false;

	LinkNode<T>* del = p->next;
	p->next = del->next;
	item = del->data; //！这里就不是很明白了,难道是等于等效设置了两个出口，一个bool 一个实参T&

	delete del;
	return true;

	

}

//链表清空：从头节点开始遍历链表，每次访问到下一个节点的时候，都删除上一个节点的地址
template<class T>
void LinkList<T>::Clear()
{
	LinkNode<T>* p = NULL;
	while (NULL != head->next)
	{
		p = head->next;
		head->next = p->next;
		delete p;
	}

}


//查找数据的位置，返回第一个找到的满足该数值的结点指针
template<class T>
LinkNode<T>* LinkList<T>::Find(T& item)
{
	int flag = 0; //找到时标记为1
	LinkNode<T>* p = head;
	while (NULL != p->next && flag == 0)
	{
		p = p->next;
		if (p->data == item) //调用的时候类要允许 == 运算符
			flag = 1;
	}
	return p;
}

//查询链表是否为空
template<class T>
bool LinkList<T>::IsEmpty() const
{
	if (NULL == head->next)
		return true;
	else
		return false;
}

//链表内两元素交换位置,只交换data即可
template<class T >
void LinkList<T>::Swap(LinkNode<T>* m, LinkNode<T>* n)
{
	T temp;
	temp = m->data;
	m->data = n->data;
	n->data = temp;
}

//链表排序
template<class T>
void LinkList<T>::SortList() //这里采用冒泡排序，从小到大
{
	LinkNode<T>* p = head->next; //需要经历两轮遍历
	LinkNode<T>* q = p->next;

	if (p->data > q->data) //小于的话 不改变，所以是稳定的
		swap(p, q); //交换T类型元素值,不改指针

	while (NULL!=p && NULL != p->next ) //这种是默认有尾结点的做法
	{
		q = p->next;
		
		while (NULL!=q && NULL!=q->next)
		{
			if (q->data > q->next->data) //小于的话 不改变，所以是稳定的
				swap(q, q->next); //交换T类型元素值
			q = q->next;
		}
		p = p->next;
	}
}