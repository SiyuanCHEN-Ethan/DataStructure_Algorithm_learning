
//https://www.cnblogs.com/jingmoxukong/p/3827011.html


//������Ľ�㶨��
template<class T>
struct LinkNode
{
	T data;
	LinkNode<T>* next;
	LinkNode(LinkNode<T>* ptr = NULL) { next = ptr };//�����ʹ��struct����ṹ��ķ�ʽ��̫��Ϥ
	LinkNode(const T& item, LinkNode<T>* ptr = NULL) 
	{
		next = ptr;
		data = item;
	}

};

//��ͷ�ڵ�ĵ�������
template<class T>
class LinkList
{
private:
	LinkNode<T>* head;
public:
	//�޲ι��캯��
	LinkList(){ head = new LinkNode<T>;}
	
	//���ι��캯��
	LinkList(const T& item) { head = new LinkNode<T>(item); }

	//�������캯��
	LinkList(LinkList<T>& List);

	//��������
	~LinkList() { Clear(); }

	//���غ���:��ֵ
	LinkList<T>& operator=(LinkList<T>& List) { this->head = List->head; }

	//�������
	void Clear();

	//��ȡ������
	int Length() const;

	//��ȡ����ͷ�ڵ�
	LinkNode<T>* GetHead() const{ return this->head; }

	//��������ͷ���
	void SetHead(LinkNode<T>* p) { this->head = p; }

	//�������ݵ�λ�ã����ص�һ���ҵ����������ֵ�Ľ��ָ��
	LinkNode<T>* Find(T& item);


	/* ��λλ�ã����������е�pos��Ԫ�صĵ�ַ�����pos<0��pos������������������NULL */
	LinkNode<T>* Locate(int pos); 

	//��ָ��λ��pos����ֵΪitem�Ľ�㣬ʧ�ܷ���flase
	bool Insert(T& item, int pos);	

	//ɾ��ָ��λ��pos�ϵĽ�� item���Ǹý���ŵ����ݣ�ʧ�ܷ���false
	bool Remove(int pos, T& item);

	//��ȡָ��λ��pos�Ľ���ֵ(��������Ƿ���ֵ����������и�ֵ�Ļ�����Ӧ����
	//������Ϊ����ֵ��ֱ��T���ͣ�����ֵ����Ӧ�þͺ�)
	T GetData(int pos) { return Locate(pos)->data; }

	//����ָ��posλ�ýڵ��ֵ,������ͷ���false
	bool SetData(int pos, T& item) { Locate(pos)->data = item; }

	//��ѯ�����Ƿ�Ϊ��
	bool IsEmpty() const ;

	//��ӡ����
	void PrintList() const;

	//��������ڵ�λ��
	void Swap(LinkNode<T>* m, LinkNode<T>* n); //����ʵ�������Լ�����
	//��������
	void SortList();
	//��������
	void ReverseList();


};

//�������캯��
template<class T>
LinkList<T>::LinkList(LinkList<T>& List)
{
	;
}

//��ȡ������
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

//��ӡ����
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
/* ��λλ�ã����������е�pos��Ԫ�صĵ�ַ�����pos<0��pos������������������NULL */
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

//��ָ��λ��pos����ֵΪitem�Ľ�㣬ʧ�ܷ���flase
template<class T>
bool LinkList<T>::Insert(T& item, int pos)
{
	LinkNode<T>* p = Locata(pos);
	if (NULL == p)
		return false;

	LinkNode<T>* node = new LinkNode<T>(item);
	if (NULL = node)
	{		
		cout << "�����ڴ�ʧ��" << endl;
		exit(1);
	}
	node->next = p->next;
	p->next = node;
	return true;

}

//ɾ��ָ��λ��pos�ϵĽ�� item���Ǹý���ŵ����ݣ�ʧ�ܷ���false
template<class T>
bool LinkList<T>::Remove(int pos, T& item)
{
	LinkNode<T>* p = Locate(pos+1);//�����ɾ���ڶ���Ԫ�أ��Ƿ�Ӧ�ö�λ����һ��Ԫ�صĽڵ��ַ�أ�������ͨ�����������һ���ڵ�ĵ�ַ��
	if (NULL = p || NULL = p->next) //��������Ӧ���ǰ������β��������������ɸѡ��
		return false;

	LinkNode<T>* del = p->next;
	p->next = del->next;
	item = del->data; //������Ͳ��Ǻ�������,�ѵ��ǵ��ڵ�Ч�������������ڣ�һ��bool һ��ʵ��T&

	delete del;
	return true;

	

}

//������գ���ͷ�ڵ㿪ʼ��������ÿ�η��ʵ���һ���ڵ��ʱ�򣬶�ɾ����һ���ڵ�ĵ�ַ
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


//�������ݵ�λ�ã����ص�һ���ҵ����������ֵ�Ľ��ָ��
template<class T>
LinkNode<T>* LinkList<T>::Find(T& item)
{
	int flag = 0; //�ҵ�ʱ���Ϊ1
	LinkNode<T>* p = head;
	while (NULL != p->next && flag == 0)
	{
		p = p->next;
		if (p->data == item) //���õ�ʱ����Ҫ���� == �����
			flag = 1;
	}
	return p;
}

//��ѯ�����Ƿ�Ϊ��
template<class T>
bool LinkList<T>::IsEmpty() const
{
	if (NULL == head->next)
		return true;
	else
		return false;
}

//��������Ԫ�ؽ���λ��,ֻ����data����
template<class T >
void LinkList<T>::Swap(LinkNode<T>* m, LinkNode<T>* n)
{
	T temp;
	temp = m->data;
	m->data = n->data;
	n->data = temp;
}

//��������
template<class T>
void LinkList<T>::SortList() //�������ð�����򣬴�С����
{
	LinkNode<T>* p = head->next; //��Ҫ�������ֱ���
	LinkNode<T>* q = p->next;

	if (p->data > q->data) //С�ڵĻ� ���ı䣬�������ȶ���
		swap(p, q); //����T����Ԫ��ֵ,����ָ��

	while (NULL!=p && NULL != p->next ) //������Ĭ����β��������
	{
		q = p->next;
		
		while (NULL!=q && NULL!=q->next)
		{
			if (q->data > q->next->data) //С�ڵĻ� ���ı䣬�������ȶ���
				swap(q, q->next); //����T����Ԫ��ֵ
			q = q->next;
		}
		p = p->next;
	}
}