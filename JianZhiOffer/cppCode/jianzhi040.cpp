/*
040 �����������

��Ŀ����
����һ�ö����������������ȡ��Ӹ���㵽Ҷ������ξ����Ľ�㣨������Ҷ��㣩
�γ�����һ��·�����·���ĳ���Ϊ������ȡ�
*/

/*
���������õݹ飬�������= max����������ȣ���������ȣ� + 1���ݹ�����ǿսڵ㣬��ʱ���Ϊ0��
*/
#include <iostream>
#include <vector>
#include <algorithm>
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
    int TreeDepth(TreeNode* pRoot)
    {
		if(!pRoot)
			return 0;

		return max(TreeDepth(pRoot->left), TreeDepth(pRoot->right)) + 1;
    }
};