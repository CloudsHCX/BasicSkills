/*
017 ��ת����
��Ŀ����
����һ��������ת��������������ı�ͷ��
*/

/*
������curNode,nextNode������㣬ֻ��Ҫ��nextNode->next = curNode���������������ɡ� 
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
    ListNode* ReverseList(ListNode* pHead) {

		ListNode* fakeHead = new ListNode(0);
		ListNode* tmp;
		while(pHead)
		{
			tmp = pHead;
			pHead = pHead->next;
			tmp ->next = fakeHead->next; 
			fakeHead->next = tmp;
		}
		return fakeHead->next;

    }
};