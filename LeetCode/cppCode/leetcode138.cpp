/*
138. Copy List with Random Pointer
*/
#include <unordered_map>
using namespace std;


// Definition for a Node.
class Node {
public:
	int val;
	Node* next;
	Node* random;

	Node() {}

	Node(int _val, Node* _next, Node* _random) {
		val = _val;
		next = _next;
		random = _random;
	}
};

class Solution {
public:
	Node* copyRandomList(Node* head) {
		if (!head)
		{
			return nullptr;
		}
		unordered_map<int, Node*> hash;

		Node* original_cur, *new_cur, *tmp;
		Node* new_fake_head = new Node(0, nullptr, nullptr);
		new_cur = new_fake_head;
		original_cur = head;

		//����next����
		while (original_cur)
		{
			tmp = new Node(original_cur->val, nullptr, nullptr);
			new_cur->next = tmp;
			//�浽hash����
			hash[tmp->val] = tmp;
			new_cur = new_cur->next;
			original_cur = original_cur->next;
		}

		//copy randomָ��
		original_cur = head;
		while (original_cur)
		{
			if (original_cur->random)
			{
				hash[original_cur->val]->random = hash[original_cur->random->val];
			}
			original_cur = original_cur->next;
		}

		return new_fake_head->next;
	}
};
