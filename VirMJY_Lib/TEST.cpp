#include<iostream>
#include"vy_Vector.h"
#include<windows.h>
using namespace vstl;

class A
{
public:
	A()
	{
		for (int i = 0; i < 10; ++i)
		{
			a[i] = i;
		}
	}
	int a[10];
};

int main()
{
	int num = 10;
	A data;
	Vector<A> b(num, data);
	Vector<A> a(b);

	for (int i = 0; i < num; ++i)
	{
		std::cout << a[i].a[i] << std::endl;
	}

	std::cout << a.size() << std::endl;
	std::cout << a.memory() << std::endl;

	getchar();
	return 0;
}