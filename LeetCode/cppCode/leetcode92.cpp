/*
92. Reverse Linked List II
*/
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		//����Ϊ�գ���m >= nʱ������ԭʼ����
		if (!head || m >= n)
		{
			return head;
		}

		ListNode* fake_head = new ListNode(0);
		fake_head->next = head;
		ListNode* cur = fake_head, *next, *pre = nullptr;
	
		//pre_start_posָ���m-1�ڵ㣬start_posָ���m�ڵ�,end_pos,ָ���n�ڵ�
		ListNode* pre_start_pos, *start_pos, *end_pos;
		for (int i = 0; i < m - 1; i++)
		{
			cur = cur->next;
		}

		pre_start_pos = cur;
		start_pos = cur->next;
		cur = start_pos;

		//����m��n֮��Ľڵ�,�˳�ѭ��ʱ��curָ��n+1
		int count = n - m + 1;
		for (int i = 0; i < count; i++)
		{
			next = cur->next;
			cur->next = pre;
			pre = cur;
			cur = next;
		}
		end_pos = pre;

		//������װ����
		pre_start_pos->next = end_pos;
		start_pos->next = cur;

		return fake_head->next;
	}
};