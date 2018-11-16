/*******************************************************************
*����ָOffer�����������Թپ������ͱ���⡷C++����
*
* htfeng
* 2018.10.08
*
* ������55: �����������
* ��Ŀһ�������������
* ��Ŀ���� ƽ�������
*
* ����: �����������ʹ�õݹ飬������ʵ��;Ҫ�ж�ƽ���������ʹ�õݹ��
* ����������������ÿ���ڵ�Ȼ���ж��Ƿ���ƽ��������ܼ򵥣����ǻ��ظ�����
* �ܶ�ڵ㣬
********************************************************************/
struct BinaryTreeNode {
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

class Solution {
public:
	// ��Ŀһ�������������
	int TreeDepth(BinaryTreeNode* pRoot) {
		if (pRoot == nullptr)
			return 0;

		int nLeft = TreeDepth(pRoot->m_pLeft);
		int nRight = TreeDepth(pRoot->m_pRight);

		return (nLeft > nRight) ? (nLeft + 1) : (nRight + 1);
	}
	// ��Ŀ���� ƽ�������

	bool IsBalanced(BinaryTreeNode* pRoot, int* pDepth) {
		if (pRoot == nullptr) {
			*pDepth = 0;
			return true;
		}

		int left, right;

		if (IsBalanced(pRoot->m_pLeft, &left) && IsBalanced(pRoot->m_pRight, &right)) {
			int diff = left - right;
			if (diff <= 1 && diff >= -1) {
				*pDepth = 1 + (left > right ? left : right);
				return true;
			}
		}
		return false;
	}

	bool IsBalanced(BinaryTreeNode* pRoot) {
		int depth = 0;
		return IsBalanced(pRoot, &depth);
	}
};