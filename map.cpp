#include <iostream>
using std::cout;
using std::endl;
using std::cin;
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
template<class T>
class LGraphTableNode
{
public:
	LGraphTableNode(int num)
	{
		adjvex = num;
		nextarc = nullptr;
	}
	int adjvex;
	LGraphTableNode<T>* nextarc;
};
template<class T>
class LGraphHeadNode
{
public:
	LGraphHeadNode()
	{
		firstarc = nullptr;
	}
	T data;
	LGraphTableNode<T>* firstarc;
};
template<class T>
class LGraph
{
public:
	LGraph(int num1, int num2)
	{
		Vexs = new LGraphHeadNode<T>[num1];
		vexnum = num1;
		arcnum = num2;
	}
	int CreateGraph();
	int LocateVex(T a);
	int BFSTraverse(int start);
	T* Vexs;
	int vexnum;
	int arcnum;
};
template<typename T>
int LGraph<T>::LocateVex(T a)
{
	for (int i = 0; i < this->vexnum; i++)
	{
		if (Vexs[i].data == a)
		{
			return i;
		}
	}
	return -1;
}
template<typename T>
int LGraph<T>::CreateGraph()
{
	for (int i = 0; i < this->vexnum; i++)
	{
		cin >> Vexs[i].data;
	}
	for (int k = 0; k < this->arcnum; k++)
	{
		T a = 0;
		T b = 0;
		cin >> a >> b;
		int i = LocateVex(a);
		int j = LocateVex(b);
		if (i == -1 || j == -1)
		{
			return -1;
		}
		else
		{
			if (Vexs[i].firstarc != nullptr)
			{
				LGraphTableNode<T>* p1 = Vexs[i].firstarc;
				p1 = p1->nextarc;
				while (p1->nextarc != nullptr)
				{
					p1 = p1->nextarc;
				}
				p1->nextarc = new LGraphTableNode<T>(j);
			}
			else
			{
				Vexs[i].firstarc = new LGraphTableNode<T>(j);
			}
			if (Vexs[j].firstarc != nullptr)
			{
				LGraphTableNode<T>* p2 = Vexs[j].firstarc;
				p2 = p2->nextarc;
				while (p2->nextarc != nullptr)
				{
					p2 = p2->nextarc;
				}
				p2->nextarc = new LGraphTableNode<T>(j);
			}
			else
			{
				Vexs[j].firstarc = new LGraphTableNode<T>(i);
			}
		}
	}
	return 0;
}
template<typename T>
int LGraph<T>::BFSTraverse(int start)
{
	if (this->vexnum == 0)
	{
		return -1;
	}
	int a[this->vexnum] = { 0 };
	Queue<T>q(this->vexnum);
	q.pushElem(Vexs[start]);
	while (q.length != 0)
	{
		LGraphTableNode<T>* p = q.getHead();
		cout << Vexs[p->adjvex] << " ";
		while (p->nextarc != nullptr)
		{
			if (a[p->adjvex] == 0)
			{
				q.pushElem(Vexs[p->adjvex]);
				a[p->adjvex] = 1;
			} 
			p = p->nextarc;
		}
		q.offElem();
	}
	return 0;
}
template<class T>
class Graph
{
public:
	Graph(int num1,int num2)
	{
		this->Vexs = new T[num1];
		this->arcs = new int*[num1];
		for (int i = 0; i < num1; i++)
		{
			arcs[i] = new int[num1];
			for (int j = 0; j < num1; j++)
			{
				arcs[i][j] = INT_MAX;
			}
		}
		this->vexnum = num1;
		this->arcnum = num2;
	}
	int CreateGraph();
	int DFSTraverse(int v);	
	int LocateVex(T a);
	T* Vexs;
	int** arcs;
	int vexnum;
	int arcnum;
};
template<typename T>
int Graph<T>::LocateVex(T a)
{
	for (int i = 0; i < this->vexnum; i++)
	{
		if (Vexs[i] == a)
		{
			return i;
		}
	}
	return -1;
}
template<typename T>
int Graph<T>::CreateGraph()
{
	for (int i = 0; i < this->vexnum; i++)
	{
		cin >> Vexs[i];
	}
	for (int k = 0; k < this->arcnum; k++)
	{
		T v1 = 0;
		T v2 = 0;
		int w = 0;
		cin >> v1 >> v2 >> w;
		int i = LocateVex(v1);
		int j = LocateVex(v2);
		if (i == -1 || j == -1)
		{
			return -1;
		}
		else
		{
			arcs[i][j] = w;
			arcs[j][i] = w;
		}
	}
	return 1;
}
template<typename T>
int Graph<T>::DFSTraverse(int v)
{
	int a[this->vexnum] = { 0 };
	cout << Vexs[v] << " ";
	a[v] = 1;
	for (int w = 0; w < this->vexnum; w++)
	{
		if (arcs[v][w] != INT_MAX && a[w] == 0)
		{
			DFSTraverse(w);
		}
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