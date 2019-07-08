/*
148. Sort List
*/

//���ù鲢�㷨������
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
 
class Solution {
public:
	ListNode* sortList(ListNode* head) {
		return __merge_sort(head);
	}

	//�鲢����
	ListNode* __merge_sort(ListNode* head)
	{
		if (head == nullptr || head->next == nullptr)
		{
			return head;
		}

		ListNode* slow = head, *fast = head;
		while (fast && fast->next && fast->next->next)
		{
			slow = slow->next;
			fast = fast->next->next;
		}

		//�ݹ�������������
		ListNode* l2 = __merge_sort(slow->next);
		slow->next = nullptr;
		ListNode* l1 = __merge_sort(head);
		//�鲢����
		return merge(l1, l2);
	}

	//�ϲ�������������ͷ�ڵ�
	ListNode* merge(ListNode* l1, ListNode* l2)
	{
		ListNode* fakeHead = new ListNode(0);
		ListNode* cur = fakeHead;

		while (l1 && l2)
		{
			if (l1->val < l2->val)
			{
				cur->next = l1;
				l1 = l1->next;
			}
			else
			{
				cur->next = l2;
				l2 = l2->next;
			}
			cur = cur->next;
		}

		//��ʣ��Ĳ��ֺϲ�
		if (l1)
		{
			cur->next = l1;
		}
		if (l2)
		{
			cur->next = l2;
		}

		cur = fakeHead->next;
		delete fakeHead;
		return cur;
	}
};