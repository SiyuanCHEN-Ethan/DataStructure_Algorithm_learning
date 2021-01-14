
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
	LinkList<T>& operator=(LinkList<T>& List);

	//链表清空
	void Clear();

	//获取链表长度
	int Length() const;

	//获取链表头节点
	LinkNode<T>* GetHead() const;

	//设置链表头结点
	void SetHead(LinkNode<T>* p);

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
	T GetData(int pos);

	//设置指定pos位置节点的值,有问题就返回false
	bool SetData(int pos, T& item);

	//查询链表是否为空
	bool IsEmpty() const;

	//打印链表
	void PrintList() const;

	//链表排序
	void SortList();
	//链表逆置
	void ReverseList();


};