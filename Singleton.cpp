/*******************************************************************
Copyright(c) 2017, htfeng
All rights reserved.
*******************************************************************/

//==================================================================
// 《剑指Offer——名企面试官精讲典型编程题》代码
//  作者：何海涛
//  C++
//==================================================================

// 面试题2：实现Singleton模式
// 题目：设计一个类，我们只能生成该类的一个实例

//注意到实现中m_pInstance和GetInstance都是静态的，所以没有创建对象就已经存在了。通过调用GetInstance来创建或者获取唯一的对象
#include<iostream>

using namespace std;

template<class T>
class CSingleton {
private:
	CSingleton() {}                    //1.构造函数是私有的，不能通过构造函数创建该类的实例
	static CSingleton<T> *m_pIstance;     //2.静态成员变量，且是私有的，指向一个CSingleton实例，同一时间只存在一个这个变量，所以只能存在一个CSingleton的实例
public:
	static CSingleton<T> *GetInstace() {  //3.只能通过这个函数来创建并获得一个CSingleton实例，且这个实例是唯一的（因为没有其他途径创建CSingleton实例，构造函数是私有的）
		if (m_pIstance == NULL) {
			m_pIstance = new CSingleton<T>;
		}

		return m_pIstance;
	}
};

template<class T>
CSingleton<T> *CSingleton<T>::m_pIstance = NULL:   //4.初始化类的静态成员变量  