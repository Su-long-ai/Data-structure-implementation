#include <iostream>
using std::cout;
using std::endl;
template<class T>
class TreeNode1
{
public:
	int number;
	TreeNode1<T>* children;
};
template<class T>
class TreeNodeFirst
{
public:
	int parent;
	T data;
	TreeNode1<T>* children;
};
template<class T>
class TreeNode2
{
public:
	T data;
	TreeNode2<T>* firstchild;
	TreeNode2<T>* nextbrother;
};
template<class T>
class Tree
{
public:
	Tree(int maxsize)
	{
		this->L = new TreeNodeFirst<T>[maxsize];
		this->maxsize = maxsize;
		this->num = 0;
	}
	int maxsize;
	int num;
	int root;
	TreeNode1<T>* L;
};
void test01()
{

}
int main()
{
	test01();
	return 0;
}