/*******************************************************************
*����ָOffer�����������Թپ������ͱ���⡷C++����
*
* htfeng
* 2018.11.13
*
* ������62: ԲȦ�����ʣ�µ�����
* ��Ŀ��0��1��...,n-1��n�������ų�һ��ԲȦ��������0��ʼ��ÿ�δ����ԲȦ
* ��ɾ����m�����֣������ԲȦ��ʣ�µ����һ������
*
* ���������û���������һ����������ɾ������ڵ�
********************************************************************/
#include<list>

using namespace std;

class Solution {
public:
	int LastRemaining(unsigned int n, unsigned int m) {
		if (n < 1 || m < 1)
			return -1;

		unsigned int i = 0;
		
		list<int> numbers;
		for (i = 0; i < n; ++i)
			numbers.push_back(i);

		list<int>::iterator current = numbers.begin();

		while (numbers.size() > 1) {
			for (int i = 1; i < m; ++i) {
				current++;
				if (current == numbers.end())
					current = numbers.begin();
			}

			list<int>::iterator next = ++current;
			if (next == numbers.end())
				next == numbers.begin();

			--current;
			numbers.erase(current);
			current = next;
		}

		return *(current);
	}
};