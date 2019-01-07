/*
028 ������������˫������

��Ŀ����
����һ�ö��������������ö���������ת����һ�������˫������
Ҫ���ܴ����κ��µĽ�㣬ֻ�ܵ������н��ָ���ָ��
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
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
		if (pRootOfTree == NULL)
			return NULL;

		TreeNode* recRoot = ConvertRec(pRootOfTree);

		return getLeftNode(recRoot);
    }

	//�ݹ��������������������˫���������ظ��ڵ�
	TreeNode* ConvertRec(TreeNode* pRootOfTree)
	{
		//�ݹ��˳�����
		if (pRootOfTree == NULL)
			return NULL;

		TreeNode* tmpRoot, *tmpNode;
		//�ݹ�������
		if (pRootOfTree->left != nullptr)
		{
			tmpRoot = ConvertRec(pRootOfTree->left);
			//�������������ڵ������Ϊ����˫����������ҽڵ�
			tmpNode = getRightNode(tmpRoot);
			pRootOfTree->left = tmpNode;
			tmpNode->right = pRootOfTree;
		}

		//�ݹ�������
		if (pRootOfTree->right != nullptr)
		{
			tmpRoot = ConvertRec(pRootOfTree->right);
			//�������������ڵ���Һ���Ϊ����˫�����������ڵ�
			tmpNode = getLeftNode(tmpRoot);
			pRootOfTree->right = tmpNode;
			tmpNode->left = pRootOfTree;
		}

		return pRootOfTree;
	}

private:
	TreeNode* getLeftNode(TreeNode* root)
	{
		while (root != NULL && root->left != NULL)
			root = root->left;

		return root;
	}

	TreeNode* getRightNode(TreeNode* root)
	{
		while (root != NULL && root->right != NULL)
			root = root->right;

		return root;
	}
};