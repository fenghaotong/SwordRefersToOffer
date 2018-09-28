/*******************************************************************
*《剑指Offer——名企面试官精讲典型编程题》C++代码
*
* htfeng
* 2018.09.21
*
* 面试题9：用两个站实现队列
* 题目：用两个栈实现队列。队列的声明如下，请实现他的两个函数appendTail和deleteHead，分别在
* 队列尾部插入节点，在队列头部删除节点。
*******************************************************************/

#include<iostream>
#include<stack>

using namespace std;

template<typename T>
class CQueue {
public:
	void appendTail(const T& node);
	T deleteHead();
private:
	stack<T> stack1;
	stack<T> stack2;
};


template<typename T>
void CQueue<T>::appendTail(const T& element) {
	stack1.push(element);
}

template<typename T>
T CQueue<T>::deleteHead() {
	// cout << stack2.size() << endl;
	if (stack2.size() <= 0) {
		while (stack1.size() > 0) {
			T& data = stack1.top();
			// cout << data << endl;
			stack1.pop();
			stack2.push(data);
		}
	}
	
	//cout << stack2.size() << endl;
	if (stack2.size() == 0)
		throw new exception("queue is empty");

	T head = stack2.top();
	stack2.pop();

	return head;
}

//===================================测试代码==========================

void Test() {
	CQueue<char> queue;

	queue.appendTail('a');
	queue.appendTail('b');
	queue.appendTail('c');

	char head = queue.deleteHead();
	cout << head << endl;

	head = queue.deleteHead();
	cout << head << endl;

	queue.appendTail('d');
	head = queue.deleteHead();
	cout << head << endl;

	head = queue.deleteHead();
	cout << head << endl;
}

int main() {
	Test();
	system("pause");
	return 0;
}