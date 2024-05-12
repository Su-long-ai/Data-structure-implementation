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
template<class T>
class SBinaryTree
{
public:
	SBinaryTree(int maxsize)
	{
		this->elem = new T[maxsize];
		this->maxsize = maxsize;
	}
	void CreateBiTree();
	void PreOrderTraverse();
	void InOrderTraverse();
	void PostOrderTraverse();
	T* elem;
	int maxsize;
};
template<class T>
class LBTnode
{
public:
	LBTnode(T data)
	{
		this->data = data;
		lchild = NULL;
		rchild = NULL;
	}
	LBTnode* lchild;
	T data;
	LBTnode* rchild;
};
template<class T>
class BiThrNode
{
public:
	BiThrNode* lchild;
	T data;
	BiThrNode* rchild;
	int ltag;
	int rtag;
};
template<class T>
class LBinaryTree
{
public:
	LBinaryTree(int maxsize)
	{
		L = new LBTnode<T>[maxsize];
		this->maxsize = maxsize;
	}
	~LBinaryTree()
	{
		delete[] L;
	}
	int DGPrintTree(LBTnode<T>* L);
	void NDGPrintTree();
	void CCPrintTree();
	void CharXXBuildTree(LBTnode<T>* L);
	int CopyTree(LBTnode<T>* L1, LBTnode<T>*& L2);
	int Depth(LBTnode<T>* L);
	int CountNode(LBTnode<T>* L);
	int CountLeaf(LBTnode<T>* L);
	LBTnode<T>* L;
	int maxsize;
};
template<typename T>
void SBinaryTree<T>::CreateBiTree()
{

}
template<typename T>
void SBinaryTree<T>::PreOrderTraverse()
{

}
template<typename T>
void SBinaryTree<T>::InOrderTraverse()
{

}
template<typename T>
void SBinaryTree<T>::PostOrderTraverse()
{

}
template<typename T>
int LBinaryTree<T>::DGPrintTree(LBTnode<T>* L)
{
	if (L == NULL)
	{
		return 0;
	}
	else
	{
		cout << L->data << " ";
		DGPrintTree(L->lchild);
		DGPrintTree(L->rchild);
	}
}
template<typename T>
void LBinaryTree<T>::NDGPrintTree()
{
	LBTnode<T>* p = L;
	Stack<T> s(maxsize);
	while (p != NULL || !s.isEmpty())
	{
		if (p != NULL)
		{
			s.PushElem(p->data);
			p = p->lchild;
		}
		else
		{
			cout << s.getTop() << " ";
			s.PopElem();
			p = p->rchild;
		}
	}
}
template<typename T>
void LBinaryTree<T>::CCPrintTree()
{
	Queue<T>q(maxsize);
	if (L != NULL)
	{
		q.pushElem(L);
	}
	while (q.length != 0)
	{
		LBTnode<T>* p = q.getHead();
		if (p->lchild != NULL)
		{
			q.pushElem(p->lchild);
		}
		if (p->rchild != NULL)
		{
			q.pushElem(p->rchild);
		}
		cout << p->data << " ";
		q.offElem();
	}
	cout << endl;
}
template<typename T>
void LBinaryTree<T>::CharXXBuildTree(LBTnode<T>* L)
{
	char ch = {};
	cin >> ch;
	if (ch == "#")
	{
		L = NULL;
	}
	else
	{
		L->data = ch;
		XXBuildTree(L->lchild);
		XXBuildTree(L->rchild);
	}
}
template<typename T>
int LBinaryTree<T>::CopyTree(LBTnode<T>* L1, LBTnode<T>*& L2)
{
	if (L1 == NULL)
	{
		L2 = NULL;
		return 0;
	}
	else
	{
		L2 = new LBTnode<T>;
		L2->data = L1->data;
		CopyTree(L1->lchild, L2->lchild);
		CopyTree(L1->rchild, L2->rchild);
	}
}
template<typename T>
int LBinaryTree<T>::Depth(LBTnode<T>* L)
{
	int m = 0;
	int n = 0;
	if (L == NULL)
	{
		return 0;
	}
	else
	{
		m = Depth(L->lchild);
		n = Depth(L->rchild);
		if (m > n)
		{
			return m + 1;
		}
		else
		{
			return n + 1;
		}
	}
}
template<typename T>
int LBinaryTree<T>::CountNode(LBTnode<T>* L)
{
	if (L == NULL)
	{
		return 0;
	}
	else
	{
		return CountNode(L->lchild) + CountNode(L->rchild) + 1;
	}
}
template<typename T>
int LBinaryTree<T>::CountLeaf(LBTnode<T>* L)
{
	if (L == NULL)
	{
		return 0;
	}
	if (L->lchild == NULL && L->rchild == NULL)
	{
		return 1;
	}
	else
	{
		return CountLeaf(L->lchild) + CountLeaf(L->rchild);
	}
}
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
		return elem[maxsize - length];
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
	LBinaryTree<int>T(10);
	T.DGPrintTree(T.L);
}
int main()
{
	test01();
	return 0;
}