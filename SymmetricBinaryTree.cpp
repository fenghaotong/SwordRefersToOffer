/*******************************************************************
*����ָOffer�����������Թپ������ͱ���⡷C++����
*
* htfeng
* 2018.10.05
*
* ������27: �ԳƵĶ�����
* ��Ŀ��ʵ��һ�������������ж�һ�Ŷ������ǲ��ǶԳƵ�
*
* ����: ǰ��������ȱ�����������ʵ��һ����ʵ�����������㷨�����
* ���ǵ�ǰ�������ͬ��Գ�
*******************************************************************/
struct BinaryTreeNode {
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

class Solution {
public:
	bool isSymmetrical(BinaryTreeNode* pRoot) {
		return isSymmetrical(pRoot, pRoot);
	}

	bool isSymmetrical(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2) {
		if (pRoot1 == nullptr && pRoot2 == nullptr)
			return true;

		if (pRoot1 == nullptr || pRoot2 == nullptr)
			return false;

		if (pRoot1->m_nValue != pRoot2->m_nValue)
			return false;

		return isSymmetrical(pRoot1->m_pLeft, pRoot2->m_pRight) && 
			isSymmetrical(pRoot1->m_pRight, pRoot2->m_pLeft);
	}
};