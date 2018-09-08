/*
98. Validate Binary Search Tree

Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
Example 1:

Input:
    2
   / \
  1   3
Output: true
����һ�����������ж����Ƿ���һ����Ч�Ķ�����������

����һ��������������������������

�ڵ��������ֻ����С�ڵ�ǰ�ڵ������
�ڵ��������ֻ�������ڵ�ǰ�ڵ������
�������������������������Ҳ�Ƕ�����������
*/

/*
�����������������������õ�һ���������У�������vector�С�
	  �ٶ�vector�����жϣ�������ǵ��������ʾ����BST��
	  ��Ȼ���ַ���ʱ�临�Ӷȡ��ռ临�Ӷȶ��Ƚϴ�
*/
#include <vector>
#include <stack>
using namespace std;

 // Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    bool isValidBST(TreeNode* root) {
		
		if(!root)
			return true;

		vector<int> res;
		stack<TreeNode* > st;
		TreeNode* cur = root;

		while(cur != nullptr || !st.empty())
		{
			//�ҵ���������Ҷ�ӽ��
			while(cur != nullptr)
			{
				st.push(cur);
				cur = cur->left;
			}

			//�ָ�����һ��㣬��ֵ��������������
			cur = st.top();
			st.pop();
			res.push_back(cur->val);
			cur = cur->right;
		}

		for(int i=0; i<res.size()-1; ++i)
		{
			if(res[i] >= res[i+1])
				return false;
		}
		return true;
    }
};