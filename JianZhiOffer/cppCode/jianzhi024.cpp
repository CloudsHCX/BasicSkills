/*
024 �������´�ӡ������

��Ŀ����
�������´�ӡ����������ÿ���ڵ㣬ͬ��ڵ�������Ҵ�ӡ��
*/

/*
���������Ĳ�α�����ͨ��һ�����������ƽ�㡣
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
		vector<int> res;

		if(!root)
			return res;

		queue<TreeNode*> qNode;
		qNode.push(root);
		TreeNode* cur;
		//��α���
		while(!qNode.empty())
		{
			cur = qNode.front();
			qNode.pop();
			res.push_back(cur->val);
			if(cur->left)
				qNode.push(cur->left);
			if(cur->right)
				qNode.push(cur->right);
		}
		return res;

    }
};