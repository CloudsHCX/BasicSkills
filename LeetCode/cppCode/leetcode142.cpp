/*
142. Linked List Cycle II
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Note: Do not modify the linked list.

Follow up:
Can you solve it without using extra space?
*/

/*
�������������ʹ���ܲ���˼��ȥ���⡣һ��ָ��죬ÿ�β���Ϊ2����һ��ָ������ÿ�β���Ϊ1��
      �����׷������ָ�룬��ʾ�л�����������null����ʾ�޻�����ʱ����ָ����ͷ�պ����һȦ��
	  ���Ե���head��ʼ��ָ����slow��ָ�벽��Ϊ1���ٴ����ʱ��Ϊ��ڵ㡣
*/

#include <iostream>
using namespace std;


// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
		ListNode* slow = head;
		ListNode* quick = head;
		while(quick)
		{
			if(quick->next == nullptr || quick->next->next == nullptr)
				return nullptr;
            slow = slow->next;
			quick = quick->next->next;
			//�л�
			if(quick == slow)
			{
				//���뻷��
				ListNode* tmp = head;
				while(tmp != slow)
				{
					slow = slow->next;
					tmp = tmp->next;
				}
				return slow;
			}
		}
		return nullptr;
    }
};