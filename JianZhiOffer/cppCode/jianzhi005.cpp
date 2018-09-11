/*
��β��ͷ��ӡ����
��Ŀ����
����һ������������ֵ��β��ͷ��˳�򷵻�һ��ArrayList��
*/

/*
�������ÿռ任ʱ�䣬��֤ʱ�临�Ӷ�ΪO(n),��������ջ��ʵ�ֵ���
*/
#include <iostream>
#include <vector>
#include <stack>
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
    vector<int> printListFromTailToHead(ListNode* head) {
		if(!head) return vector<int> ();

		stack<int> tmp_stack;
		for(ListNode* cur = head; cur != nullptr; )
		{
			tmp_stack.push(cur->val);
            cur = cur->next;
		}
		//��̬���ٿռ�
		vector<int> res(tmp_stack.size());

		for(int i = 0;!tmp_stack.empty(); ++i)
		{
			res[i] = tmp_stack.top();
			tmp_stack.pop();
		}
		return res;
    }
};