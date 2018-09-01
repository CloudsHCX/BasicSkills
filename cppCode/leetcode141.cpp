/*
141. Linked List Cycle

Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?
*/
/*
�������������ʹ���ܲ���˼��ȥ���⡣һ��ָ��죬ÿ�β���Ϊ2����һ��ָ������ÿ�β���Ϊ1��
      �����׷������ָ�룬��ʾ�л�����������null����ʾ�޻���
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
    bool hasCycle(ListNode *head) {
   
		ListNode* slow = head;
		ListNode* quick = head;
		while(quick)
		{
			if(quick->next == nullptr || quick->next->next == nullptr)
				return false;
            slow = slow->next;
			quick = quick->next->next;
			//�л�
			if(quick == slow)
				return true;
		}
		return false;
    }
};