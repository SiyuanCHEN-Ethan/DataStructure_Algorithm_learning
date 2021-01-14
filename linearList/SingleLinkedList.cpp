
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
	LinkList<T>& operator=(LinkList<T>& List);

	//�������
	void Clear();

	//��ȡ������
	int Length() const;

	//��ȡ����ͷ�ڵ�
	LinkNode<T>* GetHead() const;

	//��������ͷ���
	void SetHead(LinkNode<T>* p);

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
	T GetData(int pos);

	//����ָ��posλ�ýڵ��ֵ,������ͷ���false
	bool SetData(int pos, T& item);

	//��ѯ�����Ƿ�Ϊ��
	bool IsEmpty() const;

	//��ӡ����
	void PrintList() const;

	//��������
	void SortList();
	//��������
	void ReverseList();


};