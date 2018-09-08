/*
100. Same Tree

Given two binary trees, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical and the nodes have the same value.

Example 1:

Input:     1         1
          / \       / \
         2   3     2   3

        [1,2,3],   [1,2,3]

Output: true
Example 2:

Input:     1         1
          /           \
         2             2

        [1,2],     [1,null,2]

Output: false
Example 3:

Input:     1         1
          / \       / \
         2   1     1   2

        [1,2,1],   [1,1,2]

Output: false

������������������дһ�����������������Ƿ���ͬ��

����������ڽṹ����ͬ�����ҽڵ������ͬ��ֵ������Ϊ��������ͬ�ġ�

*/
/*
��������ö��ַ�������:
	�����������������������������α�����
*/

#include <iostream>
#include <queue>
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
    bool isSameTree(TreeNode* p, TreeNode* q) {

		queue<TreeNode* > queueP,queueQ;
		queueP.push(p),queueQ.push(q);

		TreeNode* cur1;
		TreeNode* cur2;

		while(!queueP.empty() && !queueQ.empty())
		{
			cur1 = queueP.front();
			cur2 = queueQ.front();

			queueP.pop(),queueQ.pop();
			//������Ϊ�գ������
			if(!cur1 && !cur2)
				continue;
			//����һ��Ϊ�գ���һ����Ϊ�գ�������
			if(!cur1 || !cur2)
				return false;
			//���ֵ��ͬ��������
			if(cur1->val != cur2->val)
				return false;

			queueP.push(cur1->left);
			queueP.push(cur1->right);
			queueQ.push(cur2->left);
			queueQ.push(cur2->right);
		}
		return true;
    }
};