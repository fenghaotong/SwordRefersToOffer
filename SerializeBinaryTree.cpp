/*******************************************************************
*����ָOffer�����������Թپ������ͱ���⡷C++����
*
* htfeng
* 2018.10.11
*
* ������37: ���л�������
* ��Ŀ��ʵ�������������ֱ��������л��ͷ����л�������
*******************************************************************/
#include <iostream>
#include <fstream>

using namespace std;

struct BinaryTreeNode {
	int m_mValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

class Solution {
public:
	bool ReadStream(istream& stream, int* number){
		if (stream.eof())
			return false;

		char buffer[32];
		buffer[0] = '\0';

		char ch;
		stream >> ch;
		int i = 0;
		while (!stream.eof() && ch != ','){
			buffer[i++] = ch;
			stream >> ch;
		}

		bool isNumeric = false;
		if (i > 0 && buffer[0] != '$'){
			*number = atoi(buffer);
			isNumeric = true;
		}

		return isNumeric;
	}

	void Serialize(BinaryTreeNode* pRoot, ostream& stream) {
		if (pRoot == nullptr) {
			stream << "$,";
			return;
		}

		stream << pRoot->m_mValue << ',';
		Serialize(pRoot->m_pLeft, stream);
		Serialize(pRoot->m_pRight, stream);
	}

	void Deserialize(BinaryTreeNode** pRoot, istream& stream) {
		int number;
		if (ReadStream(stream, &number)) {
			*pRoot = new BinaryTreeNode();
			(*pRoot)->m_mValue = number;
			(*pRoot)->m_pLeft = nullptr;
			(*pRoot)->m_pRight = nullptr;

			Deserialize(&((*pRoot)->m_pLeft), stream);
			Deserialize(&((*pRoot)->m_pRight), stream);
		}
	}
};