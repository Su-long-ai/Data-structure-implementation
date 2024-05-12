#include <iostream>
using std::cout;
using std::endl;
template<class T>
class Queue
{
public:
	Queue(int maxsize)
	{
		elem = new T[maxsize];
		length = 0;
		this->maxsize = maxsize;
	}
	void DestroyQueue();
	void ClearQueue();
	int getLength();
	T getHead();
	int pushElem(T elem);
	int offElem();
	void printQueue();
	T* elem;
	int length;
	int maxsize;
};
template<typename T>
void Queue<T>::DestroyQueue()
{
	delete[] elem;
	elem = NULL;
}
template<typename T>
void Queue<T>::ClearQueue()
{
	length = 0;
}
template<typename T>
int Queue<T>::getLength()
{
	return length;
}
template<typename T>
T Queue<T>::getHead()
{
    return elem[0];
}
template<typename T>
int Queue<T>::pushElem(T elem)
{
	if (length == maxsize)
	{
		return -1;
	}
	else
	{
		this->elem[length] = elem;
		length++;
	}
}
template<typename T>
int Queue<T>::offElem()
{
	if (length == 0)
	{
		return -1;
	}
	else
	{
		for (int i = 0; i < length - 1; i++)
		{
			this->elem[i] = this->elem[1 + i];
		}
		length--;
	}
}
template<typename T>
void Queue<T>::printQueue()
{
	for (int i = 0; i < length; i++)
	{
		cout << elem[i] << " ";
	}
	cout << endl;
}
void test01()
{
	Queue<int>q(10);
	for (int i = 0; i < 10; i++)
	{
		q.pushElem(i);
	}
	q.printQueue();
	q.offElem();
	q.printQueue();
	q.pushElem(42);
	q.printQueue();
	q.ClearQueue();
	q.printQueue();
}
int main()
{
	test01();
	return 0;
}