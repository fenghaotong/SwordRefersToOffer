/*******************************************************************
*����ָOffer�����������Թپ������ͱ���⡷C++����
*
* htfeng
* 2018.10.02
*
* ������22�������еĵ�����k���ڵ�
* ��Ŀ������һ����������������е�����k����㡣Ϊ�˷��ϴ�����˵�ϰ�ߣ�
* �����1��ʼ�������������β����ǵ�����1����㡣����һ��������6����㣬
* ��ͷ��㿪ʼ���ǵ�ֵ������1��2��3��4��5��6���������ĵ�����3�������
* ֵΪ4�Ľ�㡣
*******************************************************************/
struct ListNode {
	int m_nValue;
	ListNode* m_pNext;
};

class Solution {
public:
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		if (pListHead == nullptr || k == 0)
			return nullptr;

		ListNode *pAhead = pListHead;
		ListNode *pBehind = nullptr;

		for (unsigned int i = 0; i < k - 1; ++i) {
			if (pAhead->m_pNext != nullptr)
				pAhead = pAhead->m_pNext;
			else
				return nullptr;
		}
		pBehind = pListHead;
		while (pAhead->m_pNext != nullptr) {
			pAhead = pAhead->m_pNext;
			pBehind = pBehind->m_pNext;
		}

		return pBehind;
	}
};