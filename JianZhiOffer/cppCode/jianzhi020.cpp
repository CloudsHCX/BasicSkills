/*
020 �������ľ���
	
��Ŀ����
���������Ķ�����������任ΪԴ�������ľ���
*/

/*
����������ʹ�õݹ飬�ǵݹ��ǰ���С�����ʹ��ǰ���ʱ��ֻ��Ҫÿһ�㽻�����ҽ�㼴�ɡ�
		������Ҫ���ǽ�����Ľ��Ժ�����Ӱ�죬���е�����
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
    void Mirror(TreeNode *pRoot) {
		if(!pRoot)
			return;
		TreeNode* tmp = pRoot->left;
		pRoot->left = pRoot->right;
		pRoot->right = tmp;
		Mirror(pRoot->left);
		Mirror(pRoot->right);
    }
};