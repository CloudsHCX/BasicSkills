/*
94. Binary Tree Inorder Traversal

Given a binary tree, return the inorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,3,2]

����һ���������������������� ������

ʾ��:

����: [1,null,2,3]
   1
    \
     2
    /
   3

���: [1,3,2]
����: �ݹ��㷨�ܼ򵥣������ͨ�������㷨�����
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*
����������������������������������ܵݹ顣
	�ݹ�ı��ʾ����ö�ջ��ʵ�ֵģ�ͨ����ջ��������һ�ε�״̬��
	�������ǿ���ʹ��һ����ջ���洢��㣬�����Ϊ��ʱ��������һ�εĽ�㣬�洢ֵ���ټ���������������
	ѭ���������Ϳ���������������
*/
#include <vector>
#include <stack>
using namespace std;

class Solution {

	struct TreeNode {
		int val;
		TreeNode *left;
		TreeNode *right;
		TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	};
	
public:
    vector<int> inorderTraversal(TreeNode* root) {
		
		vector<int> res;
		//�����ж�
		if(!root)
			return res;

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
		return res;
    }
};