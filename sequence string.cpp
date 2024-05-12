#include <iostream>
using std::cout;
using std::endl;
class String
{
public:
	String(int maxsize)
	{
		p = new char[maxsize];
		length = 0;
		this->maxsize = maxsize;
	}
	~String()
	{
		delete[] p;
	}
	int pipei1(String& s1, String& s2);
	int KMP(String& s1, String& s2);
	char* p;
	int length;
	int maxsize;
};
int String::pipei1(String& s1,String&s2)
{
	char* p1 = s1.p;
	char* p2 = s2.p;
	int m = 0;
    flag:
	while (*p1 != '\0')
	{
		while (*p1 != *p2)
		{
			p1++;
			m++;
		}
		char* p3 = p2;
		while (*p3 != '\0')
		{
			p3++;
			if (*p3 != *p1)
			{
				p1++;
				goto flag;
			}
		}
		return m;
	}
	return 0;
}
int String::KMP(String& s1, String& s2)
{
	int* next = new int[s2.length];
	int m = 0;
	int n = 0;
	for (int i = 0; i < s2.length; i++)
	{
		if (i == 0)
		{
			next[i] = 0;
		}
		else if (i == 1)
		{
			next[i] = 1;
		}
		else
		{
			int a = 0;
			int b = 0;
			int c = i - 1;
			for (int j = 0; j < i - 1; j++)
			{
				for (int p = 0; p < i - 1 - j; p++)
				{
					b++;
					if (s2.p[p] == s2.p[p + 1 + j])
					{
						a++;
					}
				}
				if (a == b)
				{
					next[i] = a + 1;
					break;
				}
				else
				{
					a = 0;
					b = 0;
					c--;
				}
			}
			if (c == 0)
			{
				next[i] = 1;
			}
		}
	}
	while (m < s1.length)
	{
		if (s1.p[m] = s2.p[n])
		{
			m++;
			n++;
		}
		else
		{
			m++;
			n = next[n];
		}
		if (n == s2.length)
		{
			delete[] next;
			return m - s2.length;
		}
	}
	delete[] next;
	return 0;
}
void test01()
{
	String s(10);
}
int main()
{
	test01();
	return 0;
}