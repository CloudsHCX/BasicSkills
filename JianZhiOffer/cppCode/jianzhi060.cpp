/*
060 �ԳƵĶ�����

��Ŀ����
��ʵ��һ�������������ж�һ�Ŷ������ǲ��ǶԳƵġ�ע�⣬���һ��������ͬ�˶������ľ�����ͬ���ģ�
������Ϊ�ԳƵġ�
*/

#include <iostream>
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
	bool isSymmetrical(TreeNode* pRoot)
	{
		if (!pRoot)//��Ϊ����������tree
		{
			return true;
		}
		return isSymmetricalRec(pRoot->left, pRoot->right);
	}

	bool isSymmetricalRec(TreeNode* pLeft, TreeNode* pRight)
	{
		if (!pLeft && !pRight) //���ҶԳƽ�㶼Ϊ�գ��򷵻�true
		{
			return true;
		}
		
		if (!pLeft || !pRight) //���ҶԳ���һ�����Ϊ�գ��򷵻�false
		{
			return false;
		}

		if (pLeft->val != pRight->val)
		{
			return false;
		}

		//  ������ȡֵ
		return (isSymmetricalRec(pLeft->left, pRight->right)
			&& isSymmetricalRec(pLeft->right, pRight->left));
	}

};