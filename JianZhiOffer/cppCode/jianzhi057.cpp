/*
057 �����л�����ڽ��

��Ŀ����
��һ�����������а����������ҳ�������Ļ�����ڽ�㣬�������null��
*/

#include <iostream>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};

class Solution {
public:
	ListNode* EntryNodeOfLoop(ListNode* pHead)
	{
		ListNode* slow, *fast;
		
		slow = fast = pHead;
		//��ָ����������Ϊ��
		while (fast->next && fast->next->next)
		{
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast)
			{
				//��ʾ�л�
				break;
			}
		}

		//�޻�
		if (!fast->next || !fast->next->next)
		{
			return nullptr;
		}

		//�󻷳���
		int lenCir = 0;
		do
		{
			slow = slow->next;
			lenCir++;
		} while (fast != slow);

		//fast-slowΪ����������������ʱ����Ϊ����ڵ㡣
		slow = fast = pHead;
		for (int i = 0; i < lenCir; i++)
			fast = fast->next;
		while (slow != fast)
		{
			slow = slow->next;
			fast = fast->next;
		}
		return slow;
	}
};