/*
86. Partition List

Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

Example:

Input: head = 1->4->3->2->5->2, x = 3
Output: 1->2->2->4->3->5
*/

/*
������ ��������������һ������С��x�����нڵ㣬�ڶ���������ڵ���x�����н��
	   ����ٺϲ���һ���ڵ㼴�ɡ�
*/

#include <iostream> 
using namespace std;

//Definition for singly-linked list.
 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

 class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
		ListNode* tmp = new ListNode(0);
		tmp->next = head;
		ListNode* part1End = new ListNode(0);
		ListNode* part2End = new ListNode(0);
		ListNode* part1Head = part1End;
		ListNode* part2Head = part2End;
		while(tmp->next)
		{
			//С��x�Ĺ���һ������
           if(tmp->next->val < x)
			{
				part1End->next = tmp->next;
				tmp->next = tmp->next->next;
				part1End->next->next = nullptr;
				part1End = part1End->next;
			}
		   //���ڵ���x�Ĺ���һ������
			else
			{
				part2End->next = tmp->next;
				tmp->next = tmp->next->next;
				part2End->next->next = nullptr;
				part2End = part2End->next;

			}
		}
		//����1�������ָ������2��ͷ���
		part1End->next = part2Head->next;
		return part1Head->next;
    }
};