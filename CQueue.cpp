/*******************************************************************
*����ָOffer�����������Թپ������ͱ���⡷C++����
*
* htfeng
* 2018.09.21
*
* ������9��������վʵ�ֶ���
* ��Ŀ��������ջʵ�ֶ��С����е��������£���ʵ��������������appendTail��deleteHead���ֱ���
* ����β������ڵ㣬�ڶ���ͷ��ɾ���ڵ㡣
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

//===================================���Դ���==========================

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