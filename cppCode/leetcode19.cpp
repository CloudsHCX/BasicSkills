/*

19. Remove Nth Node From End of List

Given a linked list, remove the n-th node from the end of list and return its head.

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:

Given n will always be valid.

Follow up:

Could you do this in one pass?
����һ������ɾ������ĵ����� n ���ڵ㣬���ҷ��������ͷ��㡣

ʾ����

����һ������: 1->2->3->4->5, �� n = 2.

��ɾ���˵����ڶ����ڵ�������Ϊ 1->2->3->5.
˵����

������ n ��֤����Ч�ġ�

���ף�

���ܳ���ʹ��һ��ɨ��ʵ����
*/
/*
����������ͨ������ָ�룬��ʵ��һ�α�������������ָ��Ĳ���Ϊn��
	  ��sec��������ĩβ��fir�պõ��ﵹ����n���㣬ɾ����㼴�ɡ�
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
		ListNode* fir;
		ListNode* sec;
		//����ͷָ�룬����ָ���һ����㡣
		ListNode tmp(0);
		tmp.next = head;
		head = &tmp;
		fir = sec = head;

		for(int i=0; i<n; ++i)
			sec = sec->next;

		while(sec->next)
		{
			fir = fir->next;
			sec = sec->next;
		}

		//ɾ��������N�����
		fir->next = fir->next->next;
		return head;
    }
};