#include <iostream>
using std::cout;
using std::endl;
using std::cin;
template<class T>
class BSTNode
{
public:
	T data;
	BSTNode<T>* lchild;
	BSTNode<T>* rchild;
};
template<class T>
class BinaryTree
{
public:
	BinaryTree(int maxsize)
	{
		this->elem = new BSTNode<T>[maxsize];
		this->maxsize = maxsize;
		num = 0;
	}
	BSTNode<T>* Search(BSTNode<T>* p, T a);
	BSTNode<T>* Delete(BSTNode<T>* p, T a);
	BSTNode<T>* elem;
	int maxsize;
	int num;
};
template<typename T>
BSTNode<T>* BinaryTree<T>::Search(BSTNode<T>* p, T a)
{
	if (p == nullptr)
	{
		return nullptr;
	}
	if (a == p->data)
	{
		return p;
	}
	else if (a < p->data)
	{
		return Search(p->lchild, a);
	}
	else
	{
		return Search(p->rchild, a);
	}
}
template<typename T>
BSTNode<T>* BinaryTree<T>::Delete(BSTNode<T>* p, T a)
{
	if (p == nullptr)
	{
		return nullptr;
	}
	if (p->lchild->data == a && p->lchild->lchild == nullptr && p->lchild->rchild == nullptr)
	{
		delete p->lchild;
	}
	else if (p->rchild->data == a && p->rchild->lchild == nullptr && p->rchild->rchild == nullptr)
	{
		delete p->rchild;
	}
	else if (p->lchild->data == a && p->lchild->lchild == nullptr)
	{
		p->lchild = p->lchild->rchild;
		delete p->lchild;
	}
	else if (p->lchild->data == a && p->lchild->rchild == nullptr)
	{
		p->lchild = p->lchild->lchild;
		delete p->lchild;
	}
	else if (p->rchild->data == a && p->rchild->lchild == nullptr)
	{
		p->rchild = p->rchild->rchild;
		delete p->rchild;
	}
	else if (p->rchild->data == a && p->rchild->rchild == nullptr)
	{
		p->rchild = p->rchild->lchild;
		delete p->rchild;
	}
	else
	{
		Delete(p->lchild, a);
		Delete(p->rchild, a);
	}
}
void test01()
{

}
int main()
{
	test01();
	return 0;
}