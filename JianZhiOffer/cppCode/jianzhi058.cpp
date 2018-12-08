/*
058 ɾ���������ظ��Ľ��

��Ŀ����
��һ������������У������ظ��Ľ�㣬��ɾ�����������ظ��Ľ�㣬�ظ��Ľ�㲻��������������ͷָ�롣
���磬����1->2->3->3->4->4->5 �����Ϊ 1->2->5
*/

#include<iostream>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :val(x), next(NULL) {
	}
};
class Solution {
public:
	ListNode* deleteDuplication(ListNode* pHead)
	{
		ListNode* first = new ListNode(-1);
		first->next = pHead;
		ListNode* last, *cur, *tmp_Node;
		last = cur = first;
		int tmp_val;
		while (cur && cur->next)
		{
			//�����ظ�
			if (cur->val == cur->next->val)
			{
				tmp_val = cur->val;//�ݴ�ֵ
				while (cur && cur->val == tmp_val)
				{
					tmp_Node = cur;
					cur = cur->next;
					delete(tmp_Node);//ɾ���ظ�ֵ
				}
				last->next = cur;//�����ظ�ֵ����
			}
			else
			{
				last = cur;
				cur = cur->next;
			}
		}
		return first->next;
	}
};