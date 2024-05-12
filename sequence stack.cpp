#include <iostream>
using std::cout;
using std::endl;
using std::cin;
template<class T>
class Stack
{
public:
	Stack(int maxsize)
	{
		elem = new T[maxsize];
		length = 0;
		this->maxsize = maxsize;
	}
	void DestroyStack();
	bool isEmpty();
	int getLength();
	T getTop();
	void ClearList();
	int PushElem(T elem);
	int PopElem();
	void PrintList();
	T* elem;
	int length;
	int maxsize;
};
template<typename T>
void Stack<T>::DestroyStack()
{
	delete[] elem;
	elem = NULL;
}
template<class T>
bool Stack<T>::isEmpty()
{
	if (length == 0)
	{
		return 1;
	}
	return 0;
}
template<class T>
int Stack<T>::getLength()
{
	return length;
}
template<class T>
T Stack<T>::getTop()
{
	if (length == 0)
	{
		return -1;
	}
	else
	{
		return elem[maxsize-length];
	}
}
template<class T>
void Stack<T>::ClearList()
{
	length = 0;
}
template<class T>
int Stack<T>::PushElem(T elem)
{
	if (length == maxsize)
	{
		return -1;
	}
	else
	{
		this->elem[maxsize - length - 1] = elem;
		length++;
	}
}
template<class T>
int Stack<T>::PopElem()
{
	if (length == 0)
	{
		return -1;
	}
	else
	{
		length--;
	}
}
template<class T>
void Stack<T>::PrintList()
{
	for (int i = 0; i < length; i++)
	{
		cout << elem[maxsize - length + i] << " ";
	}
	cout << endl;
}
void test01()
{
	Stack<int>s(10);
	for (int i = 0; i < 5; i++)
	{
		s.PushElem(i);
	}
	s.PrintList();
	s.PopElem();
	s.PrintList();
	cout << s.getTop() << endl;
	s.ClearList();
	s.PrintList();
}
int main()
{
	test01();
	return 0;
}