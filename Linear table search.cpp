#include <iostream>
using std::cout;
using std::endl;
template<class T>
class SequentialList
{
public:
	SequentialList(int maxsize)
	{
		elem = new T[maxsize];
		length = 0;
		this->maxsize = maxsize;
	}
	void PrintList();
	int push_back(T a);
	int SearchKey(T a);
	int BinarySearch(T a);
	T* elem;
	int length;
	int maxsize;
};
template<class T>
void SequentialList<T>::PrintList()
{
	for (int i = 1; i < length + 1; i++)
	{
		cout << elem[i] << " ";
	}
	cout << endl;
}
template<class T>
int SequentialList<T>::push_back(T a)
{
	if (length == maxsize)
	{
		return 0;
	}
	else
	{
		elem[length + 1] = a;
		length++;
	}
}
template<class T>
int SequentialList<T>::SearchKey(T a)
{
	elem[0] = a;
	for (int i = this->length;; i--)
	{
		if (elem[i] == a)
		{
			return i;
		}
	}
}
template<class T>
int SequentialList<T>::BinarySearch(T a)
{
	int low = 1;
	int high = length;
	int mid = (low + high) / 2;
	while (elem[mid] != a)
	{
		if (high < low);
		{
			return 0;
		}
		if (a > elem[mid])
		{
			low = mid + 1;
			mid = (low + high) / 2;
		}
		else
		{
			high = mid - 1;
			mid = (low + high) / 2;
		}
	}
	return mid;
}
void test01()
{
	SequentialList<int>s(10);
	for (int i = 1; i < 10; i++)
	{
		s.push_back(i);
	}
	s.PrintList();
	cout << s.SearchKey(4) << endl;
	cout << s.BinarySearch(62) << endl;
}
int main()
{
	test01();
	return 0;
}