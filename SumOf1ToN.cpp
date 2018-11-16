/*******************************************************************
*《剑指Offer——名企面试官精讲典型编程题》C++代码
*
* htfeng
* 2018.11.14
*
* 面试题64: 求1+2+3+...+n
* 题目：求1到n的和，要求不能使用乘除法，for、while、if、else、switch、case等
* 关键字及条件判断语句（A？B:C)
*
********************************************************************/

// 利用构造函数求解，先定义一个类型，创建n个该类型的实例
#include<iostream>

using namespace std;

class Temp {
public:
	Temp() { ++N; Sum += N; }
	static void Reset() { N = 0; Sum = 0; }
	static unsigned int GetSum() { return Sum; }
private:
	static unsigned int N;
	static unsigned int Sum;
};

unsigned int Temp::N = 0;
unsigned int Temp::Sum = 0;

unsigned int Sum_Solution1(unsigned int n) {
	Temp::Reset();

	Temp *a = new Temp[n];
	delete[] a;
	a = nullptr;

	return Temp::GetSum();
}

// 解法二: 利用虚函数求解:虚函数的作用是允许在派生类中重新定义与基类同名的函数，
// 并且可以通过基类指针或引用来访问基类和派生类中的同名函数
class A;
A* Array[2];

class A {
public:
	virtual unsigned int Sum(unsigned int n) {
		return 0;
	}
};

class B : public A {
public:
	virtual unsigned int Sum(unsigned int n) {
		return Array[!!n]->Sum(n - 1) + n;
	}
};

int Sum_Solution2(int n) {
	A a;
	B b;
	Array[0] = &a;
	Array[1] = &b;

	int value = Array[1]->Sum(n);

	return value;
}

// 利用函数指针求解
typedef unsigned int(*fun)(unsigned int n);

unsigned int Solution3_Teminator(unsigned int n) {
	return 0;
}

unsigned int Sum_Solution3(unsigned int n) {
	static fun f[2] = { Solution3_Teminator, Sum_Solution3 };
	return n + f[!!n](n - 1);
}

// 利用模板类型求解
template<unsigned int n> struct Sum_Solution4 {
	enum Value {N = Sum_Solution4<n-1>::N + n};
};

template<> struct Sum_Solution4<1> {
	enum Value { N = 1};
};