/*
019 �����ӽṹ

��Ŀ����
�������ö�����A��B���ж�B�ǲ���A���ӽṹ����ps������Լ��������������һ�������ӽṹ��
*/

/*
������ 1.��Ҫ׼��һ���ж����ӽṹ�Ƿ���ڵĺ������ս�����ӽṹ������true���������ǿ�����
		��Ҫ����false��ѭ���ж�pRoot1��,pRoot2�����������ֵ�Ƿ���ͬ����ͬ����false����֮
		����true��
	   2.ʹ�õݹ鷽�����ҵ����ڵ���ͬ��������1�ĺ�������Ϊtrue����ʾB��A�Ľṹ
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
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
		if(!pRoot1 || !pRoot2)
			return false;

		bool res;
		if(pRoot1->val == pRoot2->val)
			res = judgeSubtree(pRoot1, pRoot2);
		if(res == true)
			return true;
		else
			return HasSubtree(pRoot1->left,pRoot2) || 
				HasSubtree(pRoot1->right,pRoot2);
    }

	//�ж��ӽṹ�Ƿ���ͬ
	bool judgeSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		if(pRoot2 == nullptr)
			return true;
		else if(pRoot1 == nullptr)
			return false;

		if(pRoot1->val == pRoot2->val)
		{
			return(judgeSubtree(pRoot1->left, pRoot2->left) && 
				judgeSubtree(pRoot1->right, pRoot2->right));
		}
		else
			return false;
	}
};