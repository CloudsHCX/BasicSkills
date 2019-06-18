/*
23. Merge k Sorted Lists    
*/
/*
���÷��η���˼�룬�ϲ�K���������ƹ鲢������������ϲ���
ʱ�临�Ӷ�ΪO(n)�����ϵݹ��ʱ�临�Ӷ�O(logk)���ܵ�ʱ�临�Ӷ�Ϊ
O(nlogk)������kΪ���������nΪ�ڵ�������ռ临�Ӷ�Ϊ0(1)
*/

#include <vector>
using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(nullptr) {}
  };
 
class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		if (lists.size() < 1)
		{
			return nullptr;
		}
		return __mergeKLists(lists, 0, lists.size() - 1);
	}

	//�ϲ���������
	ListNode* __mergeTwoLists(ListNode* fir, ListNode* sec)
	{
		//�Կ�����Ĵ���
		if (!fir)
		{
			return sec;
		}
		if (!sec)
		{
			return fir;
		}

		ListNode* fake_head = new ListNode(0);
		ListNode* cur = fake_head;
		//�����������Ϊ�գ��ϲ�
		while (fir && sec)
		{
			if (fir->val <= sec->val)
			{
				cur->next = fir;
				fir = fir->next;
			}
			else
			{
				cur->next = sec;
				sec = sec->next;
			}
			cur = cur->next;
		}

		//���п���ı�ϲ���
		if (fir)
		{
			cur->next = fir;
		}
		if (sec)
		{
			cur->next = sec;
		}

		return fake_head->next;
	}

	//���÷��η����ݹ�ϲ�lists
	ListNode* __mergeKLists(vector<ListNode*>& lists, int left, int right)
	{
		if (left > right)
		{
			return nullptr;
		}
		else if (left == right)
		{
			return lists[left];
		}

		int mid = left + ((right - left) >> 1);

		return __mergeTwoLists(__mergeKLists(lists, left, mid),
				__mergeKLists(lists, mid+1, right));
	}
};