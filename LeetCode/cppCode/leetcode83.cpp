/*
83. Remove Duplicates from Sorted List
*/
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (!head)
		{
			return head;
		}

		ListNode* cur, *next, *n_next;
		cur = head;
		while (cur)
		{
			next = cur->next;
			//ȥ��
			while (next && cur->val == next->val)
			{
				n_next = next->next;
				delete next;
				next = n_next;
			}
			//ȥ�ع����жϿ���������Ҫ��������
			cur->next = next;
			cur = cur->next;
		}
		return head;
	}
};