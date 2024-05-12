#include <iostream>
using std::cout;
using std::endl;
template<class T>
class Node
{
public:
	Node(T data)
	{
		this->date = data;
	}
	T date;
	Node* next;
};
template<class T>
class Queue
{
public:
	Queue()
	{
		L = new Node<T>(NULL);
		L->next = NULL;
		front = L;
		rear = L;
		length = 0;
	}
	void DestroyQueue();
	void EnQueue(T data);
	void PrintQueue();
	int OutQueue();
	T getHead();
	Node<T>* L;
	Node<T>* front;
	Node<T>* rear;
	int length;
};
template<typename T>
void Queue<T>::DestroyQueue()
{
	Node<T>* p;
	while (L != NULL)
	{
		p = L;
		L = L->next;
		delete p;
	}
	front = NULL;
	rear = NULL;
}
template<typename T>
void Queue<T>::EnQueue(T data)
{
	Node<T>* p = new Node<T>(data);
	p->next = NULL;
	rear->next = p;
	rear = rear->next;
	length++;
}
template<typename T>
void Queue<T>::PrintQueue()
{
	Node<T>* p = L->next;
	while (p != NULL)
	{
		cout << p->date << " ";
		p = p->next;
	}
	cout << endl;
}
template<typename T>
int Queue<T>::OutQueue()
{
	if (length == 0)
	{
		return -1;
	}
	else
	{
		Node<T>* p = L->next;
		L->next = (L->next)->next;
		front = L->next;
		if (length == 1)
		{
			rear = L->next;
		}
		delete p;
		p = NULL;
		length--;
	}
}
template<typename T>
T Queue<T>::getHead()
{
	return (L->next)->date;
}
void test01()
{
	Queue<int>q;
	for (int i = 0; i < 10; i++)
	{
		q.EnQueue(i);
	}
	q.PrintQueue();
	cout << q.getHead() << endl;
	q.DestroyQueue();
}
int main()
{
	test01();
	return 0;
}