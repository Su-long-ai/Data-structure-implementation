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
    ~SequentialList()
    {
        delete[] elem;
    }
    T operator[](int a)
    {
        if (a<0 || a>length)
        {
            return 0;
        }
        return elem[a];
    }
    void DestroyList();
    void ClearList();
    int push_back(T a);
    void PrintList();
    bool isEmpty();
    int getLength();
    int LocateElem(int a);
    int ListInsert(int a, int b);
    int ListDelete(int a);
    T* elem;
	int length;
    int maxsize;
};
template<class T>
void SequentialList<T>::DestroyList()
{
    delete[] elem;
    elem = NULL;
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
        elem[length] = a;
        length++;
    }
}
template<class T>
void SequentialList<T>::PrintList()
{
    for (int i = 0; i < length; i++)
    {
        cout << elem[i] << " ";
    }
    cout << endl;
}
template<class T>
void SequentialList<T>::ClearList()
{
    length = 0;
}
template<class T>
bool SequentialList<T>::isEmpty()
{
    if (length == 0)
    {
        return 1;
    }
    return 0;
}
template<class T>
int SequentialList<T>::getLength()
{
    return length;
}
template<class T>
int SequentialList<T>::LocateElem(int a)
{
    for (int i = 0; i <= length; i++)
    {
        if (a == elem[i])
        {
            return i;
        }
    }
    return 0;
}
template<class T>
int SequentialList<T>::ListInsert(int a, int b)
{
    if (a<0 || a>length)
    {
        return 0;
    }
    else if (length == maxsize)
    {
        return 0;
    }
    else
    {
        for (int i = 0; i <= length - a; i++)
        {
            elem[length + 1 - i] = elem[length - i];
        }
        elem[a] = b;
        length++;
    }
}
template<class T>
int SequentialList<T>::ListDelete(int a)
{
    if (a < 0 || a > length)
    {
        return 0;
    }
    else
    {
        for (int i = 1; i <= length - a; i++)
        {
            elem[a + i - 1] = elem[a + i];
        }
        length--;
    }
}
void test01()
{
    SequentialList<int>L(10);
    for (int i = 1; i < 6; i++)
    {
        L.push_back(i);
    }
    L.PrintList();
    cout << L.length << endl;
    L.ListInsert(5,7);
    L.PrintList();
    L.ListDelete(3);
    L.PrintList();
    L.ListDelete(2);
    L.PrintList();
    L.ListDelete(1);
    L.ListDelete(3);
    L.PrintList();
}
int main()
{
    test01();
    return 0;
}