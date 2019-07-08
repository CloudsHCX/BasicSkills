/*
160. Intersection of Two Linked Lists
*/

//1.��ͳ��LA,LB�ĳ���
//2.������������ƫ��|LA-LB|�ľ��룬ΪcurNew
//3.�ٴα���curNew����һ������head������ͬʱ����Ϊ���
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};
class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		if (!headA || !headB)
			return nullptr;

		//����LA��LB����
		ListNode* curA = headA, *curB = headB;
		int lenA = 1, lenB = 1;
		while (curA->next)
		{
			++lenA;
			curA = curA->next;
		}
		while (curB->next)
		{
			++lenB;
			curB = curB->next;
		}

		//���һ���ڵ㲻ͬ�����ཻ
		if (curA != curB)
			return nullptr;

		//ƫ�ƽϳ�������
		curA = headA;
		curB = headB;
		if (lenA < lenB)
		{
			int offset = lenB - lenA;
			while ((offset--) > 0)
				curB = curB->next;
		}
		else
		{
			int offset = lenA - lenB;
			while ((offset--) > 0)
				curA = curA->next;
		}

		//�ҵ����������
		while (curA && curB)
		{
			if (curA == curB)
				return curA;
			curA = curA->next;
			curB = curB->next;
		}

		return nullptr;
	}
};