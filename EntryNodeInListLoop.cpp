/*******************************************************************
*����ָOffer�����������Թپ������ͱ���⡷C++����
*
* htfeng
* 2018.10.01
*
* ������23�������еĻ�����ڽڵ�
* һ�������а�����������ҳ�������ڽ�㣿���磬��ͼ3.8�������У�
* ������ڽ���ǽ��3��
*
* ������ ��ʹ������ָ�룬һ��һ������ָ��һ������������ָ��һ����һ��
* ������ָ��׷����ָ�����л���Ȼ�������ڵ㴦��ָ�룬������ǰ�ߣ�
* �ٻص�����ڵ�ʱ����¼�ߵĲ�������Ϊ���нڵ������
* Ȼ����������ָ��һ��ָ������n��(nΪ���нڵ����)����һ��ָ�뿪ʼ�ߣ�
* ����ָ������ʱ��Ϊ�������
*******************************************************************/
struct ListNode {
	int m_nValue;
	ListNode* m_pNext;
};

class Solution {
public:
	// �ж��Ƿ��л�
	ListNode* MeetingNode(ListNode* pHead) {
		if (pHead == nullptr)
			return nullptr;

		ListNode* pSlow = pHead->m_pNext;
		if (pSlow == nullptr)
			return nullptr;

		ListNode* pFast = pSlow->m_pNext;
		if (pFast != nullptr && pSlow != nullptr) {
			if (pFast == pSlow)
				return pFast;

			pSlow = pSlow->m_pNext;
			pFast = pFast->m_pNext;
			if (pFast != nullptr)
				pFast = pFast->m_pNext;
		}

		return nullptr;
	}

	ListNode* EntryNodeOfLoop(ListNode* pHead) {
		ListNode*  meetingNode = MeetingNode(pHead);
		if (meetingNode == nullptr)
			return nullptr;

		// ���нڵ����
		int nodesLoop = 1;
		ListNode* pNode1 = meetingNode;
		while (pNode1->m_pNext != meetingNode) {
			pNode1 = pNode1->m_pNext;
			++nodesLoop;
		}

		pNode1 = pHead;
		for (int i = 0; i < nodesLoop; i++)
			pNode1 = pNode1->m_pNext;

		ListNode* pNode2 = pHead;
		while (pNode1 != pNode2) {
			pNode1 = pNode1->m_pNext;
			pNode2 = pNode2->m_pNext;
		}

		return pNode1;
	}
};