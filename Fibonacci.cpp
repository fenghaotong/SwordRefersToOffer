/*******************************************************************
*����ָOffer�����������Թپ������ͱ���⡷C++����
*
* htfeng
* 2018.09.21
*
* ������10��쳲���������
* ��Ŀһ����쳲��������еĵ�n��
*******************************************************************/

#include<iostream>
#include<ctime>

using namespace std;

// �ݹ�
long long Fibonacci_Recursive(unsigned int n) {
	if (n <= 0)
		return 0;
	if (n == 1)
		return 1;

	return Fibonacci_Recursive(n - 1) + Fibonacci(n - 2);
}

// �ǵݹ�
long long Fibonacci(unsigned int n) {
	int result[2] = { 0,1 };
	if (n < 2)
		return result[n];

	long long fibNMinusOne = 1;
	long long fibNMinusTwo = 0;
	long long fibN = 0;
	for (unsigned int i = 2; i < n; i++) {
		fibN = fibNMinusOne + fibNMinusTwo;
		fibNMinusTwo = fibNMinusOne;
		fibNMinusOne = fibN;
	}

	return fibN;
}
int main() {
	// �ݹ�����ʱ��
	time_t start_t, end_t;
	time(&start_t);
	Fibonacci_Recursive(40);
	time(&end_t);
	cout << start_t << endl;
	cout << end_t << endl;
	cout << difftime(end_t, start_t) << endl;
	// �ǵݹ�����ʱ��
	time(&start_t);
	Fibonacci(40);
	time(&end_t);
	cout << start_t << endl;
	cout << end_t << endl;
	cout << difftime(end_t, start_t) << endl;
	system("pause");
	return 0;
}