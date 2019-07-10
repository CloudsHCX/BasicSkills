/*
234. Palindrome Linked List
*/
//��Ϊ������������ǰ������Ȼ��һһ�ж��Ƿ���ȼ��ɡ�

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
	bool isPalindrome(ListNode* head) {
		//��������0,1�����ж�
		if (!head || !head->next)
			return true;
		//��������2�����ж�
		if (!head->next->next)
			return head->val == head->next->val ? true : false;

		//�������Ϊ�����֣�ʹ�ÿ���ָ��
		ListNode* slow = head, *fast = head;
		while (fast->next && fast->next->next)
		{
			slow = slow->next;
			fast = fast->next->next;
		}

		//��ǰ�벿�������ã����������ڵ�����
		ListNode *curL1, *curL2;
		curL2 = slow->next;
		slow->next = nullptr;
		curL1 = reverseList(head);
		//�����ڵ�
		if (!fast->next)
			curL1 = curL1->next;

		//�ж����������Ƿ��Ӧ��ͬ�������ж�
		while (curL1 && curL2)
		{
			if (curL1->val != curL2->val)
				return false;
			curL1 = curL1->next;
			curL2 = curL2->next;
		}
		return true;
	}

	//head������ͷ�ڵ�
	//����ֵ�����������ͷ�ڵ�
	ListNode* reverseList(ListNode* head)
	{
		if (!head)
			return nullptr;

		ListNode* cur = head, *next;
		ListNode* fakeHead = new ListNode(-1);
		//��������
		while (cur)
		{
			next = cur->next;
			cur->next = fakeHead->next;
			fakeHead->next = cur;
			cur = next;
		}
		cur = fakeHead->next;
		delete fakeHead;
		return cur;
	}
};
