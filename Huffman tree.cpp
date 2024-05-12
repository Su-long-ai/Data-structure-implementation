#include <iostream>
using std::cout;
using std::endl;
using std::cin;
template<class T>
class HMTreeNode
{
public:
	int weight;
	int parent;
	int lchild;
	int rchild;
};
template<class T>
class HMTree
{
public:
	HMTree(int num)
	{
		L = new HMTreeNode<T>[2 * num];
		this->num = num;
	}
	int BuildHMTree();
	int num;
	HMTreeNode<T>* L;
};
template<typename T>
int HMTree<T>::BuildHMTree()
{
	if (this->num == 0)
	{
		return -1;
	}
	for (int i = 1; i < this->num + 1; i++)
	{
		cin >> this->L[i].weight;
	}
	for (int i = 1; i < 2 * this->num; i++)
	{
		this->L[i].parent = 0;
		this->L[i].lchild = 0;
		this->L[i].rchild = 0;
	}
	for (int j = this->num + 1; j < 2 * this->num; j++)
	{
		int m = INT_MAX;
		int n = INT_MAX;
		int mi = 0;
		int ni = 0;
		for (int i = 1; i < this->num + 1; i++)
		{
			if (this->L[i].weight <= m && this->L[i].parent == 0)
			{
				n = m;
				m = this->L[i].weight;
				mi = i;				
			}
			else if (this->L[i].weight < n && this->L[i].parent == 0)
			{
				n = this->L[i].weight;
				ni = i;
			}
		}
		L[j].weight = m + n;
		L[j].lchild = mi;
		L[j].rchild = ni;
		L[mi].parent = j;
		L[ni].parent = j;
	}
	return 0;
}
void test01()
{

}
int main()
{
	test01();
	return 0;
}