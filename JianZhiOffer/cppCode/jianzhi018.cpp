/*
018 �ϲ��������������
��Ŀ����

���������������������������������ϳɺ��������Ȼ������Ҫ�ϳɺ���������㵥����������
*/

/*
������list1��list2���ù鲢���㷨��list1�ĵ�ǰ���<list2�ĵ�ǰ��㣬��list1�ĵ�ǰ����ƶ���
	  ��������֮�ƶ�list2��ֱ��ĳ������Ϊ�գ��ٲ�����һ�������ʣ���㡣

*/

#include <iostream>
#include <vector>
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
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
		ListNode* fakeNode = new ListNode(0);
		ListNode* cur = fakeNode;
		while(pHead1 != nullptr && pHead2 != nullptr)
		{
			if(pHead1->val < pHead2->val)
			{
				cur->next = pHead1;
				cur = pHead1;
				pHead1 = pHead1->next;
			}
			else
			{
				cur->next = pHead2;
				cur = pHead2;
				pHead2 = pHead2->next;
			}
		}
		if(pHead1)
			cur->next = pHead1;
		if(pHead2)
			cur->next = pHead2;
		return fakeNode->next;
    }
};