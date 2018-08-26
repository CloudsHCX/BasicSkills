/*
61. Rotate List

Given a linked list, rotate the list to the right by k places, where k is non-negative.

Example 1:

Input: 1->2->3->4->5->NULL, k = 2
Output: 4->5->1->2->3->NULL
Explanation:
rotate 1 steps to the right: 5->1->2->3->4->NULL
rotate 2 steps to the right: 4->5->1->2->3->NULL
Example 2:

Input: 0->1->2->NULL, k = 4
Output: 2->0->1->NULL
Explanation:
rotate 1 steps to the right: 2->0->1->NULL
rotate 2 steps to the right: 1->2->0->NULL
rotate 3 steps to the right: 0->1->2->NULL
rotate 4 steps to the right: 2->0->1->NULL

����һ��������ת����������ÿ���ڵ������ƶ� k ��λ�ã����� k �ǷǸ�����

ʾ�� 1:

����: 1->2->3->4->5->NULL, k = 2
���: 4->5->1->2->3->NULL
����:
������ת 1 ��: 5->1->2->3->4->NULL
������ת 2 ��: 4->5->1->2->3->NULL
ʾ�� 2:

����: 0->1->2->NULL, k = 4
���: 2->0->1->NULL
����:
������ת 1 ��: 2->0->1->NULL
������ת 2 ��: 1->2->0->NULL
������ת 3 ��: 0->1->2->NULL
������ת 4 ��: 2->0->1->NULL
*/

/*
������k��k<����ĳ��ȣ�roate�����ӵ�����k����㿪ʼΪͷ��㣬�γɵ�ѭ������
	 �����ҵ�������k����㣬�Լ�ȡ��k % len��Ϊ����һȦ�Ľ�㡣
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
    ListNode* rotateRight(ListNode* head, int k) {
		//���ַ������⴦��
		if(!head)
			return nullptr;
		//�������ȣ���ֹk���󣬳���rotateһȦ�ĳ��ȡ�
        int len = 1;
		for(ListNode* tmp = head; tmp->next != nullptr; tmp = tmp->next)
			len++;
		int rotate = k % len;
		
		ListNode* retHead;
		ListNode* fir;
		ListNode* sec;
		fir = sec = head;

		//�ҵ�������rotateѭ����
		for(int i=0; i<rotate; ++i)
			sec = sec->next;

		while(sec->next)
		{
			fir = fir->next;
			sec = sec->next;
		}
		sec->next = head;
		retHead = fir->next;
		fir->next = nullptr;
			
		return retHead;
    }
};