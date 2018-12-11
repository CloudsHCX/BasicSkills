/*
064 �����������ĵ�k�����

��Ŀ����
����һ�ö��������������ҳ����еĵ�kС�Ľ�㡣���磬 ��5��3��7��2��4��6��8��    
�У��������ֵ��С˳�����С����ֵΪ4��
*/

#include <iostream>
#include <vector>
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

private:
	int count = 0;

public:
	TreeNode* KthNode(TreeNode* pRoot, int k)
	{
		if (!pRoot)
		{
			return nullptr;
		}

		TreeNode *ret = nullptr;

		if ((ret = KthNode(pRoot->left, k)))
		{
			return ret;
		}
		++count;
		if (count == k)
		{
			return pRoot;
		}

		if ((ret = KthNode(pRoot->right, k)))
		{
			return ret;
		}
		return nullptr;
	}

};