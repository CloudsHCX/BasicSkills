/*
24. Swap Nodes in Pairs
*/
/*
���÷��ε�˼�룬ԭ�����ͷ��㣬��reverse֮����Ҫָ��(len-k)��ͷ�ڵ㣬
��ˣ����len��ֻ��Ҫ���len-k�������⣬�Դ����ƣ�ֱ��len<k��
ÿ����������ֻ��Ҫ����k���ڵ㼴�ɡ�����Ϊ2
*/

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
 
class Solution {
public:
	ListNode* swapPairs(ListNode* head) {

		int len = 0;
		ListNode* cur = head;
		while (cur)
		{
			cur = cur->next;
			++len;
		}
		return reverseKGroup(head, 2, len);

	}

	//���÷��η�����
	ListNode* reverseKGroup(ListNode* head, int k, int len)
	{
		//ʣ��Ϊ�գ����߽�㲻��
		if (!head || len < k)
		{
			return head;
		}

		ListNode* cur, *next, *pre = nullptr;
		ListNode* tail = head;//ԭʼͷ�ڵ�Ϊ�������β�ڵ�

		cur = head;
		int count = 0;
		while (count < k)
		{
			//���ýڵ�
			next = cur->next;
			cur->next = pre;
			pre = cur;
			cur = next;
			
			++count;
		}

		//���յ�curΪʣ�������ͷ�ڵ�
		tail->next = reverseKGroup(cur, k, len - k);
		//���յ�preΪ�������ͷ�ڵ�
		return pre;
	}
};