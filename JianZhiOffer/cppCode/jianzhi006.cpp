/*
006 �ؽ�������

����ĳ��������ǰ���������������Ľ�������ؽ����ö�������
���������ǰ���������������Ľ���ж������ظ������֡�
��������ǰ���������{1,2,4,7,3,5,6,8}�������������{4,7,2,1,5,3,8,6}��
���ؽ������������ء�
*/
/*
������ǰ���������{1,2,4,7,3,5,6,8} pre[]
	  �����������{4,7,2,1,5,3,8,6} vin[]
	  ������Բ��÷��η�����pre�е�leftΪ���������ĸ��ڵ㣬��1Ϊ�������������зֳ���������������
		  �ٲ������������������У�����pre{2,4,7}��{3,5,6,8}��vin{4,7,2}��{5,3,8,6}��
		  �ݹ���ݹ���������
	
*/
#include <iostream>
#include <vector>
using namespace std;

 // Definition for binary tree
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
public:
	TreeNode* constructBinaryTree(vector<int> &pre,vector<int> &vin,int lp, int rp, int lv, int rv)
	{
		if(lv > rv || lp > rp)
			return nullptr;
		TreeNode* node = new TreeNode(pre[lp]);
		int i;
		for(i=lv; i<=rv; i++)
			if(pre[lp] == vin[i])
				break;

		node->left = constructBinaryTree(pre, vin, lp+1, lp+i-lv, lv, i-1);
		node->right = constructBinaryTree(pre, vin, lp+i-lv+1, rp, i+1, rv);
		return node;
	}
 
	TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
		if(pre.empty())
			return nullptr;
		return constructBinaryTree(pre, vin, 0, pre.size()-1, 0, vin.size()-1);
    }
};	