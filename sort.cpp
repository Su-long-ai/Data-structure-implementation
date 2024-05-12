#include <iostream>
#include <ctime>
using std::cout;
using std::endl;
using std::cin;
void InsertSort(int a[], int len)
{
	for (int i = 1; i < len; i++)
	{
		if (a[i] >= a[i - 1])
		{
			
		}
		else
		{
			int temp = a[i];
			int low = 0;
			int high = i - 1;
			int mid = (low + high) / 2;
			while (low <= high)
			{
				if (a[mid] <= a[i])
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
			for (int j = i; j > low; j--)
			{
				a[j] = a[j - 1];
			}
			a[low] = temp;
			/*for (int j = 0; j < i; j++)
			{
				if (a[j] > a[i])
				{
					int temp = a[i];
					for (int k = i; k > j; k--)
					{
						a[k] = a[k - 1];
					}
					a[j] = temp;
				}
			}*/
		}
	}
}
void ShellSort(int a[], int len, int dk)
{
	while (dk > 0)
	{
		for (int i = dk; i < len; i = i + dk)
		{
			int temp = a[i];
			int j = i - dk;
			while (j >= 0 && a[j] > temp)	
			{
				a[j + dk] = a[j];
				a[j] = temp;
				j = j - dk;
			}
		}
		dk = dk / 2;
	}
}
void BubbleSort(int a[], int len)
{
	int n = 0;
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
				n++;
			}
		}
		if (n == 0)
		{
			break;
		}
	}
}
void QuickSort(int a[], int low, int high)
{
	if (low >= high) 
	{
		return;
	}
	int pivot = a[low];
	int left = low + 1; 
	int right = high;
	while (left <= right) 
	{
		while (left <= right && a[left] <= pivot) 
		{
			left++;
		}
		while (left <= right && a[right] >= pivot) 
		{
			right--; 
		}
		if (left < right) 
		{
			int temp = a[left];
			a[left] = a[right];
			a[right] = temp;
		}
	}
	a[low] = a[right];
	a[right] = pivot;
	QuickSort(a, low, right - 1);
	QuickSort(a, right + 1, high);
}
void SelectionSort(int a[], int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < len; j++)
		{
			if (a[j] < a[min])
			{
				min = j;
			}
		}
		if (min != i)
		{
			int temp = a[i];
			a[i] = a[min];
			a[min] = temp;
		}
	}
}
void HeapSortHelper(int a[], int len)
{
	for (int i = len / 2 - 1; i >= 0; i--)
	{
		if (2 * i + 2 <= len - 1)
		{
			if (a[2 * i + 1] > a[2 * i + 2])
			{
				if (a[i] > a[2 * i + 2])
				{
					int temp = a[i];
					a[i] = a[2 * i + 2];
					a[2 * i + 2] = temp;
				}
			}
			else
			{
				if (a[i] > a[2 * i + 1])
				{
					int temp = a[i];
					a[i] = a[2 * i + 1];
					a[2 * i + 1] = temp;
				}
			}
		}
		else
		{
			if (a[i] > a[2 * i + 1])
			{
				int temp = a[i];
				a[i] = a[2 * i + 1];
				a[2 * i + 1] = temp;
			}
		}
	}
	int n = 0;
	for (int i = 0; i <= len / 2 - 1; i++)
	{
		if (2 * i + 2 <= len - 1)
		{
			if (a[i] > a[2 * i + 1] || a[i] > a[2 * i + 2])
			{
				n++;
			}
		}
		else
		{
			if (a[i] > a[2 * i + 1])
			{
				n++;
			}
		}
	}
	if (n == 0)
	{
		return;
	}
	else
	{
		HeapSortHelper(a, len);
	}
}
void HeapSort(int a[], int len)
{
	int num = len;
	HeapSortHelper(a, len);
	for (int i = 0; i < num; i++)
	{
		int temp = a[0];
		a[0] = a[len - 1];
		a[len - 1] = temp;
		len--;
		HeapSortHelper(a, len);
	}
	int* p = new int[num];
	for (int i = 0; i < num; i++)
	{
		p[i] = a[i];
	}
	for (int i = 0; i < num; i++)
	{
		a[i] = p[num - i - 1];
	}
	delete[] p;
}
void Print(int a[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
void Initialization(int a[], int len)
{
	int b = 0;
	for (int i = 0; i < 10; i++)
	{
		b = rand() % 100;
		a[i] = b;
	}
}
void test01()
{
	int a[10] = {0};
	Initialization(a, 10);
	Print(a, 10);
	InsertSort(a, 10);
	Print(a, 10);
	cout << endl;
}
void test02()
{
	int a[10] = { 0 };
	Initialization(a, 10);
	Print(a, 10);
	ShellSort(a, 10, 3);
	Print(a, 10);
	cout << endl;
}
void test03()
{
	int a[10] = { 0 };
	Initialization(a, 10);
	Print(a, 10);
	BubbleSort(a, 10);
	Print(a, 10);
	cout << endl;
}
void test04()
{
	int a[10] = { 0 };
	Initialization(a, 10);
	Print(a, 10);
	QuickSort(a, 0, 9);
	Print(a, 10);
	cout << endl;
}
void test05()
{
	int a[10] = { 0 };
	Initialization(a, 10);
	Print(a, 10);
	SelectionSort(a, 10);
	Print(a, 10);
	cout << endl;
}
void test06()
{
	int a[10] = { 0 };
	Initialization(a, 10);
	Print(a, 10);
	HeapSort(a, 10);
	Print(a, 10);
	cout << endl;
}
int main()
{
	srand(time(NULL));
	test01();
	test02();
	test03();
	test04();
	test05();
	test06();
	return 0;
}
//没写基数(O(n))和归并排序(O(nlogn))