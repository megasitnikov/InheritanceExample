// task1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

class B
{
	int a;
public:
	B() { cout << "object of " << typeid(*this).name() << " was created\n"; };
	B(int x) : B() { a = x; };
	~B() { cout << "object of " << typeid(*this).name() << " was destroyed\n"; }
};

class D1 : public B
{
	int b;
public:
	D1(int x, int y) : B(y)
	{
		b = x;
		cout << "object of " << typeid(*this).name() << " was created\n";
	}
	~D1() { cout << "object of " << typeid(*this).name() << " was destroyed\n"; }
};

class D2 : private B
{
	int c;
public:
	D2(int x, int y) : B(y)
	{
		c = x;
		cout << "object of " << typeid(*this).name() << " was created\n";
	}
	~D2() { cout << "object of " << typeid(*this).name() << " was destroyed\n"; }
};

class D3 :private B
{
	int d;
public:
	D3(int x, int y) :B(y)
	{
		d = x;
		cout << "object of " << typeid(*this).name() << " was created\n";
	}
	~D3() { cout << "object of " << typeid(*this).name() << " was destroyed\n"; }

};

class D4 : private D1
{
	int e;
public:
	D4(int x, int y, int z) : D1(y, z)
	{
		e = x;
		cout << "object of " << typeid(*this).name() << " was created\n";
	}
	~D4() { cout << "object of " << typeid(*this).name() << " was destroyed\n"; }
};

class D5 : public D2, private D3
{
	int f;
public:
	D5(int x, int y, int z, int i, int j) : D2(y, z), D3(i, j)
	{
		f = x;
		cout << "object of " << typeid(*this).name() << " was created\n";
	}
	~D5() { cout << "object of " << typeid(*this).name() << " was destroyed\n"; }
};

int main()
{
	D4 temp(100, 200, 300);
	D5 temp1(1, 2, 3, 4, 5);
}