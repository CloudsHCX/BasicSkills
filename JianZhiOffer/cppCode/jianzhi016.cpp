/*
016 �����е�����k�����
��Ŀ����

����һ����������������е�����k����㡣
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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		
		ListNode* fast = pListHead;
		ListNode* slow = pListHead;

		while(k != 0)
		{
			if(fast == nullptr) return nullptr;
			fast = fast->next;
			k--;
		}

		while(fast != nullptr)
		{
			fast = fast->next;
			slow = slow->next;
		}
		return slow;
    }
};