#include <iostream>
using std::cout;
using std::endl;
template<class T>
class Data
{
public:
	T value;
};
template<class T>
class Node
{
public:
	Node(T value)
	{
		data.value = value;
		next = NULL;
	}
	Data<T> data;
	Node* next;
};
template<class T>
class LinkList
{
public:
	LinkList()
	{
		L = new Node<T>(NULL);
		L->next = NULL;
	}
	~LinkList()
	{
		DestroyList();
		L = NULL;
	}
	bool isEmpty();  
	void DestroyList();
	void ClearList();
	int getLength();
	Data<T> getData(int i);
	int findData(Data<T>& d);
	int insertNode(int i);
	int deleteNode(int i);
	void frontInsert(T value);
	void backInsert();
	void PrintList();
	void mergeList(LinkList& L1, LinkList& L2);
	Node<T>* L;
};
template<typename T>
bool LinkList<T>::isEmpty()
{
	return (L->next == NULL);
}
template<typename T>
void LinkList<T>::DestroyList()
{
	Node<T>* p;
	while (L != NULL)
	{
		p = L;
		L = L->next;
		delete p;
	}
}
template<typename T>
void LinkList<T>::ClearList()
{
	Node<T>* p = L->next;
	Node<T>* q;
	while (p != NULL)
	{
		q = p->next;
		delete p;
		p = q;
	}
	L->next = NULL;
}
template<typename T>
int LinkList<T>::getLength()
{
	int len = 0;
	Node<T>* p = L->next;
	while (p != NULL)
	{
		p = p->next;
		len++;
	}
	return len;
}
template<typename T>
Data<T> LinkList<T>::getData(int i)
{
	int a = 1;
	Node<T>* p = L->next;
	while (p != NULL)
	{
		if (a != i)
		{
			p = p->next;
			a++;
		}
		else
		{
			return p->data;
		}
	}
}
template<typename T>
int LinkList<T>::findData(Data<T>& d)
{
	int m = 0;
	Node<T>* p = L->next;
	while (p != NULL)
	{
		if (p->data == d)
		{
			return m;
		}
		else
		{
			p = p->next;
			m++;
		}
	}
}
template<typename T>
int LinkList<T>::insertNode(int i)
{
	int a = 2;
	Node<T>* p = L->next;
	if (i<1 || i>getLength() + 1)
	{
		return -1;
	}
	while (a != i)
	{
		p = p->next;
		a++;
	}
	Node<T>* p1 = new Node<T>();
	p1->next = p->next;
	p->next = p1;
}
template<typename T>
int LinkList<T>::deleteNode(int i)
{
	int a = 2;
	Node<T>* p = L->next;
	if (i<1 || i>getLength() + 1)
	{
		return -1;
	}
	while (a != i)
	{
		p = p->next;
		a++;
	}
	Node<T>* p1 = p->next;
	p->next = p1->next;
	delete p1;
}
template<typename T>
void LinkList<T>::frontInsert(T value)
{
	Node<T>* p = new Node<T>(value);
	p->next = L->next;
	L->next = p;
}
template<typename T>
void LinkList<T>::backInsert()
{
	Node<T>* p = L;
	while (p->next != NULL)
	{
		p = p->next;
	}
	p->next = new Node<T>();
}
template<typename T>
void LinkList<T>::PrintList()
{
	Node<T>* p = L->next;
	while (p != NULL)
	{
		cout << (p->data).value << " ";
		p = p->next;
	}
	cout << endl;
}
template<typename T>
void LinkList<T>::mergeList(LinkList& L1, LinkList& L2)
{
	Node<T>* p = L1.L;
	while ((p->next) != NULL)
	{
		p = p->next;
	}
	p->next = L2.L->next;
	L2.L->next = NULL;
	delete L2.L;
}
void test01()
{
	LinkList<int>L;
	for (int i = 0; i < 10; i++)
	{
		L.frontInsert(i);
	}
	cout << L.isEmpty() << endl;
	L.PrintList();
	cout << L.getLength() << endl;
	L.ClearList();
	cout << L.isEmpty() << endl;
	L.DestroyList();
}
int main()
{
	test01();
	return 0;
}